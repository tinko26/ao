---
author: "Stefan Wagner"
date: 2022-07-31
description: "The Source Code of the ao Real-Time Operating System (RTOS)."
draft: true
permalink: /code/index-old
title: "Code"
---

# Code



## Overriding Modules

...

- include directories
- therefore, includes generally with brackets instead of quotation marks.
- overriding supports configuration.

Both the `ao` and `ao_sys_xc32_pic32` packages contain an `ao_break.h` module. In order for a project to compile successfully, the compiler must be instructed to include the `ao_break.h` header file of the `ao_sys_xc32_pic32` package rather than the `ao_break.h` header file of the `ao` package. 

This can be achieved by setting up the compiler's include directories properly. For example, the following include directory hierarchy supports a PIC32MZ EF microcontroller.

- `ao_sys_xc32_pic32mz_ef`
- `ao_sys_xc32_pic32mz`
- `ao_sys_xc32_pic32`
- `ao_sys_xc32`
- `ao_sys`
- `ao`

...

## Naming ??

- everything is prefixed
- macro constants and macro functions, that can be used in the definition of macro constants, in uppercase. (or, that can be evaluated at compile time)
- everything else in lower case

## Safety ??

- MISRA C compliance and deviation
