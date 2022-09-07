---
author: "Stefan Wagner"
date: 2022-08-29
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz/ao_task_stack.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <stddef.h>
```

# Typedefs

```c
typedef struct ao_task_t ao_task_t;
```

# Constants

```c
#define AO_TASK_STACK_CHECK (false)
```

```c
#define AO_TASK_STACK_THRESHOLD (70)
```

# Functions

```c
void ao_task_stack_null(ao_task_t const * t);
```

```c
void ao_task_stack_overflow(ao_task_t const * t);
```

```c
void ao_task_stack_threshold(ao_task_t const * t, size_t quota);
```

```c
void ao_task_stack_underflow(ao_task_t const * t);
```

# Include Next

```c
#include_next <ao_task_stack.h>
```
