---
api: true
author: "Stefan Wagner"
date: 2022-08-31
description: "The /src/ao_sys/ao_send_obj_to_stream.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_send_obj_to_stream.h/
seealso:
- title: "<code>ao_send_obj.h</code>"
  url: /api/src/ao_sys/ao_send_obj.h/
- title: "<code>ao_stream4obj.h</code>"
  url: /api/src/ao_sys/ao_stream4obj.h/
subtitle: "Sending objects to streams"
title: "ao_send_obj_to_stream.h"
toc: true
---

# Include

```c
#include <ao_send_obj.h>
#include <ao_stream4obj.h>
```

# Functions

```c
void ao_send_obj_to_stream(ao_send_obj_t * x, ao_spush_obj_t * y);
```

```c
void ao_send_obj_to_stream_override(ao_send_obj_t * x, ao_spush_obj_t * y);
```
