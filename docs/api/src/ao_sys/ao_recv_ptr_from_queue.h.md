---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
permalink: /api/src/ao_sys/ao_recv_ptr_from_queue.h/
toc: true
---

# Include

| [`ao_queue4ptr.h`](ao_queue4ptr.h.md) |
| [`ao_recv_ptr.h`](ao_recv_ptr.h.md) |

# Functions

## `ao_recv_ptr_from_queue`

```c
void ao_recv_ptr_from_queue
(
    ao_recv_ptr_t * r, 
    ao_qpop_ptr_t * p
);
```

Sets up a receiving of a pointer to pop a pointer from a queue.
