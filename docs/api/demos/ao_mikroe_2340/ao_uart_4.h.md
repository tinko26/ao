---
author: "Stefan Wagner"
date: 2022-09-22
draft: true
permalink: /api/demos/ao_mikroe_2340/ao_uart_4.h/
toc: true
---

# Notes

This module supports baud rates up to 921600 bps.

# Include

```c
#include <ao_mikroe_2674.h>
#include <ao_mikroe_3063.h>
```

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

```c
#include_next <ao_uart_4.h>
```
