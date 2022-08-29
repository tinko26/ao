---
author: "Stefan Wagner"
date: 2022-08-17
description: "The ao_sleep.h module of the ao real-time operating system."
draft: true
permalink: /modules/sleep/
title: "<code>ao_sleep.h</code>"
toc: true
---

# Overview

...

## Types

### Sleeping

The `ao_sleep_t` represents the sleeping of a task.

```c
struct ao_sleep_t
{
    ao_alarm_t    alarm;
    ao_async_t    async;
    ao_time_t     beginning;
    bool volatile result;
    ao_time_t     timeout;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `alarm` | The alarm. |
| `async` | The asynchronous event. |
| `beginning` | The beginning. |
| `result` | Indicates whether the task has been sleeping for the specified time span. |
| `timeout` | The timeout. |

## Functions

...
