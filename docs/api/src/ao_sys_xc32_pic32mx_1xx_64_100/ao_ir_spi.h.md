---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mx_1xx_64_100/ao_ir_spi.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_1xx_64_100/ao_ir_spi.h/
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

# Constants

```c
#define AO_IR_SPI1_ATTRIBUTE __ISR(_SPI_1_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_SPI1_PRIO (4)
```

```c
#define AO_IR_SPI1_SUBPRIO (0)
```

```c
#define AO_IR_SPI2_ATTRIBUTE __ISR(_SPI_2_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_SPI2_PRIO (4)
```

```c
#define AO_IR_SPI2_SUBPRIO (0)
```

```c
#define AO_IR_SPI3_ATTRIBUTE __ISR(_SPI_3_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_SPI3_PRIO (4)
```

```c
#define AO_IR_SPI3_SUBPRIO (0)
```

```c
#define AO_IR_SPI4_ATTRIBUTE __ISR(_SPI_4_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_SPI4_PRIO (4)
```

```c
#define AO_IR_SPI4_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_spi1e_disable()
```

```c
#define ao_ir_spi1e_enable()
```

```c
#define ao_ir_spi1e_is_enabled()
```

```c
#define ao_ir_spi1e_is_pending()
```

```c
#define ao_ir_spi1e_reply()
```

```c
#define ao_ir_spi1e_request()
```

```c
#define ao_ir_spi1rx_disable()
```

```c
#define ao_ir_spi1rx_enable()
```

```c
#define ao_ir_spi1rx_is_enabled()
```

```c
#define ao_ir_spi1rx_is_pending()
```

```c
#define ao_ir_spi1rx_reply()
```

```c
#define ao_ir_spi1rx_request()
```

```c
#define ao_ir_spi1tx_disable()
```

```c
#define ao_ir_spi1tx_enable()
```

```c
#define ao_ir_spi1tx_is_enabled()
```

```c
#define ao_ir_spi1tx_is_pending()
```

```c
#define ao_ir_spi1tx_reply()
```

```c
#define ao_ir_spi1tx_request()
```

```c
#define ao_ir_spi2e_disable()
```

```c
#define ao_ir_spi2e_enable()
```

```c
#define ao_ir_spi2e_is_enabled()
```

```c
#define ao_ir_spi2e_is_pending()
```

```c
#define ao_ir_spi2e_reply()
```

```c
#define ao_ir_spi2e_request()
```

```c
#define ao_ir_spi2rx_disable()
```

```c
#define ao_ir_spi2rx_enable()
```

```c
#define ao_ir_spi2rx_is_enabled()
```

```c
#define ao_ir_spi2rx_is_pending()
```

```c
#define ao_ir_spi2rx_reply()
```

```c
#define ao_ir_spi2rx_request()
```

```c
#define ao_ir_spi2tx_disable()
```

```c
#define ao_ir_spi2tx_enable()
```

```c
#define ao_ir_spi2tx_is_enabled()
```

```c
#define ao_ir_spi2tx_is_pending()
```

```c
#define ao_ir_spi2tx_reply()
```

```c
#define ao_ir_spi2tx_request()
```

```c
#define ao_ir_spi3e_disable()
```

```c
#define ao_ir_spi3e_enable()
```

```c
#define ao_ir_spi3e_is_enabled()
```

```c
#define ao_ir_spi3e_is_pending()
```

```c
#define ao_ir_spi3e_reply()
```

```c
#define ao_ir_spi3e_request()
```

```c
#define ao_ir_spi3rx_disable()
```

```c
#define ao_ir_spi3rx_enable()
```

```c
#define ao_ir_spi3rx_is_enabled()
```

```c
#define ao_ir_spi3rx_is_pending()
```

```c
#define ao_ir_spi3rx_reply()
```

```c
#define ao_ir_spi3rx_request()
```

```c
#define ao_ir_spi3tx_disable()
```

```c
#define ao_ir_spi3tx_enable()
```

```c
#define ao_ir_spi3tx_is_enabled()
```

```c
#define ao_ir_spi3tx_is_pending()
```

```c
#define ao_ir_spi3tx_reply()
```

```c
#define ao_ir_spi3tx_request()
```

```c
#define ao_ir_spi4e_disable()
```

```c
#define ao_ir_spi4e_enable()
```

```c
#define ao_ir_spi4e_is_enabled()
```

```c
#define ao_ir_spi4e_is_pending()
```

```c
#define ao_ir_spi4e_reply()
```

```c
#define ao_ir_spi4e_request()
```

```c
#define ao_ir_spi4rx_disable()
```

```c
#define ao_ir_spi4rx_enable()
```

```c
#define ao_ir_spi4rx_is_enabled()
```

```c
#define ao_ir_spi4rx_is_pending()
```

```c
#define ao_ir_spi4rx_reply()
```

```c
#define ao_ir_spi4rx_request()
```

```c
#define ao_ir_spi4tx_disable()
```

```c
#define ao_ir_spi4tx_enable()
```

```c
#define ao_ir_spi4tx_is_enabled()
```

```c
#define ao_ir_spi4tx_is_pending()
```

```c
#define ao_ir_spi4tx_reply()
```

```c
#define ao_ir_spi4tx_request()
```
