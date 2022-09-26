---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
external:
- https://en.wikipedia.org/wiki/Lock_(computer_science) : "Lock"
- https://en.wikipedia.org/wiki/Mutual_exclusion : "Mutual exclusion"
permalink: /api/src/ao_sys/ao_mutex.h/
toc: true
---

# Notes

...

- mutual exclusion
- owned by a task
- supports (immediate and original) priority ceiling and priority inheritance
- reentrant

...

# Include

| [`ao_async.h`](ao_async.h.md) |
| [`ao_list.h`](../ao/ao_list.h.md) |
| [`ao_task.h`](ao_task.h.md) |
| [`ao_time.h`](ao_time.h.md) |
| [`ao_uint.h`](../ao/ao_uint.h.md) |
| `stdbool.h` |

# Identifier

```c
#define AO_MUTEX
```

# Types

## `ao_mutex_t`

```c
typedef struct ao_mutex_t ao_mutex_t;
```

This type represents a mutex.

## `ao_mutex_lock_t`

```c
typedef struct ao_mutex_lock_t ao_mutex_lock_t;
```

This type represents the locking of a mutex.

# Structs

## `ao_mutex_t`

```c
struct ao_mutex_t
{

#if AO_TASK_CEILING

    ao_task_ceiling_t ceiling_immediate;
    ao_task_ceiling_t ceiling_original;

#endif

    ao_list_t         lock;
    ao_task_t *       owner;
    ao_uint_t         owner_count;

#if AO_TASK_SUBMISSION

    ao_task_slave_t   slave;

#endif

};
```

| `ceiling_immediate` | The immediate task ceiling.|
| `ceiling_original` | The original task ceiling. |
| `lock` | The list of lockings. |
| `owner` | The owner. |
| `owner_count` | The owner count. |
| `slave` | The task slave. |

## `ao_mutex_lock_t`

```c
struct ao_mutex_lock_t
{
    ao_async_t       async;

#if AO_TASK_INHERITANCE

    ao_task_master_t master;

#endif

    ao_mutex_t *     mutex;
    ao_list_node_t   mutex_lock_node;
    bool volatile    result;
    ao_task_t *      task;
};
```

| `async` | The asynchronous event. |
| `master` | The task master. |
| `mutex` | The mutex. |
| `mutex_lock_node` | The node for the mutex's list of lockings. |
| `result` | The result. |
| `task` | The task. |

# Functions

## `ao_mutex_lock`
## `ao_mutex_lock_from`

```c
bool ao_mutex_lock     (ao_mutex_t * mutex, ao_time_t timeout);
bool ao_mutex_lock_from(ao_mutex_t * mutex, ao_time_t timeout, ao_time_t beginning);
```

Locks a mutex in a blocking fashion with a timeout and an optional beginning.

## `ao_mutex_lock_forever`

```c
bool ao_mutex_lock_forever(ao_mutex_t * mutex);
```

Locks a mutex indefinitely in a blocking fashion.

## `ao_mutex_lock_try`

```c
bool ao_mutex_lock_try(ao_mutex_t * mutex);
```

Locks a mutex in a non-blocking fashion.

## `ao_mutex_lock_begin`
## `ao_mutex_lock_end`

```c
void ao_mutex_lock_begin(ao_mutex_lock_t * lock);
void ao_mutex_lock_end  (ao_mutex_lock_t * lock);
```

Begins or ends, respectively, a locking of a mutex.

## `ao_mutex_unlock`

```c
void ao_mutex_unlock(ao_mutex_t * mutex);
```

Unlocks a mutex.
