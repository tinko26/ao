---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
permalink: /api/src/ao_sys/ao_send_to_callback.h/
toc: true
---

# Include

| [`ao_send.h`](ao_send.h.md) |

# Functions

## `ao_send_to_callback`

```c
void ao_send_to_callback
(
    ao_send_t * s, 
    ao_send_proc_t callback
);
```

Sets up a sending to execute a callback.
