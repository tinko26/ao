---
author: "Stefan Wagner"
date: 2022-09-23
draft: true
permalink: /api/demos/ao_mikroe_2340/ao_uart_4.h/
toc: true
---

# Notes

This module supports baud rates up to 921600 bps.

# Include

| [`ao_mikroe_2674.h`](ao_mikroe_2674.h.md) |
| [`ao_mikroe_3063.h`](ao_mikroe_3063.h.md) |

# Constants

## `AO_UART_4`

```c
#define AO_UART_4       \
(                       \
    AO_MIKROE_2674_A || \
    AO_MIKROE_3063_A    \
)
```

Indicates whether the module is used.

# Include Next

| [`ao_uart_4.h`](../../src/ao_sys_xc32_pic32_uart/ao_uart_4.h.md) |
