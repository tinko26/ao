---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_alarm.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys/ao_alarm.h/
subtitle: ""
title: "ao_alarm.h"
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

# Constants

```c
#define AO_ALARM_DELAY (AO_MILLISECONDS(100))
```

```c
#define AO_ALARM_UPDATE (AO_TIME_MAX - AO_ALARM_DELAY + 1)
```

# Types

## `ao_alarm_t`

```c
struct ao_alarm_t
{
    ao_proc_t callback;
    void * callback_parameter;
    ao_time_t end;
    ao_alarm_queue_node_t node;
    bool running;
};
```

Members:

| `callback` | |
| `callback_parameter` | |
| `end` | |
| `node` | |
| `running` | |

# Functions

```c
void ao_alarm_start( ao_alarm_t * x, ao_time_t t);
```

```c
void ao_alarm_start_from( ao_alarm_t * x, ao_time_t t, ao_time_t b);
```

```c
void ao_alarm_stop( ao_alarm_t * x);
```

