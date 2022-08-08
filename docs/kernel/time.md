---
author: "Stefan Wagner"
date: 2022-08-08
description: "Time in the ao Real-Time Operating System (RTOS)."
draft: true
permalink: /kernel/time/
title: "Time"
---

# Time

The `ao_time.h` module contains a couple of time-related definitions, that are based on the `ao_count.h` module.

Therefore, it defines the unsigned integer type `ao_time_t` to hold a time point or time span, respectively.

## Constants

The minimum and maximum time value.

```c
#define AO_TIME_MIN
#define AO_TIME_MAX
```

The value representing infinity.

```c
#define AO_INFINITY
```

## Functions

Get the current time.

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
