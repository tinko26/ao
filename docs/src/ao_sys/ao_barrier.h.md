---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_barrier.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys/ao_barrier.h/
subtitle: ""
title: "ao_barrier.h"
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
typedef struct ao_barrier_t ao_barrier_t;
```

```c
typedef struct ao_barrier_wait_t ao_barrier_wait_t;
```

# Types

## `ao_barrier_t`

```c
struct ao_barrier_t
{
    ao_uint_t count;
    ao_uint_t count_threshold;
    ao_list_t list;
};
```

Members:

| `count` | |
| `count_threshold` | |
| `list` | |

## `ao_barrier_wait_t`

```c
struct ao_barrier_wait_t
{
    ao_async_t async;
    ao_barrier_t * barrier;
    ao_list_node_t node;
    bool volatile result;
};
```

Members:

| `async` | |
| `barrier` | |
| `node` | |
| `result` | |

# Functions

```c
bool ao_barrier_wait( ao_barrier_t * x, ao_time_t timeout);
```

```c
bool ao_barrier_wait_from( ao_barrier_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
bool ao_barrier_wait_forever( ao_barrier_t * x);
```

```c
bool ao_barrier_wait_try( ao_barrier_t * x);
```

```c
void ao_barrier_wait_begin( ao_barrier_wait_t * x);
```

```c
void ao_barrier_wait_end( ao_barrier_wait_t * x);
```

