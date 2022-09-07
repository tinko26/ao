---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
external-wiki:
- lock
- mutual-exclusion
permalink: /api/src/ao_sys/ao_mutex.h/
toc: true
---

# Overview

...

- mutual exclusion
- owned by a task
- supports (immediate and original) priority ceiling and priority inheritance
- reentrant

...

# Include

```c
#include <ao_async.h>
#include <ao_list.h>
#include <ao_task.h>
#include <ao_time.h>
#include <ao_uint.h>
#include <stdbool.h>
```

# Typedefs

```c
typedef struct ao_mutex_t      ao_mutex_t;
```

```c
typedef struct ao_mutex_lock_t ao_mutex_lock_t;
```

# Types

## `ao_mutex_t`

This type represents a mutex.

```c
struct ao_mutex_t
{

#if AO_TASK_CEILING

ao_task_ceiling_t ceiling_immediate;
ao_task_ceiling_t ceiling_original;

#endif

ao_list_t         list;
ao_task_t *       owner;
ao_uint_t         owner_count;

#if AO_TASK_SUBMISSION

ao_task_slave_t   slave;

#endif

};
```

It consists of the following members.

| `ceiling_immediate` | The immediate task ceiling.|
| `ceiling_original` | The original task ceiling. |
| `list` | The list of tasks attempting to lock the mutex. |
| `owner` | The owner. This value is `NULL`, if the mutex is not locked. |
| `owner_count` | The owner count. This value is zero, if the mutex is not locked, otherwise positive. |
| `slave` | The task slave. |

## `ao_mutex_lock_t`

This type represents the locking of a mutex.

```c
struct ao_mutex_lock_t
{
ao_async_t       async;

#if AO_TASK_INHERITANCE

ao_task_master_t master;

#endif

ao_mutex_t *     mutex;
ao_list_node_t   node;
bool volatile    result;
ao_task_t *      task;
};
```

It consists of the following members.

| `async` | The asynchronous event. |
| `master` | The task master. |
| `mutex` | The mutex. |
| `node` | The node for the mutex's list of locking tasks. |
| `result` | Indicates whether the mutex has been locked. |
| `task` | The task. |

# Functions

```c
bool ao_mutex_lock(ao_mutex_t * x, ao_time_t timeout);
```

```c
bool ao_mutex_lock_from(ao_mutex_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
bool ao_mutex_lock_forever(ao_mutex_t * x);
```

```c
bool ao_mutex_lock_try(ao_mutex_t * x);
```

```c
void ao_mutex_lock_begin(ao_mutex_lock_t * x);
```

```c
void ao_mutex_lock_end(ao_mutex_lock_t * x);
```

```c
void ao_mutex_unlock(ao_mutex_t * x);
```
