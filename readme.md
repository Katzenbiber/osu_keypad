# osu_keypad

![osu_keypad](https://i.etsystatic.com/10408775/r/il/29aa5e/826177685/il_300x300.826177685_q8ol.jpg)

## About

* Keyboard Maintainer: [Christopher Wróbel](https://github.com/katzenbiber)
* Hardware Supported: LED osu! Keypad (r2)
* Hardware Availability: https://www.etsy.com/de/shop/thnikk (discontinued)
* Original Firmware Source: https://github.com/thnikk/oldKeypad/blob/master/proMicroPadNew/proMicroPadNew.ino (for single color leds)  

This is an alternative firmware using qmk for the LED osu! Keypad (r2). This firmware improves the handling of the side button, to behave like a normal ESC key. This is needed for osu!lazer, as the pause menu requires the ESC button to be held for a short time.

### Implementation Progress:
- [x] Z and X keys
- [x] ESC key as the side button
- [ ] LEDs

## Installation
1. [set up QMK](https://docs.qmk.fm/#/getting_started_build_tools)  
2. drop the whole `osu_keypad` folder into `keyboards`, or clone it as a git submodule 
3. run `qmk compile -kb osu_keypad -km default`

### Flashing for the first time:
1. run `qmk flash -kb osu_keypad -km default`
2. wait until it says `Waiting for USB serial port - reset your controller now`
3. Open and close the Serial port to the Arduino Leonardo with a baudrate of 1200 to get into the bootloader (simplest way is using the Serial Monitor of the Arduino IDE, but other methods should work too)
4. Flashing should start as soon as the board gets detected

### Flashing with this qmk firmware already installed:
1. run `qmk flash -kb osu_keypad -km default`
2. wait until it says `Waiting for USB serial port - reset your controller now`
3. press all buttons at the same time to get into the bootloader 

### Flash original firmware
Unfortunatly qmk doesn't allow for accessing the bootloader by opening an exposed serial port. As such flashing with the Arduino IDE doesn't work. Thus we will use the Arduino IDE to compile the code, and flash it with AVRdude.  
If you have the Arduino IDE installed you should already have AVRdude. On Linux it should be executable by typing `avrdude` into the command line. On Windows it should be somewhere in the Arduino IDE installation (For me it is in `C:\Program Files (x86)\Arduino\hardware\tools\avr\bin\avrdude.exe`). Of course you can download AVRdude additionally, just substitute the paths.

1. download the [original Arduino sketch](https://github.com/thnikk/oldKeypad/blob/master/proMicroPadNew/proMicroPadNew.ino)  
2. open it in the Arduino IDE    
3. go to Tools -> Board and choose Arduino Leonardo
    - if not available, install "Arduino AVR Boards" in the Board Manager
4. press the button in the top left with the checkmark to compile the sketch
    - if the compiler complains about missing libraries go to Tools -> Manage Libaries
    - Install "Bounce2" and "Keyboard"
5. export the compiled binary by going to Sketch -> Export compiled binary
6. go into to Sketch -> Show Sketch Folder  
7. there should be a file called proMicroPadNew.ino.leonardo.hex

#### To flash on Linux:  

- open Terminal and navigate to the binary  

In quick succession:  

    #press all buttons on the keypad to enter bootloader
    sudo avrdude -p m32u4 -c avr109 -P /dev/ttyACM0 -U flash:w:proMicroPadNew.ino.leonardo.hex:i

It might be necessary to change the tty or filename  

#### To flash on Windows:  

1. In the folder with the binary SHIFT + right click
2. Click "Open Powershell here"  
3. press all buttons on the keypad at once (wait for the windows disconnect sound)
4. immideatly run `[System.IO.Ports.SerialPort]::getportnames()`
5. the command should return a COMn port with n being number

I recommend preparing the command beforehand:

- Substitute avrdude path if needed
- Substitute avrdude config path if needed
- Substitute COMn for your COM port
- If needed substitute the file name

In quick succession (wait for the windows disconnect sound):

    #press all buttons on the keypad to enter bootloader
    C:\"Program Files (x86)"\Arduino\hardware\tools\avr\bin\avrdude.exe -p m32u4 -c avr109 -C C:\"Program Files (x86)"\Arduino\hardware\tools\avr\etc\avrdude.conf -P COMn -U flash:w:proMicroPadNew.ino.leonardo.hex:i

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

