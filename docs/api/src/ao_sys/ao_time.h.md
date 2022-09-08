---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_time.h/
seealso:
- /api/src/ao_sys/ao_count.h/
toc: true
---

# Overview

This module contains a couple of time-related definitions, that are based on a hardware counter.

# Include

```c
#include <ao_count.h>
```

# Constants

## `AO_INFINITY`

Infinity.

```c
#define AO_INFINITY (AO_COUNT_MAX)
```

## `AO_TIME_MAX`
## `AO_TIME_MIN`

The maximum and minimum time value, respectively.

```c
#define AO_TIME_MAX (AO_COUNT_MAX)
#define AO_TIME_MIN (AO_COUNT_MIN)
```

# Typedefs

```c
typedef ao_count_t ao_time_t;
```

# Types

## `ao_time_t`

This type is an alias for the `ao_count_t` type. It represents both time points and time spans. Because the underlying type is an unsigned integer type, negative time spans cannot be represented.

# Functions

## `ao_now`

Get the current time point.

```c
#define ao_now()
```

## `AO_DAYS`
## `AO_HOURS`
## `AO_MINUTES`
## `AO_SECONDS`
## `AO_MILLISECONDS`
## `AO_MICROSECOND`
## `AO_NANOSECONDS`

Convert a time span to an `ao_time_t` value.

```c
#define AO_DAYS(x)
#define AO_HOURS(x)
#define AO_MINUTES(x)
#define AO_SECONDS(x)
#define AO_MILLISECONDS(x)
#define AO_MICROSECONDS(x)
#define AO_NANOSECONDS(x)
```

## `AO_DAYS_FROM_TIME`
## `AO_HOURS_FROM_TIME`
## `AO_MINUTES_FROM_TIME`
## `AO_SECONDS_FROM_TIME`
## `AO_MILLISECONDS_FROM_TIME`
## `AO_MICROSECOND_FROM_TIME`
## `AO_NANOSECONDS_FROM_TIME`

Convert a time span from an `ao_time_t` value.

```c
#define AO_DAYS_FROM_TIME(x)
#define AO_HOURS_FROM_TIME(x)
#define AO_MINUTES_FROM_TIME(x)
#define AO_SECONDS_FROM_TIME(x)
#define AO_MILLISECONDS_FROM_TIME(x)
#define AO_MICROSECONDS_FROM_TIME(x)
#define AO_NANOSECONDS_FROM_TIME(x)
```
