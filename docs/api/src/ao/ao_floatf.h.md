---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao/ao_floatf.h/
seealso:
- /api/src/ao/ao_mathf.h/
toc: true
---

# Notes

This module defines the fastest floating-point type available on the target platform to be the `float` type.

# Include

```c
#include <ao_mathf.h>
#include <float.h>
```

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

The maximum and minimum value, respectively.

# Types

## `ao_float_t`

```c
typedef float ao_float_t;
```

This type represents the fastest floating-point type available on the target platform.

# Functions

## `ao_acos`

```c
#define ao_acos(x) \
(                  \
    ao_acosf(x)    \
)
```

Calculates the arc cosine of $$\texttt{x}$$.

## `ao_acosh`

```c
#define ao_acosh(x) \
(                   \
    ao_acoshf(x)    \
)
```

Calculates the area hyperbolic cosine of $$\texttt{x}$$.

## `ao_acot`

```c
#define ao_acot(x) \
(                  \
    ao_acotf(x)    \
)
```

Calculates the arc cotangent of $$\texttt{x}$$.

## `ao_acoth`

```c
#define ao_acoth(x) \
(                   \
    ao_acothf(x)    \
)
```

Calculates the area hyperbolic cotangent of $$\texttt{x}$$.

## `ao_acsc`

```c
#define ao_acsc(x) \
(                  \
    ao_acscf(x)    \
)
```

Calculates the arc cosecant of $$\texttt{x}$$.

## `ao_acsch`

```c
#define ao_acsch(x) \
(                   \
    ao_acschf(x)    \
)
```

Calculates the area hyperbolic cosecant of $$\texttt{x}$$.

## `ao_asec`

```c
#define ao_asec(x) \
(                  \
    ao_asecf(x)    \
)
```

Calculates the arc secant of $$\texttt{x}$$.

## `ao_asech`

```c
#define ao_asech(x) \
(                   \
    ao_asechf(x)    \
)
```

Calculates the area hyperbolic secant of $$\texttt{x}$$.

## `ao_asin`

```c
#define ao_asin(x) \
(                  \
    ao_asinf(x)    \
)
```

Calculates the arc sine of $$\texttt{x}$$.

## `ao_asinh`

```c
#define ao_asinh(x) \
(                   \
    ao_asinhf(x)    \
)
```

Calculates the area hyperbolic sine of $$\texttt{x}$$.

## `ao_atan`

```c
#define ao_atan(x) \
(                  \
    ao_atanf(x)    \
)
```

Calculates the arc tangent of $$\texttt{x}$$.

## `ao_atan2`

```c
#define ao_atan2(y, x) \
(                      \
    ao_atan2f(y, x)    \
)
```

Calculates the arc tangent of $$\frac{\texttt{y}}{\texttt{x}}$$.

## `ao_atanh`

```c
#define ao_atanh(x) \
(                   \
    ao_atanhf(x)    \
)
```

Calculates the area hyperbolic tangent of $$\texttt{x}$$.

## `ao_cbrt`

```c
#define ao_cbrt(x) \
(                  \
    ao_cbrtf(x)    \
)
```

Calculates the cubic root of $$\texttt{x}$$.

## `ao_ceil`

```c
#define ao_ceil(x) \
(                  \
    ao_ceilf(x)    \
)
```

Rounds $$\texttt{x}$$ up.

## `ao_cos`

```c
#define ao_cos(x) \
(                 \
    ao_cosf(x)    \
)
```

Calculates the cosine of $$\texttt{x}$$.

## `ao_cosh`

```c
#define ao_cosh(x) \
(                  \
    ao_coshf(x)    \
)
```

Calculates the hyperbolic cosine of $$\texttt{x}$$.

## `ao_cot`

```c
#define ao_cot(x) \
(                 \
    ao_cotf(x)    \
)
```

Calculates the cotangent of $$\texttt{x}$$.

## `ao_coth`

```c
#define ao_coth(x) \
(                  \
    ao_cothf(x)    \
)
```

Calculates the hyperbolic cotangent of $$\texttt{x}$$.

## `ao_csc`

```c
#define ao_csc(x) \
(                 \
    ao_cscf(x)    \
)
```

Calculates the cosecant of $$\texttt{x}$$.

## `ao_csch`

```c
#define ao_csch(x) \
(                  \
    ao_cschf(x)    \
)
```

Calculates the hyperbolic cosecant of $$\texttt{x}$$.

## `ao_deg2rad`

```c
#define ao_deg2rad(x) \
(                     \
    ao_deg2radf(x)    \
)
```

Converts degrees to radians.

## `ao_exp`

```c
#define ao_exp(x) \
(                 \
    ao_expf(x)    \
)
```

Calculates $$e^\texttt{x}$$.

## `ao_exp2`

```c
#define ao_exp2(x) \
(                  \
    ao_exp2f(x)    \
)
```

Calculates $$2^\texttt{x}$$.

## `ao_fabs`

```c
#define ao_fabs(x) \
(                  \
    ao_fabsf(x)    \
)
```

Calculates the absolute value of $$\texttt{x}$$.

## `ao_floor`

```c
#define ao_floor(x) \
(                   \
    ao_floorf(x)    \
)
```

Rounds $$\texttt{x}$$ down.

## `ao_fmod`

```c
#define ao_fmod(x, y) \
(                     \
    ao_fmodf(x, y)    \
)
```

Calculates the remainder of $$\frac{\texttt{x}}{\texttt{y}}$$ rounded to zero.

## `ao_frexp`

```c
#define ao_frexp(x, exp) \
(                        \
    ao_frexpf(x, exp)    \
)
```

Breaks $$\texttt{x}$$ into its binary significant and an integral exponent for 2.

## `ao_frexp10`

```c
#define ao_frexp10(x, exp) \
(                          \
    ao_frexp10f(x, exp)    \
)
```

Breaks $$\texttt{x}$$ into its decimal significant and an integral exponent for 10.

## `ao_hypot`

```c
#define ao_hypot(x, y) \
(                      \
    ao_hypotf(x, y)    \
)
```

Calculates $$\sqrt{\texttt{x}^2 + \texttt{y}^2}$$.

## `ao_inf`

```c
#define ao_inf() \
(                \
    ao_inff()    \
)
```

Generates positive infinity.

## `ao_isfinite`

```c
#define ao_isfinite(x) \
(                      \
    ao_isfinitef(x)    \
)
```

Checks whether $$\texttt{x}$$ is finite.

## `ao_isinf`

```c
#define ao_isinf(x) \
(                   \
    ao_isinff(x)    \
)
```

Checks whether $$\texttt{x}$$ is positive or negative infinity.

## `ao_isnan`

```c
#define ao_isnan(x) \
(                   \
    ao_isnanf(x)    \
)
```

Checks whether $$\texttt{x}$$ is not a number.

## `ao_ldexp`

```c
#define ao_ldexp(x, exp) \
(                        \
    ao_ldexpf(x, exp)    \
)
```

Calculates $$\texttt{x} \cdot 2^{\texttt{exp}}$$.

## `ao_ldexp10`

```c
#define ao_ldexp10(x, exp) \
(                          \
    ao_ldexp10f(x, exp)    \
)
```

Calculates $$\texttt{x} \cdot 10^{\texttt{exp}}$$.

## `ao_log`

```c
#define ao_log(x) \
(                 \
    ao_logf(x)    \
)
```

Calculates the natural logarithm of $$\texttt{x}$$.

## `ao_log10`

```c
#define ao_log10(x) \
(                   \
    ao_log10f(x)    \
)
```

Calculates the common logarithm of $$\texttt{x}$$.

## `ao_log2`

```c
#define ao_log2(x) \
(                  \
    ao_log2f(x)    \
)
```

Calculates the binary logarithm of $$\texttt{x}$$.

## `ao_modf`

```c
#define ao_modf(x, intpart) \
(                           \
    ao_modff(x, intpart)    \
)
```

Breaks $$\texttt{x}$$ into an integral and a fractional part.

## `ao_nan`

```c
#define ao_nan() \
(                \
    ao_nanf()    \
)
```

Generates not a number.

## `ao_pow`

```c
#define ao_pow(x, y) \
(                    \
    ao_powf(x, y)    \
)
```

Calculates $$\texttt{x}^\texttt{y}$$.

## `ao_rad2deg`

```c
#define ao_rad2deg(x) \
(                     \
    ao_rad2degf(x)    \
)
```

Converts radians to degrees.

## `ao_round`

```c
#define ao_round(x) \
(                   \
    ao_roundf(x)    \
)
```

Rounds $$\texttt{x}$$ to the nearest integer. Rounds half away from zero.

## `ao_round_away_from_infinity`

```c
#define ao_round_away_from_infinity(x) \
(                                      \
    ao_roundf_away_from_infinity(x)    \
)
```

Rounds $$\texttt{x}$$ away from infinity.

## `ao_round_away_from_negative_infinity`

```c
#define ao_round_away_from_negative_infinity(x) \
(                                               \
    ao_roundf_away_from_negative_infinity(x)    \
)
```

Rounds $$\texttt{x}$$ away from negative infinity.

## `ao_round_away_from_positive_infinity`

```c
#define ao_round_away_from_positive_infinity(x) \
(                                               \
    ao_roundf_away_from_positive_infinity(x)    \
)
```

Rounds $$\texttt{x}$$ away from positive infinity.

## `ao_round_away_from_zero`

```c
#define ao_round_away_from_zero(x) \
(                                  \
    ao_roundf_away_from_zero(x)    \
)
```

Rounds $$\texttt{x}$$ away from zero.

## `ao_round_down`

```c
#define ao_round_down(x) \
(                        \
    ao_roundf_down(x)    \
)
```

Rounds $$\texttt{x}$$ down.

## `ao_round_half_away_from_infinity`

```c
#define ao_round_half_away_from_infinity(x) \
(                                           \
    ao_roundf_half_away_from_infinity(x)    \
)
```

Rounds $$\texttt{x}$$ to the nearest integer. Rounds half away from infinity.

## `ao_round_half_away_from_negative_infinity`

```c
#define ao_round_half_away_from_negative_infinity(x) \
(                                                    \
    ao_roundf_half_away_from_negative_infinity(x)    \
)
```

Rounds $$\texttt{x}$$ to the nearest integer. Rounds half away from negative infinity.

## `ao_round_half_away_from_positive_infinity`

```c
#define ao_round_half_away_from_positive_infinity(x) \
(                                                    \
    ao_roundf_half_away_from_positive_infinity(x)    \
)
```

Rounds $$\texttt{x}$$ to the nearest integer. Rounds half away from positive infinity.

## `ao_round_half_away_from_zero`

```c
#define ao_round_half_away_from_zero(x) \
(                                       \
    ao_roundf_half_away_from_zero(x)    \
)
```

Rounds $$\texttt{x}$$ to the nearest integer. Rounds half away from zero.

## `ao_round_half_down`

```c
#define ao_round_half_down(x) \
(                             \
    ao_roundf_half_down(x)    \
)
```

Rounds $$\texttt{x}$$ to the nearest integer. Rounds half down.

## `ao_round_half_to_even`

```c
#define ao_round_half_to_even(x) \
(                                \
    ao_roundf_half_to_even(x)    \
)
```

Rounds $$\texttt{x}$$ to the nearest integer. Rounds half to even.

## `ao_round_half_to_infinity`

```c
#define ao_round_half_to_infinity(x) \
(                                    \
    ao_roundf_half_to_infinity(x)    \
)
```

Rounds $$\texttt{x}$$ to the nearest integer. Rounds half to infinity.

## `ao_round_half_to_negative_infinity`

```c
#define ao_round_half_to_negative_infinity(x) \
(                                             \
    ao_roundf_half_to_negative_infinity(x)    \
)
```

Rounds $$\texttt{x}$$ to the nearest integer. Rounds half to negative infinity.

## `ao_round_half_to_odd`

```c
#define ao_round_half_to_odd(x) \
(                               \
    ao_roundf_half_to_odd(x)    \
)
```

Rounds $$\texttt{x}$$ to the nearest integer. Rounds half to odd.

## `ao_round_half_to_positive_infinity`

```c
#define ao_round_half_to_positive_infinity(x) \
(                                             \
    ao_roundf_half_to_positive_infinity(x)    \
)
```

Rounds $$\texttt{x}$$ to the nearest integer. Rounds half to positive infinity.

## `ao_round_half_to_zero`

```c
#define ao_round_half_to_zero(x) \
(                                \
    ao_roundf_half_to_zero(x)    \
)
```

Rounds $$\texttt{x}$$ to the nearest integer. Rounds half to zero.

## `ao_round_half_up`

```c
#define ao_round_half_up(x) \
(                           \
    ao_roundf_half_up(x)    \
)
```

Rounds $$\texttt{x}$$ to the nearest integer. Rounds half up.

## `ao_round_to_infinity`

```c
#define ao_round_to_infinity(x) \
(                               \
    ao_roundf_to_infinity(x)    \
)
```

Rounds $$\texttt{x}$$ to infinity.

## `ao_round_to_negative_infinity`

```c
#define ao_round_to_negative_infinity(x) \
(                                        \
    ao_roundf_to_negative_infinity(x)    \
)
```

Rounds $$\texttt{x}$$ to negative infinity.

## `ao_round_to_positive_infinity`

```c
#define ao_round_to_positive_infinity(x) \
(                                        \
    ao_roundf_to_positive_infinity(x)    \
)
```

Rounds $$\texttt{x}$$ to positive infinity.

## `ao_round_to_zero`

```c
#define ao_round_to_zero(x) \
(                           \
    ao_roundf_to_zero(x)    \
)
```

Rounds $$\texttt{x}$$ to zero.

## `ao_round_up`

```c
#define ao_round_up(x) \
(                      \
    ao_roundf_up(x)    \
)
```

Rounds $$\texttt{x}$$ up.

## `ao_sec`

```c
#define ao_sec(x) \
(                 \
    ao_secf(x)    \
)
```

Calculates the secant of $$\texttt{x}$$.

## `ao_sech`

```c
#define ao_sech(x) \
(                  \
    ao_sechf(x)    \
)
```

Calculates the hyperbolic secant of $$\texttt{x}$$.

## `ao_sign`

```c
#define ao_sign(x) \
(                  \
    ao_signf(x)    \
)
```

Calculates the sign of $$\texttt{x}$$.

## `ao_sin`

```c
#define ao_sin(x) \
(                 \
    ao_sinf(x)    \
)
```

Calculates the sine of $$\texttt{x}$$.

## `ao_sinh`

```c
#define ao_sinh(x) \
(                  \
    ao_sinhf(x)    \
)
```

Calculates the hyperbolic sine of $$\texttt{x}$$.

## `ao_sqrt`

```c
#define ao_sqrt(x) \
(                  \
    ao_sqrtf(x)    \
)
```

Calculates the square root of $$\texttt{x}$$.

## `ao_tan`

```c
#define ao_tan(x) \
(                 \
    ao_tanf(x)    \
)
```

Calculates the tangent of $$\texttt{x}$$.

## `ao_tanh`

```c
#define ao_tanh(x) \
(                  \
    ao_tanhf(x)    \
)
```

Calculates the hyperbolic tangent of $$\texttt{x}$$.

## `ao_trunc`

```c
#define ao_trunc(x) \
(                   \
    ao_truncf(x)    \
)
```

Rounds $$\texttt{x}$$ to zero.

## `ao_wrap`

```c
#define ao_wrap(x, beginning, length) \
(                                     \
    ao_wrapf(x, beginning, length)    \
)
```

Wraps $$\texttt{x}$$ in $$[\texttt{beginning}, \texttt{length})$$.
