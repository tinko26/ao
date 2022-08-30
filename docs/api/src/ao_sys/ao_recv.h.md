---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_recv.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_recv.h/
subtitle: ""
title: "ao_recv.h"
toc: true
---

# Include

```c
#include <ao_async.h>
#include <ao_time.h>
#include <stdbool.h>
#include <stddef.h>
```

# Typedefs

```c
typedef struct ao_recv_t ao_recv_t;
```

```c
typedef void (* ao_recv_proc_t) (ao_recv_t * x);
```

# Types

## `ao_recv_t`

```c
struct ao_recv_t
{
    ao_async_t async;
    ao_recv_proc_t begin;
    size_t volatile count;
    size_t count_max;
    size_t count_min;
    ao_recv_proc_t end;
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
void ao_recv( ao_recv_t * x, ao_time_t timeout);
```

```c
void ao_recv_from( ao_recv_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
void ao_recv_forever( ao_recv_t * x);
```

```c
void ao_recv_try( ao_recv_t * x);
```

```c
void ao_recv_begin( ao_recv_t * x);
```

```c
void ao_recv_end( ao_recv_t * x);
```

