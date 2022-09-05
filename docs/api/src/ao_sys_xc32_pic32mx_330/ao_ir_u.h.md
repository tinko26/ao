---
api: true
author: "Stefan Wagner"
date: 2022-09-05
description: "The /src/ao_sys_xc32_pic32mx_330/ao_ir_u.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_330/ao_ir_u.h/
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

## `AO_IR_U1`

The interrupt handler attribute.

```c
#define AO_IR_U1_ATTRIBUTE __ISR(_UART_1_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_U1_PRIO      (4)
#define AO_IR_U1_SUBPRIO   (0)
```

## `AO_IR_U2`

The interrupt handler attribute.

```c
#define AO_IR_U2_ATTRIBUTE __ISR(_UART_2_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_U2_PRIO      (4)
#define AO_IR_U2_SUBPRIO   (0)
```

## `AO_IR_U3`

The interrupt handler attribute.

```c
#define AO_IR_U3_ATTRIBUTE __ISR(_UART_3_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_U3_PRIO      (4)
#define AO_IR_U3_SUBPRIO   (0)
```

## `AO_IR_U4`

The interrupt handler attribute.

```c
#define AO_IR_U4_ATTRIBUTE __ISR(_UART_4_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_U4_PRIO      (4)
#define AO_IR_U4_SUBPRIO   (0)
```

## `AO_IR_U5`

The interrupt handler attribute.

```c
#define AO_IR_U5_ATTRIBUTE __ISR(_UART_5_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_U5_PRIO      (4)
#define AO_IR_U5_SUBPRIO   (0)
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
