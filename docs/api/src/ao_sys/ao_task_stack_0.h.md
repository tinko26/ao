---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_task_stack_0.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_task_stack_0.h/
subtitle: ""
title: "ao_task_stack_0.h"
toc: true
---

# Include

```c
#include <stddef.h>
```

# Typedefs

```c
typedef struct ao_task_t ao_task_t;
```

```c
typedef struct ao_task_stack_t ao_task_stack_t;
```

# Types

## `ao_task_stack_t`

```c
struct ao_task_stack_t { };
```

# Functions

```c
void * ao_task_get_stack_beginning( ao_task_t const * t);
```

```c
void * ao_task_get_stack_beginning_locked( ao_task_t const * t);
```

```c
size_t ao_task_get_stack_size( ao_task_t const * t);
```

```c
size_t ao_task_get_stack_size_locked( ao_task_t const * t);
```

