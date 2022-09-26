---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_ir_task.h/
toc: true
---

# Notes

This module declares functions for controlling the task interrupts as well as a callback function for the interrupt handlers.

# Include

| [`ao_ir_cs.h`](ao_ir_cs.h.md) |

# Identifier

```c
#define AO_IR_TASK
```

# Functions

## `ao_ir_task`

```c
void ao_ir_task();
```

The callback for the interrupt handlers. Actually, this function is implemented by the [`ao_task_sched.h`](../ao_sys/ao_task_sched.h.md) module.

## `ao_ir_task_enable`
## `ao_ir_task_disable`

```c
#define ao_ir_task_enable( core) ao_ir_cs1_enable()
#define ao_ir_task_disable(core) ao_ir_cs1_disable()
```

Enables or disables the interrupt on the specified processor core.

## `ao_ir_task_request`
## `ao_ir_task_reply`

```c
#define ao_ir_task_request(core) ao_ir_cs1_request()
#define ao_ir_task_reply(  core) ao_ir_cs1_reply()
```

Requests the interrupt or replies thereto on the specified processor core.

## `ao_ir_task_is_pending`

```c
#define ao_ir_task_is_pending(core) ao_ir_cs1_is_pending()
```

Determines whether the interrupt is pending on the specified processor core.
