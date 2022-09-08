---
author: "Stefan Wagner"
date: 2022-08-29
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx/ao_task_stack.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <stddef.h>
```

# Configuration

## `AO_TASK_STACK_CHECK`

```c
#define AO_TASK_STACK_CHECK (false)
```

## `AO_TASK_STACK_THRESHOLD`

```c
#define AO_TASK_STACK_THRESHOLD (70)
```

# Typedefs

```c
typedef struct ao_task_t ao_task_t;
```

# Functions

## `ao_task_stack_null`

```c
void ao_task_stack_null(ao_task_t const * t);
```

## `ao_task_stack_overflow`

```c
void ao_task_stack_overflow(ao_task_t const * t);
```

## `ao_task_stack_threshold`

```c
void ao_task_stack_threshold(ao_task_t const * t, size_t quota);
```

## `ao_task_stack_underflow`

```c
void ao_task_stack_underflow(ao_task_t const * t);
```

# Include Next

```c
#include_next <ao_task_stack.h>
```
