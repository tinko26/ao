---
author: "Stefan Wagner"
date: 2022-09-27
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_int.h/
toc: true
---

# Notes

This module defines the fastest signed integer type available on the target platform.

# Include

| `stdint.h` |

# Constants

## `AO_INT_MAX`
## `AO_INT_MIN`

```c
#define AO_INT_MAX (INT32_MAX)
#define AO_INT_MIN (INT32_MIN)
```

The maximum and minimum value.

## `AO_INT_SIZE`

```c
#define AO_INT_SIZE (4)
```

The size, in bytes.

# Types

## `ao_int_t`

```c
typedef int32_t ao_int_t;
```

Represents the fastest signed integer type of the target platform.
