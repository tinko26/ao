---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_timer.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_timer.h/
subtitle: ""
title: "ao_timer.h"
toc: true
---

# Include

```c
#include <ao_alarm.h>
#include <ao_func.h>
#include <ao_time.h>
```

# Typedefs

```c
typedef struct ao_timer_t ao_timer_t;
```

# Types

## `ao_timer_t`

```c
struct ao_timer_t
{
    ao_alarm_t alarm;
    ao_proc_t callback;
    void * callback_parameter;
    ao_time_t end;
    ao_time_t period;
};
```

It consists of the following members.

| `alarm` | |
| `callback` | |
| `callback_parameter` | |
| `end` | |
| `period` | |

# Functions

```c
void ao_timer_start( ao_timer_t * t, ao_time_t phase, ao_time_t period);
```

```c
void ao_timer_start_from( ao_timer_t * t, ao_time_t phase, ao_time_t period, ao_time_t beginning);
```

```c
void ao_timer_stop( ao_timer_t * t);
```

