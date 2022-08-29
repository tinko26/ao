---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao/ao_size.h module of the ao real-time operating system."
draft: true
permalink: /ao/ao_size.h/ 
subtitle: "<code>ao</code>"
title: "<code>ao_size.h</code>"
toc: true
---

#ifndef AO_SIZE_BITS

#define AO_SIZE_BITS        (32)

#endif

#ifndef AO_SIZE_BITS_LOG

#define AO_SIZE_BITS_LOG    (5)

#endif

#ifndef AO_SIZE_MAX

#define AO_SIZE_MAX         (SIZE_MAX)

#endif

#ifndef AO_SIZE_MIN

#define AO_SIZE_MIN         (0)

#endif

#ifndef AO_SIZE_SIZE

#define AO_SIZE_SIZE        (4)

#endif

size_t  ao_cloz(size_t x);

size_t  ao_clzz(size_t x);

size_t  ao_ctoz(size_t x);

size_t  ao_ctzz(size_t x);

size_t  ao_ffsz(size_t x);

size_t  ao_flsz(size_t x);

#ifndef AO_LOG2Z

#define AO_LOG2Z(x)         AO_LOG2U32(x)

#endif

