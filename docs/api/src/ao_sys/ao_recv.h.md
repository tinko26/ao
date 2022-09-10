---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_recv.h/
toc: true
---

# Notes

This module provides an abstraction for tasks to receive data from an opaque source either in a blocking or in a non-blocking fashion.

# Include

```c
#include <ao_async.h>
#include <ao_time.h>
#include <stdbool.h>
#include <stddef.h>
```

# Identifiers

## `AO_RECV`

```c
#define AO_RECV
```

# Types

## `ao_recv_t`

```c
typedef struct ao_recv_t ao_recv_t;
```

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

This type represents the receiving of data. It consists of the following members.

| `async` | The asynchronous event. |
| `begin` | The function beginning the receiving. |
| `count` | The number of received bytes. |
| `count_max` | The maximum number of bytes to receive. |
| `count_min` | The minimum number of bytes to receive. |
| `end` | The function ending the receiving. |
| `parameter` | An additional parameter. |
| `ptr` | The location to store the received data. |
| `result` | Indicates whether at least `count_min` bytes and at most `count_max` bytes have been received. |

## `ao_recv_proc_t`

```c
typedef void (* ao_recv_proc_t)
(
    ao_recv_t * x
);
```

This type represents a function beginning or ending a receiving.

# Functions

## `ao_recv`
## `ao_recv_from`

```c
void ao_recv(     ao_recv_t * x, ao_time_t timeout);
void ao_recv_from(ao_recv_t * x, ao_time_t timeout, ao_time_t beginning);
```

Receives data in a blocking fashion until the specified timeout has expired. An additional parameter marks the beginning of the timeout period, which is assumed to be in the past.

## `ao_recv_forever`

```c
void ao_recv_forever(ao_recv_t * x);
```

Receives data in a blocking fashion with an infinite timeout.

## `ao_recv_try`

```c
void ao_recv_try(ao_recv_t * x);
```

Receives data in a non-blocking fashion.

## `ao_recv_begin`
## `ao_recv_end`

```c
void ao_recv_begin(ao_recv_t * x);
void ao_recv_end(  ao_recv_t * x);
```

Begins or ends the receiving of data, respectively.
