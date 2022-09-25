---
author: "Stefan Wagner"
date: 2022-09-25
draft: true
permalink: /api/src/ao_sys/ao_recv_acq_from_stream.h/
toc: true
---

# Include

| [`ao_recv_acq.h`](ao_recv_acq.h.md) |
| [`ao_stream4acq.h`](ao_stream4acq.h.md) |

# Identifier

```c
#define AO_RECV_ACQ_FROM_STREAM
```

# Functions

## `ao_recv_acq_from_stream`

```c
void ao_recv_acq_from_stream(ao_recv_acq_t * x, ao_spop_acq_t * y);
```

Sets up a receiving of an acquired memory block to pop an acquired memory block from a stream.