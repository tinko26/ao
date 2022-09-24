---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_ir_alarm.h/
toc: true
---

# Notes

This module declares functions for controlling the alarm interrupt as well as a callback function for the interrupt handler. This module is abstract, that is, an implementation must be provided by a port package in order to support alarms.

## Porting

The port must implement an interrupt handler, which in turn must execute the callback function. On start-up, the alarm interrupt must be disabled.

# Include

| [`ao_time.h`](ao_time.h.md) |

# Identifier

```c
#define AO_IR_ALARM
```

# Functions

## `ao_alarm`

```c
void ao_alarm();
```

The callback for the interrupt handler. Actually, this function is implemented by the [`ao_alarm.h`](ao_alarm.h.md) module.

## `ao_alarm_enable`
## `ao_alarm_disable`

```c
void ao_alarm_enable();
void ao_alarm_disable();
```

Enables or disables the interrupt.

## `ao_alarm_request`
## `ao_alarm_reply`

```c
void ao_alarm_request();
void ao_alarm_reply();
```

Requests the interrupt or replies thereto.

## `ao_alarm_set`

```c
void ao_alarm_set(ao_time_t t);
```

Sets the time for the next interrupt.
