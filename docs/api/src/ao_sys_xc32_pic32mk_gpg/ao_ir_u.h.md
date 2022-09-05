---
api: true
author: "Stefan Wagner"
date: 2022-09-05
description: "The /src/ao_sys_xc32_pic32mk_gpg/ao_ir_u.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gpg/ao_ir_u.h/
subtitle: "UART interrupts"
title: "ao_ir_u.h"
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
