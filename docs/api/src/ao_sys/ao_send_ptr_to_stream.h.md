---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
permalink: /api/src/ao_sys/ao_send_ptr_to_stream.h/
toc: true
---

# Include

| [`ao_send_ptr.h`](ao_send_ptr.h.md) |
| [`ao_stream4ptr.h`](ao_stream4ptr.h.md) |

# Functions

## `ao_send_ptr_to_stream`

```c
void ao_send_ptr_to_stream(ao_send_ptr_t * send, ao_spush_ptr_t * push);
```

Sets up a sending of a pointer to push a pointer to a stream.

## `ao_send_ptr_to_stream_override`

```c
void ao_send_ptr_to_stream_override(ao_send_ptr_t * send, ao_spush_ptr_t * push);
```

Sets up a sending of a pointer to push a pointer to a stream, overriding old data if the stream is full.
