---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32_can/ao_can.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <stdint.h>
```

# Typedefs

```c
typedef struct ao_can_t ao_can_t;
```

```c
typedef struct ao_can_baud_t ao_can_baud_t;
```

```c
typedef struct ao_can_bus_info_t ao_can_bus_info_t;
```

```c
typedef enum ao_can_bus_state_t ao_can_bus_state_t;
```

```c
typedef enum ao_can_fifo_flags_t ao_can_fifo_flags_t;
```

```c
typedef struct ao_can_invalid_info_t ao_can_invalid_info_t;
```

```c
typedef struct ao_can_mode_info_t ao_can_mode_info_t;
```

```c
typedef struct ao_can_overflow_info_t ao_can_overflow_info_t;
```

```c
typedef struct ao_can_reg_t ao_can_reg_t;
```

```c
typedef struct ao_can_reg_cfg_t ao_can_reg_cfg_t;
```

```c
typedef struct ao_can_reg_con_t ao_can_reg_con_t;
```

```c
typedef struct ao_can_reg_fifo_t ao_can_reg_fifo_t;
```

```c
typedef struct ao_can_reg_fifoba_t ao_can_reg_fifoba_t;
```

```c
typedef struct ao_can_reg_fifoci_t ao_can_reg_fifoci_t;
```

```c
typedef struct ao_can_reg_fifocon_t ao_can_reg_fifocon_t;
```

```c
typedef struct ao_can_reg_fifoint_t ao_can_reg_fifoint_t;
```

```c
typedef struct ao_can_reg_fifoua_t ao_can_reg_fifoua_t;
```

```c
typedef struct ao_can_reg_fltcon_t ao_can_reg_fltcon_t;
```

```c
typedef struct ao_can_reg_fltcon0_t ao_can_reg_fltcon0_t;
```

```c
typedef struct ao_can_reg_fltcon1_t ao_can_reg_fltcon1_t;
```

```c
typedef struct ao_can_reg_fltcon2_t ao_can_reg_fltcon2_t;
```

```c
typedef struct ao_can_reg_fltcon3_t ao_can_reg_fltcon3_t;
```

```c
typedef struct ao_can_reg_fltcon4_t ao_can_reg_fltcon4_t;
```

```c
typedef struct ao_can_reg_fltcon5_t ao_can_reg_fltcon5_t;
```

```c
typedef struct ao_can_reg_fltcon6_t ao_can_reg_fltcon6_t;
```

```c
typedef struct ao_can_reg_fltcon7_t ao_can_reg_fltcon7_t;
```

```c
typedef struct ao_can_reg_fstat_t ao_can_reg_fstat_t;
```

```c
typedef struct ao_can_reg_int_t ao_can_reg_int_t;
```

```c
typedef struct ao_can_reg_rxf_t ao_can_reg_rxf_t;
```

```c
typedef struct ao_can_reg_rxm_t ao_can_reg_rxm_t;
```

```c
typedef struct ao_can_reg_rxovf_t ao_can_reg_rxovf_t;
```

```c
typedef struct ao_can_reg_tmr_t ao_can_reg_tmr_t;
```

```c
typedef struct ao_can_reg_trec_t ao_can_reg_trec_t;
```

```c
typedef struct ao_can_reg_vec_t ao_can_reg_vec_t;
```

```c
typedef struct ao_can_sent_info_t ao_can_sent_info_t;
```

```c
typedef enum ao_can_system_flags_t ao_can_system_flags_t;
```

```c
typedef struct ao_can_system_info_t ao_can_system_info_t;
```

```c
typedef struct ao_can_timer_info_t ao_can_timer_info_t;
```

```c
typedef struct ao_can_underflow_info_t ao_can_underflow_info_t;
```

```c
typedef struct ao_can_wake_up_info_t ao_can_wake_up_info_t;
```

# Types

## `ao_can_t`

```c
struct ao_can_t
{
union
{
struct
{
uint32_t sid : 11;
uint32_t filter : 5;
uint32_t time : 16;
};
uint32_t cmsgsid;
};
union
{
struct
{
uint32_t dlc : 4;
uint32_t rb0 : 1;
uint32_t : 3;
uint32_t rb1 : 1;
uint32_t rtr : 1;
uint32_t eid : 18;
uint32_t ide : 1;
uint32_t srr : 1;
};
uint32_t cmsgeid;
};
union
{
struct
{
union
{
struct
{
uint8_t data0;
uint8_t data1;
uint8_t data2;
uint8_t data3;
};
struct
{
uint16_t data01;
uint16_t data23;
};
uint32_t data0123;
uint32_t cmsgdata0;
};
union
{
struct
{
uint8_t data4;
uint8_t data5;
uint8_t data6;
uint8_t data7;
};
struct
{
uint16_t data45;
uint16_t data67;
};
uint32_t data4567;
uint32_t cmsgdata1;
};
};
uint64_t data;
};
};
```

It consists of the following members.

| `cmsgdata0` | |
| `cmsgdata1` | |
| `cmsgeid` | |
| `cmsgsid` | |
| `data` | |
| `data0` | |
| `data01` | |
| `data0123` | |
| `data1` | |
| `data2` | |
| `data23` | |
| `data3` | |
| `data4` | |
| `data45` | |
| `data4567` | |
| `data5` | |
| `data6` | |
| `data67` | |
| `data7` | |
| `dlc` | |
| `eid` | |
| `filter` | |
| `ide` | |
| `rb0` | |
| `rb1` | |
| `rtr` | |
| `sid` | |
| `srr` | |
| `time` | |
| `uint32_t` | |

## `ao_can_baud_t`

```c
struct ao_can_baud_t
{
uint32_t brp;
uint32_t cfg;
uint32_t f;
uint32_t f_error;
uint32_t f_pbclk;
uint32_t f_real;
uint32_t n;
uint32_t n1;
uint32_t n2;
uint32_t np;
bool result;
double sample;
double sample_error;
double sample_real;
bool sample_thrice;
bool sample_thrice_real;
uint32_t sjw;
bool wake_up_filter;
};
```

It consists of the following members.

| `brp` | |
| `cfg` | |
| `f` | |
| `f_error` | |
| `f_pbclk` | |
| `f_real` | |
| `n` | |
| `n1` | |
| `n2` | |
| `np` | |
| `result` | |
| `sample` | |
| `sample_error` | |
| `sample_real` | |
| `sample_thrice` | |
| `sample_thrice_real` | |
| `sjw` | |
| `wake_up_filter` | |

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

## `ao_can_bus_info_t`

```c
struct ao_can_bus_info_t
{
uint32_t receive_error_counter;
ao_can_bus_state_t receive_error_state;
uint32_t transmit_error_counter;
ao_can_bus_state_t transmit_error_state;
};
```

It consists of the following members.

| `receive_error_counter` | |
| `receive_error_state` | |
| `transmit_error_counter` | |
| `transmit_error_state` | |

## `ao_can_fifo_flags_t`

```c
enum ao_can_fifo_flags_t
{
AO_CAN_FIFO_FLAGS_0 = (1 << 0),
AO_CAN_FIFO_FLAGS_1 = (1 << 1),
AO_CAN_FIFO_FLAGS_2 = (1 << 2),
AO_CAN_FIFO_FLAGS_3 = (1 << 3),
AO_CAN_FIFO_FLAGS_4 = (1 << 4),
AO_CAN_FIFO_FLAGS_5 = (1 << 5),
AO_CAN_FIFO_FLAGS_6 = (1 << 6),
AO_CAN_FIFO_FLAGS_7 = (1 << 7),
AO_CAN_FIFO_FLAGS_8 = (1 << 8),
AO_CAN_FIFO_FLAGS_9 = (1 << 9),
AO_CAN_FIFO_FLAGS_10 = (1 << 10),
AO_CAN_FIFO_FLAGS_11 = (1 << 11),
AO_CAN_FIFO_FLAGS_12 = (1 << 12),
AO_CAN_FIFO_FLAGS_13 = (1 << 13),
AO_CAN_FIFO_FLAGS_14 = (1 << 14),
AO_CAN_FIFO_FLAGS_15 = (1 << 15),
AO_CAN_FIFO_FLAGS_16 = (1 << 16),
AO_CAN_FIFO_FLAGS_17 = (1 << 17),
AO_CAN_FIFO_FLAGS_18 = (1 << 18),
AO_CAN_FIFO_FLAGS_19 = (1 << 19),
AO_CAN_FIFO_FLAGS_20 = (1 << 20),
AO_CAN_FIFO_FLAGS_21 = (1 << 21),
AO_CAN_FIFO_FLAGS_22 = (1 << 22),
AO_CAN_FIFO_FLAGS_23 = (1 << 23),
AO_CAN_FIFO_FLAGS_24 = (1 << 24),
AO_CAN_FIFO_FLAGS_25 = (1 << 25),
AO_CAN_FIFO_FLAGS_26 = (1 << 26),
AO_CAN_FIFO_FLAGS_27 = (1 << 27),
AO_CAN_FIFO_FLAGS_28 = (1 << 28),
AO_CAN_FIFO_FLAGS_29 = (1 << 29),
AO_CAN_FIFO_FLAGS_30 = (1 << 30),
AO_CAN_FIFO_FLAGS_31 = (1 << 31),
AO_CAN_FIFO_FLAGS_ALL =
AO_CAN_FIFO_FLAGS_0 |
AO_CAN_FIFO_FLAGS_1 |
AO_CAN_FIFO_FLAGS_2 |
AO_CAN_FIFO_FLAGS_3 |
AO_CAN_FIFO_FLAGS_4 |
AO_CAN_FIFO_FLAGS_5 |
AO_CAN_FIFO_FLAGS_6 |
AO_CAN_FIFO_FLAGS_7 |
AO_CAN_FIFO_FLAGS_8 |
AO_CAN_FIFO_FLAGS_9 |
AO_CAN_FIFO_FLAGS_10 |
AO_CAN_FIFO_FLAGS_11 |
AO_CAN_FIFO_FLAGS_12 |
AO_CAN_FIFO_FLAGS_13 |
AO_CAN_FIFO_FLAGS_14 |
AO_CAN_FIFO_FLAGS_15 |
AO_CAN_FIFO_FLAGS_16 |
AO_CAN_FIFO_FLAGS_17 |
AO_CAN_FIFO_FLAGS_18 |
AO_CAN_FIFO_FLAGS_19 |
AO_CAN_FIFO_FLAGS_20 |
AO_CAN_FIFO_FLAGS_21 |
AO_CAN_FIFO_FLAGS_22 |
AO_CAN_FIFO_FLAGS_23 |
AO_CAN_FIFO_FLAGS_24 |
AO_CAN_FIFO_FLAGS_25 |
AO_CAN_FIFO_FLAGS_26 |
AO_CAN_FIFO_FLAGS_27 |
AO_CAN_FIFO_FLAGS_28 |
AO_CAN_FIFO_FLAGS_29 |
AO_CAN_FIFO_FLAGS_30 |
AO_CAN_FIFO_FLAGS_31,
AO_CAN_FIFO_FLAGS_NONE = 0
};
```

It consists of the following members.

| `AO_CAN_FIFO_FLAGS_0` | |
| `AO_CAN_FIFO_FLAGS_1` | |
| `AO_CAN_FIFO_FLAGS_2` | |
| `AO_CAN_FIFO_FLAGS_3` | |
| `AO_CAN_FIFO_FLAGS_4` | |
| `AO_CAN_FIFO_FLAGS_5` | |
| `AO_CAN_FIFO_FLAGS_6` | |
| `AO_CAN_FIFO_FLAGS_7` | |
| `AO_CAN_FIFO_FLAGS_8` | |
| `AO_CAN_FIFO_FLAGS_9` | |
| `AO_CAN_FIFO_FLAGS_10` | |
| `AO_CAN_FIFO_FLAGS_11` | |
| `AO_CAN_FIFO_FLAGS_12` | |
| `AO_CAN_FIFO_FLAGS_13` | |
| `AO_CAN_FIFO_FLAGS_14` | |
| `AO_CAN_FIFO_FLAGS_15` | |
| `AO_CAN_FIFO_FLAGS_16` | |
| `AO_CAN_FIFO_FLAGS_17` | |
| `AO_CAN_FIFO_FLAGS_18` | |
| `AO_CAN_FIFO_FLAGS_19` | |
| `AO_CAN_FIFO_FLAGS_20` | |
| `AO_CAN_FIFO_FLAGS_21` | |
| `AO_CAN_FIFO_FLAGS_22` | |
| `AO_CAN_FIFO_FLAGS_23` | |
| `AO_CAN_FIFO_FLAGS_24` | |
| `AO_CAN_FIFO_FLAGS_25` | |
| `AO_CAN_FIFO_FLAGS_26` | |
| `AO_CAN_FIFO_FLAGS_27` | |
| `AO_CAN_FIFO_FLAGS_28` | |
| `AO_CAN_FIFO_FLAGS_29` | |
| `AO_CAN_FIFO_FLAGS_30` | |
| `AO_CAN_FIFO_FLAGS_31` | |
| `AO_CAN_FIFO_FLAGS_ALL` | |
| `AO_CAN_FIFO_FLAGS_NONE` | |

## `ao_can_invalid_info_t`

```c
struct ao_can_invalid_info_t { };
```

## `ao_can_mode_info_t`

```c
struct ao_can_mode_info_t { };
```

## `ao_can_overflow_info_t`

```c
struct ao_can_overflow_info_t
{
ao_can_fifo_flags_t fifos;
ao_can_fifo_flags_t fifos_rx;
};
```

It consists of the following members.

| `fifos` | |
| `fifos_rx` | |

## `ao_can_reg_cfg_t`

```c
struct ao_can_reg_cfg_t
{
union
{
uint32_t volatile reg;
struct
{
uint32_t volatile brp : 6;
uint32_t volatile sjw : 2;
uint32_t volatile prseg : 3;
uint32_t volatile seg1ph : 3;
uint32_t volatile sam : 1;
uint32_t volatile seg2phts : 1;
uint32_t volatile seg2ph : 3;
uint32_t volatile : 3;
uint32_t volatile wakfil : 1;
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
| `bits.brp` | |
| `bits.prseg` | |
| `bits.sam` | |
| `bits.seg1ph` | |
| `bits.seg2ph` | |
| `bits.seg2phts` | |
| `bits.sjw` | |
| `bits.volatile` | |
| `bits.wakfil` | |
| `clr` | |
| `inv` | |
| `reg` | |
| `set` | |

## `ao_can_reg_con_t`

```c
struct ao_can_reg_con_t
{
union
{
uint32_t volatile reg;
struct
{
uint32_t volatile dncnt : 5;
uint32_t volatile : 6;
uint32_t volatile canbusy : 1;
uint32_t volatile : 1;
uint32_t volatile sidl : 1;
uint32_t volatile : 1;
uint32_t volatile on : 1;
uint32_t volatile : 4;
uint32_t volatile cancap : 1;
uint32_t volatile opmod : 3;
uint32_t volatile reqop : 3;
uint32_t volatile abat : 1;
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
| `bits.abat` | |
| `bits.canbusy` | |
| `bits.cancap` | |
| `bits.dncnt` | |
| `bits.on` | |
| `bits.opmod` | |
| `bits.reqop` | |
| `bits.sidl` | |
| `bits.volatile` | |
| `bits.volatile` | |
| `bits.volatile` | |
| `bits.volatile` | |
| `clr` | |
| `inv` | |
| `reg` | |
| `set` | |

## `ao_can_reg_fifoba_t`

```c
struct ao_can_reg_fifoba_t
{
uint32_t volatile reg;
uint32_t volatile clr;
uint32_t volatile set;
uint32_t volatile inv;
};
```

It consists of the following members.

| `clr` | |
| `inv` | |
| `reg` | |
| `set` | |

## `ao_can_reg_fifoci_t`

```c
struct ao_can_reg_fifoci_t
{
union
{
uint32_t volatile reg;
struct
{
uint32_t volatile cfifoci : 5;
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
| `bits.cfifoci` | |
| `clr` | |
| `inv` | |
| `reg` | |
| `set` | |

## `ao_can_reg_fifocon_t`

```c
struct ao_can_reg_fifocon_t
{
union
{
uint32_t volatile reg;
struct
{
uint32_t volatile txpri : 2;
uint32_t volatile rtren : 1;
uint32_t volatile txreq : 1;
uint32_t volatile txerr : 1;
uint32_t volatile txlarb : 1;
uint32_t volatile txabat : 1;
uint32_t volatile txen : 1;
uint32_t volatile : 4;
uint32_t volatile donly : 1;
uint32_t volatile uinc : 1;
uint32_t volatile freset : 1;
uint32_t volatile : 1;
uint32_t volatile fsize : 5;
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
| `bits.donly` | |
| `bits.freset` | |
| `bits.fsize` | |
| `bits.rtren` | |
| `bits.txabat` | |
| `bits.txen` | |
| `bits.txerr` | |
| `bits.txlarb` | |
| `bits.txpri` | |
| `bits.txreq` | |
| `bits.uinc` | |
| `bits.volatile` | |
| `bits.volatile` | |
| `clr` | |
| `inv` | |
| `reg` | |
| `set` | |

## `ao_can_reg_fifoint_t`

```c
struct ao_can_reg_fifoint_t
{
union
{
uint32_t volatile reg;
struct
{
uint32_t volatile rxnemptyif : 1;
uint32_t volatile rxhalfif : 1;
uint32_t volatile rxfullif : 1;
uint32_t volatile rxovflif : 1;
uint32_t volatile : 4;
uint32_t volatile txemptyif : 1;
uint32_t volatile txhalfif : 1;
uint32_t volatile txnfullif : 1;
uint32_t volatile : 5;
uint32_t volatile rxnemptyie : 1;
uint32_t volatile rxhalfie : 1;
uint32_t volatile rxfullie : 1;
uint32_t volatile rxovflie : 1;
uint32_t volatile : 4;
uint32_t volatile txemptyie : 1;
uint32_t volatile txhalfie : 1;
uint32_t volatile txnfullie : 1;
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
| `bits.rxfullie` | |
| `bits.rxfullif` | |
| `bits.rxhalfie` | |
| `bits.rxhalfif` | |
| `bits.rxnemptyie` | |
| `bits.rxnemptyif` | |
| `bits.rxovflie` | |
| `bits.rxovflif` | |
| `bits.txemptyie` | |
| `bits.txemptyif` | |
| `bits.txhalfie` | |
| `bits.txhalfif` | |
| `bits.txnfullie` | |
| `bits.txnfullif` | |
| `bits.volatile` | |
| `bits.volatile` | |
| `bits.volatile` | |
| `clr` | |
| `inv` | |
| `reg` | |
| `set` | |

## `ao_can_reg_fifoua_t`

```c
struct ao_can_reg_fifoua_t
{
uint32_t volatile reg;
uint32_t volatile clr;
uint32_t volatile set;
uint32_t volatile inv;
};
```

It consists of the following members.

| `clr` | |
| `inv` | |
| `reg` | |
| `set` | |

## `ao_can_reg_fifo_t`

```c
struct ao_can_reg_fifo_t
{
ao_can_reg_fifocon_t con;
ao_can_reg_fifoint_t intx;
ao_can_reg_fifoua_t ua;
ao_can_reg_fifoci_t ci;
};
```

It consists of the following members.

| `ci` | |
| `con` | |
| `intx` | |
| `ua` | |

## `ao_can_reg_fltcon_t`

```c
struct ao_can_reg_fltcon_t
{
union
{
uint32_t volatile reg;
struct
{
uint32_t volatile fsel0 : 5;
uint32_t volatile msel0 : 2;
uint32_t volatile flten0 : 1;
uint32_t volatile fsel1 : 5;
uint32_t volatile msel1 : 2;
uint32_t volatile flten1 : 1;
uint32_t volatile fsel2 : 5;
uint32_t volatile msel2 : 2;
uint32_t volatile flten2 : 1;
uint32_t volatile fsel3 : 5;
uint32_t volatile msel3 : 2;
uint32_t volatile flten3 : 1;
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
| `bits.flten0` | |
| `bits.flten1` | |
| `bits.flten2` | |
| `bits.flten3` | |
| `bits.fsel0` | |
| `bits.fsel1` | |
| `bits.fsel2` | |
| `bits.fsel3` | |
| `bits.msel0` | |
| `bits.msel1` | |
| `bits.msel2` | |
| `bits.msel3` | |
| `clr` | |
| `inv` | |
| `reg` | |
| `set` | |

## `ao_can_reg_fltcon0_t`

```c
struct ao_can_reg_fltcon0_t
{
union
{
uint32_t volatile reg;
struct
{
uint32_t volatile fsel0 : 5;
uint32_t volatile msel0 : 2;
uint32_t volatile flten0 : 1;
uint32_t volatile fsel1 : 5;
uint32_t volatile msel1 : 2;
uint32_t volatile flten1 : 1;
uint32_t volatile fsel2 : 5;
uint32_t volatile msel2 : 2;
uint32_t volatile flten2 : 1;
uint32_t volatile fsel3 : 5;
uint32_t volatile msel3 : 2;
uint32_t volatile flten3 : 1;
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
| `bits.flten0` | |
| `bits.flten1` | |
| `bits.flten2` | |
| `bits.flten3` | |
| `bits.fsel0` | |
| `bits.fsel1` | |
| `bits.fsel2` | |
| `bits.fsel3` | |
| `bits.msel0` | |
| `bits.msel1` | |
| `bits.msel2` | |
| `bits.msel3` | |
| `clr` | |
| `inv` | |
| `reg` | |
| `set` | |

## `ao_can_reg_fltcon1_t`

```c
struct ao_can_reg_fltcon1_t
{
union
{
uint32_t volatile reg;
struct
{
uint32_t volatile fsel4 : 5;
uint32_t volatile msel4 : 2;
uint32_t volatile flten4 : 1;
uint32_t volatile fsel5 : 5;
uint32_t volatile msel5 : 2;
uint32_t volatile flten5 : 1;
uint32_t volatile fsel6 : 5;
uint32_t volatile msel6 : 2;
uint32_t volatile flten6 : 1;
uint32_t volatile fsel7 : 5;
uint32_t volatile msel7 : 2;
uint32_t volatile flten7 : 1;
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
| `bits.flten4` | |
| `bits.flten5` | |
| `bits.flten6` | |
| `bits.flten7` | |
| `bits.fsel4` | |
| `bits.fsel5` | |
| `bits.fsel6` | |
| `bits.fsel7` | |
| `bits.msel4` | |
| `bits.msel5` | |
| `bits.msel6` | |
| `bits.msel7` | |
| `clr` | |
| `inv` | |
| `reg` | |
| `set` | |

## `ao_can_reg_fltcon2_t`

```c
struct ao_can_reg_fltcon2_t
{
union
{
uint32_t volatile reg;
struct
{
uint32_t volatile fsel8 : 5;
uint32_t volatile msel8 : 2;
uint32_t volatile flten8 : 1;
uint32_t volatile fsel9 : 5;
uint32_t volatile msel9 : 2;
uint32_t volatile flten9 : 1;
uint32_t volatile fsel10 : 5;
uint32_t volatile msel10 : 2;
uint32_t volatile flten10 : 1;
uint32_t volatile fsel11 : 5;
uint32_t volatile msel11 : 2;
uint32_t volatile flten11 : 1;
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
| `bits.flten10` | |
| `bits.flten11` | |
| `bits.flten8` | |
| `bits.flten9` | |
| `bits.fsel10` | |
| `bits.fsel11` | |
| `bits.fsel8` | |
| `bits.fsel9` | |
| `bits.msel10` | |
| `bits.msel11` | |
| `bits.msel8` | |
| `bits.msel9` | |
| `clr` | |
| `inv` | |
| `reg` | |
| `set` | |

## `ao_can_reg_fltcon3_t`

```c
struct ao_can_reg_fltcon3_t
{
union
{
uint32_t volatile reg;
struct
{
uint32_t volatile fsel12 : 5;
uint32_t volatile msel12 : 2;
uint32_t volatile flten12 : 1;
uint32_t volatile fsel13 : 5;
uint32_t volatile msel13 : 2;
uint32_t volatile flten13 : 1;
uint32_t volatile fsel14 : 5;
uint32_t volatile msel14 : 2;
uint32_t volatile flten14 : 1;
uint32_t volatile fsel15 : 5;
uint32_t volatile msel15 : 2;
uint32_t volatile flten15 : 1;
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
| `bits.flten12` | |
| `bits.flten13` | |
| `bits.flten14` | |
| `bits.flten15` | |
| `bits.fsel12` | |
| `bits.fsel13` | |
| `bits.fsel14` | |
| `bits.fsel15` | |
| `bits.msel12` | |
| `bits.msel13` | |
| `bits.msel14` | |
| `bits.msel15` | |
| `clr` | |
| `inv` | |
| `reg` | |
| `set` | |

## `ao_can_reg_fltcon4_t`

```c
struct ao_can_reg_fltcon4_t
{
union
{
uint32_t volatile reg;
struct
{
uint32_t volatile fsel16 : 5;
uint32_t volatile msel16 : 2;
uint32_t volatile flten16 : 1;
uint32_t volatile fsel17 : 5;
uint32_t volatile msel17 : 2;
uint32_t volatile flten17 : 1;
uint32_t volatile fsel18 : 5;
uint32_t volatile msel18 : 2;
uint32_t volatile flten18 : 1;
uint32_t volatile fsel19 : 5;
uint32_t volatile msel19 : 2;
uint32_t volatile flten19 : 1;
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
| `bits.flten16` | |
| `bits.flten17` | |
| `bits.flten18` | |
| `bits.flten19` | |
| `bits.fsel16` | |
| `bits.fsel17` | |
| `bits.fsel18` | |
| `bits.fsel19` | |
| `bits.msel16` | |
| `bits.msel17` | |
| `bits.msel18` | |
| `bits.msel19` | |
| `clr` | |
| `inv` | |
| `reg` | |
| `set` | |

## `ao_can_reg_fltcon5_t`

```c
struct ao_can_reg_fltcon5_t
{
union
{
uint32_t volatile reg;
struct
{
uint32_t volatile fsel20 : 5;
uint32_t volatile msel20 : 2;
uint32_t volatile flten20 : 1;
uint32_t volatile fsel21 : 5;
uint32_t volatile msel21 : 2;
uint32_t volatile flten21 : 1;
uint32_t volatile fsel22 : 5;
uint32_t volatile msel22 : 2;
uint32_t volatile flten22 : 1;
uint32_t volatile fsel23 : 5;
uint32_t volatile msel23 : 2;
uint32_t volatile flten23 : 1;
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
| `bits.flten20` | |
| `bits.flten21` | |
| `bits.flten22` | |
| `bits.flten23` | |
| `bits.fsel20` | |
| `bits.fsel21` | |
| `bits.fsel22` | |
| `bits.fsel23` | |
| `bits.msel20` | |
| `bits.msel21` | |
| `bits.msel22` | |
| `bits.msel23` | |
| `clr` | |
| `inv` | |
| `reg` | |
| `set` | |

## `ao_can_reg_fltcon6_t`

```c
struct ao_can_reg_fltcon6_t
{
union
{
uint32_t volatile reg;
struct
{
uint32_t volatile fsel24 : 5;
uint32_t volatile msel24 : 2;
uint32_t volatile flten24 : 1;
uint32_t volatile fsel25 : 5;
uint32_t volatile msel25 : 2;
uint32_t volatile flten25 : 1;
uint32_t volatile fsel26 : 5;
uint32_t volatile msel26 : 2;
uint32_t volatile flten26 : 1;
uint32_t volatile fsel27 : 5;
uint32_t volatile msel27 : 2;
uint32_t volatile flten27 : 1;
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
| `bits.flten24` | |
| `bits.flten25` | |
| `bits.flten26` | |
| `bits.flten27` | |
| `bits.fsel24` | |
| `bits.fsel25` | |
| `bits.fsel26` | |
| `bits.fsel27` | |
| `bits.msel24` | |
| `bits.msel25` | |
| `bits.msel26` | |
| `bits.msel27` | |
| `clr` | |
| `inv` | |
| `reg` | |
| `set` | |

## `ao_can_reg_fltcon7_t`

```c
struct ao_can_reg_fltcon7_t
{
union
{
uint32_t volatile reg;
struct
{
uint32_t volatile fsel28 : 5;
uint32_t volatile msel28 : 2;
uint32_t volatile flten28 : 1;
uint32_t volatile fsel29 : 5;
uint32_t volatile msel29 : 2;
uint32_t volatile flten29 : 1;
uint32_t volatile fsel30 : 5;
uint32_t volatile msel30 : 2;
uint32_t volatile flten30 : 1;
uint32_t volatile fsel31 : 5;
uint32_t volatile msel31 : 2;
uint32_t volatile flten31 : 1;
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
| `bits.flten28` | |
| `bits.flten29` | |
| `bits.flten30` | |
| `bits.flten31` | |
| `bits.fsel28` | |
| `bits.fsel29` | |
| `bits.fsel30` | |
| `bits.fsel31` | |
| `bits.msel28` | |
| `bits.msel29` | |
| `bits.msel30` | |
| `bits.msel31` | |
| `clr` | |
| `inv` | |
| `reg` | |
| `set` | |

## `ao_can_reg_fstat_t`

```c
struct ao_can_reg_fstat_t
{
union
{
uint32_t volatile reg;
struct
{
uint32_t volatile fifoip0 : 1;
uint32_t volatile fifoip1 : 1;
uint32_t volatile fifoip2 : 1;
uint32_t volatile fifoip3 : 1;
uint32_t volatile fifoip4 : 1;
uint32_t volatile fifoip5 : 1;
uint32_t volatile fifoip6 : 1;
uint32_t volatile fifoip7 : 1;
uint32_t volatile fifoip8 : 1;
uint32_t volatile fifoip9 : 1;
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
| `bits.fifoip0` | |
| `bits.fifoip1` | |
| `bits.fifoip10` | |
| `bits.fifoip11` | |
| `bits.fifoip12` | |
| `bits.fifoip13` | |
| `bits.fifoip14` | |
| `bits.fifoip15` | |
| `bits.fifoip16` | |
| `bits.fifoip17` | |
| `bits.fifoip18` | |
| `bits.fifoip19` | |
| `bits.fifoip2` | |
| `bits.fifoip20` | |
| `bits.fifoip21` | |
| `bits.fifoip22` | |
| `bits.fifoip23` | |
| `bits.fifoip24` | |
| `bits.fifoip25` | |
| `bits.fifoip26` | |
| `bits.fifoip27` | |
| `bits.fifoip28` | |
| `bits.fifoip29` | |
| `bits.fifoip3` | |
| `bits.fifoip30` | |
| `bits.fifoip31` | |
| `bits.fifoip4` | |
| `bits.fifoip5` | |
| `bits.fifoip6` | |
| `bits.fifoip7` | |
| `bits.fifoip8` | |
| `bits.fifoip9` | |
| `clr` | |
| `inv` | |
| `reg` | |
| `set` | |

## `ao_can_reg_int_t`

```c
struct ao_can_reg_int_t
{
union
{
uint32_t volatile reg;
struct
{
uint32_t volatile tbif : 1;
uint32_t volatile rbif : 1;
uint32_t volatile ctmrif : 1;
uint32_t volatile modif : 1;
uint32_t volatile : 7;
uint32_t volatile rbovif : 1;
uint32_t volatile serrif : 1;
uint32_t volatile cerrif : 1;
uint32_t volatile wakif : 1;
uint32_t volatile ivrif : 1;
uint32_t volatile tbie : 1;
uint32_t volatile rbie : 1;
uint32_t volatile ctmrie : 1;
uint32_t volatile modie : 1;
uint32_t volatile : 7;
uint32_t volatile rbovie : 1;
uint32_t volatile serrie : 1;
uint32_t volatile cerrie : 1;
uint32_t volatile wakie : 1;
uint32_t volatile ivrie : 1;
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
| `bits.cerrie` | |
| `bits.cerrif` | |
| `bits.ctmrie` | |
| `bits.ctmrif` | |
| `bits.ivrie` | |
| `bits.ivrif` | |
| `bits.modie` | |
| `bits.modif` | |
| `bits.rbie` | |
| `bits.rbif` | |
| `bits.rbovie` | |
| `bits.rbovif` | |
| `bits.serrie` | |
| `bits.serrif` | |
| `bits.tbie` | |
| `bits.tbif` | |
| `bits.volatile` | |
| `bits.volatile` | |
| `bits.wakie` | |
| `bits.wakif` | |
| `clr` | |
| `inv` | |
| `reg` | |
| `set` | |

## `ao_can_reg_rxf_t`

```c
struct ao_can_reg_rxf_t
{
union
{
uint32_t volatile reg;
struct
{
uint32_t volatile eid : 18;
uint32_t volatile : 1;
uint32_t volatile exid : 1;
uint32_t volatile : 1;
uint32_t volatile sid : 11;
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
| `bits.eid` | |
| `bits.exid` | |
| `bits.sid` | |
| `bits.volatile` | |
| `bits.volatile` | |
| `clr` | |
| `inv` | |
| `reg` | |
| `set` | |

## `ao_can_reg_rxm_t`

```c
struct ao_can_reg_rxm_t
{
union
{
uint32_t volatile reg;
struct
{
uint32_t volatile eid : 18;
uint32_t volatile : 1;
uint32_t volatile mide : 1;
uint32_t volatile : 1;
uint32_t volatile sid : 11;
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
| `bits.eid` | |
| `bits.mide` | |
| `bits.sid` | |
| `bits.volatile` | |
| `bits.volatile` | |
| `clr` | |
| `inv` | |
| `reg` | |
| `set` | |

## `ao_can_reg_rxovf_t`

```c
struct ao_can_reg_rxovf_t
{
union
{
uint32_t volatile reg;
struct
{
uint32_t volatile rxovf0 : 1;
uint32_t volatile rxovf1 : 1;
uint32_t volatile rxovf2 : 1;
uint32_t volatile rxovf3 : 1;
uint32_t volatile rxovf4 : 1;
uint32_t volatile rxovf5 : 1;
uint32_t volatile rxovf6 : 1;
uint32_t volatile rxovf7 : 1;
uint32_t volatile rxovf8 : 1;
uint32_t volatile rxovf9 : 1;
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
| `bits.rxovf0` | |
| `bits.rxovf1` | |
| `bits.rxovf10` | |
| `bits.rxovf11` | |
| `bits.rxovf12` | |
| `bits.rxovf13` | |
| `bits.rxovf14` | |
| `bits.rxovf15` | |
| `bits.rxovf16` | |
| `bits.rxovf17` | |
| `bits.rxovf18` | |
| `bits.rxovf19` | |
| `bits.rxovf2` | |
| `bits.rxovf20` | |
| `bits.rxovf21` | |
| `bits.rxovf22` | |
| `bits.rxovf23` | |
| `bits.rxovf24` | |
| `bits.rxovf25` | |
| `bits.rxovf26` | |
| `bits.rxovf27` | |
| `bits.rxovf28` | |
| `bits.rxovf29` | |
| `bits.rxovf3` | |
| `bits.rxovf30` | |
| `bits.rxovf31` | |
| `bits.rxovf4` | |
| `bits.rxovf5` | |
| `bits.rxovf6` | |
| `bits.rxovf7` | |
| `bits.rxovf8` | |
| `bits.rxovf9` | |
| `clr` | |
| `inv` | |
| `reg` | |
| `set` | |

## `ao_can_reg_tmr_t`

```c
struct ao_can_reg_tmr_t
{
union
{
uint32_t volatile reg;
struct
{
uint32_t volatile cantspre : 16;
uint32_t volatile cants : 16;
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
| `bits.cants` | |
| `bits.cantspre` | |
| `clr` | |
| `inv` | |
| `reg` | |
| `set` | |

## `ao_can_reg_trec_t`

```c
struct ao_can_reg_trec_t
{
union
{
uint32_t volatile reg;
struct
{
uint32_t volatile rerrcnt : 8;
uint32_t volatile terrcnt : 8;
uint32_t volatile ewarn : 1;
uint32_t volatile rxwarn : 1;
uint32_t volatile txwarn : 1;
uint32_t volatile rxbp : 1;
uint32_t volatile txbp : 1;
uint32_t volatile txbo : 1;
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
| `bits.ewarn` | |
| `bits.rerrcnt` | |
| `bits.rxbp` | |
| `bits.rxwarn` | |
| `bits.terrcnt` | |
| `bits.txbo` | |
| `bits.txbp` | |
| `bits.txwarn` | |
| `clr` | |
| `inv` | |
| `reg` | |
| `set` | |

## `ao_can_reg_vec_t`

```c
struct ao_can_reg_vec_t
{
union
{
uint32_t volatile reg;
struct
{
uint32_t volatile icode : 7;
uint32_t volatile : 1;
uint32_t volatile filhit : 5;
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
| `bits.filhit` | |
| `bits.icode` | |
| `bits.volatile` | |
| `clr` | |
| `inv` | |
| `reg` | |
| `set` | |

## `ao_can_reg_t`

```c
struct ao_can_reg_t
{
ao_can_reg_con_t con;
ao_can_reg_cfg_t cfg;
ao_can_reg_int_t intx;
ao_can_reg_vec_t vec;
ao_can_reg_trec_t trec;
ao_can_reg_fstat_t fstat;
ao_can_reg_rxovf_t rxovf;
ao_can_reg_tmr_t tmr;
union
{
struct
{
ao_can_reg_rxm_t rxm0;
ao_can_reg_rxm_t rxm1;
ao_can_reg_rxm_t rxm2;
ao_can_reg_rxm_t rxm3;
};
ao_can_reg_rxm_t rxm[4];
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
ao_can_reg_fltcon_t fltcon[8];
};
union
{
struct
{
ao_can_reg_rxf_t rxf0;
ao_can_reg_rxf_t rxf1;
ao_can_reg_rxf_t rxf2;
ao_can_reg_rxf_t rxf3;
ao_can_reg_rxf_t rxf4;
ao_can_reg_rxf_t rxf5;
ao_can_reg_rxf_t rxf6;
ao_can_reg_rxf_t rxf7;
ao_can_reg_rxf_t rxf8;
ao_can_reg_rxf_t rxf9;
ao_can_reg_rxf_t rxf10;
ao_can_reg_rxf_t rxf11;
ao_can_reg_rxf_t rxf12;
ao_can_reg_rxf_t rxf13;
ao_can_reg_rxf_t rxf14;
ao_can_reg_rxf_t rxf15;
ao_can_reg_rxf_t rxf16;
ao_can_reg_rxf_t rxf17;
ao_can_reg_rxf_t rxf18;
ao_can_reg_rxf_t rxf19;
ao_can_reg_rxf_t rxf20;
ao_can_reg_rxf_t rxf21;
ao_can_reg_rxf_t rxf22;
ao_can_reg_rxf_t rxf23;
ao_can_reg_rxf_t rxf24;
ao_can_reg_rxf_t rxf25;
ao_can_reg_rxf_t rxf26;
ao_can_reg_rxf_t rxf27;
ao_can_reg_rxf_t rxf28;
ao_can_reg_rxf_t rxf29;
ao_can_reg_rxf_t rxf30;
ao_can_reg_rxf_t rxf31;
};
ao_can_reg_rxf_t rxf[32];
};
ao_can_reg_fifoba_t fifoba;
union
{
struct
{
ao_can_reg_fifo_t fifo0;
ao_can_reg_fifo_t fifo1;
ao_can_reg_fifo_t fifo2;
ao_can_reg_fifo_t fifo3;
ao_can_reg_fifo_t fifo4;
ao_can_reg_fifo_t fifo5;
ao_can_reg_fifo_t fifo6;
ao_can_reg_fifo_t fifo7;
ao_can_reg_fifo_t fifo8;
ao_can_reg_fifo_t fifo9;
ao_can_reg_fifo_t fifo10;
ao_can_reg_fifo_t fifo11;
ao_can_reg_fifo_t fifo12;
ao_can_reg_fifo_t fifo13;
ao_can_reg_fifo_t fifo14;
ao_can_reg_fifo_t fifo15;
ao_can_reg_fifo_t fifo16;
ao_can_reg_fifo_t fifo17;
ao_can_reg_fifo_t fifo18;
ao_can_reg_fifo_t fifo19;
ao_can_reg_fifo_t fifo20;
ao_can_reg_fifo_t fifo21;
ao_can_reg_fifo_t fifo22;
ao_can_reg_fifo_t fifo23;
ao_can_reg_fifo_t fifo24;
ao_can_reg_fifo_t fifo25;
ao_can_reg_fifo_t fifo26;
ao_can_reg_fifo_t fifo27;
ao_can_reg_fifo_t fifo28;
ao_can_reg_fifo_t fifo29;
ao_can_reg_fifo_t fifo30;
ao_can_reg_fifo_t fifo31;
};
ao_can_reg_fifo_t fifo[32];
};
};
```

It consists of the following members.

| `cfg` | |
| `con` | |
| `fifo[32]` | |
| `fifo0` | |
| `fifo1` | |
| `fifo10` | |
| `fifo11` | |
| `fifo12` | |
| `fifo13` | |
| `fifo14` | |
| `fifo15` | |
| `fifo16` | |
| `fifo17` | |
| `fifo18` | |
| `fifo19` | |
| `fifo2` | |
| `fifo20` | |
| `fifo21` | |
| `fifo22` | |
| `fifo23` | |
| `fifo24` | |
| `fifo25` | |
| `fifo26` | |
| `fifo27` | |
| `fifo28` | |
| `fifo29` | |
| `fifo3` | |
| `fifo30` | |
| `fifo31` | |
| `fifo4` | |
| `fifo5` | |
| `fifo6` | |
| `fifo7` | |
| `fifo8` | |
| `fifo9` | |
| `fifoba` | |
| `fltcon[8]` | |
| `fltcon0` | |
| `fltcon1` | |
| `fltcon2` | |
| `fltcon3` | |
| `fltcon4` | |
| `fltcon5` | |
| `fltcon6` | |
| `fltcon7` | |
| `fstat` | |
| `intx` | |
| `rxf[32]` | |
| `rxf0` | |
| `rxf1` | |
| `rxf10` | |
| `rxf11` | |
| `rxf12` | |
| `rxf13` | |
| `rxf14` | |
| `rxf15` | |
| `rxf16` | |
| `rxf17` | |
| `rxf18` | |
| `rxf19` | |
| `rxf2` | |
| `rxf20` | |
| `rxf21` | |
| `rxf22` | |
| `rxf23` | |
| `rxf24` | |
| `rxf25` | |
| `rxf26` | |
| `rxf27` | |
| `rxf28` | |
| `rxf29` | |
| `rxf3` | |
| `rxf30` | |
| `rxf31` | |
| `rxf4` | |
| `rxf5` | |
| `rxf6` | |
| `rxf7` | |
| `rxf8` | |
| `rxf9` | |
| `rxm[4]` | |
| `rxm0` | |
| `rxm1` | |
| `rxm2` | |
| `rxm3` | |
| `rxovf` | |
| `tmr` | |
| `trec` | |
| `vec` | |

## `ao_can_sent_info_t`

```c
struct ao_can_sent_info_t
{
uint32_t fifo;
uint32_t fifo_tx;
};
```

It consists of the following members.

| `fifo` | |
| `fifo_tx` | |

## `ao_can_system_flags_t`

```c
enum ao_can_system_flags_t
{
AO_CAN_SYSTEM_ADDRESSING = 0b1000100,
AO_CAN_SYSTEM_BANDWIDTH = 0b1000101,
AC_CAN_SYSTEM_ALL =
AO_CAN_SYSTEM_ADDRESSING |
AO_CAN_SYSTEM_BANDWIDTH,
AO_CAN_SYSTEM_NONE = 0
};
```

It consists of the following members.

| `AO_CAN_SYSTEM_ADDRESSING` | |
| `AO_CAN_SYSTEM_BANDWIDTH` | |
| `AC_CAN_SYSTEM_ALL` | |
| `AO_CAN_SYSTEM_NONE` | |

## `ao_can_system_info_t`

```c
struct ao_can_system_info_t
{
ao_can_system_flags_t flags;
};
```

It consists of the following members.

| `flags` | |

## `ao_can_timer_info_t`

```c
struct ao_can_timer_info_t { };
```

## `ao_can_underflow_info_t`

```c
struct ao_can_underflow_info_t
{
ao_can_fifo_flags_t fifos;
ao_can_fifo_flags_t fifos_tx;
};
```

It consists of the following members.

| `fifos` | |
| `fifos_tx` | |

## `ao_can_wake_up_info_t`

```c
struct ao_can_wake_up_info_t { };
```

# Functions

Get the maximum or minumum baud rate, respectively, for a given periphal bus clock frequency.

```c
#define AO_CAN_BAUD_MAX(f_pbclk)
#define AO_CAN_BAUD_MIN(f_pbclk)
```

Setup the baud rate.

```c
void ao_can_baud( ao_can_baud_t * x);
```
