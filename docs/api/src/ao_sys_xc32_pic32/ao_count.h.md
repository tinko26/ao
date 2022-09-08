---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_count.h/
seealso:
- /api/src/ao_sys_xc32_pic32/ao_sys_clock.h/
toc: true
---

# Overview

This module encapsulates a hardware counter that increments continuously at a constant rate. The hardware counter makes up the basis for measuring time. Additionally, this hardware counter and a corresponding interrupt make up the basis for alarms.

# Include

```c
#include <ao_sys.h>
#include <stdint.h>
#include <xc.h>
```

# Constants

## `AO_COUNT_FREQUENCY`

The frequency, in Hertz, at which the hardware counter is incremented.

```c
#define AO_COUNT_FREQUENCY ((AO_SYS_SYSCLK) / 2)
```

## `AO_COUNT_MAX`
## `AO_COUNT_MIN`

The maximum and minimum hardware counter value, respectively.

```c
#define AO_COUNT_MAX (UINT32_MAX)
#define AO_COUNT_MIN (0)
```

# Typedefs

```c
typedef uint32_t ao_count_t;
```

# Types

## `ao_count_t`

This type is an alias for the `uint32_t` unsigned integer type. It is to hold a value of the hardware counter.

# Functions

## `ao_count`

Get the current value of the hardware counter.

```c
#define ao_count()
```

## `ao_count_debug_continue`
## `ao_count_debug_stop`

Setup the hardware counter to continue or stop, respectively, upon a breakpoint.

```c
#define ao_count_debug_continue()
#define ao_count_debug_stop()
```
