---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
permalink: /api/src/ao_sys/ao_recv_acq_from_queue.h/
toc: true
---

# Include

| [`ao_queue4acq.h`](ao_queue4acq.h.md) |
| [`ao_recv_acq.h`](ao_recv_acq.h.md) |

# Functions

## `ao_recv_acq_from_queue`

```c
void ao_recv_acq_from_queue
(
    ao_recv_acq_t * r, 
    ao_qpop_acq_t * p
);
```

Sets up a receiving of an acquired memory block to pop an acquired memory block from a queue.
