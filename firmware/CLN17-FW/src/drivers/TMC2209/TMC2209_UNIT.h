#pragma once
#ifndef TMC2209_UNIT_H
#define TMC2209_UNIT_H

#include "TMC2209_REG.h"

struct TMC2209_UNIT
{
public:
  HardwareSerial *HSERIAL;
  uint8_t ADDRESS;

  TMC2209_REG_FIELD::Register_GCONF GCONF;           // WRITE
  TMC2209_REG_FIELD::Register_IHOLD_IRUN IHOLD_IRUN; // WRITE
  TMC2209_REG_FIELD::Register_CHOPCONF CHOPCONF;     // WRITE
  TMC2209_REG_FIELD::Register_PWMCONF PWMCONF;       // WRITE
  TMC2209_REG_FIELD::Register_COOLCONF COOLCONF;     // WRITE
  TMC2209_REG_FIELD::Register_THRS TCOOLTHRS;        // WRITE
  TMC2209_REG_FIELD::Register_THRS TPWMTHRS;         // WRITE

  TMC2209_REG_FIELD::Register_IOIN IOIN;             // READ
  TMC2209_REG_FIELD::Register_DRV_STATUS DRV_STATUS; // READ

  uint16_t SG_RESULT; // READ
  uint8_t SGTHRS;     // WRITE

  uint8_t TPOWERDOWN; // WRITE

  uint8_t IFCNT; // READ

  TMC2209_UNIT(HardwareSerial &HardSerial, uint8_t Address) {
    HSERIAL = &HardSerial;
    ADDRESS = Address;
  }
};

#endif