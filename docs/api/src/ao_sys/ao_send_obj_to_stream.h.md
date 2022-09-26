---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
permalink: /api/src/ao_sys/ao_send_obj_to_stream.h/
toc: true
---

# Include

| [`ao_send_obj.h`](ao_send_obj.h.md) |
| [`ao_stream4obj.h`](ao_stream4obj.h.md) |

# Identifier

```c
#define AO_SEND_OBJ_TO_STREAM
```

# Functions

## `ao_send_obj_to_stream`

```c
void ao_send_obj_to_stream(ao_send_obj_t * send, ao_spush_obj_t * push);
```

Sets up a sending of an object to push an object to a stream.

## `ao_send_obj_to_stream_override`

```c
void ao_send_obj_to_stream_override(ao_send_obj_t * send, ao_spush_obj_t * push);
```

Sets up a sending of an object to push an object to a stream, overriding old data if the stream is full.
