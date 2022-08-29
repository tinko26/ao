---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_alloc_2.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_alloc_2.h/ 
subtitle: "<code>ao_sys</code>"
title: "<code>ao_alloc_2.h</code>"
toc: true
---

#ifndef AO_ALLOC_2

#define AO_ALLOC_2

#endif

#ifndef AO_ALLOC_ALLOCATED

#define AO_ALLOC_ALLOCATED          (false)

#endif

#ifndef AO_ALLOC_ALLOCATED_MAX

#define AO_ALLOC_ALLOCATED_MAX      (false)

#endif

#ifndef AO_ALLOC_FREE

#define AO_ALLOC_FREE               (false)

#endif

#ifndef AO_ALLOC_FREE_MIN

#define AO_ALLOC_FREE_MIN           (false)

#endif

#ifndef AO_ALLOC_SEGREGATION

#define AO_ALLOC_SEGREGATION        (3)

#endif

#ifndef AO_ALLOC_SEGREGATION_MIN

#define AO_ALLOC_SEGREGATION_MIN    (0)

#endif

#ifndef AO_ALLOC_SEGREGATION_MAX

#define AO_ALLOC_SEGREGATION_MAX    (AO_SIZE_BITS_LOG)

#endif

#ifndef AO_ALLOC_SIZE

#define AO_ALLOC_SIZE               (8192)

#endif

extern  size_t          volatile    ao_alloc_allocated;

extern  size_t          volatile    ao_alloc_allocated_max;

extern  size_t          volatile    ao_alloc_free;

extern  size_t          volatile    ao_alloc_free_min;

