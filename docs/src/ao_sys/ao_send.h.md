---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_send.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys/ao_send.h/
subtitle: ""
title: "ao_send.h"
toc: true
---

# Include

```c
#include <ao_async.h>
#include <ao_func.h>
#include <ao_time.h>
#include <stdbool.h>
#include <stddef.h>
```

# Typedefs

```c
typedef struct ao_send_t ao_send_t;
```

```c
typedef void (* ao_send_proc_t) (ao_send_t * x);
```

# Types

## `ao_send_t`

```c
struct ao_send_t
{
    ao_async_t async;
    ao_send_proc_t begin;
    size_t volatile count;
    size_t count_max;
    size_t count_min;
    ao_send_proc_t end;
    void * parameter;
    void * ptr;
    bool volatile result;
};
```

Members:

| `async` | |
| `begin` | |
| `count` | |
| `count_max` | |
| `count_min` | |
| `end` | |
| `parameter` | |
| `ptr` | |
| `result` | |

# Functions

```c
void ao_send( ao_send_t * x, ao_time_t timeout);
```

```c
void ao_send_from( ao_send_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
void ao_send_forever( ao_send_t * x);
```

```c
void ao_send_try( ao_send_t * x);
```

```c
void ao_send_begin( ao_send_t * x);
```

```c
void ao_send_end( ao_send_t * x);
```

