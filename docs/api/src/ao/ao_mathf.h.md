---
author: "Stefan Wagner"
date: 2022-08-30
draft: true
permalink: /api/src/ao/ao_mathf.h/
toc: true
---

# Notes

This module provides mathematical constants and functions for floating-point numbers. Although the standard library provides such constants and functions, too, they are not available in a freestanding runtime environment. Nonetheless, many toolchains provide implementations for mathematical functions, that are highly optimized for the target platform, especially if the platform is equipped with a floating point unit. Therefore, this module is abstract, that is, an implementation must be provided by a port package.

# Include

```c
#include <stdbool.h>
```

# Identifier

```c
#define AO_MATHF
```

# Constants

```c
#define AO_1_PI               ( 0.31830988618379067153776752674502872406891929148091)
#define AO_2_PI               ( 0.63661977236758134307553505349005744813783858296183)
#define AO_2_SQRTPI           ( 1.12837916709551257389615890312154517168810125865800)
#define AO_DEGREES_PER_RADIAN (57.29577951308232087679815481410517033240547246656432)
#define AO_E                  ( 2.71828182845904523536028747135266249775724709369996)
#define AO_LN10               ( 2.30258509299404568401799145468436420760110148862877)
#define AO_LN2                ( 0.69314718055994530941723212145817656807550013436026)
#define AO_LOG10E             ( 0.43429448190325182765112891891660508229439700580367)
#define AO_LOG2E              ( 1.44269504088896340735992468100189213742664595415299)
#define AO_PI                 ( 3.14159265358979323846264338327950288419716939937511)
#define AO_PI_2               ( 1.57079632679489661923132169163975144209858469968755)
#define AO_PI_4               ( 0.78539816339744830961566084581987572104929234984378)
#define AO_RADIANS_PER_DEGREE ( 0.01745329251994329576923690768488612713442871888542)
#define AO_SQRT1_2            ( 0.70710678118654752440084436210484903928483593768847)
#define AO_SQRT2              ( 1.41421356237309504880168872420969807856967187537695)
```

These constants represent the following values.

| `AO_1_PI` | $$\frac{1}{\pi}$$ |
| `AO_2_PI` | $$\frac{2}{\pi}$$ |
| `AO_2_SQRTPI` | $$\frac{2}{\sqrt{\pi}}$$ |
| `AO_DEGREES_PER_RADIAN` | The number of degrees per radian |
| `AO_E` | $$e$$ |
| `AO_LN10` | $$\ln{10}$$ |
| `AO_LN2` | $$\ln{2}$$ |
| `AO_LOG10E` | $$\lg{e}$$ |
| `AO_LOG2E` | $$\log_2{e}$$ |
| `AO_PI` | $$\pi$$ |
| `AO_PI_2` | $$\frac{\pi}{2}$$ |
| `AO_PI_4` | $$\frac{\pi}{4}$$ |
| `AO_RADIANS_PER_DEGREE` | The number of radians per degree |
| `AO_SQRT1_2` | $$\sqrt{\frac{1}{2}}$$ |
| `AO_SQRT2` | $$\sqrt{2}$$ |

# Functions

## `ao_acos`

```c
double      ao_acosd(double      x);
float       ao_acosf(float       x);
long double ao_acosl(long double x);
```

Calculates the arc cosine of $$\texttt{x}$$.

## `ao_acosh`

```c
double      ao_acoshd(double      x);
float       ao_acoshf(float       x);
long double ao_acoshl(long double x);
```

Calculates the area hyperbolic cosine of $$\texttt{x}$$.

## `ao_acot`

```c
double      ao_acotd(double      x);
float       ao_acotf(float       x);
long double ao_acotl(long double x);
```

Calculates the arc cotangent of $$\texttt{x}$$.

## `ao_acoth`

```c
double      ao_acothd(double      x);
float       ao_acothf(float       x);
long double ao_acothl(long double x);
```

Calculates the area hyperbolic cotangent of $$\texttt{x}$$.

## `ao_acsc`

```c
double      ao_acscd(double      x);
float       ao_acscf(float       x);
long double ao_acscl(long double x);
```

Calculates the arc cosecant of $$\texttt{x}$$.

## `ao_acsch`

```c
double      ao_acschd(double      x);
float       ao_acschf(float       x);
long double ao_acschl(long double x);
```

Calculates the area hyperbolic cosecant of $$\texttt{x}$$.

## `ao_asec`

```c
double      ao_asecd(double      x);
float       ao_asecf(float       x);
long double ao_asecl(long double x);
```

Calculates the arc secant of $$\texttt{x}$$.

## `ao_asech`

```c
double      ao_asechd(double      x);
float       ao_asechf(float       x);
long double ao_asechl(long double x);
```

Calculates the area hyperbolic secant of $$\texttt{x}$$.

## `ao_asin`

```c
double      ao_asind(double      x);
float       ao_asinf(float       x);
long double ao_asinl(long double x);
```

Calculates the arc sine of $$\texttt{x}$$.

## `ao_asinh`

```c
double      ao_asinhd(double      x);
float       ao_asinhf(float       x);
long double ao_asinhl(long double x);
```

Calculates the area hyperbolic sine of $$\texttt{x}$$.

## `ao_atan`

```c
double      ao_atand(double      x);
float       ao_atanf(float       x);
long double ao_atanl(long double x);
```

Calculates the arc tangent of $$\texttt{x}$$.

## `ao_atan2`

```c
double      ao_atan2d(double      y, double      x);
float       ao_atan2f(float       y, float       x);
long double ao_atan2l(long double y, long double x);
```

Calculates the arc tangent of $$\frac{\texttt{y}}{\texttt{x}}$$.

## `ao_atanh`

```c
double      ao_atanhd(double      x);
float       ao_atanhf(float       x);
long double ao_atanhl(long double x);
```

Calculates the area hyperbolic tangent of $$\texttt{x}$$.

## `ao_cbrt`

```c
double      ao_cbrtd(double      x);
float       ao_cbrtf(float       x);
long double ao_cbrtl(long double x);
```

Calculates the cubic root of $$\texttt{x}$$.

## `ao_ceil`

```c
double      ao_ceild(double      x);
float       ao_ceilf(float       x);
long double ao_ceill(long double x);
```

Rounds $$\texttt{x}$$ up.

## `ao_cos`

```c
double      ao_cosd(double      x);
float       ao_cosf(float       x);
long double ao_cosl(long double x);
```

Calculates the cosine of $$\texttt{x}$$.

## `ao_cosh`

```c
double      ao_coshd(double      x);
float       ao_coshf(float       x);
long double ao_coshl(long double x);
```

Calculates the hyperbolic cosine of $$\texttt{x}$$.

## `ao_cot`

```c
double      ao_cotd(double      x);
float       ao_cotf(float       x);
long double ao_cotl(long double x);
```

Calculates the cotangent of $$\texttt{x}$$.

## `ao_coth`

```c
double      ao_cothd(double      x);
float       ao_cothf(float       x);
long double ao_cothl(long double x);
```

Calculates the hyperbolic cotangent of $$\texttt{x}$$.

## `ao_csc`

```c
double      ao_cscd(double      x);
float       ao_cscf(float       x);
long double ao_cscl(long double x);
```

Calculates the cosecant of $$\texttt{x}$$.

## `ao_csch`

```c
double      ao_cschd(double      x);
float       ao_cschf(float       x);
long double ao_cschl(long double x);
```

Calculates the hyperbolic cosecant of $$\texttt{x}$$.

## `ao_deg2rad`

```c
double      ao_deg2radd(double      x);
float       ao_deg2radf(float       x);
long double ao_deg2radl(long double x);
```

Converts degrees to radians.

## `ao_exp`

```c
double      ao_expd(double      x);
float       ao_expf(float       x);
long double ao_expl(long double x);
```

Calculates $$e^\texttt{x}$$.

## `ao_exp2`

```c
double      ao_exp2d(double      x);
float       ao_exp2f(float       x);
long double ao_exp2l(long double x);
```

Calculates $$2^\texttt{x}$$.

## `ao_fabs`

```c
double      ao_fabsd(double      x);
float       ao_fabsf(float       x);
long double ao_fabsl(long double x);
```

Calculates the absolute value of $$\texttt{x}$$.

## `ao_floor`

```c
double      ao_floord(double      x);
float       ao_floorf(float       x);
long double ao_floorl(long double x);
```

Rounds $$\texttt{x}$$ down.

## `ao_fmod`

```c
double      ao_fmodd(double      x, double      y);
float       ao_fmodf(float       x, float       y);
long double ao_fmodl(long double x, long double y);
```

Calculates the remainder of $$\frac{\texttt{x}}{\texttt{y}}$$ rounded to zero.

## `ao_frexp`

```c
double      ao_frexpd(double      x, int * exp);
float       ao_frexpf(float       x, int * exp);
long double ao_frexpl(long double x, int * exp);
```

Breaks $$\texttt{x}$$ into its binary significant and an integral exponent for 2.

## `ao_frexp10`

```c
double      ao_frexp10d(double      x, int * exp);
float       ao_frexp10f(float       x, int * exp);
long double ao_frexp10l(long double x, int * exp);
```

Breaks $$\texttt{x}$$ into its decimal significant and an integral exponent for 10.

## `ao_hypot`

```c
double      ao_hypotd(double      x, double      y);
float       ao_hypotf(float       x, float       y);
long double ao_hypotl(long double x, long double y);
```

Calculates $$\sqrt{\texttt{x}^2 + \texttt{y}^2}$$.

## `ao_inf`

```c
double      ao_infd();
float       ao_inff();
long double ao_infl();
```

Generates positive infinity.

## `ao_isfinite`

```c
bool ao_isfinited(double      x);
bool ao_isfinitef(float       x);
bool ao_isfinitel(long double x);
```

Checks whether $$\texttt{x}$$ is finite.

## `ao_isinf`

```c
bool ao_isinfd(double      x);
bool ao_isinff(float       x);
bool ao_isinfl(long double x);
```

Checks whether $$\texttt{x}$$ is positive or negative infinity.

## `ao_isnan`

```c
bool ao_isnand(double      x);
bool ao_isnanf(float       x);
bool ao_isnanl(long double x);
```

Checks whether $$\texttt{x}$$ is not a number.

## `ao_ldexp`

```c
double      ao_ldexpd(double      x, int exp);
float       ao_ldexpf(float       x, int exp);
long double ao_ldexpl(long double x, int exp);
```

Calculates $$\texttt{x} \cdot 2^{\texttt{exp}}$$.

## `ao_ldexp10`

```c
double      ao_ldexp10d(double      x, int exp);
float       ao_ldexp10f(float       x, int exp);
long double ao_ldexp10l(long double x, int exp);
```

Calculates $$\texttt{x} \cdot 10^{\texttt{exp}}$$.

## `ao_log`

```c
double      ao_logd(double      x);
float       ao_logf(float       x);
long double ao_logl(long double x);
```

Calculates the natural logarithm of $$\texttt{x}$$.

## `ao_log10`

```c
double      ao_log10d(double      x);
float       ao_log10f(float       x);
long double ao_log10l(long double x);
```

Calculates the common logarithm of $$\texttt{x}$$.

## `ao_log2`

```c
double      ao_log2d(double      x);
float       ao_log2f(float       x);
long double ao_log2l(long double x);
```

Calculates the binary logarithm of $$\texttt{x}$$.

## `ao_modf`

```c
double      ao_modfd(double      x, double      * intpart);
float       ao_modff(float       x, float       * intpart);
long double ao_modfl(long double x, long double * intpart);
```

Breaks $$\texttt{x}$$ into an integral and a fractional part.

## `ao_nan`

```c
double      ao_nand();
float       ao_nanf();
long double ao_nanl();
```

Generates not a number.

## `ao_pow`

```c
double      ao_powd(double      x, double      y);
float       ao_powf(float       x, float       y);
long double ao_powl(long double x, long double y);
```

Calculates $$\texttt{x}^\texttt{y}$$.

## `ao_rad2deg`

```c
double      ao_rad2degd(double      x);
float       ao_rad2degf(float       x);
long double ao_rad2degl(long double x);
```

Converts radians to degrees.

## `ao_round`

```c
#define ao_roundd(x) ao_roundd_half_away_from_zero(x)
#define ao_roundf(x) ao_roundf_half_away_from_zero(x)
#define ao_roundl(x) ao_roundl_half_away_from_zero(x)
```

Rounds $$\texttt{x}$$ to the nearest integer. Rounds half away from zero.

## `ao_round_away_from_infinity`

```c
#define ao_roundd_away_from_infinity(x) ao_truncd(x)
#define ao_roundf_away_from_infinity(x) ao_truncf(x)
#define ao_roundl_away_from_infinity(x) ao_truncl(x)
```

Rounds $$\texttt{x}$$ away from infinity.

## `ao_round_away_from_negative_infinity`

```c
#define ao_roundd_away_from_negative_infinity(x) ao_ceild(x)
#define ao_roundf_away_from_negative_infinity(x) ao_ceilf(x)
#define ao_roundl_away_from_negative_infinity(x) ao_ceill(x)
```

Rounds $$\texttt{x}$$ away from negative infinity.

## `ao_round_away_from_positive_infinity`

```c
#define ao_roundd_away_from_positive_infinity(x) ao_floord(x)
#define ao_roundf_away_from_positive_infinity(x) ao_floorf(x)
#define ao_roundl_away_from_positive_infinity(x) ao_floorl(x)
```

Rounds $$\texttt{x}$$ away from positive infinity.

## `ao_round_away_from_zero`

```c
double      ao_roundd_away_from_zero(double      x);
float       ao_roundf_away_from_zero(float       x);
long double ao_roundl_away_from_zero(long double x);
```

Rounds $$\texttt{x}$$ away from zero.

## `ao_round_down`

```c
#define ao_roundd_down(x) ao_floord(x)
#define ao_roundf_down(x) ao_floorf(x)
#define ao_roundl_down(x) ao_floorl(x)
```

Rounds $$\texttt{x}$$ down.

## `ao_round_half_away_from_infinity`

```c
#define ao_roundd_half_away_from_infinity(x) ao_roundd_half_to_zero(x)
#define ao_roundf_half_away_from_infinity(x) ao_roundf_half_to_zero(x)
#define ao_roundl_half_away_from_infinity(x) ao_roundl_half_to_zero(x)
```

Rounds $$\texttt{x}$$ to the nearest integer. Rounds half away from infinity.

## `ao_round_half_away_from_negative_infinity`

```c
#define ao_roundd_half_away_from_negative_infinity(x) ao_roundd_half_up(x)
#define ao_roundf_half_away_from_negative_infinity(x) ao_roundf_half_up(x)
#define ao_roundl_half_away_from_negative_infinity(x) ao_roundl_half_up(x)
```

Rounds $$\texttt{x}$$ to the nearest integer. Rounds half away from negative infinity.

## `ao_round_half_away_from_positive_infinity`

```c
#define ao_roundd_half_away_from_positive_infinity(x) ao_roundd_half_down(x)
#define ao_roundf_half_away_from_positive_infinity(x) ao_roundf_half_down(x)
#define ao_roundl_half_away_from_positive_infinity(x) ao_roundl_half_down(x)
```

Rounds $$\texttt{x}$$ to the nearest integer. Rounds half away from positive infinity.

## `ao_round_half_away_from_zero`

```c
#define ao_roundd_half_away_from_zero(x) ao_roundd_half_to_infinity(x)
#define ao_roundf_half_away_from_zero(x) ao_roundf_half_to_infinity(x)
#define ao_roundl_half_away_from_zero(x) ao_roundl_half_to_infinity(x)
```

Rounds $$\texttt{x}$$ to the nearest integer. Rounds half away from zero.

## `ao_round_half_down`

```c
double      ao_roundd_half_down(double      x);
float       ao_roundf_half_down(float       x);
long double ao_roundl_half_down(long double x);
```

Rounds $$\texttt{x}$$ to the nearest integer. Rounds half down.

## `ao_round_half_to_even`

```c
double      ao_roundd_half_to_even(double      x);
float       ao_roundf_half_to_even(float       x);
long double ao_roundl_half_to_even(long double x);
```

Rounds $$\texttt{x}$$ to the nearest integer. Rounds half to even.

## `ao_round_half_to_infinity`

```c
double      ao_roundd_half_to_infinity(double      x);
float       ao_roundf_half_to_infinity(float       x);
long double ao_roundl_half_to_infinity(long double x);
```

Rounds $$\texttt{x}$$ to the nearest integer. Rounds half to infinity.

## `ao_round_half_to_negative_infinity`

```c
#define ao_roundd_half_to_negative_infinity(x) ao_roundd_half_down(x)
#define ao_roundf_half_to_negative_infinity(x) ao_roundf_half_down(x)
#define ao_roundl_half_to_negative_infinity(x) ao_roundl_half_down(x)
```

Rounds $$\texttt{x}$$ to the nearest integer. Rounds half to negative infinity.

## `ao_round_half_to_odd`

```c
double      ao_roundd_half_to_odd(double      x);
float       ao_roundf_half_to_odd(float       x);
long double ao_roundl_half_to_odd(long double x);
```

Rounds $$\texttt{x}$$ to the nearest integer. Rounds half to odd.

## `ao_round_half_to_positive_infinity`

```c
#define ao_roundd_half_to_positive_infinity(x) ao_roundd_half_up(x)
#define ao_roundf_half_to_positive_infinity(x) ao_roundf_half_up(x)
#define ao_roundl_half_to_positive_infinity(x) ao_roundl_half_up(x)
```

Rounds $$\texttt{x}$$ to the nearest integer. Rounds half to positive infinity.

## `ao_round_half_to_zero`

```c
double      ao_roundd_half_to_zero(double      x);
float       ao_roundf_half_to_zero(float       x);
long double ao_roundl_half_to_zero(long double x);
```

Rounds $$\texttt{x}$$ to the nearest integer. Rounds half to zero.

## `ao_round_half_up`

```c
double      ao_roundd_half_up(double      x);
float       ao_roundf_half_up(float       x);
long double ao_roundl_half_up(long double x);
```

Rounds $$\texttt{x}$$ to the nearest integer. Rounds half up.

## `ao_round_to_infinity`

```c
#define ao_roundd_to_infinity(x) ao_roundd_away_from_zero(x)
#define ao_roundf_to_infinity(x) ao_roundf_away_from_zero(x)
#define ao_roundl_to_infinity(x) ao_roundl_away_from_zero(x)
```

Rounds $$\texttt{x}$$ to infinity.

## `ao_round_to_negative_infinity`

```c
#define ao_roundd_to_negative_infinity(x) ao_floord(x)
#define ao_roundf_to_negative_infinity(x) ao_floorf(x)
#define ao_roundl_to_negative_infinity(x) ao_floorl(x)
```

Rounds $$\texttt{x}$$ to negative infinity.

## `ao_round_to_positive_infinity`

```c
#define ao_roundd_to_positive_infinity(x) ao_ceild(x)
#define ao_roundf_to_positive_infinity(x) ao_ceilf(x)
#define ao_roundl_to_positive_infinity(x) ao_ceill(x)
```

Rounds $$\texttt{x}$$ to positive infinity.

## `ao_round_to_zero`

```c
#define ao_roundd_to_zero(x) ao_truncd(x)
#define ao_roundf_to_zero(x) ao_truncf(x)
#define ao_roundl_to_zero(x) ao_truncl(x)
```

Rounds $$\texttt{x}$$ to zero.

## `ao_round_up`

```c
#define ao_roundd_up(x) ao_ceild(x)
#define ao_roundf_up(x) ao_ceilf(x)
#define ao_roundl_up(x) ao_ceill(x)
```

Rounds $$\texttt{x}$$ up.

## `ao_sec`

```c
double      ao_secd(double      x);
float       ao_secf(float       x);
long double ao_secl(long double x);
```

Calculates the secant of $$\texttt{x}$$.

## `ao_sech`

```c
double      ao_sechd(double      x);
float       ao_sechf(float       x);
long double ao_sechl(long double x);
```

Calculates the hyperbolic secant of $$\texttt{x}$$.

## `ao_sign`

```c
double      ao_signd(double      x);
float       ao_signf(float       x);
long double ao_signl(long double x);
```

Calculates the sign of $$\texttt{x}$$.

## `ao_sin`

```c
double      ao_sind(double      x);
float       ao_sinf(float       x);
long double ao_sinl(long double x);
```

Calculates the sine of $$\texttt{x}$$.

## `ao_sinh`

```c
double      ao_sinhd(double      x);
float       ao_sinhf(float       x);
long double ao_sinhl(long double x);
```

Calculates the hyperbolic sine of $$\texttt{x}$$.

## `ao_sqrt`

```c
double      ao_sqrtd(double      x);
float       ao_sqrtf(float       x);
long double ao_sqrtl(long double x);
```

Calculates the square root of $$\texttt{x}$$.

## `ao_tan`

```c
double      ao_tand(double      x);
float       ao_tanf(float       x);
long double ao_tanl(long double x);
```

Calculates the tangent of $$\texttt{x}$$.

## `ao_tanh`

```c
double      ao_tanhd(double      x);
float       ao_tanhf(float       x);
long double ao_tanhl(long double x);
```

Calculates the hyperbolic tangent of $$\texttt{x}$$.

## `ao_trunc`

```c
double      ao_truncd(double      x);
float       ao_truncf(float       x);
long double ao_truncl(long double x);
```

Rounds $$\texttt{x}$$ to zero.

## `ao_wrap`

```c
double      ao_wrapd(double      x, double      beginning, double      length);
float       ao_wrapf(float       x, float       beginning, float       length);
long double ao_wrapl(long double x, long double beginning, long double length);
```

Wraps $$\texttt{x}$$ in $$[\texttt{beginning}, \texttt{length})$$.
