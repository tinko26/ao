---
author: "Stefan Wagner"
date: 2022-08-30
draft: true
permalink: /api/src/ao/ao_int.h/
toc: true
---

# Notes

This module defines the fastest signed integer type available on the target platform. This module is considered abstract and should be overridden by a port package.

# Include

```c
#include <stdint.h>
```

# Constants

## `AO_INT_MAX`
## `AO_INT_MIN`

The maximum and minimum value.

```c
#define AO_INT_MAX (INT32_MAX)
#define AO_INT_MIN (INT32_MIN)
```

## `AO_INT_SIZE`

The size in bytes.

```c
#define AO_INT_SIZE (4)
```

# Typedefs

```c
typedef int32_t ao_int_t;
```

# Types

## `ao_int_t`

This type represents the fastest signed integer type of the target platform. It is an alias for one of the fixed-width signed integer types defined by the standard library.
