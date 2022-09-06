---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_1xx_64_100/ao_ir_spi.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_SPI1`

The interrupt handler attribute.

```c
#define AO_IR_SPI1_ATTRIBUTE __ISR(_SPI_1_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_SPI1_PRIO      (4)
#define AO_IR_SPI1_SUBPRIO   (0)
```

## `AO_IR_SPI2`

The interrupt handler attribute.

```c
#define AO_IR_SPI2_ATTRIBUTE __ISR(_SPI_2_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_SPI2_PRIO      (4)
#define AO_IR_SPI2_SUBPRIO   (0)
```

## `AO_IR_SPI3`

The interrupt handler attribute.

```c
#define AO_IR_SPI3_ATTRIBUTE __ISR(_SPI_3_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_SPI3_PRIO      (4)
#define AO_IR_SPI3_SUBPRIO   (0)
```

## `AO_IR_SPI4`

The interrupt handler attribute.

```c
#define AO_IR_SPI4_ATTRIBUTE __ISR(_SPI_4_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_SPI4_PRIO      (4)
#define AO_IR_SPI4_SUBPRIO   (0)
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
