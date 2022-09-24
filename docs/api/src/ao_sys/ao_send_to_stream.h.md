---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
permalink: /api/src/ao_sys/ao_send_to_stream.h/
toc: true
---

# Include

[`ao_send.h`](ao_send.h.md) <br/>
[`ao_stream.h`](ao_stream.h.md)

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
