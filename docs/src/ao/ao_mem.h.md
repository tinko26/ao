---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao/ao_mem.h file of the ao real-time operating system."
draft: true
permalink: /src/ao/ao_mem.h/
subtitle: ""
title: "ao_mem.h"
toc: true
---

# Include

```c
#include <stddef.h>
#include <stdint.h>
```

# Functions

```c
void * ao_memcpy(void * d, void const * s, size_t n);
```

```c
void * ao_memmove(void * d, void const * s, size_t n);
```

```c
void * ao_memset(void * p, uint8_t v, size_t n);
```

