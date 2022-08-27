---
author: "Stefan Wagner"
date: 2022-08-17
description: "The ao_send_obj.h module of the ao real-time operating system."
draft: true
permalink: /modules/send-obj/
title: "<code>ao_send_obj.h</code>"
---

# Overview

...

## Types

### Sending

The `ao_send_obj_t` type represents the sending of an object.

```c
struct ao_send_obj_t
{
    ao_async_t         async;
    ao_send_obj_proc_t begin;
    ao_send_obj_proc_t end;
    void *             parameter;
    void *             ptr;
    bool volatile      result;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `async` | The asynchronous event. |
| `begin` | The function beginning the sending. |
| `end` | The function ending the sending. |
| `parameter` | An additional parameter. |
| `ptr` | A pointer to the object to send. |
| `result` | Indicates whether the object has been sent. |

### Sending Procedure

The `ao_send_obj_proc_t` represents a function beginning or ending a sending.

```c
typedef void (* ao_send_obj_proc_t) (ao_send_obj_t * x);
```

## Functions

...

