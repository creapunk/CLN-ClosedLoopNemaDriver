#pragma once

#ifndef TMC2209_UART_H
#define TMC2209_UART_H
#include <Arduino.h>
#include "TMC2209_UNIT.h"


/**
 * @class TMC2209_LL
 * @brief Class to handle datagram generation, CRC calculation and UART communication with TMC2209 stepper motor drivers.
 * This class provides methods to read from and write to TMC2209 registers using UART.
 */
class TMC2209_LL
{
private:
    HardwareSerial *HSERIAL;

    // SYNK sequence
    static constexpr uint8_t SYNC = 0b00000101;

    // Posible TMC2209 addresses
    static constexpr uint8_t ADR_0 = 0x00;
    static constexpr uint8_t ADR_1 = 0x01;
    static constexpr uint8_t ADR_2 = 0x02;
    static constexpr uint8_t ADR_3 = 0x03;

    // Precalculated start CRC for SYNK and DEV_ADDR bytes to improve speed of CRC calculation
    static constexpr uint8_t CRC_START_ADR_0 = 0x18;       // 1010 0000 0000 0000 or 0xA000
    static constexpr uint8_t CRC_START_ADR_1 = 0x91;       // 1010 0000 1000 0000 or 0xA080
    static constexpr uint8_t CRC_START_ADR_2 = 0xDF;       // 1010 0000 0100 0000 or 0xA040
    static constexpr uint8_t CRC_START_ADR_3 = 0x56;       // 1010 0000 1100 0000 or 0xA0C0
    static constexpr uint8_t CRC_START_ADR_RESPOND = 0xEB; // 1010 0000 1111 1111 0r 0xA0FF

    // 64bit write message or read response message
    union Datagram64
    {
        struct
        {
            uint64_t sync : 8;
            uint64_t serial_address : 8;
            uint64_t register_address : 8;
            uint64_t data : 32;
            uint64_t crc : 8;
        };
        uint64_t UINT64;
    };

    // 32bit read request message
    union Datagram32
    {
        struct
        {
            uint32_t sync : 8;
            uint32_t serial_address : 8;
            uint32_t register_address : 8;
            uint32_t crc : 8;
        };
        uint32_t UINT32;
    };

    // CRC calculation
    uint8_t getStartCRC(uint8_t address);
    uint8_t get1ByteCRC(uint8_t byte, uint8_t crc);
    uint8_t get4ByteCRC(uint32_t data, uint8_t crc);

    // Data byte repack
    uint32_t reverseBytes(uint32_t data);

    // Creating a message datagram for WRITE data
    uint64_t writeDatagram(uint8_t address, uint8_t reg, uint32_t data);
    // Creating a message datagram for READ request
    uint32_t requestDatagram(uint8_t address, uint8_t reg);
    // Getting a respond data for READ request
    uint32_t respondData(uint64_t datagram);

    // Write register data request to driver
    void request(HardwareSerial *hserial, uint8_t address, uint8_t reg);
    // Read register data respond from driver
    uint64_t respond(HardwareSerial *hserial);

public:
    TMC2209_LL();

    // Write 32bit data to driver
    void write(HardwareSerial *hserial, uint8_t address, uint8_t reg, uint32_t data);
    // Read 32bit data from driver
    uint32_t read(HardwareSerial *hserial, uint8_t address, uint8_t reg);

    void writeGCONF(TMC2209_UNIT *config, uint32_t value = UINT32_MAX);
    void writeIHOLD_IRUN(TMC2209_UNIT *config, uint32_t value = UINT32_MAX);
    void writeCHOPCONF(TMC2209_UNIT *config, uint32_t value = UINT32_MAX);
    void writePWMCONF(TMC2209_UNIT *config, uint32_t value = UINT32_MAX);

    void writeCOOLCONF(TMC2209_UNIT *config, uint32_t value = UINT32_MAX);
    void writeTCOOLTHRS(TMC2209_UNIT *config, uint32_t value = UINT32_MAX);

    void writeTPWMTHRS(TMC2209_UNIT *config, uint32_t value = UINT32_MAX);
    void writeSGTHRS(TMC2209_UNIT *config, uint32_t value = UINT32_MAX);
    void writeTPOWERDOWN(TMC2209_UNIT *config, uint32_t value = UINT32_MAX);

    uint32_t readIOIN(TMC2209_UNIT *config);
    uint32_t readSG_RESULT(TMC2209_UNIT *config);
    uint32_t readIFCNT(TMC2209_UNIT *config);
};

class TMC2209
{
private:
    static constexpr uint32_t COOLCONF_DEFAULT = 0;
    static constexpr uint8_t SGTHRS_DEFAULT = 0;
    static constexpr uint8_t TPOWERDOWN_DEFAULT = 20;

public:
    TMC2209_LL ll;
    
    TMC2209();

    /**
     * @brief Устанавливает параметры по умолчанию для драйвера
     * @param config - ссылка на экземпляр настроек драйвера
     */
    bool setupDefault(TMC2209_UNIT *config);

    /**
     * @brief Проверяет, доступен ли драйвер, отправляя запрос в регистр IOIN.
     * Если коммуникации нет, будет получен ответ UINT32_MAX
     * @param config - ссылка на экземпляр настроек драйвера
     */
    bool available(TMC2209_UNIT *config);
};



#endif