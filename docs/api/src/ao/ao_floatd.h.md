---
api: true
author: "Stefan Wagner"
date: 2022-08-31
description: "The /src/ao/ao_floatd.h file of the ao real-time operating system."
draft: false
permalink: /api/src/ao/ao_floatd.h/
subtitle: "Floating-point numbers based on <code>double</code>"
title: "ao_floatd.h"
toc: true
---

# Overview

This module defines the fastest floating-point type available on the target platform to be the `double` type. Additionally, it provides a couple of mathematical functions for that type.

An override of the [`ao_float.h`](ao_float.h.md) module can conveniently include this module, if actually `double` is the fastest floating-point type available on the target platform.

# Include

```c
#include <ao_mathf.h>
#include <float.h>
```

# Typedefs

The `ao_float_t` type represents the fastest floating-point type available on the target platform. It is an alias for one of the language-defined floating-point types.

```c
typedef double ao_float_t;
```

# Constants

The number of decimal digits that are preserved, when converting a floating-point value to string and back again.

```c
#define AO_FLOAT_DIG     (DBL_DIG)
```

The difference between one and the next representable value.

```c
#define AO_FLOAT_EPSILON (DBL_EPSILON)
```

The minimum and maximum value, respectively.

```c
#define AO_FLOAT_MAX     (DBL_MAX)
#define AO_FLOAT_MIN     (DBL_MIN)
```

# Functions

## Absolute value

Get the absolute value of $$\texttt{x}$$.

```c
#define ao_fabs(x)
```

## Angles

Convert degrees to radians.

```c
#define ao_deg2rad(x)
```

Convert radians to degrees.

```c
#define ao_rad2deg(x)
```

## Classification

Check whether $$\texttt{x}$$ is finite.

```c
#define ao_isfinite(x)
```

Check whether $$\texttt{x}$$ is positive or negative infinity.

```c
#define ao_isinf(x)
```

Check whether $$\texttt{x}$$ is not a number.

```c
#define ao_isnan(x)
```

## Division

Get the remainder of $$\frac{\texttt{x}}{\texttt{y}}$$ rounded to zero.

```c
#define ao_fmod(x, y)
```

## Exponential Functions

Get $$e^\texttt{x}$$.

```c
#define ao_exp(x)
```

Get $$2^\texttt{x}$$.

```c
#define ao_exp2(x)
```

## Generators

Generate positive infinity.

```c
#define ao_inf()
```

Generate not a number.

```c
#define ao_nan()
```

## Hyperbolic functions

Get the area hyperbolic cosine of $$\texttt{x}$$.

```c
#define ao_acosh(x)
```

Get the area hyperbolic cotangent of $$\texttt{x}$$.

```c
#define ao_acoth(x)
```

Get the area hyperbolic cosecant of $$\texttt{x}$$.

```c
#define ao_acsch(x)
```

Get the area hyperbolic secant of $$\texttt{x}$$.

```c
#define ao_asech(x)
```

Get the area hyperbolic sine of $$\texttt{x}$$.

```c
#define ao_asinh(x)
```

Get the area hyperbolic tangent of $$\texttt{x}$$.

```c
#define ao_atanh(x)
```

Get the hyperbolic cosine of $$\texttt{x}$$.

```c
#define ao_cosh(x)
```

Get the hyperbolic cotangent of $$\texttt{x}$$.

```c
#define ao_coth(x)
```

Get the hyperbolic cosecant of $$\texttt{x}$$.

```c
#define ao_csch(x)
```

Get the hyperbolic secant of $$\texttt{x}$$.

```c
#define ao_sech(x)
```

Get the hyperbolic sine of $$\texttt{x}$$.

```c
#define ao_sinh(x)
```

Get the hyperbolic tangent of $$\texttt{x}$$.


## Logarithmic functions

Break $$\texttt{x}$$ into its binary significant and an integral exponent for $$2$$.

```c
#define ao_frexp(x, exp)
```

Break $$\texttt{x}$$ into its decimal significant and an integral exponent for $$10$$.

```c
#define ao_frexp10(x, exp)
```

Get the natural logarithm of $$\texttt{x}$$.

```c
#define ao_log(x)
```

Get the common logarithm of $$\texttt{x}$$.

```c
#define ao_log10(x)
```

Get the binary logarithm of $$\texttt{x}$$.

```c
#define ao_log2(x)
```

## Power Functions

Get the cubic root of $$\texttt{x}$$.

```c
#define ao_cbrt(x)
```

Get $$\sqrt{\texttt{x}^2 + \texttt{y}^2}$$.

```c
#define ao_hypot(x, y)
```

Get $$\texttt{x} \cdot 2^{\texttt{exp}}$$.

```c
#define ao_ldexp(x, exp)
```

Get $$\texttt{x} \cdot 10^{\texttt{exp}}$$.

```c
#define ao_ldexp10(x, exp)
```

Get $$x^y$$.

```c
#define ao_pow(x, y)
```

Get the square root of $$\texttt{x}$$.

```c
#define ao_sqrt(x)
```

## Rounding

Round $$\texttt{x}$$ up.

```c
#define ao_ceil(x)
```

Round $$\texttt{x}$$ down.

```c
#define ao_floor(x)
```

Break $$\texttt{x}$$ into an integral and a fractional part.

```c
#define ao_modf(x, intpart)
```

Round $$\texttt{x}$$ to the nearest integer. Round half away from zero.

```c
#define ao_round(x)
```

Round $$\texttt{x}$$ away from infinity.

```c
#define ao_round_away_from_infinity(x)
```

Round $$\texttt{x}$$ away from negative infinity.

```c
#define ao_round_away_from_negative_infinity(x)
```

Round $$\texttt{x}$$ away from positive infinity.

```c
#define ao_round_away_from_positive_infinity(x)
```

Round $$\texttt{x}$$ away from zero.

```c
#define ao_round_away_from_zero(x)
```

Round $$\texttt{x}$$ down.

```c
#define ao_round_down(x)
```

Round $$\texttt{x}$$ to the nearest integer. Round half away from infinity.

```c
#define ao_round_half_away_from_infinity(x)
```

Round $$\texttt{x}$$ to the nearest integer. Round half away from negative infinity.

```c
#define ao_round_half_away_from_negative_infinity(x)
```

Round $$\texttt{x}$$ to the nearest integer. Round half away from positive infinity.

```c
#define ao_round_half_away_from_positive_infinity(x)
```

Round $$\texttt{x}$$ to the nearest integer. Round half away from zero.

```c
#define ao_round_half_away_from_zero(x)
```

Round $$\texttt{x}$$ to the nearest integer. Round half down.

```c
#define ao_round_half_down(x)
```

Round $$\texttt{x}$$ to the nearest integer. Round half to even.

```c
#define ao_round_half_to_even(x)
```

Round $$\texttt{x}$$ to the nearest integer. Round half to infinity.

```c
#define ao_round_half_to_infinity(x)
```

Round $$\texttt{x}$$ to the nearest integer. Round half to negative infinity.

```c
#define ao_round_half_to_negative_infinity(x)
```

Round $$\texttt{x}$$ to the nearest integer. Round half to odd.

```c
#define ao_round_half_to_odd(x)
```

Round $$\texttt{x}$$ to the nearest integer. Round half to positive infinity.

```c
#define ao_round_half_to_positive_infinity(x)
```

Round $$\texttt{x}$$ to the nearest integer. Round half to zero.

```c
#define ao_round_half_to_zero(x)
```

Round $$\texttt{x}$$ to the nearest integer. Round half up.

```c
#define ao_round_half_up(x)
```

Round $$\texttt{x}$$ to infinity.

```c
#define ao_round_to_infinity(x)
```

Round $$\texttt{x}$$ to negative infinity.

```c
#define ao_round_to_negative_infinity(x)
```

Round $$\texttt{x}$$ to positive infinity.

```c
#define ao_round_to_positive_infinity(x)
```

Round $$\texttt{x}$$ to zero.

```c
#define ao_round_to_zero(x)
```

Round $$\texttt{x}$$ up.

```c
#define ao_round_up(x)
```

Round $$\texttt{x}$$ to zero.

```c
#define ao_trunc(x)
```

## Sign

Get the sign of $$\texttt{x}$$.

```c
#define ao_sign(x)
```

## Trigonometric Functions

Get the arc cosine of $$\texttt{x}$$.

```c
#define ao_acos(x)
```

Get the arc cotangent of $$\texttt{x}$$.

```c
#define ao_acot(x)
```

Get the arc cosecant of $$\texttt{x}$$.

```c
#define ao_acsc(x)
```

Get the arc secant of $$\texttt{x}$$.

```c
#define ao_asec(x)
```

Get the arc sine of $$\texttt{x}$$.

```c
#define ao_asin(x)
```

Get the arc tangent of $$\texttt{x}$$.

```c
#define ao_atan(x)
```

Get the arc tangent of $$\frac{\texttt{y}}{\texttt{x}}$$.

```c
#define ao_atan2(y, x)
```

Get the cosine of $$\texttt{x}$$.

```c
#define ao_cos(x)
```

Get the cotangent of $$\texttt{x}$$.

```c
#define ao_cot(x)
```

Get the cosecant of $$\texttt{x}$$.

```c
#define ao_csc(x)
```

Get the secant of $$\texttt{x}$$.

```c
#define ao_sec(x)
```

Get the sine of $$\texttt{x}$$.

```c
#define ao_sin(x)
```

Get the tangent of $$\texttt{x}$$.

```c
#define ao_tan(x)
```

## Wrapping

Wrap $$\texttt{x}$$ in $$[\texttt{beginning}, \texttt{length})$$.

```c
#define ao_wrap(x, beginning, length)
```
