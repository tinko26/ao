---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
permalink: /api/src/ao_sys/ao_send_to_callback.h/
seealso:
- /api/src/ao_sys/ao_send.h/
toc: true
---

# Include

```c
#include <ao_send.h>
```

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
