---
author: "Stefan Wagner"
date: 2022-08-16
description: "The ao_recv_ptr.h module of the ao real-time operating system."
draft: true
permalink: /modules/recv-ptr/
title: "ao_recv_ptr.h"
---

# ao_recv_ptr.h

...

## Types

### Receiving

The `ao_recv_ptr_t` type represents the receiving of a pointer.

```c
struct ao_recv_ptr_t
{
    ao_async_t         async;
    ao_recv_ptr_proc_t begin;
    ao_recv_ptr_proc_t end;
    void *             parameter;
    void * volatile    ptr;
    bool   volatile    result;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `async` | The asynchronous event. |
| `begin` | The function beginning the receiving. |
| `end` | The function ending the receiving. |
| `parameter` | An additional parameter. |
| `ptr` | The received pointer. |
| `result` | Indicates whether a pointer has been received. |

### Receiving Procedure

The `ao_recv_ptr_proc_t` represents a function beginning or ending a receiving.

```c
typedef void (* ao_recv_ptr_proc_t) (ao_recv_ptr_t * x);
```

## Functions

...
