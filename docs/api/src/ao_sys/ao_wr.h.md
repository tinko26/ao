---
author: "Stefan Wagner"
date: 2022-09-13
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

| [`ao_async.h`](ao_async.h.md) |
| [`ao_list.h`](../ao/ao_list.h.md) |
| [`ao_time.h`](ao_time.h.md) |
| [`ao_uint.h`](../ao/ao_uint.h.md) |
| `stdbool.h` |

# Identifier

```c
#define AO_WR
```

# Types

## `ao_wr_t`

```c
typedef struct ao_wr_t ao_wr_t;
```

This type represents a readers-writer lock.

## `ao_wr_lock_t`

```c
typedef struct ao_wr_lock_t ao_wr_lock_t;
```

This type represents the locking of a readers-writer lock.

# Structs

## `ao_wr_t`

```c
struct ao_wr_t
{
    ao_uint_t r_active;
    ao_list_t r_waiting;
    bool      w_active;
    ao_list_t w_waiting;
};
```

| `r_active` | The number of active readers. |
| `r_waiting` | The list of waiting readers |
| `w_active` | Indicates whether a writer is active. |
| `w_waiting` | The list of waiting writers. |

## `ao_wr_lock_t`

```c
struct ao_wr_lock_t
{
    ao_async_t     async;
    ao_list_node_t node;
    bool volatile  result;
    ao_wr_t *      wr;
};
```

| `async` | The asynchronous event. |
| `node` | The node for the readers-writer lock's waiting lists. |
| `result` | The result. |
| `wr` | The readers-writer lock. |

# Functions

## `ao_wr_lock_read`
## `ao_wr_lock_read_from`

```c
bool ao_wr_lock_read     (ao_wr_t * x, ao_time_t timeout);
bool ao_wr_lock_read_from(ao_wr_t * x, ao_time_t timeout, ao_time_t beginning);
```

Locks a readers-writer lock for reading in a blocking fashion with a timeout and an optional beginning.

## `ao_wr_lock_read_forever`

```c
bool ao_wr_lock_read_forever(ao_wr_t * x);
```

Locks a readers-writer lock for reading indefinitely in a blocking fashion.

## `ao_wr_lock_read_try`

```c
bool ao_wr_lock_read_try(ao_wr_t * x);
```

Locks a readers-writer lock for reading in a non-blocking fashion.

## `ao_wr_lock_read_begin`
## `ao_wr_lock_read_end`

```c
void ao_wr_lock_read_begin(ao_wr_lock_t * x);
void ao_wr_lock_read_end  (ao_wr_lock_t * x);
```

Begins or ends, respectively, a locking of a readers-writer lock for reading.

## `ao_wr_lock_write`
## `ao_wr_lock_write_from`

```c
bool ao_wr_lock_write     (ao_wr_t * x, ao_time_t timeout);
bool ao_wr_lock_write_from(ao_wr_t * x, ao_time_t timeout, ao_time_t beginning);
```

Locks a readers-writer lock for writing in a blocking fashion with a timeout and an optional beginning.

## `ao_wr_lock_write_forever`

```c
bool ao_wr_lock_write_forever(ao_wr_t * x);
```

Locks a readers-writer lock for writing indefinitely in a blocking fashion.

## `ao_wr_lock_write_try`

```c
bool ao_wr_lock_write_try(ao_wr_t * x);
```

Locks a readers-writer lock for writing in a non-blocking fashion.

## `ao_wr_lock_write_begin`
## `ao_wr_lock_write_end`

```c
void ao_wr_lock_write_begin(ao_wr_lock_t * x);
void ao_wr_lock_write_end  (ao_wr_lock_t * x);
```

Begins or ends, respectively, a locking of a readers-writer lock for writing.

## `ao_wr_unlock_read`

```c
void ao_wr_unlock_read(ao_wr_t * x);
```

Unlocks a readers-writer lock for reading.

## `ao_wr_unlock_write`

```c
void ao_wr_unlock_write(ao_wr_t * x);
```

Unlocks a readers-writer lock for writing.
