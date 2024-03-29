---
author: "Stefan Wagner"
date: 2022-09-27
draft: true
permalink: /api/src/ao_sys/ao_count.h/
toc: true
---

# Notes

This module encapsulates a hardware counter that increments continuously at a constant rate. The counter makes up the basis for measuring time. Additionally, this counter and a corresponding interrupt make up the basis for alarms. This module is abstract, that is, an implementation must be provided by a port in order to support timing.

# Include

| `stdint.h` |

# Constants

## `AO_COUNT_FREQUENCY`

```c
#define AO_COUNT_FREQUENCY (0)
```

The frequency, in Hertz, at which the counter is incremented.

## `AO_COUNT_MAX`
## `AO_COUNT_MIN`

```c
#define AO_COUNT_MAX (UINT32_MAX)
#define AO_COUNT_MIN (0)
```

The maximum and minimum counter value, respectively.

# Types

## `ao_count_t`

```c
typedef uint32_t ao_count_t;
```

This type is an alias for an unsigned integer type that can hold a value of the counter.

# Functions

## `ao_count`

```c
ao_count_t ao_count();
```

Gets the current value of the counter.
