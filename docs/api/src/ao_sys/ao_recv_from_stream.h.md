---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
permalink: /api/src/ao_sys/ao_recv_from_stream.h/
toc: true
---

# Include

| [`ao_recv.h`](ao_recv.h.md) |
| [`ao_stream.h`](ao_stream.h.md) |

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
