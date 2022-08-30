---
api: true
author: "Stefan Wagner"
date: 2022-08-30
description: "The /src/ao/ao_uint.h file of the ao real-time operating system."
draft: false
permalink: /api/src/ao/ao_uint.h/
subtitle: "Unsigned integers"
title: "ao_uint.h"
toc: true
---

# Overview

This module defines the fastest unsigned integer type available on the target platform. Additionally, it provides a couple of useful functions. This module is considered abstract and should be overridden by a port package.

# Include

```c
#include <stdint.h>
```

# Typedefs

```c
typedef uint32_t ao_uint_t;
```

# Constants

The size in bits and the base-2 logarithm thereof.

```c
#define AO_UINT_BITS (32)
#define AO_UINT_BITS_LOG (5)
```

The maximum and minimum value.

```c
#define AO_UINT_MAX (UINT32_MAX)
#define AO_UINT_MIN (0)
```

The size in bytes.

```c
#define AO_UINT_SIZE (4)
```

# Functions

Count the number of leading or trailing ones or zeros, respectively.

```c
ao_uint_t ao_clou(ao_uint_t x);
ao_uint_t ao_clzu(ao_uint_t x);
ao_uint_t ao_ctou(ao_uint_t x);
ao_uint_t ao_ctzu(ao_uint_t x);
```

Find the first or last set bit, respectively.

```c
ao_uint_t ao_ffsu(ao_uint_t x);
ao_uint_t ao_flsu(ao_uint_t x);
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
