---
author: "Stefan Wagner"
date: 2022-08-30
draft: true
permalink: /api/demos/ao_mikroe_2340/ao_uart_2.h/
toc: true
---

# Include

```c
#include <ao_mikroe_2674.h>
#include <ao_mikroe_3063.h>
```

# Configuration

## `AO_UART_2`

Indicates whether the UART module is used.

```c
#define AO_UART_2       \
(                       \
    AO_MIKROE_2674_D || \
    AO_MIKROE_3063_D    \
)
```

# Include Next

```c
#include_next <ao_uart_2.h>
```
