---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_block.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys/ao_block.h/
subtitle: ""
title: "ao_block.h"
toc: true
---

# Include

```c
#include <ao_alarm.h>
#include <ao_time.h>
```

# Typedefs

```c
typedef struct ao_block_t ao_block_t;
```

# Types

## `ao_block_t`

```c
struct ao_block_t
{
    ao_alarm_t alarm;
    ao_time_t beginning;
    ao_time_t timeout;
};
```

Members:

| `alarm` | |
| `beginning` | |
| `timeout` | |

