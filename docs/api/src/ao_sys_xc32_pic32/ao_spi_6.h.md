---
author: "Stefan Wagner"
date: 2022-10-13
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_spi_6.h/
toc: true
---

# Include

| [`ao_spi.h`](ao_spi.h.md) |
| [`ao_sys.h`](ao_sys.h.md) |
| `stdbool.h` |
| `xc.h` |

# Configuration

## `AO_SPI_6`

```c
#define AO_SPI_6 (false)
```

Defines whether to use the module.

# Constants

## `AO_SPI_BAUD_MAX_6`
## `AO_SPI_BAUD_MIN_6`

```c
#define AO_SPI_BAUD_MAX_6 AO_SPI_BAUD_MAX(AO_SYS_CLOCK_SPI6)
#define AO_SPI_BAUD_MIN_6 AO_SPI_BAUD_MIN(AO_SYS_CLOCK_SPI6)
```

The maximum and minimum baud rate, in bits per second.

# Functions

## `ao_spi_baud_6`

```c
#define ao_spi_baud_6(f)   \
{                          \
    ao_spi_baud            \
    (                      \
        ao_spi_reg_6(),    \
        AO_SYS_CLOCK_SPI6, \
        f                  \
    );                     \
}
```

Sets up the baud rate, in bits per second.

## `ao_spi_reg_6`

```c
#define ao_spi_reg_6()     \
(                          \
    (ao_spi_reg_t *)       \
    (                      \
        _SPI6_BASE_ADDRESS \
    )                      \
)
```

Gets the control registers.
