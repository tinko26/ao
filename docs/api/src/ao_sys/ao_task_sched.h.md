---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_task_sched.h/
toc: true
---

# Configuration

## `AO_TASK_SCHED`

```c
#define AO_TASK_SCHED (2)
```

Selects the task scheduler implementation. The following options are available.

| [`ao_task_sched_0`](ao_task_sched_0.h.md) | Stub |
| [`ao_task_sched_1`](ao_task_sched_1.h.md) | Round-robin without priorities |
| [`ao_task_sched_2`](ao_task_sched_2.h.md) | Round-robin with priorities |
