---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao/ao_floatf.h module of the ao real-time operating system."
draft: true
permalink: /ao/ao_floatf.h/ 
subtitle: ""
title: "ao_floatf.h"
toc: true
---

```c
#include <ao_mathf.h>
#include <float.h>

typedef float                                           ao_float_t;

#ifndef AO_FLOAT_DIG

#define AO_FLOAT_DIG                                    (FLT_DIG)

#endif

#ifndef AO_FLOAT_EPSILON

#define AO_FLOAT_EPSILON                                (FLT_EPSILON)

#endif

#ifndef AO_FLOAT_MAX

#define AO_FLOAT_MAX                                    (FLT_MAX)

#endif

#ifndef AO_FLOAT_MIN

#define AO_FLOAT_MIN                                    (FLT_MIN)

#endif

#ifndef ao_acos

#define ao_acos(x)                                      ao_acosf(x)

#endif

#ifndef ao_acosh

#define ao_acosh(x)                                     ao_acoshf(x)

#endif

#ifndef ao_acot

#define ao_acot(x)                                      ao_acotf(x)

#endif

#ifndef ao_acoth

#define ao_acoth(x)                                     ao_acothf(x)

#endif

#ifndef ao_acsc

#define ao_acsc(x)                                      ao_acscf(x)

#endif

#ifndef ao_acsch

#define ao_acsch(x)                                     ao_acschf(x)

#endif

#ifndef ao_asec

#define ao_asec(x)                                      ao_asecf(x)

#endif

#ifndef ao_asech

#define ao_asech(x)                                     ao_asechf(x)

#endif

#ifndef ao_asin

#define ao_asin(x)                                      ao_asinf(x)

#endif

#ifndef ao_asinh

#define ao_asinh(x)                                     ao_asinhf(x)

#endif

#ifndef ao_atan

#define ao_atan(x)                                      ao_atanf(x)

#endif

#ifndef ao_atan2

#define ao_atan2(y, x)                                  ao_atan2f(y, x)

#endif

#ifndef ao_atanh

#define ao_atanh(x)                                     ao_atanhf(x)

#endif

#ifndef ao_cbrt

#define ao_cbrt(x)                                      ao_cbrtf(x)

#endif

#ifndef ao_ceil

#define ao_ceil(x)                                      ao_ceilf(x)

#endif

#ifndef ao_cos

#define ao_cos(x)                                       ao_cosf(x)

#endif

#ifndef ao_cosh

#define ao_cosh(x)                                      ao_coshf(x)

#endif

#ifndef ao_cot

#define ao_cot(x)                                       ao_cotf(x)

#endif

#ifndef ao_coth

#define ao_coth(x)                                      ao_cothf(x)

#endif

#ifndef ao_csc

#define ao_csc(x)                                       ao_cscf(x)

#endif

#ifndef ao_csch

#define ao_csch(x)                                      ao_cschf(x)

#endif

#ifndef ao_deg2rad

#define ao_deg2rad(x)                                   ao_deg2radf(x)

#endif

#ifndef ao_exp

#define ao_exp(x)                                       ao_expf(x)

#endif

#ifndef ao_exp2

#define ao_exp2(x)                                      ao_exp2f(x)

#endif

#ifndef ao_fabs

#define ao_fabs(x)                                      ao_fabsf(x)

#endif

#ifndef ao_floor

#define ao_floor(x)                                     ao_floorf(x)

#endif

#ifndef ao_fmod

#define ao_fmod(x, y)                                   ao_fmodf(x, y)

#endif

#ifndef ao_frexp

#define ao_frexp(x, exp)                                ao_frexpf(x, exp)

#endif

#ifndef ao_frexp10

#define ao_frexp10(x, exp)                              ao_frexp10f(x, exp)

#endif

#ifndef ao_hypot

#define ao_hypot(x, y)                                  ao_hypotf(x, y)

#endif

#ifndef ao_inf

#define ao_inf()                                        ao_inff()

#endif

#ifndef ao_isfinite

#define ao_isfinite(x)                                  ao_isfinitef(x)

#endif

#ifndef ao_isinf

#define ao_isinf(x)                                     ao_isinff(x)

#endif

#ifndef ao_isnan

#define ao_isnan(x)                                     ao_isnanf(x)

#endif

#ifndef ao_ldexp

#define ao_ldexp(x, exp)                                ao_ldexpf(x, exp)

#endif

#ifndef ao_ldexp10

#define ao_ldexp10(x, exp)                              ao_ldexp10f(x, exp)

#endif

#ifndef ao_log

#define ao_log(x)                                       ao_logf(x)

#endif

#ifndef ao_log10

#define ao_log10(x)                                     ao_log10f(x)

#endif

#ifndef ao_log2

#define ao_log2(x)                                      ao_log2f(x)

#endif

#ifndef ao_modf

#define ao_modf(x, intpart)                             ao_modff(x, intpart)

#endif

#ifndef ao_nan

#define ao_nan()                                        ao_nanf()

#endif

#ifndef ao_pow

#define ao_pow(x, y)                                    ao_powf(x, y)

#endif

#ifndef ao_rad2deg

#define ao_rad2deg(x)                                   ao_rad2degf(x)

#endif

#ifndef ao_round

#define ao_round(x)                                     ao_roundf(x)

#endif

#ifndef ao_round_away_from_infinity

#define ao_round_away_from_infinity(x)                  ao_roundf_away_from_infinity(x)

#endif

#ifndef ao_round_away_from_negative_infinity

#define ao_round_away_from_negative_infinity(x)         ao_roundf_away_from_negative_infinity(x)

#endif

#ifndef ao_round_away_from_positive_infinity

#define ao_round_away_from_positive_infinity(x)         ao_roundf_away_from_positive_infinity(x)

#endif

#ifndef ao_round_away_from_zero

#define ao_round_away_from_zero(x)                      ao_roundf_away_from_zero(x)

#endif

#ifndef ao_round_down

#define ao_round_down(x)                                ao_roundf_down(x)

#endif

#ifndef ao_round_half_away_from_infinity

#define ao_round_half_away_from_infinity(x)             ao_roundf_half_away_from_infinity(x)

#endif

#ifndef ao_round_half_away_from_negative_infinity

#define ao_round_half_away_from_negative_infinity(x)    ao_roundf_half_away_from_negative_infinity(x)

#endif

#ifndef ao_round_half_away_from_positive_infinity

#define ao_round_half_away_from_positive_infinity(x)    ao_roundf_half_away_from_positive_infinity(x)

#endif

#ifndef ao_round_half_away_from_zero

#define ao_round_half_away_from_zero(x)                 ao_roundf_half_away_from_zero(x)

#endif

#ifndef ao_round_half_down

#define ao_round_half_down(x)                           ao_roundf_half_down(x)

#endif

#ifndef ao_round_half_to_even

#define ao_round_half_to_even(x)                        ao_roundf_half_to_even(x)

#endif

#ifndef ao_round_half_to_infinity

#define ao_round_half_to_infinity(x)                    ao_roundf_half_to_infinity(x)

#endif

#ifndef ao_round_half_to_negative_infinity

#define ao_round_half_to_negative_infinity(x)           ao_roundf_half_to_negative_infinity(x)

#endif

#ifndef ao_round_half_to_odd

#define ao_round_half_to_odd(x)                         ao_roundf_half_to_odd(x)

#endif

#ifndef ao_round_half_to_positive_infinity

#define ao_round_half_to_positive_infinity(x)           ao_roundf_half_to_positive_infinity(x)

#endif

#ifndef ao_round_half_to_zero

#define ao_round_half_to_zero(x)                        ao_roundf_half_to_zero(x)

#endif

#ifndef ao_round_half_up

#define ao_round_half_up(x)                             ao_roundf_half_up(x)

#endif

#ifndef ao_round_to_infinity

#define ao_round_to_infinity(x)                         ao_roundf_to_infinity(x)

#endif

#ifndef ao_round_to_negative_infinity

#define ao_round_to_negative_infinity(x)                ao_roundf_to_negative_infinity(x)

#endif

#ifndef ao_round_to_positive_infinity

#define ao_round_to_positive_infinity(x)                ao_roundf_to_positive_infinity(x)

#endif

#ifndef ao_round_to_zero

#define ao_round_to_zero(x)                             ao_roundf_to_zero(x)

#endif

#ifndef ao_round_up

#define ao_round_up(x)                                  ao_roundf_up(x)

#endif

#ifndef ao_sec

#define ao_sec(x)                                       ao_secf(x)

#endif

#ifndef ao_sech

#define ao_sech(x)                                      ao_sechf(x)

#endif

#ifndef ao_sign

#define ao_sign(x)                                      ao_signf(x)

#endif

#ifndef ao_sin

#define ao_sin(x)                                       ao_sinf(x)

#endif

#ifndef ao_sinh

#define ao_sinh(x)                                      ao_sinhf(x)

#endif

#ifndef ao_sqrt

#define ao_sqrt(x)                                      ao_sqrtf(x)

#endif

#ifndef ao_tan

#define ao_tan(x)                                       ao_tanf(x)

#endif

#ifndef ao_tanh

#define ao_tanh(x)                                      ao_tanhf(x)

#endif

#ifndef ao_trunc

#define ao_trunc(x)                                     ao_truncf(x)

#endif

#ifndef ao_wrap

#define ao_wrap(x, beginning, length)                   ao_wrapf(x, beginning, length)

#endif

```
