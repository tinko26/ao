---
author: "Stefan Wagner"
date: 2022-08-07
description: "Printing in the ao Real-Time Operating System (RTOS)."
draft: false
permalink: /environment/print/
title: "Printing"
---

# Printing

The `ao_print.h` module contains functions to convert a number to a string. Although the standard library contains similar functions, these are not available in a freestanding runtime environment.

## Type

The `ao_print_t` type represents options for the conversion. It consists of the following members.

| Member | |
|--------|-|
| `digits_exponent` | The minimum number of exponent digits to output. Eventually, leading zeros will be added. |
| `digits_fractional` | The minimum number of fractional digits to output. Eventually, trailing zeros will be added. |
| `digits_integral` | The minimum number of integral digits to output. Eventually, leading zeros will be added. |
| `precision` | The maximum number of fractional digits to output. |
| `radix` | The [radix](https://en.wikipedia.org/wiki/Radix) of the positional numeral system, wherein the number is to be represented. |
| `right` | Indicates whether to right-justify the string, if its length is less than the specified minimum `width`. |
| `sign` | Indicates whether the significant is to be preceeded by a `+` character, if the number is positive. Negative numbers are always preceeded by a `-` character. |
| `sign_exponent` | Indicates whether the exponent is to be preceeded by a `+` character, if it is positive. Negative exponents are always preceeded by a `-` character. If the exponent is zero, then its output will be omitted. |
| `sign_space` | Indicates whether the significant is to be preceeded by a space character, if the number is positive or zero. Negative numbers are always preceeded by a `-` character. In the case of positive numbers, this option is inferior to the `sign` option. |
| `uppercase` | Indicates whether alphabetic characters are to be emitted in uppercase. |
| `width` | The minimum width of the string to output. Eventually, leading or trailing spaces will be added. |

## Functions

The module contains functions to convert a floating-point number in scientific notation, ...

```c
size_t ao_printed( char * s, size_t n, ao_print_t const * o, double      const * v);
size_t ao_printef( char * s, size_t n, ao_print_t const * o, float       const * v);
size_t ao_printel( char * s, size_t n, ao_print_t const * o, long double const * v);
```

... a floating-point number in decimal notation, ...

```c
size_t ao_printfd( char * s, size_t n, ao_print_t const * o, double      const * v);
size_t ao_printff( char * s, size_t n, ao_print_t const * o, float       const * v);
size_t ao_printfl( char * s, size_t n, ao_print_t const * o, long double const * v);
```

... a signed integer, ...

```c
size_t ao_printi8( char * s, size_t n, ao_print_t const * o, int8_t  const * v);
size_t ao_printi16(char * s, size_t n, ao_print_t const * o, int16_t const * v);
size_t ao_printi32(char * s, size_t n, ao_print_t const * o, int32_t const * v);
size_t ao_printi64(char * s, size_t n, ao_print_t const * o, int64_t const * v);
```

... or an unsigned integer to a string.

```c
size_t ao_printu8( char * s, size_t n, ao_print_t const * o, uint8_t  const * v);
size_t ao_printu16(char * s, size_t n, ao_print_t const * o, uint16_t const * v);
size_t ao_printu32(char * s, size_t n, ao_print_t const * o, uint32_t const * v);
size_t ao_printu64(char * s, size_t n, ao_print_t const * o, uint64_t const * v);
```

The respective suffix indicates, which kind of number to convert, as well as the source type. All the functions have the same parameter list.

| Parameter | |
|-----------|-|
| `s` | The string to convert to. |
| `n` | The maximum number of characters to write to the string. |
| `o` | The conversion options. |
| `v` | The pointer to the value to convert. |

The return value indicates the actual number of bytes that have been written. The value `0` indicates, that the conversion has failed.

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
