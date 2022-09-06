---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_recv.h/
toc: true
---

# Overview

This module provides an abstraction for tasks to receive data from an opaque source either in a blocking or in a non-blocking fashion.

# Include

```c
#include <ao_async.h>
#include <ao_time.h>
#include <stdbool.h>
#include <stddef.h>
```

# Typedefs

```c
typedef struct ao_recv_t ao_recv_t;
```

```c
typedef void (* ao_recv_proc_t)
(
ao_recv_t * x
);
```

# Types

## `ao_recv_t`

This type represents the receiving of data.

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

It consists of the following members.

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

This type represents a function beginning or ending a receiving.

# Functions

Receive data in a blocking fashion until the specified timeout has expired. An additional parameter marks the beginning of the timeout period, which is assumed to be in the past.

```c
void ao_recv(     ao_recv_t * x, ao_time_t timeout);
void ao_recv_from(ao_recv_t * x, ao_time_t timeout, ao_time_t beginning);
```

Receive data in a blocking fashion with an infinite timeout.

```c
void ao_recv_forever(ao_recv_t * x);
```

Receive data in a non-blocking fashion.

```c
void ao_recv_try(ao_recv_t * x);
```

Begin or end the receiving of data, respectively.

```c
void ao_recv_begin(ao_recv_t * x);
void ao_recv_end(  ao_recv_t * x);
```

# Usage

Prior to calling any functions, a receiving proxy must be initialized properly.

```c
// The receiving proxy.
ao_recv_t * x;
```

```c
// The buffer to store the received data.
uint8_t data[4];
```

```c
// The number of bytes to receive.
x->count_min = 1;
x->count_max = 4;

// The pointer to the store.
x->ptr = data;
```

Data can be received in a blocking fashion.

```c
ao_time_t timeout = AO_MILLISECONDS(500);
ao_time_t beginning = ao_now();
```

```c
// Receive with timeout.
ao_recv(x, timeout);

// Receive with timeout and beginning.
ao_recv_from(x, timeout, beginning);

// Receive without timeout.
ao_recv_forever(x);
```

Also, data can be received in a non-blocking fashion, which succeeds only if data is available immediately.

```c
ao_recv_try(x);
```

Finally, the process can be stripped down into the three stages of beginning, awaiting, and ending the receiving of data.

```c
// Begin.
ao_recv_begin(x);

// Await.
ao_await(&x->async, timeout);

// End.
ao_recv_end(x);
```

Afterwards, it should be verified whether data has actually been received.

```c
if (x->result)
{
// x->count bytes have been received.
}
```
