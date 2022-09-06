---
api: true
author: "Stefan Wagner"
date: 2022-08-31
description: "The /src/ao/ao_print.h file of the ao real-time operating system."
draft: false
permalink: /api/src/ao/ao_print.h/
subtitle: "Converting numbers to string"
title: "ao_print.h"
toc: true
wiki:
- radix
---

# Overview

This module contains functions to convert a number to a string. Although the standard library contains similar functions, these are not available in a freestanding runtime environment.

# Include

```c
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
```

# Typedefs

```c
typedef struct ao_print_t ao_print_t;
```

# Types

## `ao_print_t`

This type represents options for the conversion.

```c
struct ao_print_t
{
    size_t digits_exponent;
    size_t digits_fractional;
    size_t digits_integral;
    size_t precision;
    size_t radix;
    bool   right;
    bool   sign;
    bool   sign_exponent;
    bool   sign_space;
    bool   uppercase;
    size_t width;
};
```

It consists of the following members.

| `digits_exponent` | The minimum number of exponent digits to output. Eventually, leading zeros will be added. |
| `digits_fractional` | The minimum number of fractional digits to output. Eventually, trailing zeros will be added. |
| `digits_integral` | The minimum number of integral digits to output. Eventually, leading zeros will be added. |
| `precision` | The maximum number of fractional digits to output. |
| `radix` | The radix of the positional numeral system, wherein the number is to be represented. |
| `right` | Indicates whether to right-justify the string, if its length is less than the specified minimum `width`. |
| `sign` | Indicates whether the significant is to be preceeded by a `+` character, if the number is positive. Negative numbers are always preceeded by a `-` character. |
| `sign_exponent` | Indicates whether the exponent is to be preceeded by a `+` character, if it is positive. Negative exponents are always preceeded by a `-` character. If the exponent is zero, then its output will be omitted. |
| `sign_space` | Indicates whether the significant is to be preceeded by a space character, if the number is positive or zero. Negative numbers are always preceeded by a `-` character. In the case of positive numbers, this option is inferior to the `sign` option. |
| `uppercase` | Indicates whether alphabetic characters are to be emitted in uppercase. |
| `width` | The minimum width of the string to output. Eventually, leading or trailing spaces will be added. |

# Functions

Convert a floating-point number to string in scientific notation.

```c
size_t ao_printed( char * s, size_t n, ao_print_t const * o, double const * v);
size_t ao_printef( char * s, size_t n, ao_print_t const * o, float const * v);
size_t ao_printel( char * s, size_t n, ao_print_t const * o, long double const * v);
```

Convert a floating-point number to string in decimal notation.

```c
size_t ao_printfd( char * s, size_t n, ao_print_t const * o, double const * v);
size_t ao_printff( char * s, size_t n, ao_print_t const * o, float const * v);
size_t ao_printfl( char * s, size_t n, ao_print_t const * o, long double const * v);
```

Convert a signed integer to string.

```c
size_t ao_printi8( char * s, size_t n, ao_print_t const * o, int8_t const * v);
size_t ao_printi16(char * s, size_t n, ao_print_t const * o, int16_t const * v);
size_t ao_printi32(char * s, size_t n, ao_print_t const * o, int32_t const * v);
size_t ao_printi64(char * s, size_t n, ao_print_t const * o, int64_t const * v);
```

Convert an unsigned integer to string.

```c
size_t ao_printu8( char * s, size_t n, ao_print_t const * o, uint8_t const * v);
size_t ao_printu16(char * s, size_t n, ao_print_t const * o, uint16_t const * v);
size_t ao_printu32(char * s, size_t n, ao_print_t const * o, uint32_t const * v);
size_t ao_printu64(char * s, size_t n, ao_print_t const * o, uint64_t const * v);
```

The respective suffix indicates, which kind of number to convert, as well as the source type. All the functions have the same parameter list.

| `s` | The string to convert to. |
| `n` | The maximum number of characters to write to the string. |
| `o` | The conversion options. |
| `v` | The pointer to the value to convert. |

The return value indicates the actual number of bytes that have been written. The value `0` indicates, that the conversion has failed.

# Example

```c
// String.
char s[128];

// String length.
size_t n = 128;

// Options.
ao_print_t o = 
{
    .digits_fractional = 0,
    .digits_integral = 0,
    .precision = 4,
    .right = false,
    .sign = true,
    .width = 0
};

// Value.
double v = 1234.567;
```

```c
ao_printfd(s, n, &o, &v);
```
