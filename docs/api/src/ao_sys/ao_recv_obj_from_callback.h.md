---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
permalink: /api/src/ao_sys/ao_recv_obj_from_callback.h/
toc: true
---

# Include

| [`ao_recv_obj.h`](ao_recv_obj.h.md) |

# Identifier

```c
#define AO_RECV_OBJ_FROM_CALLBACK
```

# Functions

## `ao_recv_obj_from_callback`

```c
void ao_recv_obj_from_callback(ao_recv_obj_t * x, ao_recv_obj_proc_t y);
```

Sets up a receiving of an object to execute a callback.

