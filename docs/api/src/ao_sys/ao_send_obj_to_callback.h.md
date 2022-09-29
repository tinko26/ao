---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
permalink: /api/src/ao_sys/ao_send_obj_to_callback.h/
toc: true
---

# Include

| [`ao_send_obj.h`](ao_send_obj.h.md) |

# Functions

## `ao_send_obj_to_callback`

```c
void ao_send_obj_to_callback
(
    ao_send_obj_t * s, 
    ao_send_obj_proc_t callback
);
```

Sets up a sending of an object to execute a callback.
