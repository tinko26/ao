---
author: "Stefan Wagner"
date: 2022-09-25
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_1xx_xlp/ao_ir_u.h/
toc: true
---

# Include

| `stdbool.h` |
| `sys/attribs.h` |
| `xc.h` |

# Identifier

```c
#define AO_IR_U
```

# Configuration

## `AO_IR_U1_*`

```c
#define AO_IR_U1_ATTRIBUTE __ISR(_UART_1_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_U1_PRIO    (4)
#define AO_IR_U1_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U2_*`

```c
#define AO_IR_U2_ATTRIBUTE __ISR(_UART_2_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_U2_PRIO    (4)
#define AO_IR_U2_SUBPRIO (0)
```

The interrupt priority and subpriority.

# Functions

## `ao_ir_u1e_*`

```c
#define ao_ir_u1e_enable()  { IEC1SET = _IEC1_U1EIE_MASK; }
#define ao_ir_u1e_disable() { IEC1CLR = _IEC1_U1EIE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_u1e_request() { IFS1SET = _IFS1_U1EIF_MASK; }
#define ao_ir_u1e_reply()   { IFS1CLR = _IFS1_U1EIF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u1e_is_enabled() \
(                              \
    (IEC1 & _IEC1_U1EIE_MASK)  \
    ? true                     \
    : false                    \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u1e_is_pending() \
(                              \
    (IFS1 & _IFS1_U1EIF_MASK)  \
    ? true                     \
    : false                    \
)
```

Checks whether the interrupt is pending.

## `ao_ir_u1rx_*`

```c
#define ao_ir_u1rx_enable()  { IEC1SET = _IEC1_U1RXIE_MASK; }
#define ao_ir_u1rx_disable() { IEC1CLR = _IEC1_U1RXIE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_u1rx_request() { IFS1SET = _IFS1_U1RXIF_MASK; }
#define ao_ir_u1rx_reply()   { IFS1CLR = _IFS1_U1RXIF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u1rx_is_enabled() \
(                               \
    (IEC1 & _IEC1_U1RXIE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u1rx_is_pending() \
(                               \
    (IFS1 & _IFS1_U1RXIF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

## `ao_ir_u1tx_*`

```c
#define ao_ir_u1tx_enable()  { IEC1SET = _IEC1_U1TXIE_MASK; }
#define ao_ir_u1tx_disable() { IEC1CLR = _IEC1_U1TXIE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_u1tx_request() { IFS1SET = _IFS1_U1TXIF_MASK; }
#define ao_ir_u1tx_reply()   { IFS1CLR = _IFS1_U1TXIF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u1tx_is_enabled() \
(                               \
    (IEC1 & _IEC1_U1TXIE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u1tx_is_pending() \
(                               \
    (IFS1 & _IFS1_U1TXIF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

## `ao_ir_u2e_*`

```c
#define ao_ir_u2e_enable()  { IEC1SET = _IEC1_U2EIE_MASK; }
#define ao_ir_u2e_disable() { IEC1CLR = _IEC1_U2EIE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_u2e_request() { IFS1SET = _IFS1_U2EIF_MASK; }
#define ao_ir_u2e_reply()   { IFS1CLR = _IFS1_U2EIF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u2e_is_enabled() \
(                              \
    (IEC1 & _IEC1_U2EIE_MASK)  \
    ? true                     \
    : false                    \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u2e_is_pending() \
(                              \
    (IFS1 & _IFS1_U2EIF_MASK)  \
    ? true                     \
    : false                    \
)
```

Checks whether the interrupt is pending.

## `ao_ir_u2rx_*`

```c
#define ao_ir_u2rx_enable()  { IEC1SET = _IEC1_U2RXIE_MASK; }
#define ao_ir_u2rx_disable() { IEC1CLR = _IEC1_U2RXIE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_u2rx_request() { IFS1SET = _IFS1_U2RXIF_MASK; }
#define ao_ir_u2rx_reply()   { IFS1CLR = _IFS1_U2RXIF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u2rx_is_enabled() \
(                               \
    (IEC1 & _IEC1_U2RXIE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u2rx_is_pending() \
(                               \
    (IFS1 & _IFS1_U2RXIF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

## `ao_ir_u2tx_*`

```c
#define ao_ir_u2tx_enable()  { IEC1SET = _IEC1_U2TXIE_MASK; }
#define ao_ir_u2tx_disable() { IEC1CLR = _IEC1_U2TXIE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_u2tx_request() { IFS1SET = _IFS1_U2TXIF_MASK; }
#define ao_ir_u2tx_reply()   { IFS1CLR = _IFS1_U2TXIF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u2tx_is_enabled() \
(                               \
    (IEC1 & _IEC1_U2TXIE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u2tx_is_pending() \
(                               \
    (IFS1 & _IFS1_U2TXIF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

