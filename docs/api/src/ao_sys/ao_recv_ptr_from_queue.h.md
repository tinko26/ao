---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_recv_ptr_from_queue.h/
seealso:
- /api/src/ao_sys/ao_queue4ptr.h/
- /api/src/ao_sys/ao_recv_ptr.h/
toc: true
---

# Include

```c
#include <ao_queue4ptr.h>
#include <ao_recv_ptr.h>
```

# Identifiers

## `AO_RECV_PTR_FROM_QUEUE`

```c
#define AO_RECV_PTR_FROM_QUEUE
```

# Functions

## `ao_recv_ptr_from_queue`

```c
void ao_recv_ptr_from_queue(ao_recv_ptr_t * x, ao_qpop_ptr_t * y);
```
