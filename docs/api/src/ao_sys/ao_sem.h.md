---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
external-wiki:
- semaphore
permalink: /api/src/ao_sys/ao_sem.h/
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
typedef struct ao_sem_t      ao_sem_t;
```

```c
typedef struct ao_sem_take_t ao_sem_take_t;
```

# Types

## `ao_sem_t`

This type represents a counting semaphore.

```c
struct ao_sem_t
{
ao_uint_t count;
ao_list_t list;
};
```

It consists of the following members.

| `count` | The count of the semaphore. |
| `list` | The list of tasks attempting to take the semaphore. |

## `ao_sem_take_t`

This type represents the taking of a semaphore count.

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

It consists of the following members.

| `async` | The asynchronous event. |
| `count` | The count to take. |
| `node` | The list node. |
| `result` | Indicates whether the semaphore count has been taken. |
| `sem` | The semaphore. |

# Functions

```c
void ao_sem_give(ao_sem_t * x, ao_uint_t count);
```

```c
bool ao_sem_take(ao_sem_t * x, ao_uint_t count, ao_time_t timeout);
```

```c
bool ao_sem_take_from(ao_sem_t * x, ao_uint_t count, ao_time_t timeout, ao_time_t beginning);
```

```c
bool ao_sem_take_forever(ao_sem_t * x, ao_uint_t count);
```

```c
bool ao_sem_take_try(ao_sem_t * x, ao_uint_t count);
```

```c
void ao_sem_take_begin(ao_sem_take_t * x);
```

```c
void ao_sem_take_end(ao_sem_take_t * x);
```
