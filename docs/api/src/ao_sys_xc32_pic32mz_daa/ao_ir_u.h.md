---
author: "Stefan Wagner"
date: 2022-10-13
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz_daa/ao_ir_u.h/
toc: true
---

# Include

| `stdbool.h` |
| `sys/attribs.h` |
| `xc.h` |

# Configuration

## `AO_IR_U1E_*`

```c
#define AO_IR_U1E_ATTRIBUTE __ISR(_UART1_FAULT_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U1E_PRIO    (4)
#define AO_IR_U1E_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U1RX_*`

```c
#define AO_IR_U1RX_ATTRIBUTE __ISR(_UART1_RX_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U1RX_PRIO    (4)
#define AO_IR_U1RX_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U1TX_*`

```c
#define AO_IR_U1TX_ATTRIBUTE __ISR(_UART1_TX_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U1TX_PRIO    (4)
#define AO_IR_U1TX_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U2E_*`

```c
#define AO_IR_U2E_ATTRIBUTE __ISR(_UART2_FAULT_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U2E_PRIO    (4)
#define AO_IR_U2E_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U2RX_*`

```c
#define AO_IR_U2RX_ATTRIBUTE __ISR(_UART2_RX_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U2RX_PRIO    (4)
#define AO_IR_U2RX_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U2TX_*`

```c
#define AO_IR_U2TX_ATTRIBUTE __ISR(_UART2_TX_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U2TX_PRIO    (4)
#define AO_IR_U2TX_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U3E_*`

```c
#define AO_IR_U3E_ATTRIBUTE __ISR(_UART3_FAULT_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U3E_PRIO    (4)
#define AO_IR_U3E_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U3RX_*`

```c
#define AO_IR_U3RX_ATTRIBUTE __ISR(_UART3_RX_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U3RX_PRIO    (4)
#define AO_IR_U3RX_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U3TX_*`

```c
#define AO_IR_U3TX_ATTRIBUTE __ISR(_UART3_TX_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U3TX_PRIO    (4)
#define AO_IR_U3TX_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U4E_*`

```c
#define AO_IR_U4E_ATTRIBUTE __ISR(_UART4_FAULT_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U4E_PRIO    (4)
#define AO_IR_U4E_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U4RX_*`

```c
#define AO_IR_U4RX_ATTRIBUTE __ISR(_UART4_RX_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U4RX_PRIO    (4)
#define AO_IR_U4RX_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U4TX_*`

```c
#define AO_IR_U4TX_ATTRIBUTE __ISR(_UART4_TX_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U4TX_PRIO    (4)
#define AO_IR_U4TX_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U5E_*`

```c
#define AO_IR_U5E_ATTRIBUTE __ISR(_UART5_FAULT_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U5E_PRIO    (4)
#define AO_IR_U5E_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U5RX_*`

```c
#define AO_IR_U5RX_ATTRIBUTE __ISR(_UART5_RX_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U5RX_PRIO    (4)
#define AO_IR_U5RX_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U5TX_*`

```c
#define AO_IR_U5TX_ATTRIBUTE __ISR(_UART5_TX_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U5TX_PRIO    (4)
#define AO_IR_U5TX_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U6E_*`

```c
#define AO_IR_U6E_ATTRIBUTE __ISR(_UART6_FAULT_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U6E_PRIO    (4)
#define AO_IR_U6E_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U6RX_*`

```c
#define AO_IR_U6RX_ATTRIBUTE __ISR(_UART6_RX_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U6RX_PRIO    (4)
#define AO_IR_U6RX_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U6TX_*`

```c
#define AO_IR_U6TX_ATTRIBUTE __ISR(_UART6_TX_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U6TX_PRIO    (4)
#define AO_IR_U6TX_SUBPRIO (0)
```

The interrupt priority and subpriority.

# Functions

## `ao_ir_u1e_*`

```c
#define ao_ir_u1e_enable()  { IEC3SET = _IEC3_U1EIE_MASK; }
#define ao_ir_u1e_disable() { IEC3CLR = _IEC3_U1EIE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_u1e_request() { IFS3SET = _IFS3_U1EIF_MASK; }
#define ao_ir_u1e_reply()   { IFS3CLR = _IFS3_U1EIF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u1e_is_enabled() \
(                              \
    (IEC3 & _IEC3_U1EIE_MASK)  \
    ? true                     \
    : false                    \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u1e_is_pending() \
(                              \
    (IFS3 & _IFS3_U1EIF_MASK)  \
    ? true                     \
    : false                    \
)
```

Checks whether the interrupt is pending.

## `ao_ir_u1rx_*`

```c
#define ao_ir_u1rx_enable()  { IEC3SET = _IEC3_U1RXIE_MASK; }
#define ao_ir_u1rx_disable() { IEC3CLR = _IEC3_U1RXIE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_u1rx_request() { IFS3SET = _IFS3_U1RXIF_MASK; }
#define ao_ir_u1rx_reply()   { IFS3CLR = _IFS3_U1RXIF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u1rx_is_enabled() \
(                               \
    (IEC3 & _IEC3_U1RXIE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u1rx_is_pending() \
(                               \
    (IFS3 & _IFS3_U1RXIF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

## `ao_ir_u1tx_*`

```c
#define ao_ir_u1tx_enable()  { IEC3SET = _IEC3_U1TXIE_MASK; }
#define ao_ir_u1tx_disable() { IEC3CLR = _IEC3_U1TXIE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_u1tx_request() { IFS3SET = _IFS3_U1TXIF_MASK; }
#define ao_ir_u1tx_reply()   { IFS3CLR = _IFS3_U1TXIF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u1tx_is_enabled() \
(                               \
    (IEC3 & _IEC3_U1TXIE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u1tx_is_pending() \
(                               \
    (IFS3 & _IFS3_U1TXIF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

## `ao_ir_u2e_*`

```c
#define ao_ir_u2e_enable()  { IEC4SET = _IEC4_U2EIE_MASK; }
#define ao_ir_u2e_disable() { IEC4CLR = _IEC4_U2EIE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_u2e_request() { IFS4SET = _IFS4_U2EIF_MASK; }
#define ao_ir_u2e_reply()   { IFS4CLR = _IFS4_U2EIF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u2e_is_enabled() \
(                              \
    (IEC4 & _IEC4_U2EIE_MASK)  \
    ? true                     \
    : false                    \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u2e_is_pending() \
(                              \
    (IFS4 & _IFS4_U2EIF_MASK)  \
    ? true                     \
    : false                    \
)
```

Checks whether the interrupt is pending.

## `ao_ir_u2rx_*`

```c
#define ao_ir_u2rx_enable()  { IEC4SET = _IEC4_U2RXIE_MASK; }
#define ao_ir_u2rx_disable() { IEC4CLR = _IEC4_U2RXIE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_u2rx_request() { IFS4SET = _IFS4_U2RXIF_MASK; }
#define ao_ir_u2rx_reply()   { IFS4CLR = _IFS4_U2RXIF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u2rx_is_enabled() \
(                               \
    (IEC4 & _IEC4_U2RXIE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u2rx_is_pending() \
(                               \
    (IFS4 & _IFS4_U2RXIF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

## `ao_ir_u2tx_*`

```c
#define ao_ir_u2tx_enable()  { IEC4SET = _IEC4_U2TXIE_MASK; }
#define ao_ir_u2tx_disable() { IEC4CLR = _IEC4_U2TXIE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_u2tx_request() { IFS4SET = _IFS4_U2TXIF_MASK; }
#define ao_ir_u2tx_reply()   { IFS4CLR = _IFS4_U2TXIF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u2tx_is_enabled() \
(                               \
    (IEC4 & _IEC4_U2TXIE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u2tx_is_pending() \
(                               \
    (IFS4 & _IFS4_U2TXIF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

## `ao_ir_u3e_*`

```c
#define ao_ir_u3e_enable()  { IEC4SET = _IEC4_U3EIE_MASK; }
#define ao_ir_u3e_disable() { IEC4CLR = _IEC4_U3EIE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_u3e_request() { IFS4SET = _IFS4_U3EIF_MASK; }
#define ao_ir_u3e_reply()   { IFS4CLR = _IFS4_U3EIF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u3e_is_enabled() \
(                              \
    (IEC4 & _IEC4_U3EIE_MASK)  \
    ? true                     \
    : false                    \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u3e_is_pending() \
(                              \
    (IFS4 & _IFS4_U3EIF_MASK)  \
    ? true                     \
    : false                    \
)
```

Checks whether the interrupt is pending.

## `ao_ir_u3rx_*`

```c
#define ao_ir_u3rx_enable()  { IEC4SET = _IEC4_U3RXIE_MASK; }
#define ao_ir_u3rx_disable() { IEC4CLR = _IEC4_U3RXIE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_u3rx_request() { IFS4SET = _IFS4_U3RXIF_MASK; }
#define ao_ir_u3rx_reply()   { IFS4CLR = _IFS4_U3RXIF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u3rx_is_enabled() \
(                               \
    (IEC4 & _IEC4_U3RXIE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u3rx_is_pending() \
(                               \
    (IFS4 & _IFS4_U3RXIF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

## `ao_ir_u3tx_*`

```c
#define ao_ir_u3tx_enable()  { IEC4SET = _IEC4_U3TXIE_MASK; }
#define ao_ir_u3tx_disable() { IEC4CLR = _IEC4_U3TXIE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_u3tx_request() { IFS4SET = _IFS4_U3TXIF_MASK; }
#define ao_ir_u3tx_reply()   { IFS4CLR = _IFS4_U3TXIF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u3tx_is_enabled() \
(                               \
    (IEC4 & _IEC4_U3TXIE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u3tx_is_pending() \
(                               \
    (IFS4 & _IFS4_U3TXIF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

## `ao_ir_u4e_*`

```c
#define ao_ir_u4e_enable()  { IEC5SET = _IEC5_U4EIE_MASK; }
#define ao_ir_u4e_disable() { IEC5CLR = _IEC5_U4EIE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_u4e_request() { IFS5SET = _IFS5_U4EIF_MASK; }
#define ao_ir_u4e_reply()   { IFS5CLR = _IFS5_U4EIF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u4e_is_enabled() \
(                              \
    (IEC5 & _IEC5_U4EIE_MASK)  \
    ? true                     \
    : false                    \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u4e_is_pending() \
(                              \
    (IFS5 & _IFS5_U4EIF_MASK)  \
    ? true                     \
    : false                    \
)
```

Checks whether the interrupt is pending.

## `ao_ir_u4rx_*`

```c
#define ao_ir_u4rx_enable()  { IEC5SET = _IEC5_U4RXIE_MASK; }
#define ao_ir_u4rx_disable() { IEC5CLR = _IEC5_U4RXIE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_u4rx_request() { IFS5SET = _IFS5_U4RXIF_MASK; }
#define ao_ir_u4rx_reply()   { IFS5CLR = _IFS5_U4RXIF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u4rx_is_enabled() \
(                               \
    (IEC5 & _IEC5_U4RXIE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u4rx_is_pending() \
(                               \
    (IFS5 & _IFS5_U4RXIF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

## `ao_ir_u4tx_*`

```c
#define ao_ir_u4tx_enable()  { IEC5SET = _IEC5_U4TXIE_MASK; }
#define ao_ir_u4tx_disable() { IEC5CLR = _IEC5_U4TXIE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_u4tx_request() { IFS5SET = _IFS5_U4TXIF_MASK; }
#define ao_ir_u4tx_reply()   { IFS5CLR = _IFS5_U4TXIF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u4tx_is_enabled() \
(                               \
    (IEC5 & _IEC5_U4TXIE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u4tx_is_pending() \
(                               \
    (IFS5 & _IFS5_U4TXIF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

## `ao_ir_u5e_*`

```c
#define ao_ir_u5e_enable()  { IEC5SET = _IEC5_U5EIE_MASK; }
#define ao_ir_u5e_disable() { IEC5CLR = _IEC5_U5EIE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_u5e_request() { IFS5SET = _IFS5_U5EIF_MASK; }
#define ao_ir_u5e_reply()   { IFS5CLR = _IFS5_U5EIF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u5e_is_enabled() \
(                              \
    (IEC5 & _IEC5_U5EIE_MASK)  \
    ? true                     \
    : false                    \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u5e_is_pending() \
(                              \
    (IFS5 & _IFS5_U5EIF_MASK)  \
    ? true                     \
    : false                    \
)
```

Checks whether the interrupt is pending.

## `ao_ir_u5rx_*`

```c
#define ao_ir_u5rx_enable()  { IEC5SET = _IEC5_U5RXIE_MASK; }
#define ao_ir_u5rx_disable() { IEC5CLR = _IEC5_U5RXIE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_u5rx_request() { IFS5SET = _IFS5_U5RXIF_MASK; }
#define ao_ir_u5rx_reply()   { IFS5CLR = _IFS5_U5RXIF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u5rx_is_enabled() \
(                               \
    (IEC5 & _IEC5_U5RXIE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u5rx_is_pending() \
(                               \
    (IFS5 & _IFS5_U5RXIF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

## `ao_ir_u5tx_*`

```c
#define ao_ir_u5tx_enable()  { IEC5SET = _IEC5_U5TXIE_MASK; }
#define ao_ir_u5tx_disable() { IEC5CLR = _IEC5_U5TXIE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_u5tx_request() { IFS5SET = _IFS5_U5TXIF_MASK; }
#define ao_ir_u5tx_reply()   { IFS5CLR = _IFS5_U5TXIF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u5tx_is_enabled() \
(                               \
    (IEC5 & _IEC5_U5TXIE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u5tx_is_pending() \
(                               \
    (IFS5 & _IFS5_U5TXIF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

## `ao_ir_u6e_*`

```c
#define ao_ir_u6e_enable()  { IEC5SET = _IEC5_U6EIE_MASK; }
#define ao_ir_u6e_disable() { IEC5CLR = _IEC5_U6EIE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_u6e_request() { IFS5SET = _IFS5_U6EIF_MASK; }
#define ao_ir_u6e_reply()   { IFS5CLR = _IFS5_U6EIF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u6e_is_enabled() \
(                              \
    (IEC5 & _IEC5_U6EIE_MASK)  \
    ? true                     \
    : false                    \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u6e_is_pending() \
(                              \
    (IFS5 & _IFS5_U6EIF_MASK)  \
    ? true                     \
    : false                    \
)
```

Checks whether the interrupt is pending.

## `ao_ir_u6rx_*`

```c
#define ao_ir_u6rx_enable()  { IEC5SET = _IEC5_U6RXIE_MASK; }
#define ao_ir_u6rx_disable() { IEC5CLR = _IEC5_U6RXIE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_u6rx_request() { IFS5SET = _IFS5_U6RXIF_MASK; }
#define ao_ir_u6rx_reply()   { IFS5CLR = _IFS5_U6RXIF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u6rx_is_enabled() \
(                               \
    (IEC5 & _IEC5_U6RXIE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u6rx_is_pending() \
(                               \
    (IFS5 & _IFS5_U6RXIF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

## `ao_ir_u6tx_*`

```c
#define ao_ir_u6tx_enable()  { IEC5SET = _IEC5_U6TXIE_MASK; }
#define ao_ir_u6tx_disable() { IEC5CLR = _IEC5_U6TXIE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_u6tx_request() { IFS5SET = _IFS5_U6TXIF_MASK; }
#define ao_ir_u6tx_reply()   { IFS5CLR = _IFS5_U6TXIF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u6tx_is_enabled() \
(                               \
    (IEC5 & _IEC5_U6TXIE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u6tx_is_pending() \
(                               \
    (IFS5 & _IFS5_U6TXIF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

