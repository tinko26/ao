---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_mathf.h/
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

Get the area hyperbolic sine of $$\texttt{x}$$.

```c
#define ao_asinhd(x)
#define ao_asinhf(x)
#define ao_asinhl(x)
```

Get the area hyperbolic tangent of $$\texttt{x}$$.

```c
#define ao_atanhd(x)
#define ao_atanhf(x)
#define ao_atanhl(x)
```

Get the hyperbolic cosine of $$\texttt{x}$$.

```c
#define ao_coshd(x)
#define ao_coshf(x)
#define ao_coshl(x)
```

Get the hyperbolic sine of $$\texttt{x}$$.

```c
#define ao_sinhd(x)
#define ao_sinhf(x)
#define ao_sinhl(x)
```

Get the hyperbolic tangent of $$\texttt{x}$$.

```c
#define ao_tanhd(x)
#define ao_tanhf(x)
#define ao_tanhl(x)
```

## Logarithmic functions

Break $$\texttt{x}$$ into its binary significant and an integral exponent for 2.

```c
#define ao_frexpd(x, exp)
#define ao_frexpf(x, exp)
#define ao_frexpl(x, exp)
```

Get the natural logarithm of $$\texttt{x}$$.

```c
#define ao_logd(x)
#define ao_logf(x)
#define ao_logl(x)
```

Get the common logarithm of $$\texttt{x}$$.

```c
#define ao_log10d(x)
#define ao_log10f(x)
#define ao_log10l(x)
```

## Power Functions

Get the cubic root of $$\texttt{x}$$.

```c
#define ao_cbrtd(x)
#define ao_cbrtf(x)
#define ao_cbrtl(x)
```

Get $$\sqrt{\texttt{x}^2 + \texttt{y}^2}$$.

```c
#define ao_hypotd(x, y)
#define ao_hypotf(x, y)
#define ao_hypotl(x, y)
```

Get $$\texttt{x} \cdot 2^{\texttt{exp}}$$.

```c
#define ao_ldexpd(x, exp)
#define ao_ldexpf(x, exp)
#define ao_ldexpl(x, exp)
```

Get $$\texttt{x}^\texttt{y}$$.

```c
#define ao_powd(x, y)
#define ao_powf(x, y)
#define ao_powl(x, y)
```

Get the square root of $$\texttt{x}$$.

```c
#define ao_sqrtd(x)
#define ao_sqrtf(x)
#define ao_sqrtl(x)
```

## Rounding

Round $$\texttt{x}$$ up.

```c
#define ao_ceild(x)
#define ao_ceilf(x)
#define ao_ceill(x)
```

Round $$\texttt{x}$$ down.

```c
#define ao_floord(x)
#define ao_floorf(x)
#define ao_floorl(x)
```

Break $$\texttt{x}$$ into an integral and a fractional part.

```c
#define ao_modfd(x, intpart)
#define ao_modff(x, intpart)
#define ao_modfl(x, intpart)
```

## Trigonometric Functions

Get the arc cosine of $$\texttt{x}$$.

```c
#define ao_acosd(x)
#define ao_acosf(x)
#define ao_acosl(x)
```

Get the arc sine of $$\texttt{x}$$.

```c
#define ao_asind(x)
#define ao_asinf(x)
#define ao_asinl(x)
```

Get the arc tangent of $$\texttt{x}$$.

```c
#define ao_atand(x)
#define ao_atanf(x)
#define ao_atanl(x)
```

Get the arc tangent of $$\frac{\texttt{y}}{\texttt{x}}$$.

```c
#define ao_atan2d(y, x)
#define ao_atan2f(y, x)
#define ao_atan2l(y, x)
```

Get the cosine of $$\texttt{x}$$.

```c
#define ao_cosd(x)
#define ao_cosf(x)
#define ao_cosl(x)
```

Get the sine of $$\texttt{x}$$.

```c
#define ao_sind(x)
#define ao_sinf(x)
#define ao_sinl(x)
```

Get the tangent of $$\texttt{x}$$.

```c
#define ao_tand(x)
#define ao_tanf(x)
#define ao_tanl(x)
```

# Include Next

```c
#include_next <ao_mathf.h>
```
