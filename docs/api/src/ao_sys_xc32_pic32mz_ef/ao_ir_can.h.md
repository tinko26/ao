---
author: "Stefan Wagner"
date: 2022-09-25
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz_ef/ao_ir_can.h/
toc: true
---

# Include

| `stdbool.h` |
| `sys/attribs.h` |
| `xc.h` |

# Identifier

```c
#define AO_IR_CAN
```

# Configuration

## `AO_IR_CAN1_*`

```c
#define AO_IR_CAN1_ATTRIBUTE __ISR(_CAN1_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_CAN1_PRIO    (4)
#define AO_IR_CAN1_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_CAN2_*`

```c
#define AO_IR_CAN2_ATTRIBUTE __ISR(_CAN2_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_CAN2_PRIO    (4)
#define AO_IR_CAN2_SUBPRIO (0)
```

The interrupt priority and subpriority.

# Functions

## `ao_ir_can1_*`

```c
#define ao_ir_can1_enable()  { IEC4SET = _IEC4_CAN1IE_MASK; }
#define ao_ir_can1_disable() { IEC4CLR = _IEC4_CAN1IE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_can1_request() { IFS4SET = _IFS4_CAN1IF_MASK; }
#define ao_ir_can1_reply()   { IFS4CLR = _IFS4_CAN1IF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_can1_is_enabled() \
(                               \
    (IEC4 & _IEC4_CAN1IE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_can1_is_pending() \
(                               \
    (IFS4 & _IFS4_CAN1IF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

## `ao_ir_can2_*`

```c
#define ao_ir_can2_enable()  { IEC4SET = _IEC4_CAN2IE_MASK; }
#define ao_ir_can2_disable() { IEC4CLR = _IEC4_CAN2IE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_can2_request() { IFS4SET = _IFS4_CAN2IF_MASK; }
#define ao_ir_can2_reply()   { IFS4CLR = _IFS4_CAN2IF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_can2_is_enabled() \
(                               \
    (IEC4 & _IEC4_CAN2IE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_can2_is_pending() \
(                               \
    (IFS4 & _IFS4_CAN2IF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

