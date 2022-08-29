---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao/ao_uint.h file of the ao real-time operating system."
draft: true
permalink: /src/ao/ao_uint.h/ 
subtitle: ""
title: "ao_uint.h"
toc: true
---

# Overview

...

# Includes

```c
#include <stdint.h>

typedef     uint32_t            ao_uint_t;

#ifndef     AO_UINT_BITS

#define     AO_UINT_BITS        (32)

#endif

#ifndef     AO_UINT_BITS_LOG

#define     AO_UINT_BITS_LOG    (5)

#endif

#ifndef     AO_UINT_MAX

#define     AO_UINT_MAX         (UINT32_MAX)

#endif

#ifndef     AO_UINT_MIN

#define     AO_UINT_MIN         (0)

#endif

#ifndef     AO_UINT_SIZE

#define     AO_UINT_SIZE        (4)

#endif

ao_uint_t   ao_clou(ao_uint_t x);

ao_uint_t   ao_clzu(ao_uint_t x);

ao_uint_t   ao_ctou(ao_uint_t x);

ao_uint_t   ao_ctzu(ao_uint_t x);

ao_uint_t   ao_ffsu(ao_uint_t x);

ao_uint_t   ao_flsu(ao_uint_t x);

#ifndef     AO_LOG2U

#define     AO_LOG2U(x)         AO_LOG2U32(x)

#endif

#ifndef     AO_LOG2U2

#define     AO_LOG2U2(x)        ((x) & 0x0000000000000002U ?  1                         : 0            )

#endif

#ifndef     AO_LOG2U4

#define     AO_LOG2U4(x)        ((x) & 0x000000000000000CU ?  2 + AO_LOG2U2( (x) >>  2) : AO_LOG2U2(x) )

#endif

#ifndef     AO_LOG2U8

#define     AO_LOG2U8(x)        ((x) & 0x00000000000000F0U ?  4 + AO_LOG2U4( (x) >>  4) : AO_LOG2U4(x) )

#endif

#ifndef     AO_LOG2U16

#define     AO_LOG2U16(x)       ((x) & 0x000000000000FF00U ?  8 + AO_LOG2U8( (x) >>  8) : AO_LOG2U8(x) )

#endif

#ifndef     AO_LOG2U32

#define     AO_LOG2U32(x)       ((x) & 0x00000000FFFF0000U ? 16 + AO_LOG2U16((x) >> 16) : AO_LOG2U16(x))

#endif

#ifndef     AO_LOG2U64

#define     AO_LOG2U64(x)       ((x) & 0xFFFFFFFF00000000U ? 32 + AO_LOG2U32((x) >> 32) : AO_LOG2U32(x))

#endif

```
