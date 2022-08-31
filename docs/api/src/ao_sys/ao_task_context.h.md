---
api: true
author: "Stefan Wagner"
date: 2022-08-31
description: "The /src/ao_sys/ao_task_context.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_task_context.h/
subtitle: "Task context"
title: "ao_task_context.h"
toc: true
---

# Typedefs

```c
typedef struct ao_task_t         ao_task_t;
```

```c
typedef struct ao_task_context_t ao_task_context_t;
```

# Types

## `ao_task_context_t`

```c
struct ao_task_context_t { };
```

# Functions

```c
void ao_task_start_context(ao_task_t * t);
```

```c
void ao_task_stop_context(ao_task_t * t);
```
