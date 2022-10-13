---
author: "Stefan Wagner"
date: 2022-10-13
draft: true
permalink: /api/demos/ao_mikroe_2340/ao_uart_1.h/
toc: true
---

# Notes

This module supports baud rates up to 921600 bps.

# Include

| [`ao_mikroe_2674.h`](ao_mikroe_2674.h.md) |
| [`ao_mikroe_3063.h`](ao_mikroe_3063.h.md) |

# Constants

## `AO_UART_1`

```c
#define AO_UART_1       \
(                       \
    AO_MIKROE_2674_C || \
    AO_MIKROE_3063_C    \
)
```

Indicates whether the module is used.

# Include Next

| [`ao_uart_1.h`](../../src/ao_sys_xc32_pic32/ao_uart_1.h.md) |
