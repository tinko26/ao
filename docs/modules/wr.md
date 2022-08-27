---
author: "Stefan Wagner"
date: 2022-08-16
description: "The ao_wr.h module of the ao real-time operating system."
draft: true
permalink: /modules/wr/
title: "<code>ao_wr.h"
---

# Overview

...

- Readers-writer locks preferring writers.
- That is, readers must wait until there are no more writers.

...

## Types

### Lock

The `ao_wr_t` type represents a readers-writer lock.

```c
struct ao_wr_t
{
    ao_uint_t r_active;
    ao_list_t r_waiting;
    bool      w_active;
    ao_list_t w_waiting;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `r_active` | The number of active readers. |
| `r_waiting` | The list of waiting readers |
| `w_active` | Indicates whether a writer is active. |
| `w_waiting` | The list of waiting writers. |

### Locking

The `ao_wr_lock_t` type represents the locking of a readers-writer lock.

```c
struct ao_wr_lock_t
{
    ao_async_t     async;
    ao_list_node_t node;
    bool volatile  result;
    ao_wr_t *      wr;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `async` | The asynchronous event. |
| `node` | The node for the lock's waiting lists. |
| `result` | Indicates whether the locking was successful. |
| `rw` | The lock. |

## Functions

Let's assume, that there is a global variable ...

```c
double data[16];
```

```c
ao_wr_t lock;
```

### Locking to Read

...

```c
bool can_read = ao_wr_lock_read(&lock, AO_MILLISECONDS(500));

if (can_read)
{
    /* ... */ = data[0];
    /* ... */ = data[1];
    /* ... */ = data[2];

    ao_wr_unlock_read(&lock);
}
```

...

### Locking to Write

...

```c
bool can_write = ao_wr_lock_write(&lock, AO_MILLISECONDS(500));

if (can_write)
{
    data[0] = /* ... */;
    data[1] = /* ... */;
    data[2] = /* ... */;

    ao_wr_unlock_write(&lock);
}
```

...

## External Links

[https://en.wikipedia.org/wiki/Readers–writer_lock](https://en.wikipedia.org/wiki/Readers–writer_lock)
