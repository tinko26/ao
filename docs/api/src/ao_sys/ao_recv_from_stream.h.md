---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
permalink: /api/src/ao_sys/ao_recv_from_stream.h/
toc: true
---

# Include

```c
#include <ao_recv.h>
#include <ao_stream.h>
```

# Identifier

```c
#define AO_RECV_FROM_STREAM
```

# Functions

## `ao_recv_from_stream`

```c
void ao_recv_from_stream(ao_recv_t * x, ao_spop_t * y);
```

Sets up a receiving to pop from a stream.
