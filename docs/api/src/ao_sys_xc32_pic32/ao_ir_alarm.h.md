---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_ir_alarm.h/
toc: true
---

# Notes

This module declares functions for controlling the alarm interrupt as well as a callback function for the interrupt handler.

# Include

```c
#include <ao_ir_ct.h>
#include <xc.h>
```

# Functions

## `ao_alarm`

```c
void ao_alarm();
```

The callback for the interrupt handler. Actually, this function is implemented by the [`ao_alarm.h`](../ao_sys/ao_alarm.h.md) module.

## `ao_alarm_enable`
## `ao_alarm_disable`

```c
#define ao_alarm_enable()
#define ao_alarm_disable()
```

Enables or disables the interrupt.

## `ao_alarm_request`
## `ao_alarm_reply`

```c
#define ao_alarm_request()
#define ao_alarm_reply()
```

Requests the interrupt or replies thereto.

## `ao_alarm_set`

```c
#define ao_alarm_set(t)
```

Sets the time for the next interrupt.
