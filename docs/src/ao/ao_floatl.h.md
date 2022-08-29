---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao/ao_floatl.h file of the ao real-time operating system."
draft: true
permalink: /src/ao/ao_floatl.h/ 
subtitle: ""
title: "ao_floatl.h"
toc: true
---

# Overview

...

# Includes

```c
#include <ao_mathf.h>
#include <float.h>

typedef long double                                     ao_float_t;

#ifndef AO_FLOAT_DIG

#define AO_FLOAT_DIG                                    (LDBL_DIG)

#endif

#ifndef AO_FLOAT_EPSILON

#define AO_FLOAT_EPSILON                                (LDBL_EPSILON)

#endif

#ifndef AO_FLOAT_MAX

#define AO_FLOAT_MAX                                    (LDBL_MAX)

#endif

#ifndef AO_FLOAT_MIN

#define AO_FLOAT_MIN                                    (LDBL_MIN)

#endif

#ifndef ao_acos

#define ao_acos(x)                                      ao_acosl(x)

#endif

#ifndef ao_acosh

#define ao_acosh(x)                                     ao_acoshl(x)

#endif

#ifndef ao_acot

#define ao_acot(x)                                      ao_acotl(x)

#endif

#ifndef ao_acoth

#define ao_acoth(x)                                     ao_acothl(x)

#endif

#ifndef ao_acsc

#define ao_acsc(x)                                      ao_acscl(x)

#endif

#ifndef ao_acsch

#define ao_acsch(x)                                     ao_acschl(x)

#endif

#ifndef ao_asec

#define ao_asec(x)                                      ao_asecl(x)

#endif

#ifndef ao_asech

#define ao_asech(x)                                     ao_asechl(x)

#endif

#ifndef ao_asin

#define ao_asin(x)                                      ao_asinl(x)

#endif

#ifndef ao_asinh

#define ao_asinh(x)                                     ao_asinhl(x)

#endif

#ifndef ao_atan

#define ao_atan(x)                                      ao_atanl(x)

#endif

#ifndef ao_atan2

#define ao_atan2(y, x)                                  ao_atan2l(y, x)

#endif

#ifndef ao_atanh

#define ao_atanh(x)                                     ao_atanhl(x)

#endif

#ifndef ao_cbrt

#define ao_cbrt(x)                                      ao_cbrtl(x)

#endif

#ifndef ao_ceil

#define ao_ceil(x)                                      ao_ceill(x)

#endif

#ifndef ao_cos

#define ao_cos(x)                                       ao_cosl(x)

#endif

#ifndef ao_cosh

#define ao_cosh(x)                                      ao_coshl(x)

#endif

#ifndef ao_cot

#define ao_cot(x)                                       ao_cotl(x)

#endif

#ifndef ao_coth

#define ao_coth(x)                                      ao_cothl(x)

#endif

#ifndef ao_csc

#define ao_csc(x)                                       ao_cscl(x)

#endif

#ifndef ao_csch

#define ao_csch(x)                                      ao_cschl(x)

#endif

#ifndef ao_deg2rad

#define ao_deg2rad(x)                                   ao_deg2radl(x)

#endif

#ifndef ao_exp

#define ao_exp(x)                                       ao_expl(x)

#endif

#ifndef ao_exp2

#define ao_exp2(x)                                      ao_exp2l(x)

#endif

#ifndef ao_fabs

#define ao_fabs(x)                                      ao_fabsl(x)

#endif

#ifndef ao_floor

#define ao_floor(x)                                     ao_floorl(x)

#endif

#ifndef ao_fmod

#define ao_fmod(x, y)                                   ao_fmodl(x, y)

#endif

#ifndef ao_frexp

#define ao_frexp(x, exp)                                ao_frexpl(x, exp)

#endif

#ifndef ao_frexp10

#define ao_frexp10(x, exp)                              ao_frexp10l(x, exp)

#endif

#ifndef ao_hypot

#define ao_hypot(x, y)                                  ao_hypotl(x, y)

#endif

#ifndef ao_inf

#define ao_inf()                                        ao_infl()

#endif

#ifndef ao_isfinite

#define ao_isfinite(x)                                  ao_isfinitel(x)

#endif

#ifndef ao_isinf

#define ao_isinf(x)                                     ao_isinfl(x)

#endif

#ifndef ao_isnan

#define ao_isnan(x)                                     ao_isnanl(x)

#endif

#ifndef ao_ldexp

#define ao_ldexp(x, exp)                                ao_ldexpl(x, exp)

#endif

#ifndef ao_ldexp10

#define ao_ldexp10(x, exp)                              ao_ldexp10l(x, exp)

#endif

#ifndef ao_log

#define ao_log(x)                                       ao_logl(x)

#endif

#ifndef ao_log10

#define ao_log10(x)                                     ao_log10l(x)

#endif

#ifndef ao_log2

#define ao_log2(x)                                      ao_log2l(x)

#endif

#ifndef ao_modf

#define ao_modf(x, intpart)                             ao_modfl(x, intpart)

#endif

#ifndef ao_nan

#define ao_nan()                                        ao_nanl()

#endif

#ifndef ao_pow

#define ao_pow(x, y)                                    ao_powl(x, y)

#endif

#ifndef ao_rad2deg

#define ao_rad2deg(x)                                   ao_rad2degl(x)

#endif

#ifndef ao_round

#define ao_round(x)                                     ao_roundl(x)

#endif

#ifndef ao_round_away_from_infinity

#define ao_round_away_from_infinity(x)                  ao_roundl_away_from_infinity(x)

#endif

#ifndef ao_round_away_from_negative_infinity

#define ao_round_away_from_negative_infinity(x)         ao_roundl_away_from_negative_infinity(x)

#endif

#ifndef ao_round_away_from_positive_infinity

#define ao_round_away_from_positive_infinity(x)         ao_roundl_away_from_positive_infinity(x)

#endif

#ifndef ao_round_away_from_zero

#define ao_round_away_from_zero(x)                      ao_roundl_away_from_zero(x)

#endif

#ifndef ao_round_down

#define ao_round_down(x)                                ao_roundl_down(x)

#endif

#ifndef ao_round_half_away_from_infinity

#define ao_round_half_away_from_infinity(x)             ao_roundl_half_away_from_infinity(x)

#endif

#ifndef ao_round_half_away_from_negative_infinity

#define ao_round_half_away_from_negative_infinity(x)    ao_roundl_half_away_from_negative_infinity(x)

#endif

#ifndef ao_round_half_away_from_positive_infinity

#define ao_round_half_away_from_positive_infinity(x)    ao_roundl_half_away_from_positive_infinity(x)

#endif

#ifndef ao_round_half_away_from_zero

#define ao_round_half_away_from_zero(x)                 ao_roundl_half_away_from_zero(x)

#endif

#ifndef ao_round_half_down

#define ao_round_half_down(x)                           ao_roundl_half_down(x)

#endif

#ifndef ao_round_half_to_even

#define ao_round_half_to_even(x)                        ao_roundl_half_to_even(x)

#endif

#ifndef ao_round_half_to_infinity

#define ao_round_half_to_infinity(x)                    ao_roundl_half_to_infinity(x)

#endif

#ifndef ao_round_half_to_negative_infinity

#define ao_round_half_to_negative_infinity(x)           ao_roundl_half_to_negative_infinity(x)

#endif

#ifndef ao_round_half_to_odd

#define ao_round_half_to_odd(x)                         ao_roundl_half_to_odd(x)

#endif

#ifndef ao_round_half_to_positive_infinity

#define ao_round_half_to_positive_infinity(x)           ao_roundl_half_to_positive_infinity(x)

#endif

#ifndef ao_round_half_to_zero

#define ao_round_half_to_zero(x)                        ao_roundl_half_to_zero(x)

#endif

#ifndef ao_round_half_up

#define ao_round_half_up(x)                             ao_roundl_half_up(x)

#endif

#ifndef ao_round_to_infinity

#define ao_round_to_infinity(x)                         ao_roundl_to_infinity(x)

#endif

#ifndef ao_round_to_negative_infinity

#define ao_round_to_negative_infinity(x)                ao_roundl_to_negative_infinity(x)

#endif

#ifndef ao_round_to_positive_infinity

#define ao_round_to_positive_infinity(x)                ao_roundl_to_positive_infinity(x)

#endif

#ifndef ao_round_to_zero

#define ao_round_to_zero(x)                             ao_roundl_to_zero(x)

#endif

#ifndef ao_round_up

#define ao_round_up(x)                                  ao_roundl_up(x)

#endif

#ifndef ao_sec

#define ao_sec(x)                                       ao_secl(x)

#endif

#ifndef ao_sech

#define ao_sech(x)                                      ao_sechl(x)

#endif

#ifndef ao_sign

#define ao_sign(x)                                      ao_signl(x)

#endif

#ifndef ao_sin

#define ao_sin(x)                                       ao_sinl(x)

#endif

#ifndef ao_sinh

#define ao_sinh(x)                                      ao_sinhl(x)

#endif

#ifndef ao_sqrt

#define ao_sqrt(x)                                      ao_sqrtl(x)

#endif

#ifndef ao_tan

#define ao_tan(x)                                       ao_tanl(x)

#endif

#ifndef ao_tanh

#define ao_tanh(x)                                      ao_tanhl(x)

#endif

#ifndef ao_trunc

#define ao_trunc(x)                                     ao_truncl(x)

#endif

#ifndef ao_wrap

#define ao_wrap(x, beginning, length)                   ao_wrapl(x, beginning, length)

#endif

```
