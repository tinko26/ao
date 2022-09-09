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

Callback for the interrupt handler. Actually, this function is implemented by the [`ao_alarm.h`](../ao_sys/ao_alarm.h.md) module.

```c
void ao_alarm();
```

## `ao_alarm_enable`
## `ao_alarm_disable`

Enable or disable the interrupt.

```c
#define ao_alarm_enable()
#define ao_alarm_disable()
```

## `ao_alarm_request`
## `ao_alarm_reply`

Request the interrupt or reply thereto.

```c
#define ao_alarm_request()
#define ao_alarm_reply()
```

## `ao_alarm_set`

Set the time for the next interrupt.

```c
#define ao_alarm_set(t)
```
