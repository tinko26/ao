---
author: "Stefan Wagner"
date: 2022-09-27
draft: true
permalink: /api/src/ao_sys/ao_alarm.h/
toc: true
---

# Include

| [`ao_alarm_queue.h`](ao_alarm_queue.h.md) |
| [`ao_func.h`](../ao/ao_func.h.md) |
| [`ao_time.h`](ao_time.h.md) |
| `stdbool.h` |

# Configuration

## `AO_ALARM_DELAY`

```c
#define AO_ALARM_DELAY (AO_MILLISECONDS(100))
```

The alarm delay is an estimate of the maximum latency of the alarm interrupt. This latency may be caused by hardware, interrupts of higher priority being served, interrupts being disabled due to critical zones, or interrupt context save and restore operations, among others. This value must be greater than zero.

# Constants

## `AO_ALARM_UPDATE`

```c
#define AO_ALARM_UPDATE \
(                       \
    (AO_TIME_MAX)    -  \
    (AO_ALARM_DELAY) +  \
    1                   \
)
```

The alarm update specifies the maximum time span between subsequent alarm interrupts. It takes into account the latency of the alarm interrupt in order to not miss a count overflow.

# Types

## `ao_alarm_t`

```c
typedef struct ao_alarm_t ao_alarm_t;
```

Represents an alarm.

# Structs

## `ao_alarm_t`

```c
struct ao_alarm_t
{
    ao_proc_t             callback;
    void *                callback_parameter;
    ao_time_t             end;
    ao_alarm_queue_node_t node;
    bool                  running;
};
```

| `callback` | The callback. |
| `callback_parameter` | The callback parameter. |
| `end` | The time point, when the alarm is due. |
| `node` | The node for the alarm queue. |
| `running` | Indicates whether the alarm has been started. |

# Functions

## `ao_alarm_start`
## `ao_alarm_start_from`

```c
void ao_alarm_start     (ao_alarm_t * alarm, ao_time_t timeout);
void ao_alarm_start_from(ao_alarm_t * alarm, ao_time_t timeout, ao_time_t beginning);
```

Starts an alarm with a timeout and an optional beginning.

## `ao_alarm_stop`

```c
void ao_alarm_stop(ao_alarm_t * alarm);
```

Stops an alarm.
