---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
permalink: /api/src/ao_sys/ao_recv_obj_from_stream.h/
seealso:
- /api/src/ao_sys/ao_recv_obj.h/
- /api/src/ao_sys/ao_stream4obj.h/
toc: true
---

# Include

```c
#include <ao_recv_obj.h>
#include <ao_stream4obj.h>
```

# Identifier

```c
#define AO_RECV_OBJ_FROM_STREAM
```

# Functions

## `ao_recv_obj_from_stream`

```c
void ao_recv_obj_from_stream(ao_recv_obj_t * x, ao_spop_obj_t * y);
```

Sets up a receiving of an object to pop an object from a stream.
