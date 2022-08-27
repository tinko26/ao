---
author: "Stefan Wagner"
date: 2022-08-17
description: "The ao_timer.h module of the ao real-time operating system."
draft: true
permalink: /modules/timer/
title: "<code>ao_timer.h</code>"
---

# Overview

...

- software timer based on alarms
- can restart automatically, if a finite period is specified.
- callback executed in the context of the alarm interrupt.

...

## Types

The `ao_timer_t` type represents a timer.

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

| Member | |
|--------|-|
| `alarm` | The alarm. |
| `callback` | The callback. |
| `callback_parameter` | The callback parameter. |
| `end` | The next time point of expiration. |
| `period` | The period. |

## Initialization

...

## Functions

...
