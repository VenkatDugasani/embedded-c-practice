# AVR Bare-Metal LED Blink (ATmega328P)

## Overview

This is my first attempt at writing bare-metal C code on the ATmega328P (Arduino Uno) without using Arduino functions.

I wanted to understand what actually happens behind things like `digitalWrite()` by directly working with registers.

---

## What I did

I used register-level programming to control the onboard LED connected to **PB5 (Arduino pin 13)**.

Instead of using Arduino libraries, I used:

* `DDRB` to set the pin as output
* `PORTB` to control HIGH/LOW

---

## Key things I learned

* `DDRB` decides whether a pin is input or output
* `PORTB` decides whether the pin is HIGH or LOW
* PB5 maps to Arduino digital pin 13
* Delay functions depend on CPU frequency (`F_CPU`)
* The LED connection is not direct — I checked the schematic to understand how it is wired

---

## Code (core idea)

```c
DDRB |= (1 << DDB5);      // set PB5 as output

PORTB |= (1 << PORTB5);   // LED ON
PORTB &= ~(1 << PORTB5);  // LED OFF
```

---

## How it works

Inside an infinite loop:

* turn LED ON
* wait
* turn LED OFF
* wait
* repeat

---

## Build and upload

```bash
avr-gcc -mmcu=atmega328p -Os -o main.elf LEDBlink1.c
avr-objcopy -O ihex main.elf main.hex
avrdude -c arduino -p m328p -P COM3 -b 115200 -U flash:w:main.hex
```

---

## Issues I ran into

* `avrdude` not recognized (PATH problem)
* figuring out the correct COM port
* confusion about why `F_CPU` is needed for delay

---

## Next

* try using timers instead of delay
* add button input
* move to interrupt-based programs

---

## Author

Venkat Dugasani
