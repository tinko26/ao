---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
permalink: /api/src/ao_sys/ao_send_acq_to_stream.h/
toc: true
---

# Include

| [`ao_send_acq.h`](ao_send_acq.h.md) |
| [`ao_stream4acq.h`](ao_stream4acq.h.md) |

# Functions

## `ao_send_acq_to_stream`

```c
void ao_send_acq_to_stream
(
    ao_send_acq_t * s, 
    ao_spush_acq_t * p
);
```

Sets up a sending of an acquired memory block to push an acquired memory block to a stream.

## `ao_send_acq_to_stream_override`

```c
void ao_send_acq_to_stream_override
(
    ao_send_acq_t * s, 
    ao_spush_acq_t * p
);
```

Sets up a sending of an acquired memory block to push an acquired memory block to a stream, overriding old data if the stream is full.
