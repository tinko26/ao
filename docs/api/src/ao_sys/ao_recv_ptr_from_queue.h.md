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

# Identifier

```c
#define AO_RECV_PTR_FROM_QUEUE
```

# Functions

## `ao_recv_ptr_from_queue`

```c
void ao_recv_ptr_from_queue(ao_recv_ptr_t * recv, ao_qpop_ptr_t * pop);
```

Sets up a receiving of a pointer to pop a pointer from a queue.
