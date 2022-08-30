---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_sleep.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_sleep.h/
subtitle: ""
title: "ao_sleep.h"
toc: true
---

# Include

```c
#include <ao_alarm.h>
#include <ao_async.h>
#include <ao_time.h>
#include <stdbool.h>
```

# Typedefs

```c
typedef struct ao_sleep_t ao_sleep_t;
```

# Types

## `ao_sleep_t`

```c
struct ao_sleep_t
{
    ao_alarm_t alarm;
    ao_async_t async;
    ao_time_t beginning;
    bool volatile result;
    ao_time_t timeout;
};
```

Members:

| `alarm` | |
| `async` | |
| `beginning` | |
| `result` | |
| `timeout` | |

# Functions

```c
bool ao_sleep( ao_time_t timeout);
```

```c
bool ao_sleep_from( ao_time_t timeout, ao_time_t beginning);
```

```c
bool ao_sleep_forever();
```

```c
void ao_sleep_begin( ao_sleep_t * x);
```

```c
void ao_sleep_end( ao_sleep_t * x);
```

