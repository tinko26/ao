---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_task_stack.h/
toc: true
---

# Identifiers

## `AO_TASK_STACK`

```c
#define AO_TASK_STACK
```

# Configuration

## `AO_TASK_STACK`

Select the task stack implementation.

```c
#define AO_TASK_STACK (2)
```

The following options are available.

| [`ao_task_stack_0`](ao_task_stack_0.h.md) | Stub |
| [`ao_task_stack_1`](ao_task_stack_1.h.md) | Injection |
| [`ao_task_stack_2`](ao_task_stack_2.h.md) | Allocation |
