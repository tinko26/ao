---
author: "Stefan Wagner"
date: 2022-09-23
draft: true
permalink: /api/src/ao_sys_xc32_pic32_can/ao_can.h/
toc: true
---

# Include

```c
#include <stdint.h>
```

# Types

## `ao_can_bus_t`

```c
typedef struct ao_can_bus_t ao_can_bus_t;
```

This type represents the data provided to the application, when being notified of bus errors.

## `ao_can_bus_state_t`

```c
typedef enum ao_can_bus_state_t ao_can_bus_state_t;
```

This type specifies the possible bus states.

## `ao_can_msg_t`

```c
typedef struct ao_can_msg_t ao_can_msg_t;
```

This type represents a message.

## `ao_can_reg_t`

```c
typedef struct ao_can_reg_t ao_can_reg_t;
```

This type represents the control register set.

## `ao_can_reg_*_t`

```c
typedef struct ao_can_reg_cfg_t     ao_can_reg_cfg_t;
typedef struct ao_can_reg_con_t     ao_can_reg_con_t;
typedef struct ao_can_reg_fifo_t    ao_can_reg_fifo_t;
typedef struct ao_can_reg_fifoba_t  ao_can_reg_fifoba_t;
typedef struct ao_can_reg_fifoci_t  ao_can_reg_fifoci_t;
typedef struct ao_can_reg_fifocon_t ao_can_reg_fifocon_t;
typedef struct ao_can_reg_fifoint_t ao_can_reg_fifoint_t;
typedef struct ao_can_reg_fifoua_t  ao_can_reg_fifoua_t;
typedef struct ao_can_reg_fltcon_t  ao_can_reg_fltcon_t;
typedef struct ao_can_reg_fltcon0_t ao_can_reg_fltcon0_t;
typedef struct ao_can_reg_fltcon1_t ao_can_reg_fltcon1_t;
typedef struct ao_can_reg_fltcon2_t ao_can_reg_fltcon2_t;
typedef struct ao_can_reg_fltcon3_t ao_can_reg_fltcon3_t;
typedef struct ao_can_reg_fltcon4_t ao_can_reg_fltcon4_t;
typedef struct ao_can_reg_fltcon5_t ao_can_reg_fltcon5_t;
typedef struct ao_can_reg_fltcon6_t ao_can_reg_fltcon6_t;
typedef struct ao_can_reg_fltcon7_t ao_can_reg_fltcon7_t;
typedef struct ao_can_reg_fstat_t   ao_can_reg_fstat_t;
typedef struct ao_can_reg_int_t     ao_can_reg_int_t;
typedef struct ao_can_reg_rxf_t     ao_can_reg_rxf_t;
typedef struct ao_can_reg_rxm_t     ao_can_reg_rxm_t;
typedef struct ao_can_reg_rxovf_t   ao_can_reg_rxovf_t;
typedef struct ao_can_reg_tmr_t     ao_can_reg_tmr_t;
typedef struct ao_can_reg_trec_t    ao_can_reg_trec_t;
typedef struct ao_can_reg_vec_t     ao_can_reg_vec_t;
```

These types represent individual control registers.

## `ao_can_system_t`

```c
typedef enum ao_can_system_t ao_can_system_t;
```

This type represents possible system errors.

# Enums

## `ao_can_bus_state_t`

```c
enum ao_can_bus_state_t
{
    AO_CAN_BUS_ACTIVE,
    AO_CAN_BUS_ACTIVE_WARNING,
    AO_CAN_BUS_PASSIVE,
    AO_CAN_BUS_OFF
};
```

## `ao_can_system_t`

```c
enum ao_can_system_t
{
    AO_CAN_SYSTEM_ADDRESSING = 0b1000100,
    AO_CAN_SYSTEM_BANDWIDTH  = 0b1000101
};
```

# Structs

## `ao_can_bus_t`

```c
struct ao_can_bus_t
{
    uint32_t           receive_error_counter;
    ao_can_bus_state_t receive_error_state;
    uint32_t           transmit_error_counter;
    ao_can_bus_state_t transmit_error_state;
};
```

| `receive_error_counter` | The receive error counter. |
| `receive_error_state` | The receive error state. |
| `transmit_error_counter` | The transmit error counter. |
| `transmit_error_state` | The transmit error state. |

## `ao_can_msg_t`

```c
struct ao_can_msg_t
{
    union
    {
        struct
        {
            uint32_t         sid    : 11;
            uint32_t         filter :  5;
            uint32_t         time   : 16;
        };
        uint32_t             cmsgsid;
    };
    union
    {
        struct
        {
            uint32_t         dlc    :  4;
            uint32_t         rb0    :  1;
            uint32_t                :  3;
            uint32_t         rb1    :  1;
            uint32_t         rtr    :  1;
            uint32_t         eid    : 18;
            uint32_t         ide    :  1;
            uint32_t         srr    :  1;
        };
        uint32_t             cmsgeid;
    };
    union
    {
        struct
        {
            union
            {
                struct
                {
                    uint8_t  data0;
                    uint8_t  data1;
                    uint8_t  data2;
                    uint8_t  data3;
                };
                struct
                {
                    uint16_t data01;
                    uint16_t data23;
                };
                uint32_t     data0123;
                uint32_t     cmsgdata0;
            };
            union
            {
                struct
                {
                    uint8_t  data4;
                    uint8_t  data5;
                    uint8_t  data6;
                    uint8_t  data7;
                };
                struct
                {
                    uint16_t data45;
                    uint16_t data67;
                };
                uint32_t     data4567;
                uint32_t     cmsgdata1;
            };
        };
        uint64_t             data;
    };
};
```

## `ao_can_reg_t`

```c
struct ao_can_reg_t
{
    ao_can_reg_con_t             con;
    ao_can_reg_cfg_t             cfg;
    ao_can_reg_int_t             intx;
    ao_can_reg_vec_t             vec;
    ao_can_reg_trec_t            trec;
    ao_can_reg_fstat_t           fstat;
    ao_can_reg_rxovf_t           rxovf;
    ao_can_reg_tmr_t             tmr;
    union
    {
        struct
        {
            ao_can_reg_rxm_t     rxm0;
            ao_can_reg_rxm_t     rxm1;
            ao_can_reg_rxm_t     rxm2;
            ao_can_reg_rxm_t     rxm3;
        };
        ao_can_reg_rxm_t         rxm[4];
    };
    union
    {
        struct
        {
            ao_can_reg_fltcon0_t fltcon0;
            ao_can_reg_fltcon1_t fltcon1;
            ao_can_reg_fltcon2_t fltcon2;
            ao_can_reg_fltcon3_t fltcon3;
            ao_can_reg_fltcon4_t fltcon4;
            ao_can_reg_fltcon5_t fltcon5;
            ao_can_reg_fltcon6_t fltcon6;
            ao_can_reg_fltcon7_t fltcon7;
        };
        ao_can_reg_fltcon_t      fltcon[8];
    };
    union
    {
        struct
        {
            ao_can_reg_rxf_t     rxf0;
            ao_can_reg_rxf_t     rxf1;
            ao_can_reg_rxf_t     rxf2;
            ao_can_reg_rxf_t     rxf3;
            ao_can_reg_rxf_t     rxf4;
            ao_can_reg_rxf_t     rxf5;
            ao_can_reg_rxf_t     rxf6;
            ao_can_reg_rxf_t     rxf7;
            ao_can_reg_rxf_t     rxf8;
            ao_can_reg_rxf_t     rxf9;
            ao_can_reg_rxf_t     rxf10;
            ao_can_reg_rxf_t     rxf11;
            ao_can_reg_rxf_t     rxf12;
            ao_can_reg_rxf_t     rxf13;
            ao_can_reg_rxf_t     rxf14;
            ao_can_reg_rxf_t     rxf15;
            ao_can_reg_rxf_t     rxf16;
            ao_can_reg_rxf_t     rxf17;
            ao_can_reg_rxf_t     rxf18;
            ao_can_reg_rxf_t     rxf19;
            ao_can_reg_rxf_t     rxf20;
            ao_can_reg_rxf_t     rxf21;
            ao_can_reg_rxf_t     rxf22;
            ao_can_reg_rxf_t     rxf23;
            ao_can_reg_rxf_t     rxf24;
            ao_can_reg_rxf_t     rxf25;
            ao_can_reg_rxf_t     rxf26;
            ao_can_reg_rxf_t     rxf27;
            ao_can_reg_rxf_t     rxf28;
            ao_can_reg_rxf_t     rxf29;
            ao_can_reg_rxf_t     rxf30;
            ao_can_reg_rxf_t     rxf31;
        };
        ao_can_reg_rxf_t         rxf[32];
    };
    ao_can_reg_fifoba_t          fifoba;
    union
    {
        struct
        {
            ao_can_reg_fifo_t    fifo0;
            ao_can_reg_fifo_t    fifo1;
            ao_can_reg_fifo_t    fifo2;
            ao_can_reg_fifo_t    fifo3;
            ao_can_reg_fifo_t    fifo4;
            ao_can_reg_fifo_t    fifo5;
            ao_can_reg_fifo_t    fifo6;
            ao_can_reg_fifo_t    fifo7;
            ao_can_reg_fifo_t    fifo8;
            ao_can_reg_fifo_t    fifo9;
            ao_can_reg_fifo_t    fifo10;
            ao_can_reg_fifo_t    fifo11;
            ao_can_reg_fifo_t    fifo12;
            ao_can_reg_fifo_t    fifo13;
            ao_can_reg_fifo_t    fifo14;
            ao_can_reg_fifo_t    fifo15;
            ao_can_reg_fifo_t    fifo16;
            ao_can_reg_fifo_t    fifo17;
            ao_can_reg_fifo_t    fifo18;
            ao_can_reg_fifo_t    fifo19;
            ao_can_reg_fifo_t    fifo20;
            ao_can_reg_fifo_t    fifo21;
            ao_can_reg_fifo_t    fifo22;
            ao_can_reg_fifo_t    fifo23;
            ao_can_reg_fifo_t    fifo24;
            ao_can_reg_fifo_t    fifo25;
            ao_can_reg_fifo_t    fifo26;
            ao_can_reg_fifo_t    fifo27;
            ao_can_reg_fifo_t    fifo28;
            ao_can_reg_fifo_t    fifo29;
            ao_can_reg_fifo_t    fifo30;
            ao_can_reg_fifo_t    fifo31;
        };
        ao_can_reg_fifo_t        fifo[32];
    };
};
```

## `ao_can_reg_cfg_t`

```c
struct ao_can_reg_cfg_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile brp      : 6;
            uint32_t volatile sjw      : 2;
            uint32_t volatile prseg    : 3;
            uint32_t volatile seg1ph   : 3;
            uint32_t volatile sam      : 1;
            uint32_t volatile seg2phts : 1;
            uint32_t volatile seg2ph   : 3;
            uint32_t volatile          : 3;
            uint32_t volatile wakfil   : 1;
        }                     bits;
    };
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

## `ao_can_reg_con_t`

```c
struct ao_can_reg_con_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile dncnt   : 5;
            uint32_t volatile         : 6;
            uint32_t volatile canbusy : 1;
            uint32_t volatile         : 1;
            uint32_t volatile sidl    : 1;
            uint32_t volatile         : 1;
            uint32_t volatile on      : 1;
            uint32_t volatile         : 4;
            uint32_t volatile cancap  : 1;
            uint32_t volatile opmod   : 3;
            uint32_t volatile reqop   : 3;
            uint32_t volatile abat    : 1;
        }                     bits;
    };
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

## `ao_can_reg_fifoba_t`

```c
struct ao_can_reg_fifoba_t
{
    uint32_t     volatile reg;
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

## `ao_can_reg_fifoci_t`

```c
struct ao_can_reg_fifoci_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile cfifoci : 5;
        }                     bits;
    };
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

## `ao_can_reg_fifocon_t`

```c
struct ao_can_reg_fifocon_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile txpri  : 2;
            uint32_t volatile rtren  : 1;
            uint32_t volatile txreq  : 1;
            uint32_t volatile txerr  : 1;
            uint32_t volatile txlarb : 1;
            uint32_t volatile txabat : 1;
            uint32_t volatile txen   : 1;
            uint32_t volatile        : 4;
            uint32_t volatile donly  : 1;
            uint32_t volatile uinc   : 1;
            uint32_t volatile freset : 1;
            uint32_t volatile        : 1;
            uint32_t volatile fsize  : 5;
        }                     bits;
    };
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

## `ao_can_reg_fifoint_t`

```c
struct ao_can_reg_fifoint_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile rxnemptyif : 1;
            uint32_t volatile rxhalfif   : 1;
            uint32_t volatile rxfullif   : 1;
            uint32_t volatile rxovflif   : 1;
            uint32_t volatile            : 4;
            uint32_t volatile txemptyif  : 1;
            uint32_t volatile txhalfif   : 1;
            uint32_t volatile txnfullif  : 1;
            uint32_t volatile            : 5;
            uint32_t volatile rxnemptyie : 1;
            uint32_t volatile rxhalfie   : 1;
            uint32_t volatile rxfullie   : 1;
            uint32_t volatile rxovflie   : 1;
            uint32_t volatile            : 4;
            uint32_t volatile txemptyie  : 1;
            uint32_t volatile txhalfie   : 1;
            uint32_t volatile txnfullie  : 1;
        }                     bits;
    };
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

## `ao_can_reg_fifoua_t`

```c
struct ao_can_reg_fifoua_t
{
    uint32_t     volatile reg;
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

## `ao_can_reg_fifo_t`

```c
struct ao_can_reg_fifo_t
{
    ao_can_reg_fifocon_t con;
    ao_can_reg_fifoint_t intx;
    ao_can_reg_fifoua_t  ua;
    ao_can_reg_fifoci_t  ci;
};
```

## `ao_can_reg_fltcon_t`

```c
struct ao_can_reg_fltcon_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile fsel0  : 5;
            uint32_t volatile msel0  : 2;
            uint32_t volatile flten0 : 1;
            uint32_t volatile fsel1  : 5;
            uint32_t volatile msel1  : 2;
            uint32_t volatile flten1 : 1;
            uint32_t volatile fsel2  : 5;
            uint32_t volatile msel2  : 2;
            uint32_t volatile flten2 : 1;
            uint32_t volatile fsel3  : 5;
            uint32_t volatile msel3  : 2;
            uint32_t volatile flten3 : 1;
        }                     bits;
    };
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

## `ao_can_reg_fltcon0_t`

```c
struct ao_can_reg_fltcon0_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile fsel0  : 5;
            uint32_t volatile msel0  : 2;
            uint32_t volatile flten0 : 1;
            uint32_t volatile fsel1  : 5;
            uint32_t volatile msel1  : 2;
            uint32_t volatile flten1 : 1;
            uint32_t volatile fsel2  : 5;
            uint32_t volatile msel2  : 2;
            uint32_t volatile flten2 : 1;
            uint32_t volatile fsel3  : 5;
            uint32_t volatile msel3  : 2;
            uint32_t volatile flten3 : 1;
        }                     bits;
    };
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

## `ao_can_reg_fltcon1_t`

```c
struct ao_can_reg_fltcon1_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile fsel4  : 5;
            uint32_t volatile msel4  : 2;
            uint32_t volatile flten4 : 1;
            uint32_t volatile fsel5  : 5;
            uint32_t volatile msel5  : 2;
            uint32_t volatile flten5 : 1;
            uint32_t volatile fsel6  : 5;
            uint32_t volatile msel6  : 2;
            uint32_t volatile flten6 : 1;
            uint32_t volatile fsel7  : 5;
            uint32_t volatile msel7  : 2;
            uint32_t volatile flten7 : 1;
        }                     bits;
    };
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

## `ao_can_reg_fltcon2_t`

```c
struct ao_can_reg_fltcon2_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile fsel8   : 5;
            uint32_t volatile msel8   : 2;
            uint32_t volatile flten8  : 1;
            uint32_t volatile fsel9   : 5;
            uint32_t volatile msel9   : 2;
            uint32_t volatile flten9  : 1;
            uint32_t volatile fsel10  : 5;
            uint32_t volatile msel10  : 2;
            uint32_t volatile flten10 : 1;
            uint32_t volatile fsel11  : 5;
            uint32_t volatile msel11  : 2;
            uint32_t volatile flten11 : 1;
        }                     bits;
    };
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

## `ao_can_reg_fltcon3_t`

```c
struct ao_can_reg_fltcon3_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile fsel12  : 5;
            uint32_t volatile msel12  : 2;
            uint32_t volatile flten12 : 1;
            uint32_t volatile fsel13  : 5;
            uint32_t volatile msel13  : 2;
            uint32_t volatile flten13 : 1;
            uint32_t volatile fsel14  : 5;
            uint32_t volatile msel14  : 2;
            uint32_t volatile flten14 : 1;
            uint32_t volatile fsel15  : 5;
            uint32_t volatile msel15  : 2;
            uint32_t volatile flten15 : 1;
        }                     bits;
    };
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

## `ao_can_reg_fltcon4_t`

```c
struct ao_can_reg_fltcon4_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile fsel16  : 5;
            uint32_t volatile msel16  : 2;
            uint32_t volatile flten16 : 1;
            uint32_t volatile fsel17  : 5;
            uint32_t volatile msel17  : 2;
            uint32_t volatile flten17 : 1;
            uint32_t volatile fsel18  : 5;
            uint32_t volatile msel18  : 2;
            uint32_t volatile flten18 : 1;
            uint32_t volatile fsel19  : 5;
            uint32_t volatile msel19  : 2;
            uint32_t volatile flten19 : 1;
        }                     bits;
    };
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

## `ao_can_reg_fltcon5_t`

```c
struct ao_can_reg_fltcon5_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile fsel20  : 5;
            uint32_t volatile msel20  : 2;
            uint32_t volatile flten20 : 1;
            uint32_t volatile fsel21  : 5;
            uint32_t volatile msel21  : 2;
            uint32_t volatile flten21 : 1;
            uint32_t volatile fsel22  : 5;
            uint32_t volatile msel22  : 2;
            uint32_t volatile flten22 : 1;
            uint32_t volatile fsel23  : 5;
            uint32_t volatile msel23  : 2;
            uint32_t volatile flten23 : 1;
        }                     bits;
    };
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

## `ao_can_reg_fltcon6_t`

```c
struct ao_can_reg_fltcon6_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile fsel24  : 5;
            uint32_t volatile msel24  : 2;
            uint32_t volatile flten24 : 1;
            uint32_t volatile fsel25  : 5;
            uint32_t volatile msel25  : 2;
            uint32_t volatile flten25 : 1;
            uint32_t volatile fsel26  : 5;
            uint32_t volatile msel26  : 2;
            uint32_t volatile flten26 : 1;
            uint32_t volatile fsel27  : 5;
            uint32_t volatile msel27  : 2;
            uint32_t volatile flten27 : 1;
        }                     bits;
    };
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

## `ao_can_reg_fltcon7_t`

```c
struct ao_can_reg_fltcon7_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile fsel28  : 5;
            uint32_t volatile msel28  : 2;
            uint32_t volatile flten28 : 1;
            uint32_t volatile fsel29  : 5;
            uint32_t volatile msel29  : 2;
            uint32_t volatile flten29 : 1;
            uint32_t volatile fsel30  : 5;
            uint32_t volatile msel30  : 2;
            uint32_t volatile flten30 : 1;
            uint32_t volatile fsel31  : 5;
            uint32_t volatile msel31  : 2;
            uint32_t volatile flten31 : 1;
        }                     bits;
    };
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

## `ao_can_reg_fstat_t`

```c
struct ao_can_reg_fstat_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile fifoip0  : 1;
            uint32_t volatile fifoip1  : 1;
            uint32_t volatile fifoip2  : 1;
            uint32_t volatile fifoip3  : 1;
            uint32_t volatile fifoip4  : 1;
            uint32_t volatile fifoip5  : 1;
            uint32_t volatile fifoip6  : 1;
            uint32_t volatile fifoip7  : 1;
            uint32_t volatile fifoip8  : 1;
            uint32_t volatile fifoip9  : 1;
            uint32_t volatile fifoip10 : 1;
            uint32_t volatile fifoip11 : 1;
            uint32_t volatile fifoip12 : 1;
            uint32_t volatile fifoip13 : 1;
            uint32_t volatile fifoip14 : 1;
            uint32_t volatile fifoip15 : 1;
            uint32_t volatile fifoip16 : 1;
            uint32_t volatile fifoip17 : 1;
            uint32_t volatile fifoip18 : 1;
            uint32_t volatile fifoip19 : 1;
            uint32_t volatile fifoip20 : 1;
            uint32_t volatile fifoip21 : 1;
            uint32_t volatile fifoip22 : 1;
            uint32_t volatile fifoip23 : 1;
            uint32_t volatile fifoip24 : 1;
            uint32_t volatile fifoip25 : 1;
            uint32_t volatile fifoip26 : 1;
            uint32_t volatile fifoip27 : 1;
            uint32_t volatile fifoip28 : 1;
            uint32_t volatile fifoip29 : 1;
            uint32_t volatile fifoip30 : 1;
            uint32_t volatile fifoip31 : 1;
        }                     bits;
    };
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

## `ao_can_reg_int_t`

```c
struct ao_can_reg_int_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile tbif   : 1;
            uint32_t volatile rbif   : 1;
            uint32_t volatile ctmrif : 1;
            uint32_t volatile modif  : 1;
            uint32_t volatile        : 7;
            uint32_t volatile rbovif : 1;
            uint32_t volatile serrif : 1;
            uint32_t volatile cerrif : 1;
            uint32_t volatile wakif  : 1;
            uint32_t volatile ivrif  : 1;
            uint32_t volatile tbie   : 1;
            uint32_t volatile rbie   : 1;
            uint32_t volatile ctmrie : 1;
            uint32_t volatile modie  : 1;
            uint32_t volatile        : 7;
            uint32_t volatile rbovie : 1;
            uint32_t volatile serrie : 1;
            uint32_t volatile cerrie : 1;
            uint32_t volatile wakie  : 1;
            uint32_t volatile ivrie  : 1;
        }                     bits;
    };
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

## `ao_can_reg_rxf_t`

```c
struct ao_can_reg_rxf_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile eid  : 18;
            uint32_t volatile      : 1;
            uint32_t volatile exid : 1;
            uint32_t volatile      : 1;
            uint32_t volatile sid  : 11;
        }                     bits;
    };
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

## `ao_can_reg_rxm_t`

```c
struct ao_can_reg_rxm_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile eid  : 18;
            uint32_t volatile      : 1;
            uint32_t volatile mide : 1;
            uint32_t volatile      : 1;
            uint32_t volatile sid  : 11;
        }                     bits;
    };
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

## `ao_can_reg_rxovf_t`

```c
struct ao_can_reg_rxovf_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile rxovf0  : 1;
            uint32_t volatile rxovf1  : 1;
            uint32_t volatile rxovf2  : 1;
            uint32_t volatile rxovf3  : 1;
            uint32_t volatile rxovf4  : 1;
            uint32_t volatile rxovf5  : 1;
            uint32_t volatile rxovf6  : 1;
            uint32_t volatile rxovf7  : 1;
            uint32_t volatile rxovf8  : 1;
            uint32_t volatile rxovf9  : 1;
            uint32_t volatile rxovf10 : 1;
            uint32_t volatile rxovf11 : 1;
            uint32_t volatile rxovf12 : 1;
            uint32_t volatile rxovf13 : 1;
            uint32_t volatile rxovf14 : 1;
            uint32_t volatile rxovf15 : 1;
            uint32_t volatile rxovf16 : 1;
            uint32_t volatile rxovf17 : 1;
            uint32_t volatile rxovf18 : 1;
            uint32_t volatile rxovf19 : 1;
            uint32_t volatile rxovf20 : 1;
            uint32_t volatile rxovf21 : 1;
            uint32_t volatile rxovf22 : 1;
            uint32_t volatile rxovf23 : 1;
            uint32_t volatile rxovf24 : 1;
            uint32_t volatile rxovf25 : 1;
            uint32_t volatile rxovf26 : 1;
            uint32_t volatile rxovf27 : 1;
            uint32_t volatile rxovf28 : 1;
            uint32_t volatile rxovf29 : 1;
            uint32_t volatile rxovf30 : 1;
            uint32_t volatile rxovf31 : 1;
        }                     bits;
    };
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

## `ao_can_reg_tmr_t`

```c
struct ao_can_reg_tmr_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile cantspre : 16;
            uint32_t volatile cants    : 16;
        }                     bits;
    };
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

## `ao_can_reg_trec_t`

```c
struct ao_can_reg_trec_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile rerrcnt : 8;
            uint32_t volatile terrcnt : 8;
            uint32_t volatile ewarn   : 1;
            uint32_t volatile rxwarn  : 1;
            uint32_t volatile txwarn  : 1;
            uint32_t volatile rxbp    : 1;
            uint32_t volatile txbp    : 1;
            uint32_t volatile txbo    : 1;
        }                     bits;
    };
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

## `ao_can_reg_vec_t`

```c
struct ao_can_reg_vec_t
{
    union
    {
        uint32_t     volatile reg;
        struct
        {
            uint32_t volatile icode  : 7;
            uint32_t volatile        : 1;
            uint32_t volatile filhit : 5;
        }                     bits;
    };
    uint32_t         volatile clr;
    uint32_t         volatile set;
    uint32_t         volatile inv;
};
```

# Functions

## `AO_CAN_BAUD_MAX`

```c
#define AO_CAN_BAUD_MAX(f_pbclk) \
(                                \
    (f_pbclk) / 16               \
)
```

| `f_pbclk` | The frequency of the peripheral bus clock, in Hertz. |

Calculates the maximum possible baud rate, in bits per second.

## `AO_CAN_BAUD_MIN`

```c
#define AO_CAN_BAUD_MIN(f_pbclk) \
(                                \
    1 + (((f_pbclk) - 1) / 3200) \
)
```

| `f_pbclk` | The frequency of the peripheral bus clock, in Hertz. |

Calculates the minimum possible baud rate, in bits per second.

# Include Next

```c
#include_next <ao_can.h>
```
