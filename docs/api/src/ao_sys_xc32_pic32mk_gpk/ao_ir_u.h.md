---
author: "Stefan Wagner"
date: 2022-09-22
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gpk/ao_ir_u.h/
toc: true
---

# Include

| `stdbool.h` |
| `sys/attribs.h` |
| `xc.h` |

# Configuration

## `AO_IR_U1E`

```c
#define AO_IR_U1E_ATTRIBUTE __ISR(_UART1_FAULT_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U1E_PRIO    (4)
#define AO_IR_U1E_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U1RX`

```c
#define AO_IR_U1RX_ATTRIBUTE __ISR(_UART1_RX_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U1RX_PRIO    (4)
#define AO_IR_U1RX_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U1TX`

```c
#define AO_IR_U1TX_ATTRIBUTE __ISR(_UART1_TX_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U1TX_PRIO    (4)
#define AO_IR_U1TX_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U2E`

```c
#define AO_IR_U2E_ATTRIBUTE __ISR(_UART2_FAULT_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U2E_PRIO    (4)
#define AO_IR_U2E_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U2RX`

```c
#define AO_IR_U2RX_ATTRIBUTE __ISR(_UART2_RX_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U2RX_PRIO    (4)
#define AO_IR_U2RX_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U2TX`

```c
#define AO_IR_U2TX_ATTRIBUTE __ISR(_UART2_TX_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U2TX_PRIO    (4)
#define AO_IR_U2TX_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U3E`

```c
#define AO_IR_U3E_ATTRIBUTE __ISR(_UART3_FAULT_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U3E_PRIO    (4)
#define AO_IR_U3E_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U3RX`

```c
#define AO_IR_U3RX_ATTRIBUTE __ISR(_UART3_RX_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U3RX_PRIO    (4)
#define AO_IR_U3RX_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U3TX`

```c
#define AO_IR_U3TX_ATTRIBUTE __ISR(_UART3_TX_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U3TX_PRIO    (4)
#define AO_IR_U3TX_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U4E`

```c
#define AO_IR_U4E_ATTRIBUTE __ISR(_UART4_FAULT_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U4E_PRIO    (4)
#define AO_IR_U4E_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U4RX`

```c
#define AO_IR_U4RX_ATTRIBUTE __ISR(_UART4_RX_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U4RX_PRIO    (4)
#define AO_IR_U4RX_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U4TX`

```c
#define AO_IR_U4TX_ATTRIBUTE __ISR(_UART4_TX_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U4TX_PRIO    (4)
#define AO_IR_U4TX_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U5E`

```c
#define AO_IR_U5E_ATTRIBUTE __ISR(_UART5_FAULT_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U5E_PRIO    (4)
#define AO_IR_U5E_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U5RX`

```c
#define AO_IR_U5RX_ATTRIBUTE __ISR(_UART5_RX_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U5RX_PRIO    (4)
#define AO_IR_U5RX_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U5TX`

```c
#define AO_IR_U5TX_ATTRIBUTE __ISR(_UART5_TX_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U5TX_PRIO    (4)
#define AO_IR_U5TX_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U6E`

```c
#define AO_IR_U6E_ATTRIBUTE __ISR(_UART6_FAULT_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U6E_PRIO    (4)
#define AO_IR_U6E_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U6RX`

```c
#define AO_IR_U6RX_ATTRIBUTE __ISR(_UART6_RX_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_U6RX_PRIO    (4)
#define AO_IR_U6RX_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U6TX`

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

## `ao_ir_u1e`

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

## `ao_ir_u1rx`

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

## `ao_ir_u1tx`

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

## `ao_ir_u2e`

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

## `ao_ir_u2rx`

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

## `ao_ir_u2tx`

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

## `ao_ir_u3e`

```c
#define ao_ir_u3e_enable()  { IEC1SET = _IEC1_U3EIE_MASK; }
#define ao_ir_u3e_disable() { IEC1CLR = _IEC1_U3EIE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_u3e_request() { IFS1SET = _IFS1_U3EIF_MASK; }
#define ao_ir_u3e_reply()   { IFS1CLR = _IFS1_U3EIF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u3e_is_enabled() \
(                              \
    (IEC1 & _IEC1_U3EIE_MASK)  \
    ? true                     \
    : false                    \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u3e_is_pending() \
(                              \
    (IFS1 & _IFS1_U3EIF_MASK)  \
    ? true                     \
    : false                    \
)
```

Checks whether the interrupt is pending.

## `ao_ir_u3rx`

```c
#define ao_ir_u3rx_enable()  { IEC1SET = _IEC1_U3RXIE_MASK; }
#define ao_ir_u3rx_disable() { IEC1CLR = _IEC1_U3RXIE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_u3rx_request() { IFS1SET = _IFS1_U3RXIF_MASK; }
#define ao_ir_u3rx_reply()   { IFS1CLR = _IFS1_U3RXIF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u3rx_is_enabled() \
(                               \
    (IEC1 & _IEC1_U3RXIE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u3rx_is_pending() \
(                               \
    (IFS1 & _IFS1_U3RXIF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

## `ao_ir_u3tx`

```c
#define ao_ir_u3tx_enable()  { IEC2SET = _IEC2_U3TXIE_MASK; }
#define ao_ir_u3tx_disable() { IEC2CLR = _IEC2_U3TXIE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_u3tx_request() { IFS2SET = _IFS2_U3TXIF_MASK; }
#define ao_ir_u3tx_reply()   { IFS2CLR = _IFS2_U3TXIF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u3tx_is_enabled() \
(                               \
    (IEC2 & _IEC2_U3TXIE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u3tx_is_pending() \
(                               \
    (IFS2 & _IFS2_U3TXIF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

## `ao_ir_u4e`

```c
#define ao_ir_u4e_enable()  { IEC2SET = _IEC2_U4EIE_MASK; }
#define ao_ir_u4e_disable() { IEC2CLR = _IEC2_U4EIE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_u4e_request() { IFS2SET = _IFS2_U4EIF_MASK; }
#define ao_ir_u4e_reply()   { IFS2CLR = _IFS2_U4EIF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u4e_is_enabled() \
(                              \
    (IEC2 & _IEC2_U4EIE_MASK)  \
    ? true                     \
    : false                    \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u4e_is_pending() \
(                              \
    (IFS2 & _IFS2_U4EIF_MASK)  \
    ? true                     \
    : false                    \
)
```

Checks whether the interrupt is pending.

## `ao_ir_u4rx`

```c
#define ao_ir_u4rx_enable()  { IEC2SET = _IEC2_U4RXIE_MASK; }
#define ao_ir_u4rx_disable() { IEC2CLR = _IEC2_U4RXIE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_u4rx_request() { IFS2SET = _IFS2_U4RXIF_MASK; }
#define ao_ir_u4rx_reply()   { IFS2CLR = _IFS2_U4RXIF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u4rx_is_enabled() \
(                               \
    (IEC2 & _IEC2_U4RXIE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u4rx_is_pending() \
(                               \
    (IFS2 & _IFS2_U4RXIF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

## `ao_ir_u4tx`

```c
#define ao_ir_u4tx_enable()  { IEC2SET = _IEC2_U4TXIE_MASK; }
#define ao_ir_u4tx_disable() { IEC2CLR = _IEC2_U4TXIE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_u4tx_request() { IFS2SET = _IFS2_U4TXIF_MASK; }
#define ao_ir_u4tx_reply()   { IFS2CLR = _IFS2_U4TXIF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u4tx_is_enabled() \
(                               \
    (IEC2 & _IEC2_U4TXIE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u4tx_is_pending() \
(                               \
    (IFS2 & _IFS2_U4TXIF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

## `ao_ir_u5e`

```c
#define ao_ir_u5e_enable()  { IEC2SET = _IEC2_U5EIE_MASK; }
#define ao_ir_u5e_disable() { IEC2CLR = _IEC2_U5EIE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_u5e_request() { IFS2SET = _IFS2_U5EIF_MASK; }
#define ao_ir_u5e_reply()   { IFS2CLR = _IFS2_U5EIF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u5e_is_enabled() \
(                              \
    (IEC2 & _IEC2_U5EIE_MASK)  \
    ? true                     \
    : false                    \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u5e_is_pending() \
(                              \
    (IFS2 & _IFS2_U5EIF_MASK)  \
    ? true                     \
    : false                    \
)
```

Checks whether the interrupt is pending.

## `ao_ir_u5rx`

```c
#define ao_ir_u5rx_enable()  { IEC2SET = _IEC2_U5RXIE_MASK; }
#define ao_ir_u5rx_disable() { IEC2CLR = _IEC2_U5RXIE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_u5rx_request() { IFS2SET = _IFS2_U5RXIF_MASK; }
#define ao_ir_u5rx_reply()   { IFS2CLR = _IFS2_U5RXIF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u5rx_is_enabled() \
(                               \
    (IEC2 & _IEC2_U5RXIE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u5rx_is_pending() \
(                               \
    (IFS2 & _IFS2_U5RXIF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

## `ao_ir_u5tx`

```c
#define ao_ir_u5tx_enable()  { IEC2SET = _IEC2_U5TXIE_MASK; }
#define ao_ir_u5tx_disable() { IEC2CLR = _IEC2_U5TXIE_MASK; }
```

Enables or disables the interrupt.

```c
#define ao_ir_u5tx_request() { IFS2SET = _IFS2_U5TXIF_MASK; }
#define ao_ir_u5tx_reply()   { IFS2CLR = _IFS2_U5TXIF_MASK; }
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u5tx_is_enabled() \
(                               \
    (IEC2 & _IEC2_U5TXIE_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u5tx_is_pending() \
(                               \
    (IFS2 & _IFS2_U5TXIF_MASK)  \
    ? true                      \
    : false                     \
)
```

Checks whether the interrupt is pending.

## `ao_ir_u6e`

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

## `ao_ir_u6rx`

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

## `ao_ir_u6tx`

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

