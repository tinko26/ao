---
author: "Stefan Wagner"
date: 2022-08-30
draft: true
permalink: /api/demos/ao_mikroe_2340/ao_uart_3.h/
toc: true
---

# Include

```c
#include <ao_mikroe_2674.h>
#include <ao_mikroe_3063.h>
```

# Configuration

```c
#define AO_UART_3       \
(                       \
    AO_MIKROE_2674_B || \
    AO_MIKROE_3063_B    \
)
```

# Include Next

```c
#include_next <ao_uart_3.h>
```
