---
author: "Stefan Wagner"
date: 2022-08-11
description: ""
draft: false
permalink: /kernel/time/
title: "Time"
---

# Time

The `ao_time.h` module contains a couple of time-related definitions, that are based on a [hardware counter](count.md).

## Type

First and foremost, the module defines the `ao_time_t` type, that represents both time points and time spans. Because it is an alias for the `ao_count_t` type, which is an unsigned integer type, it cannot represent negative time spans.

```c
typedef ao_count_t ao_time_t;
```

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
