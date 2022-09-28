---
author: "Stefan Wagner"
date: 2022-09-22
draft: true
permalink: /api/src/ao_sys_xc32_pic32_spi/ao_spi_2.h/
toc: true
---

# Include

| [`ao_spi.h`](ao_spi.h.md) |
| [`ao_sys.h`](ao_sys.h.md) |
| `stdbool.h` |
| `xc.h` |

# Configuration

## `AO_SPI_2`

```c
#define AO_SPI_2 (false)
```

Defines whether to use the module.

# Constants

## `AO_SPI_BAUD_MAX_2`
## `AO_SPI_BAUD_MIN_2`

```c
#define AO_SPI_BAUD_MAX_2 AO_SPI_BAUD_MAX(AO_SYS_CLOCK_SPI2)
#define AO_SPI_BAUD_MIN_2 AO_SPI_BAUD_MIN(AO_SYS_CLOCK_SPI2)
```

The maximum and minimum baud rate, in bits per second.

# Functions

## `ao_spi_baud_2`

```c
#define ao_spi_baud_2(f)   \
{                          \
    ao_spi_baud            \
    (                      \
        ao_spi_reg_2(),    \
        AO_SYS_CLOCK_SPI2, \
        f                  \
    );                     \
}
```

Sets up the baud rate, in bits per second.

## `ao_spi_reg_2`

```c
#define ao_spi_reg_2()     \
(                          \
    (ao_spi_reg_t *)       \
    (                      \
        _SPI2_BASE_ADDRESS \
    )                      \
)
```

Gets the control registers.
