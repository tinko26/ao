---
author: "Stefan Wagner"
date: 2022-09-23
draft: true
permalink: /api/src/ao_sys_xc32_pic32_uart/ao_uart.h/
toc: true
---

# Include

```c
#include <stdint.h>
```

# Identifier

```c
#define AO_UART
```

# Constants

## `AO_UART_BRG_BITS`

```c
#define AO_UART_BRG_BITS (16)
```

The size of the `UxBRG.BRG` field, in bits.

## `AO_UART_BRG_MAX`
## `AO_UART_BRG_MIN`

```c
#define AO_UART_BRG_MAX ((1 << (AO_UART_BRG_BITS)) - 1)
#define AO_UART_BRG_MIN (0)
```

The maximum and minimum value, respectively, of the `UxBRG.BRG` field.

## `AO_UART_DATA_BITS_8_PARITY_NONE`
## `AO_UART_DATA_BITS_8_PARITY_EVEN`
## `AO_UART_DATA_BITS_8_PARITY_ODD`
## `AO_UART_DATA_BITS_9_PARITY_NONE`

```c
#define AO_UART_DATA_BITS_8_PARITY_NONE (0b00)
#define AO_UART_DATA_BITS_8_PARITY_EVEN (0b01)
#define AO_UART_DATA_BITS_8_PARITY_ODD  (0b10)
#define AO_UART_DATA_BITS_9_PARITY_NONE (0b11)
```

The options for the `UxMODE.PDSEL` field specifying both the number of data bits and the parity.

## `AO_UART_FIFO_CAPACITY`

```c
#define AO_UART_FIFO_CAPACITY (8)
```

The capacity of the receive FIFO, in bytes.

## `AO_UART_STOP_BITS_ONE`
## `AO_UART_STOP_BITS_TWO`

```c
#define AO_UART_STOP_BITS_ONE (0)
#define AO_UART_STOP_BITS_TWO (1)
```

The options for the `UxMODE.STSEL` field specifying the number of stop bits.

# Types

## `ao_uart_error_t`

```c
typedef enum ao_uart_error_t ao_uart_error_t;
```

This type represents the possible error conditions.

## `ao_uart_reg_t`

```c
typedef struct ao_uart_reg_t ao_uart_reg_t;
```

This type represents the control register set.

## `ao_uart_reg_*_t`

```c
typedef struct ao_uart_reg_brg_t  ao_uart_reg_brg_t;
typedef struct ao_uart_reg_mode_t ao_uart_reg_mode_t;
typedef struct ao_uart_reg_rx_t   ao_uart_reg_rx_t;
typedef struct ao_uart_reg_sta_t  ao_uart_reg_sta_t;
typedef struct ao_uart_reg_tx_t   ao_uart_reg_tx_t;
```

These types represent individual control registers.

# Enums

## `ao_uart_error_t`

```c
enum ao_uart_error_t
{
    AO_UART_ERROR_NONE    = 0,
    AO_UART_ERROR_OVERRUN = 0x02,
    AO_UART_ERROR_FRAMING = 0x04,
    AO_UART_ERROR_PARITY  = 0x08,
    AO_UART_ERROR_ALL     = 0x0E
};
```

| `AO_UART_ERROR_ALL` | All. |
| `AO_UART_ERROR_FRAMING` | A framing error has been detected for the current byte. |
| `AO_UART_ERROR_NONE` | None. |
| `AO_UART_ERROR_OVERRUN` | The receive buffer has overrun. |
| `AO_UART_ERROR_PARITY` | A parity error has been detected for the current byte. |

# Structs

## `ao_uart_reg_t`

```c
struct ao_uart_reg_t
{
    ao_uart_reg_mode_t mode;
    ao_uart_reg_sta_t  sta;
    ao_uart_reg_tx_t   tx;
    ao_uart_reg_rx_t   rx;
    ao_uart_reg_brg_t  brg;
};
```

## `ao_uart_reg_brg_t`

```c
struct ao_uart_reg_brg_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile brg : 16;
        }                     bits;
    };
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

## `ao_uart_reg_mode_t`

```c
struct ao_uart_reg_mode_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile stsel  : 1;
            uint32_t volatile pdsel  : 2;
            uint32_t volatile brgh   : 1;
            uint32_t volatile rxinv  : 1;
            uint32_t volatile abaud  : 1;
            uint32_t volatile lpback : 1;
            uint32_t volatile wake   : 1;
            uint32_t volatile uen    : 2;
            uint32_t volatile        : 1;
            uint32_t volatile rtsmd  : 1;
            uint32_t volatile iren   : 1;
            uint32_t volatile sidl   : 1;
            uint32_t volatile        : 1;
            uint32_t volatile on     : 1;
            uint32_t volatile runovf : 1;
            uint32_t volatile clksel : 2;
            uint32_t volatile        : 3;
            uint32_t volatile active : 1;
            uint32_t volatile slpen  : 1;
        }                     bits;
    };
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

## `ao_uart_reg_rx_t`

```c
struct ao_uart_reg_rx_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile rx :  9;
        }                     bits;
    };
    uint32_t         volatile    : 32;
    uint32_t         volatile    : 32;
    uint32_t         volatile    : 32;
};
```

## `ao_uart_reg_sta_t`

```c
struct ao_uart_reg_sta_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile urxda   : 1;
            uint32_t volatile oerr    : 1;
            uint32_t volatile ferr    : 1;
            uint32_t volatile perr    : 1;
            uint32_t volatile ridle   : 1;
            uint32_t volatile adden   : 1;
            uint32_t volatile urxisel : 2;
            uint32_t volatile trmt    : 1;
            uint32_t volatile utxbf   : 1;
            uint32_t volatile utxen   : 1;
            uint32_t volatile utxbrk  : 1;
            uint32_t volatile urxen   : 1;
            uint32_t volatile utxinv  : 1;
            uint32_t volatile utxisel : 2;
            uint32_t volatile addr    : 8;
            uint32_t volatile adm_en  : 1;
        }                     bits;
    };
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

## `ao_uart_reg_tx_t`

```c
struct ao_uart_reg_tx_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile tx :  9;
        }                     bits;
    };
    uint32_t         volatile    : 32;
    uint32_t         volatile    : 32;
    uint32_t         volatile    : 32;
};
```

# Functions

## `AO_UART_BAUD_MAX`

```c
#define AO_UART_BAUD_MAX(f_pbclk) \
(                                 \
    AO_UART_BAUD_MAX_HI(f_pbclk)  \
)
```

| `f_pbclk` | The frequency of the peripheral bus clock, in Hertz. |

Calculates the maximum possible baud rate, in bits per second.

## `AO_UART_BAUD_MAX_HI`

```c
#define AO_UART_BAUD_MAX_HI(f_pbclk) \
(                                    \
    (f_pbclk) /                      \
    (                                \
        4 * ((AO_UART_BRG_MIN) + 1)  \
    )                                \
)
```

| `f_pbclk` | The frequency of the peripheral bus clock, in Hertz. |

Calculates the maximum possible baud rate in high-speed mode, in bits per second.

## `AO_UART_BAUD_MAX_LO`

```c
#define AO_UART_BAUD_MAX_LO(f_pbclk) \
(                                    \
    (f_pbclk) /                      \
    (                                \
        16 * ((AO_UART_BRG_MIN) + 1) \
    )                                \
)
```

| `f_pbclk` | The frequency of the peripheral bus clock, in Hertz. |

Calculates the maximum possible baud rate in standard-speed mode, in bits per second.

## `AO_UART_BAUD_MIN`

```c
#define AO_UART_BAUD_MIN(f_pbclk) \
(                                 \
    AO_UART_BAUD_MIN_LO(f_pbclk)  \
)
```

| `f_pbclk` | The frequency of the peripheral bus clock, in Hertz. |

Calculates the minimum possible baud rate, in bits per second.

## `AO_UART_BAUD_MIN_HI`

```c
#define AO_UART_BAUD_MIN_HI(f_pbclk)    \
(                                       \
    1 +                                 \
    (                                   \
        ((f_pbclk) - 1) /               \
        (                               \
            4 * ((AO_UART_BRG_MAX) + 1) \
        )                               \
    )                                   \
)
```

| `f_pbclk` | The frequency of the peripheral bus clock, in Hertz. |

Calculates the minimum possible baud rate in high-speed mode, in bits per second.

## `AO_UART_BAUD_MIN_LO`

```c
#define AO_UART_BAUD_MIN_LO(f_pbclk)     \
(                                        \
    1 +                                  \
    (                                    \
        ((f_pbclk) - 1) /                \
        (                                \
            16 * ((AO_UART_BRG_MAX) + 1) \
        )                                \
    )                                    \
)
```

| `f_pbclk` | The frequency of the peripheral bus clock, in Hertz. |

Calculates the minimum possible baud rate in standard-speed mode, in bits per second.
