---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_alloc_2.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_alloc_2.h/
subtitle: ""
title: "ao_alloc_2.h"
toc: true
---

# Include

```c
#include <ao_size.h>
#include <stdbool.h>
#include <stddef.h>
```

# Constants

```c
#define AO_ALLOC_ALLOCATED (false)
```

```c
#define AO_ALLOC_ALLOCATED_MAX (false)
```

```c
#define AO_ALLOC_FREE (false)
```

```c
#define AO_ALLOC_FREE_MIN (false)
```

```c
#define AO_ALLOC_SEGREGATION (3)
```

```c
#define AO_ALLOC_SEGREGATION_MAX (AO_SIZE_BITS_LOG)
```

```c
#define AO_ALLOC_SEGREGATION_MIN (0)
```

```c
#define AO_ALLOC_SIZE (8192)
```

# Variables

```c
extern size_t volatile ao_alloc_allocated;
```

```c
extern size_t volatile ao_alloc_allocated_max;
```

```c
extern size_t volatile ao_alloc_free;
```

```c
extern size_t volatile ao_alloc_free_min;
```

