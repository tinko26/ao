---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
permalink: /api/src/ao_sys/ao_recv_from_callback.h/
toc: true
---

# Include

| [`ao_recv.h`](ao_recv.h.md) |

# Functions

## `ao_recv_from_callback`

```c
void ao_recv_from_callback
(
    ao_recv_t * r, 
    ao_recv_proc_t callback
);
```

Sets up a receiving to execute a callback.
