---
author: "Stefan Wagner"
date: 2022-08-30
draft: true
permalink: /api/demos/ao_mikroe_2800/ao_uart_3.h/
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

```c
#include_next <ao_uart_3.h>
```
