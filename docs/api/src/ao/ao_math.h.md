---
author: "Stefan Wagner"
date: 2022-08-30
draft: true
permalink: /api/src/ao/ao_math.h/
toc: true
---

# Notes

This module provides a number of useful mathematical operations. They are implemented as macro functions, that work for all fundamental scalar types. This is for two reasons. First, when called with constant parameter values, the result can be evaluated at compile time. Second, they can be used in the definition of macro constants. However, care must be taken for side effects, as some parameter values get evaluated more than once.

# Include

```c
#include <stdbool.h>
```

# Functions

## `AO_ABS`

Absolute value.

```c
#define AO_ABS(x)
```

## `AO_CLAMP`

Clamping.

```c
#define AO_CLAMP(x, x_min, x_max)
```

## `AO_IS_EQUAL`
## `AO_IS_GREATER`
## `AO_IS_GREATER_EQUAL`
## `AO_IS_LESS`
## `AO_IS_LESS_EQUAL`

Comparison.

```c
#define AO_IS_EQUAL(x, y)
#define AO_IS_GREATER(x, y)
#define AO_IS_GREATER_EQUAL(x, y)
#define AO_IS_LESS(x, y)
#define AO_IS_LESS_EQUAL(x, y)
```

## `AO_IS_NEGATIVE`
## `AO_IS_POSITIVE`
## `AO_IS_ZERO`

Sign.

```c
#define AO_IS_NEGATIVE(x)
#define AO_IS_POSITIVE(x)
#define AO_IS_ZERO(x)
```

## `AO_MAX`
## `AO_MIN`

Maximum and minimum.

```c
#define AO_MAX(x, y)
#define AO_MIN(x, y)
```
