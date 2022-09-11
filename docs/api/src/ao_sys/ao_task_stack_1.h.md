---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_task_stack_1.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <stddef.h>
```

# Identifier

```c
#define AO_TASK_STACK_1
```

# Configuration

## `AO_TASK_STACK_HIGH_WATER_MARK`

```c
#define AO_TASK_STACK_HIGH_WATER_MARK (false)
```

Defines whether to measure the high water mark for each task stack.

# Types

## `ao_task_stack_t`

```c
typedef struct ao_task_stack_t ao_task_stack_t;
```

```c
struct ao_task_stack_t
{
    void * beginning;
    size_t size;

#if AO_TASK_STACK_HIGH_WATER_MARK

    size_t high_water_mark;

#endif

};
```

It consists of the following members.

| `beginning` | |
| `high_water_mark` | |
| `size` | |

# Functions

## `ao_task_get_stack_beginning`
## `ao_task_get_stack_beginning_locked`

```c
void * ao_task_get_stack_beginning(       ao_task_t const * t);
void * ao_task_get_stack_beginning_locked(ao_task_t const * t);
```

Gets the stack beginning of the specified task. The latter function assumes, that the kernel is locked.

## `ao_task_get_stack_high_water_mark`
## `ao_task_get_stack_high_water_mark_locked`

```c
size_t ao_task_get_stack_high_water_mark(       ao_task_t const * t);
size_t ao_task_get_stack_high_water_mark_locked(ao_task_t const * t);
```

Gets the stack high water mark of the specified task. The latter function assumes, that the kernel is locked.

## `ao_task_get_stack_size`
## `ao_task_get_stack_size_locked`

```c
size_t ao_task_get_stack_size(       ao_task_t const * t);
size_t ao_task_get_stack_size_locked(ao_task_t const * t);
```

Gets the stack size of the specified task. The latter function assumes, that the kernel is locked.

## `ao_task_set_stack`

```c
void ao_task_set_stack(ao_task_t * t, void * beginning, size_t size);
```

Sets the stack of the specified task.

## `ao_task_stack_high_water_mark`

```c
void ao_task_stack_high_water_mark(ao_task_t * t);
```

Measures the stack high water mark of the specified task.
