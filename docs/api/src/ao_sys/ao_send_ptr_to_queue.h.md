---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
permalink: /api/src/ao_sys/ao_send_ptr_to_queue.h/
toc: true
---

# Include

| [`ao_queue4ptr.h`](ao_queue4ptr.h.md) |
| [`ao_send_ptr.h`](ao_send_ptr.h.md) |

# Functions

## `ao_send_ptr_to_queue`

```c
void ao_send_ptr_to_queue
(
    ao_send_ptr_t * s, 
    ao_qinsert_ptr_t * i
);
```

Sets up a sending of a pointer to insert a pointer into a queue.
