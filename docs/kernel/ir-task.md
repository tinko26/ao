---
author: "Stefan Wagner"
date: 2022-08-12
description: "Task Switch Interrupts in the ao Real-Time Operating System (RTOS)."
draft: false
permalink: /kernel/ir_task/
title: "Task Switch Interrupts"
---

# Task Switch Interrupts

The `ao_ir_task.h` module declares functions for controlling the task switch interrupts as well as callback functions for the interrupt handlers. This module is abstract, that is, an implementation must be provided by a port package in order to support [multitasking](multitasking.md).

## Functions

Enable or disable the interrupt, respectively, on the specified [core](core.md).

```c
void ao_task_switch_enable(ao_core_t c);
void ao_task_switch_disable(ao_core_t c);
```

Request an interrupt or reply thereto, respectively, on the specified core.

```c
void ao_task_switch_request(ao_core_t c);
void ao_task_switch_reply(ao_core_t c);
```

Determine whether an interrupt is pending on the specified core.

```c
bool ao_task_switch_is_pending(ao_core_t c);
```

Callback for the interrupt handlers. Actually, this function is implemented by the [`ao_task_sched.h`](task-sched.md) module.

```c
void ao_task_switch();
```

## Porting

The port must implement the necessary interrupt handlers, which in turn must execute the callback function.

On start-up, the task switch interrupts must be disabled.
