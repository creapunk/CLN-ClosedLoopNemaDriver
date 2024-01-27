/**
 * @file TMC2209_REG.h
 * @author Anton Khrustalev, 2023
 * @brief This file contains the definition of the register structures for the TMC2209 stepper motor driver.
 * @attention Read the TMC2209 datasheet first before making any changes
 */

#pragma once

#ifndef TMC2209_REG_H
#define TMC2209_REG_H

/**
 * @namespace TMC2209_REG_FIELD
 * @brief Namespace containing definitions of register structures for TMC2209.
 * @attention Read the TMC2209 datasheet first before making any changes
 */
namespace TMC2209_REG_FIELD
{
    /**
     * @brief Global configuration flags: WRITE
     */
    union Register_GCONF
    {
        struct
        {
            uint32_t i_scale_analog : 1;      // Voltage reference. 0: Internal; 1: external VREF
            uint32_t internal_rsense : 1;     // Current sense resistors. 0: Exteral; 1: internal
            uint32_t enable_spread_cycle : 1; // Speed mode. 0: StealthChop; 1: SpreadCycle
            uint32_t shaft : 1;               // Shaft direction
            uint32_t index_otpw : 1;          // INDEX out. 0: Microstep; 1: Overtemp
            uint32_t index_step : 1;          // INDEX out. 0: index_otpw; 1: Steps
            uint32_t pdn_disable : 1;         // Uart. 1: Uart enable
            uint32_t mstep_reg_select : 1;    // Microstepping. 0: MS1, MS2 pins; 1: register
            uint32_t multistep_filt : 1;      // Step pulse filter. 0: disable; 1: enable
            uint32_t reserved : 23;           // DO NOT USE!
        } REG;
        uint32_t UINT32;
    };

    /**
     * @brief – Global status flags: READ
     */
    union Register_GSTAT
    {
        struct
        {
            uint8_t reset : 1;     // Indicates that the IC has been reset since the last read access to GSTAT
            uint8_t drv_err : 1;   // Indicates, that the driver has been shut down since the last read access
            uint8_t iuv_cprun : 1; // Indicates an undervoltage on the charge pump
            uint8_t reserved : 5;  // DO NOT USE!
        } REG;
        uint8_t UINT8;
    };

    /**
     * @brief SENDDELAY for read access (time until reply is sent): WRITE
     */
    union Register_SLAVECONF
    {
        struct
        {
            uint16_t reserved1 : 8; // DO NOT USE!
            uint16_t drv_err : 4;   // Indicates, that the driver has been shut down since the last read access
            uint16_t reserved2 : 4; // DO NOT USE!
        } REG;
        uint16_t UINT16;
    };

    /**
     * @brief Velocity Dependent Driver Feature Control Register Set: WRITE
     */
    union Register_IHOLD_IRUN
    {
        struct
        {
            uint32_t ihold : 5;      // IHOLD. Standstill current (0=1/32 … 31=32/32)
            uint32_t reserved1 : 3;  // DO NOT USE!
            uint32_t irun : 5;       // IRUN. Motor run current (0=1/32 … 31=32/32)
            uint32_t reserved2 : 3;  // DO NOT USE!
            uint32_t iholddelay : 4; // IHOLDDELAY
            uint32_t reserved3 : 12; // DO NOT USE!
        } REG;
        uint32_t UINT32;
    };

    /**
     * @brief Driver pin status for test/debug communication: READ
     */
    union Register_IOIN
    {
        struct
        {
            uint32_t enn : 1;        // ENN pin state
            uint32_t reserved1 : 1;  // DO NOT USE!
            uint32_t ms1 : 1;        // MS1 pin state
            uint32_t ms2 : 1;        // MS2 pin state
            uint32_t diag : 1;       // DIAG pin state
            uint32_t reserved2 : 1;  // DO NOT USE!
            uint32_t pdn_serial : 1; // PDN pin state
            uint32_t step : 1;       // STEP pin state
            uint32_t spread_en : 1;  // SPREAD pin state
            uint32_t dir : 1;        // DIR pin state
            uint32_t reserved3 : 14; // DO NOT USE!
            uint32_t version : 8;    // Chip version: 0x21
        } REG;
        uint32_t UINT32;
    };

    /**
     * @brief Driver status flags and current level read back: READ
     */
    union Register_DRV_STATUS
    {
        struct
        {
            uint32_t over_temperature_warning : 1;  // Overtemperature prewarning flag
            uint32_t over_temperature_shutdown : 1; // Overtemperature warning shutdown
            uint32_t short_to_ground_a : 1;         // Short coil detection
            uint32_t short_to_ground_b : 1;         // Short coil detection
            uint32_t low_side_short_a : 1;          // Short coil detection
            uint32_t low_side_short_b : 1;          // Short coil detection
            uint32_t open_load_a : 1;               // Not connected coil detection (low speed only)
            uint32_t open_load_b : 1;               // Not connected coil detection (low speed only)
            uint32_t over_temperature_120c : 1;     // Overtemperature threshold
            uint32_t over_temperature_143c : 1;     // Overtemperature threshold
            uint32_t over_temperature_150c : 1;     // Overtemperature threshold
            uint32_t over_temperature_157c : 1;     // Overtemperature threshold
            uint32_t reserved1 : 4;                 // DO NOT USE!
            uint32_t current_scaling : 5;           // Actual current scaling
            uint32_t reserved2 : 9;                 // DO NOT USE!
            uint32_t stealth_chop_mode : 1;         // Chopper mode. 0: SpreadCycle; 1: StealthChop
            uint32_t standstill : 1;                // Standstill indicator
        } REG;
        uint32_t UINT32;
    };

    /**
     * @brief Chopper and driver configuration: WRITE
     */
    union Register_CHOPCONF
    {
        struct
        {
            uint32_t toff : 4;          // 0: Driver disable; 2 ... 15: Duration of slow decay phase
            uint32_t hstrt : 3;         // Hysteresis start value
            uint32_t hend : 4;          // Hysteresis low value
            uint32_t reserved1 : 4;     // DO NOT USE!
            uint32_t tbl : 2;           // Comparator blank time select
            uint32_t vsense : 1;        // Current resistor sensetivity. 0: Low; 1: High
            uint32_t reserved2 : 6;     // DO NOT USE!
            uint32_t mres : 4;          // Microstepping resolution 0 ... 8 <=> 256 ... 0
            uint32_t interpolation : 1; // Interpolation. 0: Off; 1: On
            uint32_t double_edge : 1;   // Double edge step pulses to reduce step freq. 0: Off; 1: On
            uint32_t diss2g : 1;        // Disable GND Short proection
            uint32_t diss2vs : 1;       // Disable VSS Short proection
        } REG;
        uint32_t UINT32;
    };

    /**
     * @brief StealthChop PWM chopper configuration: WRITE
     */
    union Register_PWMCONF
    {
        struct
        {
            uint32_t pwm_offset : 8;    // User defined amplitude (offset)
            uint32_t pwm_grad : 8;      // User defined amplitude gradient
            uint32_t pwm_freq : 2;      // PWM frequency 0b01 or 0b10
            uint32_t pwm_autoscale : 1; // PWM automatic amplitude scaling
            uint32_t pwm_autograd : 1;  // PWM automatic gradient adaptation
            uint32_t freewheel : 2;     // Stand Still mode if I_HOLD=0. 0b01: Freewheeling; 0b10: Passive bracking
            uint32_t reserved : 2;      // DO NOT USE!
            uint32_t pwm_reg : 4;       // Regulation loop gradient
            uint32_t pwm_lim : 4;       // PWM automatic scale amplitude limit when switching on
        } REG;
        uint32_t UINT32;
    };

    /**
     * @brief CoolStep configuration: WRITE
     */
    union Register_COOLCONF
    {
        struct
        {
            uint32_t semin : 4;      // Load compensation (Increase current)
            uint32_t reserved1 : 1;  // DO NOT USE!
            uint32_t seup : 2;       // Current up step. 0b00 … 0b11: 1, 2, 4, 8
            uint32_t reserved2 : 1;  // DO NOT USE!
            uint32_t semax : 4;      // Load compensation (Decrease current)
            uint32_t reserved3 : 1;  // DO NOT USE!
            uint32_t sedn : 2;       // Current up step. 0b00 … 0b11: 1, 2, 4, 8
            uint32_t seimin : 1;     // Minimum current for smart current control
            uint32_t reserved4 : 16; // DO NOT USE!
        } REG;
        uint32_t UINT32;
    };

    /**
     * @brief Threshold velocity for switching CoolStep/StealthChop/SpreadCycle: WRITE
     */
    union Register_THRS
    {
        struct
        {
            uint32_t threshold : 20; // Threshold velocity
            uint32_t reserved : 12;  // DO NOT USE!
        } REG;
        uint32_t UINT32;
    };

    /**
     * @brief Results of StealthChop amplitude regulator: READ
     * These values can be used to monitor
     * automatic PWM amplitude scaling (255=max. voltage)
     */
    union Register_PWM_SCALE
    {
        struct
        {
            uint32_t pwm_scale_sum : 8;  // Actual PWM duty cycle
            uint32_t reserved1 : 8;      // DO NOT USE!
            uint32_t pwm_scale_auto : 9; // 9 Bit signed offset added to the calculated PWM duty cycle
            uint32_t reserved2 : 7;      // DO NOT USE!
        } REG;
        uint32_t UINT32;
    };

    /**
     * @brief Current values of PWM_GRAD and PWM_OFS: READ
     */
    union Register_PWM_AUTO
    {
        struct
        {
            uint32_t pwm_ofs_auto : 8;  // Automatically determined offset value
            uint32_t reserved1 : 8;     // DO NOT USE!
            uint32_t pwm_grad_auto : 8; // Automatically determined gradient value
            uint32_t reserved2 : 8;     // DO NOT USE!
        } REG;
        uint32_t UINT32;
    };
}

/**
 * @namespace TMC2209_REG_ADDRESS
 * @brief Namespace containing adresses of registers
 * @attention Read the TMC2209 datasheet first before making any changes
 */
namespace TMC2209_REG_ADDRESS
{
    // Registers adresses with WRITE acces (added 0x80)
    constexpr uint8_t ADDRESS_GCONF = 0x00 + 0x80;      // Write access
    constexpr uint8_t ADDRESS_SLAVECONF = 0x03 + 0x80;  // Write access
    constexpr uint8_t ADDRESS_IHOLD_IRUN = 0x10 + 0x80; // Write access
    constexpr uint8_t ADDRESS_TPOWERDOWN = 0x11 + 0x80; // Write access
    constexpr uint8_t ADDRESS_TPWMTHRS = 0x13 + 0x80;   // Write access
    constexpr uint8_t ADDRESS_TCOOLTHRS = 0x14 + 0x80;  // Write access
    constexpr uint8_t ADDRESS_SGTHRS = 0x40 + 0x80;     // Write access
    constexpr uint8_t ADDRESS_COOLCONF = 0x42 + 0x80;   // Write access
    constexpr uint8_t ADDRESS_CHOPCONF = 0x6C + 0x80;   // Write access
    constexpr uint8_t ADDRESS_PWMCONF = 0x70 + 0x80;    // Write access

    // Registers adresses with READ acces
    constexpr uint8_t ADDRESS_GSTAT = 0x01;      // Read access
    constexpr uint8_t ADDRESS_IFCNT = 0x02;      // Read access
    constexpr uint8_t ADDRESS_IOIN = 0x06;       // Read access
    constexpr uint8_t ADDRESS_SG_RESULT = 0x41;  // Read access
    constexpr uint8_t ADDRESS_DRV_STATUS = 0X6F; // Read access
}

/**
 * @namespace TMC2209_REG_DEFAULT
 * @brief Namespace containing default compile time values for initializing writable registers of TMC2209.
 * @attention Read the TMC2209 datasheet first before making any changes
 */
namespace TMC2209_REG_DEFAULT
{
    constexpr TMC2209_REG_FIELD::Register_GCONF GCONF_DEFAULT = {
        .REG = {
            .i_scale_analog = 0,      // Enable VREF current scaling
            .internal_rsense = 0,     // External current sense resistors
            .enable_spread_cycle = 0, // StealthChop default
            .shaft = 0,               // Not inverted
            .index_otpw = 1,          // INDEX overtemp out
            .index_step = 0,          // INDEX overtemp out
            .pdn_disable = 1,         // Enable UART communication
            .mstep_reg_select = 1,    // Microstepping source = internal register
            .multistep_filt = 0       // No filtration (TO ENABLE DEDGE)
        }};

    constexpr TMC2209_REG_FIELD::Register_IHOLD_IRUN IHOLD_IRUN_DEFAULT = {
        .REG = {
            .ihold = 4,     // 1/4 of max current
            .irun = 4,      // 1/4 of max current
            .iholddelay = 7 // Optimal value
        }};

    constexpr TMC2209_REG_FIELD::Register_PWMCONF PWMCONF_DEFAULT = {
        .REG = {
            .pwm_offset = 0,    // ?
            .pwm_grad = 0,      // ?
            .pwm_freq = 0b01,   // Default PWM frequency
            .pwm_autoscale = 1, // Enabled
            .pwm_autograd = 0,  // Disabled
            .freewheel = 0b10,  // Passive bracking
            .pwm_reg = 4,       // ?
            .pwm_lim = 12       // ?
        }};

    constexpr TMC2209_REG_FIELD::Register_CHOPCONF CHOPCONF_DEFAULT = {
        .REG = {
            .toff = 3,          // Power off time
            .hstrt = 5,         // Todo
            .hend = 0,          // Todo
            .tbl = 0b10,        // Optimal value (see datasheet)
            .vsense = 1,        // High resistor sensetivity (low current operation)
            .mres = 1,          // 128 microsteps control
            .interpolation = 1, // Enabled interpolation
            .double_edge = 1,   // Step trigger on both rising and falling edge
            .diss2g = 0,        // ShortToGnd protection enabled
            .diss2vs = 0        // ShortToVss protection enabled
        }};

    constexpr TMC2209_REG_FIELD::Register_COOLCONF COOLCONF_DEFAULT = {
        .REG = {
            .semin = 16,
            .seup = 0,
            .semax = 0,
            .sedn = 0,
            .seimin = 0}};

    constexpr TMC2209_REG_FIELD::Register_THRS TPWMTHRS_DEFAULT = {
        .REG = {
            .threshold = 0x40 // ~220RPM (fClk/64)
        }};

    constexpr TMC2209_REG_FIELD::Register_THRS TCOOLTHRS_DEFAULT = {
        .REG = {
            .threshold = 0x3000 // ~1RPM (fClk/12288)
        }};
}

#endif