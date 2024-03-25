# CLN17-V1.0 Specification

## ⚡ Electrical characteristics

- **Input voltage:** 5-25VDC with overcurrent protection, reverse polarity protection and surge protection
- **Current requirements:** 2A<sub>RMS</sub> with up to 3A peak current
- **Powering options:**
	- 2-Pin connector XH2.5 (3A limited by connector); 
	- 6-Pin control connector XH2.5 with power lines (3A limited by connector);
	- USB Type-C connector (20VDC 5A limited by connector)
- **System voltage source:** On-board 1.4MHz synchronous DC-DC converter

------

## 🔄 Motor Driving Control Capabilities

- **Supported stepper motor form factor:** NEMA17
- **Maximum coil current (bipolar configuration only):**
	- **1.4A<sub>RMS</sub>** per phase continuously
	- **2A<sub>RMS</sub>** per phase with 50% duty cycle (period 1s)
	- **2.5A** peak per phase
- **Maximum output voltage:** 25VDC
- **Maximum step sub-division resolution:** 1/256 of full step
- **Energy saving features:** Passive Braking, Freewheeling and automatic power down
- **Working frequency:** up to 40kHz PWM
- **Phase channel resistance:** Mosfets RDS<sub>ON</sub> 170mΩ for both sides + 100mΩ current sensing resistor
- **True Driver positioning resolution:** Up to 0.028° (may be limited by motor)
- **True Encoder position feedback resolution:** 14bit per full rotation or 0.02° at 20kHz update rate
- **Diagnostic functions:** overheat detection, short-circuit detection, under-voltage detection, open-load detection in case connectors are not firmly plugged in

------

## 🖥️ MCU Performance and External interfaces

**MCU:** High-performance Arm Cortex-M4 MCU **STM32G431CB** running at **170MHz** with:

* **128KB Flash** memory and **32KB SRAM** memory and **1Kb OTP**
* Math accelerator with trigonometric functions calculations support;
* True random number generator
* Internal HSI and RTC with external oscillator option

**Interfaces:**

* **USB2.0** for PC communication
* **CAN-Bus** with CAN-FD support for high-speed or long-range wired connection with daisy chain connection option

- **SWD** programming interface with debug over SWO trace

- **6-Pin connector** with power line and multifunctional bidirectional fast 4-Pin interface up to 8MHz with support:

	* **Classic En/Dir/Step** interface

	* **I2C and UART Single-Wire** for control and diagnostics features

	* **Custom interface** including numerous combination of the above interfaces

- **8-Pin connector** with 1A power line and multifunctional bidirectional fast 6-Pin interface up to 8MHz can be utilized as:

	* **Classic UART** interface

	* **Comparator** or **OpAmp** IO 

	* **4x Analog Channels**

**I/O protection features**:

* ESD protection (persistent against electrostatic discharge)
* USB, SWD and control interfaces are 5V-tollerant
* Reverse polarity signal protection
* Overcurrent protection

**User interaction:**

*  **2** programmable custom **user buttons** (one can be used as reset button)
*  **RGB LED** for indication of working mode or current status

------

## 📏 Mechanical data

- **Size dimensions:** PCB outline is 40x40mm (adapted for NEMA17 form factor) 7.5-12mm total height (depends on the connectors type)
- **Driver housing:** 42x42mm CNC-milled alluminum case for PCB mounting, heatsink and mechanical protection with
- Weight: 
	- **8g**   board only
	- **18g** board with mount
	- **24g** with **low-profile** aluminum housing
	- **28g** with **full-size** aluminum housing

------

## 🔥 Operating conditions

* **Working temperature range:** **-25 to +80** degrees Celcius
* **Environment humidity range:** 0 to 90%
* **Environmental safety:** potential **Lead-Free** and **RoHS** compliance
* **Maximum heat dissipation**: 3W from motor driver and 0.5W from other system
