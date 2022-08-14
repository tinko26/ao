---
author: "Stefan Wagner"
date: 2022-08-12
description: "The ao_float.h module of the ao real-time operating system."
draft: false
permalink: /modules/float/
title: "ao_float.h"
---

# ao_float.h

This module defines the fastest floating-point type available on the target platform. Additionally, it provides a couple of mathematical functions for that type. This module is considered abstract and should be overridden by a port package.

## Type

The `ao_float_t` type represents the fastest floating-point type available on the target platform. It is an alias for one the language-defined floating-point types.

## Constants

The number of decimal digits that are preserved, when converting a floating-point value to string and back again.

```c
#define AO_FLOAT_DIG
```

The difference between one and the next representable value.

```c
#define AO_FLOAT_EPSILON
```

The maximum finite value and the minimum positive value.

```c
#define AO_FLOAT_MAX
#define AO_FLOAT_MIN
```

## Functions

Absolute value.

```c
ao_float_t ao_fabs(ao_float_t x);
```

Angles.

```c
ao_float_t ao_deg2rad(ao_float_t x);
ao_float_t ao_rad2deg(ao_float_t x);
```

Classification.

```c
bool ao_isfinite(ao_float_t x);
bool ao_isinf(ao_float_t x);
bool ao_isnan(ao_float_t x);
```

Division.

```c
ao_float_t ao_fmod(ao_float_t x, ao_float_t y);
```

Exponential functions.

```c
ao_float_t ao_exp(ao_float_t x);
ao_float_t ao_exp2(ao_float_t x);
```

Generators.

```c
ao_float_t ao_inf();
ao_float_t ao_nan();
```

Hyperbolic functions.

```c
ao_float_t ao_acosh(ao_float_t x);
ao_float_t ao_acoth(ao_float_t x);
ao_float_t ao_acsch(ao_float_t x);
ao_float_t ao_asech(ao_float_t x);
ao_float_t ao_asinh(ao_float_t x);
ao_float_t ao_atanh(ao_float_t x);
ao_float_t ao_cosh(ao_float_t x);
ao_float_t ao_coth(ao_float_t x);
ao_float_t ao_csch(ao_float_t x);
ao_float_t ao_sech(ao_float_t x);
ao_float_t ao_sinh(ao_float_t x);
ao_float_t ao_tanh(ao_float_t x);
```

Logarithmic functions.

```c
ao_float_t ao_frexp(ao_float_t x, int * exp);
ao_float_t ao_frexp10(ao_float_t x, int * exp);
ao_float_t ao_log(ao_float_t x);
ao_float_t ao_log10(ao_float_t x);
ao_float_t ao_log2(ao_float_t x);
```

Power functions.

```c
ao_float_t ao_cbrt(ao_float_t x);
ao_float_t ao_hypot(ao_float_t x, ao_float_t y);
ao_float_t ao_ldexp(ao_float_t x, int exp);
ao_float_t ao_ldexp10(ao_float_t x, int exp);
ao_float_t ao_pow(ao_float_t x, ao_float_t y);
ao_float_t ao_sqrt(ao_float_t x);
```

Rounding.

```c
ao_float_t ao_ceil(ao_float_t x);
ao_float_t ao_floor(ao_float_t x);
ao_float_t ao_modf(ao_float_t x, ao_float_t * intpart);
ao_float_t ao_round(ao_float_t x);
ao_float_t ao_round_away_from_infinity(ao_float_t x);
ao_float_t ao_round_away_from_negative_infinity(ao_float_t x);
ao_float_t ao_round_away_from_positive_infinity(ao_float_t x);
ao_float_t ao_round_away_from_zero(ao_float_t x);
ao_float_t ao_round_down(ao_float_t x);
ao_float_t ao_round_half_away_from_infinity(ao_float_t x);
ao_float_t ao_round_half_away_from_negative_infinity(ao_float_t x);
ao_float_t ao_round_half_away_from_positive_infinity(ao_float_t x);
ao_float_t ao_round_half_away_from_zero(ao_float_t x);
ao_float_t ao_round_half_down(ao_float_t x);
ao_float_t ao_round_half_to_even(ao_float_t x);
ao_float_t ao_round_half_to_infinity(ao_float_t x);
ao_float_t ao_round_half_to_negative_infinity(ao_float_t x);
ao_float_t ao_round_half_to_odd(ao_float_t x);
ao_float_t ao_round_half_to_positive_infinity(ao_float_t x);
ao_float_t ao_round_half_to_zero(ao_float_t x);
ao_float_t ao_round_half_up(ao_float_t x);
ao_float_t ao_round_to_infinity(ao_float_t x);
ao_float_t ao_round_to_negative_infinity(ao_float_t x);
ao_float_t ao_round_to_positive_infinity(ao_float_t x);
ao_float_t ao_round_to_zero(ao_float_t x);
ao_float_t ao_round_up(ao_float_t x);
ao_float_t ao_trunc(ao_float_t x);
```

Sign.

```c
ao_float_t ao_sign(ao_float_t x);
```

Trigonometric functions.

```c
ao_float_t ao_acos(ao_float_t x);
ao_float_t ao_acot(ao_float_t x);
ao_float_t ao_acsc(ao_float_t x);
ao_float_t ao_asec(ao_float_t x);
ao_float_t ao_asin(ao_float_t x);
ao_float_t ao_atan(ao_float_t x);
ao_float_t ao_atan2(ao_float_t y, ao_float_t x);
ao_float_t ao_cos(ao_float_t x);
ao_float_t ao_cot(ao_float_t x);
ao_float_t ao_csc(ao_float_t x);
ao_float_t ao_sec(ao_float_t x);
ao_float_t ao_sin(ao_float_t x);
ao_float_t ao_tan(ao_float_t x);
```

Wrapping.

```c
ao_float_t ao_wrap(ao_float_t x, ao_float_t beginning, ao_float_t length);
```
