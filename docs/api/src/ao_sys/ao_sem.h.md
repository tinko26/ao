---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_sem.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_sem.h/
subtitle: ""
title: "ao_sem.h"
toc: true
---

# Include

```c
#include <ao_async.h>
#include <ao_list.h>
#include <ao_time.h>
#include <ao_uint.h>
#include <stdbool.h>
```

# Typedefs

```c
typedef struct ao_sem_t ao_sem_t;
```

```c
typedef struct ao_sem_take_t ao_sem_take_t;
```

# Types

## `ao_sem_t`

```c
struct ao_sem_t
{
    ao_uint_t count;
    ao_list_t list;
};
```

It consists of the following members.

| `count` | |
| `list` | |

## `ao_sem_take_t`

```c
struct ao_sem_take_t
{
    ao_async_t async;
    ao_uint_t count;
    ao_list_node_t node;
    bool volatile result;
    ao_sem_t * sem;
};
```

It consists of the following members.

| `async` | |
| `count` | |
| `node` | |
| `result` | |
| `sem` | |

# Functions

```c
void ao_sem_give( ao_sem_t * x, ao_uint_t count);
```

```c
bool ao_sem_take( ao_sem_t * x, ao_uint_t count, ao_time_t timeout);
```

```c
bool ao_sem_take_from( ao_sem_t * x, ao_uint_t count, ao_time_t timeout, ao_time_t beginning);
```

```c
bool ao_sem_take_forever( ao_sem_t * x, ao_uint_t count);
```

```c
bool ao_sem_take_try( ao_sem_t * x, ao_uint_t count);
```

```c
void ao_sem_take_begin( ao_sem_take_t * x);
```

```c
void ao_sem_take_end( ao_sem_take_t * x);
```

