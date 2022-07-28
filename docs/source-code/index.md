---
author: "Stefan Wagner"
description: "Source code of the ao real-time operating system (RTOS)."
permalink: /source-code/
title: "Source Code"
---

# Source Code

## Location

The source code of the RTOS is located in the repository's [`src`](https://github.com/tinko26/ao/tree/main/src) folder. 

## Organization

### Packages

The source code is subdivided into C files and folders containing header files. Thereby, folders and corresponding C files constitute a total of four packages.

#### ao

This package is an extension to the freestanding runtime environment. It provides environment constants and variables, type definitions, support for debugging, as well as useful functions and data structures. It consists of the `ao` folder and the `ao.c` file.

#### ao_sys

This package contains the kernel and provides common features such as multitasking, synchronization, timers, or dynamic memory management. It consists of the `ao_sys` folder and the `ao_sys.c` file.

#### ao_sys_xc32

This package contains some support for Microchip's XC32 compiler. It consists of the `ao_sys_xc32` folder, only, and has no corresponding C file.

#### ao_sys_xc32_pic32

This package contains a port for PIC32 microcontrollers. It consists of the `ao_sys_xc32_pic32.c` file and all the folders, whose names start with `ao_sys_xc32_pic32`.

### Modules

Each package is made up of modules. For each module, there is a dedicated header file. The `ao` package, for example, contains the `ao_break` module, that declares a single function that executes a software breakpoint. 

```c
void ao_break();
```

Modules can depend on each other. For example, the `ao_assert` module defines a macro function for runtime assertions. Due to the implementation, it depends on the `ao_break` module.

```c
#define ao_assert(exp)      \
{                           \
        if (!(exp))         \
        {                   \
            ao_break();     \
        }                   \
}
```

### Hardware-Agnostic vs. Hardware-Specific

The modules of the `ao` and `ao_sys` packages are implemented in a strict hardware-agnostic fashion. That is, they do not contain...

...

The `ao` and `ao_sys` packages are implemented in a strict hardware-agnostic fashion. That is, they do not contain interrupt handlers, assembly, or any features specific to a toolchain or target. They only rely on the declarations and definitions of the following header files of a freestanding runtime environment.

- `float.h`
- `stdbool.h`
- `stddef.h`
- `stdint.h`

Thereby, these two packages make use of functions and types that they have declared, but not defined. For example, the `ao` package declares, but does not define, a function that executes a software breakpoint.

```c
void ao_break();
```

An implementation of this function can be found in the `ao_sys_xc32_pic32` package. It makes use of a built-in function provided by the XC32 compiler. For the sake of simplicity and execution speed, it is implemented as a macro function rather than an ordinary function.

```c
#define ao_break() __builtin_software_breakpoint()
```


...

In order for this to work out, these two packages declare and use functions

...

Each package contains a number of **modules**, where each module comes with a corresponding header file. 

## Usage

- #include_next directive

## 


# DRAFT

- namespaces
- MISRA C compliance and deviation
- memory management (static, dynamic)
- memory initialization
- usage of C language features (macros, macro functions, enums, typedefs)
