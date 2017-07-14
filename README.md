# FeyerPower: Firmware for Tippmann X7 Phenom

The goal of the FeyerPower Project is to develop firmware for the
[Tippmann X7 Phenom electro-pneumatic paintball gun](http://www.tippmann.com/p/x7-phenom?pp=24)
that matches
and surpasses the features of the factory firmware. This project started from a desire
to disable the "three shot safety" associated with the enhanced firing modes of the
factory firmware.

The FeyerPower Project is not affiliated with or endorsed by Tippmann. This project is made
available to you without any warranty, whether express or implied. The user accepts all
risks associated with using this project, whether known or unknown. Always heed all
cautions and warnings included in the user manual that was included with your paintball gun.
Never point a paintball gun at anything that you don't want to shoot.

## Features

| Feature                                               | FeyerPower   | Tippmann  |
| ----------------------------------------------------- |:------------:|:---------:|
| Three Shot Safety for Enhanced Modes                  | Configurable | Mandatory |
| Semi-Automatic Firing Mode                            | Yes          | Yes       |
| Auto-Response Firing Mode                             | Yes          | Yes       |
| Three Shot Burst Firing Mode                          | Yes          | Yes       |
| Turbo Firing Mode                                     | Yes          | Yes       |
| Fully Automatic Firing Mode                           | Yes          | Yes       |
| Configurable Firing Rate (Balls Per Second)           | Yes          | Yes       |
| Configurable Dwell Time                               | Yes          | Yes       |
| Configurable Debounce Time                            | Yes          | Yes       |
| Low Battery Indicator                                 | (not yet)    | Yes       |
| Select Firing Mode while in Shooting Mode             | Yes          | Yes       |
| Save Firing Mode Selected while in Shooting Mode      | (not yet)    | Yes       |
| Save Firing Mode Selected while in Configuration Mode | Yes          | Yes       |
| Processor Sleeps to Extend Battery Life               | Yes          | (unknown) |

## Operating a FeyerPower-equipped paintball gun

A paintball gun with FeyerPower firmware installed can be booted into either
"shooting" (normal) mode or "configuration" (menu) mode. Instructions for
installing the FeyerPower firmware can be found in the "Installing" section
later in this document.

### Shooting (normal) mode

Shooting mode enables you to use your paintball gun as a paintball gun to deliberately
shoot stuff.

To boot into "shooting" mode, turn the paintball gun's selector switch to the electronic
firing mode position without holding down the recessed pushbutton.

### Configuration mode

Configuration mode enables you to adjust the settings of your paintball gun. While it
is not possible to use your paintball gun as a paintball gun while in configuration mode,
accidental discharge is always possible; never point your paintball gun at anything
you do not want to shoot.

Configuration mode let's you adjust settings through a menu. First you
select the variable that you want to adjust, then you select the new value for that
variable.

To boot into "configuration" mode, hold down the recessed pushbutton while turning the
paintball gun's selector switch to the electronic firing mode position.  Continue
holding the recessed pushbutton until the recessed light (TODO).

## Installing

Installing the FeyerPower firmware on your paintball gun will erase the factory firmware.
It is not possible to reinstall the factory firmware once it has been erased.
Installing the FeyerPower firmware will also erase any settings that you may have configured,
such as (but not limited to) dwell time and debounce time.

To install FeyerPower firmware on your paintball gun, you will need:

* paintball gun
* FeyerPower firmware binary image file
  * instructions for creating this file can be found in the "Building" section later in this document
* programming device capable of programming your paintball gun's [Atmel AVR ATtiny44 microcontroller](http://www.atmel.com/images/doc8006.pdf)
  * we use an [Atmel AVR Dragon](http://www.atmel.com/tools/avrdragon.aspx)
* programming software compatible with your programming device
  * we use [Atmel Studio](http://www.atmel.com/tools/atmelstudio.aspx)
* means of connecting programming device to paintball gun's microcontroller
  * we use a [Pomonoa 5251](http://www.pomonaelectronics.com/pdf/d5250-54_5437_1_01.pdf) test clip
  * consider adding jumper wires, such as [Adafruit 793](https://www.adafruit.com/product/793)

Your paintball gun's microcontroller came from the factory with a sticker indicating
which version of firmware the factory installed on it. Remove this sticker to avoid
confusion later.

## Building

You can use [Atmel Studio](http://www.atmel.com/tools/atmelstudio.aspx) software to
generate a firmware binary image file from the source code of the FeyerPower Project.

## Developing

### Board design

An Atmel AVR ATtiny44 8-bit microcontroller is at the core of the design of the
Phenom's circuit board.  It functions as the gun's brain.  It processes inputs
from the following sensors and sends outputs to the following actuators.

#### Sensors (inputs)
* Trigger
* Pushbutton

#### Actuators (outputs)
* Solenoid
* Red LED
* Green LED

### Tips

* You can purchase additional electronics assemblies from Tippmann as part number TA99600 "Hall Effect Electronics (Electro-pneumatic mode". We use two: one with the factory firmware to use as a reference, and one with FeyerPower firmware.

* Consider building a "test bed" on a breadboard to make development and testing easier.
An Atmel AVR ATtiny44 micrcontroller in a DIP package is easier to work with during
software development.  Even though it is a different shape from the microcontroller on
your paintball gun's electronics assembly, they are identical from an electrical and
firmware perspective.  The DIP package can be stuck onto a standard breadboard, which makes
it easy to make reliable connections.  Add LEDs and pushbuttons onto the breadboard to
substitue for the LEDS, trigger, and pushbutton on the gun.  Working directly with the microcontroller on
the electronics assembly can be a hassle because 1) magnets must be positioned just right
to enable power, 2) magnets must be positioned just right to effect a trigger pull,
and 3) the test clip can easily be knocked loose.

* Power your board with a 9V DC power supply instead of a battery during
development and testing to avoid the frustrations of depleted batteries.
