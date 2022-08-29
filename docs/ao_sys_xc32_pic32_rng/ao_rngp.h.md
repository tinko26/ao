---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32_rng/ao_rngp.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32_rng/ao_rngp.h/ 
subtitle: ""
title: "ao_rngp.h"
toc: true
---

```c
#include <stdint.h>
#include <xc.h>

#ifndef ao_rngp_disable

#define ao_rngp_disable()               { RNGCONbits.PRNGEN = 0; }

#endif

#ifndef ao_rngp_enable

#define ao_rngp_enable()                { RNGCONbits.PRNGEN = 1; }

#endif

#ifndef ao_rngp_bits

#define ao_rngp_bits()                  (RNGCONbits.PLEN)

#endif

#ifndef ao_rngp_bits_set

#define ao_rngp_bits_set(x)             { RNGCONbits.PLEN = (uint32_t) (x); }

#endif

#ifndef ao_rngp_continuous_disable

#define ao_rngp_continuous_disable()    { RNGCONbits.CONT = 0; }

#endif

#ifndef ao_rngp_continuous_enable

#define ao_rngp_continuous_enable()     { RNGCONbits.CONT = 1; }

#endif

#ifndef ao_rngp_poly

#define ao_rngp_poly()                  (((uint64_t) RNGPOLY2 << 32) | (uint64_t) RNGPOLY1)

#endif

#ifndef ao_rngp_poly_set

#define ao_rngp_poly_set(x)                                                 \
{                                                                           \
        RNGPOLY2 = (uint32_t) (((uint64_t) (x) >> 32) & 0xFFFFFFFFULL);     \
        RNGPOLY1 = (uint32_t) (((uint64_t) (x) >>  0) & 0xFFFFFFFFULL);     \
}

#endif

#ifndef ao_rngp_poly_hi

#define ao_rngp_poly_hi()               (RNGPOLY2)

#endif

#ifndef ao_rngp_poly_hi_set

#define ao_rngp_poly_hi_set(x)          { RNGPOLY2 = (uint32_t) (x); }

#endif

#ifndef ao_rngp_poly_lo

#define ao_rngp_poly_lo()               (RNGPOLY1)

#endif

#ifndef ao_rngp_poly_lo_set

#define ao_rngp_poly_lo_set(x)          { RNGPOLY1 = (uint32_t) (x); }

#endif

#ifndef ao_rngp_seed

#define ao_rngp_seed(x)                 ao_rngp_value_set(x)

#endif

#ifndef ao_rngp_seed_hi

#define ao_rngp_seed_hi(x)              ao_rngp_value_hi_set(x)

#endif

#ifndef ao_rngp_seed_lo

#define ao_rngp_seed_lo(x)              ao_rngp_value_lo_set(x)

#endif

#ifndef ao_rngp_seed_true

#define ao_rngp_seed_true(x)            { RNGCONbits.LOAD = 1; }

#endif

#ifndef ao_rngp_value

#define ao_rngp_value()                 (((uint64_t) RNGNUMGEN2 << 32) | (uint64_t) RNGNUMGEN1)

#endif

#ifndef ao_rngp_value_set

#define ao_rngp_value_set(x)                                                \
{                                                                           \
        RNGNUMGEN2 = (uint32_t) (((uint64_t) (x) >> 32) & 0xFFFFFFFFULL);   \
        RNGNUMGEN1 = (uint32_t) (((uint64_t) (x) >>  0) & 0xFFFFFFFFULL);   \
}

#endif

#ifndef ao_rngp_value_hi

#define ao_rngp_value_hi()              (RNGNUMGEN2)

#endif

#ifndef ao_rngp_value_hi_set

#define ao_rngp_value_hi_set(x)         { RNGNUMGEN2 = (uint32_t) (x); }

#endif

#ifndef ao_rngp_value_lo

#define ao_rngp_value_lo()              (RNGNUMGEN1)

#endif

#ifndef ao_rngp_value_lo_set

#define ao_rngp_value_lo_set(x)         { RNGNUMGEN1 = (uint32_t) (x); }

#endif

```
