---
author: "Stefan Wagner"
date: 2022-09-20
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

## `ao_uart_error_flags_t`

```c
typedef enum ao_uart_error_flags_t ao_uart_error_flags_t;
```

This type represents the possible error conditions.

## `ao_uart_error_info_t`

```c
typedef struct ao_uart_error_info_t ao_uart_error_info_t;
```

This type represents the information provided to the application, when being notified of errors.

## `ao_uart_reg`

```c
typedef struct ao_uart_reg_brg_t  ao_uart_reg_brg_t;
typedef struct ao_uart_reg_mode_t ao_uart_reg_mode_t;
typedef struct ao_uart_reg_rx_t   ao_uart_reg_rx_t;
typedef struct ao_uart_reg_sta_t  ao_uart_reg_sta_t;
typedef struct ao_uart_reg_tx_t   ao_uart_reg_tx_t;
```

These types represent individual control registers.

## `ao_uart_reg_t`

```c
typedef struct ao_uart_reg_t ao_uart_reg_t;
```

This type represents the control register set.

# Enums

## `ao_uart_error_flags_t`

```c
enum ao_uart_error_flags_t
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

## `ao_uart_error_info_t`

```c
struct ao_uart_error_info_t
{
    ao_uart_error_flags_t flags;
};
```

| `flags` | The flags. |

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

## `ao_uart_baud`

```c
void ao_uart_baud(ao_uart_reg_t * r, uint32_t f_pbclk, uint32_t f);
```

Sets up the baud rate for a module. This function enables or disables high-speed mode, depending on the specified baud rate.

| `r` | The control registers of the module. |
| `f_pbclk` | The frequency of the peripheral bus clock, in Hertz. |
| `f` | The baud rate, in bits per second. |

## `AO_UART_BAUD_MAX`
## `AO_UART_BAUD_MIN`

```c
#define AO_UART_BAUD_MAX(f_pbclk) AO_UART_BAUD_HIGH_MAX(f_pbclk)
#define AO_UART_BAUD_MIN(f_pbclk) AO_UART_BAUD_LOW_MIN (f_pbclk)
```

Calculates the maximum or minimum possible baud rate, respectively, in bits per second.

| `f_pbclk` | The frequency of the peripheral bus clock, in Hertz. |

## `ao_uart_baud_high`

```c
void ao_uart_baud_high(ao_uart_reg_t * r, uint32_t f_pbclk, uint32_t f);
```

Enables high-speed mode and sets up the baud rate for a module.

| `r` | The control registers of the module. |
| `f_pbclk` | The frequency of the peripheral bus clock, in Hertz. |
| `f` | The baud rate, in bits per second. |

## `AO_UART_BAUD_HIGH_MAX`

```c
#define AO_UART_BAUD_HIGH_MAX(f_pbclk) \
(                                      \
    (f_pbclk) /                        \
    (                                  \
        4 * ((AO_UART_BRG_MIN) + 1)    \
    )                                  \
)
```

Calculates the maximum possible baud rate in high-speed mode, in bits per second.

| `f_pbclk` | The frequency of the peripheral bus clock, in Hertz. |

## `AO_UART_BAUD_HIGH_MIN`

```c
#define AO_UART_BAUD_HIGH_MIN(f_pbclk)  \
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

Calculates the minimum possible baud rate in high-speed mode, in bits per second.

| `f_pbclk` | The frequency of the peripheral bus clock, in Hertz. |

## `ao_uart_baud_low`

```c
void ao_uart_baud_low(ao_uart_reg_t * r, uint32_t f_pbclk, uint32_t f);
```

Disables high-speed mode and sets up the baud rate for a module.

| `r` | The control registers of the module. |
| `f_pbclk` | The frequency of the peripheral bus clock, in Hertz. |
| `f` | The baud rate, in bits per second. |

## `AO_UART_BAUD_LOW_MAX`

```c
#define AO_UART_BAUD_LOW_MAX(f_pbclk) \
(                                     \
    (f_pbclk) /                       \
    (                                 \
        16 * ((AO_UART_BRG_MIN) + 1)  \
    )                                 \
)
```

Calculates the maximum possible baud rate in standard-speed mode, in bits per second.

| `f_pbclk` | The frequency of the peripheral bus clock, in Hertz. |

## `AO_UART_BAUD_LOW_MIN`

```c
#define AO_UART_BAUD_LOW_MIN(f_pbclk)    \
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

Calculates the minimum possible baud rate in standard-speed mode, in bits per second.

| `f_pbclk` | The frequency of the peripheral bus clock, in Hertz. |

## `ao_uart_loopback_enable`
## `ao_uart_loopback_disable`

```c
void ao_uart_loopback_enable (ao_uart_reg_t * r);
void ao_uart_loopback_disable(ao_uart_reg_t * r);
```

Enables or disables, respectively, loopback mode for a module.
