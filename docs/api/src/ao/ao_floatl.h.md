---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao/ao_floatl.h/
toc: true
---

# Overview

This module defines the fastest floating-point type available on the target platform to be the `long double` type.

# Include

```c
#include <ao_mathf.h>
#include <float.h>
```

# Constants

## `AO_FLOAT_DIG`

The number of decimal digits that are preserved, when converting a floating-point value to string and back again.

```c
#define AO_FLOAT_DIG (LDBL_DIG)
```

## `AO_FLOAT_EPSILON`

The difference between one and the next representable value.

```c
#define AO_FLOAT_EPSILON (LDBL_EPSILON)
```

## `AO_FLOAT_MAX`
## `AO_FLOAT_MIN`

The minimum and maximum value, respectively.

```c
#define AO_FLOAT_MAX (LDBL_MAX)
#define AO_FLOAT_MIN (LDBL_MIN)
```

# Typedefs

```c
typedef long double ao_float_t;
```

# Types

## `ao_float_t`

This type represents the fastest floating-point type available on the target platform.

# Functions

## `ao_acos`

Get the arc cosine of $$\texttt{x}$$.

```c
#define ao_acos(x)
```

## `ao_acosh`

Get the area hyperbolic cosine of $$\texttt{x}$$.

```c
#define ao_acosh(x)
```

## `ao_acot`

Get the arc cotangent of $$\texttt{x}$$.

```c
#define ao_acot(x)
```

## `ao_acoth`

Get the area hyperbolic cotangent of $$\texttt{x}$$.

```c
#define ao_acoth(x)
```

## `ao_acsc`

Get the arc cosecant of $$\texttt{x}$$.

```c
#define ao_acsc(x)
```

## `ao_acsch`

Get the area hyperbolic cosecant of $$\texttt{x}$$.

```c
#define ao_acsch(x)
```

## `ao_asec`

Get the arc secant of $$\texttt{x}$$.

```c
#define ao_asec(x)
```

## `ao_asech`

Get the area hyperbolic secant of $$\texttt{x}$$.

```c
#define ao_asech(x)
```

## `ao_asin`

Get the arc sine of $$\texttt{x}$$.

```c
#define ao_asin(x)
```

## `ao_asinh`

Get the area hyperbolic sine of $$\texttt{x}$$.

```c
#define ao_asinh(x)
```

## `ao_atan`

Get the arc tangent of $$\texttt{x}$$.

```c
#define ao_atan(x)
```

## `ao_atan2`

Get the arc tangent of $$\frac{\texttt{y}}{\texttt{x}}$$.

```c
#define ao_atan2(y, x)
```

## `ao_atanh`

Get the area hyperbolic tangent of $$\texttt{x}$$.

```c
#define ao_atanh(x)
```

## `ao_cbrt`

Get the cubic root of $$\texttt{x}$$.

```c
#define ao_cbrt(x)
```

## `ao_ceil`

Round $$\texttt{x}$$ up.

```c
#define ao_ceil(x)
```

## `ao_cos`

Get the cosine of $$\texttt{x}$$.

```c
#define ao_cos(x)
```

## `ao_cosh`

Get the hyperbolic cosine of $$\texttt{x}$$.

```c
#define ao_cosh(x)
```

## `ao_cot`

Get the cotangent of $$\texttt{x}$$.

```c
#define ao_cot(x)
```

## `ao_coth`

Get the hyperbolic cotangent of $$\texttt{x}$$.

```c
#define ao_coth(x)
```

## `ao_csc`

Get the cosecant of $$\texttt{x}$$.

```c
#define ao_csc(x)
```

## `ao_csch`

Get the hyperbolic cosecant of $$\texttt{x}$$.

```c
#define ao_csch(x)
```

## `ao_deg2rad`

Convert degrees to radians.

```c
#define ao_deg2rad(x)
```

## `ao_exp`

Get $$e^\texttt{x}$$.

```c
#define ao_exp(x)
```

## `ao_exp2`

Get $$2^\texttt{x}$$.

```c
#define ao_exp2(x)
```

## `ao_fabs`

Get the absolute value of $$\texttt{x}$$.

```c
#define ao_fabs(x)
```

## `ao_floor`

Round $$\texttt{x}$$ down.

```c
#define ao_floor(x)
```

## `ao_fmod`

Get the remainder of $$\frac{\texttt{x}}{\texttt{y}}$$ rounded to zero.

```c
#define ao_fmod(x, y)
```

## `ao_frexp`

Break $$\texttt{x}$$ into its binary significant and an integral exponent for 2.

```c
#define ao_frexp(x, exp)
```

## `ao_frexp10`

Break $$\texttt{x}$$ into its decimal significant and an integral exponent for 10.

```c
#define ao_frexp10(x, exp)
```

## `ao_inf`

Generate positive infinity.

```c
#define ao_inf()
```

## `ao_isfinite`

Check whether $$\texttt{x}$$ is finite.

```c
#define ao_isfinite(x)
```

## `ao_isinf`

Check whether $$\texttt{x}$$ is positive or negative infinity.

```c
#define ao_isinf(x)
```

## `ao_isnan`

Check whether $$\texttt{x}$$ is not a number.

```c
#define ao_isnan(x)
```

## `ao_hypot`

Get $$\sqrt{\texttt{x}^2 + \texttt{y}^2}$$.

```c
#define ao_hypot(x, y)
```

## `ao_ldexp`

Get $$\texttt{x} \cdot 2^{\texttt{exp}}$$.

```c
#define ao_ldexp(x, exp)
```

## `ao_ldexp10`

Get $$\texttt{x} \cdot 10^{\texttt{exp}}$$.

```c
#define ao_ldexp10(x, exp)
```

## `ao_log`

Get the natural logarithm of $$\texttt{x}$$.

```c
#define ao_log(x)
```

## `ao_log10`

Get the common logarithm of $$\texttt{x}$$.

```c
#define ao_log10(x)
```

## `ao_log2`

Get the binary logarithm of $$\texttt{x}$$.

```c
#define ao_log2(x)
```

## `ao_modf`

Break $$\texttt{x}$$ into an integral and a fractional part.

```c
#define ao_modf(x, intpart)
```

## `ao_nan`

Generate not a number.

```c
#define ao_nan()
```

## `ao_pow`

Get $$\texttt{x}^\texttt{y}$$.

```c
#define ao_pow(x, y)
```

## `ao_rad2deg`

Convert radians to degrees.

```c
#define ao_rad2deg(x)
```

## `ao_round`

Round $$\texttt{x}$$ to the nearest integer. Round half away from zero.

```c
#define ao_round(x)
```

## `ao_round_away_from_infinity`

Round $$\texttt{x}$$ away from infinity.

```c
#define ao_round_away_from_infinity(x)
```

## `ao_round_away_from_negative_infinity`

Round $$\texttt{x}$$ away from negative infinity.

```c
#define ao_round_away_from_negative_infinity(x)
```

## `ao_round_away_from_positive_infinity`

Round $$\texttt{x}$$ away from positive infinity.

```c
#define ao_round_away_from_positive_infinity(x)
```

## `ao_round_away_from_zero`

Round $$\texttt{x}$$ away from zero.

```c
#define ao_round_away_from_zero(x)
```

## `ao_round_down`

Round $$\texttt{x}$$ down.

```c
#define ao_round_down(x)
```

## `ao_round_half_away_from_infinity`

Round $$\texttt{x}$$ to the nearest integer. Round half away from infinity.

```c
#define ao_round_half_away_from_infinity(x)
```

## `ao_round_half_away_from_negative_infinity`

Round $$\texttt{x}$$ to the nearest integer. Round half away from negative infinity.

```c
#define ao_round_half_away_from_negative_infinity(x)
```

## `ao_round_half_away_from_positive_infinity`

Round $$\texttt{x}$$ to the nearest integer. Round half away from positive infinity.

```c
#define ao_round_half_away_from_positive_infinity(x)
```

## `ao_round_half_away_from_zero`

Round $$\texttt{x}$$ to the nearest integer. Round half away from zero.

```c
#define ao_round_half_away_from_zero(x)
```

## `ao_round_half_down`

Round $$\texttt{x}$$ to the nearest integer. Round half down.

```c
#define ao_round_half_down(x)
```

## `ao_round_half_to_even`

Round $$\texttt{x}$$ to the nearest integer. Round half to even.

```c
#define ao_round_half_to_even(x)
```

## `ao_round_half_to_infinity`

Round $$\texttt{x}$$ to the nearest integer. Round half to infinity.

```c
#define ao_round_half_to_infinity(x)
```

## `ao_round_half_to_negative_infinity`

Round $$\texttt{x}$$ to the nearest integer. Round half to negative infinity.

```c
#define ao_round_half_to_negative_infinity(x)
```

## `ao_round_half_to_odd`

Round $$\texttt{x}$$ to the nearest integer. Round half to odd.

```c
#define ao_round_half_to_odd(x)
```

## `ao_round_half_to_positive_infinity`

Round $$\texttt{x}$$ to the nearest integer. Round half to positive infinity.

```c
#define ao_round_half_to_positive_infinity(x)
```

## `ao_round_half_to_zero`

Round $$\texttt{x}$$ to the nearest integer. Round half to zero.

```c
#define ao_round_half_to_zero(x)
```

## `ao_round_half_up`

Round $$\texttt{x}$$ to the nearest integer. Round half up.

```c
#define ao_round_half_up(x)
```

## `ao_round_to_infinity`

Round $$\texttt{x}$$ to infinity.

```c
#define ao_round_to_infinity(x)
```

## `ao_round_to_negative_infinity`

Round $$\texttt{x}$$ to negative infinity.

```c
#define ao_round_to_negative_infinity(x)
```

## `ao_round_to_positive_infinity`

Round $$\texttt{x}$$ to positive infinity.

```c
#define ao_round_to_positive_infinity(x)
```

## `ao_round_to_zero`

Round $$\texttt{x}$$ to zero.

```c
#define ao_round_to_zero(x)
```

## `ao_round_up`

Round $$\texttt{x}$$ up.

```c
#define ao_round_up(x)
```

## `ao_sec`

Get the secant of $$\texttt{x}$$.

```c
#define ao_sec(x)
```

## `ao_sech`

Get the hyperbolic secant of $$\texttt{x}$$.

```c
#define ao_sech(x)
```

## `ao_sign`

Get the sign of $$\texttt{x}$$.

```c
#define ao_sign(x)
```

## `ao_sin`

Get the sine of $$\texttt{x}$$.

```c
#define ao_sin(x)
```

## `ao_sinh`

Get the hyperbolic sine of $$\texttt{x}$$.

```c
#define ao_sinh(x)
```

## `ao_sqrt`

Get the square root of $$\texttt{x}$$.

```c
#define ao_sqrt(x)
```

## `ao_tan`

Get the tangent of $$\texttt{x}$$.

```c
#define ao_tan(x)
```

## `ao_tanh`

Get the hyperbolic tangent of $$\texttt{x}$$.

```c
#define ao_tanh(x)
```

## `ao_trunc`

Round $$\texttt{x}$$ to zero.

```c
#define ao_trunc(x)
```

## `ao_wrap`

Wrap $$\texttt{x}$$ in $$[\texttt{beginning}, \texttt{length})$$.

```c
#define ao_wrap(x, beginning, length)
```
