---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
permalink: /api/src/ao_sys/ao_send_obj_to_queue.h/
toc: true
---

# Include

| [`ao_queue4obj.h`](ao_queue4obj.h.md) |
| [`ao_send_obj.h`](ao_send_obj.h.md) |

# Identifier

```c
#define AO_SEND_OBJ_TO_QUEUE
```

# Functions

## `ao_send_obj_to_queue`

```c
void ao_send_obj_to_queue(ao_send_obj_t * x, ao_qinsert_obj_t * y);
```

Sets up a sending of an object to insert an object into a queue.
