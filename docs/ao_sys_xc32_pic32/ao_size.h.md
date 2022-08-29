---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32/ao_size.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32/ao_size.h/ 
subtitle: ""
title: "ao_size.h"
toc: true
---

# Overview

...

# Includes

```c
#include <ao_uint.h>

#ifndef AO_SIZE_BITS

#define AO_SIZE_BITS        (AO_UINT_BITS)

#endif

#ifndef AO_SIZE_BITS_LOG

#define AO_SIZE_BITS_LOG    (AO_UINT_BITS_LOG)

#endif

#ifndef AO_SIZE_MAX

#define AO_SIZE_MAX         (AO_UINT_MAX)

#endif

#ifndef AO_SIZE_MIN

#define AO_SIZE_MIN         (AO_UINT_MIN)

#endif

#ifndef AO_SIZE_SIZE

#define AO_SIZE_SIZE        (AO_UINT_SIZE)

#endif

#ifndef ao_cloz

#define ao_cloz(x)          ao_clou(x)

#endif

#ifndef ao_clzz

#define ao_clzz(x)          ao_clzu(x)

#endif

#ifndef ao_ctoz

#define ao_ctoz(x)          ao_ctou(x)

#endif

#ifndef ao_ctzz

#define ao_ctzz(x)          ao_ctzu(x)

#endif

#ifndef ao_ffsz

#define ao_ffsz(x)          ao_ffsu(x)

#endif

#ifndef ao_flsz

#define ao_flsz(x)          ao_flsu(x)

#endif

#ifndef AO_LOG2Z

#define AO_LOG2Z(x)         AO_LOG2U(x)

#endif

```
