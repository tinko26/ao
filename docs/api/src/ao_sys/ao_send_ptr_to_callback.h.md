---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
permalink: /api/src/ao_sys/ao_send_ptr_to_callback.h/
toc: true
---

# Include

| [`ao_send_ptr.h`](ao_send_ptr.h.md) |

# Identifier

```c
#define AO_SEND_PTR_TO_CALLBACK
```

# Functions

## `ao_send_ptr_to_callback`

```c
void ao_send_ptr_to_callback(ao_send_ptr_t * x, ao_send_ptr_proc_t y);
```

Sets up a sending of a pointer to execute a callback.
