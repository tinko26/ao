---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
permalink: /api/src/ao_sys/ao_recv_ptr_from_stream.h/
toc: true
---

# Include

| [`ao_recv_ptr.h`](ao_recv_ptr.h.md) |
| [`ao_stream4ptr.h`](ao_stream4ptr.h.md) |

# Functions

## `ao_recv_ptr_from_stream`

```c
void ao_recv_ptr_from_stream
(
    ao_recv_ptr_t * r, 
    ao_spop_ptr_t * p
);
```

Sets up a receiving of a pointer to pop a pointer from a stream.
