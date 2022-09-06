---
api: true
author: "Stefan Wagner"
date: 2022-08-31
description: "The /src/ao_sys/ao_time.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_time.h/
seealso:
- /api/src/ao_sys/ao_count.h/
subtitle: "Time"
title: "ao_time.h"
toc: true
---

# Overview

This module contains a couple of time-related definitions, that are based on a hardware counter.

# Include

```c
#include <ao_count.h>
```

# Typedefs

```c
typedef ao_count_t ao_time_t;
```

# Constants

Infinity.

```c
#define AO_INFINITY (AO_COUNT_MAX)
```

The maximum and minimum time value, respectively.

```c
#define AO_TIME_MAX (AO_COUNT_MAX)
#define AO_TIME_MIN (AO_COUNT_MIN)
```

# Types

## `ao_time_t`

This type is an alias for the `ao_count_t` type. It represents both time points and time spans. Because the underlying type is an unsigned integer type, negative time spans cannot be represented.

# Functions

Get the current time point.

```c
#define ao_now()
```

Convert a time span to an `ao_time_t` value.

```c
#define AO_DAYS(x)
#define AO_HOURS(x)
#define AO_MINUTES(x)
#define AO_MICROSECONDS(x)
#define AO_MILLISECONDS(x)
#define AO_NANOSECONDS(x)
#define AO_SECONDS(x)
```

Convert a time span from an `ao_time_t` value.

```c
#define AO_DAYS_FROM_TIME(x)
#define AO_HOURS_FROM_TIME(x)
#define AO_MINUTES_FROM_TIME(x)
#define AO_MICROSECONDS_FROM_TIME(x)
#define AO_MILLISECONDS_FROM_TIME(x)
#define AO_NANOSECONDS_FROM_TIME(x)
#define AO_SECONDS_FROM_TIME(x)
```
