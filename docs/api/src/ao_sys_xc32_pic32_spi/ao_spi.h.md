---
author: "Stefan Wagner"
date: 2022-09-20
draft: true
permalink: /api/src/ao_sys_xc32_pic32_spi/ao_spi.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <stdint.h>
```

# Identifier

```c
#define AO_SPI
```

# Constants

## `AO_SPI_BRG_BITS`

```c
#define AO_SPI_BRG_BITS (13)
```

The size of the `SPIxBRG.BRG` field, in bits.

## `AO_SPI_BRG_MAX`
## `AO_SPI_BRG_MIN`

```c
#define AO_SPI_BRG_MAX ((1 << (AO_SPI_BRG_BITS)) - 1)
#define AO_SPI_BRG_MIN (0)
```

The maximum and minimum value, respectively, of the `SPIxBRG.BRG` field.

## `AO_SPI_ENHBUF`

```c
#define AO_SPI_ENHBUF (true)
```

Indicates whether the `SPIxCON.ENHBUF` field is available.

# Types

## `ao_spi_reg_t`

```c
typedef struct ao_spi_reg_t ao_spi_reg_t;
```

This type represents the control register set.

## `ao_spi_reg_*_t`

```c
typedef struct ao_spi_reg_brg_t  ao_spi_reg_brg_t;
typedef struct ao_spi_reg_buf_t  ao_spi_reg_buf_t;
typedef struct ao_spi_reg_con_t  ao_spi_reg_con_t;
typedef struct ao_spi_reg_con2_t ao_spi_reg_con2_t;
typedef struct ao_spi_reg_stat_t ao_spi_reg_stat_t;
```

These types represent individual control registers.

# Structs

## `ao_spi_reg_t`

```c
struct ao_spi_reg_t
{
    ao_spi_reg_con_t  con;
    ao_spi_reg_stat_t stat;
    ao_spi_reg_buf_t  buf;
    ao_spi_reg_brg_t  brg;
    ao_spi_reg_con2_t con2;
};
```

## `ao_spi_reg_brg_t`

```c
struct ao_spi_reg_brg_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile brg : 13;
        }                     bits;
    };
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

## `ao_spi_reg_buf_t`

```c
struct ao_spi_reg_buf_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile data : 32;
        }                     bits;
    };
    uint32_t         volatile      : 32;
    uint32_t         volatile      : 32;
    uint32_t         volatile      : 32;
};
```

## `ao_spi_reg_con_t`

```c
struct ao_spi_reg_con_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile srxisel : 2;
            uint32_t volatile stxisel : 2;
            uint32_t volatile dissdi  : 1;
            uint32_t volatile msten   : 1;
            uint32_t volatile ckp     : 1;
            uint32_t volatile ssen    : 1;
            uint32_t volatile cke     : 1;
            uint32_t volatile smp     : 1;
            uint32_t volatile mode16  : 1;
            uint32_t volatile mode32  : 1;
            uint32_t volatile dissdo  : 1;
            uint32_t volatile sidl    : 1;
            uint32_t volatile         : 1;
            uint32_t volatile on      : 1;
            uint32_t volatile enhbuf  : 1;
            uint32_t volatile spife   : 1;
            uint32_t volatile         : 5;
            uint32_t volatile mclksel : 1;
            uint32_t volatile frmcnt  : 3;
            uint32_t volatile frmsypw : 1;
            uint32_t volatile mssen   : 1;
            uint32_t volatile frmpol  : 1;
            uint32_t volatile frmsync : 1;
            uint32_t volatile frmen   : 1;
        }                     bits;
    };
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

## `ao_spi_reg_con2_t`

```c
struct ao_spi_reg_con2_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile audmod    : 2;
            uint32_t volatile           : 1;
            uint32_t volatile audmono   : 1;
            uint32_t volatile           : 3;
            uint32_t volatile auden     : 1;
            uint32_t volatile igntur    : 1;
            uint32_t volatile ignrov    : 1;
            uint32_t volatile spituren  : 1;
            uint32_t volatile spiroven  : 1;
            uint32_t volatile frmerren  : 1;
            uint32_t volatile           : 2;
            uint32_t volatile spisgnext : 1;
        }                     bits;
    };
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

## `ao_spi_reg_stat_t`

```c
struct ao_spi_reg_stat_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile spirbf   : 1;
            uint32_t volatile spitbf   : 1;
            uint32_t volatile          : 1;
            uint32_t volatile spitbe   : 1;
            uint32_t volatile          : 1;
            uint32_t volatile spirbe   : 1;
            uint32_t volatile spirov   : 1;
            uint32_t volatile srmt     : 1;
            uint32_t volatile spitur   : 1;
            uint32_t volatile          : 2;
            uint32_t volatile spibusy  : 1;
            uint32_t volatile frmerr   : 1;
            uint32_t volatile          : 3;
            uint32_t volatile txbufelm : 5;
            uint32_t volatile          : 3;
            uint32_t volatile rxbufelm : 5;
        }                     bits;
    };
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

# Functions

## `ao_spi_baud`

```c
void ao_spi_baud(ao_spi_reg_t * r, uint32_t f_pbclk, uint32_t f);
```

Sets up the baud rate for a module.

| `r` | The control registers of the module. |
| `f_pbclk` | The frequency of the peripheral bus clock, in Hertz. |
| `f` | The baud rate, in bits per second. |

## `AO_SPI_BAUD_MAX`

```c
#define AO_SPI_BAUD_MAX(f_pbclk)   \
(                                  \
    (f_pbclk) /                    \
    (                              \
        2 * ((AO_SPI_BRG_MIN) + 1) \
    )                              \
)
```

Calculates the maximum possible baud rate, in bits per second.

| `f_pbclk` | The frequency of the peripheral bus clock, in Hertz. |

## `AO_SPI_BAUD_MIN`

```c
#define AO_SPI_BAUD_MIN(f_pbclk)       \
(                                      \
    1 +                                \
    (                                  \
        ((f_pbclk) - 1) /              \
        (                              \
            2 * ((AO_SPI_BRG_MAX) + 1) \
        )                              \
    )                                  \
)
```

Calculates the minimum possible baud rate, in bits per second.

| `f_pbclk` | The frequency of the peripheral bus clock, in Hertz. |
