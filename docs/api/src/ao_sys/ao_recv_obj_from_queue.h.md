---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
permalink: /api/src/ao_sys/ao_recv_obj_from_queue.h/
toc: true
---

# Include

```c
#include <ao_queue4obj.h>
#include <ao_recv_obj.h>
```

# Identifier

```c
#define AO_RECV_OBJ_FROM_QUEUE
```

# Functions

## `ao_recv_obj_from_queue`

```c
void ao_recv_obj_from_queue(ao_recv_obj_t * x, ao_qpop_obj_t * y);
```

Sets up a receiving of an object to pop an object from a queue.

