# CLN17-V2.0 Specification

## ⚡ Electrical characteristics

- **Input voltage:** 8-48VDC with overcurrent protection, reverse polarity protection and surge protection
- **Current requirements:** 2A~RMS~ with up to 3A peak current
- **Powering options:**
	- 2-Pin connector **XH2.5** (3A limited by connector); 
- **System voltage source:** 
	- On-board 1.4MHz synchronous DC-DC converter
	- USB Type-C connector (5VDC 1.5A limited by design)
	- CTRL connector (5VDC 1A limited by design)


------

## 🔄 Motor Driving Control Capabilities

- **Supported stepper motor form factor:** NEMA17
- **Maximum coil current (bipolar configuration only):**
	- **1.75A~RMS~** per phase continuously
	- **2A~RMS~** per phase with 50% duty cycle (period 1s)
	- **2.5A** peak per phase
- **Maximum output voltage:** 48VDC
- **Maximum step sub-division resolution:** 1/256 of full step
- **Energy saving features:** Passive Braking, Freewheeling and automatic power down
- **Working frequency:** up to 40kHz PWM (allows silent and smooth motion)
- **Phase channel resistance:** Mosfets RDS~ON~ 580mΩ for both sides + 20mΩ current sensing resistor
- **True Driver positioning resolution:** Up to 0.028° (limited by motor)
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
- **5-Pin CTRL connector PH2.0** with multifunctional bidirectional fast 4-Pin interface up to 8MHz with support:
  * **Classic EN/DIR/STEP** interface with **ERR line**

  * **USART** (Single wire, Asynchronous, Synchronous)

  * **I2C**

  * **SPI or SSI**

  * **ABZ incremental interface** for external encoder connection with programmable **5V voltage source**

  * **Custom interface** including numerous combination of the above interfaces
- **4-Pin expansion connector 2x2P2.0** with 2A power line and multifunctional bidirectional fast 2-Pin interface up to 8MHz with **Classic UART** interface

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
* **Environmental safety:** **Lead-Free** and **RoHS** compliance
* **Maximum heat dissipation**: 3W from motor driver and 0.5W from other system
