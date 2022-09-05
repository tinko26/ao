---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32_uart/ao_uart.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32_uart/ao_uart.h/
subtitle: "UART"
title: "ao_uart.h"
toc: true
---

# Include

```c
#include <stdint.h>
```

# Typedefs

```c
typedef enum ao_uart_error_flags_t ao_uart_error_flags_t;
```

```c
typedef struct ao_uart_error_info_t ao_uart_error_info_t;
```

```c
typedef struct ao_uart_reg_t ao_uart_reg_t;
```

```c
typedef struct ao_uart_reg_brg_t ao_uart_reg_brg_t;
```

```c
typedef struct ao_uart_reg_mode_t ao_uart_reg_mode_t;
```

```c
typedef struct ao_uart_reg_rx_t ao_uart_reg_rx_t;
```

```c
typedef struct ao_uart_reg_sta_t ao_uart_reg_sta_t;
```

```c
typedef struct ao_uart_reg_tx_t ao_uart_reg_tx_t;
```

# Constants

```c
#define AO_UART_BRG_BITS (16)
```

```c
#define AO_UART_BRG_MAX ((1 << (AO_UART_BRG_BITS)) - 1)
```

```c
#define AO_UART_BRG_MIN (0)
```

```c
#define AO_UART_DATA_BITS_8_PARITY_EVEN (0b01)
```

```c
#define AO_UART_DATA_BITS_8_PARITY_NONE (0b00)
```

```c
#define AO_UART_DATA_BITS_8_PARITY_ODD (0b10)
```

```c
#define AO_UART_DATA_BITS_9_PARITY_NONE (0b11)
```

```c
#define AO_UART_FIFO_CAPACITY (8)
```

```c
#define AO_UART_STOP_BITS_ONE (0)
```

```c
#define AO_UART_STOP_BITS_TWO (1)
```

# Types

## `ao_uart_error_flags_t`

```c
enum ao_uart_error_flags_t
{
    AO_UART_ERROR_ALL = 0x0E,
    AO_UART_ERROR_FRAMING = 0x04,
    AO_UART_ERROR_NONE = 0,
    AO_UART_ERROR_OVERRUN = 0x02,
    AO_UART_ERROR_PARITY = 0x08,
};
```

It consists of the following members.

| `AO_UART_ERROR_ALL` | |
| `AO_UART_ERROR_FRAMING` | |
| `AO_UART_ERROR_NONE` | |
| `AO_UART_ERROR_OVERRUN` | |
| `AO_UART_ERROR_PARITY` | |

## `ao_uart_error_info_t`

```c
struct ao_uart_error_info_t
{
    ao_uart_error_flags_t flags;
};
```

It consists of the following members.

| `flags` | |

## `ao_uart_reg_brg_t`

```c
struct ao_uart_reg_brg_t
{
    union
    {
        uint32_t volatile reg;
        struct
        {
            uint32_t volatile brg : 16;
        }
        bits;
    };
    uint32_t volatile clr;
    uint32_t volatile set;
    uint32_t volatile inv;
};
```

It consists of the following members.

| `bits` | |
| `bits.brg` | |
| `clr` | |
| `inv` | |
| `reg` | |
| `set` | |

## `ao_uart_reg_mode_t`

```c
struct ao_uart_reg_mode_t
{
    union
    {
        uint32_t volatile reg;
        struct
        {
            uint32_t volatile stsel : 1;
            uint32_t volatile pdsel : 2;
            uint32_t volatile brgh : 1;
            uint32_t volatile rxinv : 1;
            uint32_t volatile abaud : 1;
            uint32_t volatile lpback : 1;
            uint32_t volatile wake : 1;
            uint32_t volatile uen : 2;
            uint32_t volatile : 1;
            uint32_t volatile rtsmd : 1;
            uint32_t volatile iren : 1;
            uint32_t volatile sidl : 1;
            uint32_t volatile : 1;
            uint32_t volatile on : 1;
            uint32_t volatile runovf : 1;
            uint32_t volatile clksel : 2;
            uint32_t volatile : 3;
            uint32_t volatile active : 1;
            uint32_t volatile slpen : 1;
        }
        bits;
    };
    uint32_t volatile clr;
    uint32_t volatile set;
    uint32_t volatile inv;
};
```

It consists of the following members.

| `bits` | |
| `bits.abaud` | |
| `bits.active` | |
| `bits.brgh` | |
| `bits.clksel` | |
| `bits.iren` | |
| `bits.lpback` | |
| `bits.on` | |
| `bits.pdsel` | |
| `bits.rtsmd` | |
| `bits.runovf` | |
| `bits.rxinv` | |
| `bits.sidl` | |
| `bits.slpen` | |
| `bits.stsel` | |
| `bits.uen` | |
| `bits.volatile` | |
| `bits.volatile` | |
| `bits.volatile` | |
| `bits.wake` | |
| `clr` | |
| `inv` | |
| `reg` | |
| `set` | |

## `ao_uart_reg_rx_t`

```c
struct ao_uart_reg_rx_t
{
    union
    {
        uint32_t volatile reg;
        struct
        {
            uint32_t volatile rx : 9;
        }
        bits;
    };
    uint32_t volatile : 32;
    uint32_t volatile : 32;
    uint32_t volatile : 32;
};
```

It consists of the following members.

| `bits` | |
| `bits.rx` | |
| `reg` | |
| `volatile` | |
| `volatile` | |
| `volatile` | |

## `ao_uart_reg_sta_t`

```c
struct ao_uart_reg_sta_t
{
    union
    {
        uint32_t volatile reg;
        struct
        {
            uint32_t volatile urxda : 1;
            uint32_t volatile oerr : 1;
            uint32_t volatile ferr : 1;
            uint32_t volatile perr : 1;
            uint32_t volatile ridle : 1;
            uint32_t volatile adden : 1;
            uint32_t volatile urxisel : 2;
            uint32_t volatile trmt : 1;
            uint32_t volatile utxbf : 1;
            uint32_t volatile utxen : 1;
            uint32_t volatile utxbrk : 1;
            uint32_t volatile urxen : 1;
            uint32_t volatile utxinv : 1;
            uint32_t volatile utxisel : 2;
            uint32_t volatile addr : 8;
            uint32_t volatile adm_en : 1;
        }
        bits;
    };
    uint32_t volatile clr;
    uint32_t volatile set;
    uint32_t volatile inv;
};
```

It consists of the following members.

| `bits` | |
| `bits.adden` | |
| `bits.addr` | |
| `bits.adm_en` | |
| `bits.ferr` | |
| `bits.oerr` | |
| `bits.perr` | |
| `bits.ridle` | |
| `bits.trmt` | |
| `bits.urxda` | |
| `bits.urxen` | |
| `bits.urxisel` | |
| `bits.utxbf` | |
| `bits.utxbrk` | |
| `bits.utxen` | |
| `bits.utxinv` | |
| `bits.utxisel` | |
| `clr` | |
| `inv` | |
| `reg` | |
| `set` | |

## `ao_uart_reg_tx_t`

```c
struct ao_uart_reg_tx_t
{
    union
    {
        uint32_t volatile reg;
        struct
        {
            uint32_t volatile tx : 9;
        }
        bits;
    };
    uint32_t volatile : 32;
    uint32_t volatile : 32;
    uint32_t volatile : 32;
};
```

It consists of the following members.

| `bits` | |
| `bits.tx` | |
| `reg` | |
| `volatile` | |
| `volatile` | |
| `volatile` | |

## `ao_uart_reg_t`

```c
struct ao_uart_reg_t
{
    ao_uart_reg_mode_t mode;
    ao_uart_reg_sta_t sta;
    ao_uart_reg_tx_t tx;
    ao_uart_reg_rx_t rx;
    ao_uart_reg_brg_t brg;
};
```

It consists of the following members.

| `brg` | |
| `mode` | |
| `rx` | |
| `sta` | |
| `tx` | |

# Functions

```c
#define AO_UART_BAUD_MAX(f_pbclk)
```

```c
#define AO_UART_BAUD_MIN(f_pbclk)
```

```c
#define AO_UART_BAUD_HIGH_MAX(f_pbclk)
```

```c
#define AO_UART_BAUD_HIGH_MIN(f_pbclk)
```

```c
#define AO_UART_BAUD_LOW_MAX(f_pbclk)
```

```c
#define AO_UART_BAUD_LOW_MIN(f_pbclk)
```

```c
void ao_uart_baud ( ao_uart_reg_t * r, uint32_t f_pbclk, uint32_t f );
```

```c
void ao_uart_baud_high ( ao_uart_reg_t * r, uint32_t f_pbclk, uint32_t f );
```

```c
void ao_uart_baud_low ( ao_uart_reg_t * r, uint32_t f_pbclk, uint32_t f );
```

```c
void ao_uart_loopback_disable( ao_uart_reg_t * r);
```

```c
void ao_uart_loopback_enable( ao_uart_reg_t * r);
```
