---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_task_stack_0.h/
toc: true
---

# Include

```c
#include <stddef.h>
```

# Identifiers

## `AO_TASK_STACK_0`

```c
#define AO_TASK_STACK_0
```

# Types

## `ao_task_stack_t`

```c
typedef struct ao_task_stack_t ao_task_stack_t;
```

```c
struct ao_task_stack_t { };
```

# Functions

## `ao_task_get_stack_beginning`
## `ao_task_get_stack_beginning_locked`

```c
void * ao_task_get_stack_beginning(       ao_task_t const * t);
void * ao_task_get_stack_beginning_locked(ao_task_t const * t);
```

Gets the stack beginning of the specified task. The latter function assumes, that the kernel is locked.

## `ao_task_get_stack_size`
## `ao_task_get_stack_size_locked`

```c
size_t ao_task_get_stack_size(       ao_task_t const * t);
size_t ao_task_get_stack_size_locked(ao_task_t const * t);
```

Gets the stack size of the specified task. The latter function assumes, that the kernel is locked.
