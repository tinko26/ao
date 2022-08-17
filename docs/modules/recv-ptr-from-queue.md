---
author: "Stefan Wagner"
date: 2022-08-17
description: "The ao_recv_ptr_from_queue.h module of the ao real-time operating system."
draft: false
permalink: /modules/recv-ptr-from-queue/
title: "ao_recv_ptr_from_queue.h"
---

# ao_recv_ptr_from_queue.h

This module defines a single function that facilitates [receiving pointers](recv-ptr.md) from a [queue](queue4ptr.md).

```c
void ao_recv_ptr_from_queue(ao_recv_ptr_t * x, ao_qpop_ptr_t * y);
```
