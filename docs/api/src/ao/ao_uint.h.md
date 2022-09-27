---
author: "Stefan Wagner"
date: 2022-09-27
draft: true
permalink: /api/src/ao/ao_uint.h/
toc: true
---

# Notes

This module defines the fastest unsigned integer type available on the target platform. Additionally, it provides a couple of useful functions.

# Include

| `stdint.h` |

# Constants

## `AO_UINT_BITS`
## `AO_UINT_BITS_LOG`

```c
#define AO_UINT_BITS     (32)
#define AO_UINT_BITS_LOG (5)
```

The size, in bits, and the base-2 logarithm thereof.

## `AO_UINT_MAX`
## `AO_UINT_MIN`

```c
#define AO_UINT_MAX (UINT32_MAX)
#define AO_UINT_MIN (0)
```

The maximum and minimum value.

## `AO_UINT_SIZE`

```c
#define AO_UINT_SIZE (4)
```

The size, in bytes.

# Types

## `ao_uint_t`

```c
typedef uint32_t ao_uint_t;
```

Represents the fastest unsigned integer type of the target platform.

# Functions

## `ao_clou`
## `ao_clzu`
## `ao_ctou`
## `ao_ctzu`

```c
ao_uint_t ao_clou(ao_uint_t x);
ao_uint_t ao_clzu(ao_uint_t x);
ao_uint_t ao_ctou(ao_uint_t x);
ao_uint_t ao_ctzu(ao_uint_t x);
```

Counts the number of leading or trailing ones or zeros, respectively.

## `ao_ffsu`
## `ao_flsu`

```c
ao_uint_t ao_ffsu(ao_uint_t x);
ao_uint_t ao_flsu(ao_uint_t x);
```

Finds the first or last set bit, respectively.

## `AO_LOG2U`

```c
#define AO_LOG2U(x) \
(                   \
    AO_LOG2U32(x)   \
)
```

Calculates the base-2 logarithm.

## `AO_LOG2U*`

```c
#define AO_LOG2U2( x) ((x) & 0x0000000000000002U ?  1                         : 0            )
#define AO_LOG2U4( x) ((x) & 0x000000000000000CU ?  2 + AO_LOG2U2 ((x) >>  2) : AO_LOG2U2 (x))
#define AO_LOG2U8( x) ((x) & 0x00000000000000F0U ?  4 + AO_LOG2U4 ((x) >>  4) : AO_LOG2U4 (x))
#define AO_LOG2U16(x) ((x) & 0x000000000000FF00U ?  8 + AO_LOG2U8 ((x) >>  8) : AO_LOG2U8 (x))
#define AO_LOG2U32(x) ((x) & 0x00000000FFFF0000U ? 16 + AO_LOG2U16((x) >> 16) : AO_LOG2U16(x))
#define AO_LOG2U64(x) ((x) & 0xFFFFFFFF00000000U ? 32 + AO_LOG2U32((x) >> 32) : AO_LOG2U32(x))
```

Calculates the base-2 logarithm of a fixed-width unsigned integer value.
