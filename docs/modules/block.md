---
author: "Stefan Wagner"
date: 2022-08-16
description: "The ao_block.h module of the ao real-time operating system."
draft: true
permalink: /modules/block/
title: "ao_block.h"
---

# ao_block.h

...

## Types

The `ao_block_t` type represents the blocking of a task.

```c
struct ao_block_t
{
    ao_alarm_t alarm;
    ao_time_t  beginning;
    ao_time_t  timeout;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `alarm` | ... |
| `beginning` | ... |
| `timeout` | ... |

## Functions

...

`ao_block()` not exposed

...

## External Links

[https://en.wikipedia.org/wiki/Blocking_(computing)](https://en.wikipedia.org/wiki/Blocking_(computing))
