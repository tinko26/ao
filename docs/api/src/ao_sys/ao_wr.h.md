---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
external:
- https://en.wikipedia.org/wiki/Readers–writer_lock : "Readers-writer lock"
permalink: /api/src/ao_sys/ao_wr.h/
toc: true
---

# Notes

...

- Readers-writer locks preferring writers.
- That is, readers must wait until there are no more writers.

...

# Include

```c
#include <ao_async.h>
#include <ao_list.h>
#include <ao_time.h>
#include <ao_uint.h>
#include <stdbool.h>
```

# Identifiers

## `AO_WR`

```c
#define AO_WR
```

# Typedefs

```c
typedef struct ao_wr_t      ao_wr_t;
typedef struct ao_wr_lock_t ao_wr_lock_t;
```

# Types

## `ao_wr_t`

This type represents a readers-writer lock.

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

| `r_active` | The number of active readers. |
| `r_waiting` | The list of waiting readers |
| `w_active` | Indicates whether a writer is active. |
| `w_waiting` | The list of waiting writers. |

## `ao_wr_lock_t`

This type represents the locking of a readers-writer lock.

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

| `async` | The asynchronous event. |
| `node` | The node for the lock's waiting lists. |
| `result` | Indicates whether the locking was successful. |
| `rw` | The lock. |

# Functions

## `ao_wr_lock_read`
## `ao_wr_lock_read_from`

```c
bool ao_wr_lock_read(     ao_wr_t * x, ao_time_t timeout);
bool ao_wr_lock_read_from(ao_wr_t * x, ao_time_t timeout, ao_time_t beginning);
```

## `ao_wr_lock_read_forever`

```c
bool ao_wr_lock_read_forever(ao_wr_t * x);
```

## `ao_wr_lock_read_try`

```c
bool ao_wr_lock_read_try(ao_wr_t * x);
```

## `ao_wr_lock_read_begin`
## `ao_wr_lock_read_end`

```c
void ao_wr_lock_read_begin(ao_wr_lock_t * x);
void ao_wr_lock_read_end(  ao_wr_lock_t * x);
```

## `ao_wr_lock_write`
## `ao_wr_lock_write_from`

```c
bool ao_wr_lock_write(     ao_wr_t * x, ao_time_t timeout);
bool ao_wr_lock_write_from(ao_wr_t * x, ao_time_t timeout, ao_time_t beginning);
```

## `ao_wr_lock_write_forever`

```c
bool ao_wr_lock_write_forever(ao_wr_t * x);
```

## `ao_wr_lock_write_try`

```c
bool ao_wr_lock_write_try(ao_wr_t * x);
```

## `ao_wr_lock_write_begin`
## `ao_wr_lock_write_end`

```c
void ao_wr_lock_write_begin(ao_wr_lock_t * x);
void ao_wr_lock_write_end(  ao_wr_lock_t * x);
```

## `ao_wr_unlock_read`

```c
void ao_wr_unlock_read(ao_wr_t * x);
```

## `ao_wr_unlock_write`

```c
void ao_wr_unlock_write(ao_wr_t * x);
```

# Example

Let's assume, that there is a global variable ...

```c
double data[16];
```

```c
ao_wr_t lock;
```

Locking to Read.

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

Locking to Write.

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
