---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_ir_alarm.h/
toc: true
---

# Notes

This module declares functions for controlling the alarm interrupt as well as a callback function for the interrupt handler.

# Include

| [`ao_ir_ct.h`](ao_ir_ct.h.md) |
| `xc.h` |

# Identifier

```c
#define AO_IR_ALARM
```

# Functions

## `ao_ir_alarm`

```c
void ao_ir_alarm();
```

The callback for the interrupt handler. Actually, this function is implemented by the [`ao_alarm.h`](../ao_sys/ao_alarm.h.md) module.

## `ao_ir_alarm_enable`
## `ao_ir_alarm_disable`

```c
#define ao_ir_alarm_enable()  ao_ir_ct_enable()
#define ao_ir_alarm_disable() ao_ir_ct_disable()
```

Enables or disables the interrupt.

## `ao_ir_alarm_request`
## `ao_ir_alarm_reply`

```c
#define ao_ir_alarm_request() ao_ir_ct_request()
#define ao_ir_alarm_reply()   ao_ir_ct_reply()
```

Requests the interrupt or replies thereto.

## `ao_ir_alarm_set`

```c
#define ao_ir_alarm_set(time) \
{                             \
    _CP0_SET_COMPARE(time);   \
}
```

Sets the time for the next interrupt.
