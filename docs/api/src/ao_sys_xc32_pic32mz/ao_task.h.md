---
author: "Stefan Wagner"
date: 2022-08-29
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz/ao_task.h/
toc: true
---

# Notes

## Task switch interrupt

The implementation of the task switch interrupt makes the following assumptions.

The priority of the task switch interrupt equals 1.

Priority level 1 interrupts do not use a shadow set.

`Status.FR` == 1.

`Status.CU1` == 1.

`Status.MX` == 1.

# Include

```c
#include <ao_task_context.h>
#include <ao_task_stack.h>
```

# Include Next

```c
#include_next <ao_task.h>
```
