---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
permalink: /api/src/ao_sys/ao_recv.h/
toc: true
---

# Notes

This module provides an abstraction for receiving from an opaque source.

# Include

| [`ao_async.h`](ao_async.h.md) |
| [`ao_time.h`](ao_time.h.md) |
| `stdbool.h` |
| `stddef.h` |

# Identifier

```c
#define AO_RECV
```

# Types

## `ao_recv_t`

```c
typedef struct ao_recv_t ao_recv_t;
```

This type represents the receiving of data.

## `ao_recv_proc_t`

```c
typedef void (* ao_recv_proc_t)
(
    ao_recv_t * x
);
```

This type represents a function beginning or ending a receiving.

# Structs

## `ao_recv_t`

```c
struct ao_recv_t
{
    ao_async_t      async;
    ao_recv_proc_t  begin;
    size_t volatile count;
    size_t          count_max;
    size_t          count_min;
    ao_recv_proc_t  end;
    void *          parameter;
    void *          ptr;
    bool   volatile result;
};
```

| `async` | The asynchronous event. |
| `begin` | The function beginning the receiving. |
| `count` | The number of received bytes. |
| `count_max` | The maximum number of bytes to receive. |
| `count_min` | The minimum number of bytes to receive. |
| `end` | The function ending the receiving. |
| `parameter` | An additional parameter. |
| `ptr` | The location to store the received data. |
| `result` | The result. |

# Functions

## `ao_recv`
## `ao_recv_from`

```c
void ao_recv     (ao_recv_t * x, ao_time_t timeout);
void ao_recv_from(ao_recv_t * x, ao_time_t timeout, ao_time_t beginning);
```

Receives in a blocking fashion with a timeout and an optional beginning.

## `ao_recv_forever`

```c
void ao_recv_forever(ao_recv_t * x);
```

Receives indefinitely in a blocking fashion.

## `ao_recv_try`

```c
void ao_recv_try(ao_recv_t * x);
```

Receives in a non-blocking fashion.

## `ao_recv_begin`
## `ao_recv_end`

```c
void ao_recv_begin(ao_recv_t * x);
void ao_recv_end  (ao_recv_t * x);
```

Begins or ends, respectively, a receiving.
