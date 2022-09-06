---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_stack.h/
toc: true
---

# Include

```c
#include <stddef.h>
```

# Constants

The stack pointer alignment, in bytes.

```c
#define AO_STACK_ALIGN (8)
```

The stack fill pattern.

```c
#define AO_STACK_FILL  (0xDEADBEEF)
```

# Functions

```c
void ao_stack_fill(void * beginning, size_t size);
```

```c
size_t ao_stack_get_high_water_mark(void const * beginning, size_t size);
```
