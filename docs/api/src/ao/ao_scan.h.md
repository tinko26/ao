---
author: "Stefan Wagner"
date: 2022-08-31
draft: false
permalink: /api/src/ao/ao_scan.h/
toc: true
wiki:
- radix
---

# Overview

This module contains functions to convert a string to a number. Although the standard library contains similar functions, these are not available in a freestanding runtime environment.

# Include

```c
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
```

# Typedefs

```c
typedef struct ao_scan_t ao_scan_t;
```

# Types

## `ao_scan_t`

This type represents options for the conversion.

```c
struct ao_scan_t
{
size_t radix;
bool   seek;
};
```

It consists of the following members.

| `radix` | The radix of the positional numeral system, wherein the number is represented. |
| `seek` | Indicates whether to seek for a valid character (sign, digit, or decimal separator) before the conversion. |

# Functions

Convert a floating-point number from string.

```c
size_t ao_scanfd( char const * s, size_t n, ao_scan_t const * o, double * v);
size_t ao_scanff( char const * s, size_t n, ao_scan_t const * o, float * v);
size_t ao_scanfl( char const * s, size_t n, ao_scan_t const * o, long double * v);
```

Convert a signed integer from string.

```c
size_t ao_scani8( char const * s, size_t n, ao_scan_t const * o, int8_t * v);
size_t ao_scani16(char const * s, size_t n, ao_scan_t const * o, int16_t * v);
size_t ao_scani32(char const * s, size_t n, ao_scan_t const * o, int32_t * v);
size_t ao_scani64(char const * s, size_t n, ao_scan_t const * o, int64_t * v);
```

Convert an unsigned integer from string.

```c
size_t ao_scanu8( char const * s, size_t n, ao_scan_t const * o, uint8_t * v);
size_t ao_scanu16(char const * s, size_t n, ao_scan_t const * o, uint16_t * v);
size_t ao_scanu32(char const * s, size_t n, ao_scan_t const * o, uint32_t * v);
size_t ao_scanu64(char const * s, size_t n, ao_scan_t const * o, uint64_t * v);
```

The respective suffix indicates, which kind of number to convert to, as well as the destination type. All the functions have the same parameter list.

| `s` | The string to convert. |
| `n` | The maximum number of characters to read from the string. |
| `o` | The conversion options. |
| `v` | The pointer to a location where to store the result. |

The return value indicates the actual number of bytes that have been read. The value `0` indicates, that the conversion has failed.

# Example

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
