---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mk_gpg/ao_ir_spi.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gpg/ao_ir_spi.h/
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
#define AO_IR_SPI1E_ATTRIBUTE __ISR(_SPI1_FAULT_VECTOR, IPL4SRS)
```

```c
#define AO_IR_SPI1E_PRIO (4)
```

```c
#define AO_IR_SPI1E_SUBPRIO (0)
```

```c
#define AO_IR_SPI1RX_ATTRIBUTE __ISR(_SPI1_RX_VECTOR, IPL4SRS)
```

```c
#define AO_IR_SPI1RX_PRIO (4)
```

```c
#define AO_IR_SPI1RX_SUBPRIO (0)
```

```c
#define AO_IR_SPI1TX_ATTRIBUTE __ISR(_SPI1_TX_VECTOR, IPL4SRS)
```

```c
#define AO_IR_SPI1TX_PRIO (4)
```

```c
#define AO_IR_SPI1TX_SUBPRIO (0)
```

```c
#define AO_IR_SPI2E_ATTRIBUTE __ISR(_SPI2_FAULT_VECTOR, IPL4SRS)
```

```c
#define AO_IR_SPI2E_PRIO (4)
```

```c
#define AO_IR_SPI2E_SUBPRIO (0)
```

```c
#define AO_IR_SPI2RX_ATTRIBUTE __ISR(_SPI2_RX_VECTOR, IPL4SRS)
```

```c
#define AO_IR_SPI2RX_PRIO (4)
```

```c
#define AO_IR_SPI2RX_SUBPRIO (0)
```

```c
#define AO_IR_SPI2TX_ATTRIBUTE __ISR(_SPI2_TX_VECTOR, IPL4SRS)
```

```c
#define AO_IR_SPI2TX_PRIO (4)
```

```c
#define AO_IR_SPI2TX_SUBPRIO (0)
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
