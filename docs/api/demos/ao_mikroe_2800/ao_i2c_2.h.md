---
author: "Stefan Wagner"
date: 2022-10-13
draft: true
permalink: /api/demos/ao_mikroe_2800/ao_i2c_2.h/
toc: true
---

# Include

| [`ao_mikroe_1877.h`](ao_mikroe_1877.h.md) |
| [`ao_mikroe_2950.h`](ao_mikroe_2950.h.md) |
| [`ao_mikroe_4186.h`](ao_mikroe_4186.h.md) |

# Constants

## `AO_I2C_2`

```c
#define AO_I2C_2        \
(                       \
    AO_MIKROE_1877_2 || \
    AO_MIKROE_2950_2 || \
    AO_MIKROE_4186_2    \
)
```

Indicates whether the module is used.

# Include Next

| [`ao_i2c_2.h`](../../src/ao_sys_xc32_pic32/ao_i2c_2.h.md) |
