---
author: "Stefan Wagner"
date: 2022-08-11
description: "Alarm Interrupt in the ao Real-Time Operating System (RTOS)."
draft: false
permalink: /kernel/ir_alarm/
title: "Alarm Interrupt"
---

# Alarm Interrupt

The `ao_ir_alarm.h` module declares functions for controlling the alarm interrupt as well as a callback function for the interrupt handler.

## Functions

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

Callback for the interrupt handler. Actually, this function is implemented by the [`ao_alarm.h`](alarm.md) module.

```c
void ao_alarm();
```
