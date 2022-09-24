---
author: "Stefan Wagner"
date: 2022-09-22
draft: true
permalink: /api/src/ao_sys_xc32_pic32_i2c/ao_i2c_1.h/
toc: true
---

# Include

| [`ao_i2c.h`](ao_i2c.h.md) |
| [`ao_sys.h`](ao_sys.h.md) |
| `stdbool.h` |
| `xc.h` |

# Identifier

```c
#define AO_I2C_1
```

# Configuration

## `AO_I2C_1`

```c
#define AO_I2C_1 (false)
```

Defines whether to use the module.

# Functions

## `ao_i2c_baud_1`

```c
#define ao_i2c_baud_1(f)   \
(                          \
    ao_i2c_baud            \
    (                      \
        ao_i2c_reg_1(),    \
        AO_SYS_CLOCK_I2C1, \
        f                  \
    )                      \
)
```

Sets up the baud rate, in bits per second.

## `ao_i2c_reg_1`

```c
#define ao_i2c_reg_1()     \
(                          \
    (ao_i2c_reg_t *)       \
    (                      \
        _I2C1_BASE_ADDRESS \
    )                      \
)
```

Gets the control registers.
