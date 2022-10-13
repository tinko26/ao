---
author: "Stefan Wagner"
date: 2022-10-13
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_i2c_2.h/
toc: true
---

# Include

| [`ao_i2c.h`](ao_i2c.h.md) |
| [`ao_sys.h`](ao_sys.h.md) |
| `stdbool.h` |
| `xc.h` |

# Configuration

## `AO_I2C_2`

```c
#define AO_I2C_2 (false)
```

Defines whether to use the module.

# Functions

## `ao_i2c_baud_2`

```c
#define ao_i2c_baud_2(f)   \
(                          \
    ao_i2c_baud            \
    (                      \
        ao_i2c_reg_2(),    \
        AO_SYS_CLOCK_I2C2, \
        f                  \
    )                      \
)
```

Sets up the baud rate, in bits per second.

## `ao_i2c_reg_2`

```c
#define ao_i2c_reg_2()     \
(                          \
    (ao_i2c_reg_t *)       \
    (                      \
        _I2C2_BASE_ADDRESS \
    )                      \
)
```

Gets the control registers.
