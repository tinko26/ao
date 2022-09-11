---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_mathf.h/
toc: true
---

# Notes

This module provides mathematical constants and functions for floating-point numbers.

# Include

```c
#include <math.h>
```

# Functions

## `ao_acos`

```c
#define ao_acosd(x) acos(x)
#define ao_acosf(x) acosf(x)
#define ao_acosl(x) acosl(x)
```

Calculates the arc cosine of $$\texttt{x}$$.

## `ao_acosh`

```c
#define ao_acoshd(x) acosh(x)
#define ao_acoshf(x) acoshf(x)
#define ao_acoshl(x) acoshl(x)
```

Calculates the area hyperbolic cosine of $$\texttt{x}$$.

## `ao_asin`

```c
#define ao_asind(x) asin(x)
#define ao_asinf(x) asinf(x)
#define ao_asinl(x) asinl(x)
```

Calculates the arc sine of $$\texttt{x}$$.

## `ao_asinh`

```c
#define ao_asinhd(x) asinh(x)
#define ao_asinhf(x) asinhf(x)
#define ao_asinhl(x) asinhl(x)
```

Calculates the area hyperbolic sine of $$\texttt{x}$$.

## `ao_atan`

```c
#define ao_atand(x) atan(x)
#define ao_atanf(x) atanf(x)
#define ao_atanl(x) atanl(x)
```

Calculates the arc tangent of $$\texttt{x}$$.

## `ao_atan2`

```c
#define ao_atan2d(y, x) atan2(y, x)
#define ao_atan2f(y, x) atan2f(y, x)
#define ao_atan2l(y, x) atan2l(y, x)
```

Calculates the arc tangent of $$\frac{\texttt{y}}{\texttt{x}}$$.

## `ao_atanh`

```c
#define ao_atanhd(x) atanh(x)
#define ao_atanhf(x) atanhf(x)
#define ao_atanhl(x) atanhl(x)
```

Calculates the area hyperbolic tangent of $$\texttt{x}$$.

## `ao_cbrt`

```c
#define ao_cbrtd(x) cbrt(x)
#define ao_cbrtf(x) cbrtf(x)
#define ao_cbrtl(x) cbrtl(x)
```

Calculates the cubic root of $$\texttt{x}$$.

## `ao_ceil`

```c
#define ao_ceild(x) ceil(x)
#define ao_ceilf(x) ceilf(x)
#define ao_ceill(x) ceill(x)
```

Rounds $$\texttt{x}$$ up.

## `ao_cos`

```c
#define ao_cosd(x) cos(x)
#define ao_cosf(x) cosf(x)
#define ao_cosl(x) cosl(x)
```

Calculates the cosine of $$\texttt{x}$$.

## `ao_cosh`

```c
#define ao_coshd(x) cosh(x)
#define ao_coshf(x) coshf(x)
#define ao_coshl(x) coshl(x)
```

Calculates the hyperbolic cosine of $$\texttt{x}$$.

## `ao_exp`

```c
#define ao_expd(x) exp(x)
#define ao_expf(x) expf(x)
#define ao_expl(x) expl(x)
```

Calculates $$e^\texttt{x}$$.

## `ao_fabs`

```c
#define ao_fabsd(x) fabs(x)
#define ao_fabsf(x) fabsf(x)
#define ao_fabsl(x) fabsl(x)
```

Calculates the absolute value of $$\texttt{x}$$.

## `ao_floor`

```c
#define ao_floord(x) floor(x)
#define ao_floorf(x) floorf(x)
#define ao_floorl(x) floorl(x)
```

Rounds $$\texttt{x}$$ down.

## `ao_fmod`

```c
#define ao_fmodd(x, y) fmod(x, y)
#define ao_fmodf(x, y) fmodf(x, y)
#define ao_fmodl(x, y) fmodl(x, y)
```

Calculates the remainder of $$\frac{\texttt{x}}{\texttt{y}}$$ rounded to zero.

## `ao_frexp`

```c
#define ao_frexpd(x, exp) frexp(x, exp)
#define ao_frexpf(x, exp) frexpf(x, exp)
#define ao_frexpl(x, exp) frexpl(x, exp)
```

Breaks $$\texttt{x}$$ into its binary significant and an integral exponent for 2.

## `ao_hypot`

```c
#define ao_hypotd(x, y) hypot(x, y)
#define ao_hypotf(x, y) hypotf(x, y)
#define ao_hypotl(x, y) hypotl(x, y)
```

Calculates $$\sqrt{\texttt{x}^2 + \texttt{y}^2}$$.

## `ao_isfinite`

```c
#define ao_isfinited(x) isfinite(x)
#define ao_isfinitef(x) isfinitef(x)
#define ao_isfinitel(x) isfinitel(x)
```

Checks whether $$\texttt{x}$$ is finite.

## `ao_isinf`

```c
#define ao_isinfd(x) isinf(x)
#define ao_isinff(x) isinff(x)
#define ao_isinfl(x) isinfl(x)
```

Checks whether $$\texttt{x}$$ is positive or negative infinity.

## `ao_isnan`

```c
#define ao_isnand(x) isnan(x)
#define ao_isnanf(x) isnanf(x)
#define ao_isnanl(x) isnanl(x)
```

Checks whether $$\texttt{x}$$ is not a number.

## `ao_ldexp`

```c
#define ao_ldexpd(x, exp) ldexp(x, exp)
#define ao_ldexpf(x, exp) ldexpf(x, exp)
#define ao_ldexpl(x, exp) ldexpl(x, exp)
```

Calculates $$\texttt{x} \cdot 2^{\texttt{exp}}$$.

## `ao_log`

```c
#define ao_logd(x) log(x)
#define ao_logf(x) logf(x)
#define ao_logl(x) logl(x)
```

Calculates the natural logarithm of $$\texttt{x}$$.

## `ao_log10`

```c
#define ao_log10d(x) log10(x)
#define ao_log10f(x) log10f(x)
#define ao_log10l(x) log10l(x)
```

Calculates the common logarithm of $$\texttt{x}$$.

## `ao_modf`

```c
#define ao_modfd(x, intpart) modf(x, intpart)
#define ao_modff(x, intpart) modff(x, intpart)
#define ao_modfl(x, intpart) modfl(x, intpart)
```

Breaks $$\texttt{x}$$ into an integral and a fractional part.

## `ao_pow`

```c
#define ao_powd(x, y) pow(x, y)
#define ao_powf(x, y) powf(x, y)
#define ao_powl(x, y) powl(x, y)
```

Calculates $$\texttt{x}^\texttt{y}$$.

## `ao_sin`

```c
#define ao_sind(x) sin(x)
#define ao_sinf(x) sinf(x)
#define ao_sinl(x) sinl(x)
```

Calculates the sine of $$\texttt{x}$$.

## `ao_sinh`

```c
#define ao_sinhd(x) sinh(x)
#define ao_sinhf(x) sinhf(x)
#define ao_sinhl(x) sinhl(x)
```

Calculates the hyperbolic sine of $$\texttt{x}$$.

## `ao_sqrt`

```c
#define ao_sqrtd(x) sqrt(x)
#define ao_sqrtf(x) sqrtf(x)
#define ao_sqrtl(x) sqrtl(x)
```

Calculates the square root of $$\texttt{x}$$.

## `ao_tan`

```c
#define ao_tand(x) tan(x)
#define ao_tanf(x) tanf(x)
#define ao_tanl(x) tanl(x)
```

Calculates the tangent of $$\texttt{x}$$.

## `ao_tanh`

```c
#define ao_tanhd(x) tanh(x)
#define ao_tanhf(x) tanhf(x)
#define ao_tanhl(x) tanhl(x)
```

Calculates the hyperbolic tangent of $$\texttt{x}$$.

# Include Next

```c
#include_next <ao_mathf.h>
```
