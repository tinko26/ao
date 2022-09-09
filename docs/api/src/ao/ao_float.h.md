---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao/ao_float.h/
toc: true
---

# Notes

This module defines the fastest floating-point type available on the target platform. Additionally, it provides a couple of mathematical functions for that type. This module is considered abstract and should be overridden by a port package.

# Constants

## `AO_FLOAT_DIG`

```c
#define AO_FLOAT_DIG (FLT_DIG)
```

The number of decimal digits that are preserved, when converting a floating-point value to string and back again.

## `AO_FLOAT_EPSILON`

```c
#define AO_FLOAT_EPSILON (FLT_EPSILON)
```

The difference between one and the next representable value.

## `AO_FLOAT_MAX`
## `AO_FLOAT_MIN`

```c
#define AO_FLOAT_MAX (FLT_MAX)
#define AO_FLOAT_MIN (FLT_MIN)
```

The minimum and maximum value, respectively.

# Types

## `ao_float_t`

```c
typedef float ao_float_t;
```

This type represents the fastest floating-point type available on the target platform. It is an alias for one of the language-defined floating-point types.

# Functions

## `ao_acos`

```c
ao_float_t ao_acos(ao_float_t x);
```

Calculates the arc cosine of $$\texttt{x}$$.

## `ao_acosh`

```c
ao_float_t ao_acosh(ao_float_t x);
```

Calculates the area hyperbolic cosine of $$\texttt{x}$$.

## `ao_acot`

```c
ao_float_t ao_acot(ao_float_t x);
```

Calculates the arc cotangent of $$\texttt{x}$$.

## `ao_acoth`

```c
ao_float_t ao_acoth(ao_float_t x);
```

Calculates the area hyperbolic cotangent of $$\texttt{x}$$.

## `ao_acsc`

```c
ao_float_t ao_acsc(ao_float_t x);
```

Calculates the arc cosecant of $$\texttt{x}$$.

## `ao_acsch`

```c
ao_float_t ao_acsch(ao_float_t x);
```

Calculates the area hyperbolic cosecant of $$\texttt{x}$$.

## `ao_asec`

```c
ao_float_t ao_asec(ao_float_t x);
```

Calculates the arc secant of $$\texttt{x}$$.

## `ao_asech`

```c
ao_float_t ao_asech(ao_float_t x);
```

Calculates the area hyperbolic secant of $$\texttt{x}$$.

## `ao_asin`

```c
ao_float_t ao_asin(ao_float_t x);
```

Calculates the arc sine of $$\texttt{x}$$.

## `ao_asinh`

```c
ao_float_t ao_asinh(ao_float_t x);
```

Calculates the area hyperbolic sine of $$\texttt{x}$$.

## `ao_atan`

```c
ao_float_t ao_atan(ao_float_t x);
```

Calculates the arc tangent of $$\texttt{x}$$.

## `ao_atan2`

```c
ao_float_t ao_atan2(ao_float_t y, ao_float_t x);
```

Calculates the arc tangent of $$\frac{\texttt{y}}{\texttt{x}}$$.

## `ao_atanh`

```c
ao_float_t ao_atanh(ao_float_t x);
```

Calculates the area hyperbolic tangent of $$\texttt{x}$$.

## `ao_cbrt`

```c
ao_float_t ao_cbrt(ao_float_t x);
```

Calculates the cubic root of $$\texttt{x}$$.

## `ao_ceil`

```c
ao_float_t ao_ceil(ao_float_t x);
```

Rounds $$\texttt{x}$$ up.

## `ao_cos`

```c
ao_float_t ao_cos(ao_float_t x);
```

Calculates the cosine of $$\texttt{x}$$.

## `ao_cosh`

```c
ao_float_t ao_cosh(ao_float_t x);
```

Calculates the hyperbolic cosine of $$\texttt{x}$$.

## `ao_cot`

```c
ao_float_t ao_cot(ao_float_t x);
```

Calculates the cotangent of $$\texttt{x}$$.

## `ao_coth`

```c
ao_float_t ao_coth(ao_float_t x);
```

Calculates the hyperbolic cotangent of $$\texttt{x}$$.

## `ao_csc`

```c
ao_float_t ao_csc(ao_float_t x);
```

Calculates the cosecant of $$\texttt{x}$$.

## `ao_csch`

```c
ao_float_t ao_csch(ao_float_t x);
```

Calculates the hyperbolic cosecant of $$\texttt{x}$$.

## `ao_deg2rad`

```c
ao_float_t ao_deg2rad(ao_float_t x);
```

Converts degrees to radians.

## `ao_exp`

```c
ao_float_t ao_exp(ao_float_t x);
```

Calculates $$e^\texttt{x}$$.

## `ao_exp2`

```c
ao_float_t ao_exp2(ao_float_t x);
```

Calculates $$2^\texttt{x}$$.

## `ao_fabs`

```c
ao_float_t ao_fabs(ao_float_t x);
```

Calculates the absolute value of $$\texttt{x}$$.

## `ao_floor`

```c
ao_float_t ao_floor(ao_float_t x);
```

Rounds $$\texttt{x}$$ down.

## `ao_fmod`

```c
ao_float_t ao_fmod(ao_float_t x, ao_float_t y);
```

Calculates the remainder of $$\frac{\texttt{x}}{\texttt{y}}$$ rounded to zero.

## `ao_frexp`

```c
ao_float_t ao_frexp(ao_float_t x, int * exp);
```

Breaks $$\texttt{x}$$ into its binary significant and an integral exponent for 2.

## `ao_frexp10`

```c
ao_float_t ao_frexp10(ao_float_t x, int * exp);
```

Breaks $$\texttt{x}$$ into its decimal significant and an integral exponent for 10.

## `ao_hypot`

```c
ao_float_t ao_hypot(ao_float_t x, ao_float_t y);
```

Calculates $$\sqrt{\texttt{x}^2 + \texttt{y}^2}$$.

## `ao_inf`

```c
ao_float_t ao_inf();
```

Generates positive infinity.

## `ao_isfinite`

```c
bool ao_isfinite(ao_float_t x);
```

Checks whether $$\texttt{x}$$ is finite.

## `ao_isinf`

```c
bool ao_isinf(ao_float_t x);
```

Checks whether $$\texttt{x}$$ is positive or negative infinity.

## `ao_isnan`

```c
bool ao_isnan(ao_float_t x);
```

Checks whether $$\texttt{x}$$ is not a number.

## `ao_ldexp`

```c
ao_float_t ao_ldexp(ao_float_t x, int exp);
```

Calculates $$\texttt{x} \cdot 2^{\texttt{exp}}$$.

## `ao_ldexp10`

```c
ao_float_t ao_ldexp10(ao_float_t x, int exp);
```

Calculates $$\texttt{x} \cdot 10^{\texttt{exp}}$$.

## `ao_log`

```c
ao_float_t ao_log(ao_float_t x);
```

Calculates the natural logarithm of $$\texttt{x}$$.

## `ao_log10`

```c
ao_float_t ao_log10(ao_float_t x);
```

Calculates the common logarithm of $$\texttt{x}$$.

## `ao_log2`

```c
ao_float_t ao_log2(ao_float_t x);
```

Calculates the binary logarithm of $$\texttt{x}$$.

## `ao_modf`

```c
ao_float_t ao_modf(ao_float_t x, ao_float_t * intpart);
```

Breaks $$\texttt{x}$$ into an integral and a fractional part.

## `ao_nan`

```c
ao_float_t ao_nan();
```

Generates not a number.

## `ao_pow`

```c
ao_float_t ao_pow(ao_float_t x, ao_float_t y);
```

Calculates $$\texttt{x}^\texttt{y}$$.

## `ao_rad2deg`

```c
ao_float_t ao_rad2deg(ao_float_t x);
```

Converts radians to degrees.

## `ao_round`

```c
ao_float_t ao_round(ao_float_t x);
```

Rounds $$\texttt{x}$$ to the nearest integer. Round half away from zero.

## `ao_round_away_from_infinity`

```c
ao_float_t ao_round_away_from_infinity(ao_float_t x);
```

Rounds $$\texttt{x}$$ away from infinity.

## `ao_round_away_from_negative_infinity`

```c
ao_float_t ao_round_away_from_negative_infinity(ao_float_t x);
```

Rounds $$\texttt{x}$$ away from negative infinity.

## `ao_round_away_from_positive_infinity`

```c
ao_float_t ao_round_away_from_positive_infinity(ao_float_t x);
```

Rounds $$\texttt{x}$$ away from positive infinity.

## `ao_round_away_from_zero`

```c
ao_float_t ao_round_away_from_zero(ao_float_t x);
```

Rounds $$\texttt{x}$$ away from zero.

## `ao_round_down`

```c
ao_float_t ao_round_down(ao_float_t x);
```

Rounds $$\texttt{x}$$ down.

## `ao_round_half_away_from_infinity`

```c
ao_float_t ao_round_half_away_from_infinity(ao_float_t x);
```

Rounds $$\texttt{x}$$ to the nearest integer. Round half away from infinity.

## `ao_round_half_away_from_negative_infinity`

```c
ao_float_t ao_round_half_away_from_negative_infinity(ao_float_t x);
```

Rounds $$\texttt{x}$$ to the nearest integer. Round half away from negative infinity.

## `ao_round_half_away_from_positive_infinity`

```c
ao_float_t ao_round_half_away_from_positive_infinity(ao_float_t x);
```

Rounds $$\texttt{x}$$ to the nearest integer. Round half away from positive infinity.

## `ao_round_half_away_from_zero`

```c
ao_float_t ao_round_half_away_from_zero(ao_float_t x);
```

Rounds $$\texttt{x}$$ to the nearest integer. Round half away from zero.

## `ao_round_half_down`

```c
ao_float_t ao_round_half_down(ao_float_t x);
```

Rounds $$\texttt{x}$$ to the nearest integer. Round half down.

## `ao_round_half_to_even`

```c
ao_float_t ao_round_half_to_even(ao_float_t x);
```

Rounds $$\texttt{x}$$ to the nearest integer. Round half to even.

## `ao_round_half_to_infinity`

```c
ao_float_t ao_round_half_to_infinity(ao_float_t x);
```

Rounds $$\texttt{x}$$ to the nearest integer. Round half to infinity.

## `ao_round_half_to_negative_infinity`

```c
ao_float_t ao_round_half_to_negative_infinity(ao_float_t x);
```

Rounds $$\texttt{x}$$ to the nearest integer. Round half to negative infinity.

## `ao_round_half_to_odd`

```c
ao_float_t ao_round_half_to_odd(ao_float_t x);
```

Rounds $$\texttt{x}$$ to the nearest integer. Round half to odd.

## `ao_round_half_to_positive_infinity`

```c
ao_float_t ao_round_half_to_positive_infinity(ao_float_t x);
```

Rounds $$\texttt{x}$$ to the nearest integer. Round half to positive infinity.

## `ao_round_half_to_zero`

```c
ao_float_t ao_round_half_to_zero(ao_float_t x);
```

Rounds $$\texttt{x}$$ to the nearest integer. Round half to zero.

## `ao_round_half_up`

```c
ao_float_t ao_round_half_up(ao_float_t x);
```

Rounds $$\texttt{x}$$ to the nearest integer. Round half up.

## `ao_round_to_infinity`

```c
ao_float_t ao_round_to_infinity(ao_float_t x);
```

Rounds $$\texttt{x}$$ to infinity.

## `ao_round_to_negative_infinity`

```c
ao_float_t ao_round_to_negative_infinity(ao_float_t x);
```

Rounds $$\texttt{x}$$ to negative infinity.

## `ao_round_to_positive_infinity`

```c
ao_float_t ao_round_to_positive_infinity(ao_float_t x);
```

Rounds $$\texttt{x}$$ to positive infinity.

## `ao_round_to_zero`

```c
ao_float_t ao_round_to_zero(ao_float_t x);
```

Rounds $$\texttt{x}$$ to zero.

## `ao_round_up`

```c
ao_float_t ao_round_up(ao_float_t x);
```

Rounds $$\texttt{x}$$ up.

## `ao_sec`

```c
ao_float_t ao_sec(ao_float_t x);
```

Calculates the secant of $$\texttt{x}$$.

## `ao_sech`

```c
ao_float_t ao_sech(ao_float_t x);
```

Calculates the hyperbolic secant of $$\texttt{x}$$.

## `ao_sign`

```c
ao_float_t ao_sign(ao_float_t x);
```

Calculates the sign of $$\texttt{x}$$.

## `ao_sin`

```c
ao_float_t ao_sin(ao_float_t x);
```

Calculates the sine of $$\texttt{x}$$.

## `ao_sinh`

```c
ao_float_t ao_sinh(ao_float_t x);
```

Calculates the hyperbolic sine of $$\texttt{x}$$.

## `ao_sqrt`

```c
ao_float_t ao_sqrt(ao_float_t x);
```

Calculates the square root of $$\texttt{x}$$.

## `ao_tan`

```c
ao_float_t ao_tan(ao_float_t x);
```

Calculates the tangent of $$\texttt{x}$$.

## `ao_tanh`

```c
ao_float_t ao_tanh(ao_float_t x);
```

Calculates the hyperbolic tangent of $$\texttt{x}$$.

## `ao_trunc`

```c
ao_float_t ao_trunc(ao_float_t x);
```

Rounds $$\texttt{x}$$ to zero.

## `ao_wrap`

```c
ao_float_t ao_wrap(ao_float_t x, ao_float_t beginning, ao_float_t length);
```

Wraps $$\texttt{x}$$ in $$[\texttt{beginning}, \texttt{length})$$.
