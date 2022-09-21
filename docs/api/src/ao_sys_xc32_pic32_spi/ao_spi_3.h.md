---
author: "Stefan Wagner"
date: 2022-09-20
draft: true
permalink: /api/src/ao_sys_xc32_pic32_spi/ao_spi_3.h/
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
#define AO_SPI_3
```

# Constants

## `AO_SPI_3`

```c
#define AO_SPI_3 (false)
```

Indicates whether the module is available.

## `AO_SPI_BAUD_MAX_3`
## `AO_SPI_BAUD_MIN_3`

```c
#define AO_SPI_BAUD_MAX_3 AO_SPI_BAUD_MAX(AO_SYS_CLOCK_SPI3)
#define AO_SPI_BAUD_MIN_3 AO_SPI_BAUD_MIN(AO_SYS_CLOCK_SPI3)
```

The maximum and minimum baud rate, in bits per second.

# Functions

## `ao_spi_baud_3`

```c
#define ao_spi_baud_3(f)   \
{                          \
    ao_spi_baud            \
    (                      \
        ao_spi_reg_3(),    \
        AO_SYS_CLOCK_SPI3, \
        f                  \
    );                     \
}
```

Sets up the baud rate, in bits per second.

## `ao_spi_reg_3`

```c
#define ao_spi_reg_3()     \
(                          \
    (ao_spi_reg_t *)       \
    (                      \
        _SPI3_BASE_ADDRESS \
    )                      \
)
```

Gets the control registers.
