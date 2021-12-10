# keyboard-firmware

The firmware has been tested on Teensy 3.2 and Teensy LC for a split keyboard.
It is meant to be compiled with Teensyduino which can be downloaded from
[PJRC website](http://www.pjrc.com/teensy/teensyduino.html).
My development environment runs on Linux Mint. Other variants in the Debian
family, like Ubuntu, should be fine too but I didn't verify.

To support multiple keyboards nicely, the firmware should be installed as an
Arduino library. The easiest way is to create a symbolic link to a clone of
this repository under the directory of Arduino libraries. For example,
```
~/Downloads/arduino-1.8.7/libraries/keyboard-firmware -> ~/projects/keyboard-firmware
```
but your paths may be different. The exact `keyboard-firmware` directory name
must be used or Arduino will complain.

To create a new keyboard, look at the files in `keyboards/` directory for examples.
In particular, I've been using the [Darknight keyboard](https://github.com/macroxue/keyboard-diy)
for several years. Its definition
[`darknight.ino`](https://github.com/macroxue/keyboard-firmware/blob/master/keyboards/darknight/darknight.ino)
has multiple layers including a VI-like one. You can copy and modify
any of the keyboards to start.

After a keyboard is defined, the next step is to compile it and upload it to Teensy.
In the Arduino IDE (1.6.12 and above), open the `.ino` file, set USB
type to have both keyboard and mouse (Tools -> USB Type), compile (Sketch ->
Verify/Compile) and upload (Sketch -> Upload) to the Teensy board.

## Switching between layers

Each keyboard can have multiple layers. Each layer has an associated Fn layer.
There are three ways to switch to another layer.

1. Hit a layer key, e.g. switching to layer 2 by hitting `l2` key in the
   current layer.
2. Press and hold the `fn` key to shift to the Fn layer of the current layer.
   Once the `fn` key is released, it's back to the previous layer. This is
   similar to how Shift key works.
3. Hit the `fnl` key and lock to the Fn layer of the current layer. Hit the
   `fnl` key again to go back to the previous layer. This is similar to the
   use of CapsLock key.

If a modifier can be held down while the layer is switched, it must exist in
the new layer on the same physical key or the behavior is undefined when the
modifier is released.

## Defining dual-role modifiers

Modifiers such as `control`, `alt`, `shift` and `fn` can be redefined when they
are tapped without being combined with another key. For example, a `control`
key produces `esc` when tapped alone. It can also be viewed the other way
around: the `esc` becomes a `control` key when it's held down and combined with
another key.

Dual-role modifiers can reduce the number of physical keys and produce a
compact layout like [Darknight keyboard](https://github.com/macroxue/keyboard-diy)
when used properly. However, they can also lead to issues of mistyping at high
speed when a dual-role key is not released before the next key is pressed. It's
almost impossible to reliably determine whether the next key should be modified
or not. So the general recommendation is to have dual-role modifiers produce
infrequently used keys or keys that are not quickly followed by other keys.

## Using VI translator for a layer

A layer can optionally have a translator to convert a sequence of keys to
another sequence of keys. This is similar to having macros, but more generic.

For now, there is one built-in translator to provide VI-like editing commands.
I have long been missing VI's power in a browser environment, say, when
writing an email. Now with the VI translator, I can move the cursor to the
beginning of the line with "0" and then change the three words there with "c3w".
Or, I can fix a typo with "xp" quickly.

The translator can't do everything that VI does but it does provide a usable
VI-like environment almost everywhere.

## Dumping debug info

A debug layer can be installed to dump info about the keyboard. The following
keys are supported by the debug layer. Make sure you're in an editor before
invoking the dumps.

* The 'p' key shows column pins and row pins.
* The 'l' key shows all layers.
* The 'h' key shows heat maps of keystrokes in all layers.
