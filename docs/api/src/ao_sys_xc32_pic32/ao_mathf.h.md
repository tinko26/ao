---
api: true
author: "Stefan Wagner"
date: 2022-09-05
description: "The /src/ao_sys_xc32_pic32/ao_mathf.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_mathf.h/
subtitle: "Mathematics for floating-point numbers"
title: "ao_mathf.h"
toc: true
---

# Overview

This module provides mathematical constants and functions for floating-point numbers.

# Include

```c
#include <math.h>
```

# Functions

## Absolute value

Get the absolute value of $$\texttt{x}$$.

```c
#define ao_fabsd(x)
#define ao_fabsf(x)
#define ao_fabsl(x)
```

## Classification

Check whether $$\texttt{x}$$ is finite.

```c
#define ao_isfinited(x)
#define ao_isfinitef(x)
#define ao_isfinitel(x)
```

Check whether $$\texttt{x}$$ is positive or negative infinity.

```c
#define ao_isinfd(x)
#define ao_isinff(x)
#define ao_isinfl(x)
```

Check whether $$\texttt{x}$$ is not a number.

```c
#define ao_isnand(x)
#define ao_isnanf(x)
#define ao_isnanl(x)
```

## Division

Get the remainder of $$\frac{\texttt{x}}{\texttt{y}}$$ rounded to zero.

```c
#define ao_fmodd(x, y)
#define ao_fmodf(x, y)
#define ao_fmodl(x, y)
```

## Exponential Functions

Get $$e^\texttt{x}$$.

```c
#define ao_expd(x)
#define ao_expf(x)
#define ao_expl(x)
```

## Hyperbolic functions

Get the area hyperbolic cosine of $$\texttt{x}$$.

```c
#define ao_acoshd(x)
#define ao_acoshf(x)
#define ao_acoshl(x)
```

Get the area hyperbolic tangent of $$\texttt{x}$$.

```c
#define ao_atanhd(x)
#define ao_atanhf(x)
#define ao_atanhl(x)
```










```c
#define ao_acosd(x)
#define ao_acosf(x)
#define ao_acosl(x)
```

```c
#define ao_asind(x)
#define ao_asinf(x)
#define ao_asinl(x)
```

```c
#define ao_atand(x)
#define ao_atanf(x)
#define ao_atanl(x)
```

```c
#define ao_atan2d(y, x)
#define ao_atan2f(y, x)
#define ao_atan2l(y, x)
```

```c
#define ao_cbrtd(x)
#define ao_cbrtf(x)
#define ao_cbrtl(x)
```

```c
#define ao_ceild(x)
#define ao_ceilf(x)
#define ao_ceill(x)
```

```c
#define ao_cosd(x)
#define ao_cosf(x)
#define ao_cosl(x)
```

```c
#define ao_floord(x)
#define ao_floorf(x)
#define ao_floorl(x)
```

```c
#define ao_frexpd(x, exp)
#define ao_frexpf(x, exp)
#define ao_frexpl(x, exp)
```

```c
#define ao_hypotd(x, y)
#define ao_hypotf(x, y)
#define ao_hypotl(x, y)
```

```c
#define ao_ldexpd(x, exp)
#define ao_ldexpf(x, exp)
#define ao_ldexpl(x, exp)
```

```c
#define ao_logd(x)
#define ao_logf(x)
#define ao_logl(x)
```

```c
#define ao_modfd(x, intpart)
#define ao_modff(x, intpart)
#define ao_modfl(x, intpart)
```

```c
#define ao_powd(x, y)
#define ao_powf(x, y)
#define ao_powl(x, y)
```

```c
#define ao_sind(x)
#define ao_sinf(x)
#define ao_sinl(x)
```

```c
#define ao_sqrtd(x)
#define ao_sqrtf(x)
#define ao_sqrtl(x)
```

```c
#define ao_tand(x)
#define ao_tanf(x)
#define ao_tanl(x)
```

# Include Next

```c
#include_next <ao_mathf.h>
```
