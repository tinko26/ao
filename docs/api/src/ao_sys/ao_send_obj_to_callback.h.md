---
api: true
author: "Stefan Wagner"
date: 2022-08-31
description: "The /src/ao_sys/ao_send_obj_to_callback.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_send_obj_to_callback.h/
seealso:
- /api/src/ao_sys/ao_send_obj.h/
subtitle: "Sending objects to callbacks"
title: "ao_send_obj_to_callback.h"
toc: true
---

# Include

```c
#include <ao_send_obj.h>
```

# Functions

```c
void ao_send_obj_to_callback(ao_send_obj_t * x, ao_send_obj_proc_t y);
```
