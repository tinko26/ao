---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
permalink: /api/src/ao_sys/ao_send_acq_to_queue.h/
toc: true
---

# Include

| [`ao_queue4acq.h`](ao_queue4acq.h.md) |
| [`ao_send_acq.h`](ao_send_acq.h.md) |

# Identifier

```c
#define AO_SEND_ACQ_TO_QUEUE
```

# Functions

## `ao_send_acq_to_queue`

```c
void ao_send_acq_to_queue(ao_send_acq_t * send, ao_qinsert_acq_t * insert);
```

Sets up a sending of an acquired memory block to insert an acquired memory block into a queue.
