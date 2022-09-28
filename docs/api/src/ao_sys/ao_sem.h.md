---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
external:
- https://en.wikipedia.org/wiki/Semaphore_(programming) : "Semaphore"
permalink: /api/src/ao_sys/ao_sem.h/
toc: true
---

# Notes

This module defines counting semaphores.

# Include

| [`ao_async.h`](ao_async.h.md) |
| [`ao_list.h`](../ao/ao_list.h.md) |
| [`ao_time.h`](ao_time.h.md) |
| [`ao_uint.h`](../ao/ao_uint.h.md) |
| `stdbool.h` |

# Types

## `ao_sem_t`

```c
typedef struct ao_sem_t ao_sem_t;
```

Represents a counting semaphore.

## `ao_sem_take_t`

```c
typedef struct ao_sem_take_t ao_sem_take_t;
```

Represents the taking of a counting semaphore.

# Structs

## `ao_sem_t`

```c
struct ao_sem_t
{
    ao_uint_t count;
    ao_list_t take;
};
```

| `count` | The count. |
| `take` | The list of takings. |

## `ao_sem_take_t`

```c
struct ao_sem_take_t
{
    ao_async_t     async;
    ao_uint_t      count;
    bool volatile  result;
    ao_sem_t *     sem;
    ao_list_node_t sem_take_node;
};
```

| `async` | The asynchronous event. |
| `count` | The count to take. |
| `result` | The result. |
| `sem` | The counting semaphore. |
| `sem_take_node` | The node for the counting semaphore's list of takings. |

# Functions

## `ao_sem_give`

```c
void ao_sem_give(ao_sem_t * sem, ao_uint_t count);
```

Gives a counting semaphore.

## `ao_sem_take`
## `ao_sem_take_from`

```c
bool ao_sem_take     (ao_sem_t * sem, ao_uint_t count, ao_time_t timeout);
bool ao_sem_take_from(ao_sem_t * sem, ao_uint_t count, ao_time_t timeout, ao_time_t beginning);
```

Takes a counting semaphore in a blocking fashion with a timeout and an optional beginning.

## `ao_sem_take_forever`

```c
bool ao_sem_take_forever(ao_sem_t * sem, ao_uint_t count);
```

Takes a counting semaphore indefinitely in a blocking fashion.

## `ao_sem_take_try`

```c
bool ao_sem_take_try(ao_sem_t * sem, ao_uint_t count);
```

Takes a counting semaphore in a non-blocking fashion.

## `ao_sem_take_begin`
## `ao_sem_take_end`

```c
void ao_sem_take_begin(ao_sem_take_t * take);
void ao_sem_take_end  (ao_sem_take_t * take);
```

Begins or ends, respectively, a taking of a counting semaphore.
