---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
permalink: /api/src/ao_sys/ao_recv_ptr_from_stream.h/
seealso:
- /api/src/ao_sys/ao_recv_ptr.h/
- /api/src/ao_sys/ao_stream4ptr.h/
toc: true
---

# Include

```c
#include <ao_recv_ptr.h>
#include <ao_stream4ptr.h>
```

# Identifier

```c
#define AO_RECV_PTR_FROM_STREAM
```

# Functions

## `ao_recv_ptr_from_stream`

```c
void ao_recv_ptr_from_stream(ao_recv_ptr_t * x, ao_spop_ptr_t * y);
```

Sets up a receiving of a pointer to pop a pointer from a stream.
