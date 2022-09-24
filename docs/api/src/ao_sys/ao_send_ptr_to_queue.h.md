---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
permalink: /api/src/ao_sys/ao_send_ptr_to_queue.h/
toc: true
---

# Include

[`ao_queue4ptr.h`](ao_queue4ptr.h.md) <br/>
[`ao_send_ptr.h`](ao_send_ptr.h.md)

# Identifier

```c
#define AO_SEND_PTR_TO_QUEUE
```

# Functions

## `ao_send_acq_to_queue`

```c
void ao_send_acq_to_queue(ao_send_ptr_t * x, ao_qinsert_ptr_t * y);
```

Sets up a sending of a pointer to insert a pointer to an acquired memory block into a queue.

## `ao_send_ptr_to_queue`

```c
void ao_send_ptr_to_queue(ao_send_ptr_t * x, ao_qinsert_ptr_t * y);
```

Sets up a sending of a pointer to insert a pointer into a queue.
