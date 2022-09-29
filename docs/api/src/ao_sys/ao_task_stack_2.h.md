---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
permalink: /api/src/ao_sys/ao_task_stack_2.h/
toc: true
---

# Include

| `stdbool.h` |
| `stddef.h` |

# Configuration

## `AO_TASK_STACK_HIGH_WATER_MARK`

```c
#define AO_TASK_STACK_HIGH_WATER_MARK (false)
```

Defines whether to measure the high water mark for each task stack.

## `AO_TASK_STACK_SIZE_DEFAULT`

```c
#define AO_TASK_STACK_SIZE_DEFAULT (1024)
```

The default task stack size, in bytes.

# Types

## `ao_task_stack_t`

```c
typedef struct ao_task_stack_t ao_task_stack_t;
```

Represents stack-related data of a task.

# Structs

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

| `beginning` | The beginning. |
| `high_water_mark` | The high water mark, in bytes. |
| `size` | The size, in bytes. |

# Functions

## `ao_task_get_stack_beginning`
## `ao_task_get_stack_beginning_locked`

```c
void * ao_task_get_stack_beginning       (ao_task_t const * t);
void * ao_task_get_stack_beginning_locked(ao_task_t const * t);
```

Gets the stack beginning of the specified task. The latter function assumes, that the kernel is locked.

## `ao_task_get_stack_high_water_mark`
## `ao_task_get_stack_high_water_mark_locked`

```c
size_t ao_task_get_stack_high_water_mark       (ao_task_t const * t);
size_t ao_task_get_stack_high_water_mark_locked(ao_task_t const * t);
```

Gets the stack high water mark of the specified task. The latter function assumes, that the kernel is locked.

## `ao_task_get_stack_size`
## `ao_task_get_stack_size_locked`

```c
size_t ao_task_get_stack_size       (ao_task_t const * t);
size_t ao_task_get_stack_size_locked(ao_task_t const * t);
```

Gets the stack size of the specified task. The latter function assumes, that the kernel is locked.

## `ao_task_set_stack`

```c
void ao_task_set_stack_size(ao_task_t * t, size_t x);
```

Sets the stack of the specified task.

## `ao_task_stack_high_water_mark`

```c
void ao_task_stack_high_water_mark(ao_task_t * t);
```

Measures the stack high water mark of the specified task.
