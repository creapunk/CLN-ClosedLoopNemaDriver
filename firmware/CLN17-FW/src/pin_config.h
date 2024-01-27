#pragma once

#ifndef PIN_CONFIG_H
#define PIN_CONFIG_H

namespace PINOUT
{
    // Encoder
    constexpr PinName ENC_MOSI = PA_7;
    constexpr PinName ENC_MISO = PA_6;
    constexpr PinName ENC_SCLK = PA_5;
    constexpr PinName ENC_CSEL = PC_4;

    // LED
    constexpr PinName LED_RED = PB_13; // OUTPUT; HIGH = OFF, LOW = ON
    constexpr PinName LED_GRN = PB_14; // OUTPUT; HIGH = OFF, LOW = ON
    constexpr PinName LED_BLU = PB_15; // OUTPUT; HIGH = OFF, LOW = ON

    // Ststem telemetry
    constexpr PinName SYS_VSUP = PA_2;      // INPUT_ANALOG
    constexpr PinName SYS_VREF = PADC_VREF; // Core VREF voltage ADC
    constexpr PinName SYS_TEMP = PADC_TEMP; // Core VTEMP temperature ADC

    // Buttons
    constexpr PinName SYS_SW1 = PA_15; // INPUT_PULLUP; LOW = PRESSED
    constexpr PinName SYS_SW2 = PB_7;  // INPUT_PULLUP; LOW = PRESSED

    // CTRL connector
    constexpr PinName CTRL_ENB = PA_8;  // ENB / 5V / SCL / CS   / 5V
    constexpr PinName CTRL_STP = PB_5;  // DIR / CK / SDA / MOSI / A
    constexpr PinName CTRL_DIR = PB_4;  // STP / RX / RX  / MISO / B
    constexpr PinName CTRL_ERR = PB_3;  // ERR / TX / TX  / SCK  / Z
    constexpr PinName CTRL_5VO = PB_12; // 5V output on ENB, OPEN-DRAIN Logic

    // Expansion connector
    constexpr PinName EXP_TX = PC_10; // UART3 RX
    constexpr PinName EXP_RX = PC_11; // UART3 TX

    // CAN-Bus interface
    constexpr PinName CAN_RX = PB_8;  // Recieve line
    constexpr PinName CAN_TX = PB_9;  // Trancieve line
    constexpr PinName CAN_SD = PA_9;  // Shutdown pin (ACTIVE LOW)
    constexpr PinName CAN_IO = PA_10; // HIGH for (VIO or EN) or HIGH-Z for (VREF)

    // USB interface
    constexpr PinName USB_USB_DP = PA_12;
    constexpr PinName USB_USB_DN = PA_11;

    // Motor Driver (depends on version)
    namespace V1_5 // CLN17 V1.5
    {
        constexpr PinName ISEN_A = PA_3;
        constexpr PinName ISEN_B = PB_0;

        constexpr PinName DRV_RST = PA_4; // Should be HIGH before activating DIAG, DIR, STEP, PDN
        constexpr PinName DRV_ERR = PB_1;

        constexpr PinName DRV_PDN = PB_11; // LPUART1

        constexpr PinName DRV_DIR = PA_0;
        constexpr PinName DRV_STEP = PA_1;


    }

    namespace V2_0 // CLN17 V1.5
    {
        constexpr PinName ISEN_A = PA_3;
        constexpr PinName ISEN_B = PB_0;

        constexpr PinName DRV_RST = PA_4;
        constexpr PinName DRV_ERR = PB_1;

        constexpr PinName DRV_EN = PA_4;
        constexpr PinName DRV_A1 = PA_0;
        constexpr PinName DRV_A2 = PA_1;
        constexpr PinName DRV_B1 = PB_11;
        constexpr PinName DRV_B2 = PB_10;
    }

}

#endif