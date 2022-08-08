---
author: "Stefan Wagner"
date: 2022-08-08
description: "Alarm Interrupt in the ao Real-Time Operating System (RTOS)."
draft: false
permalink: /kernel/ir_alarm/
title: "Alarm Interrupt"
---

# Alarm Interrupt

The `ao_ir_alarm.h` module contains the following functions for controlling the alarm interrupt.

Enable or disable the interrupt, respectively.

```c
void ao_ir_alarm_disable();
void ao_ir_alarm_enable();
```

Request an interrupt or reply thereto, respectively.

```c
void ao_alarm_request();
void ao_alarm_reply();
```

Set the time for the next interrupt.

```c
void ao_alarm_set(ao_time_t t);
```

Additionally, the module declares the interrupt handler function, which is actually implemented by the [`ao_alarm.h`](alarm.md) module.

```c
void ao_alarm();
```
