---
author: "Stefan Wagner"
date: 2022-08-16
description: "The ao_mutex.h module of the ao real-time operating system."
draft: true
permalink: /modules/mutex/
title: "ao_mutex.h"
---

# ao_mutex.h

...

- mutual exclusion
- owned by a task
- supports (immediate and original) priority ceiling and priority inheritance
- reentrant

...

## Types

### Mutex

The `ao_mutex_t` type represents a mutex.

```c
struct ao_mutex_t
{
    ao_task_ceiling_t ceiling_immediate;
    ao_task_ceiling_t ceiling_original;
    ao_list_t         list;
    ao_task_t *       owner;
    ao_uint_t         owner_count;
    ao_task_slave_t   slave;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `ceiling_immediate` | The immediate task ceiling. This member is absent, if the [task scheduler](../task-scheduler.md) does not support task ceiling. |
| `ceiling_original` | The original task ceiling. This member is absent, if the task scheduler does not support task ceiling. |
| `list` | The list of tasks attempting to lock the mutex. |
| `owner` | The owner. This value is `NULL`, if the mutex is not locked. |
| `owner_count` | The owner count. This value is zero, if the mutex is not locked, otherwise positive. |
| `slave` | The task slave. This member is absent, if the scheduler does not support task submission. |

### Mutex Locking

The `ao_mutex_lock_t` type represents the locking of a mutex.

```c
struct ao_mutex_lock_t
{
    ao_async_t       async;
    ao_task_master_t master;
    ao_mutex_t *     mutex;
    ao_list_node_t   node;
    bool volatile    result;
    ao_task_t *      task;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `async` | The asynchronous event. |
| `master` | The task master. This member is absent, if the [task scheduler](../task-scheduler.md) does not support task inheritance. |
| `mutex` | The mutex. |
| `node` | The node for the mutex's list of locking tasks. |
| `result` | Indicates whether the mutex has been locked. |
| `task` | The task. |

## Functions

### Locking

...

### Unlocking

...

## External Links

[https://en.wikipedia.org/wiki/Lock_(computer_science)](https://en.wikipedia.org/wiki/Lock_(computer_science))

[https://en.wikipedia.org/wiki/Mutual_exclusion](https://en.wikipedia.org/wiki/Mutual_exclusion)
