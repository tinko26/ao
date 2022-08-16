---
author: "Stefan Wagner"
date: 2022-08-16
description: "The ao_recv.h module of the ao real-time operating system."
draft: true
permalink: /modules/recv/
title: "ao_recv.h"
---

# ao_recv.h

...

## Types

### Receiving

The `ao_recv_t` type represents the receiving of data.

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

| Member | |
|--------|-|
| `async` | The asynchronous event. |
| `begin` | The function beginning the receiving. |
| `count` | The number of received bytes. |
| `count_max` | The maximum number of bytes to receive. |
| `count_min` | The minimum number of bytes to receive. |
| `end` | The function ending the receiving. |
| `parameter` | An additional parameter. |
| `ptr` | Points to a location to store the received data. |
| `result` | Indicates whether data has been received. |

### Receiving Procedure

The `ao_recv_proc_t` represents a function beginning or ending a receiving.

```c
typedef void (* ao_recv_proc_t) (ao_recv_t * x);
```

## Functions

...
