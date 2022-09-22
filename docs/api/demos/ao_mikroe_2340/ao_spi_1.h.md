---
author: "Stefan Wagner"
date: 2022-09-22
draft: true
permalink: /api/demos/ao_mikroe_2340/ao_spi_1.h/
toc: true
---

# Include

```c
#include <ao_mikroe_2935.h>
```

# Constants

## `AO_SPI_1`

```c
#define AO_SPI_1        \
(                       \
    AO_MIKROE_2935_C || \
    AO_MIKROE_2935_D    \
)
```

Indicates whether the module is used.

# Include Next

```c
#include_next <ao_spi_1.h>
```
