# CLN - CLOSED-LOOP DRIVERS FOR NEMA MOTORS

[![License: CC BY-NC-SA 4.0](https://img.shields.io/badge/License-CC_BY--NC--SA_4.0-lightgrey.svg)](license.md)

[![CLN17](./wiki/assets/CLN17.jpg)](https://www.youtube.com/watch?v=A67UROq0t6Q)

The CLN motor driver series is an **open-source** project aimed at creating a range of compact, cost-efficient high-performance closed-loop stepper drivers for various NEMA form factor motors. These drivers are designed to provide silent and smooth motion, high-precision position control, and energy-saving capabilities, suitable for a wide array of applications in robotics, CNC machines, 3D printers, and more.

## Key Features

- 🕹️ **Closed-Loop Control:** Integrates an encoder for real-time position monitoring, ensuring precise and safe motion.
- 📏 **Fine Positioning:** Achieves high position control accuracy of 0.01° for smooth operation.
- 🛡️ **Reliable Operation and Enhanced Safety:** Features integrated diagnostic and protection mechanisms for the motor and the user safety.
- 🧩 **Modular Concept:** Offers various configurations for different cost, size and performance needs, supporting expansion boards and daisy chain connections.

## Applications

- 🎓 Learning Platforms
- 🛠️ CNC Machines & 3D printers
- 🤖 Robotics & Automation Systems
- 🤝 Collaborative Robots
- 🔭 Camera & Telescope Stabilization Systems
- 🔬 Laboratory Equipment
- 🏭 Industrial Motion Control Systems
- 📳 Haptics & Force Feedback Systems

## Repository Structure

- **[`wiki`](wiki)**: includes design documentation and other information
- **[`hardware`](hardware)**: contains design source files, manufacturing files, schematics, block diagrams and 3D models
- **[`firmware`](firmware)**: [to be updated as the project evolves]

## Hardware Versions

#### [NEMA17 dedicated drivers](./wiki/CLN17/readme.md)

- **[`V1.0`](hardware/CLN17/V1.0)** [obsolete]: pilot version [[wiki]](./wiki/CLN17/V1.0/specification.md)

  > - **Key info:** TMC2209 based, 5-25V 1.4A~RMS~, 15bit position feedback, two-sided assembly
  >- **Supported interfaces:** STEP-DIR-EN, USB, CAN-FD, UART, I2C
  > - **Release of source files:** Released
  
  

- **[`V1.5`](hardware/CLN17/V1.5)** [tested]: cost-efficient version [[wiki]](./wiki/CLN17/V1.5/specification.md)

  > - **Key info:** TMC2209 based, 5-25V 1.4A~RMS~, 15bit position feedback, single-sided assembly
  >- **Supported interfaces:** STEP-DIR-EN, USB, CAN-FD, USART, I2C, SPI, ABZ
  > - **Release of source files:** Released
  
  

- **[`V2.0`](hardware/CLN17/V2.0)** [under testing]: high voltage version [[wiki]](./wiki/CLN17/V2.0/specification.md)

	> - **Key info:** DRV8844 based, 8-48V 1.75A~RMS~, 15bit position feedback, single-sided assembly
	>- **Supported interfaces:** STEP-DIR-EN, USB, CAN-FD, USART, I2C, SPI, ABZ
	> - **Release of source files:** February 2024
	

***Important Note:** V1 design is obsolete and will not be supported in future, please wait for V1.5 or V2 release*

## Hardware Development Roadmap

- **[February 2024]** - End of testing for CLN17 V2.0, release of their source files
- **[March 2024]** - CLN234 design for Nema23, Nema34 and Nema42 and new external board to enhance driver capabilities and integration
- **[April 2024]** - CLN14 for Nema14 miniature motors

***Important Note:** If critical problems will be revealed, the schedule will be updated*

## Supporting the Project

If this project resonates with you, please consider the following ways to support its development:

- **[Ko-fi](https://ko-fi.com/creapunk):** Preferred for membership subscription and one-time donation
- **[Patreon](https://patreon.com/creapunk):** Alternative platform with higher fees
- **Join [Discord community](https://discord.gg/V4aJdTja8v):** Stay updated, engage in discussions, and contribute to the project

**Your contribution, regardless of size, is greatly appreciated!** 

*A heartfelt thank you to [everyone who supports this project](sponsors.md)!*

---

***Important Note:** This README will be updated to reflect the latest progress and changes in the project*.

