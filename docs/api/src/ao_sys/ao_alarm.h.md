---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_alarm.h/
seealso:
- /api/src/ao_sys/ao_alarm_queue.h/
toc: true
---

# Include

```c
#include <ao_alarm_queue.h>
#include <ao_func.h>
#include <ao_time.h>
#include <stdbool.h>
```

# Typedefs

```c
typedef struct ao_alarm_t ao_alarm_t;
```

# Configuration

```c
#define AO_ALARM_DELAY  (AO_MILLISECONDS(100))
```

# Constants

```c
#define AO_ALARM_UPDATE (AO_TIME_MAX - AO_ALARM_DELAY + 1)
```

# Types

## `ao_alarm_t`

This type represents an alarm.

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

It consists of the following members.

| `callback` | The callback. |
| `callback_parameter` | The callback parameter. |
| `end` | The time point, when the alarm is due. |
| `node` | The node for the alarm queue. |
| `running` | Indicates whether the alarm has been started. |

# Functions

Start an alarm with a timeout and an optional beginning.

```c
void ao_alarm_start(     ao_alarm_t * x, ao_time_t t);
void ao_alarm_start_from(ao_alarm_t * x, ao_time_t t, ao_time_t b);
```

Stop an alarm.

```c
void ao_alarm_stop(ao_alarm_t * x);
```
