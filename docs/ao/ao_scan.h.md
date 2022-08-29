---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao/ao_scan.h module of the ao real-time operating system."
draft: true
permalink: /ao/ao_scan.h/ 
subtitle: "<code>ao</code>"
title: "<code>ao_scan.h</code>"
toc: true
---

```c
typedef struct  ao_scan_t   ao_scan_t;

#ifndef AO_SCAN

#define AO_SCAN

struct  ao_scan_t
{
        size_t      radix;

        bool        seek;
};

#endif

size_t  ao_scanfd(  char const * s, size_t n, ao_scan_t const * o, double      * v);

size_t  ao_scanff(  char const * s, size_t n, ao_scan_t const * o, float       * v);

size_t  ao_scanfl(  char const * s, size_t n, ao_scan_t const * o, long double * v);

size_t  ao_scani8(  char const * s, size_t n, ao_scan_t const * o, int8_t  * v);

size_t  ao_scani16( char const * s, size_t n, ao_scan_t const * o, int16_t * v);

size_t  ao_scani32( char const * s, size_t n, ao_scan_t const * o, int32_t * v);

size_t  ao_scani64( char const * s, size_t n, ao_scan_t const * o, int64_t * v);

size_t  ao_scanu8(  char const * s, size_t n, ao_scan_t const * o, uint8_t  * v);

size_t  ao_scanu16( char const * s, size_t n, ao_scan_t const * o, uint16_t * v);

size_t  ao_scanu32( char const * s, size_t n, ao_scan_t const * o, uint32_t * v);

size_t  ao_scanu64( char const * s, size_t n, ao_scan_t const * o, uint64_t * v);

```
