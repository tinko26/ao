---
author: "Stefan Wagner"
date: 2022-09-22
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_1xx_64_100/ao_ir_can.h/
toc: true
---

# Include

`stdbool.h` <br/>
`sys/attribs.h` <br/>
`xc.h`

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

# Functions

## `ao_ir_can1`

```c
#define ao_ir_can1_enable()  { IEC2SET = _IEC2_CAN1IE_MASK; }
#define ao_ir_can1_disable() { IEC2CLR = _IEC2_CAN1IE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_can1_request() { IFS2SET = _IFS2_CAN1IF_MASK; }
#define ao_ir_can1_reply()   { IFS2CLR = _IFS2_CAN1IF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_can1_is_enabled() \
(                               \
    (IEC2 & _IEC2_CAN1IE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_can1_is_pending() \
(                               \
    (IFS2 & _IFS2_CAN1IF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

