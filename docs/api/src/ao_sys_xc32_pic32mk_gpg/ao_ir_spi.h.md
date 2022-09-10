---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gpg/ao_ir_spi.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_SPI1E`

```c
#define AO_IR_SPI1E_ATTRIBUTE __ISR(_SPI1_FAULT_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_SPI1E_PRIO    (4)
#define AO_IR_SPI1E_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_SPI1RX`

```c
#define AO_IR_SPI1RX_ATTRIBUTE __ISR(_SPI1_RX_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_SPI1RX_PRIO    (4)
#define AO_IR_SPI1RX_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_SPI1TX`

```c
#define AO_IR_SPI1TX_ATTRIBUTE __ISR(_SPI1_TX_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_SPI1TX_PRIO    (4)
#define AO_IR_SPI1TX_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_SPI2E`

```c
#define AO_IR_SPI2E_ATTRIBUTE __ISR(_SPI2_FAULT_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_SPI2E_PRIO    (4)
#define AO_IR_SPI2E_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_SPI2RX`

```c
#define AO_IR_SPI2RX_ATTRIBUTE __ISR(_SPI2_RX_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_SPI2RX_PRIO    (4)
#define AO_IR_SPI2RX_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_SPI2TX`

```c
#define AO_IR_SPI2TX_ATTRIBUTE __ISR(_SPI2_TX_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_SPI2TX_PRIO    (4)
#define AO_IR_SPI2TX_SUBPRIO (0)
```

The interrupt priority and subpriority.

# Functions

## `ao_ir_spi1e`

```c
#define ao_ir_spi1e_enable()
#define ao_ir_spi1e_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_spi1e_request()
#define ao_ir_spi1e_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_spi1e_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_spi1e_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_spi1rx`

```c
#define ao_ir_spi1rx_enable()
#define ao_ir_spi1rx_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_spi1rx_request()
#define ao_ir_spi1rx_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_spi1rx_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_spi1rx_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_spi1tx`

```c
#define ao_ir_spi1tx_enable()
#define ao_ir_spi1tx_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_spi1tx_request()
#define ao_ir_spi1tx_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_spi1tx_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_spi1tx_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_spi2e`

```c
#define ao_ir_spi2e_enable()
#define ao_ir_spi2e_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_spi2e_request()
#define ao_ir_spi2e_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_spi2e_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_spi2e_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_spi2rx`

```c
#define ao_ir_spi2rx_enable()
#define ao_ir_spi2rx_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_spi2rx_request()
#define ao_ir_spi2rx_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_spi2rx_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_spi2rx_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_spi2tx`

```c
#define ao_ir_spi2tx_enable()
#define ao_ir_spi2tx_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_spi2tx_request()
#define ao_ir_spi2tx_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_spi2tx_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_spi2tx_is_pending()
```

Checks whether the interrupt is pending.
