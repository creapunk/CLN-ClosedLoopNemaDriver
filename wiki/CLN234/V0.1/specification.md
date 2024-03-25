# CLN234-V0.1 Specification

## ⚡ Electrical characteristics

- **Input voltage:** 6-52VDC with overcurrent protection, reverse polarity protection and surge protection
- **Current requirements:** 10A<sub>RMS</sub> with up to 20A peak current
- **Powering options:**
	- P5.08 screw terminal / Pluggable screw terminal system
- **System voltage source:** 
	- On-board DC-DC converter
	- USB Type-C connector (5VDC 1.5A limited by design)


------

## 🔄 Motor Driving Control Capabilities

- **Supported motor type:** Dual DC, Steppers, BLDC, PMSM
- **Supported NEMA motors:** NEMA23, NEM34, NEMA42, other
- **Maximum phase current:**
	- **10A<sub>RMS</sub>** per phase continuously
	- **13A<sub>RMS</sub>** per phase with 50% duty cycle (period 1s)
	- **20A** peak per phase
- **Maximum output voltage:** 52VDC
- **Maximum step sub-division resolution:** 1/512 of full step
- **Energy saving features:** Passive Braking, Freewheeling and automatic power down
- **Working frequency:** up to 83kHz PWM
- **Phase channel resistance:** Mosfets RDS<sub>ON</sub> 20mΩ for both sides + 2.5mΩ current sensing resistor
- **Encoder position feedback resolution:** 16bit/21bit per full rotation or 0.005° at 20kHz update rate
- **Diagnostic functions:** overheat detection, short-circuit detection, under-voltage detection, open-load detection

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
- First **5-Pin CTRL connector PH2.0**:
  * **Classic EN/DIR/STEP** interface with **ERR line**
  * **USART** (Single wire, Asynchronous, Synchronous)
  * **SPI or SSI**
  * **ABZ incremental interface** for external encoder connection with program-controlled **5V voltage source**
- Second **5-Pin CTRL connector PH2.0**:
	- **Classic EN/DIR/STEP** interface or **DIR/STEP** with **ERR line**
	- **I2C**
	- **ABZ incremental interface** for external encoder connection

- **4-Pin expansion connector 2x2P2.0** with 2A power line and multifunctional bidirectional fast 2-Pin interface up to 8MHz with **Classic UART** interface

**I/O protection features**:

* ESD protection (persistent against electrostatic discharge)
* USB, SWD and control interfaces are 5V-tollerant
* Reverse polarity signal protection
* Overcurrent protection

**User interaction:**

*  Reset button

------

## 📏 Mechanical data

- **Size dimensions:** 
	- PCB outline: 54x54mm (adapted for NEMA23 form factor)
	- PCB circumcircle radius: 60mm
	- PCBA Height: 15mm

- Weight: 
  - **8g**   board only
  - **18g** board with mount
  - **24g** with **low-profile** aluminum housing
  - **28g** with **full-size** aluminum housing

------

## 🔥 Operating conditions

* **Working temperature range:** **-25 to +80** degrees Celsius
* **Environment humidity range:** 0 to 90%
* **Environmental safety:** potential **Lead-Free** and **RoHS** compliance
* **Maximum heat dissipation**: 20W from motor driver and 0.5W from other system
