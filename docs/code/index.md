---
author: "Stefan Wagner"
date: 2022-08-10
description: "The Source Code of the ao Real-Time Operating System (RTOS)."
draft: false
permalink: /code/
title: "Code"
---

# Code

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

The [kernel](../kernel/index.md) package provides functions for timing, multitasking, real-time scheduling, inter-process communication, synchronization, and dynamic memory management.

### Port

The [port](../port/index.md) package contains all the ingredients required to make an application run on PIC32 microcontrollers.

## Modules

Each package is made up of modules. For each module, there is a dedicated header file. The real-time operating system contains quite a lot of modules. The rationale behind this is [separation of concerns](https://en.wikipedia.org/wiki/Separation_of_concerns), which means, that each module should address a single concern, only.

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

Such interdependencies can exist both between modules and between packages. However, there is a strict top-down hierarchy for packages. Therefore, kernel modules can depend on other kernel modules or environment modules, whereas the latter can depend on other environment modules, but not on kernel modules.

## Platform-Agnostic Modules

The modules of the environment and kernel packages are implemented in a strict platform-agnostic fashion. That is, they do not contain interrupt handlers, assembly code, or the like. Therefore, they only make use of the header files of a **freestanding runtime environment**, that solely define types and macros, but do not declare any functions.

| Header File     | Dealing with ...                    |
|-----------------|-------------------------------------|
| `float.h`       | ... floating-point types.           |
| `iso646.h`      | ... alternative operator spellings. |
| `limits.h`      | ... integer types.                  |
| `stdalign.h`    | ... memory alignment.               |
| `stdarg.h`      | ... variable function arguments.    |
| `stdbool.h`     | ... the boolean type.               |
| `stddef.h`      | ... miscellaneous stuff.            |
| `stdint.h`      | ... fixed-width integer types.      |
| `stdnoreturn.h` | ... functions that do not return.   |

All the other header files of the standard library, such as `stdio.h`, are part of a **hosted runtime environment**. Its name implies, that there must be a hosting operating system to provide services such as reading a file.

Obviously, since the real-time operating system itself is such a host, it cannot rely on someone else to provide these services. Therefore, the environment and kernel packages provide a lot of functionality themselves, that can otherwise be found in the header files of a hosted runtime environment.

The aforementioned `ao_assert()` macro function is a good example. Although a similar macro function is defined in the standard library's `assert.h` header file, it is not being used, because that header file is not part of a freestanding runtime environment. 

## Platform-Specific Modules

In contrast, the modules of the port package are platform-specific. For example, they include the compiler's `xc.h` header file and make heavy use of non-standard language features, primarily for the sake of execution speed. 

Also, they call functions declared in header files of a hosted runtime environment, such as `memset()`, because the XC32 compiler ships with an implementation of a subset of the standard library. 

And all that makes perfect sense. Since the port package is explicitly devoted to the XC32 toolchain, there is no point in not using its rich and highly optimized features.

## Abstract Modules

Kernel functions cannot be implemented thoroughly without platform-specific features. In order to achieve platform independency nonetheless, the environment and kernel packages contain abstract modules. These modules declare necessary functions, but do not define them.

For example, the aforementioned `ao_break.h` module of the environment package is abstract, because the execution of a breakpoint is platform-specific. Consequently, there is no implementation of this function in the `ao.c` file.

## Overriding Modules

Instead, an implementation of the `ao_break()` function can be found in the port package. There, it simply forwards the call to a built-in function provided by the XC32 compiler. For the sake of simplicity and execution speed, it is implemented as a macro function rather than an ordinary function.

```c
#define ao_break() __builtin_software_breakpoint()
```

So, the port package contains an `ao_break.h` header file, too, just like the environment package. This brings up the question of how to make the compiler use the former instead of the latter.

## Include Directories

When including a header file with the angle-bracket form, the compiler searches a sequence of directories. Although the standard spares the details of the search and leaves it up to the implementation, virtually every compiler first scans a user-defined, then an implementation-defined sequence of directories.

So, in order to include the correct `ao_break.h` header file, the compiler's include directories must be set up properly, so that it searches the `ao_sys_xc32_pic32` directory of the port package before the `ao` directory of the environment package. 

This hierarchy of include directories is mirrored by the directory names. For example, the following setup must be chosen, in order to target a PIC32MZ EF microcontroller.

| Directory                |       |
|--------------------------|-------|
| `ao_sys_xc32_pic32mz_ef` | First |
| `ao_sys_xc32_pic32mz`    |       |
| `ao_sys_xc32_pic32`      |       |
| `ao_sys_xc32`            |       |
| `ao_sys`                 |       |
| `ao`                     | Last  |
