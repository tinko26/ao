---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_ir_alarm.h/
toc: true
---

# Overview

This module declares functions for controlling the alarm interrupt as well as a callback function for the interrupt handler.

# Include

```c
#include <ao_ir_ct.h>
#include <xc.h>
```

# Functions

Callback for the interrupt handler. Actually, this function is implemented by the [`ao_alarm.h`](../ao_sys/ao_alarm.h.md) module.

```c
void ao_alarm();
```

Enable or disable the interrupt.

```c
#define ao_alarm_enable()
#define ao_alarm_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_alarm_request()
#define ao_alarm_reply()
```

Set the time for the next interrupt.

```c
#define ao_alarm_set(t)
```
