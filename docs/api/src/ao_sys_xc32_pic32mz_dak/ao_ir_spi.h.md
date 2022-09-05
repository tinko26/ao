---
api: true
author: "Stefan Wagner"
date: 2022-09-05
description: "The /src/ao_sys_xc32_pic32mz_dak/ao_ir_spi.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz_dak/ao_ir_spi.h/
subtitle: "SPI interrupts"
title: "ao_ir_spi.h"
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

The interrupt handler attribute.

```c
#define AO_IR_SPI1E_ATTRIBUTE __ISR(_SPI1_FAULT_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_SPI1E_PRIO      (4)
#define AO_IR_SPI1E_SUBPRIO   (0)
```

## `AO_IR_SPI1RX`

The interrupt handler attribute.

```c
#define AO_IR_SPI1RX_ATTRIBUTE __ISR(_SPI1_RX_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_SPI1RX_PRIO      (4)
#define AO_IR_SPI1RX_SUBPRIO   (0)
```

## `AO_IR_SPI1TX`

The interrupt handler attribute.

```c
#define AO_IR_SPI1TX_ATTRIBUTE __ISR(_SPI1_TX_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_SPI1TX_PRIO      (4)
#define AO_IR_SPI1TX_SUBPRIO   (0)
```

## `AO_IR_SPI2E`

The interrupt handler attribute.

```c
#define AO_IR_SPI2E_ATTRIBUTE __ISR(_SPI2_FAULT_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_SPI2E_PRIO      (4)
#define AO_IR_SPI2E_SUBPRIO   (0)
```

## `AO_IR_SPI2RX`

The interrupt handler attribute.

```c
#define AO_IR_SPI2RX_ATTRIBUTE __ISR(_SPI2_RX_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_SPI2RX_PRIO      (4)
#define AO_IR_SPI2RX_SUBPRIO   (0)
```

## `AO_IR_SPI2TX`

The interrupt handler attribute.

```c
#define AO_IR_SPI2TX_ATTRIBUTE __ISR(_SPI2_TX_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_SPI2TX_PRIO      (4)
#define AO_IR_SPI2TX_SUBPRIO   (0)
```

## `AO_IR_SPI3E`

The interrupt handler attribute.

```c
#define AO_IR_SPI3E_ATTRIBUTE __ISR(_SPI3_FAULT_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_SPI3E_PRIO      (4)
#define AO_IR_SPI3E_SUBPRIO   (0)
```

## `AO_IR_SPI3RX`

The interrupt handler attribute.

```c
#define AO_IR_SPI3RX_ATTRIBUTE __ISR(_SPI3_RX_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_SPI3RX_PRIO      (4)
#define AO_IR_SPI3RX_SUBPRIO   (0)
```

## `AO_IR_SPI3TX`

The interrupt handler attribute.

```c
#define AO_IR_SPI3TX_ATTRIBUTE __ISR(_SPI3_TX_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_SPI3TX_PRIO      (4)
#define AO_IR_SPI3TX_SUBPRIO   (0)
```

## `AO_IR_SPI4E`

The interrupt handler attribute.

```c
#define AO_IR_SPI4E_ATTRIBUTE __ISR(_SPI4_FAULT_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_SPI4E_PRIO      (4)
#define AO_IR_SPI4E_SUBPRIO   (0)
```

## `AO_IR_SPI4RX`

The interrupt handler attribute.

```c
#define AO_IR_SPI4RX_ATTRIBUTE __ISR(_SPI4_RX_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_SPI4RX_PRIO      (4)
#define AO_IR_SPI4RX_SUBPRIO   (0)
```

## `AO_IR_SPI4TX`

The interrupt handler attribute.

```c
#define AO_IR_SPI4TX_ATTRIBUTE __ISR(_SPI4_TX_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_SPI4TX_PRIO      (4)
#define AO_IR_SPI4TX_SUBPRIO   (0)
```

## `AO_IR_SPI5E`

The interrupt handler attribute.

```c
#define AO_IR_SPI5E_ATTRIBUTE __ISR(_SPI5_FAULT_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_SPI5E_PRIO      (4)
#define AO_IR_SPI5E_SUBPRIO   (0)
```

## `AO_IR_SPI5RX`

The interrupt handler attribute.

```c
#define AO_IR_SPI5RX_ATTRIBUTE __ISR(_SPI5_RX_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_SPI5RX_PRIO      (4)
#define AO_IR_SPI5RX_SUBPRIO   (0)
```

## `AO_IR_SPI5TX`

The interrupt handler attribute.

```c
#define AO_IR_SPI5TX_ATTRIBUTE __ISR(_SPI5_TX_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_SPI5TX_PRIO      (4)
#define AO_IR_SPI5TX_SUBPRIO   (0)
```

## `AO_IR_SPI6E`

The interrupt handler attribute.

```c
#define AO_IR_SPI6E_ATTRIBUTE __ISR(_SPI6_FAULT_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_SPI6E_PRIO      (4)
#define AO_IR_SPI6E_SUBPRIO   (0)
```

## `AO_IR_SPI6RX`

The interrupt handler attribute.

```c
#define AO_IR_SPI6RX_ATTRIBUTE __ISR(_SPI6_RX_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_SPI6RX_PRIO      (4)
#define AO_IR_SPI6RX_SUBPRIO   (0)
```

## `AO_IR_SPI6TX`

The interrupt handler attribute.

```c
#define AO_IR_SPI6TX_ATTRIBUTE __ISR(_SPI6_TX_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_SPI6TX_PRIO      (4)
#define AO_IR_SPI6TX_SUBPRIO   (0)
```

# Functions

## `ao_ir_spi1e`

Enable or disable the interrupt.

```c
#define ao_ir_spi1e_enable()
#define ao_ir_spi1e_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_spi1e_request()
#define ao_ir_spi1e_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_spi1e_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_spi1e_is_pending()
```

## `ao_ir_spi1rx`

Enable or disable the interrupt.

```c
#define ao_ir_spi1rx_enable()
#define ao_ir_spi1rx_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_spi1rx_request()
#define ao_ir_spi1rx_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_spi1rx_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_spi1rx_is_pending()
```

## `ao_ir_spi1tx`

Enable or disable the interrupt.

```c
#define ao_ir_spi1tx_enable()
#define ao_ir_spi1tx_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_spi1tx_request()
#define ao_ir_spi1tx_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_spi1tx_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_spi1tx_is_pending()
```

## `ao_ir_spi2e`

Enable or disable the interrupt.

```c
#define ao_ir_spi2e_enable()
#define ao_ir_spi2e_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_spi2e_request()
#define ao_ir_spi2e_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_spi2e_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_spi2e_is_pending()
```

## `ao_ir_spi2rx`

Enable or disable the interrupt.

```c
#define ao_ir_spi2rx_enable()
#define ao_ir_spi2rx_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_spi2rx_request()
#define ao_ir_spi2rx_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_spi2rx_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_spi2rx_is_pending()
```

## `ao_ir_spi2tx`

Enable or disable the interrupt.

```c
#define ao_ir_spi2tx_enable()
#define ao_ir_spi2tx_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_spi2tx_request()
#define ao_ir_spi2tx_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_spi2tx_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_spi2tx_is_pending()
```

## `ao_ir_spi3e`

Enable or disable the interrupt.

```c
#define ao_ir_spi3e_enable()
#define ao_ir_spi3e_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_spi3e_request()
#define ao_ir_spi3e_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_spi3e_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_spi3e_is_pending()
```

## `ao_ir_spi3rx`

Enable or disable the interrupt.

```c
#define ao_ir_spi3rx_enable()
#define ao_ir_spi3rx_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_spi3rx_request()
#define ao_ir_spi3rx_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_spi3rx_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_spi3rx_is_pending()
```

## `ao_ir_spi3tx`

Enable or disable the interrupt.

```c
#define ao_ir_spi3tx_enable()
#define ao_ir_spi3tx_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_spi3tx_request()
#define ao_ir_spi3tx_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_spi3tx_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_spi3tx_is_pending()
```

## `ao_ir_spi4e`

Enable or disable the interrupt.

```c
#define ao_ir_spi4e_enable()
#define ao_ir_spi4e_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_spi4e_request()
#define ao_ir_spi4e_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_spi4e_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_spi4e_is_pending()
```

## `ao_ir_spi4rx`

Enable or disable the interrupt.

```c
#define ao_ir_spi4rx_enable()
#define ao_ir_spi4rx_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_spi4rx_request()
#define ao_ir_spi4rx_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_spi4rx_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_spi4rx_is_pending()
```

## `ao_ir_spi4tx`

Enable or disable the interrupt.

```c
#define ao_ir_spi4tx_enable()
#define ao_ir_spi4tx_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_spi4tx_request()
#define ao_ir_spi4tx_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_spi4tx_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_spi4tx_is_pending()
```

## `ao_ir_spi5e`

Enable or disable the interrupt.

```c
#define ao_ir_spi5e_enable()
#define ao_ir_spi5e_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_spi5e_request()
#define ao_ir_spi5e_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_spi5e_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_spi5e_is_pending()
```

## `ao_ir_spi5rx`

Enable or disable the interrupt.

```c
#define ao_ir_spi5rx_enable()
#define ao_ir_spi5rx_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_spi5rx_request()
#define ao_ir_spi5rx_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_spi5rx_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_spi5rx_is_pending()
```

## `ao_ir_spi5tx`

Enable or disable the interrupt.

```c
#define ao_ir_spi5tx_enable()
#define ao_ir_spi5tx_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_spi5tx_request()
#define ao_ir_spi5tx_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_spi5tx_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_spi5tx_is_pending()
```

## `ao_ir_spi6e`

Enable or disable the interrupt.

```c
#define ao_ir_spi6e_enable()
#define ao_ir_spi6e_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_spi6e_request()
#define ao_ir_spi6e_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_spi6e_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_spi6e_is_pending()
```

## `ao_ir_spi6rx`

Enable or disable the interrupt.

```c
#define ao_ir_spi6rx_enable()
#define ao_ir_spi6rx_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_spi6rx_request()
#define ao_ir_spi6rx_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_spi6rx_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_spi6rx_is_pending()
```

## `ao_ir_spi6tx`

Enable or disable the interrupt.

```c
#define ao_ir_spi6tx_enable()
#define ao_ir_spi6tx_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_spi6tx_request()
#define ao_ir_spi6tx_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_spi6tx_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_spi6tx_is_pending()
```
