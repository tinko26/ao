---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
external:
- https://en.wikipedia.org/wiki/Barrier_(computer_science) : "Barrier"
permalink: /api/src/ao_sys/ao_barrier.h/
toc: true
---

# Notes

This module defines execution barriers, where tasks can synchronize.

# Include

| [`ao_async.h`](ao_async.h.md) |
| [`ao_list.h`](../ao/ao_list.h.md) |
| [`ao_time.h`](ao_time.h.md) |
| [`ao_uint.h`](../ao/ao_uint.h.md) |
| `stdbool.h` |

# Types

## `ao_barrier_t`

```c
typedef struct ao_barrier_t ao_barrier_t;
```

Represents a barrier.

## `ao_barrier_wait_t`

```c
typedef struct ao_barrier_wait_t ao_barrier_wait_t;
```

Represents the waiting at a barrier.

# Structs

## `ao_barrier_t`

```c
struct ao_barrier_t
{
    ao_uint_t count;
    ao_uint_t count_threshold;
    ao_list_t wait;
};
```

| `count` | The current number of waitings. |
| `count_threshold` | The maximum number waitings. |
| `wait` | The list of waitings. |

## `ao_barrier_wait_t`

```c
struct ao_barrier_wait_t
{
    ao_async_t     async;
    ao_barrier_t * barrier;
    ao_list_node_t barrier_wait_node;
    bool volatile  result;
};
```

| `async` | The asynchronous event. |
| `barrier` | The barrier. |
| `barrier_wait_node` | The node for the barrier's list of waitings. |
| `result` | The result. |

# Functions

## `ao_barrier_wait`
## `ao_barrier_wait_from`

```c
bool ao_barrier_wait     (ao_barrier_t * b, ao_time_t timeout);
bool ao_barrier_wait_from(ao_barrier_t * b, ao_time_t timeout, ao_time_t beginning);
```

Waits at a barrier in a blocking fashion with a timeout and an optional beginning.

## `ao_barrier_wait_forever`

```c
bool ao_barrier_wait_forever(ao_barrier_t * b);
```

Waits at a barrier indefinitely in a blocking fashion.

## `ao_barrier_wait_try`

```c
bool ao_barrier_wait_try(ao_barrier_t * b);
```

Waits at a barrier in a non-blocking fashion.

## `ao_barrier_wait_begin`
## `ao_barrier_wait_end`

```c
void ao_barrier_wait_begin(ao_barrier_wait_t * w);
void ao_barrier_wait_end  (ao_barrier_wait_t * w);
```

Begins or ends, respectively, a waiting at a barrier.
