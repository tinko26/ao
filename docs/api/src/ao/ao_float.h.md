---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao/ao_float.h/
toc: true
---

# Overview

This module defines the fastest floating-point type available on the target platform. Additionally, it provides a couple of mathematical functions for that type. This module is considered abstract and should be overridden by a port package.

# Constants

## `AO_FLOAT_DIG`

The number of decimal digits that are preserved, when converting a floating-point value to string and back again.

```c
#define AO_FLOAT_DIG (FLT_DIG)
```

## `AO_FLOAT_EPSILON`

The difference between one and the next representable value.

```c
#define AO_FLOAT_EPSILON (FLT_EPSILON)
```

## `AO_FLOAT_MAX`
## `AO_FLOAT_MIN`

The minimum and maximum value, respectively.

```c
#define AO_FLOAT_MAX (FLT_MAX)
#define AO_FLOAT_MIN (FLT_MIN)
```

# Typedefs

```c
typedef float ao_float_t;
```

# Types

## `ao_float_t`

This type represents the fastest floating-point type available on the target platform. It is an alias for one of the language-defined floating-point types.

# Functions

## `ao_acos`

Get the arc cosine of $$\texttt{x}$$.

```c
ao_float_t ao_acos(ao_float_t x);
```

## `ao_acosh`

Get the area hyperbolic cosine of $$\texttt{x}$$.

```c
ao_float_t ao_acosh(ao_float_t x);
```

## `ao_acot`

Get the arc cotangent of $$\texttt{x}$$.

```c
ao_float_t ao_acot(ao_float_t x);
```

## `ao_acoth`

Get the area hyperbolic cotangent of $$\texttt{x}$$.

```c
ao_float_t ao_acoth(ao_float_t x);
```

## `ao_acsc`

Get the arc cosecant of $$\texttt{x}$$.

```c
ao_float_t ao_acsc(ao_float_t x);
```

## `ao_acsch`

Get the area hyperbolic cosecant of $$\texttt{x}$$.

```c
ao_float_t ao_acsch(ao_float_t x);
```

## `ao_asec`

Get the arc secant of $$\texttt{x}$$.

```c
ao_float_t ao_asec(ao_float_t x);
```

## `ao_asech`

Get the area hyperbolic secant of $$\texttt{x}$$.

```c
ao_float_t ao_asech(ao_float_t x);
```

## `ao_asin`

Get the arc sine of $$\texttt{x}$$.

```c
ao_float_t ao_asin(ao_float_t x);
```

## `ao_asinh`

Get the area hyperbolic sine of $$\texttt{x}$$.

```c
ao_float_t ao_asinh(ao_float_t x);
```

## `ao_atan`

Get the arc tangent of $$\texttt{x}$$.

```c
ao_float_t ao_atan(ao_float_t x);
```

## `ao_atan2`

Get the arc tangent of $$\frac{\texttt{y}}{\texttt{x}}$$.

```c
ao_float_t ao_atan2(ao_float_t y, ao_float_t x);
```

## `ao_atanh`

Get the area hyperbolic tangent of $$\texttt{x}$$.

```c
ao_float_t ao_atanh(ao_float_t x);
```

## `ao_cbrt`

Get the cubic root of $$\texttt{x}$$.

```c
ao_float_t ao_cbrt(ao_float_t x);
```

## `ao_ceil`

Round $$\texttt{x}$$ up.

```c
ao_float_t ao_ceil(ao_float_t x);
```

## `ao_cos`

Get the cosine of $$\texttt{x}$$.

```c
ao_float_t ao_cos(ao_float_t x);
```

## `ao_cosh`

Get the hyperbolic cosine of $$\texttt{x}$$.

```c
ao_float_t ao_cosh(ao_float_t x);
```

## `ao_cot`

Get the cotangent of $$\texttt{x}$$.

```c
ao_float_t ao_cot(ao_float_t x);
```

## `ao_coth`

Get the hyperbolic cotangent of $$\texttt{x}$$.

```c
ao_float_t ao_coth(ao_float_t x);
```

## `ao_csc`

Get the cosecant of $$\texttt{x}$$.

```c
ao_float_t ao_csc(ao_float_t x);
```

## `ao_csch`

Get the hyperbolic cosecant of $$\texttt{x}$$.

```c
ao_float_t ao_csch(ao_float_t x);
```

## `ao_deg2rad`

Convert degrees to radians.

```c
ao_float_t ao_deg2rad(ao_float_t x);
```

## `ao_exp`

Get $$e^\texttt{x}$$.

```c
ao_float_t ao_exp(ao_float_t x);
```

## `ao_exp2`

Get $$2^\texttt{x}$$.

```c
ao_float_t ao_exp2(ao_float_t x);
```

## `ao_fabs`

Get the absolute value of $$\texttt{x}$$.

```c
ao_float_t ao_fabs(ao_float_t x);
```

## `ao_floor`

Round $$\texttt{x}$$ down.

```c
ao_float_t ao_floor(ao_float_t x);
```

## `ao_fmod`

Get the remainder of $$\frac{\texttt{x}}{\texttt{y}}$$ rounded to zero.

```c
ao_float_t ao_fmod(ao_float_t x, ao_float_t y);
```

## `ao_frexp`

Break $$\texttt{x}$$ into its binary significant and an integral exponent for 2.

```c
ao_float_t ao_frexp(ao_float_t x, int * exp);
```

## `ao_frexp10`

Break $$\texttt{x}$$ into its decimal significant and an integral exponent for 10.

```c
ao_float_t ao_frexp10(ao_float_t x, int * exp);
```

## `ao_hypot`

Get $$\sqrt{\texttt{x}^2 + \texttt{y}^2}$$.

```c
ao_float_t ao_hypot(ao_float_t x, ao_float_t y);
```

## `ao_inf`

Generate positive infinity.

```c
ao_float_t ao_inf();
```

## `ao_isfinite`

Check whether $$\texttt{x}$$ is finite.

```c
bool ao_isfinite(ao_float_t x);
```

## `ao_isinf`

Check whether $$\texttt{x}$$ is positive or negative infinity.

```c
bool ao_isinf(ao_float_t x);
```

## `ao_isnan`

Check whether $$\texttt{x}$$ is not a number.

```c
bool ao_isnan(ao_float_t x);
```

## `ao_ldexp`

Get $$\texttt{x} \cdot 2^{\texttt{exp}}$$.

```c
ao_float_t ao_ldexp(ao_float_t x, int exp);
```

## `ao_ldexp10`

Get $$\texttt{x} \cdot 10^{\texttt{exp}}$$.

```c
ao_float_t ao_ldexp10(ao_float_t x, int exp);
```

## `ao_log`

Get the natural logarithm of $$\texttt{x}$$.

```c
ao_float_t ao_log(ao_float_t x);
```

## `ao_log10`

Get the common logarithm of $$\texttt{x}$$.

```c
ao_float_t ao_log10(ao_float_t x);
```

## `ao_log2`

Get the binary logarithm of $$\texttt{x}$$.

```c
ao_float_t ao_log2(ao_float_t x);
```

## `ao_modf`

Break $$\texttt{x}$$ into an integral and a fractional part.

```c
ao_float_t ao_modf(ao_float_t x, ao_float_t * intpart);
```

## `ao_nan`

Generate not a number.

```c
ao_float_t ao_nan();
```

## `ao_pow`

Get $$\texttt{x}^\texttt{y}$$.

```c
ao_float_t ao_pow(ao_float_t x, ao_float_t y);
```

## `ao_rad2deg`

Convert radians to degrees.

```c
ao_float_t ao_rad2deg(ao_float_t x);
```

## `ao_round`

Round $$\texttt{x}$$ to the nearest integer. Round half away from zero.

```c
ao_float_t ao_round(ao_float_t x);
```

## `ao_round_away_from_infinity`

Round $$\texttt{x}$$ away from infinity.

```c
ao_float_t ao_round_away_from_infinity(ao_float_t x);
```

## `ao_round_away_from_negative_infinity`

Round $$\texttt{x}$$ away from negative infinity.

```c
ao_float_t ao_round_away_from_negative_infinity(ao_float_t x);
```

## `ao_round_away_from_positive_infinity`

Round $$\texttt{x}$$ away from positive infinity.

```c
ao_float_t ao_round_away_from_positive_infinity(ao_float_t x);
```

## `ao_round_away_from_zero`

Round $$\texttt{x}$$ away from zero.

```c
ao_float_t ao_round_away_from_zero(ao_float_t x);
```

## `ao_round_down`

Round $$\texttt{x}$$ down.

```c
ao_float_t ao_round_down(ao_float_t x);
```

## `ao_round_half_away_from_infinity`

Round $$\texttt{x}$$ to the nearest integer. Round half away from infinity.

```c
ao_float_t ao_round_half_away_from_infinity(ao_float_t x);
```

## `ao_round_half_away_from_negative_infinity`

Round $$\texttt{x}$$ to the nearest integer. Round half away from negative infinity.

```c
ao_float_t ao_round_half_away_from_negative_infinity(ao_float_t x);
```

## `ao_round_half_away_from_positive_infinity`

Round $$\texttt{x}$$ to the nearest integer. Round half away from positive infinity.

```c
ao_float_t ao_round_half_away_from_positive_infinity(ao_float_t x);
```

## `ao_round_half_away_from_zero`

Round $$\texttt{x}$$ to the nearest integer. Round half away from zero.

```c
ao_float_t ao_round_half_away_from_zero(ao_float_t x);
```

## `ao_round_half_down`

Round $$\texttt{x}$$ to the nearest integer. Round half down.

```c
ao_float_t ao_round_half_down(ao_float_t x);
```

## `ao_round_half_to_even`

Round $$\texttt{x}$$ to the nearest integer. Round half to even.

```c
ao_float_t ao_round_half_to_even(ao_float_t x);
```

## `ao_round_half_to_infinity`

Round $$\texttt{x}$$ to the nearest integer. Round half to infinity.

```c
ao_float_t ao_round_half_to_infinity(ao_float_t x);
```

## `ao_round_half_to_negative_infinity`

Round $$\texttt{x}$$ to the nearest integer. Round half to negative infinity.

```c
ao_float_t ao_round_half_to_negative_infinity(ao_float_t x);
```

## `ao_round_half_to_odd`

Round $$\texttt{x}$$ to the nearest integer. Round half to odd.

```c
ao_float_t ao_round_half_to_odd(ao_float_t x);
```

## `ao_round_half_to_positive_infinity`

Round $$\texttt{x}$$ to the nearest integer. Round half to positive infinity.

```c
ao_float_t ao_round_half_to_positive_infinity(ao_float_t x);
```

## `ao_round_half_to_zero`

Round $$\texttt{x}$$ to the nearest integer. Round half to zero.

```c
ao_float_t ao_round_half_to_zero(ao_float_t x);
```

## `ao_round_half_up`

Round $$\texttt{x}$$ to the nearest integer. Round half up.

```c
ao_float_t ao_round_half_up(ao_float_t x);
```

## `ao_round_to_infinity`

Round $$\texttt{x}$$ to infinity.

```c
ao_float_t ao_round_to_infinity(ao_float_t x);
```

## `ao_round_to_negative_infinity`

Round $$\texttt{x}$$ to negative infinity.

```c
ao_float_t ao_round_to_negative_infinity(ao_float_t x);
```

## `ao_round_to_positive_infinity`

Round $$\texttt{x}$$ to positive infinity.

```c
ao_float_t ao_round_to_positive_infinity(ao_float_t x);
```

## `ao_round_to_zero`

Round $$\texttt{x}$$ to zero.

```c
ao_float_t ao_round_to_zero(ao_float_t x);
```

## `ao_round_up`

Round $$\texttt{x}$$ up.

```c
ao_float_t ao_round_up(ao_float_t x);
```

## `ao_sec`

Get the secant of $$\texttt{x}$$.

```c
ao_float_t ao_sec(ao_float_t x);
```

## `ao_sech`

Get the hyperbolic secant of $$\texttt{x}$$.

```c
ao_float_t ao_sech(ao_float_t x);
```

## `ao_sign`

Get the sign of $$\texttt{x}$$.

```c
ao_float_t ao_sign(ao_float_t x);
```

## `ao_sin`

Get the sine of $$\texttt{x}$$.

```c
ao_float_t ao_sin(ao_float_t x);
```

## `ao_sinh`

Get the hyperbolic sine of $$\texttt{x}$$.

```c
ao_float_t ao_sinh(ao_float_t x);
```

## `ao_sqrt`

Get the square root of $$\texttt{x}$$.

```c
ao_float_t ao_sqrt(ao_float_t x);
```

## `ao_tan`

Get the tangent of $$\texttt{x}$$.

```c
ao_float_t ao_tan(ao_float_t x);
```

## `ao_tanh`

Get the hyperbolic tangent of $$\texttt{x}$$.

```c
ao_float_t ao_tanh(ao_float_t x);
```

## `ao_trunc`

Round $$\texttt{x}$$ to zero.

```c
ao_float_t ao_trunc(ao_float_t x);
```

## `ao_wrap`

Wrap $$\texttt{x}$$ in $$[\texttt{beginning}, \texttt{length})$$.

```c
ao_float_t ao_wrap(ao_float_t x, ao_float_t beginning, ao_float_t length);
```
