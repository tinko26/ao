---
author: "Stefan Wagner"
date: 2022-07-31
description: "The Source Code of the ao Real-Time Operating System (RTOS)."
draft: true
permalink: /code/index-old
title: "Code"
---

# Code


## Modules

...

## Hardware-Agnostic Modules

The modules of the `ao` and `ao_sys` packages are implemented in a strict hardware-agnostic fashion. That is, they do not contain interrupt handlers, assembly code, or the like. They only rely on the declarations and definitions of the following header files of a freestanding runtime environment.

- `float.h`
- `stdbool.h`
- `stddef.h`
- `stdint.h`

## Hardware-Specific Modules

In contrast, the modules of the `ao_sys_xc32` and `ao_sys_xc32_pic32` packages are toolchain-specific and hardware-specific, respectively. They include the compiler's `xc.h` header file and make heavy use of non-standard language features, mostly for the sake of execution speed. Additionally, they facilitate functions of the toolchain's implementation of the C standard library.

## Abstract Modules

Kernel functions cannot be implemented thoroughly without hardware-specific features, such as instructions for masking interrupts. In order to achieve a separation of hardware-agnostic modules nonetheless, the `ao` and `ao_sys` packages contain abstract modules. These modules declare necessary functions, but do not define them. 

For example, the `ao_break.h` module declares, but does not define, a function that executes a breakpoint.

```c
void ao_break();
```

An implementation of this function can be found in the `ao_sys_xc32_pic32` package. It makes use of a built-in function provided by the XC32 compiler. For the sake of simplicity and execution speed, it is implemented as a macro function rather than an ordinary function.

```c
#define ao_break() __builtin_software_breakpoint()
```

## Include Directories

Both the `ao` and `ao_sys_xc32_pic32` packages contain an `ao_break.h` module. In order for a project to compile successfully, the compiler must be instructed to include the `ao_break.h` header file of the `ao_sys_xc32_pic32` package rather than the `ao_break.h` header file of the `ao` package. 

This can be achieved by setting up the compiler's include directories properly. For example, the following include directory hierarchy supports a PIC32MZ EF microcontroller.

- `ao_sys_xc32_pic32mz_ef`
- `ao_sys_xc32_pic32mz`
- `ao_sys_xc32_pic32`
- `ao_sys_xc32`
- `ao_sys`
- `ao`

# DRAFT

## General

- written in C
- standard C99, especially fixed-width integer types and boolean type and constants

## Usage

- set up include directories properly
- provide ao.h, that includes all required modules (and excludes everything that is not needed, therefore saving space and minimizing the footprint).

## Misc

- include_next
- MISRA C compliance and deviation
- memory management (static)
- memory initialization

## Configuration

- via header file overrides
