---
author: "Stefan Wagner"
date: 2022-09-22
draft: true
permalink: /api/demos/ao_mikroe_2340/ao_i2c_2.h/
toc: true
---

# Include

```c
#include <ao_mikroe_1877.h>
#include <ao_mikroe_2950.h>
#include <ao_mikroe_4186.h>
```

# Constants

## `AO_I2C_2`

```c
#define AO_I2C_2        \
(                       \
    AO_MIKROE_1877_A || \
    AO_MIKROE_1877_B || \
    AO_MIKROE_2950_A || \
    AO_MIKROE_2950_B || \
    AO_MIKROE_4186_A || \
    AO_MIKROE_4186_B    \
)
```

Indicates whether the module is used.

# Include Next

```c
#include_next <ao_i2c_2.h>
```
