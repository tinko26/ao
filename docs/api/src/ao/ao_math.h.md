---
author: "Stefan Wagner"
date: 2022-09-24
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

# Identifier

```c
#define AO_MATH
```

# Functions

## `AO_ABS`

```c
#define AO_ABS(x) \
(                 \
    (x) < (0)     \
    ? -(x)        \
    :  (x)        \
)
```

Calculates the absolute value of $$\texttt{x}$$.

## `AO_CLAMP`

```c
#define AO_CLAMP(x, x_min, x_max) \
(                                 \
    (x) <= (x_min)                \
    ? (x_min)                     \
    :                             \
    (                             \
        (x) >= (x_max)            \
        ? (x_max)                 \
        : (x)                     \
    )                             \
)
```

Clamps $$\texttt{x}$$ into the interval $$\left[\texttt{x_min}, \texttt{x_max}\right]$$

## `AO_IS_EQUAL`
## `AO_IS_GREATER`
## `AO_IS_GREATER_EQUAL`
## `AO_IS_LESS`
## `AO_IS_LESS_EQUAL`

```c
#define AO_IS_EQUAL(x, y)         ((x) == (y) ? true : false)
#define AO_IS_GREATER(x, y)       ((x) >  (y) ? true : false)
#define AO_IS_GREATER_EQUAL(x, y) ((x) >= (y) ? true : false)
#define AO_IS_LESS(x, y)          ((x) <  (y) ? true : false)
#define AO_IS_LESS_EQUAL(x, y)    ((x) <= (y) ? true : false)
```

Compares $$\texttt{x}$$ to $$\texttt{y}$$.

## `AO_IS_NEGATIVE`
## `AO_IS_POSITIVE`
## `AO_IS_ZERO`

```c
#define AO_IS_NEGATIVE(x) ((x) <  (0) ? true : false)
#define AO_IS_POSITIVE(x) ((x) >  (0) ? true : false)
#define AO_IS_ZERO(x)     ((x) == (0) ? true : false)
```

Checks whether $$\texttt{x}$$ is negative, positive, or equal to zero, respectively.

## `AO_MAX`
## `AO_MIN`

```c
#define AO_MAX(x, y) ((x) >= (y) ? (x) : (y))
#define AO_MIN(x, y) ((x) <= (y) ? (x) : (y))
```

Calculates the maximum or minimum, respectively, of $$\texttt{x}$$ and $$\texttt{y}$$.
