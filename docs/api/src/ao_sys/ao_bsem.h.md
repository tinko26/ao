---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
external:
- https://en.wikipedia.org/wiki/Semaphore_(programming) : "Semaphore"
permalink: /api/src/ao_sys/ao_bsem.h/
toc: true
---

# Notes

This module defines binary semaphore.

# Include

| [`ao_async.h`](ao_async.h.md) |
| [`ao_list.h`](../ao/ao_list.h.md) |
| [`ao_time.h`](ao_time.h.md) |
| `stdbool.h` |

# Types

## `ao_bsem_t`

```c
typedef struct ao_bsem_t ao_bsem_t;
```

Represents a binary semaphore.

## `ao_bsem_take_t`

```c
typedef struct ao_bsem_take_t ao_bsem_take_t;
```

Represents the taking of a binary semaphore.

# Structs

## `ao_bsem_t`

```c
struct ao_bsem_t
{
    ao_list_t take;
    bool      taken;
};
```

| `take` | The list of takings. |
| `taken` | Indicates whether the semaphore is taken. |

## `ao_bsem_take_t`

```c
struct ao_bsem_take_t
{
    ao_async_t     async;
    ao_bsem_t *    bsem;
    ao_list_node_t bsem_take_node;
    bool volatile  result;
};
```

| `async` | The asynchronous event. |
| `bsem` | The binary semaphore. |
| `bsem_take_node` | The node for the binary semaphore's list of takings. |
| `result` | The result. |

# Functions

## `ao_bsem_give`

```c
void ao_bsem_give(ao_bsem_t * bsem);
```

Gives a binary semaphore.

## `ao_bsem_take`
## `ao_bsem_take_from`

```c
bool ao_bsem_take     (ao_bsem_t * bsem, ao_time_t timeout);
bool ao_bsem_take_from(ao_bsem_t * bsem, ao_time_t timeout, ao_time_t beginning);
```

Takes a binary semaphore in a blocking fashion with a timeout and an optional beginning.

## `ao_bsem_take_forever`

```c
bool ao_bsem_take_forever(ao_bsem_t * bsem);
```

Takes a binary semaphore indefinitely in a blocking fashion.

## `ao_bsem_take_try`

```c
bool ao_bsem_take_try(ao_bsem_t * bsem);
```

Takes a binary semaphore in a non-blocking fashion.

## `ao_bsem_take_begin`
## `ao_bsem_take_end`

```c
void ao_bsem_take_begin(ao_bsem_take_t * take);
void ao_bsem_take_end  (ao_bsem_take_t * take);
```

Begins or ends, respectively, a taking of a binary semaphore.
