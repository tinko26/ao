---
author: "Stefan Wagner"
date: 2022-09-11
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_float.h/
seealso:
- /api/src/ao/ao_floatf.h/
- /api/src/ao/ao_floatl.h/
toc: true
---

# Notes

This module defines the fastest floating-point type available on the target platform. Additionally, it provides a couple of mathematical functions for that type.

# Configuration

## `AO_FLOAT`

```c
#define AO_FLOAT (32)
```

The size of a floating-point number, in bits. The following options are available.

| `32` | Includes the [`ao_floatf.h`](../ao/ao_floatf.h.md) module, which defines the fastest floating-point type available on the target platform to be the `float` type, which is always 32 bits wide. |
| `64` | Includes the [`ao_floatl.h`](../ao/ao_floatl.h.md) module, which defines the fastest floating-point type available on the target platform to be the `long double` type, which is always 64 bits wide. |
