---
author: "Stefan Wagner"
date: 2022-09-25
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_330/ao_ir_ct.h/
toc: true
---

# Include

| `stdbool.h` |
| `sys/attribs.h` |
| `xc.h` |

# Identifier

```c
#define AO_IR_CT
```

# Configuration

## `AO_IR_CT_*`

```c
#define AO_IR_CT_ATTRIBUTE __ISR(_CORE_TIMER_VECTOR, IPL3SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_CT_PRIO    (3)
#define AO_IR_CT_SUBPRIO (0)
```

The interrupt priority and subpriority.

# Functions

## `ao_ir_ct_*`

```c
#define ao_ir_ct_enable()  { IEC0SET = _IEC0_CTIE_MASK; }
#define ao_ir_ct_disable() { IEC0CLR = _IEC0_CTIE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_ct_request() { IFS0SET = _IFS0_CTIF_MASK; }
#define ao_ir_ct_reply()   { IFS0CLR = _IFS0_CTIF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ct_is_enabled() \
(                             \
    (IEC0 & _IEC0_CTIE_MASK)  \
    ? true                    \
    : false                   \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ct_is_pending() \
(                             \
    (IFS0 & _IFS0_CTIF_MASK)  \
    ? true                    \
    : false                   \
)
```

Checks whether the interrupt is pending.

