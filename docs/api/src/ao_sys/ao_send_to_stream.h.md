---
author: "Stefan Wagner"
date: 2022-09-25
draft: true
permalink: /api/src/ao_sys/ao_send_to_stream.h/
toc: true
---

# Include

| [`ao_send.h`](ao_send.h.md) |
| [`ao_stream.h`](ao_stream.h.md) |

# Identifier

```c
#define AO_SEND_TO_STREAM
```

# Functions

## `ao_send_to_stream`

```c
void ao_send_to_stream(ao_send_t * x, ao_spush_t * y);
```

Sets up a sending to push to a stream.

## `ao_send_to_stream_override`

```c
void ao_send_to_stream_override(ao_send_t * x, ao_spush_t * y);
```

Sets up a sending to push to a stream, overriding old data if the stream is full.
