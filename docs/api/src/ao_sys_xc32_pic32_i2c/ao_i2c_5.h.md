---
author: "Stefan Wagner"
date: 2022-09-22
draft: true
permalink: /api/src/ao_sys_xc32_pic32_i2c/ao_i2c_5.h/
toc: true
---

# Include

| [`ao_i2c.h`](ao_i2c.h.md) |
| [`ao_sys.h`](ao_sys.h.md) |
| `stdbool.h` |
| `xc.h` |

# Configuration

## `AO_I2C_5`

```c
#define AO_I2C_5 (false)
```

Defines whether to use the module.

# Functions

## `ao_i2c_baud_5`

```c
#define ao_i2c_baud_5(f)   \
(                          \
    ao_i2c_baud            \
    (                      \
        ao_i2c_reg_5(),    \
        AO_SYS_CLOCK_I2C5, \
        f                  \
    )                      \
)
```

Sets up the baud rate, in bits per second.

## `ao_i2c_reg_5`

```c
#define ao_i2c_reg_5()     \
(                          \
    (ao_i2c_reg_t *)       \
    (                      \
        _I2C5_BASE_ADDRESS \
    )                      \
)
```

Gets the control registers.
