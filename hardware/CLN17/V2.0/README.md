#  CLN17 V2.0 HARDWARE

[![License: CC BY-NC-SA 4.0](https://img.shields.io/badge/License-CC_BY--NC--SA_4.0-lightgrey.svg)](/license.md)

Compact and powerful driver for NEMA17, an advanced version of CLN17, suitable for 12V, 24V, 36V, and 48V systems with a current of up to 1.75A RMS

`STATUS` As of May 2024, the [board's functionality has been confirmed](#tested-hardware-features). The first batch of boards was produced and sent to testers and developers as part of the BETA testing. The source files have been published.

- [`Specification`](/wiki/CLN17/V2.0/specification.md)
- [`PCBA Manufacturing`](#pcba-manufacturing-specification)

------

### Board Diagram

![](./CLN17-V2.0-BOARD-DIAGRAM.PNG)

------

### STOCK AVAILABILITY

Tentatively, if the results of the beta testing (expected to be completed by mid to late August) do not reveal any design issues and the firmware implementing the basic functionality is finalized, a pre-order for a ready-to-use driver will be available. Tentatively:

- $27 for the stepper upgrade kit with a delivery time of 6 weeks.
- $45 for the assembled closed loop stepper kit with a delivery time of 8 weeks.

Join [the community](https://discord.gg/4uFSsffhMt) to stay updated with all the details.

------

### Attention!

> - **Possible design issues:** the boards have still not undergone comprehensive mass testing to verify specified functionality in the entire range of potential applications.
>
> - **Not Recommended for Mass Production:** The V2.0 Beta design is not optimized for mass production and has several areas that may cause increase  manufacturing defects rate.
>
> - **Not Recommended for Mass Production:** The V2.0 Beta design is not optimized for mass production and has several areas that may cause increase  manufacturing defects rate.
>
> - **Uncompleted firmware:** Firmware of CLN17 V2.0 driver is in active development. May contain unforeseen issues.
>
> - **Potential Design Changes:** The design will undergo minor modifications in the future.
>
> - **No Author Liability:** The author bears no responsibility for any damages resulting from incorrect usage, connections, manufacturing faults, or coding errors.
>
> - **User's Duty:** Users must conduct comprehensive tests in their specific environments. Adherence to provided usage guidelines is crucial.

------

### Tested Hardware Features

Driver IC:

- ✅ DRV8844 PWM generation
- ✅ Active Overcurrent/Overtemperature protection fetures
- ⛔ Freewheeling when unpowered [NOT WORKING DUE TO DRIVER CHIP]
- ✅ Freewheeling when external powered
- ✅ Analog Current sensing
- ✅ FOC Support

Encoder IC:

- ✅ TLE5012 SPI communication
- ✅ TLE5012 through the PCB position sensing (1LSB noise)

Power:

- ✅ Daisy Chain Power connection
- ✅ DCDC stability at voltage range [External: 5.8V-25V, USB: 4.9V-5.5V]
- ✅ ENB CLTR 5V (Power Sink & Source 5V 200mA)

Interfaces:

- ✅ USB communication
- ✅ CTRL connector - UART, I2C, SPI communication (ABZ not tested yet)
- ✅ CAN-Bus IC Shutdown and Logic supply, diff signal generation
- ✅ Expansion connector - UART communication
- ✅ SWD with reset functionality

Peripherals:

- ✅ SW1 & SW2 as button
- ✅ RESET using SW2 as output
- ✅ RGB LED (single color indication)
- ✅ External Precise Clock (10ppm) (HSE)

------

### PCBA Manufacturing Specification

- **Layers**: 4
- **Minimum Via Hole Size/Via Diameter**: 0.25mm/0.45mm
- **Minimum track width/spacing**: 0.13mm/0.13mm
- **Material**: FR4
- **PCB Thickness**: 1mm [preferred]
- **PCB Color**: Any, but black is more aesthetic.
- **PCB Surface Finish**: ENIG [preferred]
- **Outer/Inner Copper Weight**: 1oz/0.5oz or 1oz/1oz
- **Via Covering**: Plugged [preferred] or Tented
- **Board Outline Tolerance**: ±0.2mm
- **Panelization**: optional, but if horizontal connectors used, the gap between boards should be ≥5mm.
- **Assembly**: Single top side
- **Tooling Holes**: Already present 4x D1.152mm in the corners of the board. May require modification for specific equipment.

#### Important Notes

> ***Non-stock Components Note:** The design features 3 irreplaceable components: the driver chip, microcontroller, and encoder. Other parts can be replaced with in-stock equivalents that match or surpass the original specs, provided you conduct a schematic review beforehand.*

> ***Cost Reduction Note:** Eliminate unused components such as the CAN-Bus or CTRL connector to reduce costs, provided you conduct a schematic review beforehand.*

------

### Support the Project!

**If you like the project and want to support its development, you can do so through:**

- **[Ko-fi](https://ko-fi.com/creapunk)** (*preferred for membership subscription and one-time donation*) - here, you can sign up for monthly support, or you can make a one-time donation as well!
- **[Patreon](http://patreon.com/creapunk)** - similar to Ko-fi, but with higher fees.

Don't forget to join **[creapunk community on Discord](https://discord.gg/4uFSsffhMt)** for the latest updates and discussions!

------

Special thanks to [JLCPCB](https://jlcpcb.com/?from=creapunk) for sponsoring the board manufacturing of this design!

[![img](/wiki/assets/sponsors/JLCPCB.png)](https://jlcpcb.com/?from=creapunk)
