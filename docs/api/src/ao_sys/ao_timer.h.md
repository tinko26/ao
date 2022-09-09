---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_timer.h/
toc: true
---

# Overview

...

- software timer based on alarms
- can restart automatically, if a finite period is specified.
- callback executed in the context of the alarm interrupt.

...

# Include

```c
#include <ao_alarm.h>
#include <ao_func.h>
#include <ao_time.h>
```

# Identifiers

## `AO_TIMER`

```c
#define AO_TIMER
```

# Typedefs

```c
typedef struct ao_timer_t ao_timer_t;
```

# Types

## `ao_timer_t`

This type represents a timer.

```c
struct ao_timer_t
{
    ao_alarm_t alarm;
    ao_proc_t  callback;
    void *     callback_parameter;
    ao_time_t  end;
    ao_time_t  period;
};
```

It consists of the following members.

| `alarm` | The alarm. |
| `callback` | The callback. |
| `callback_parameter` | The callback parameter. |
| `end` | The next time point of expiration. |
| `period` | The period. |

# Functions

## `ao_timer_start`
## `ao_timer_start_from`

```c
void ao_timer_start(     ao_timer_t * t, ao_time_t phase, ao_time_t period);
void ao_timer_start_from(ao_timer_t * t, ao_time_t phase, ao_time_t period, ao_time_t beginning);
```

## `ao_timer_stop`

```c
void ao_timer_stop(ao_timer_t * t);
```
