---
author: "Stefan Wagner"
date: 2022-08-07
description: "The ao_scan.h module of the ao real-time operating system."
draft: false
permalink: /modules/scan/
title: "<code>ao_scan.h</code>"
---

# Overview

This module contains functions to convert a string to a number. Although the standard library contains similar functions, these are not available in a freestanding runtime environment.

## Type

The `ao_scan_t` type represents options for the conversion. It consists of the following members.

| Member | |
|--------|-|
| `radix` | The radix of the positional numeral system, wherein the number is represented. |
| `seek` | Indicates whether to seek for a valid character (sign, digit, or decimal separator) before the conversion. |

## Functions

The module contains functions to convert a string to a floating-point number, ... 

```c
size_t ao_scanfd(char const * s, size_t n, ao_scan_t const * o, double      * v);
size_t ao_scanff(char const * s, size_t n, ao_scan_t const * o, float       * v);
size_t ao_scanfl(char const * s, size_t n, ao_scan_t const * o, long double * v);
```

... a signed integer, ... 

```c
size_t ao_scani8( char const * s, size_t n, ao_scan_t const * o, int8_t  * v);
size_t ao_scani16(char const * s, size_t n, ao_scan_t const * o, int16_t * v);
size_t ao_scani32(char const * s, size_t n, ao_scan_t const * o, int32_t * v);
size_t ao_scani64(char const * s, size_t n, ao_scan_t const * o, int64_t * v);
```

... or an unsigned integer. 

```c
size_t ao_scanu8( char const * s, size_t n, ao_scan_t const * o, uint8_t  * v);
size_t ao_scanu16(char const * s, size_t n, ao_scan_t const * o, uint16_t * v);
size_t ao_scanu32(char const * s, size_t n, ao_scan_t const * o, uint32_t * v);
size_t ao_scanu64(char const * s, size_t n, ao_scan_t const * o, uint64_t * v);
```

The respective suffix indicates, which kind of number to convert to, as well as the destination type. All the functions have the same parameter list.

| Parameter | |
|-----------|-|
| `s` | The string to convert. |
| `n` | The maximum number of characters to read from the string. |
| `o` | The conversion options. |
| `v` | The pointer to a location where to store the result. |

The return value indicates the actual number of bytes that have been read. The value `0` indicates, that the conversion has failed.

```c
// String.
char const * s = "The depth is -12.34567e+2 meters.";

// String length.
size_t n = 33;

// Options.
ao_scan_t o =
{
    .radix = 10,
    .seek = true
};

// Value.
double v;
```

```c
ao_scanfd(s, n, &o, &v);
```

## External Links

[https://en.wikipedia.org/wiki/Radix](https://en.wikipedia.org/wiki/Radix)
