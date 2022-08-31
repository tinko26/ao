---
api: true
author: "Stefan Wagner"
date: 2022-08-31
description: "The /src/ao_sys/ao_recv_from_stream.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_recv_from_stream.h/
seealso:
- title: "<code>ao_recv.h</code>"
  url: /api/src/ao_sys/ao_recv.h/
- title: "<code>ao_stream.h</code>"
  url: /api/src/ao_sys/ao_stream.h/
subtitle: "Receiving from streams"
title: "ao_recv_from_stream.h"
toc: true
---

# Include

```c
#include <ao_recv.h>
#include <ao_stream.h>
```

# Functions

```c
void ao_recv_from_stream(ao_recv_t * x, ao_spop_t * y);
```
