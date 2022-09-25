---
author: "Stefan Wagner"
date: 2022-09-25
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz/ao_task.h/
toc: true
---

# Notes

## Task interrupt

The implementation of the task interrupt makes the following assumptions.

The priority of the task interrupt equals 1.

Priority level 1 interrupts do not use a shadow set.

`Status.FR` == 1.

`Status.CU1` == 1.

`Status.MX` == 1.

# Include

| [`ao_task_context.h`](ao_task_context.h.md) |
| [`ao_task_stack.h`](ao_task_stack.h.md) |

# Include Next

| [`ao_task.h`](../ao_sys/ao_task.h.md) |
