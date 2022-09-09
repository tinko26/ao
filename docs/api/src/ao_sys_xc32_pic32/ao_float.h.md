---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_float.h/
toc: true
---

# Notes

This module defines the fastest floating-point type available on the target platform. Additionally, it provides a couple of mathematical functions for that type.

# Configuration

## `AO_FLOAT`

The size of a floating-point number in bits.

```c
#define AO_FLOAT (32)
```

The following options are available.

| 32 | The `ao_float_t` type is defined to be the `float` type, which is always 32 bits wide. |
| 64 | The `ao_float_t` type is defined to be the `long double` type, which is always 64 bits wide. |
