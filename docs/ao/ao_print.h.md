---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao/ao_print.h module of the ao real-time operating system."
draft: true
permalink: /ao/ao_print.h/ 
subtitle: ""
title: "ao_print.h"
toc: true
---

# Overview

...

# Includes

```c
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct  ao_print_t  ao_print_t;

#ifndef AO_PRINT

#define AO_PRINT

struct  ao_print_t
{
        size_t      digits_exponent;

        size_t      digits_fractional;

        size_t      digits_integral;

        size_t      precision;

        size_t      radix;

        bool        right;

        bool        sign;

        bool        sign_exponent;

        bool        sign_space;

        bool        uppercase;

        size_t      width;
};

#endif

size_t  ao_printed( char * s, size_t n, ao_print_t const * o, double      const * v);

size_t  ao_printef( char * s, size_t n, ao_print_t const * o, float       const * v);

size_t  ao_printel( char * s, size_t n, ao_print_t const * o, long double const * v);

size_t  ao_printfd( char * s, size_t n, ao_print_t const * o, double      const * v);

size_t  ao_printff( char * s, size_t n, ao_print_t const * o, float       const * v);

size_t  ao_printfl( char * s, size_t n, ao_print_t const * o, long double const * v);

size_t  ao_printi8( char * s, size_t n, ao_print_t const * o, int8_t  const * v);

size_t  ao_printi16(char * s, size_t n, ao_print_t const * o, int16_t const * v);

size_t  ao_printi32(char * s, size_t n, ao_print_t const * o, int32_t const * v);

size_t  ao_printi64(char * s, size_t n, ao_print_t const * o, int64_t const * v);

size_t  ao_printu8( char * s, size_t n, ao_print_t const * o, uint8_t  const * v);

size_t  ao_printu16(char * s, size_t n, ao_print_t const * o, uint16_t const * v);

size_t  ao_printu32(char * s, size_t n, ao_print_t const * o, uint32_t const * v);

size_t  ao_printu64(char * s, size_t n, ao_print_t const * o, uint64_t const * v);

```
