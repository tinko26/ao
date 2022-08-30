---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao/ao_mathf.h file of the ao real-time operating system."
draft: true
permalink: /src/ao/ao_mathf.h/
subtitle: ""
title: "ao_mathf.h"
toc: true
---

# Include

```c
#include <stdbool.h>
```

# Constants

```c
#define AO_1_PI ( 0.31830988618379067153776752674502872406891929148091)
```

```c
#define AO_2_PI ( 0.63661977236758134307553505349005744813783858296183)
```

```c
#define AO_2_SQRTPI ( 1.12837916709551257389615890312154517168810125865800)
```

```c
#define AO_DEGREES_PER_RADIAN (57.29577951308232087679815481410517033240547246656432)
```

```c
#define AO_E ( 2.71828182845904523536028747135266249775724709369996)
```

```c
#define AO_LN10 ( 2.30258509299404568401799145468436420760110148862877)
```

```c
#define AO_LN2 ( 0.69314718055994530941723212145817656807550013436026)
```

```c
#define AO_LOG10E ( 0.43429448190325182765112891891660508229439700580367)
```

```c
#define AO_LOG2E ( 1.44269504088896340735992468100189213742664595415299)
```

```c
#define AO_PI ( 3.14159265358979323846264338327950288419716939937511)
```

```c
#define AO_PI_2 ( 1.57079632679489661923132169163975144209858469968755)
```

```c
#define AO_PI_4 ( 0.78539816339744830961566084581987572104929234984378)
```

```c
#define AO_RADIANS_PER_DEGREE ( 0.01745329251994329576923690768488612713442871888542)
```

```c
#define AO_SQRT1_2 ( 0.70710678118654752440084436210484903928483593768847)
```

```c
#define AO_SQRT2 ( 1.41421356237309504880168872420969807856967187537695)
```

# Functions

```c
#define ao_roundd(x)
```

```c
#define ao_roundf(x)
```

```c
#define ao_roundl(x)
```

```c
#define ao_roundd_away_from_infinity(x)
```

```c
#define ao_roundf_away_from_infinity(x)
```

```c
#define ao_roundl_away_from_infinity(x)
```

```c
#define ao_roundd_away_from_negative_infinity(x)
```

```c
#define ao_roundf_away_from_negative_infinity(x)
```

```c
#define ao_roundl_away_from_negative_infinity(x)
```

```c
#define ao_roundd_away_from_positive_infinity(x)
```

```c
#define ao_roundf_away_from_positive_infinity(x)
```

```c
#define ao_roundl_away_from_positive_infinity(x)
```

```c
#define ao_roundd_down(x)
```

```c
#define ao_roundf_down(x)
```

```c
#define ao_roundl_down(x)
```

```c
#define ao_roundd_half_away_from_infinity(x)
```

```c
#define ao_roundf_half_away_from_infinity(x)
```

```c
#define ao_roundl_half_away_from_infinity(x)
```

```c
#define ao_roundd_half_away_from_negative_infinity(x)
```

```c
#define ao_roundf_half_away_from_negative_infinity(x)
```

```c
#define ao_roundl_half_away_from_negative_infinity(x)
```

```c
#define ao_roundd_half_away_from_positive_infinity(x)
```

```c
#define ao_roundf_half_away_from_positive_infinity(x)
```

```c
#define ao_roundl_half_away_from_positive_infinity(x)
```

```c
#define ao_roundd_half_away_from_zero(x)
```

```c
#define ao_roundf_half_away_from_zero(x)
```

```c
#define ao_roundl_half_away_from_zero(x)
```

```c
#define ao_roundd_half_to_negative_infinity(x)
```

```c
#define ao_roundf_half_to_negative_infinity(x)
```

```c
#define ao_roundl_half_to_negative_infinity(x)
```

```c
#define ao_roundd_half_to_positive_infinity(x)
```

```c
#define ao_roundf_half_to_positive_infinity(x)
```

```c
#define ao_roundl_half_to_positive_infinity(x)
```

```c
#define ao_roundd_to_infinity(x)
```

```c
#define ao_roundf_to_infinity(x)
```

```c
#define ao_roundl_to_infinity(x)
```

```c
#define ao_roundd_to_negative_infinity(x)
```

```c
#define ao_roundf_to_negative_infinity(x)
```

```c
#define ao_roundl_to_negative_infinity(x)
```

```c
#define ao_roundd_to_positive_infinity(x)
```

```c
#define ao_roundf_to_positive_infinity(x)
```

```c
#define ao_roundl_to_positive_infinity(x)
```

```c
#define ao_roundd_to_zero(x)
```

```c
#define ao_roundf_to_zero(x)
```

```c
#define ao_roundl_to_zero(x)
```

```c
#define ao_roundd_up(x)
```

```c
#define ao_roundf_up(x)
```

```c
#define ao_roundl_up(x)
```

```c
double ao_acosd(double x);
```

```c
float ao_acosf(float x);
```

```c
long double ao_acosl(long double x);
```

```c
double ao_acoshd(double x);
```

```c
float ao_acoshf(float x);
```

```c
long double ao_acoshl(long double x);
```

```c
double ao_acotd(double x);
```

```c
float ao_acotf(float x);
```

```c
long double ao_acotl(long double x);
```

```c
double ao_acothd(double x);
```

```c
float ao_acothf(float x);
```

```c
long double ao_acothl(long double x);
```

```c
double ao_acscd(double x);
```

```c
float ao_acscf(float x);
```

```c
long double ao_acscl(long double x);
```

```c
double ao_acschd(double x);
```

```c
float ao_acschf(float x);
```

```c
long double ao_acschl(long double x);
```

```c
double ao_asecd(double x);
```

```c
float ao_asecf(float x);
```

```c
long double ao_asecl(long double x);
```

```c
double ao_asechd(double x);
```

```c
float ao_asechf(float x);
```

```c
long double ao_asechl(long double x);
```

```c
double ao_asind(double x);
```

```c
float ao_asinf(float x);
```

```c
long double ao_asinl(long double x);
```

```c
double ao_asinhd(double x);
```

```c
float ao_asinhf(float x);
```

```c
long double ao_asinhl(long double x);
```

```c
double ao_atand(double x);
```

```c
float ao_atanf(float x);
```

```c
long double ao_atanl(long double x);
```

```c
double ao_atan2d(double y, double x);
```

```c
float ao_atan2f(float y, float x);
```

```c
long double ao_atan2l(long double y, long double x);
```

```c
double ao_atanhd(double x);
```

```c
float ao_atanhf(float x);
```

```c
long double ao_atanhl(long double x);
```

```c
double ao_cbrtd(double x);
```

```c
float ao_cbrtf(float x);
```

```c
long double ao_cbrtl(long double x);
```

```c
double ao_ceild(double x);
```

```c
float ao_ceilf(float x);
```

```c
long double ao_ceill(long double x);
```

```c
double ao_cosd(double x);
```

```c
float ao_cosf(float x);
```

```c
long double ao_cosl(long double x);
```

```c
double ao_coshd(double x);
```

```c
float ao_coshf(float x);
```

```c
long double ao_coshl(long double x);
```

```c
double ao_cotd(double x);
```

```c
float ao_cotf(float x);
```

```c
long double ao_cotl(long double x);
```

```c
double ao_cothd(double x);
```

```c
float ao_cothf(float x);
```

```c
long double ao_cothl(long double x);
```

```c
double ao_cscd(double x);
```

```c
float ao_cscf(float x);
```

```c
long double ao_cscl(long double x);
```

```c
double ao_cschd(double x);
```

```c
float ao_cschf(float x);
```

```c
long double ao_cschl(long double x);
```

```c
double ao_deg2radd(double x);
```

```c
float ao_deg2radf(float x);
```

```c
long double ao_deg2radl(long double x);
```

```c
double ao_expd(double x);
```

```c
float ao_expf(float x);
```

```c
long double ao_expl(long double x);
```

```c
double ao_exp2d(double x);
```

```c
float ao_exp2f(float x);
```

```c
long double ao_exp2l(long double x);
```

```c
double ao_fabsd(double x);
```

```c
float ao_fabsf(float x);
```

```c
long double ao_fabsl(long double x);
```

```c
double ao_floord(double x);
```

```c
float ao_floorf(float x);
```

```c
long double ao_floorl(long double x);
```

```c
double ao_fmodd(double x, double y);
```

```c
float ao_fmodf(float x, float y);
```

```c
long double ao_fmodl(long double x, long double y);
```

```c
double ao_frexpd(double x, int * exp);
```

```c
float ao_frexpf(float x, int * exp);
```

```c
long double ao_frexpl(long double x, int * exp);
```

```c
double ao_frexp10d(double x, int * exp);
```

```c
float ao_frexp10f(float x, int * exp);
```

```c
long double ao_frexp10l(long double x, int * exp);
```

```c
double ao_hypotd(double x, double y);
```

```c
float ao_hypotf(float x, float y);
```

```c
long double ao_hypotl(long double x, long double y);
```

```c
double ao_infd();
```

```c
float ao_inff();
```

```c
long double ao_infl();
```

```c
bool ao_isfinited(double x);
```

```c
bool ao_isfinitef(float x);
```

```c
bool ao_isfinitel(long double x);
```

```c
bool ao_isinfd(double x);
```

```c
bool ao_isinff(float x);
```

```c
bool ao_isinfl(long double x);
```

```c
bool ao_isnand(double x);
```

```c
bool ao_isnanf(float x);
```

```c
bool ao_isnanl(long double x);
```

```c
double ao_ldexpd(double x, int exp);
```

```c
float ao_ldexpf(float x, int exp);
```

```c
long double ao_ldexpl(long double x, int exp);
```

```c
double ao_ldexp10d(double x, int exp);
```

```c
float ao_ldexp10f(float x, int exp);
```

```c
long double ao_ldexp10l(long double x, int exp);
```

```c
double ao_logd(double x);
```

```c
float ao_logf(float x);
```

```c
long double ao_logl(long double x);
```

```c
double ao_log10d(double x);
```

```c
float ao_log10f(float x);
```

```c
long double ao_log10l(long double x);
```

```c
double ao_log2d(double x);
```

```c
float ao_log2f(float x);
```

```c
long double ao_log2l(long double x);
```

```c
double ao_modfd(double x, double * intpart);
```

```c
float ao_modff(float x, float * intpart);
```

```c
long double ao_modfl(long double x, long double * intpart);
```

```c
double ao_nand();
```

```c
float ao_nanf();
```

```c
long double ao_nanl();
```

```c
double ao_powd(double x, double y);
```

```c
float ao_powf(float x, float y);
```

```c
long double ao_powl(long double x, long double y);
```

```c
double ao_rad2degd(double x);
```

```c
float ao_rad2degf(float x);
```

```c
long double ao_rad2degl(long double x);
```

```c
double ao_roundd_away_from_zero(double x);
```

```c
float ao_roundf_away_from_zero(float x);
```

```c
long double ao_roundl_away_from_zero(long double x);
```

```c
double ao_roundd_half_down(double x);
```

```c
float ao_roundf_half_down(float x);
```

```c
long double ao_roundl_half_down(long double x);
```

```c
double ao_roundd_half_to_even(double x);
```

```c
float ao_roundf_half_to_even(float x);
```

```c
long double ao_roundl_half_to_even(long double x);
```

```c
double ao_roundd_half_to_infinity(double x);
```

```c
float ao_roundf_half_to_infinity(float x);
```

```c
long double ao_roundl_half_to_infinity(long double x);
```

```c
double ao_roundd_half_to_odd(double x);
```

```c
float ao_roundf_half_to_odd(float x);
```

```c
long double ao_roundl_half_to_odd(long double x);
```

```c
double ao_roundd_half_to_zero(double x);
```

```c
float ao_roundf_half_to_zero(float x);
```

```c
long double ao_roundl_half_to_zero(long double x);
```

```c
double ao_roundd_half_up(double x);
```

```c
float ao_roundf_half_up(float x);
```

```c
long double ao_roundl_half_up(long double x);
```

```c
double ao_secd(double x);
```

```c
float ao_secf(float x);
```

```c
long double ao_secl(long double x);
```

```c
double ao_sechd(double x);
```

```c
float ao_sechf(float x);
```

```c
long double ao_sechl(long double x);
```

```c
double ao_signd(double x);
```

```c
float ao_signf(float x);
```

```c
long double ao_signl(long double x);
```

```c
double ao_sind(double x);
```

```c
float ao_sinf(float x);
```

```c
long double ao_sinl(long double x);
```

```c
double ao_sinhd(double x);
```

```c
float ao_sinhf(float x);
```

```c
long double ao_sinhl(long double x);
```

```c
double ao_sqrtd(double x);
```

```c
float ao_sqrtf(float x);
```

```c
long double ao_sqrtl(long double x);
```

```c
double ao_tand(double x);
```

```c
float ao_tanf(float x);
```

```c
long double ao_tanl(long double x);
```

```c
double ao_tanhd(double x);
```

```c
float ao_tanhf(float x);
```

```c
long double ao_tanhl(long double x);
```

```c
double ao_truncd(double x);
```

```c
float ao_truncf(float x);
```

```c
long double ao_truncl(long double x);
```

```c
double ao_wrapd(double x, double beginning, double length);
```

```c
float ao_wrapf(float x, float beginning, float length);
```

```c
long double ao_wrapl(long double x, long double beginning, long double length);
```

