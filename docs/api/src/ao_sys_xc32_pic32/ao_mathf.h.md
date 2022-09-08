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

## `ao_acos`

Get the arc cosine of $$\texttt{x}$$.

```c
#define ao_acosd(x)
#define ao_acosf(x)
#define ao_acosl(x)
```

## `ao_acosh`

Get the area hyperbolic cosine of $$\texttt{x}$$.

```c
#define ao_acoshd(x)
#define ao_acoshf(x)
#define ao_acoshl(x)
```

## `ao_asin`

Get the arc sine of $$\texttt{x}$$.

```c
#define ao_asind(x)
#define ao_asinf(x)
#define ao_asinl(x)
```

## `ao_asinh`

Get the area hyperbolic sine of $$\texttt{x}$$.

```c
#define ao_asinhd(x)
#define ao_asinhf(x)
#define ao_asinhl(x)
```

## `ao_atan`

Get the arc tangent of $$\texttt{x}$$.

```c
#define ao_atand(x)
#define ao_atanf(x)
#define ao_atanl(x)
```

## `ao_atan2`

Get the arc tangent of $$\frac{\texttt{y}}{\texttt{x}}$$.

```c
#define ao_atan2d(y, x)
#define ao_atan2f(y, x)
#define ao_atan2l(y, x)
```

## `ao_atanh`

Get the area hyperbolic tangent of $$\texttt{x}$$.

```c
#define ao_atanhd(x)
#define ao_atanhf(x)
#define ao_atanhl(x)
```

## `ao_cbrt`

Get the cubic root of $$\texttt{x}$$.

```c
#define ao_cbrtd(x)
#define ao_cbrtf(x)
#define ao_cbrtl(x)
```

## `ao_ceil`

Round $$\texttt{x}$$ up.

```c
#define ao_ceild(x)
#define ao_ceilf(x)
#define ao_ceill(x)
```

## `ao_cos`

Get the cosine of $$\texttt{x}$$.

```c
#define ao_cosd(x)
#define ao_cosf(x)
#define ao_cosl(x)
```

## `ao_cosh`

Get the hyperbolic cosine of $$\texttt{x}$$.

```c
#define ao_coshd(x)
#define ao_coshf(x)
#define ao_coshl(x)
```

## `ao_exp`

Get $$e^\texttt{x}$$.

```c
#define ao_expd(x)
#define ao_expf(x)
#define ao_expl(x)
```

## `ao_fabs`

Get the absolute value of $$\texttt{x}$$.

```c
#define ao_fabsd(x)
#define ao_fabsf(x)
#define ao_fabsl(x)
```

## `ao_floor`

Round $$\texttt{x}$$ down.

```c
#define ao_floord(x)
#define ao_floorf(x)
#define ao_floorl(x)
```

## `ao_fmod`

Get the remainder of $$\frac{\texttt{x}}{\texttt{y}}$$ rounded to zero.

```c
#define ao_fmodd(x, y)
#define ao_fmodf(x, y)
#define ao_fmodl(x, y)
```

## `ao_frexp`

Break $$\texttt{x}$$ into its binary significant and an integral exponent for 2.

```c
#define ao_frexpd(x, exp)
#define ao_frexpf(x, exp)
#define ao_frexpl(x, exp)
```

## `ao_hypot`

Get $$\sqrt{\texttt{x}^2 + \texttt{y}^2}$$.

```c
#define ao_hypotd(x, y)
#define ao_hypotf(x, y)
#define ao_hypotl(x, y)
```

## `ao_isfinite`

Check whether $$\texttt{x}$$ is finite.

```c
#define ao_isfinited(x)
#define ao_isfinitef(x)
#define ao_isfinitel(x)
```

## `ao_isinf`

Check whether $$\texttt{x}$$ is positive or negative infinity.

```c
#define ao_isinfd(x)
#define ao_isinff(x)
#define ao_isinfl(x)
```

## `ao_isnan`

Check whether $$\texttt{x}$$ is not a number.

```c
#define ao_isnand(x)
#define ao_isnanf(x)
#define ao_isnanl(x)
```

## `ao_ldexp`

Get $$\texttt{x} \cdot 2^{\texttt{exp}}$$.

```c
#define ao_ldexpd(x, exp)
#define ao_ldexpf(x, exp)
#define ao_ldexpl(x, exp)
```

## `ao_log`

Get the natural logarithm of $$\texttt{x}$$.

```c
#define ao_logd(x)
#define ao_logf(x)
#define ao_logl(x)
```

## `ao_log10`

Get the common logarithm of $$\texttt{x}$$.

```c
#define ao_log10d(x)
#define ao_log10f(x)
#define ao_log10l(x)
```

## `ao_modf`

Break $$\texttt{x}$$ into an integral and a fractional part.

```c
#define ao_modfd(x, intpart)
#define ao_modff(x, intpart)
#define ao_modfl(x, intpart)
```

## `ao_pow`

Get $$\texttt{x}^\texttt{y}$$.

```c
#define ao_powd(x, y)
#define ao_powf(x, y)
#define ao_powl(x, y)
```

## `ao_sin`

Get the sine of $$\texttt{x}$$.

```c
#define ao_sind(x)
#define ao_sinf(x)
#define ao_sinl(x)
```

## `ao_sinh`

Get the hyperbolic sine of $$\texttt{x}$$.

```c
#define ao_sinhd(x)
#define ao_sinhf(x)
#define ao_sinhl(x)
```

## `ao_sqrt`

Get the square root of $$\texttt{x}$$.

```c
#define ao_sqrtd(x)
#define ao_sqrtf(x)
#define ao_sqrtl(x)
```

## `ao_tan`

Get the tangent of $$\texttt{x}$$.

```c
#define ao_tand(x)
#define ao_tanf(x)
#define ao_tanl(x)
```

## `ao_tanh`

Get the hyperbolic tangent of $$\texttt{x}$$.

```c
#define ao_tanhd(x)
#define ao_tanhf(x)
#define ao_tanhl(x)
```

# Include Next

```c
#include_next <ao_mathf.h>
```
