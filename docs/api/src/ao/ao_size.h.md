---
author: "Stefan Wagner"
date: 2022-08-30
draft: true
permalink: /api/src/ao/ao_size.h/
toc: true
---

# Notes

The standard library's `size_t` type is an unsigned integer type, at least 16 bits wide, that can store the size of any kind of object, from single numbers to huge arrays. It is intended to be used for loop counters and array indexes. This module specifies properties of the type and provides a couple of useful functions. This module is considered abstract and should be overridden by a port package.

# Include

```c
#include <ao_uint.h>
#include <stddef.h>
#include <stdint.h>
```

# Constants

## `AO_SIZE_BITS`
## `AO_SIZE_BITS_LOG`

```c
#define AO_SIZE_BITS     (32)
#define AO_SIZE_BITS_LOG (5)
```

The size, in bits, and the base-2 logarithm thereof.

## `AO_SIZE_MAX`
## `AO_SIZE_MIN`

```c
#define AO_SIZE_MAX (SIZE_MAX)
#define AO_SIZE_MIN (0)
```

The maximum and minimum value.

## `AO_SIZE_SIZE`

```c
#define AO_SIZE_SIZE (4)
```

The size, in bytes.

# Functions

## `ao_cloz`
## `ao_clzz`
## `ao_ctoz`
## `ao_ctzz`

```c
size_t ao_cloz(size_t x);
size_t ao_clzz(size_t x);
size_t ao_ctoz(size_t x);
size_t ao_ctzz(size_t x);
```

Counts the number of leading or trailing ones or zeros, respectively.

## `ao_ffsz`
## `ao_flsz`

```c
size_t ao_ffsz(size_t x);
size_t ao_flsz(size_t x);
```

Finds the first or last set bit, respectively.

## `AO_LOG2Z`

```c
#define AO_LOG2Z(x) AO_LOG2U32(x)
```

Calculates the base-2 logarithm.
