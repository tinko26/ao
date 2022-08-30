---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_send_ptr_to_stream.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys/ao_send_ptr_to_stream.h/
subtitle: ""
title: "ao_send_ptr_to_stream.h"
toc: true
---

# Include

```c
#include <ao_send_ptr.h>
#include <ao_stream4ptr.h>
```

# Functions

```c
void ao_send_acq_to_stream( ao_send_ptr_t * x, ao_spush_ptr_t * y);
```

```c
void ao_send_acq_to_stream_override( ao_send_ptr_t * x, ao_spush_ptr_t * y);
```

```c
void ao_send_ptr_to_stream( ao_send_ptr_t * x, ao_spush_ptr_t * y);
```

```c
void ao_send_ptr_to_stream_override( ao_send_ptr_t * x, ao_spush_ptr_t * y);
```

