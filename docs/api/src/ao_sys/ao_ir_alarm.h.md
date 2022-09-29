---
author: "Stefan Wagner"
date: 2022-09-27
draft: true
permalink: /api/src/ao_sys/ao_ir_alarm.h/
toc: true
---

# Notes

This module declares functions for controlling the alarm interrupt as well as a callback function for the interrupt handler. This module is abstract, that is, an implementation must be provided by a port in order to support alarms.

## Porting

The port must implement an interrupt handler, which in turn must execute the callback function. On start-up, the alarm interrupt must be disabled.

# Include

| [`ao_time.h`](ao_time.h.md) |

# Functions

## `ao_ir_alarm`

```c
void ao_ir_alarm();
```

The callback for the interrupt handler. Actually, this function is implemented by the [`ao_alarm.h`](ao_alarm.h.md) module.

## `ao_ir_alarm_enable`
## `ao_ir_alarm_disable`

```c
void ao_ir_alarm_enable();
void ao_ir_alarm_disable();
```

Enables or disables the interrupt.

## `ao_ir_alarm_request`
## `ao_ir_alarm_reply`

```c
void ao_ir_alarm_request();
void ao_ir_alarm_reply();
```

Requests the interrupt or replies thereto.

## `ao_ir_alarm_set`

```c
void ao_ir_alarm_set(ao_time_t t);
```

Sets the time for the next interrupt.
