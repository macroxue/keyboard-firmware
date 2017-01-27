# keyboard-firmware

The firmware has been tested on Teensy 3.2 for a split keyboard. It is meant to
be compiled with Teensyduino which can be downloaded from [PJRC website]
(http://www.pjrc.com/teensy/teensyduino.html). In the Arduino IDE (1.6.12 and
above), load `keyboard-firmware.ino`, set USB type to have both keyboard and mouse
(Tools -> USB Type) and compile (Sketch -> Verify/Compile).

To create a new keyboard, look at `left_split.h` and `right_split.h` for
example. You can copy and modify one of them to start. After a new keyboard is
defined, include it in `keyboard-firmware.ino` and comment out all other keyboards.
