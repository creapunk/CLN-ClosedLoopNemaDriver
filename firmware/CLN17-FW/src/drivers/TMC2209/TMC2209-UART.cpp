#include "TMC2209-UART.h"


TMC2209::TMC2209()
{
    
}

bool TMC2209::setupDefault(TMC2209_UNIT *config)
{
    ll.writeGCONF(config, TMC2209_REG_DEFAULT::GCONF_DEFAULT.UINT32);
    ll.writeIHOLD_IRUN(config, TMC2209_REG_DEFAULT::IHOLD_IRUN_DEFAULT.UINT32);
    ll.writeCHOPCONF(config, TMC2209_REG_DEFAULT::CHOPCONF_DEFAULT.UINT32);
    ll.writePWMCONF(config, TMC2209_REG_DEFAULT::PWMCONF_DEFAULT.UINT32);
    ll.writeTPWMTHRS(config, TMC2209_REG_DEFAULT::TPWMTHRS_DEFAULT.UINT32);
    ll.writeTCOOLTHRS(config, TMC2209_REG_DEFAULT::TCOOLTHRS_DEFAULT.UINT32);
    return available(config);
}

bool TMC2209::available(TMC2209_UNIT *config)
{
    if (ll.readIOIN(config) != UINT32_MAX) {
        return true;
    }
    return false;
}


TMC2209_LL::TMC2209_LL(/* args */)
{
}

uint8_t TMC2209_LL::getStartCRC(uint8_t address)
{
    if (address == ADR_0)
        return CRC_START_ADR_0;
    if (address == ADR_1)
        return CRC_START_ADR_1;
    if (address == ADR_2)
        return CRC_START_ADR_2;
    if (address == ADR_3)
        return CRC_START_ADR_3;
    return 0;
}

uint8_t TMC2209_LL::get4ByteCRC(uint32_t data, uint8_t crc)
{
    for (uint8_t i = 0; i < 4; ++i)
    {
        crc = get1ByteCRC((data & 0xFFU), crc);
        data >>= 8; // Get #i byte of datagram
    }
    return crc;
}

uint8_t TMC2209_LL::get1ByteCRC(uint8_t byte, uint8_t crc)
{
    for (uint8_t j = 0; j < 0x8; ++j) // CRC calculation
    {
        if ((crc >> 7) ^ (byte & 0x01))
            crc = (crc << 1) ^ 0x07;
        else
            crc = crc << 1;
        byte = byte >> 1;
    }
    return crc;
}

uint32_t TMC2209_LL::reverseBytes(uint32_t data)
{
    uint32_t reversed_data = 0;
    uint8_t right_shift;
    uint8_t left_shift;
    for (uint8_t i = 0; i < 4; ++i)
    {
        right_shift = (3 - i) * 8;
        left_shift = i * 8;
        reversed_data |= ((data >> right_shift) & 0xFF) << left_shift;
    }
    return reversed_data;
}

uint64_t TMC2209_LL::writeDatagram(uint8_t address, uint8_t reg, uint32_t data)
{
    Datagram64 datagram;
    datagram.sync = SYNC;
    datagram.serial_address = address;
    datagram.register_address = reg;
    datagram.data = reverseBytes(data);
    datagram.crc = get4ByteCRC(datagram.data, get1ByteCRC(reg, getStartCRC(address)));
    return datagram.UINT64;
}

uint32_t TMC2209_LL::requestDatagram(uint8_t address, uint8_t reg)
{
    Datagram32 datagram;
    datagram.sync = SYNC;
    datagram.serial_address = address;
    datagram.register_address = reg;
    datagram.crc = get1ByteCRC(reg, getStartCRC(address));
    return datagram.UINT32;
}

uint32_t TMC2209_LL::respondData(uint64_t datagram)
{
    if (datagram == UINT64_MAX)
        return datagram;
    uint8_t reg = datagram >>= 16;  // datagr.register_address;
    uint32_t data = datagram >>= 8; // datagr.data;
    uint8_t crc_recieved = datagram >>= 32;
    uint8_t crc_calculated = get4ByteCRC(data, get1ByteCRC(reg, CRC_START_ADR_RESPOND));
    if (crc_recieved != crc_calculated)
        return UINT32_MAX;
    return reverseBytes(data);
}

/*
@TODO
Hardware timer interrupt:
1) Starts at sending message,
2) Wait [1000000 / BAUD * (32+64+REPLY_DELAY)] us
3) Recieve [(32+64+REPLY_DELAY)/8] bytes
*/

void TMC2209_LL::write(HardwareSerial *hserial, uint8_t address, uint8_t reg, uint32_t data)
{
    if (hserial == nullptr)
        return;

    uint64_t datagram = writeDatagram(address, reg, data);

    hserial->flush(); // Wait communication complete

    for (uint8_t i = 0; i < 8; ++i)
        hserial->write((uint8_t)(datagram >> (i * 8U))); // Send message
}

void TMC2209_LL::request(HardwareSerial *hserial, uint8_t address, uint8_t reg)
{
    if (hserial == nullptr)
        return;

    uint32_t datagram = requestDatagram(address, reg);

    hserial->flush(); // Wait communication complete
    for (uint8_t i = 0; i < 4; ++i)
        hserial->write((uint8_t)(datagram >> (i * 8U))); // Send message
}

uint64_t TMC2209_LL::respond(HardwareSerial *hserial)
{
    if (hserial == nullptr)
        return UINT64_MAX;

    uint64_t reply = 0;
    uint16_t reply_delay = 250;

    hserial->flush(); // Wait communication complete
    hserial->enableHalfDuplexRx();

    while (hserial->available() > 0)
        hserial->read(); // Clean rx buffer

    delayMicroseconds(16); // 8bit delay

    while (hserial->available() < 8 and reply_delay)
    { // Wait reply
        delayMicroseconds(1);
        reply_delay--;
    }
    if (reply_delay == 0)
        return UINT64_MAX;

    for (uint8_t i = 0; i < 8U; ++i)
        reply |= (uint64_t)(hserial->read()) << (i * 8U);

    return reply;
}

uint32_t TMC2209_LL::read(HardwareSerial *hserial, uint8_t address, uint8_t reg)
{
    request(hserial, address, reg);
    uint64_t datagram = respond(hserial);
    return respondData(datagram);
}

void TMC2209_LL::writeGCONF(TMC2209_UNIT *config, uint32_t value)
{
    if (value != UINT32_MAX)
        config->GCONF.UINT32 = value;
    write(config->HSERIAL, config->ADDRESS, TMC2209_REG_ADDRESS::ADDRESS_GCONF, config->GCONF.UINT32);
}

void TMC2209_LL::writeIHOLD_IRUN(TMC2209_UNIT *config, uint32_t value)
{
    if (value != UINT32_MAX)
        config->IHOLD_IRUN.UINT32 = value;
    write(config->HSERIAL, config->ADDRESS, TMC2209_REG_ADDRESS::ADDRESS_IHOLD_IRUN, config->IHOLD_IRUN.UINT32);
}

void TMC2209_LL::writeCHOPCONF(TMC2209_UNIT *config, uint32_t value)
{
    if (value != UINT32_MAX)
        config->CHOPCONF.UINT32 = value;
    write(config->HSERIAL, config->ADDRESS, TMC2209_REG_ADDRESS::ADDRESS_CHOPCONF, config->CHOPCONF.UINT32);
}

void TMC2209_LL::writePWMCONF(TMC2209_UNIT *config, uint32_t value)
{
    if (value != UINT32_MAX)
        config->PWMCONF.UINT32 = value;
    write(config->HSERIAL, config->ADDRESS, TMC2209_REG_ADDRESS::ADDRESS_PWMCONF, config->PWMCONF.UINT32);
}

void TMC2209_LL::writeCOOLCONF(TMC2209_UNIT *config, uint32_t value)
{
    if (value != UINT32_MAX)
        config->COOLCONF.UINT32 = value;
    write(config->HSERIAL, config->ADDRESS, TMC2209_REG_ADDRESS::ADDRESS_COOLCONF, config->COOLCONF.UINT32);
}

void TMC2209_LL::writeTCOOLTHRS(TMC2209_UNIT *config, uint32_t value)
{
    if (value != UINT32_MAX)
        config->TCOOLTHRS.UINT32 = value;
    write(config->HSERIAL, config->ADDRESS, TMC2209_REG_ADDRESS::ADDRESS_TCOOLTHRS, config->TCOOLTHRS.UINT32);
}

void TMC2209_LL::writeTPWMTHRS(TMC2209_UNIT *config, uint32_t value)
{
    if (value != UINT32_MAX)
        config->TPWMTHRS.UINT32 = value;
    write(config->HSERIAL, config->ADDRESS, TMC2209_REG_ADDRESS::ADDRESS_TPWMTHRS, config->TPWMTHRS.UINT32);
}

void TMC2209_LL::writeSGTHRS(TMC2209_UNIT *config, uint32_t value)
{
    if (value != UINT32_MAX)
        config->SGTHRS = value;
    write(config->HSERIAL, config->ADDRESS, TMC2209_REG_ADDRESS::ADDRESS_SGTHRS, config->SGTHRS);
}

void TMC2209_LL::writeTPOWERDOWN(TMC2209_UNIT *config, uint32_t value)
{
    if (value != UINT32_MAX)
        config->TPOWERDOWN = value;
    write(config->HSERIAL, config->ADDRESS, TMC2209_REG_ADDRESS::ADDRESS_TPOWERDOWN, config->TPOWERDOWN);
}

uint32_t TMC2209_LL::readIOIN(TMC2209_UNIT *config)
{
    uint32_t data = read(config->HSERIAL, config->ADDRESS, TMC2209_REG_ADDRESS::ADDRESS_IOIN);
    if (data != UINT32_MAX)
        config->IOIN.UINT32 = data;
    return data;
}

uint32_t TMC2209_LL::readSG_RESULT(TMC2209_UNIT *config)
{
    uint32_t data = read(config->HSERIAL, config->ADDRESS, TMC2209_REG_ADDRESS::ADDRESS_SG_RESULT);
    if (data != UINT32_MAX)
        config->SG_RESULT = data;
    return data;
}

uint32_t TMC2209_LL::readIFCNT(TMC2209_UNIT *config)
{
    uint32_t data = read(config->HSERIAL, config->ADDRESS, TMC2209_REG_ADDRESS::ADDRESS_IFCNT);
    if (data != UINT32_MAX)
        config->IFCNT = data;
    return data;
}