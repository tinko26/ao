---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_task_stack_2.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <stddef.h>
```

# Identifiers

## `AO_TASK_STACK_2`

```c
#define AO_TASK_STACK_2
```

# Configuration

## `AO_TASK_STACK_HIGH_WATER_MARK`

Measure the high water mark for each task stack.

```c
#define AO_TASK_STACK_HIGH_WATER_MARK (false)
```

## `AO_TASK_STACK_SIZE_DEFAULT`

The default task stack size, in bytes.

```c
#define AO_TASK_STACK_SIZE_DEFAULT (1024)
```

# Typedefs

```c
typedef struct ao_task_t       ao_task_t;
typedef struct ao_task_stack_t ao_task_stack_t;
```

# Types

## `ao_task_stack_t`

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

Gets the stack beginning of the specified task. The latter function assumes, that the kernel is locked.

```c
void * ao_task_get_stack_beginning(       ao_task_t const * t);
void * ao_task_get_stack_beginning_locked(ao_task_t const * t);
```

## `ao_task_get_stack_high_water_mark`
## `ao_task_get_stack_high_water_mark_locked`

Gets the stack high water mark of the specified task. The latter function assumes, that the kernel is locked.

```c
size_t ao_task_get_stack_high_water_mark(       ao_task_t const * t);
size_t ao_task_get_stack_high_water_mark_locked(ao_task_t const * t);
```

## `ao_task_get_stack_size`
## `ao_task_get_stack_size_locked`

Gets the stack size of the specified task. The latter function assumes, that the kernel is locked.

```c
size_t ao_task_get_stack_size(       ao_task_t const * t);
size_t ao_task_get_stack_size_locked(ao_task_t const * t);
```

## `ao_task_set_stack`

Sets the stack of the specified task.

```c
void ao_task_set_stack_size(ao_task_t * t, size_t x);
```

## `ao_task_stack_high_water_mark`

Measures the stack high water mark of the specified task.

```c
void ao_task_stack_high_water_mark(ao_task_t * t);
```
