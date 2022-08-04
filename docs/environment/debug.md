---
author: "Stefan Wagner"
date: 2022-08-04
description: "Debugging in the ao Real-Time Operating System (RTOS)."
draft: false
permalink: /environment/debug/
title: "Debugging"
---

# Debugging

The `ao_debug.h` module defines a single macro constant indicating whether an application is running in debug mode. By default, its value is false.

```c
#define AO_DEBUG (false)
```

The purpose of this macro constant is to have a toolchain-agnostic abstraction that can be used to write portable code.

Consequently, this module should be overridden in a toolchain-specific package, not least because usually compilers implicitly define macro constants indicating debug mode. In the case of the XC32 compiler, which is a GCC port, this override is as follows.

```c
#ifndef AO_DEBUG
#ifndef NDEBUG
#ifndef __DEBUG

#define AO_DEBUG (false)

#else

#define AO_DEBUG (true)

#endif
#else

#define AO_DEBUG (false)

#endif
#endif
```
