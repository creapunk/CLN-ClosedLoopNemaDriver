# CLN17 V1 Notes

> #### Attention!
>
> This board has been tested, and the functionality of its main components has been confirmed. However, the board has several issues.
>
> You can proceed with its production, but it's recommended to wait for the updated version with all corrections. By using these files, you acknowledge and understand that:
>
> - This version is released for preview purposes only and will not receive future support.
> - Any use of this version is at your own risk. The author is not responsible for any damage caused by the malfunction of this driver version.
> - Subsequent versions may have changes in the BoM and the layout of all board components, including connectors.

#### Known hardware issues:

- Unstable operation when powered from 4.5 to 5.7V. 
	Minor changes have been made to the circuit and the board that might theoretically fix this issue, but the problem may still arise. This might eliminate the possibility of powering solely through Type-C.
- NRST couldn't be reconfigured to function as a user button. This might be fixable through software.
- Incomplete UCPD interface

#### Known software issues:

- The CAN-Bus transceiver physically operates and produces a differential signal, but its software functionality hasn't been tested
- The IMU seems responsive, but the entire library might need to be rewritten for half-duplex SPI operation

#### Not tested:

- The operation of the external HSE crystal and the dependent RTC

	

#### V1.1 fixes:

- Optimised circuit power supply: 
	- Improved power polygon layout; 
	- Improved DCDC converter layout
- Improved Type-C compatibility: 
	- Added full-featured UCPD interface; 
	- Added 5.1k resistors in case UCPD doesn't work
- Optimised components:
	- ESD protection reduced form factor; 
	- Correct USB Type-C connector with both CC lines
