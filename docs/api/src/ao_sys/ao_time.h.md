---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_time.h/
seealso:
- /api/src/ao_sys/ao_count.h/
toc: true
---

# Notes

This module contains a couple of time-related definitions, that are based on a hardware counter.

# Include

```c
#include <ao_count.h>
```

# Constants

## `AO_INFINITY`

```c
#define AO_INFINITY (AO_COUNT_MAX)
```

Infinity.

## `AO_TIME_MAX`
## `AO_TIME_MIN`

```c
#define AO_TIME_MAX (AO_COUNT_MAX)
#define AO_TIME_MIN (AO_COUNT_MIN)
```

The maximum and minimum time value, respectively.

# Types

## `ao_time_t`

```c
typedef ao_count_t ao_time_t;
```

This type is an alias for the `ao_count_t` type. It represents both time points and time spans. Because the underlying type is an unsigned integer type, negative time spans cannot be represented.

# Functions

## `ao_now`

```c
#define ao_now() \
(                \
    ao_count()   \
)
```

Gets the current time point.

## `AO_DAYS`
## `AO_HOURS`
## `AO_MINUTES`
## `AO_SECONDS`
## `AO_MILLISECONDS`
## `AO_MICROSECOND`
## `AO_NANOSECONDS`

```c
#define AO_DAYS(x)         ((x) * (AO_COUNT_FREQUENCY) * (86400))
#define AO_HOURS(x)        ((x) * (AO_COUNT_FREQUENCY) * (3600))
#define AO_MINUTES(x)      ((x) * (AO_COUNT_FREQUENCY) * (60))
#define AO_SECONDS(x)      ((x) * (AO_COUNT_FREQUENCY))
#define AO_MILLISECONDS(x) ((x) * (AO_COUNT_FREQUENCY) / (1000))
#define AO_MICROSECONDS(x) ((x) * (AO_COUNT_FREQUENCY) / (1000000))
#define AO_NANOSECONDS(x)  ((x) * (AO_COUNT_FREQUENCY) / (1000000000))
```

Converts a time span to an `ao_time_t` value.

## `AO_DAYS_FROM_TIME`
## `AO_HOURS_FROM_TIME`
## `AO_MINUTES_FROM_TIME`
## `AO_SECONDS_FROM_TIME`
## `AO_MILLISECONDS_FROM_TIME`
## `AO_MICROSECOND_FROM_TIME`
## `AO_NANOSECONDS_FROM_TIME`

```c
#define AO_DAYS_FROM_TIME(x)         ((x) / (AO_COUNT_FREQUENCY) / (86400))
#define AO_HOURS_FROM_TIME(x)        ((x) / (AO_COUNT_FREQUENCY) / (3600))
#define AO_MINUTES_FROM_TIME(x)      ((x) / (AO_COUNT_FREQUENCY) / (60))
#define AO_SECONDS_FROM_TIME(x)      ((x) / (AO_COUNT_FREQUENCY))
#define AO_MILLISECONDS_FROM_TIME(x) ((x) * (1000) / (AO_COUNT_FREQUENCY))
#define AO_MICROSECONDS_FROM_TIME(x) ((x) * (1000000) / (AO_COUNT_FREQUENCY))
#define AO_NANOSECONDS_FROM_TIME(x)  ((x) * (1000000000) / (AO_COUNT_FREQUENCY))
```

Converts a time span from an `ao_time_t` value.
