---
author: "Stefan Wagner"
date: 2022-08-09
description: "The Source Code of the ao Real-Time Operating System (RTOS)."
draft: true
permalink: /code/
title: "Code"
---

# Code

## Location

The source code of the real-time operating system is located in the [repository's](https://github.com/tinko26/ao) `src` folder.

## Packages

The source code is subdivided into C files and folders containing header files. Thereby, folders and corresponding C files constitute the following three packages.

| Package     | Folders        | File                  |
|-------------|----------------|-----------------------|
| Environment | `ao`           | `ao.c`                |
| Kernel      | `ao_sys`       | `ao_sys.c`            |
| Port        | `ao_sys_xc32*` | `ao_sys_xc32_pic32.c` |

### Environment

The [environment](../environment/index.md) package is an extension to the freestanding runtime environment. It provides environment constants and variables, type definitions, support for debugging, as well as plenty of useful functions and data structures.

### Kernel

The [kernel](../kernel/index.md) package provides functions for timing, multi-tasking, real-time scheduling, inter-process communication, synchronization, and dynamic memory management.

### Port

The [port](../port/index.md) package contains all the ingredients required to make an application run on PIC32 microcontrollers.

## Modules

Each package is made up of modules. For each module, there is a dedicated header file.

### Separation of Concerns

The real-time operation system contains quite a lot of modules. The rationale behind this is [separation of concerns](https://en.wikipedia.org/wiki/Separation_of_concerns), which means, that each module should address a single concern, only.

The environment package, for example, contains the `ao_break.h` module. That module, in turn, contains a single function, which executes a breakpoint.

```c
void ao_break();
```

However, having separate modules focusing on individual concerns leads to interdependency. For example, the `ao_assert.h` module of the environment package contains a macro function for runtime assertions, which executes a breakpoint, when an assertion has failed.

```c
#define ao_assert(exp)  \
{                       \
    if (!(exp))         \
    {                   \
        ao_break();     \
    }                   \
}
```

...
