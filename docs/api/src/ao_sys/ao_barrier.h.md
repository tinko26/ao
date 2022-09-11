---
author: "Stefan Wagner"
date: 2022-08-29
draft: true
external:
- https://en.wikipedia.org/wiki/Barrier_(computer_science) : "Barrier"
permalink: /api/src/ao_sys/ao_barrier.h/
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

# Identifier

```c
#define AO_BARRIER
```

# Types

## `ao_barrier_t`

```c
typedef struct ao_barrier_t ao_barrier_t;
```

```c
struct ao_barrier_t
{
    ao_uint_t count;
    ao_uint_t count_threshold;
    ao_list_t list;
};
```

This type represents a barrier. It consists of the following members.

| `count` | The current number of waiting tasks. |
| `count_threshold` | The maximum number waiting tasks. |
| `list` | The list of waiting tasks. |

## `ao_barrier_wait_t`

```c
typedef struct ao_barrier_wait_t ao_barrier_wait_t;
```

```c
struct ao_barrier_wait_t
{
    ao_async_t     async;
    ao_barrier_t * barrier;
    ao_list_node_t node;
    bool volatile  result;
};
```

This type represents the waiting at a barrier. It consists of the following members.

| `async` | |
| `barrier` | |
| `node` | |
| `result` | |

# Functions

## `ao_barrier_wait`
## `ao_barrier_wait_from`

```c
bool ao_barrier_wait(     ao_barrier_t * x, ao_time_t timeout);
bool ao_barrier_wait_from(ao_barrier_t * x, ao_time_t timeout, ao_time_t beginning);
```

## `ao_barrier_wait_forever`

```c
bool ao_barrier_wait_forever(ao_barrier_t * x);
```

## `ao_barrier_wait_try`

```c
bool ao_barrier_wait_try(ao_barrier_t * x);
```

## `ao_barrier_wait_begin`
## `ao_barrier_wait_end`

```c
void ao_barrier_wait_begin(ao_barrier_wait_t * x);
void ao_barrier_wait_end(  ao_barrier_wait_t * x);
```
