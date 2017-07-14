# FeyerPower: Firmware for Tippmann X7 Phenom

The goal of the FeyerPower Project is to develop firmware for the Tippmann X7 Phenom that matches
and surpasses the features of the factory firmware. This project started from a desire
to disable the "three shot safety" associated with the enhanced firing modes of the
factory firmware.

The FeyerPower Project is not affiliated with or endorsed by Tippmann. This project is made
available to you without any warranty, whether express or implied. The user accepts all
risks associated with using this project, whether known or unknown. Always heed all
cautions and warnings included in the user manual that was included with your paintball gun.
Never point a paintball gun at anything that you don't want to shoot.

## Features

| Feature                                              | FeyerPower   | Tippmann  |
| ---------------------------------------------------- |:------------:|:-----:|
| Three Shot Safety for Enhanced Modes                 | Configurable | Mandatory |
| Semi-Automatic Firing Mode                           | Yes          | Yes |
| Auto-Response Firing Mode                            | Yes          | Yes |
| Three Shot Burst Firing Mode                         | Yes          | Yes |
| Turbo Firing Mode                                    | Yes          | Yes |
| Fully Automatic Firing Mode                          | Yes          | Yes |
| Configurable Firing Rate (Balls Per Second)          | Yes          | Yes |
| Configurable Dwell Time                              | Yes          | Yes |
| Configurable Debounce Time                           | Yes          | Yes |
| Low Battery Indicator                                | (not yet)    | Yes |
| Select Firing Mode Outside Configuration Menu        | Yes          | Yes |
| Save Firing Mode Selected Outside Configuration Menu | (not yet)    | Yes |

## Operating a FeyerPower-equipped paintball gun

FeyerPower can be booted into either "shooting" (normal) or "configuration" (menu) mode.

### Shooting (normal) mode

Shooting mode enables you to use the paintball gun like it's a paintball gun and shoot
stuff.

To boot into "shooting" mode, turn the paintball gun's selector switch to the electronic
firing mode position without holding down the recessed pushbutton.

### Configuration mode

Configuration mode enables you to adjust the settings of your paintball gun. Though it
is not possible to use the paintball gun like a paintball gun in configuration mode,
accidental discharge is always possible; never point your paintball gun at anything
you do not want to shoot.

Configuration mode let's you adjust settings through a menu. First you
select the variable that you want to adjust, then you select the new value for that
variable.

To boot into "configuration" mode, hold down the recessed pushbutton while turning the
paintball gun's selector switch to the electronic firing mode position.  Continue
holding the recessed pushbutton until the recessed light (TODO).

## Installing

Once you begin to install the FeyerPower firmware on your paintball gun, your
gun will no longer have the factory firmware installed.  It is not possible to
reinstall the factory firmware. Installing the FeyerPower firmware will erase
any settings you may have configured, such as (but not limited to) dwell time
and debounce time.

To install FeyerPower firmware on your paintball gun, you will need:

* paintball gun
* FeyerPower firmware binary image (produced by the "Building" instructions below)
* programming device compatible with an Atmel AVR attiny44 target
* programming software compatible with your programming device, such as Atmel Studio

## Building

Use can use Atmel Studio software to build the source code of the FeyerPower Project
into a firmware binary image that can be installed on your paintball gun.

## Developing

TODO
