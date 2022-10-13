---
author: "Stefan Wagner"
date: 2022-10-13
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gpd/ao_ir_can.h/
toc: true
---

# Include

| `stdbool.h` |
| `sys/attribs.h` |
| `xc.h` |

# Configuration

## `AO_IR_CAN1_*`

```c
#define AO_IR_CAN1_ATTRIBUTE __ISR(_CAN1_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_CAN1_PRIO    (4)
#define AO_IR_CAN1_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_CAN2_*`

```c
#define AO_IR_CAN2_ATTRIBUTE __ISR(_CAN2_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_CAN2_PRIO    (4)
#define AO_IR_CAN2_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_CAN3_*`

```c
#define AO_IR_CAN3_ATTRIBUTE __ISR(_CAN3_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_CAN3_PRIO    (4)
#define AO_IR_CAN3_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_CAN4_*`

```c
#define AO_IR_CAN4_ATTRIBUTE __ISR(_CAN4_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_CAN4_PRIO    (4)
#define AO_IR_CAN4_SUBPRIO (0)
```

The interrupt priority and subpriority.

# Functions

## `ao_ir_can1_*`

```c
#define ao_ir_can1_enable()  { IEC5SET = _IEC5_CAN1IE_MASK; }
#define ao_ir_can1_disable() { IEC5CLR = _IEC5_CAN1IE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_can1_request() { IFS5SET = _IFS5_CAN1IF_MASK; }
#define ao_ir_can1_reply()   { IFS5CLR = _IFS5_CAN1IF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_can1_is_enabled() \
(                               \
    (IEC5 & _IEC5_CAN1IE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_can1_is_pending() \
(                               \
    (IFS5 & _IFS5_CAN1IF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

## `ao_ir_can2_*`

```c
#define ao_ir_can2_enable()  { IEC5SET = _IEC5_CAN2IE_MASK; }
#define ao_ir_can2_disable() { IEC5CLR = _IEC5_CAN2IE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_can2_request() { IFS5SET = _IFS5_CAN2IF_MASK; }
#define ao_ir_can2_reply()   { IFS5CLR = _IFS5_CAN2IF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_can2_is_enabled() \
(                               \
    (IEC5 & _IEC5_CAN2IE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_can2_is_pending() \
(                               \
    (IFS5 & _IFS5_CAN2IF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

## `ao_ir_can3_*`

```c
#define ao_ir_can3_enable()  { IEC5SET = _IEC5_CAN3IE_MASK; }
#define ao_ir_can3_disable() { IEC5CLR = _IEC5_CAN3IE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_can3_request() { IFS5SET = _IFS5_CAN3IF_MASK; }
#define ao_ir_can3_reply()   { IFS5CLR = _IFS5_CAN3IF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_can3_is_enabled() \
(                               \
    (IEC5 & _IEC5_CAN3IE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_can3_is_pending() \
(                               \
    (IFS5 & _IFS5_CAN3IF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

## `ao_ir_can4_*`

```c
#define ao_ir_can4_enable()  { IEC5SET = _IEC5_CAN4IE_MASK; }
#define ao_ir_can4_disable() { IEC5CLR = _IEC5_CAN4IE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_can4_request() { IFS5SET = _IFS5_CAN4IF_MASK; }
#define ao_ir_can4_reply()   { IFS5CLR = _IFS5_CAN4IF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_can4_is_enabled() \
(                               \
    (IEC5 & _IEC5_CAN4IE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_can4_is_pending() \
(                               \
    (IFS5 & _IFS5_CAN4IF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

