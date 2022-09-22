---
author: "Stefan Wagner"
date: 2022-09-22
draft: true
permalink: /api/demos/ao_mikroe_2800/ao_i2c_4.h/
toc: true
---

# Include

```c
#include <ao_mikroe_1877.h>
#include <ao_mikroe_2950.h>
#include <ao_mikroe_4186.h>
```

# Constants

## `AO_I2C_4`

```c
#define AO_I2C_4        \
(                       \
    AO_MIKROE_1877_1 || \
    AO_MIKROE_2950_1 || \
    AO_MIKROE_4186_1    \
)
```

Indicates whether the module is used.

# Include Next

```c
#include_next <ao_i2c_4.h>
```
