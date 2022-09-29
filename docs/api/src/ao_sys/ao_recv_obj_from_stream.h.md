---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
permalink: /api/src/ao_sys/ao_recv_obj_from_stream.h/
toc: true
---

# Include

| [`ao_recv_obj.h`](ao_recv_obj.h.md) |
| [`ao_stream4obj.h`](ao_stream4obj.h.md) |

# Functions

## `ao_recv_obj_from_stream`

```c
void ao_recv_obj_from_stream
(
    ao_recv_obj_t * r, 
    ao_spop_obj_t * p
);
```

Sets up a receiving of an object to pop an object from a stream.
