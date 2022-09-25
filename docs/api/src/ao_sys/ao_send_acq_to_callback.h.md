---
author: "Stefan Wagner"
date: 2022-09-25
draft: true
permalink: /api/src/ao_sys/ao_send_acq_to_callback.h/
toc: true
---

# Include

| [`ao_send_acq.h`](ao_send_acq.h.md) |

# Identifier

```c
#define AO_SEND_ACQ_TO_CALLBACK
```

# Functions

## `ao_send_acq_to_callback`

```c
void ao_send_acq_to_callback(ao_send_acq_t * x, ao_send_acq_proc_t y);
```

Sets up a sending of an acquired memory block to execute a callback.