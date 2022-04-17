# osu_keypad

![osu_keypad](https://i.etsystatic.com/10408775/r/il/29aa5e/826177685/il_300x300.826177685_q8ol.jpg)

## About

* Keyboard Maintainer: [Christopher Wróbel](https://github.com/katzenbiber)
* Hardware Supported: LED osu! Keypad (r2)
* Hardware Availability: https://www.etsy.com/de/shop/thnikk (discontinued)
* Original Firmware Source: https://github.com/thnikk/oldKeypad/blob/master/proMicroPadNew/proMicroPadNew.ino  

### Implemented:
- Z and X keys
- ESC key as the side button

### Not Implemented:
- LEDs (neither RGB nor white)

## ⚠️❗```Warning```❗⚠️  
Currently this configuration overwrites the Arduino bootloader. As such you won't be able to flash the device a second time using the Arduino IDE or AVRdude without an ICP Programmer like USBasp. 

## Compiling and Flashing 
Compile Firmware (after setting up your build environment):

    qmk compile -kb osu_keypad -km default

Flashing example for this keyboard on Windows:

1. Open and close the Serial port to the Arduino Leonardo with a baudrate of 1200
2. A new COM port should open up to flash the firmware
3. Use AVRdude to flash the .hex file to the new COM port (if you have the Arduino IDE installed you can copy paste the avrdude command as shown in this [video](https://youtu.be/C5bJ8LyxhvU))

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

