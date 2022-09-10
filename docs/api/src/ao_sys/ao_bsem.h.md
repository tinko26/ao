---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
external:
- https://en.wikipedia.org/wiki/Semaphore_(programming) : "Semaphore"
permalink: /api/src/ao_sys/ao_bsem.h/
toc: true
---

# Include

```c
#include <ao_async.h>
#include <ao_list.h>
#include <ao_time.h>
#include <stdbool.h>
```

# Identifiers

## `AO_BSEM`

```c
#define AO_BSEM
```

# Typedefs

# Types

## `ao_bsem_t`

```c
typedef struct ao_bsem_t ao_bsem_t;
```

```c
struct ao_bsem_t
{
    ao_list_t list;
    bool      taken;
};
```

This type represents a binary semaphore. It consists of the following members.

| `list` | The list of tasks attempting to take the semaphore. |
| `taken` | Indicates whether the semaphore is taken. |

## `ao_bsem_take_t`

```c
typedef struct ao_bsem_take_t ao_bsem_take_t;
```

```c
struct ao_bsem_take_t
{
    ao_async_t     async;
    ao_list_node_t node;
    bool volatile  result;
    ao_bsem_t *    sem;
};
```

This type represents the taking of a binary semaphore. It consists of the following members.

| `async` | The asynchronous event. |
| `node` | The list node. |
| `result` | Indicates whether the binary semaphore has been taken. |
| `sem` | The binary semaphore. |

# Functions

## `ao_bsem_give`

```c
void ao_bsem_give(ao_bsem_t * x);
```

Gives a binary semaphore. This function can be called from both task and interrupt context.

## `ao_bsem_take`
## `ao_bsem_take_from`

```c
bool ao_bsem_take(     ao_bsem_t * x, ao_time_t timeout);
bool ao_bsem_take_from(ao_bsem_t * x, ao_time_t timeout, ao_time_t beginning);
```

## `ao_bsem_take_forever`

```c
bool ao_bsem_take_forever(ao_bsem_t * x);
```

## `ao_bsem_take_try`

```c
bool ao_bsem_take_try(ao_bsem_t * x);
```

## `ao_bsem_take_begin`
## `ao_bsem_take_end`

```c
void ao_bsem_take_begin(ao_bsem_take_t * x);
void ao_bsem_take_end(  ao_bsem_take_t * x);
```
