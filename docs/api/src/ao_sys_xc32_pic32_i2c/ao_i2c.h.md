---
author: "Stefan Wagner"
date: 2022-09-20
draft: true
permalink: /api/src/ao_sys_xc32_pic32_i2c/ao_i2c.h/
toc: true
---

# Include

```c
#include <ao_sys.h>
#include <ao_time.h>
#include <stdbool.h>
#include <stdint.h>
```

# Identifier

```c
#define AO_I2C
```

# Constants

## `AO_I2C_BRG_BITS`

```c
#define AO_I2C_BRG_BITS (16)
```

The size of the `I2CxBRG.BRG` field, in bits.

## `AO_I2C_BRG_MAX`
## `AO_I2C_BRG_MIN`

```c
#define AO_I2C_BRG_MAX ((1 << (AO_I2C_BRG_BITS)) - 1)
#define AO_I2C_BRG_MIN (0)
```

The maximum and minimum value, respectively, of the `I2CxBRG.BRG` field.

# Types

## `ao_i2c_reg_t`

```c
typedef struct ao_i2c_reg_t ao_i2c_reg_t;
```

This type represents the control register set.

## `ao_i2c_reg_*_t`

```c
typedef struct ao_i2c_reg_add_t  ao_i2c_reg_add_t;
typedef struct ao_i2c_reg_brg_t  ao_i2c_reg_brg_t;
typedef struct ao_i2c_reg_con_t  ao_i2c_reg_con_t;
typedef struct ao_i2c_reg_msk_t  ao_i2c_reg_msk_t;
typedef struct ao_i2c_reg_rcv_t  ao_i2c_reg_rcv_t;
typedef struct ao_i2c_reg_stat_t ao_i2c_reg_stat_t;
typedef struct ao_i2c_reg_trn_t  ao_i2c_reg_trn_t;
```

These types represent individual control registers.

# Structs

## `ao_i2c_reg_t`

```c
struct ao_i2c_reg_t
{
    ao_i2c_reg_con_t  con;
    ao_i2c_reg_stat_t stat;
    ao_i2c_reg_add_t  add;
    ao_i2c_reg_msk_t  msk;
    ao_i2c_reg_brg_t  brg;
    ao_i2c_reg_trn_t  trn;
    ao_i2c_reg_rcv_t  rcv;
};
```

## `ao_i2c_reg_add_t`

```c
struct ao_i2c_reg_add_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile add : 10;
        }                     bits;
    };
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

## `ao_i2c_reg_brg_t`

```c
struct ao_i2c_reg_brg_t
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

## `ao_i2c_reg_con_t`

```c
struct ao_i2c_reg_con_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile sen    : 1;
            uint32_t volatile rsen   : 1;
            uint32_t volatile pen    : 1;
            uint32_t volatile rcen   : 1;
            uint32_t volatile acken  : 1;
            uint32_t volatile ackdt  : 1;
            uint32_t volatile stren  : 1;
            uint32_t volatile gcen   : 1;
            uint32_t volatile smen   : 1;
            uint32_t volatile disslw : 1;
            uint32_t volatile a10m   : 1;
            uint32_t volatile strict : 1;
            uint32_t volatile sckrel : 1;
            uint32_t volatile sidl   : 1;
            uint32_t volatile        : 1;
            uint32_t volatile on     : 1;
            uint32_t volatile dhen   : 1;
            uint32_t volatile ahen   : 1;
            uint32_t volatile sbcde  : 1;
            uint32_t volatile sdaht  : 1;
            uint32_t volatile boen   : 1;
            uint32_t volatile scie   : 1;
            uint32_t volatile pcie   : 1;
        }                     bits;
    };
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

## `ao_i2c_reg_msk_t`

```c
struct ao_i2c_reg_msk_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile msk : 10;
        }                     bits;
    };
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

## `ao_i2c_reg_rcv_t`

```c
struct ao_i2c_reg_rcv_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile rxdata : 8;
        }                     bits;
    };
};
```

## `ao_i2c_reg_stat_t`

```c
struct ao_i2c_reg_stat_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile tbf     : 1;
            uint32_t volatile rbf     : 1;
            uint32_t volatile r_w     : 1;
            uint32_t volatile s       : 1;
            uint32_t volatile p       : 1;
            uint32_t volatile d_a     : 1;
            uint32_t volatile i2cov   : 1;
            uint32_t volatile iwcol   : 1;
            uint32_t volatile add10   : 1;
            uint32_t volatile gcstat  : 1;
            uint32_t volatile bcl     : 1;
            uint32_t volatile         : 2;
            uint32_t volatile acktim  : 1;
            uint32_t volatile trstat  : 1;
            uint32_t volatile ackstat : 1;
        }                     bits;
    };
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

## `ao_i2c_reg_trn_t`

```c
struct ao_i2c_reg_trn_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile txdata : 8;
        }                     bits;
    };
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

# Functions

## `ao_i2c_ack`

```c
bool ao_i2c_ack        (ao_i2c_reg_t * r, ao_time_t t);
bool ao_i2c_ack_from   (ao_i2c_reg_t * r, ao_time_t t, ao_time_t b);
bool ao_i2c_ack_forever(ao_i2c_reg_t * r);
```

Generates an acknowledge. The return value indicates, whether the operation succeeded.

| `r` | The control registers. |
| `t` | The timeout. |
| `b` | The beginning. |

## `ao_i2c_acked`

```c
bool ao_i2c_acked(ao_i2c_reg_t const * r);
```

Checks whether an acknowledge has been received.

## `ao_i2c_baud`

```c
void ao_i2c_baud(ao_i2c_reg_t * r, uint32_t f_pbclk, uint32_t f);
```

Sets up the baud rate for a module.

| `r` | The control registers of the module. |
| `f_pbclk` | The frequency of the peripheral bus clock, in Hertz. |
| `f` | The baud rate, in bits per second. |

## `ao_i2c_nack`

```c
bool ao_i2c_nack        (ao_i2c_reg_t * r, ao_time_t t);
bool ao_i2c_nack_from   (ao_i2c_reg_t * r, ao_time_t t, ao_time_t b);
bool ao_i2c_nack_forever(ao_i2c_reg_t * r);
```

Generates a not acknowledge. The return value indicates, whether the operation succeeded.

| `r` | The control registers. |
| `t` | The timeout. |
| `b` | The beginning. |

## `ao_i2c_nacked`

```c
bool ao_i2c_nacked(ao_i2c_reg_t const * r);
```

Checks whether a not acknowledge has been received.

## `ao_i2c_recv`

```c
bool ao_i2c_recv        (ao_i2c_reg_t * r, uint8_t * v, ao_time_t t);
bool ao_i2c_recv_from   (ao_i2c_reg_t * r, uint8_t * v, ao_time_t t, ao_time_t b);
bool ao_i2c_recv_forever(ao_i2c_reg_t * r, uint8_t * v);
```

Receives data. The return value indicates, whether the operation succeeded.

| `r` | The control registers. |
| `v` | The pointer to the location to store the received data. |
| `t` | The timeout. |
| `b` | The beginning. |

## `ao_i2c_restart`

```c
bool ao_i2c_restart        (ao_i2c_reg_t * r, ao_time_t t);
bool ao_i2c_restart_from   (ao_i2c_reg_t * r, ao_time_t t, ao_time_t b);
bool ao_i2c_restart_forever(ao_i2c_reg_t * r);
```

Generates a repeated start bus event. The return value indicates, whether the operation succeeded.

| `r` | The control registers. |
| `t` | The timeout. |
| `b` | The beginning. |

## `ao_i2c_send`

```c
bool ao_i2c_send        (ao_i2c_reg_t * r, uint8_t v, ao_time_t t);
bool ao_i2c_send_from   (ao_i2c_reg_t * r, uint8_t v, ao_time_t t, ao_time_t b);
bool ao_i2c_send_forever(ao_i2c_reg_t * r, uint8_t v);
```

Sends data. The return value indicates, whether the operation succeeded.

| `r` | The control registers. |
| `v` | The data. |
| `t` | The timeout. |
| `b` | The beginning. |

## `ao_i2c_start`

```c
bool ao_i2c_start        (ao_i2c_reg_t * r, ao_time_t t);
bool ao_i2c_start_from   (ao_i2c_reg_t * r, ao_time_t t, ao_time_t b);
bool ao_i2c_start_forever(ao_i2c_reg_t * r);
```

Generates a start bus event. The return value indicates, whether the operation succeeded.

| `r` | The control registers. |
| `t` | The timeout. |
| `b` | The beginning. |

## `ao_i2c_stop`

```c
bool ao_i2c_stop        (ao_i2c_reg_t * r, ao_time_t t);
bool ao_i2c_stop_from   (ao_i2c_reg_t * r, ao_time_t t, ao_time_t b);
bool ao_i2c_stop_forever(ao_i2c_reg_t * r);
```

Generates a stop bus event. The return value indicates, whether the operation succeeded.

| `r` | The control registers. |
| `t` | The timeout. |
| `b` | The beginning. |
