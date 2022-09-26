---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
permalink: /api/src/ao_sys/ao_recv_acq_from_callback.h/
toc: true
---

# Include

| [`ao_recv_acq.h`](ao_recv_acq.h.md) |

# Identifier

```c
#define AO_RECV_ACQ_FROM_CALLBACK
```

# Functions

## `ao_recv_acq_from_callback`

```c
void ao_recv_acq_from_callback(ao_recv_acq_t * recv, ao_recv_acq_proc_t callback);
```

Sets up a receiving of an acquired memory block to execute a callback.
