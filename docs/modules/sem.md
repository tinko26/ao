---
author: "Stefan Wagner"
date: 2022-08-16
description: "The ao_sem.h module of the ao real-time operating system."
draft: true
permalink: /modules/sem/
title: "ao_sem.h"
---

# ao_sem.h

...

- Counting semaphore

...

## Types

### Semaphore

The `ao_sem_t` type represents a semaphore.

```c
struct ao_sem_t
{
    ao_uint_t count;
    ao_list_t list;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `count` | The count of the semaphore. |
| `list` | The list of tasks attempting to take the semaphore. |

### Semaphore Taking

The `ao_sem_take_t` type represents the taking of a semaphore count.

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

| Member | |
|--------|-|
| `async` | The asynchronous event. |
| `count` | The count to take. |
| `node` | The list node. |
| `result` | Indicates whether the semaphore count has been taken. |
| `sem` | The semaphore. |

## Functions

### Giving

A semaphore count can be given from both task and interrupt context.

```c
ao_sem_t * s;
```

```c
ao_sem_give(s, 2);
```

### Taking

In contrast, a semaphore count can be taken by a task, only.

```c
bool r;
```

```c
r = ao_sem_take(s, 2, AO_MILLISECONDS(500));

if (r)
{
    // Semaphore count of 2 has been taken.
}
```

## External Links

[https://en.wikipedia.org/wiki/Semaphore_(programming)](https://en.wikipedia.org/wiki/Semaphore_(programming))
