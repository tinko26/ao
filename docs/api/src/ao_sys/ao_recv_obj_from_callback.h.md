---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
permalink: /api/src/ao_sys/ao_recv_obj_from_callback.h/
toc: true
---

# Include

| [`ao_recv_obj.h`](ao_recv_obj.h.md) |

# Functions

## `ao_recv_obj_from_callback`

```c
void ao_recv_obj_from_callback
(
    ao_recv_obj_t * r, 
    ao_recv_obj_proc_t callback
);
```

Sets up a receiving of an object to execute a callback.

