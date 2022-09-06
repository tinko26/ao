---
author: "Stefan Wagner"
date: 2022-08-14
draft: true
permalink: /source-code/
toc: true
wiki:
- pic32
- separation-of-concerns
---

# Overview

The source code of the framework is located in the `src` directory of the repository.

# Packages

The source code is subdivided into C files and directories containing header files. Thereby, directories and corresponding C files constitute the following three packages.

| Package     | Directories | Files        |
|-------------|-------------|--------------|
| Port        | `ao_sys_*`  | `ao_sys_*.c` |
| Kernel      | `ao_sys`    | `ao_sys.c`   |
| Environment | `ao`        | `ao.c`       |

## Port

The port package contains all the ingredients required to make an application run on a target platform.

## Kernel

The kernel package provides functions for timing, multitasking, real-time scheduling, inter-process communication, synchronization, and dynamic memory management.

## Environment

The environment package is an extension to a freestanding runtime environment. It provides environment constants and variables, type definitions, support for debugging, as well as plenty of useful functions and data structures.

# Modules

Each package is made up of modules. For each module, there is a dedicated header file. The real-time operating system contains quite a lot of modules. The rationale behind this is separation of concerns, which means, that each module should address a single concern, only.

The environment package, for example, contains the [`ao_break.h`](api/src/ao/ao_break.h.md) module. That module, in turn, contains a single function, which executes a breakpoint.

```c
void ao_break();
```

However, having separate modules focusing on individual concerns leads to interdependency. For example, the [`ao_assert.h`](api/src/ao/ao_assert.h.md) module of the environment package contains a macro function for runtime assertions, which executes a breakpoint, when an assertion has failed.

```c
#define ao_assert(exp)  \
{                       \
if (!(exp))         \
{                   \
ao_break();     \
}                   \
}
```

Such interdependencies can exist between modules from different packages, too. However, this is limited to a strict top-down package hierarchy. For example, kernel modules can depend on other kernel modules or environment modules, whereas environment modules can depend on other environment modules, but not on kernel modules.

| Package     | Module Interdependencies |
|-------------|--------------------------|
| Port        | ⬅️, ⬇️ |
| Kernel      | ⬅️, ⬇️ |
| Environment | ⬅️ |

# Platform-Agnostic Modules

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

# Platform-Specific Modules

In contrast, the modules of the port package are platform-specific. For example, they include the compiler's `xc.h` header file and make heavy use of non-standard language features, not least for the sake of execution speed.

Also, they call functions declared in header files of a hosted runtime environment, such as `memset()`, because the XC32 compiler ships with an implementation of a subset of the standard library.

And all that makes perfect sense. Since the port package is explicitly devoted to the XC32 toolchain, there is no point in not using its rich and highly optimized features.

# Abstract Modules

Kernel functions cannot be implemented thoroughly without platform-specific features. In order to achieve platform independency nonetheless, the environment and kernel packages contain abstract modules. These modules declare necessary functions, but do not define them.

For example, the aforementioned [`ao_break.h`](api/src/ao/ao_break.h.md) module of the environment package is abstract, because the execution of a breakpoint is platform-specific. Consequently, there is no implementation of this function in the `ao.c` file.

# Overriding Modules

Instead, an implementation of the `ao_break()` function can be found in the port package. There, it simply forwards the call to a built-in function provided by the XC32 compiler. For the sake of simplicity and execution speed, it is implemented as a macro function rather than an ordinary function.

```c
#define ao_break() __builtin_software_breakpoint()
```

So, the port package contains an `ao_break.h` header file, too, just like the environment package. This brings up the question of how to make the compiler use the former instead of the latter.

# Include Directories

When including a header file with the angle-bracket form, the compiler searches a sequence of directories. Although the standard spares the details of the search and leaves it up to the implementation, virtually every compiler first scans a user-defined, then an implementation-defined sequence of directories.

So, in order to include the correct `ao_break.h` header file, the compiler's include directories must be set up properly, so that it searches the directories of the port package before the directory of the environment package.

This hierarchy of include directories is mirrored by the directory names. For example, the following setup must be chosen, in order to target a PIC32MZ EF microcontroller.

| | Directory | Package | |
|-|-----------|---------|-|
| 1️⃣ | `ao_sys_xc32_pic32mz_ef` | Port | ⬇️ |
| 2️⃣ | `ao_sys_xc32_pic32mz` | Port | ⬇️ |
| 3️⃣ | `ao_sys_xc32_pic32` | Port | ⬇️ |
| 4️⃣ | `ao_sys_xc32` | Port | ⬇️ |
| 5️⃣ | `ao_sys` | Kernel | ⬇️ |
| 6️⃣ | `ao` | Environment | |

# Configuration

In object-oriented programming, overriding is not solely a way to implement an abstract method in a subclass, but can also be used to provide a new implementation for an already implemented method, in order to make instances of that subclass behave more specific. The same is true for a header file, that can be replaced by another version from somewhere upstream the include directory hierarchy, in order to configure the respective module's behavior.

For example, the [`ao_buffer.h`](api/src/ao/ao_buffer.h.md) module defines a macro constant, that indicates whether buffers should keep track of their maximum usage. By default, this configuration option is disabled.

```c
#ifndef AO_BUFFER_COUNT_MAX
#define AO_BUFFER_COUNT_MAX (false)
#endif
```

Now, an application can choose to override this definition by supplying its own `ao_buffer.h` header file. Of course, the include directory hierarchy must be set up properly, in order for the compiler to find the application's version of the header file first.

| | Directory | Package | |
|-|-----------|---------|-|
| 1️⃣ | `app_directory` | App | ⬇️ |
| 2️⃣ | `ao_sys_xc32_pic32mz_ef` | Port | ⬇️ |
| 3️⃣ | `ao_sys_xc32_pic32mz` | Port | ⬇️ |
| 4️⃣ | `ao_sys_xc32_pic32` | Port | ⬇️ |
| 5️⃣ | `ao_sys_xc32` | Port | ⬇️ |
| 6️⃣ | `ao_sys` | Kernel | ⬇️ |
| 7️⃣ | `ao` | Environment | |

However, instead of providing a copy of the entire header file, the `#include_next` directive can be used in the override, if that is supported by the compiler.

```c
#ifndef AO_BUFFER_COUNT_MAX
#define AO_BUFFER_COUNT_MAX (true)
#endif

#include_next <ao_buffer.h>
```

# ao.h

In addition to optional overrides for selected modules, an application must supply an `ao.h` header file, because that is included by all the real-time operating system's C files. This header file is to include all the modules, that are required by the application.

```c
#include <ao_align.h>
#include <ao_alloc.h>
#include <ao_assert.h>
#include <ao_async.h>
#include <ao_await.h>
#include <ao_block.h>
#include <ao_boot.h>
#include <ao_float.h>
#include <ao_int.h>
#include <ao_ir.h>
// ...
```

Additionally, this mechanism provides a very fine-grained control of the memory usage of the application, because functions and data will not get linked in, unless the respective header file has been included by `ao.h`.
