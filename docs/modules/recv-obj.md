---
author: "Stefan Wagner"
date: 2022-08-16
description: "The ao_recv_obj.h module of the ao real-time operating system."
draft: true
permalink: /modules/recv-obj/
title: "<code>ao_recv_obj.h</code>"
---

# Overview

...

## Types

### Receiving

The `ao_recv_obj_t` type represents the receiving of an object.

```c
struct ao_recv_obj_t
{
    ao_async_t         async;
    ao_recv_obj_proc_t begin;
    ao_recv_obj_proc_t end;
    void *             parameter;
    void *             ptr;
    bool volatile      result;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `async` | The asynchronous event. |
| `begin` | The function beginning the receiving. |
| `end` | The function ending the receiving. |
| `parameter` | An additional parameter. |
| `ptr` | A pointer to a location to store the received object. |
| `result` | Indicates whether an object has been received. |

### Receiving Procedure

The `ao_recv_obj_proc_t` represents a function beginning or ending a receiving.

```c
typedef void (* ao_recv_obj_proc_t) (ao_recv_obj_t * x);
```

## Functions

...

