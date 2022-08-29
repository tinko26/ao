---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao/ao_floatd.h module of the ao real-time operating system."
draft: true
permalink: /ao/ao_floatd.h/ 
subtitle: ""
title: "ao_floatd.h"
toc: true
---

```c
#include <ao_mathf.h>
#include <float.h>

typedef double                                          ao_float_t;

#ifndef AO_FLOAT_DIG

#define AO_FLOAT_DIG                                    (DBL_DIG)

#endif

#ifndef AO_FLOAT_EPSILON

#define AO_FLOAT_EPSILON                                (DBL_EPSILON)

#endif

#ifndef AO_FLOAT_MAX

#define AO_FLOAT_MAX                                    (DBL_MAX)

#endif

#ifndef AO_FLOAT_MIN

#define AO_FLOAT_MIN                                    (DBL_MIN)

#endif

#ifndef ao_acos

#define ao_acos(x)                                      ao_acosd(x)

#endif

#ifndef ao_acosh

#define ao_acosh(x)                                     ao_acoshd(x)

#endif

#ifndef ao_acot

#define ao_acot(x)                                      ao_acotd(x)

#endif

#ifndef ao_acoth

#define ao_acoth(x)                                     ao_acothd(x)

#endif

#ifndef ao_acsc

#define ao_acsc(x)                                      ao_acscd(x)

#endif

#ifndef ao_acsch

#define ao_acsch(x)                                     ao_acschd(x)

#endif

#ifndef ao_asec

#define ao_asec(x)                                      ao_asecd(x)

#endif

#ifndef ao_asech

#define ao_asech(x)                                     ao_asechd(x)

#endif

#ifndef ao_asin

#define ao_asin(x)                                      ao_asind(x)

#endif

#ifndef ao_asinh

#define ao_asinh(x)                                     ao_asinhd(x)

#endif

#ifndef ao_atan

#define ao_atan(x)                                      ao_atand(x)

#endif

#ifndef ao_atan2

#define ao_atan2(y, x)                                  ao_atan2d(y, x)

#endif

#ifndef ao_atanh

#define ao_atanh(x)                                     ao_atanhd(x)

#endif

#ifndef ao_cbrt

#define ao_cbrt(x)                                      ao_cbrtd(x)

#endif

#ifndef ao_ceil

#define ao_ceil(x)                                      ao_ceild(x)

#endif

#ifndef ao_cos

#define ao_cos(x)                                       ao_cosd(x)

#endif

#ifndef ao_cosh

#define ao_cosh(x)                                      ao_coshd(x)

#endif

#ifndef ao_cot

#define ao_cot(x)                                       ao_cotd(x)

#endif

#ifndef ao_coth

#define ao_coth(x)                                      ao_cothd(x)

#endif

#ifndef ao_csc

#define ao_csc(x)                                       ao_cscd(x)

#endif

#ifndef ao_csch

#define ao_csch(x)                                      ao_cschd(x)

#endif

#ifndef ao_deg2rad

#define ao_deg2rad(x)                                   ao_deg2radd(x)

#endif

#ifndef ao_exp

#define ao_exp(x)                                       ao_expd(x)

#endif

#ifndef ao_exp2

#define ao_exp2(x)                                      ao_exp2d(x)

#endif

#ifndef ao_fabs

#define ao_fabs(x)                                      ao_fabsd(x)

#endif

#ifndef ao_floor

#define ao_floor(x)                                     ao_floord(x)

#endif

#ifndef ao_fmod

#define ao_fmod(x, y)                                   ao_fmodd(x, y)

#endif

#ifndef ao_frexp

#define ao_frexp(x, exp)                                ao_frexpd(x, exp)

#endif

#ifndef ao_frexp10

#define ao_frexp10(x, exp)                              ao_frexp10d(x, exp)

#endif

#ifndef ao_hypot

#define ao_hypot(x, y)                                  ao_hypotd(x, y)

#endif

#ifndef ao_inf

#define ao_inf()                                        ao_infd()

#endif

#ifndef ao_isfinite

#define ao_isfinite(x)                                  ao_isfinited(x)

#endif

#ifndef ao_isinf

#define ao_isinf(x)                                     ao_isinfd(x)

#endif

#ifndef ao_isnan

#define ao_isnan(x)                                     ao_isnand(x)

#endif

#ifndef ao_ldexp

#define ao_ldexp(x, exp)                                ao_ldexpd(x, exp)

#endif

#ifndef ao_ldexp10

#define ao_ldexp10(x, exp)                              ao_ldexp10d(x, exp)

#endif

#ifndef ao_log

#define ao_log(x)                                       ao_logd(x)

#endif

#ifndef ao_log10

#define ao_log10(x)                                     ao_log10d(x)

#endif

#ifndef ao_log2

#define ao_log2(x)                                      ao_log2d(x)

#endif

#ifndef ao_modf

#define ao_modf(x, intpart)                             ao_modfd(x, intpart)

#endif

#ifndef ao_nan

#define ao_nan()                                        ao_nand()

#endif

#ifndef ao_pow

#define ao_pow(x, y)                                    ao_powd(x, y)

#endif

#ifndef ao_rad2deg

#define ao_rad2deg(x)                                   ao_rad2degd(x)

#endif

#ifndef ao_round

#define ao_round(x)                                     ao_roundd(x)

#endif

#ifndef ao_round_away_from_infinity

#define ao_round_away_from_infinity(x)                  ao_roundd_away_from_infinity(x)

#endif

#ifndef ao_round_away_from_negative_infinity

#define ao_round_away_from_negative_infinity(x)         ao_roundd_away_from_negative_infinity(x)

#endif

#ifndef ao_round_away_from_positive_infinity

#define ao_round_away_from_positive_infinity(x)         ao_roundd_away_from_positive_infinity(x)

#endif

#ifndef ao_round_away_from_zero

#define ao_round_away_from_zero(x)                      ao_roundd_away_from_zero(x)

#endif

#ifndef ao_round_down

#define ao_round_down(x)                                ao_roundd_down(x)

#endif

#ifndef ao_round_half_away_from_infinity

#define ao_round_half_away_from_infinity(x)             ao_roundd_half_away_from_infinity(x)

#endif

#ifndef ao_round_half_away_from_negative_infinity

#define ao_round_half_away_from_negative_infinity(x)    ao_roundd_half_away_from_negative_infinity(x)

#endif

#ifndef ao_round_half_away_from_positive_infinity

#define ao_round_half_away_from_positive_infinity(x)    ao_roundd_half_away_from_positive_infinity(x)

#endif

#ifndef ao_round_half_away_from_zero

#define ao_round_half_away_from_zero(x)                 ao_roundd_half_away_from_zero(x)

#endif

#ifndef ao_round_half_down

#define ao_round_half_down(x)                           ao_roundd_half_down(x)

#endif

#ifndef ao_round_half_to_even

#define ao_round_half_to_even(x)                        ao_roundd_half_to_even(x)

#endif

#ifndef ao_round_half_to_infinity

#define ao_round_half_to_infinity(x)                    ao_roundd_half_to_infinity(x)

#endif

#ifndef ao_round_half_to_negative_infinity

#define ao_round_half_to_negative_infinity(x)           ao_roundd_half_to_negative_infinity(x)

#endif

#ifndef ao_round_half_to_odd

#define ao_round_half_to_odd(x)                         ao_roundd_half_to_odd(x)

#endif

#ifndef ao_round_half_to_positive_infinity

#define ao_round_half_to_positive_infinity(x)           ao_roundd_half_to_positive_infinity(x)

#endif

#ifndef ao_round_half_to_zero

#define ao_round_half_to_zero(x)                        ao_roundd_half_to_zero(x)

#endif

#ifndef ao_round_half_up

#define ao_round_half_up(x)                             ao_roundd_half_up(x)

#endif

#ifndef ao_round_to_infinity

#define ao_round_to_infinity(x)                         ao_roundd_to_infinity(x)

#endif

#ifndef ao_round_to_negative_infinity

#define ao_round_to_negative_infinity(x)                ao_roundd_to_negative_infinity(x)

#endif

#ifndef ao_round_to_positive_infinity

#define ao_round_to_positive_infinity(x)                ao_roundd_to_positive_infinity(x)

#endif

#ifndef ao_round_to_zero

#define ao_round_to_zero(x)                             ao_roundd_to_zero(x)

#endif

#ifndef ao_round_up

#define ao_round_up(x)                                  ao_roundd_up(x)

#endif

#ifndef ao_sec

#define ao_sec(x)                                       ao_secd(x)

#endif

#ifndef ao_sech

#define ao_sech(x)                                      ao_sechd(x)

#endif

#ifndef ao_sign

#define ao_sign(x)                                      ao_signd(x)

#endif

#ifndef ao_sin

#define ao_sin(x)                                       ao_sind(x)

#endif

#ifndef ao_sinh

#define ao_sinh(x)                                      ao_sinhd(x)

#endif

#ifndef ao_sqrt

#define ao_sqrt(x)                                      ao_sqrtd(x)

#endif

#ifndef ao_tan

#define ao_tan(x)                                       ao_tand(x)

#endif

#ifndef ao_tanh

#define ao_tanh(x)                                      ao_tanhd(x)

#endif

#ifndef ao_trunc

#define ao_trunc(x)                                     ao_truncd(x)

#endif

#ifndef ao_wrap

#define ao_wrap(x, beginning, length)                   ao_wrapd(x, beginning, length)

#endif

```
