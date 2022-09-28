---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
permalink: /api/src/ao_sys/ao_recv_ptr_from_callback.h/
toc: true
---

# Include

| [`ao_recv_ptr.h`](ao_recv_ptr.h.md) |

# Functions

## `ao_recv_ptr_from_callback`

```c
void ao_recv_ptr_from_callback(ao_recv_ptr_t * recv, ao_recv_ptr_proc_t callback);
```

Sets up a receiving of a pointer to execute a callback.
