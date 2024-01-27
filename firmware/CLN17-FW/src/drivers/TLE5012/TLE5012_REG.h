/**
 * @file TLE5012B_REG.h
 * @author Anton Khrustalev, 2023
 * @brief This file contains the definition of the register structures for the TLE5012B 15bit absolute magnet encoder.
 * @attention Read the TLE5012B datasheet first before making any changes
 */

#pragma once

#ifndef TLE5012_REG_H
#define TLE5012_REG_H

/**
 * @namespace TLE5012B_REG_FIELD
 * @brief Namespace containing definitions of register structures for TLE5012B.
 * @attention Read the TLE5012B datasheet first before making any changes
 */
namespace TLE5012B_REG_FIELD
{
    /**
     * @brief Command Word to access and change operating modes
     */
    union CommandWord
    {
        struct
        {
            uint16_t ND : 4;   // 4-bit Number of Data Words (if bits set to 0000B, no safety word is provided)
            uint16_t ADDR : 6; // 6-bit Address
            uint16_t UPD : 1;  // Update-Register Access. 0: Access to current values; 1: Access to values in update buffer
            uint16_t LOCK : 4; // 4-bit Lock Value. Default: 0b0; Configuration access for addresses 0x05 - 0x11: 0b1010
            uint16_t RW : 1;   // Read - Write. 0: Write; 1: Read
        } REG;
        uint16_t UINT16;
    };

    /**
     * @brief Safety Word confirms the data transfer and provides status information
     */
    union SafetyWord
    {
        struct
        {
            uint16_t CRC8 : 8;        // Cyclic Redundancy Check
            uint16_t RESP : 4;        // Sensor number response indicator
            uint16_t STAT_ANGLE : 1;  // Invalid angle value (NO_GMR_A = 1; NO_GMR_XY = 1)
            uint16_t STAT_ACCESS : 1; // Interface access error (access to wrong address; wrong lock)
            uint16_t STAT_SYSTEM : 1; // System error
            uint16_t STAT_RESET : 1;  // Indication of chip reset or watchdog overflow (resets after readout) via SSC

        } REG;
        uint16_t UINT16;
    };

    /**
     * @brief STATus register. Access: READ/WRITE/UPDATE
     */
    union Register_STAT
    {
        struct
        {
            uint16_t S_RST : 1;     // SRST status watch dog
            uint16_t S_WD : 1;      // SWD status watch dog
            uint16_t S_VR : 1;      // SVR status voltage regulator
            uint16_t S_FUSE : 1;    // SFUSE status fuses
            uint16_t S_DSPU : 1;    // SDSPU status digital signal processing unit
            uint16_t S_OV : 1;      // SOV status overflow
            uint16_t S_XYOL : 1;    // SXYOL status X/Y data out limit
            uint16_t S_MAGOL : 1;   // SMAGOL status magnitude out limit
            uint16_t RESERVED : 1;  // DO NOT USE!
            uint16_t S_ADCT : 1;    // SADCT status ADC test
            uint16_t S_ROM : 1;     // SROM status ROM
            uint16_t NO_GMR_XY : 1; // NOGMRXY no valid GMR XY Values
            uint16_t NO_GMR_A : 1;  // NOGMRA no valid GMR Angle Value
            uint16_t S_NR : 2;      // SNR slave number
            uint16_t RD_ST : 1;     // RDST read status
        } REG;
        uint16_t UINT16;
    };

    /**
     * @brief ACtivation STATus register. Access: WRITE
     */
    union Register_ACSTAT
    {
        struct
        {
            uint16_t AS_RST : 1;     // ASRST Activation of Hardware Reset
            uint16_t AS_WD : 1;      // ASWD Enable DSPU Watch dog
            uint16_t AS_VR : 1;      // ASVR Enable Voltage regulator Check
            uint16_t AS_FUSE : 1;    // ASFUSE Activation Fuse CRC
            uint16_t AS_DSPU : 1;    // ASDSPU Activation DSPU BIST
            uint16_t AS_OV : 1;      // ASOV Enable of DSPU Overflow Check
            uint16_t AS_VEC_XY : 1;  // ASVECXY Activation of X,Y Out of Limit-Check
            uint16_t AS_VEG_MAG : 1; // ASVEGMAG Activation of Magnitude Check
            uint16_t RESERVED1 : 1;  // DO NOT USE!
            uint16_t AS_ADCT : 1;    // ASADCT Enable ADC Test vector Check
            uint16_t AS_FRST : 1;    // ASFRST Activation of Firmware Reset
            uint16_t RESERVED2 : 5;  // DO NOT USE!

        } REG;
        uint16_t UINT16;
    };

    /**
     * @brief Angle VALue register. Access: READ/UPDATE
     */
    union Register_AVAL
    {
        struct
        {
            uint16_t ANG_VAL : 15; // ANGVAL Calculated Angle Value
            uint16_t RD_AV : 1;    // RDAV Read Status, Angle Value
        } REG;
        uint16_t UINT16;
    };

    /**
     * @brief Angle SPeeD registerAngle SPeeD register. Access: READ/UPDATE
     */
    union Register_ASPD
    {
        struct
        {
            uint16_t ANG_SPD : 15; // ANGSPD Calculated Angle Speed Value, where the sign bit [14] indicates the direction of the rotation
            uint16_t RD_AS : 1;    // RDAS Read Status, Angle Speed
        } REG;
        uint16_t UINT16;
    };

    /**
     * @brief Angle REVolution register. Access: READ/WRITE/UPDATE
     */
    union Register_AREV
    {
        struct
        {
            uint16_t REVOL : 9;  // REVOL Revolution counter that increments for every full rotation in counter-clockwise direction
            uint16_t FCNT : 6;   // FCNT Internal frame counter. Increments every update period
            uint16_t RD_REV : 1; // RDREV Read Status, Revolution
        } REG;
        uint16_t UINT16;
    };

    /**
     * @brief Frame SYNChronization register. Access: READ/WRITE/UPDATE
     */
    union Register_FSYNC
    {
        struct
        {
            uint16_t TEMPER : 9; // TEMPR Signed offset compensated temperature value
            uint16_t FSYNC : 7;  // FSYNC Frame Synchronization Counter Value
        } REG;
        uint16_t UINT16;
    };

    /**
     * @brief Interface MODe1 register. Access: WRITE
     */
    union Register_MOD_1
    {
        struct
        {
            uint16_t IIF_MOD : 2;   // IIFMOD Incremental Interface Mode
            uint16_t DSPU_HOLD : 1; // DSPUHOLD if DSPU is on hold, no watch dog reset is performed by DSPU
            uint16_t RESERVED1 : 1; // DO NOT USE!
            uint16_t CLK_SEL : 1;   // CLKSEL switch to external clock at start-up only
            uint16_t RESERVED2 : 9; // DO NOT USE!
            uint16_t FIR_MD : 2;    // FIRMD Update Rate Setting
        } REG;
        uint16_t UINT16;
    };

    /**
     * @brief SIL register. Access: WRITE
     */
    union Register_SIL
    {
        struct
        {
            uint16_t ADCTV_X : 3;   // ADCTVX Test vector X
            uint16_t ADCTV_Y : 3;   // ADCTVY Test vector Y
            uint16_t ADCTV_EN : 1;  // ADCTVEN Sensor elements are internally disconnected and test voltages are connected to ADCs
            uint16_t RESERVED1 : 3; // DO NOT USE!
            uint16_t FUSE_REL : 1;  // FUSEREL Triggers reload of default values from laser fuses into configuration registers
            uint16_t RESERVED2 : 3; // DO NOT USE!
            uint16_t FILT_INV : 1;  // FILTINV the X- and Y-signals are inverted. The angle output is then shifted by 180°
            uint16_t FILT_PAR : 1;  // FILTPAR the raw X-signal is routed also to the raw Y-signal input of the filter so SIN and COS signal should be identical
        } REG;
        uint16_t UINT16;
    };

    /**
     * @brief Interface MODe2 register. Access: WRITE
     */
    union Register_MOD_2
    {
        struct
        {
            uint16_t AUTOCAL : 2;    // AUTOCAL Automatic calibration of offset and amplitude synchronicity for applications with full-turn
            uint16_t PREDICT : 1;    // PREDICT Prediction of angle value based on current angle speed
            uint16_t ANG_DIR : 1;    // ANGDIR Inverts angle and angle speed values and revolution counter behavior
            uint16_t ANG_RANGE : 11; // ANGRANGE Changes the representation of the angle output by multiplying the output with a factor ANG_RANGE/128
            uint16_t RESERVED : 1;   // DO NOT USE!
        } REG;
        uint16_t UINT16;
    };

    /**
     * @brief Interface MODe3 register. Access: WRITE
     */
    union Register_MOD_3
    {
        struct
        {
            uint16_t PAD_DRV : 2;   // PADDRV Configuration of Pad-Driver
            uint16_t SSC_OD : 1;    // SSCOD SSC-Interface Data Pin Output Mode
            uint16_t SPIKEF : 1;    // SPIKEF Filters voltage spikes on input pads (IFC, SCK and CSQ)
            uint16_t ANG_BASE : 12; // ANG_BASE Sets the 0° angle position (12 bit value). Angle base is factory-calibrated to make the 0° direction parallel to the edge of the chip

        } REG;
        uint16_t UINT16;
    };

    /**
     * @brief OFFset X or OFFset Y. Access: WRITE
     */
    union Register_OFF
    {
        struct
        {
            uint16_t RESERVED : 4;  // DO NOT USE!
            uint16_t OFFSET : 12; // XOFFSET 12-bit signed integer value of raw X-signal offset correction at 25°C
        } REG;
        uint16_t UINT16;
    };

    /**
     * @brief SYNCHronicity. Access: WRITE
     */
    union Register_SYNCH
    {
        struct
        {
            uint16_t RESERVED : 4; // DO NOT USE!
            uint16_t SYNCH : 12;   // SYNCH 12-bit signed integer value of amplitude synchronicity
        } REG;
        uint16_t UINT16;
    };

    /**
     * @brief IFAB register. Access: WRITE
     */
    union Register_IFAB
    {
        struct
        {
            uint16_t IFAB_HYST : 2; // IFADHYST Hysteresis (multi-purpose)
            uint16_t IFAB_OD : 1;   // IFABOD IFA,IFB,IFC Output Mode
            uint16_t FIR_UDR : 1;   // FIRUDR Initial filter update rate (FIR)
            uint16_t ORTHO : 12;    // ORTHO Orthogonality Correction of X and Y Components
        } REG;
        uint16_t UINT16;
    };

    /**
     * @brief Interface MODe4 register. Access: WRITE
     */
    union Register_MOD_4
    {
        struct
        {
            uint16_t IF_MD : 2;    // IFMD Interface Mode on IFA,IFB,IFC
            uint16_t RESERVED : 1; // DO NOT USE!
            uint16_t IFAB_RES : 2; // IFABRES IIF resolution (multi-purpose)
            uint16_t HSM_PLP : 4;  // HSMPLP Hall Switch mode (multi-purpose)
            uint16_t TCO_X_T : 7;  // TCOXT 7-bit signed integer value of X-offset temperature coefficient
        } REG;
        uint16_t UINT16;
    };

    /**
     * @brief Temperature COefficient register. Access: WRITE
     */
    union Register_TCO_Y
    {
        struct
        {
            uint16_t CRC_PAR : 8; // CRCPAR CRC of Parameters
            uint16_t SBIST : 1;   // SBIST Startup-BIST
            uint16_t TCO_Y_T : 7; // TCOYT 7-bit signed integer value of Y-offset temperature coefficient
        } REG;
        uint16_t UINT16;
    };

    /**
     * @brief ADC X-raw or Y-raw value. Access: READ
     */
    union Register_ADC
    {
        struct
        {
            uint16_t ADC : 16; // ADCX ADC value of X-GMR

        } REG;
        uint16_t UINT16;
    };


    /**
     * @brief Angle vector MAGnitude. Access: READ/UPDATE
     */
    union Register_D_MAG
    {
        struct
        {
            uint16_t MAG : 10;     // MAG Unsigned Angle Vector Magnitude after X, Y error compensation (due to temperature)
            uint16_t RESERVED : 6; // DO NOT USE!
        } REG;
        uint16_t UINT16;
    };

    /**
     * @brief Temperature sensor RAW-value. Access: READ/UPDATE
     */
    union Register_T_RAW
    {
        struct
        {
            uint16_t T_RAW : 10;   // TRAW Temperature Sensor Raw-Value at ADC without offset
            uint16_t RESERVED : 5; // DO NOT USE!
            uint16_t T_TGL : 1;    // TTGL Temperature Sensor Raw-Value Toggle toggles after every new temperature value
        } REG;
        uint16_t UINT16;
    };

    /**
     * @brief IIF CouNTer value. Access: READ/UPDATE
     */
    union Register_IIF_CNT
    {
        struct
        {
            uint16_t IIF_CNT : 14; // IIFCNT 14 bit counter value of IIF increments
            uint16_t RESERVED : 2; // DO NOT USE!
        } REG;
        uint16_t UINT16;
    };

    /**
     * @brief Temperature 25°C Offset value. Access: READ
     */
    union Register_T25O
    {
        struct
        {
            uint16_t RESERVED : 9; // DO NOT USE!
            uint16_t T25O : 7;     // T250 Signed offset value at 25°C temperature; 1dig=0.36°C
        } REG;
        uint16_t UINT16;
    };
}

/**
 * @namespace TLE5012_REG_ADDRESS
 * @brief Namespace containing adresses of registers
 * @attention Read the TLE5012 datasheet first before making any changes
 */
namespace TLE5012B_REG_ADDRESS
{
    constexpr uint8_t ADDRESS_STAT = 0x00;    // READ/WRITE
    constexpr uint8_t ADDRESS_ACSTAT = 0x01;  // WRITE
    constexpr uint8_t ADDRESS_AVAL = 0x02;    // READ
    constexpr uint8_t ADDRESS_ASPD = 0X03;    // READ
    constexpr uint8_t ADDRESS_AREV = 0x04;    // READ/WRITE
    constexpr uint8_t ADDRESS_FSYNC = 0x05;   // READ/WRITE
    constexpr uint8_t ADDRESS_MOD_1 = 0x06;   // WRITE
    constexpr uint8_t ADDRESS_SIL = 0x07;     // WRITE
    constexpr uint8_t ADDRESS_MOD_2 = 0x08;   // WRITE
    constexpr uint8_t ADDRESS_MOD_3 = 0x09;   // WRITE
    constexpr uint8_t ADDRESS_OFFX = 0X0A;    // WRITE
    constexpr uint8_t ADDRESS_OFFY = 0x0B;    // WRITE
    constexpr uint8_t ADDRESS_SYNCH = 0x0C;   // WRITE
    constexpr uint8_t ADDRESS_IFAB = 0x0D;    // WRITE
    constexpr uint8_t ADDRESS_MOD_4 = 0x0E;   // WRITE
    constexpr uint8_t ADDRESS_TCO_Y = 0x0F;   // WRITE
    constexpr uint8_t ADDRESS_ADC_X = 0X10;   // READ
    constexpr uint8_t ADDRESS_ADC_Y = 0X11;   // READ
    constexpr uint8_t ADDRESS_D_MAG = 0X14;   // READ
    constexpr uint8_t ADDRESS_T_RAW = 0X15;   // READ
    constexpr uint8_t ADDRESS_IIF_CNT = 0X20; // READ
    constexpr uint8_t ADDRESS_T25O = 0X30;    // READ
}

#endif