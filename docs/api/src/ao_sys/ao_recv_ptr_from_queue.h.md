---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
permalink: /api/src/ao_sys/ao_recv_ptr_from_queue.h/
toc: true
---

# Include

[`ao_queue4ptr.h`](ao_queue4ptr.h.md) <br/>
[`ao_recv_ptr.h`](ao_recv_ptr.h.md)

# Identifier

```c
#define AO_RECV_PTR_FROM_QUEUE
```

# Functions

## `ao_recv_ptr_from_queue`

```c
void ao_recv_ptr_from_queue(ao_recv_ptr_t * x, ao_qpop_ptr_t * y);
```

Sets up a receiving of a pointer to pop a pointer from a queue.
