# YAWN - Your Autonomous Wireless Node
This repository presents the developed hardware and software for wireless node based on PIC16LF1459. The repository includes schematic and gerber files as PCB documentation. Furthermore, the software libraries are added for basic node functionality.

# Hardware description
uC: PIC16LF1459 low power microcontroller programmable through header U4 (pins 11-15)

communication modules: nRF24L01+ (SPI) or BLE HM-11 (UART)

sensors: HDC1080 (temperature and humidity sensor) and OPT3001 (light sensor)

power supply: 1.5 F supercapacitor or CR2032 battery. The supercapacictor can be charged through USB port, or through expansions header (i.e. energy harvesting module aka shield, connected to YAWN)

LED: two green and red signalling LED 

push buttons: 4 general purpose push buttons and RESET button

timer: for long interval and minmum sleep current consumption

jumpers: J1-J4 push buttons select jumpers, J5-J6 power supply configuration, J7-J8 DONE pin (timer is used) selector, J11 - VCAP monitor, all other jumpers are header pin selectors

(c) University of Zagreb Faculty of Electrical Engineering and Computing

_Authors : T. Mandic, N. Budimir, A. Baric

_Version : 4

_Date : 2016/01/19
