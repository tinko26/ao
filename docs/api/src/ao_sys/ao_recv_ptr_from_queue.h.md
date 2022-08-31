---
api: true
author: "Stefan Wagner"
date: 2022-08-31
description: "The /src/ao_sys/ao_recv_ptr_from_queue.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_recv_ptr_from_queue.h/
seealso:
- title: "<code>ao_queue4ptr.h</code>"
  url: /api/src/ao_sys/ao_queue4ptr.h/
- title: "<code>ao_recv_ptr.h</code>"
  url: /api/src/ao_sys/ao_recv_ptr.h/
subtitle: "Receiving pointers from queues"
title: "ao_recv_ptr_from_queue.h"
toc: true
---

# Include

```c
#include <ao_queue4ptr.h>
#include <ao_recv_ptr.h>
```

# Functions

```c
void ao_recv_ptr_from_queue(ao_recv_ptr_t * x, ao_qpop_ptr_t * y);
```
