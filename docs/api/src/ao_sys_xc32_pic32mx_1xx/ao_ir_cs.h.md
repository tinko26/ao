---
author: "Stefan Wagner"
date: 2022-09-25
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_1xx/ao_ir_cs.h/
toc: true
---

# Include

| `stdbool.h` |
| `sys/attribs.h` |
| `xc.h` |

# Identifier

```c
#define AO_IR_CS
```

# Configuration

## `AO_IR_CS0_*`

```c
#define AO_IR_CS0_ATTRIBUTE __ISR(_CORE_SOFTWARE_0_VECTOR, IPL2SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_CS0_PRIO    (2)
#define AO_IR_CS0_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_CS1_*`

```c
#define AO_IR_CS1_ATTRIBUTE __attribute__ ((naked, vector(_CORE_SOFTWARE_1_VECTOR)))
```

The interrupt handler attribute.

```c
#define AO_IR_CS1_PRIO    (1)
#define AO_IR_CS1_SUBPRIO (0)
```

The interrupt priority and subpriority.

# Functions

## `ao_ir_cs0_*`

```c
#define ao_ir_cs0_enable()  { IEC0SET = _IEC0_CS0IE_MASK; }
#define ao_ir_cs0_disable() { IEC0CLR = _IEC0_CS0IE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_cs0_request() { IFS0SET = _IFS0_CS0IF_MASK; }
#define ao_ir_cs0_reply()   { IFS0CLR = _IFS0_CS0IF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_cs0_is_enabled() \
(                              \
    (IEC0 & _IEC0_CS0IE_MASK)  \
    ? true                     \
    : false                    \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_cs0_is_pending() \
(                              \
    (IFS0 & _IFS0_CS0IF_MASK)  \
    ? true                     \
    : false                    \
)
```

Checks whether the interrupt is pending.

## `ao_ir_cs1_*`

```c
#define ao_ir_cs1_enable()  { IEC0SET = _IEC0_CS1IE_MASK; }
#define ao_ir_cs1_disable() { IEC0CLR = _IEC0_CS1IE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_cs1_request() { IFS0SET = _IFS0_CS1IF_MASK; }
#define ao_ir_cs1_reply()   { IFS0CLR = _IFS0_CS1IF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_cs1_is_enabled() \
(                              \
    (IEC0 & _IEC0_CS1IE_MASK)  \
    ? true                     \
    : false                    \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_cs1_is_pending() \
(                              \
    (IFS0 & _IFS0_CS1IF_MASK)  \
    ? true                     \
    : false                    \
)
```

Checks whether the interrupt is pending.

