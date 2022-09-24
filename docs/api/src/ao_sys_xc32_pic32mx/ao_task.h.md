---
author: "Stefan Wagner"
date: 2022-08-29
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx/ao_task.h/
toc: true
---

# Notes

## Task switch interrupt

The implementation of the task switch interrupt makes the following assumptions.

The priority of the task switch interrupt equals 1.

Priority level 1 interrupts do not use a shadow set.

# Include

| [`ao_task_context.h`](ao_task_context.h.md) |
| [`ao_task_stack.h`](ao_task_stack.h.md) |

# Include Next

| [`ao_task.h`](../ao_sys/ao_task.h.md) |
