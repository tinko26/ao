---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_ir_task.h/
toc: true
---

# Overview

This module declares functions for controlling the task switch interrupts as well as a callback function for the interrupt handlers.

# Include

```c
#include <ao_core.h>
#include <ao_ir_cs.h>
#include <stdbool.h>
```

# Functions

Callback for the interrupt handlers. Actually, this function is implemented by the [`ao_task_sched.h`](../ao_sys/ao_task_sched.h.md) module.

```c
void ao_task_switch();
```

Enable or disable the interrupt on the specified processor core.

```c
void ao_task_switch_enable( ao_core_t c);
void ao_task_switch_disable(ao_core_t c);
```

Request the interrupt or reply thereto on the specified processor core.

```c
void ao_task_switch_request(ao_core_t c);
void ao_task_switch_reply(  ao_core_t c);
```

Determine whether the interrupt is pending on the specified processor core.

```c
bool ao_task_switch_is_pending(ao_core_t c);
```
