---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_ir_task.h/
toc: true
---

# Notes

This module declares functions for controlling the task switch interrupts as well as a callback function for the interrupt handlers. This module is abstract, that is, an implementation must be provided by a port package in order to support multitasking.

## Porting

The port must implement the necessary interrupt handlers, which in turn must execute the callback function. On start-up, the task switch interrupts must be disabled.

# Include

```c
#include <ao_core.h>
#include <stdbool.h>
```

# Functions

## `ao_task_switch`

```c
void ao_task_switch();
```

The callback for the interrupt handlers. Actually, this function is implemented by the [`ao_task_sched.h`](ao_task_sched.h.md) module.

## `ao_task_switch_enable`
## `ao_task_switch_disable`

```c
void ao_task_switch_enable( ao_core_t c);
void ao_task_switch_disable(ao_core_t c);
```

Enables or disables the interrupt on the specified processor core.

## `ao_task_switch_request`
## `ao_task_switch_reply`

```c
void ao_task_switch_request(ao_core_t c);
void ao_task_switch_reply(  ao_core_t c);
```

Requests the interrupt or replies thereto on the specified processor core.

## `ao_task_switch_is_pending`

```c
bool ao_task_switch_is_pending(ao_core_t c);
```

Determines whether the interrupt is pending on the specified processor core.
