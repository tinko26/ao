---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
permalink: /api/src/ao_sys/ao_send_obj_to_queue.h/
seealso:
- /api/src/ao_sys/ao_queue4obj.h/
- /api/src/ao_sys/ao_send_obj.h/
toc: true
---

# Include

```c
#include <ao_queue4obj.h>
#include <ao_send_obj.h>
```

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
