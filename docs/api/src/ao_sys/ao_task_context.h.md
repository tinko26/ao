---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
permalink: /api/src/ao_sys/ao_task_context.h/
toc: true
---

# Notes

This module defines the context of a task. This module is abstract.

# Types

## `ao_task_context_t`

```c
typedef struct ao_task_context_t ao_task_context_t;
```

```c
struct ao_task_context_t { };
```

This type represents context-related data of a task.

# Functions

## `ao_task_start_context`

```c
void ao_task_start_context(ao_task_t * t);
```

Starts a task. This function is called by the kernel when a task is being started in order to prepare its context.

## `ao_task_stop_context`

```c
void ao_task_stop_context(ao_task_t * t);
```

Stops a task. This function is called by the kernel when a task is being stopped in order to clean up its context.
