---
author: "Stefan Wagner"
date: 2022-09-22
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_5xx/ao_ir_can.h/
toc: true
---

# Include

| `stdbool.h` |
| `sys/attribs.h` |
| `xc.h` |

# Configuration

## `AO_IR_CAN1`

```c
#define AO_IR_CAN1_ATTRIBUTE __ISR(_CAN_1_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_CAN1_PRIO    (4)
#define AO_IR_CAN1_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_CAN2`

```c
#define AO_IR_CAN2_ATTRIBUTE __ISR(_CAN_2_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_CAN2_PRIO    (4)
#define AO_IR_CAN2_SUBPRIO (0)
```

The interrupt priority and subpriority.

# Functions

## `ao_ir_can1`

```c
#define ao_ir_can1_enable()  { IEC1SET = _IEC1_CAN1IE_MASK; }
#define ao_ir_can1_disable() { IEC1CLR = _IEC1_CAN1IE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_can1_request() { IFS1SET = _IFS1_CAN1IF_MASK; }
#define ao_ir_can1_reply()   { IFS1CLR = _IFS1_CAN1IF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_can1_is_enabled() \
(                               \
    (IEC1 & _IEC1_CAN1IE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_can1_is_pending() \
(                               \
    (IFS1 & _IFS1_CAN1IF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

## `ao_ir_can2`

```c
#define ao_ir_can2_enable()  { IEC1SET = _IEC1_CAN2IE_MASK; }
#define ao_ir_can2_disable() { IEC1CLR = _IEC1_CAN2IE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_can2_request() { IFS1SET = _IFS1_CAN2IF_MASK; }
#define ao_ir_can2_reply()   { IFS1CLR = _IFS1_CAN2IF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_can2_is_enabled() \
(                               \
    (IEC1 & _IEC1_CAN2IE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_can2_is_pending() \
(                               \
    (IFS1 & _IFS1_CAN2IF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

