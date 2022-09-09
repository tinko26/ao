---
author: "Stefan Wagner"
date: 2022-08-30
draft: true
permalink: /api/src/ao/ao_uint.h/
toc: true
---

# Notes

This module defines the fastest unsigned integer type available on the target platform. Additionally, it provides a couple of useful functions. This module is considered abstract and should be overridden by a port package.

# Include

```c
#include <stdint.h>
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

This type represents the fastest unsigned integer type of the target platform. It is an alias for one of the fixed-width unsigned integer types defined by the standard library.

# Functions

## `ao_clou`
## `ao_clzu`
## `ao_ctou`
## `ao_ctzu`

Count the number of leading or trailing ones or zeros, respectively.

```c
ao_uint_t ao_clou(ao_uint_t x);
ao_uint_t ao_clzu(ao_uint_t x);
ao_uint_t ao_ctou(ao_uint_t x);
ao_uint_t ao_ctzu(ao_uint_t x);
```

## `ao_ffsu`
## `ao_flsu`

Find the first or last set bit, respectively.

```c
ao_uint_t ao_ffsu(ao_uint_t x);
ao_uint_t ao_flsu(ao_uint_t x);
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
