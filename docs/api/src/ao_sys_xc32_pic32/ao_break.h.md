---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_break.h/
toc: true
---

# Notes

This module contains a single function that executes a breakpoint, if the application is running in debug mode.

# Include

| [`ao_debug.h`](../ao_sys_xc32/ao_debug.h.md) |

# Identifier

```c
#define AO_BREAK
```

# Functions

## `ao_break`

```c
#if     AO_DEBUG

#ifndef ao_break

#define ao_break() __builtin_software_breakpoint()

#endif

#else

#ifndef ao_break

#define ao_break()

#endif

#endif
```

Executes a breakpoint.
