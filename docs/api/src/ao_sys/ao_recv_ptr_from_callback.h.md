---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
permalink: /api/src/ao_sys/ao_recv_ptr_from_callback.h/
toc: true
---

# Include

```c
#include <ao_recv_ptr.h>
```

# Identifier

```c
#define AO_RECV_PTR_FROM_CALLBACK
```

# Functions

## `ao_recv_ptr_from_callback`

```c
void ao_recv_ptr_from_callback(ao_recv_ptr_t * x, ao_recv_ptr_proc_t y);
```

Sets up a receiving of a pointer to execute a callback.
