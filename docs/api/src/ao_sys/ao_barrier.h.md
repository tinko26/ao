---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_barrier.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_barrier.h/
subtitle: "Barriers"
title: "ao_barrier.h"
toc: true
wiki:
- barrier
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
typedef struct ao_barrier_t      ao_barrier_t;
```

```c
typedef struct ao_barrier_wait_t ao_barrier_wait_t;
```

# Types

## `ao_barrier_t`

This type represents a barrier.

```c
struct ao_barrier_t
{
    ao_uint_t count;
    ao_uint_t count_threshold;
    ao_list_t list;
};
```

It consists of the following members.

| `count` | The current number of waiting tasks. |
| `count_threshold` | The maximum number waiting tasks. |
| `list` | The list of waiting tasks. |

## `ao_barrier_wait_t`

This type represents the waiting at a barrier.

```c
struct ao_barrier_wait_t
{
    ao_async_t     async;
    ao_barrier_t * barrier;
    ao_list_node_t node;
    bool volatile  result;
};
```

It consists of the following members.

| `async` | |
| `barrier` | |
| `node` | |
| `result` | |

# Functions

```c
bool ao_barrier_wait(     ao_barrier_t * x, ao_time_t timeout);
bool ao_barrier_wait_from(ao_barrier_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
bool ao_barrier_wait_forever(ao_barrier_t * x);
```

```c
bool ao_barrier_wait_try(ao_barrier_t * x);
```

```c
void ao_barrier_wait_begin(ao_barrier_wait_t * x);
void ao_barrier_wait_end(  ao_barrier_wait_t * x);
```
