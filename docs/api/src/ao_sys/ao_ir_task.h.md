---
api: true
author: "Stefan Wagner"
date: 2022-08-31
description: "The /src/ao_sys/ao_ir_task.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_ir_task.h/
subtitle: "Task switch interrupts"
title: "ao_ir_task.h"
toc: true
---

# Overview

This module declares functions for controlling the task switch interrupts as well as a callback function for the interrupt handlers. This module is abstract, that is, an implementation must be provided by a port package in order to support multitasking.

# Include

```c
#include <ao_core.h>
#include <stdbool.h>
```

# Functions

Callback for the interrupt handlers. Actually, this function is implemented by the [`ao_task_sched.h`](ao_task_sched.h.md) module.

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

# Porting

The port must implement the necessary interrupt handlers, which in turn must execute the callback function.

On start-up, the task switch interrupts must be disabled.
