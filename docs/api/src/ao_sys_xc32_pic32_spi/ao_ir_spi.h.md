---
api: true
author: "Stefan Wagner"
date: 2022-09-05
description: "The /src/ao_sys_xc32_pic32_spi/ao_ir_spi.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32_spi/ao_ir_spi.h/
subtitle: "SPI interrupts"
title: "ao_ir_spi.h"
toc: true
---

# Include

```c
#include <stdbool.h>
```

# Functions

## SPI 1 Error Interrupt

Enable or disable the interrupt.

```c
void ao_ir_spi1e_enable();
void ao_ir_spi1e_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_spi1e_request();
void ao_ir_spi1e_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_spi1e_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_spi1e_is_pending();
```

## SPI 1 Receive Interrupt

Enable or disable the interrupt.

```c
void ao_ir_spi1rx_enable();
void ao_ir_spi1rx_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_spi1rx_request();
void ao_ir_spi1rx_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_spi1rx_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_spi1rx_is_pending();
```

## SPI 1 Transmit Interrupt

Enable or disable the interrupt.

```c
void ao_ir_spi1tx_enable();
void ao_ir_spi1tx_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_spi1tx_request();
void ao_ir_spi1tx_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_spi1tx_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_spi1tx_is_pending();
```

## SPI 2 Error Interrupt

Enable or disable the interrupt.

```c
void ao_ir_spi2e_enable();
void ao_ir_spi2e_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_spi2e_request();
void ao_ir_spi2e_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_spi2e_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_spi2e_is_pending();
```

## SPI 2 Receive Interrupt

Enable or disable the interrupt.

```c
void ao_ir_spi2rx_enable();
void ao_ir_spi2rx_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_spi2rx_request();
void ao_ir_spi2rx_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_spi2rx_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_spi2rx_is_pending();
```

## SPI 2 Transmit Interrupt

Enable or disable the interrupt.

```c
void ao_ir_spi2tx_enable();
void ao_ir_spi2tx_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_spi2tx_request();
void ao_ir_spi2tx_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_spi2tx_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_spi2tx_is_pending();
```

## SPI 3 Error Interrupt

Enable or disable the interrupt.

```c
void ao_ir_spi3e_enable();
void ao_ir_spi3e_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_spi3e_request();
void ao_ir_spi3e_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_spi3e_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_spi3e_is_pending();
```

## SPI 3 Receive Interrupt

Enable or disable the interrupt.

```c
void ao_ir_spi3rx_enable();
void ao_ir_spi3rx_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_spi3rx_request();
void ao_ir_spi3rx_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_spi3rx_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_spi3rx_is_pending();
```

## SPI 3 Transmit Interrupt

Enable or disable the interrupt.

```c
void ao_ir_spi3tx_enable();
void ao_ir_spi3tx_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_spi3tx_request();
void ao_ir_spi3tx_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_spi3tx_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_spi3tx_is_pending();
```

## SPI 4 Error Interrupt

Enable or disable the interrupt.

```c
void ao_ir_spi4e_enable();
void ao_ir_spi4e_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_spi4e_request();
void ao_ir_spi4e_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_spi4e_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_spi4e_is_pending();
```

## SPI 4 Receive Interrupt

Enable or disable the interrupt.

```c
void ao_ir_spi4rx_enable();
void ao_ir_spi4rx_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_spi4rx_request();
void ao_ir_spi4rx_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_spi4rx_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_spi4rx_is_pending();
```

## SPI 4 Transmit Interrupt

Enable or disable the interrupt.

```c
void ao_ir_spi4tx_enable();
void ao_ir_spi4tx_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_spi4tx_request();
void ao_ir_spi4tx_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_spi4tx_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_spi4tx_is_pending();
```

## SPI 5 Error Interrupt

Enable or disable the interrupt.

```c
void ao_ir_spi5e_enable();
void ao_ir_spi5e_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_spi5e_request();
void ao_ir_spi5e_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_spi5e_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_spi5e_is_pending();
```

## SPI 5 Receive Interrupt

Enable or disable the interrupt.

```c
void ao_ir_spi5rx_enable();
void ao_ir_spi5rx_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_spi5rx_request();
void ao_ir_spi5rx_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_spi5rx_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_spi5rx_is_pending();
```

## SPI 5 Transmit Interrupt

Enable or disable the interrupt.

```c
void ao_ir_spi5tx_enable();
void ao_ir_spi5tx_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_spi5tx_request();
void ao_ir_spi5tx_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_spi5tx_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_spi5tx_is_pending();
```

## SPI 6 Error Interrupt

Enable or disable the interrupt.

```c
void ao_ir_spi6e_enable();
void ao_ir_spi6e_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_spi6e_request();
void ao_ir_spi6e_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_spi6e_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_spi6e_is_pending();
```

## SPI 6 Receive Interrupt

Enable or disable the interrupt.

```c
void ao_ir_spi6rx_enable();
void ao_ir_spi6rx_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_spi6rx_request();
void ao_ir_spi6rx_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_spi6rx_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_spi6rx_is_pending();
```

## SPI 6 Transmit Interrupt

Enable or disable the interrupt.

```c
void ao_ir_spi6tx_enable();
void ao_ir_spi6tx_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_spi6tx_request();
void ao_ir_spi6tx_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_spi6tx_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_spi6tx_is_pending();
```
