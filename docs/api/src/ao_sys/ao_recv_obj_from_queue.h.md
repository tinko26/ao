---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_recv_obj_from_queue.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_recv_obj_from_queue.h/
seealso:
- title: "<code>ao_queue4obj.h</code>"
  url: /api/src/ao_sys/ao_queue4obj.h/
- title: "<code>ao_recv_obj.h</code>"
  url: /api/src/ao_sys/ao_recv_obj.h/
subtitle: "Receiving objects from queues"
title: "ao_recv_obj_from_queue.h"
toc: true
---

# Include

```c
#include <ao_queue4obj.h>
#include <ao_recv_obj.h>
```

# Functions

```c
void ao_recv_obj_from_queue(ao_recv_obj_t * x, ao_qpop_obj_t * y);
```

