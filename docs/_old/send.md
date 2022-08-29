---
author: "Stefan Wagner"
date: 2022-08-17
description: "The ao_send.h module of the ao real-time operating system."
draft: true
permalink: /modules/send/
title: "<code>ao_send.h</code>"
toc: true
---

# Overview

...

## Types

### Sending

The `ao_send_t` type represents the sending of data.

```c
struct ao_send_t
{
    ao_async_t      async;
    ao_send_proc_t  begin;
    size_t volatile count;
    size_t          count_max;
    size_t          count_min;
    ao_send_proc_t  end;
    void *          parameter;
    void *          ptr;
    bool   volatile result;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `async` | The asynchronous event. |
| `begin` | The function beginning the sending. |
| `count` | The number of sent bytes. |
| `count_max` | The maximum number of bytes to send. |
| `count_min` | The minimum number of bytes to send. |
| `end` | The function ending the sending. |
| `parameter` | An additional parameter. |
| `ptr` | Points to the data to send. |
| `result` | Indicates whether the data has been sent. |

### Sending Procedure

The `ao_send_proc_t` represents a function beginning or ending a sending.

```c
typedef void (* ao_send_proc_t) (ao_send_t * x);
```

## Functions

...
