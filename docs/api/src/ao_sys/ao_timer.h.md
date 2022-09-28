---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
permalink: /api/src/ao_sys/ao_timer.h/
toc: true
---

# Notes

...

- software timer based on alarms
- can restart automatically, if a finite period is specified.
- callback executed in the context of the alarm interrupt.

...

# Include

| [`ao_alarm.h`](ao_alarm.h.md) |
| [`ao_func.h`](../ao/ao_func.h.md) |
| [`ao_time.h`](ao_time.h.md) |

# Types

## `ao_timer_t`

```c
typedef struct ao_timer_t ao_timer_t;
```

Represents a timer.

# Structs

## `ao_timer_t`

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

| `alarm` | The alarm. |
| `callback` | The callback. |
| `callback_parameter` | The callback parameter. |
| `end` | The next time point of expiration. |
| `period` | The period. |

# Functions

## `ao_timer_start`
## `ao_timer_start_from`

```c
void ao_timer_start     (ao_timer_t * timer, ao_time_t phase, ao_time_t period);
void ao_timer_start_from(ao_timer_t * timer, ao_time_t phase, ao_time_t period, ao_time_t beginning);
```

Starts a timer with a phase, a period, and an optional beginning.

## `ao_timer_stop`

```c
void ao_timer_stop(ao_timer_t * timer);
```

Stops a timer.
