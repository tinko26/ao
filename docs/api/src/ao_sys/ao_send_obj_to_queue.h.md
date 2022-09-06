---
api: true
author: "Stefan Wagner"
date: 2022-08-31
description: "The /src/ao_sys/ao_send_obj_to_queue.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_send_obj_to_queue.h/
seealso:
- /api/src/ao_sys/ao_queue4obj.h/
- /api/src/ao_sys/ao_send_obj.h/
subtitle: "Sending objects to queues"
title: "ao_send_obj_to_queue.h"
toc: true
---

# Include

```c
#include <ao_queue4obj.h>
#include <ao_send_obj.h>
```

# Functions

```c
void ao_send_obj_to_queue(ao_send_obj_t * x, ao_qinsert_obj_t * y);
```
