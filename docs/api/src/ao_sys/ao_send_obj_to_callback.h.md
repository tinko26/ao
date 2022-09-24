---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
permalink: /api/src/ao_sys/ao_send_obj_to_callback.h/
toc: true
---

# Include

| [`ao_send_obj.h`](ao_send_obj.h.md) |

# Identifier

```c
#define AO_SEND_OBJ_TO_CALLBACK
```

# Functions

## `ao_send_obj_to_callback`

```c
void ao_send_obj_to_callback(ao_send_obj_t * x, ao_send_obj_proc_t y);
```

Sets up a sending of an object to execute a callback.
