---
author: "Stefan Wagner"
date: 2022-08-04
description: "Breakpoints in the ao Real-Time Operating System (RTOS)."
draft: false
permalink: /environment/break/
title: "Breakpoints"
---

# Breakpoints

The `ao_break.h` module declares a single function that executes a [breakpoint](https://en.wikipedia.org/wiki/Breakpoint).

```c
void ao_break();
```

The purpose of this declaration is to have a hardware-agnostic abstraction that can be used to write portable code. Since a breakpoint is a hardware-specific operation, the environment package does not provide a definition. 

Consequently, such a definition must be provided by a hardware-specific package by overriding this module. In the case of PIC32 microcontrollers, this override calls an XC32 compiler's built-in function, which in turn executes the `SDDBP 0` instruction.

```c
#define ao_break() __builtin_software_breakpoint()
```
