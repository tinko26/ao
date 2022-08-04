---
author: "Stefan Wagner"
date: 2022-07-31
description: "The Source Code of the ao Real-Time Operating System (RTOS)."
draft: true
permalink: /code/
title: "Code"
---

# Code

## Location

The source code of the RTOS is located in the repository's `src` folder. 

## Packages

The source code is subdivided into C files and folders containing header files. Thereby, folders and corresponding C files constitute a total of four packages.

### ao

This package is an extension to the freestanding runtime [environment](../environment/index.md). It provides environment constants and variables, type definitions, support for debugging, as well as useful functions and data structures. It consists of the `ao` folder and the `ao.c` file.

### ao_sys

This package contains the [kernel](../kernel/index.md). It provides all the basic features that a thorough RTOS is expected to have, i.e. multitasking, priority-based real-time scheduling, inter-process communication, and synchronization. It consists of the `ao_sys` folder and the `ao_sys.c` file.

### ao_sys_xc32

This package contains support for the XC32 compiler. It consists of the `ao_sys_xc32` folder, only, and has no corresponding C file.

### ao_sys_xc32_pic32

This package contains a [port](../port/index.md) for PIC32 microcontrollers. It consists of the `ao_sys_xc32_pic32.c` file and the following folders.

- `ao_sys_xc32_pic32`
- `ao_sys_xc32_pic32_can`
- `ao_sys_xc32_pic32_i2c`
- `ao_sys_xc32_pic32_rng`
- `ao_sys_xc32_pic32_spi`
- `ao_sys_xc32_pic32_uart`
- `ao_sys_xc32_pic32_wdt`
- `ao_sys_xc32_pic32mk`
- `ao_sys_xc32_pic32mk_gp`
- `ao_sys_xc32_pic32mk_gpg`
- `ao_sys_xc32_pic32mk_gpk`
- `ao_sys_xc32_pic32mx`
- `ao_sys_xc32_pic32mx_1xx`
- `ao_sys_xc32_pic32mx_1xx_64_100`
- `ao_sys_xc32_pic32mx_1xx_xlp`
- `ao_sys_xc32_pic32mx_330`
- `ao_sys_xc32_pic32mx_3xx`
- `ao_sys_xc32_pic32mx_5xx`
- `ao_sys_xc32_pic32mz`
- `ao_sys_xc32_pic32mz_da`
- `ao_sys_xc32_pic32mz_dak`
- `ao_sys_xc32_pic32mz_ec`
- `ao_sys_xc32_pic32mz_ef`

## Modules

Each package is made up of modules. For each module, there is a dedicated header file. The `ao` package, for example, contains the `ao_break.h` module, that declares a single function that executes a breakpoint. 

```c
void ao_break();
```

Modules can depend on each other. For example, the `ao_assert.h` module defines a macro function for runtime assertions. Due to the way it is implemented, it depends on the `ao_break.h` module.

```c
#define ao_assert(exp)  \
{                       \
  if (!(exp))           \
  {                     \
    ao_break();         \
  }                     \
}
```

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
