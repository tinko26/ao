---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_send_ptr_to_queue.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys/ao_send_ptr_to_queue.h/
subtitle: ""
title: "ao_send_ptr_to_queue.h"
toc: true
---

# Include

```c
#include <ao_queue4ptr.h>
#include <ao_send_ptr.h>
```

# Functions

```c
void ao_send_acq_to_queue( ao_send_ptr_t * x, ao_qinsert_ptr_t * y);
```

```c
void ao_send_ptr_to_queue( ao_send_ptr_t * x, ao_qinsert_ptr_t * y);
```

