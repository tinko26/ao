---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
permalink: /api/src/ao_sys/ao_recv_obj_from_queue.h/
toc: true
---

# Include

| [`ao_queue4obj.h`](ao_queue4obj.h.md) |
| [`ao_recv_obj.h`](ao_recv_obj.h.md) |

# Functions

## `ao_recv_obj_from_queue`

```c
void ao_recv_obj_from_queue
(
    ao_recv_obj_t * r, 
    ao_qpop_obj_t * p
);
```

Sets up a receiving of an object to pop an object from a queue.

