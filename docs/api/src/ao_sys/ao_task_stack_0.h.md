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

# Typedefs

```c
typedef struct ao_task_t       ao_task_t;
typedef struct ao_task_stack_t ao_task_stack_t;
```

# Types

## `ao_task_stack_t`

```c
struct ao_task_stack_t { };
```

# Functions

## `ao_task_get_stack_beginning`
## `ao_task_get_stack_beginning_locked`

Gets the stack beginning of the specified task. The latter function assumes, that the kernel is locked.

```c
void * ao_task_get_stack_beginning(       ao_task_t const * t);
void * ao_task_get_stack_beginning_locked(ao_task_t const * t);
```

## `ao_task_get_stack_size`
## `ao_task_get_stack_size_locked`

Gets the stack size of the specified task. The latter function assumes, that the kernel is locked.

```c
size_t ao_task_get_stack_size(       ao_task_t const * t);
size_t ao_task_get_stack_size_locked(ao_task_t const * t);
```
