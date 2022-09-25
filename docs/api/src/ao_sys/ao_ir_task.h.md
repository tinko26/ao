---
author: "Stefan Wagner"
date: 2022-09-25
draft: true
permalink: /api/src/ao_sys/ao_ir_task.h/
toc: true
---

# Notes

This module declares functions for controlling the task interrupts as well as a callback function for the interrupt handlers. This module is abstract, that is, an implementation must be provided by a port package in order to support multitasking.

## Porting

The port must implement the necessary interrupt handlers, which in turn must execute the callback function. On start-up, the task interrupts must be disabled.

# Include

| [`ao_core.h`](ao_core.h.md) |
| `stdbool.h` |
uint32_t 
# Identifier

```c
#define AO_IR_TASK
```

# Functions

## `ao_ir_task`

```c
void ao_ir_task();
```

The callback for the interrupt handlers. Actually, this function is implemented by the [`ao_task_sched.h`](ao_task_sched.h.md) module.

## `ao_ir_task_enable`
## `ao_ir_task_disable`

```c
void ao_ir_task_enable (ao_core_t c);
void ao_ir_task_disable(ao_core_t c);
```

Enables or disables the interrupt on the specified processor core.

## `ao_ir_task_request`
## `ao_ir_task_reply`

```c
void ao_ir_task_request(ao_core_t c);
void ao_ir_task_reply  (ao_core_t c);
```

Requests the interrupt or replies thereto on the specified processor core.

## `ao_ir_task_is_pending`

```c
bool ao_ir_task_is_pending(ao_core_t c);
```

Determines whether the interrupt is pending on the specified processor core.
