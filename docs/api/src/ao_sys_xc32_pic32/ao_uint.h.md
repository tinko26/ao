---
api: true
author: "Stefan Wagner"
date: 2022-09-05
description: "The /src/ao_sys_xc32_pic32/ao_uint.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_uint.h/
subtitle: "Unsigned integers"
title: "ao_uint.h"
toc: true
---

# Overview

This module defines the fastest unsigned integer type available on the target platform. Additionally, it provides a couple of useful functions.

# Include

```c
#include <stdint.h>
#include <xc.h>
```

# Typedefs

The `ao_uint_t` type represents the fastest unsigned integer type of the target platform. It is an alias for the `uint32_t` fixed-width unsigned integer type defined by the standard library.

```c
typedef uint32_t ao_uint_t;
```

# Constants

The size in bits and the base-2 logarithm thereof.

```c
#define AO_UINT_BITS     (32)
#define AO_UINT_BITS_LOG (5)
```

The maximum and minimum value.

```c
#define AO_UINT_MAX      (UINT32_MAX)
#define AO_UINT_MIN      (0)
```

The size in bytes.

```c
#define AO_UINT_SIZE     (4)
```

# Functions

Count the number of leading or trailing ones or zeros, respectively.

```c
#define ao_clou(x)
#define ao_clzu(x)
#define ao_ctou(x)
#define ao_ctzu(x)
```

Find the first or last set bit, respectively.

```c
#define ao_ffsu(x)
#define ao_flsu(x)
```

Calculate the base-2 logarithm.

```c
#define AO_LOG2U(x)
```

Calculate the base-2 logarithm for a fixed-width unsigned integer.

```c
#define AO_LOG2U2(x)
#define AO_LOG2U4(x)
#define AO_LOG2U8(x)
#define AO_LOG2U16(x)
#define AO_LOG2U32(x)
#define AO_LOG2U64(x)
```
