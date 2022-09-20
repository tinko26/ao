---
author: "Stefan Wagner"
date: 2022-09-20
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

Defines whether to check the task stack upon each context switch.

## `AO_TASK_STACK_THRESHOLD`

```c
#define AO_TASK_STACK_THRESHOLD (70)
```

The task stack quota threshold, in per cent.

# Functions

## `ao_task_stack_null`

```c
void ao_task_stack_null(ao_task_t const * t);
```

This function is called, when a task has got no stack. It must be implemented by the application.

## `ao_task_stack_overflow`

```c
void ao_task_stack_overflow(ao_task_t const * t);
```

This function is called, when a task stack overflow has occured. It must be implemented by the application.

## `ao_task_stack_threshold`

```c
void ao_task_stack_threshold(ao_task_t const * t, size_t quota);
```

This function is called, when a task stack quota threshold has been exceeded. It must be implemented by the application.

## `ao_task_stack_underflow`

```c
void ao_task_stack_underflow(ao_task_t const * t);
```

This function is called, when a task stack underflow has occured. It must be implemented by the application.

# Include Next

```c
#include_next <ao_task_stack.h>
```
