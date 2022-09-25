---
author: "Stefan Wagner"
date: 2022-09-25
draft: true
permalink: /port/
---

- Alarm interrupt is core timer interrupt, default priority 3
- Task interrupt is core software interrupt 1, because lowest natural priority of both core software interrupts, default priority 1
- Interrupt stack
- Locking: lock priority to keep interrupts enabled, that do not call kernel functions
- timing based on CP0 Count register, that increments every other sysclk
- task context stored on stack, some basic diagnostics to detect overflow/underflow and optimize stack sizes
- drivers for CAN, I2C, SPI, UART, WDT, and RNG
