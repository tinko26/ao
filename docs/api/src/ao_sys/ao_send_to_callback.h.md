---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
permalink: /api/src/ao_sys/ao_send_to_callback.h/
toc: true
---

# Include

[`ao_send.h`](ao_send.h.md)

# Identifier

```c
#define AO_SEND_TO_CALLBACK
```

# Functions

## `ao_send_to_callback`

```c
void ao_send_to_callback(ao_send_t * x, ao_send_proc_t y);
```

Sets up a sending to execute a callback.
