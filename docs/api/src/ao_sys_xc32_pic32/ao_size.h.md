---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_size.h/
toc: true
---

# Notes

The standard library's `size_t` type is an unsigned integer type, at least 16 bits wide, that can store the size of any kind of object, from single numbers to huge arrays. It is intended to be used for loop counters and array indexes. This module specifies properties of the type and provides a couple of useful functions.

# Include

```c
#include <ao_uint.h>
```

# Constants

## `AO_SIZE_BITS`
## `AO_SIZE_BITS_LOG`

```c
#define AO_SIZE_BITS     (AO_UINT_BITS)
#define AO_SIZE_BITS_LOG (AO_UINT_BITS_LOG)
```

The size, in bits, and the base-2 logarithm thereof.

## `AO_SIZE_MAX`
## `AO_SIZE_MIN`

```c
#define AO_SIZE_MAX (AO_UINT_MAX)
#define AO_SIZE_MIN (AO_UINT_MIN)
```

The maximum and minimum value.

## `AO_SIZE_SIZE`

```c
#define AO_SIZE_SIZE (AO_UINT_SIZE)
```

The size, in bytes.

# Functions

## `ao_cloz`
## `ao_clzz`
## `ao_ctoz`
## `ao_ctzz`

```c
#define ao_cloz(x)
#define ao_clzz(x)
#define ao_ctoz(x)
#define ao_ctzz(x)
```

Counts the number of leading or trailing ones or zeros, respectively.

## `ao_ffsz`
## `ao_flsz`

```c
#define ao_ffsz(x)
#define ao_flsz(x)
```

Finds the first or last set bit, respectively.

## `AO_LOG2Z`

```c
#define AO_LOG2Z(x)
```

Calculates the base-2 logarithm.
