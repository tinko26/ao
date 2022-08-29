---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32/ao_uint.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32/ao_uint.h/ 
subtitle: "ao_sys_xc32_pic32"
title: "ao_uint.h"
toc: true
---

```c
#include <stdint.h>
#include <xc.h>

typedef uint32_t            ao_uint_t;

#ifndef AO_UINT_BITS

#define AO_UINT_BITS        (32)

#endif

#ifndef AO_UINT_BITS_LOG

#define AO_UINT_BITS_LOG    (5)

#endif

#ifndef AO_UINT_MAX

#define AO_UINT_MAX         (UINT32_MAX)

#endif

#ifndef AO_UINT_MIN

#define AO_UINT_MIN         (0)

#endif

#ifndef AO_UINT_SIZE

#define AO_UINT_SIZE        (4)

#endif

#ifndef ao_clou

#define ao_clou(x)          _clo(x)

#endif

#ifndef ao_clzu

#define ao_clzu(x)          _clz(x)

#endif

#ifndef ao_ctou

#define ao_ctou(x)          _ctz(~(x))

#endif

#ifndef ao_ctzu

#define ao_ctzu(x)          _ctz(x)

#endif

#ifndef ao_ffsu

#define ao_ffsu(x)          _ctz(x)

#endif

#ifndef ao_flsu

#define ao_flsu(x)          (31 - _clz(x))

#endif

#ifndef AO_LOG2U

#define AO_LOG2U(x)         AO_LOG2U32(x)

#endif

#ifndef AO_LOG2U2

#define AO_LOG2U2(x)        ((x) & 0x0000000000000002U ?  1                         : 0            )

#endif

#ifndef AO_LOG2U4

#define AO_LOG2U4(x)        ((x) & 0x000000000000000CU ?  2 + AO_LOG2U2( (x) >>  2) : AO_LOG2U2(x) )

#endif

#ifndef AO_LOG2U8

#define AO_LOG2U8(x)        ((x) & 0x00000000000000F0U ?  4 + AO_LOG2U4( (x) >>  4) : AO_LOG2U4(x) )

#endif

#ifndef AO_LOG2U16

#define AO_LOG2U16(x)       ((x) & 0x000000000000FF00U ?  8 + AO_LOG2U8( (x) >>  8) : AO_LOG2U8(x) )

#endif

#ifndef AO_LOG2U32

#define AO_LOG2U32(x)       ((x) & 0x00000000FFFF0000U ? 16 + AO_LOG2U16((x) >> 16) : AO_LOG2U16(x))

#endif

#ifndef AO_LOG2U64

#define AO_LOG2U64(x)       ((x) & 0xFFFFFFFF00000000U ? 32 + AO_LOG2U32((x) >> 32) : AO_LOG2U32(x))

#endif

```
