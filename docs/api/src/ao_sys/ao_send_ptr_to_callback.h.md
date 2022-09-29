---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
permalink: /api/src/ao_sys/ao_send_ptr_to_callback.h/
toc: true
---

# Include

| [`ao_send_ptr.h`](ao_send_ptr.h.md) |

# Functions

## `ao_send_ptr_to_callback`

```c
void ao_send_ptr_to_callback
(
    ao_send_ptr_t * s, 
    ao_send_ptr_proc_t callback
);
```

Sets up a sending of a pointer to execute a callback.
