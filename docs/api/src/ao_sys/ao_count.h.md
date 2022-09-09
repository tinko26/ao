---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_count.h/
toc: true
---

# Notes

This module encapsulates a hardware counter that increments continuously at a constant rate. The hardware counter makes up the basis for measuring time. Additionally, this hardware counter and a corresponding interrupt make up the basis for alarms.

This module is abstract, that is, an implementation must be provided by a port package in order to support timing.

# Include

```c
#include <stdint.h>
```

# Constants

## `AO_COUNT_FREQUENCY`

The frequency, in Hertz, at which the hardware counter is incremented.

```c
#define AO_COUNT_FREQUENCY (0)
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

This type is an alias for an unsigned integer type that can hold a value of the hardware counter.

# Functions

## `ao_count`

Get the current value of the hardware counter.

```c
ao_count_t ao_count();
```
