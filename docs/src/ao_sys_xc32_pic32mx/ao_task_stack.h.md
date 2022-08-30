---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mx/ao_task_stack.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32_pic32mx/ao_task_stack.h/
subtitle: ""
title: "ao_task_stack.h"
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
void ao_task_stack_null( ao_task_t const * t);
```

```c
void ao_task_stack_overflow( ao_task_t const * t);
```

```c
void ao_task_stack_threshold( ao_task_t const * t, size_t quota);
```

```c
void ao_task_stack_underflow( ao_task_t const * t);
```

# Include Next

```c
#include_next <ao_task_stack.h>
```

