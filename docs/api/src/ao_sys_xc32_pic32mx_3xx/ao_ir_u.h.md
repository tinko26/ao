---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_3xx/ao_ir_u.h/
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

```c
#define AO_IR_U1_ATTRIBUTE __ISR(_UART_1_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_U1_PRIO    (4)
#define AO_IR_U1_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_U2`

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

## `ao_ir_u1e`

```c
#define ao_ir_u1e_enable()
#define ao_ir_u1e_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_u1e_request()
#define ao_ir_u1e_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u1e_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u1e_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_u1rx`

```c
#define ao_ir_u1rx_enable()
#define ao_ir_u1rx_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_u1rx_request()
#define ao_ir_u1rx_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u1rx_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u1rx_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_u1tx`

```c
#define ao_ir_u1tx_enable()
#define ao_ir_u1tx_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_u1tx_request()
#define ao_ir_u1tx_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u1tx_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u1tx_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_u2e`

```c
#define ao_ir_u2e_enable()
#define ao_ir_u2e_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_u2e_request()
#define ao_ir_u2e_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u2e_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u2e_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_u2rx`

```c
#define ao_ir_u2rx_enable()
#define ao_ir_u2rx_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_u2rx_request()
#define ao_ir_u2rx_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u2rx_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u2rx_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_u2tx`

```c
#define ao_ir_u2tx_enable()
#define ao_ir_u2tx_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_u2tx_request()
#define ao_ir_u2tx_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_u2tx_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_u2tx_is_pending()
```

Checks whether the interrupt is pending.
