---
author: "Stefan Wagner"
date: 2022-08-29
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

## `AO_SPI_BRG_MAX`
## `AO_SPI_BRG_MIN`

```c
#define AO_SPI_BRG_MAX ((1 << (AO_SPI_BRG_BITS)) - 1)
#define AO_SPI_BRG_MIN (0)
```

## `AO_SPI_ENHBUF`

```c
#define AO_SPI_ENHBUF (true)
```

# Types

## `ao_spi_reg_brg_t`

```c
typedef struct ao_spi_reg_brg_t ao_spi_reg_brg_t;
```

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

It consists of the following members.

| `bits` | |
| `bits.brg` | |
| `clr` | |
| `inv` | |
| `reg` | |
| `set` | |

## `ao_spi_reg_buf_t`

```c
typedef struct ao_spi_reg_buf_t ao_spi_reg_buf_t;
```

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

It consists of the following members.

| `bits` | |
| `bits.data` | |
| `reg` | |

## `ao_spi_reg_con_t`

```c
typedef struct ao_spi_reg_con_t ao_spi_reg_con_t;
```

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

It consists of the following members.

| `bits` | |
| `bits.cke` | |
| `bits.ckp` | |
| `bits.dissdi` | |
| `bits.dissdo` | |
| `bits.enhbuf` | |
| `bits.frmcnt` | |
| `bits.frmen` | |
| `bits.frmpol` | |
| `bits.frmsync` | |
| `bits.frmsypw` | |
| `bits.mclksel` | |
| `bits.mode16` | |
| `bits.mode32` | |
| `bits.mssen` | |
| `bits.msten` | |
| `bits.on` | |
| `bits.sidl` | |
| `bits.smp` | |
| `bits.spife` | |
| `bits.srxisel` | |
| `bits.ssen` | |
| `bits.stxisel` | |
| `clr` | |
| `inv` | |
| `reg` | |
| `set` | |

## `ao_spi_reg_con2_t`

```c
typedef struct ao_spi_reg_con2_t ao_spi_reg_con2_t;
```

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

It consists of the following members.

| `bits` | |
| `bits.auden` | |
| `bits.audmod` | |
| `bits.audmono` | |
| `bits.frmerren` | |
| `bits.ignrov` | |
| `bits.igntur` | |
| `bits.spiroven` | |
| `bits.spisgnext` | |
| `bits.spituren` | |
| `clr` | |
| `inv` | |
| `reg` | |
| `set` | |

## `ao_spi_reg_stat_t`

```c
typedef struct ao_spi_reg_stat_t ao_spi_reg_stat_t;
```

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

It consists of the following members.

| `bits` | |
| `bits.frmerr` | |
| `bits.rxbufelm` | |
| `bits.spibusy` | |
| `bits.spirbe` | |
| `bits.spirbf` | |
| `bits.spirov` | |
| `bits.spitbe` | |
| `bits.spitbf` | |
| `bits.spitur` | |
| `bits.srmt` | |
| `bits.txbufelm` | |
| `clr` | |
| `inv` | |
| `reg` | |
| `set` | |

## `ao_spi_reg_t`

```c
typedef struct ao_spi_reg_t ao_spi_reg_t;
```

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

It consists of the following members.

| `brg` | |
| `buf` | |
| `con` | |
| `con2` | |
| `stat` | |

# Functions

## `ao_spi_baud`

```c
void ao_spi_baud(ao_spi_reg_t * r, uint32_t f_pbclk, uint32_t f );
```

## `AO_SPI_BAUD_MAX`
## `AO_SPI_BAUD_MIN`

```c
#define AO_SPI_BAUD_MAX(f_pbclk)
#define AO_SPI_BAUD_MIN(f_pbclk)
```
