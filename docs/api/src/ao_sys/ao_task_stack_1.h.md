---
api: true
author: "Stefan Wagner"
date: 2022-08-31
description: "The /src/ao_sys/ao_task_stack_1.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_task_stack_1.h/
subtitle: "Task stack from injection"
title: "ao_task_stack_1.h"
toc: true
---

# Include

```c
#include <stdbool.h>
#include <stddef.h>
```

# Typedefs

```c
typedef struct ao_task_t       ao_task_t;
```

```c
typedef struct ao_task_stack_t ao_task_stack_t;
```

# Configuration

```c
#define AO_TASK_STACK_HIGH_WATER_MARK (false)
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

```c
void * ao_task_get_stack_beginning(ao_task_t const * t);
```

```c
void * ao_task_get_stack_beginning_locked(ao_task_t const * t);
```

```c
size_t ao_task_get_stack_high_water_mark(ao_task_t const * t);
```

```c
size_t ao_task_get_stack_high_water_mark_locked(ao_task_t const * t);
```

```c
size_t ao_task_get_stack_size(ao_task_t const * t);
```

```c
size_t ao_task_get_stack_size_locked(ao_task_t const * t);
```

```c
void ao_task_set_stack(ao_task_t * t, void * beginning, size_t size);
```

```c
void ao_task_stack_high_water_mark(ao_task_t * t);
```
