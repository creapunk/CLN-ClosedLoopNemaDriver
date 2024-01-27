# Firmware for CLN17 drivers 

***Note:** This page will be updated during the firmware development process for CLN17*

------

## TODO

### Motion Control

Responsible for interfacing with the motor driver chip and its movement.

- TMC2209 UART driver control library
  - ✅ Interface with TMC2209 registers, read and write via UART SW
  - Library optimization for peripheral operations without MCU overhead
  - Hardware CRC computation support for faster operation
  - Direct peripheral interfacing
  - Buffer for 4 commands for efficient parameter updates
- Periodic calculation of the function [delta steps / dt] from t based on given parameters:
  - Target displacement
  - Specified or maximum speed
  - Specified or maximum acceleration
  - Specified or maximum jerk
- Different motion patterns algorithms
  - Triangle motion ramp
  - Trapezoidal motion ramp
  - S-Shaped motion ramp
  - Constant speed motion
- Quad half bridge driver (CLN17 V2.0)
	- Sine PWM generation
	- Same program interface as TMC2209 driver
	- Error handling
	- Current sensing


### Position Supervisor

- TLE5012 SPI encoder library
	- Interfacing with registers via SPI
	- Detection of successful initialization and configuration
- Absolute coordinates controller
	- Periodic absolute position updates at a specified frequency
	- Setting, offsetting, or resetting the coordinate system's zero
- Stepper motor position controller
	- Calculation and adjustment of motor position during its movement
- Position error detector
	- Comparing the difference between the motor's physical and theoretical positions
	- Error occurrence action handler

### Error-Recovery

Handles system error compensation algorithms.

- Simple position error notification to the higher-level controller in the hierarchy
- Rollback and execution of the last error-causing command
- Active PID compensation (?)

### Motion Planner

Responsible for converting abstract commands into a standard format for the Motion Control algorithm.

- G-Code overlay
- Klipper overlay (?)
- Step-Dir interface handling
- Custom overlays for UART/I2C/CAN-Bus

### System Parameters Control

Ensures safe system operation and error detection.

- Operating voltage
- Overheat prevention
- Interface error prevention
- Motor connection detection
- Encoder magnet presence check

### Additional Algorithms

- Sensorless parking
- Workspace size auto-detection
- RTC and stand-alone operation systems

------

## Supporting the Project

If this project resonates with you, please consider the following ways to support its development:

- **[Ko-fi](https://ko-fi.com/creapunk):** Preferred for membership subscription and one-time donation
- **[Patreon](https://patreon.com/creapunk):** Alternative platform with higher fees
- **Join [Discord community](https://discord.gg/V4aJdTja8v):** Stay updated, engage in discussions, and contribute to the project

**Your contribution, regardless of size, is greatly appreciated!** 

*A heartfelt thank you to [everyone who supports this project](sponsors.md)!*