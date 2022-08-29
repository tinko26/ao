---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao/ao_lfsr.h module of the ao real-time operating system."
draft: true
permalink: /ao/ao_lfsr.h/ 
subtitle: "<code>ao</code>"
title: "<code>ao_lfsr.h</code>"
toc: true
---

typedef struct  ao_lfsr8_t  ao_lfsr8_t;

typedef struct  ao_lfsr16_t ao_lfsr16_t;

typedef struct  ao_lfsr32_t ao_lfsr32_t;

typedef struct  ao_lfsr64_t ao_lfsr64_t;

#ifndef AO_LFSR8

#define AO_LFSR8

struct  ao_lfsr8_t
{
        uint8_t             polynomial;

        uint8_t             seed;
};

#endif

#ifndef AO_LFSR16

#define AO_LFSR16

struct  ao_lfsr16_t
{
        uint16_t            polynomial;

        uint16_t            seed;
};

#endif

#ifndef AO_LFSR32

#define AO_LFSR32

struct  ao_lfsr32_t
{
        uint32_t            polynomial;

        uint32_t            seed;
};

#endif

#ifndef AO_LFSR64

#define AO_LFSR64

struct  ao_lfsr64_t
{
        uint64_t            polynomial;

        uint64_t            seed;
};

#endif

void    ao_lfsr8(           ao_lfsr8_t  * r);

void    ao_lfsr16(          ao_lfsr16_t * r);

void    ao_lfsr32(          ao_lfsr32_t * r);

void    ao_lfsr64(          ao_lfsr64_t * r);

