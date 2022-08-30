---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_stack.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys/ao_stack.h/
subtitle: ""
title: "ao_stack.h"
toc: true
---

# Include

```c
#include <stddef.h>
```

# Functions

```c
void ao_stack_fill( void * beginning, size_t size);
```

```c
size_t ao_stack_get_high_water_mark( void const * beginning, size_t size);
```

