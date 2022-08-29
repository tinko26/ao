---
author: "Stefan Wagner"
date: 2022-08-17
description: "The ao_send_ptr.h module of the ao real-time operating system."
draft: true
permalink: /modules/send-ptr/
title: "<code>ao_send_ptr.h</code>"
toc: true
---

# Overview

...

## Types

### Sending

The `ao_send_ptr_t` type represents the sending of a pointer.

```c
struct ao_send_ptr_t
{
    ao_async_t         async;
    ao_send_ptr_proc_t begin;
    ao_send_ptr_proc_t end;
    void *             parameter;
    void *             ptr;
    bool   volatile    result;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `async` | The asynchronous event. |
| `begin` | The function beginning the sending. |
| `end` | The function ending the sending. |
| `parameter` | An additional parameter. |
| `ptr` | The pointer to send. |
| `result` | Indicates whether the pointer has been sent. |

### Sending Procedure

The `ao_send_ptr_proc_t` represents a function beginning or ending a sending.

```c
typedef void (* ao_send_ptr_proc_t) (ao_send_ptr_t * x);
```

## Functions

...
