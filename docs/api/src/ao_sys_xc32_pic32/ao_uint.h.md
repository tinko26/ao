---
author: "Stefan Wagner"
date: 2022-09-27
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_uint.h/
toc: true
---

# Notes

This module defines the fastest unsigned integer type available on the target platform. Additionally, it provides a couple of useful functions.

# Include

| `stdint.h` |
| `xc.h` |

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
#define ao_clou(x) _clo(  x )
#define ao_clzu(x) _clz(  x )
#define ao_ctou(x) _ctz(~(x))
#define ao_ctzu(x) _ctz(  x )
```

Counts the number of leading or trailing ones or zeros, respectively.

## `ao_ffsu`
## `ao_flsu`

```c
#define ao_ffsu(x) (     _ctz(x))
#define ao_flsu(x) (31 - _clz(x))
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

# Include Next

[`ao_uint.h`](../ao/ao_uint.h.md)
