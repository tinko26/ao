---
author: "Stefan Wagner"
date: 2022-09-24
draft: true
external:
- https://en.wikipedia.org/wiki/Radix : "Radix"
permalink: /api/src/ao/ao_scan.h/
toc: true
---

# Notes

This module contains functions to convert a string to a number. Although the standard library contains similar functions, these are not available in a freestanding runtime environment.

# Include

| `stdbool.h` |
| `stddef.h` |
| `stdint.h` |

# Types

## `ao_scan_t`

```c
typedef struct ao_scan_t ao_scan_t;
```

Represents options for the conversion.

# Structs

## `ao_scan_t`

```c
struct ao_scan_t
{
    size_t radix;
    bool   seek;
};
```

| `radix` | The radix of the positional numeral system, wherein the number is represented. |
| `seek` | Indicates whether to seek for a valid character (sign, digit, or decimal separator) before the conversion. |

# Functions

## `ao_scanf*`

```c
size_t ao_scanfd(char const * s, size_t n, ao_scan_t const * o, double      * v);
size_t ao_scanff(char const * s, size_t n, ao_scan_t const * o, float       * v);
size_t ao_scanfl(char const * s, size_t n, ao_scan_t const * o, long double * v);
```

| `s` | The string to convert. |
| `n` | The maximum number of characters to read from the string. |
| `o` | The conversion options. |
| `v` | The pointer to a location where to store the result. |

Converts a floating-point number from string. The respective suffix indicates, which kind of number to convert to, as well as the destination type. The return value indicates the actual number of bytes that have been read. The value `0` indicates, that the conversion has failed. All the functions have the same parameter list.

## `ao_scani*`

```c
size_t ao_scani8 (char const * s, size_t n, ao_scan_t const * o, int8_t  * v);
size_t ao_scani16(char const * s, size_t n, ao_scan_t const * o, int16_t * v);
size_t ao_scani32(char const * s, size_t n, ao_scan_t const * o, int32_t * v);
size_t ao_scani64(char const * s, size_t n, ao_scan_t const * o, int64_t * v);
```

| `s` | The string to convert. |
| `n` | The maximum number of characters to read from the string. |
| `o` | The conversion options. |
| `v` | The pointer to a location where to store the result. |

Converts a signed integer from string. The respective suffix indicates, which kind of number to convert to, as well as the destination type. The return value indicates the actual number of bytes that have been read. The value `0` indicates, that the conversion has failed. All the functions have the same parameter list.

## `ao_scanu*`

```c
size_t ao_scanu8 (char const * s, size_t n, ao_scan_t const * o, uint8_t  * v);
size_t ao_scanu16(char const * s, size_t n, ao_scan_t const * o, uint16_t * v);
size_t ao_scanu32(char const * s, size_t n, ao_scan_t const * o, uint32_t * v);
size_t ao_scanu64(char const * s, size_t n, ao_scan_t const * o, uint64_t * v);
```

| `s` | The string to convert. |
| `n` | The maximum number of characters to read from the string. |
| `o` | The conversion options. |
| `v` | The pointer to a location where to store the result. |

Converts an unsigned integer from string. The respective suffix indicates, which kind of number to convert to, as well as the destination type. The return value indicates the actual number of bytes that have been read. The value `0` indicates, that the conversion has failed. All the functions have the same parameter list.
