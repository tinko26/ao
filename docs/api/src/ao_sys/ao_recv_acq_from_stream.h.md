---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
permalink: /api/src/ao_sys/ao_recv_acq_from_stream.h/
toc: true
---

# Include

| [`ao_recv_acq.h`](ao_recv_acq.h.md) |
| [`ao_stream4acq.h`](ao_stream4acq.h.md) |

# Functions

## `ao_recv_acq_from_stream`

```c
void ao_recv_acq_from_stream
(
    ao_recv_acq_t * r, 
    ao_spop_acq_t * p
);
```

Sets up a receiving of an acquired memory block to pop an acquired memory block from a stream.
