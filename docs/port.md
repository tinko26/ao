---
author: "Stefan Wagner"
date: 2022-08-29
description: "The port of the ao real-time operating system."
draft: true
permalink: /port/
---

- Alarm interrupt is core timer interrupt, default priority 3
- Task switch interrupt is core software interrupt 1, because lowest natural priority, default priority 1
- Interrupt stack
- Locking: lock priority to keep interrupts enabled, that do not call kernel functions
- timing based on CP0 Count register, that increments every other sysclk
- task context stored on stack, some basic diagnostics to detect overflow/underflow and optimize stack sizes
- drivers for CAN, I2C, SPI, UART, WDT, and RNG
