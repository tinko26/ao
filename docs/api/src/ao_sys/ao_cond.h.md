---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_cond.h/
toc: true
---

# Notes

...

- Condition (variable), but not that monitor-based kind implemented in the STL.
- actually the same behavior as a binary semaphore

...

# Include

```c
#include <ao_async.h>
#include <ao_list.h>
#include <ao_time.h>
#include <stdbool.h>
```

# Identifier

```c
#define AO_COND
```

# Types

## `ao_cond_t`

```c
typedef struct ao_cond_t ao_cond_t;
```

```c
struct ao_cond_t
{
    ao_list_t list;
    bool      state;
};
```

This type represents a condition. It consists of the following members.

| `list` | |
| `state` | |

## `ao_cond_wait_t`

```c
typedef struct ao_cond_wait_t ao_cond_wait_t;
```

```c
struct ao_cond_wait_t
{
    ao_async_t     async;
    ao_cond_t *    cond;
    ao_list_node_t node;
    bool volatile  result;
};
```

This type represents the waiting for a condition. It consists of the following members.

| `async` | |
| `cond` | |
| `node` | |
| `result` | |

# Functions

## `ao_cond_clear`

```c
void ao_cond_clear(ao_cond_t * x);
```

## `ao_cond_set`

```c
void ao_cond_set(ao_cond_t * x);
```

## `ao_cond_wait`
## `ao_cond_wait_from`

```c
bool ao_cond_wait(     ao_cond_t * x, ao_time_t timeout);
bool ao_cond_wait_from(ao_cond_t * x, ao_time_t timeout, ao_time_t beginning);
```

## `ao_cond_wait_forever`

```c
bool ao_cond_wait_forever(ao_cond_t * x);
```

## `ao_cond_wait_try`

```c
bool ao_cond_wait_try(ao_cond_t * x);
```

## `ao_cond_wait_begin`
## `ao_cond_wait_end`

```c
void ao_cond_wait_begin(ao_cond_wait_t * x);
void ao_cond_wait_end(  ao_cond_wait_t * x);
```
