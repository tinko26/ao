---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_time.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_time.h/ 
subtitle: ""
title: "ao_time.h"
toc: true
---

# Overview

...

# Includes

```c
#include <ao_count.h>

typedef ao_count_t                      ao_time_t;

#ifndef AO_INFINITY

#define AO_INFINITY                     (AO_COUNT_MAX)

#endif

#ifndef AO_TIME_MAX

#define AO_TIME_MAX                     (AO_COUNT_MAX)

#endif

#ifndef AO_TIME_MIN

#define AO_TIME_MIN                     (AO_COUNT_MIN)

#endif

#ifndef ao_now

#define ao_now()                        ao_count()

#endif

#ifndef AO_DAYS

#define AO_DAYS(x)                      ((x) * (AO_COUNT_FREQUENCY) * (86400))

#endif

#ifndef AO_DAYS_FROM_TIME

#define AO_DAYS_FROM_TIME(x)            ((x) / (AO_COUNT_FREQUENCY) / (86400))

#endif

#ifndef AO_HOURS

#define AO_HOURS(x)                     ((x) * (AO_COUNT_FREQUENCY) * (3600))

#endif

#ifndef AO_HOURS_FROM_TIME

#define AO_HOURS_FROM_TIME(x)           ((x) / (AO_COUNT_FREQUENCY) / (3600))

#endif

#ifndef AO_MINUTES

#define AO_MINUTES(x)                   ((x) * (AO_COUNT_FREQUENCY) * (60))

#endif

#ifndef AO_MINUTES_FROM_TIME

#define AO_MINUTES_FROM_TIME(x)         ((x) / (AO_COUNT_FREQUENCY) / (60))

#endif

#ifndef AO_SECONDS

#define AO_SECONDS(x)                   ((x) * (AO_COUNT_FREQUENCY))

#endif

#ifndef AO_SECONDS_FROM_TIME

#define AO_SECONDS_FROM_TIME(x)         ((x) / (AO_COUNT_FREQUENCY))

#endif

#ifndef AO_MILLISECONDS

#define AO_MILLISECONDS(x)              ((x) * (AO_COUNT_FREQUENCY) / (1000))

#endif

#ifndef AO_MILLISECONDS_FROM_TIME

#define AO_MILLISECONDS_FROM_TIME(x)    ((x) * (1000) / (AO_COUNT_FREQUENCY))

#endif

#ifndef AO_MICROSECONDS

#define AO_MICROSECONDS(x)              ((x) * (AO_COUNT_FREQUENCY) / (1000000))

#endif

#ifndef AO_MICROSECONDS_FROM_TIME

#define AO_MICROSECONDS_FROM_TIME(x)    ((x) * (1000000) / (AO_COUNT_FREQUENCY))

#endif

#ifndef AO_NANOSECONDS

#define AO_NANOSECONDS(x)               ((x) * (AO_COUNT_FREQUENCY) / (1000000000))

#endif

#ifndef AO_NANOSECONDS_FROM_TIME

#define AO_NANOSECONDS_FROM_TIME(x)     ((x) * (1000000000) / (AO_COUNT_FREQUENCY))

#endif

```
