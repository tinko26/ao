---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz_ef/ao_ir_u.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_U1E`

The interrupt handler attribute.

```c
#define AO_IR_U1E_ATTRIBUTE __ISR(_UART1_FAULT_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_U1E_PRIO      (4)
#define AO_IR_U1E_SUBPRIO   (0)
```

## `AO_IR_U1RX`

The interrupt handler attribute.

```c
#define AO_IR_U1RX_ATTRIBUTE __ISR(_UART1_RX_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_U1RX_PRIO      (4)
#define AO_IR_U1RX_SUBPRIO   (0)
```

## `AO_IR_U1TX`

The interrupt handler attribute.

```c
#define AO_IR_U1TX_ATTRIBUTE __ISR(_UART1_TX_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_U1TX_PRIO      (4)
#define AO_IR_U1TX_SUBPRIO   (0)
```

## `AO_IR_U2E`

The interrupt handler attribute.

```c
#define AO_IR_U2E_ATTRIBUTE __ISR(_UART2_FAULT_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_U2E_PRIO      (4)
#define AO_IR_U2E_SUBPRIO   (0)
```

## `AO_IR_U2RX`

The interrupt handler attribute.

```c
#define AO_IR_U2RX_ATTRIBUTE __ISR(_UART2_RX_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_U2RX_PRIO      (4)
#define AO_IR_U2RX_SUBPRIO   (0)
```

## `AO_IR_U2TX`

The interrupt handler attribute.

```c
#define AO_IR_U2TX_ATTRIBUTE __ISR(_UART2_TX_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_U2TX_PRIO      (4)
#define AO_IR_U2TX_SUBPRIO   (0)
```

## `AO_IR_U3E`

The interrupt handler attribute.

```c
#define AO_IR_U3E_ATTRIBUTE __ISR(_UART3_FAULT_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_U3E_PRIO      (4)
#define AO_IR_U3E_SUBPRIO   (0)
```

## `AO_IR_U3RX`

The interrupt handler attribute.

```c
#define AO_IR_U3RX_ATTRIBUTE __ISR(_UART3_RX_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_U3RX_PRIO      (4)
#define AO_IR_U3RX_SUBPRIO   (0)
```

## `AO_IR_U3TX`

The interrupt handler attribute.

```c
#define AO_IR_U3TX_ATTRIBUTE __ISR(_UART3_TX_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_U3TX_PRIO      (4)
#define AO_IR_U3TX_SUBPRIO   (0)
```

## `AO_IR_U4E`

The interrupt handler attribute.

```c
#define AO_IR_U4E_ATTRIBUTE __ISR(_UART4_FAULT_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_U4E_PRIO      (4)
#define AO_IR_U4E_SUBPRIO   (0)
```

## `AO_IR_U4RX`

The interrupt handler attribute.

```c
#define AO_IR_U4RX_ATTRIBUTE __ISR(_UART4_RX_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_U4RX_PRIO      (4)
#define AO_IR_U4RX_SUBPRIO   (0)
```

## `AO_IR_U4TX`

The interrupt handler attribute.

```c
#define AO_IR_U4TX_ATTRIBUTE __ISR(_UART4_TX_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_U4TX_PRIO      (4)
#define AO_IR_U4TX_SUBPRIO   (0)
```

## `AO_IR_U5E`

The interrupt handler attribute.

```c
#define AO_IR_U5E_ATTRIBUTE __ISR(_UART5_FAULT_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_U5E_PRIO      (4)
#define AO_IR_U5E_SUBPRIO   (0)
```

## `AO_IR_U5RX`

The interrupt handler attribute.

```c
#define AO_IR_U5RX_ATTRIBUTE __ISR(_UART5_RX_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_U5RX_PRIO      (4)
#define AO_IR_U5RX_SUBPRIO   (0)
```

## `AO_IR_U5TX`

The interrupt handler attribute.

```c
#define AO_IR_U5TX_ATTRIBUTE __ISR(_UART5_TX_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_U5TX_PRIO      (4)
#define AO_IR_U5TX_SUBPRIO   (0)
```

## `AO_IR_U6E`

The interrupt handler attribute.

```c
#define AO_IR_U6E_ATTRIBUTE __ISR(_UART6_FAULT_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_U6E_PRIO      (4)
#define AO_IR_U6E_SUBPRIO   (0)
```

## `AO_IR_U6RX`

The interrupt handler attribute.

```c
#define AO_IR_U6RX_ATTRIBUTE __ISR(_UART6_RX_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_U6RX_PRIO      (4)
#define AO_IR_U6RX_SUBPRIO   (0)
```

## `AO_IR_U6TX`

The interrupt handler attribute.

```c
#define AO_IR_U6TX_ATTRIBUTE __ISR(_UART6_TX_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_U6TX_PRIO      (4)
#define AO_IR_U6TX_SUBPRIO   (0)
```

# Functions

## `ao_ir_u1e`

Enable or disable the interrupt.

```c
#define ao_ir_u1e_enable()
#define ao_ir_u1e_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_u1e_request()
#define ao_ir_u1e_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_u1e_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_u1e_is_pending()
```

## `ao_ir_u1rx`

Enable or disable the interrupt.

```c
#define ao_ir_u1rx_enable()
#define ao_ir_u1rx_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_u1rx_request()
#define ao_ir_u1rx_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_u1rx_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_u1rx_is_pending()
```

## `ao_ir_u1tx`

Enable or disable the interrupt.

```c
#define ao_ir_u1tx_enable()
#define ao_ir_u1tx_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_u1tx_request()
#define ao_ir_u1tx_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_u1tx_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_u1tx_is_pending()
```

## `ao_ir_u2e`

Enable or disable the interrupt.

```c
#define ao_ir_u2e_enable()
#define ao_ir_u2e_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_u2e_request()
#define ao_ir_u2e_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_u2e_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_u2e_is_pending()
```

## `ao_ir_u2rx`

Enable or disable the interrupt.

```c
#define ao_ir_u2rx_enable()
#define ao_ir_u2rx_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_u2rx_request()
#define ao_ir_u2rx_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_u2rx_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_u2rx_is_pending()
```

## `ao_ir_u2tx`

Enable or disable the interrupt.

```c
#define ao_ir_u2tx_enable()
#define ao_ir_u2tx_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_u2tx_request()
#define ao_ir_u2tx_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_u2tx_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_u2tx_is_pending()
```

## `ao_ir_u3e`

Enable or disable the interrupt.

```c
#define ao_ir_u3e_enable()
#define ao_ir_u3e_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_u3e_request()
#define ao_ir_u3e_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_u3e_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_u3e_is_pending()
```

## `ao_ir_u3rx`

Enable or disable the interrupt.

```c
#define ao_ir_u3rx_enable()
#define ao_ir_u3rx_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_u3rx_request()
#define ao_ir_u3rx_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_u3rx_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_u3rx_is_pending()
```

## `ao_ir_u3tx`

Enable or disable the interrupt.

```c
#define ao_ir_u3tx_enable()
#define ao_ir_u3tx_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_u3tx_request()
#define ao_ir_u3tx_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_u3tx_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_u3tx_is_pending()
```

## `ao_ir_u4e`

Enable or disable the interrupt.

```c
#define ao_ir_u4e_enable()
#define ao_ir_u4e_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_u4e_request()
#define ao_ir_u4e_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_u4e_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_u4e_is_pending()
```

## `ao_ir_u4rx`

Enable or disable the interrupt.

```c
#define ao_ir_u4rx_enable()
#define ao_ir_u4rx_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_u4rx_request()
#define ao_ir_u4rx_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_u4rx_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_u4rx_is_pending()
```

## `ao_ir_u4tx`

Enable or disable the interrupt.

```c
#define ao_ir_u4tx_enable()
#define ao_ir_u4tx_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_u4tx_request()
#define ao_ir_u4tx_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_u4tx_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_u4tx_is_pending()
```

## `ao_ir_u5e`

Enable or disable the interrupt.

```c
#define ao_ir_u5e_enable()
#define ao_ir_u5e_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_u5e_request()
#define ao_ir_u5e_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_u5e_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_u5e_is_pending()
```

## `ao_ir_u5rx`

Enable or disable the interrupt.

```c
#define ao_ir_u5rx_enable()
#define ao_ir_u5rx_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_u5rx_request()
#define ao_ir_u5rx_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_u5rx_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_u5rx_is_pending()
```

## `ao_ir_u5tx`

Enable or disable the interrupt.

```c
#define ao_ir_u5tx_enable()
#define ao_ir_u5tx_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_u5tx_request()
#define ao_ir_u5tx_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_u5tx_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_u5tx_is_pending()
```

## `ao_ir_u6e`

Enable or disable the interrupt.

```c
#define ao_ir_u6e_enable()
#define ao_ir_u6e_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_u6e_request()
#define ao_ir_u6e_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_u6e_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_u6e_is_pending()
```

## `ao_ir_u6rx`

Enable or disable the interrupt.

```c
#define ao_ir_u6rx_enable()
#define ao_ir_u6rx_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_u6rx_request()
#define ao_ir_u6rx_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_u6rx_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_u6rx_is_pending()
```

## `ao_ir_u6tx`

Enable or disable the interrupt.

```c
#define ao_ir_u6tx_enable()
#define ao_ir_u6tx_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_u6tx_request()
#define ao_ir_u6tx_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_u6tx_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_u6tx_is_pending()
```
