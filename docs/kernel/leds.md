---
author: "Stefan Wagner"
date: 2022-08-08
description: "LEDs in the ao Real-Time Operating System (RTOS)."
draft: true
permalink: /kernel/leds/
title: "LEDs"
---

# LEDs

The `ao_led.h` module encapsulates [LEDs](https://en.wikipedia.org/wiki/Light-emitting_diode) that can be switched on and off. The number of LEDs is defined by a macro constant.

```c
#define AO_LED_COUNT
```
