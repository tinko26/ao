---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_uint.h/
toc: true
---

# Notes

This module defines the fastest unsigned integer type available on the target platform. Additionally, it provides a couple of useful functions.

# Include

```c
#include <stdint.h>
#include <xc.h>
```

# Constants

## `AO_UINT_BITS`
## `AO_UINT_BITS_LOG`

The size in bits and the base-2 logarithm thereof.

```c
#define AO_UINT_BITS     (32)
#define AO_UINT_BITS_LOG (5)
```

## `AO_UINT_MAX`
## `AO_UINT_MIN`

The maximum and minimum value.

```c
#define AO_UINT_MAX (UINT32_MAX)
#define AO_UINT_MIN (0)
```

## `AO_UINT_SIZE`

The size in bytes.

```c
#define AO_UINT_SIZE (4)
```

# Typedefs

```c
typedef uint32_t ao_uint_t;
```

# Types

## `ao_uint_t`

This type represents the fastest unsigned integer type of the target platform. It defined to be the `uint32_t` type defined by the standard library.

# Functions

## `ao_clou`
## `ao_clzu`
## `ao_ctou`
## `ao_ctzu`

Count the number of leading or trailing ones or zeros, respectively.

```c
#define ao_clou(x)
#define ao_clzu(x)
#define ao_ctou(x)
#define ao_ctzu(x)
```

## `ao_ffsu`
## `ao_flsu`

Find the first or last set bit, respectively.

```c
#define ao_ffsu(x)
#define ao_flsu(x)
```

## `AO_LOG2U`

Calculate the base-2 logarithm.

```c
#define AO_LOG2U(x)
```

## `AO_LOG2U2`
## `AO_LOG2U4`
## `AO_LOG2U8`
## `AO_LOG2U16`
## `AO_LOG2U32`
## `AO_LOG2U64`

Calculate the base-2 logarithm for a fixed-width unsigned integer.

```c
#define AO_LOG2U2(x)
#define AO_LOG2U4(x)
#define AO_LOG2U8(x)
#define AO_LOG2U16(x)
#define AO_LOG2U32(x)
#define AO_LOG2U64(x)
```
