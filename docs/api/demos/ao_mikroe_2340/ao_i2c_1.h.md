---
author: "Stefan Wagner"
date: 2022-09-22
draft: true
permalink: /api/demos/ao_mikroe_2340/ao_i2c_1.h/
toc: true
---

# Include

| [`ao_mikroe_1877.h`](ao_mikroe_1877.h.md) |
| [`ao_mikroe_2950.h`](ao_mikroe_2950.h.md) |
| [`ao_mikroe_4186.h`](ao_mikroe_4186.h.md) |

# Constants

## `AO_I2C_1`

```c
#define AO_I2C_1        \
(                       \
    AO_MIKROE_1877_C || \
    AO_MIKROE_1877_D || \
    AO_MIKROE_2950_C || \
    AO_MIKROE_2950_D || \
    AO_MIKROE_4186_C || \
    AO_MIKROE_4186_D    \
)
```

Indicates whether the module is used.

# Include Next

| [`ao_i2c_1.h`](../../src/ao_sys_xc32_pic32_i2c/ao_i2c_1.h.md) |
