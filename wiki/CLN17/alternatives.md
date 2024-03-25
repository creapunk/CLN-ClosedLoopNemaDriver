# Alternative Closed-Loop Drivers for NEMA17

CLN17 is not the only closed-loop motor driver. There are several alternatives available, which are also closed-loop drivers and designed with a similar architecture. These drivers comprise a microcontroller, an encoder, and a driver, all integrated onto a single printed circuit board placed at the rear side of the NEMA17 motor.

## Quick overview of the alternatives

- [USTEPPER S32](https://github.com/uStepper/uStepperS) by [uStepper](https://github.com/uStepper)
- [MKS SERVO42C](https://github.com/makerbase-mks/MKS-SERVO42C) by [Makerbase](https://github.com/makerbase-mks)
- [MECHADUINO](https://github.com/jcchurch13/Mechaduino-Hardware) by [jcchurch13](https://github.com/jcchurch13)
- [XDrive](https://github.com/unlir/XDrive) by [unlir](https://github.com/unlir)
- [BTT S42C](https://biqu.equipment/products/bigtreetech-s42c-v1-0-42-stepper-motor-closed-loop-driver-board-with-oled-display) by [BigTreeTech](https://github.com/bigtreetech)
- [Smart Stepper](https://github.com/Misfittech/nano_stepper) by [Misfittech](https://github.com/Misfittech)
- [Ethersweep](https://github.com/Neumi/ethersweep) by [Neumi](https://github.com/Neumi)

|                  |                           CLN17 V2                           |           USTEPPER S32            |      MKS SERVO42C       |         BTT S42C          |             MECHADUINO              |            Smart Stepper             |                  XDrive                  |             Ethersweep              |
| :--------------: | :----------------------------------------------------------: | :-------------------------------: | :---------------------: | :-----------------------: | :---------------------------------: | :----------------------------------: | :--------------------------------------: | :---------------------------------: |
|     **MCU**      |                  STM32G431CB<br/>M4 170MHz                   |     STM32F401RE<br/>M4 84MHz      | HC32L130F8<br/>M0 48MHz | STM32G031G8<br/>M0+ 64MHz |      ATSAMD21G18<br/>M0+ 48MHz      |       STM32F103CB<br/>M3 72MHz       |         STM32F103CB<br/>M3 72MHz         |      STM32F103C8<br/>M3 72MHz       |
|    **Memory**    |                  128KB FLASH<br/> 32KB SRAM                  |      512K FLASH<br/>96K SRAM      | 64KB FLASH<br/>8KB SRAM |  64KB FLASH<br/>8KB SRAM  |      256KB FLASH<br/>32KB SRAM      |      256KB FLASH<br/>32KB SRAM       |        128KB FLASH<br/>20KB SRAM         |      64KB FLASH<br/>20KB SRAM       |
|   **Encoder**    |                      TLE5012B<br/>15bit                      |        TLE5012B<br/>15bit         |    MT6816<br/>14bit     |    TLE5012B<br/>15bit     |          AS5047D<br/>14bit          |          AS5047D<br/>14bit           |             MT6816<br/>14bit             |          AS5600<br/>12bit           |
|    **Driver**    |                           DRV8844                            |              TMC5130              |    EG3013<br/>CJ3400    |     EG3013<br/>A03400     |                A4954                |                A4954                 |                 TB67H450                 |               TMC2209               |
| **Output power** |                     8-48V<br/>1.75A<sub>RMS</sub>                     |        8-42V<br/>1.4A<sub>RMS</sub>        |   7-28V<br/>3.0A<sub>RMS</sub>   |   12-24V<br/>3.0A<sub>RMS</sub>    |         8-25V<br/>2.0A<sub>RMS</sub>         |         8-35V<br/>2.0A<sub>RMS</sub>          |           6-38V<br/>2.5A<sub>RMS</sub>            |         6-30V<br/>1.4A<sub>RMS</sub>         |
|  **Interfaces**  | STEP-DIR<br/>USB2.0<br/>CAN-Bus FD<br/>USART<br/>I2C<br/>SPI / SSI<br/>ABZ | STEP-DIR<br/>UART<br/>SPI<br/>I2C |    STEP-DIR<br/>UART    | STEP-DIR<br/>UART<br/>SPI | STEP-DIR<br/>USB2.0<br/>SPI<br/>I2C | STEP-DIR<br/>USB2.0<br/>UART<br/>I2C | STEP-DIR<br/>USB2.0 or CAN-Bus<br/>RS485 | USB2.0<br/>SPI<br/>I2C<br/>Ethernet |
|  **Size (WDH)**  |                          40x40x10mm                          |            42x42x12mm             |       43x40x12mm        |        40x40x12mm         |             42x42x16mm              |              42x42x16mm              |                40x40x12mm                |             40x40x25mm              |
|    **Status**    |                         Open-Source                          |            Open-Source            |       Open-Source       |        Proprietary        |             Open-Source             |             Open-Source              |               Open-Source                |             Open-Source             |

> The following information is sourced from the analysis of datasheets, official descriptions, and other reliable sources. However, please note that it may be outdated, inaccurate, or incomplete.

## Is there anything else?

There are several other similar products available, but they haven't been described due to the project's confidentiality or lack of information.

- [Emm42](https://github.com/Macrobase-tech/Emm42) by [Macrobase-tech](https://github.com/Macrobase-tech). Status: proprietary
- [AnanasStepper](https://github.com/AnanasRobot/AnanasStepper) by [AnanasRobot](https://github.com/AnanasRobot). Status: V3.0 not released
- [PANdrive](https://www.trinamic.com/products/pandrive-smart-motors/) by [Trinamic](https://www.trinamic.com/). Status: proprietary
