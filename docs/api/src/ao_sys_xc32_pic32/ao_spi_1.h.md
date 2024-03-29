---
author: "Stefan Wagner"
date: 2022-10-13
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_spi_1.h/
toc: true
---

# Include

| [`ao_spi.h`](ao_spi.h.md) |
| [`ao_sys.h`](ao_sys.h.md) |
| `stdbool.h` |
| `xc.h` |

# Configuration

## `AO_SPI_1`

```c
#define AO_SPI_1 (false)
```

Defines whether to use the module.

# Constants

## `AO_SPI_BAUD_MAX_1`
## `AO_SPI_BAUD_MIN_1`

```c
#define AO_SPI_BAUD_MAX_1 AO_SPI_BAUD_MAX(AO_SYS_CLOCK_SPI1)
#define AO_SPI_BAUD_MIN_1 AO_SPI_BAUD_MIN(AO_SYS_CLOCK_SPI1)
```

The maximum and minimum baud rate, in bits per second.

# Functions

## `ao_spi_baud_1`

```c
#define ao_spi_baud_1(f)   \
{                          \
    ao_spi_baud            \
    (                      \
        ao_spi_reg_1(),    \
        AO_SYS_CLOCK_SPI1, \
        f                  \
    );                     \
}
```

Sets up the baud rate, in bits per second.

## `ao_spi_reg_1`

```c
#define ao_spi_reg_1()     \
(                          \
    (ao_spi_reg_t *)       \
    (                      \
        _SPI1_BASE_ADDRESS \
    )                      \
)
```

Gets the control registers.
