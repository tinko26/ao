---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
external:
- https://en.wikipedia.org/wiki/Semaphore_(programming) : "Semaphore"
permalink: /api/src/ao_sys/ao_sem.h/
toc: true
---

# Notes

This module defines counting semaphores.

# Include

[`ao_async.h`](ao_async.h.md) <br/>
[`ao_list.h`](../ao/ao_list.h.md) <br/>
[`ao_time.h`](ao_time.h.md) <br/>
[`ao_uint.h`](../ao/ao_uint.h.md) <br/>
`stdbool.h`

# Identifier

```c
#define AO_SEM
```

# Types

## `ao_sem_t`

```c
typedef struct ao_sem_t ao_sem_t;
```

```c
struct ao_sem_t
{
    ao_uint_t count;
    ao_list_t list;
};
```

This type represents a counting semaphore. It consists of the following members.

| `count` | The count. |
| `list` | The list of takings. |

## `ao_sem_take_t`

```c
typedef struct ao_sem_take_t ao_sem_take_t;
```

```c
struct ao_sem_take_t
{
    ao_async_t     async;
    ao_uint_t      count;
    ao_list_node_t node;
    bool volatile  result;
    ao_sem_t *     sem;
};
```

This type represents the taking of a counting semaphore. It consists of the following members.

| `async` | The asynchronous event. |
| `count` | The count to take. |
| `node` | The node for the counting semaphore's list of takings. |
| `result` | The result. |
| `sem` | The counting semaphore. |

# Functions

## `ao_sem_give`

```c
void ao_sem_give(ao_sem_t * x, ao_uint_t count);
```

Gives a counting semaphore.

## `ao_sem_take`
## `ao_sem_take_from`

```c
bool ao_sem_take     (ao_sem_t * x, ao_uint_t count, ao_time_t timeout);
bool ao_sem_take_from(ao_sem_t * x, ao_uint_t count, ao_time_t timeout, ao_time_t beginning);
```

Takes a counting semaphore in a blocking fashion with a timeout and an optional beginning.

## `ao_sem_take_forever`

```c
bool ao_sem_take_forever(ao_sem_t * x, ao_uint_t count);
```

Takes a counting semaphore indefinitely in a blocking fashion.

## `ao_sem_take_try`

```c
bool ao_sem_take_try(ao_sem_t * x, ao_uint_t count);
```

Takes a counting semaphore in a non-blocking fashion.

## `ao_sem_take_begin`
## `ao_sem_take_end`

```c
void ao_sem_take_begin(ao_sem_take_t * x);
void ao_sem_take_end  (ao_sem_take_t * x);
```

Begins or ends, respectively, a taking of a counting semaphore.
