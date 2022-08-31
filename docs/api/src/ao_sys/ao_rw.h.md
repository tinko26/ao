---
api: true
author: "Stefan Wagner"
date: 2022-08-31
description: "The /src/ao_sys/ao_rw.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_rw.h/
subtitle: "Readers-writer locks preferring readers"
title: "ao_rw.h"
toc: true
wiki:
- title: "Readers-writer lock"
  url: https://en.wikipedia.org/wiki/Readers–writer_lock
---

# Overview

...

- Readers-writer locks preferring readers.
- That is, writers must wait until there are no more readers.

...

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
typedef struct ao_rw_t      ao_rw_t;
```

```c
typedef struct ao_rw_lock_t ao_rw_lock_t;
```

# Types

## `ao_rw_t`

This type represents a readers-writer lock.

```c
struct ao_rw_t
{
    ao_uint_t r_active;
    ao_list_t r_waiting;
    bool      w_active;
    ao_list_t w_waiting;
};
```

It consists of the following members.

| `r_active` | The number of active readers. |
| `r_waiting` | The list of waiting readers |
| `w_active` | Indicates whether a writer is active. |
| `w_waiting` | The list of waiting writers. |

## `ao_rw_lock_t`

This type represents the locking of a readers-writer lock.

```c
struct ao_rw_lock_t
{
    ao_async_t     async;
    ao_list_node_t node;
    bool volatile  result;
    ao_rw_t *      rw;
};
```

It consists of the following members.

| `async` | The asynchronous event. |
| `node` | The node for the lock's waiting lists. |
| `result` | Indicates whether the locking was successful. |
| `rw` | The lock. |

# Functions

```c
bool ao_rw_lock_read(ao_rw_t * x, ao_time_t timeout);
```

```c
bool ao_rw_lock_read_forever(ao_rw_t * x);
```

```c
bool ao_rw_lock_read_from(ao_rw_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
bool ao_rw_lock_read_try(ao_rw_t * x);
```

```c
void ao_rw_lock_read_begin(ao_rw_lock_t * x);
```

```c
void ao_rw_lock_read_end(ao_rw_lock_t * x);
```

```c
bool ao_rw_lock_write(ao_rw_t * x, ao_time_t timeout);
```

```c
bool ao_rw_lock_write_forever(ao_rw_t * x);
```

```c
bool ao_rw_lock_write_from(ao_rw_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
bool ao_rw_lock_write_try(ao_rw_t * x);
```

```c
void ao_rw_lock_write_begin(ao_rw_lock_t * x);
```

```c
void ao_rw_lock_write_end(ao_rw_lock_t * x);
```

```c
void ao_rw_unlock_read(ao_rw_t * x);
```

```c
void ao_rw_unlock_write(ao_rw_t * x);
```

# Example

Let's assume, that there is a global variable ...

```c
double data[16];
```

```c
ao_rw_t lock;
```

Locking to Read.

...

```c
bool can_read = ao_rw_lock_read(&lock, AO_MILLISECONDS(500));

if (can_read)
{
    /* ... */ = data[0];
    /* ... */ = data[1];
    /* ... */ = data[2];

    ao_rw_unlock_read(&lock);
}
```

...

Locking to Write.

...

```c
bool can_write = ao_rw_lock_write(&lock, AO_MILLISECONDS(500));

if (can_write)
{
    data[0] = /* ... */;
    data[1] = /* ... */;
    data[2] = /* ... */;

    ao_rw_unlock_write(&lock);
}
```

...
