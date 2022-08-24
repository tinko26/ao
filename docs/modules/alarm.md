---
author: "Stefan Wagner"
date: 2022-08-15
description: "The ao_alarm.h module of the ao real-time operating system."
draft: true
permalink: /modules/alarm/
title: "ao_alarm.h"
---

# Overview

...

# Configuration

```c
#define AO_ALARM_DELAY
```

# Constants

```c
#define AO_ALARM_UPDATE
```

# Type

The `ao_alarm_t` type represents an alarm.

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

| Member | |
|--------|-|
| `callback` | The callback. |
| `callback_parameter` | The callback parameter. |
| `end` | The time point, when the alarm is due. |
| `node` | The node member for the alarm queue. |
| `running` | Indicates whether the alarm has been started. |

# Functions

Start an alarm.

```c
void ao_alarm_start(ao_alarm_t * x, ao_time_t t);
void ao_alarm_start_from(ao_alarm_t * x, ao_time_t t, ao_time_t b);
```

Stop an alarm.

```c
void ao_alarm_stop(ao_alarm_t * x);
```
