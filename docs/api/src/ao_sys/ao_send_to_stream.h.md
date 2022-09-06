---
api: true
author: "Stefan Wagner"
date: 2022-08-31
description: "The /src/ao_sys/ao_send_to_stream.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_send_to_stream.h/
seealso:
- /api/src/ao_sys/ao_send.h/
- /api/src/ao_sys/ao_stream.h/
subtitle: "Sending to streams"
title: "ao_send_to_stream.h"
toc: true
---

# Include

```c
#include <ao_send.h>
#include <ao_stream.h>
```

# Functions

```c
void ao_send_to_stream(ao_send_t * x, ao_spush_t * y);
```
