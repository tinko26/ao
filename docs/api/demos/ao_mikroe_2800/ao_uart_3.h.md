---
author: "Stefan Wagner"
date: 2022-09-23
draft: true
permalink: /api/demos/ao_mikroe_2800/ao_uart_3.h/
toc: true
---

# Notes

This module supports baud rates up to 921600 bps.

# Include

[`ao_mikroe_2674.h`](ao_mikroe_2674.h.md) <br/>
[`ao_mikroe_3063.h`](ao_mikroe_3063.h.md)

# Constants

## `AO_UART_3`

```c
#define AO_UART_3       \
(                       \
    AO_MIKROE_2674_2 || \
    AO_MIKROE_3063_2    \
)
```

Indicates whether the module is used.

# Include Next

[`ao_uart_3.h`](../../src/ao_sys_xc32_pic32_uart/ao_uart_3.h.md)
