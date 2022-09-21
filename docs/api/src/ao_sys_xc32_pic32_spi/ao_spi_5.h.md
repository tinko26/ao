---
author: "Stefan Wagner"
date: 2022-09-20
draft: true
permalink: /api/src/ao_sys_xc32_pic32_spi/ao_spi_5.h/
toc: true
---

# Include

```c
#include <ao_spi.h>
#include <ao_sys.h>
#include <stdbool.h>
#include <xc.h>
```

# Identifier

```c
#define AO_SPI_5
```

# Constants

## `AO_SPI_5`

```c
#define AO_SPI_5 (false)
```

Indicates whether the module is available.

## `AO_SPI_BAUD_MAX_5`
## `AO_SPI_BAUD_MIN_5`

```c
#define AO_SPI_BAUD_MAX_5 AO_SPI_BAUD_MAX(AO_SYS_CLOCK_SPI5)
#define AO_SPI_BAUD_MIN_5 AO_SPI_BAUD_MIN(AO_SYS_CLOCK_SPI5)
```

The maximum and minimum baud rate, in bits per second.

# Functions

## `ao_spi_baud_5`

```c
#define ao_spi_baud_5(f)   \
{                          \
    ao_spi_baud            \
    (                      \
        ao_spi_reg_5(),    \
        AO_SYS_CLOCK_SPI5, \
        f                  \
    );                     \
}
```

Sets up the baud rate, in bits per second.

## `ao_spi_reg_5`

```c
#define ao_spi_reg_5()     \
(                          \
    (ao_spi_reg_t *)       \
    (                      \
        _SPI5_BASE_ADDRESS \
    )                      \
)
```

Gets the control registers.
