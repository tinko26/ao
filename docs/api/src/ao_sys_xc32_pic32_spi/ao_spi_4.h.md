---
author: "Stefan Wagner"
date: 2022-09-22
draft: true
permalink: /api/src/ao_sys_xc32_pic32_spi/ao_spi_4.h/
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
#define AO_SPI_4
```

# Configuration

## `AO_SPI_4`

```c
#define AO_SPI_4 (false)
```

Defines whether to use the module.

# Constants

## `AO_SPI_BAUD_MAX_4`
## `AO_SPI_BAUD_MIN_4`

```c
#define AO_SPI_BAUD_MAX_4 AO_SPI_BAUD_MAX(AO_SYS_CLOCK_SPI4)
#define AO_SPI_BAUD_MIN_4 AO_SPI_BAUD_MIN(AO_SYS_CLOCK_SPI4)
```

The maximum and minimum baud rate, in bits per second.

# Functions

## `ao_spi_baud_4`

```c
#define ao_spi_baud_4(f)   \
{                          \
    ao_spi_baud            \
    (                      \
        ao_spi_reg_4(),    \
        AO_SYS_CLOCK_SPI4, \
        f                  \
    );                     \
}
```

Sets up the baud rate, in bits per second.

## `ao_spi_reg_4`

```c
#define ao_spi_reg_4()     \
(                          \
    (ao_spi_reg_t *)       \
    (                      \
        _SPI4_BASE_ADDRESS \
    )                      \
)
```

Gets the control registers.
