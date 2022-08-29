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

# Overview

...

# Includes

```c
#include <stdbool.h>

#ifndef     AO_MATHF

#define     AO_MATHF

#endif

#ifndef     AO_1_PI

#define     AO_1_PI                                         ( 0.31830988618379067153776752674502872406891929148091)

#endif

#ifndef     AO_2_PI

#define     AO_2_PI                                         ( 0.63661977236758134307553505349005744813783858296183)

#endif

#ifndef     AO_2_SQRTPI

#define     AO_2_SQRTPI                                     ( 1.12837916709551257389615890312154517168810125865800)

#endif

#ifndef     AO_DEGREES_PER_RADIAN

#define     AO_DEGREES_PER_RADIAN                           (57.29577951308232087679815481410517033240547246656432)

#endif

#ifndef     AO_E

#define     AO_E                                            ( 2.71828182845904523536028747135266249775724709369996)

#endif

#ifndef     AO_LN10

#define     AO_LN10                                         ( 2.30258509299404568401799145468436420760110148862877)

#endif

#ifndef     AO_LN2

#define     AO_LN2                                          ( 0.69314718055994530941723212145817656807550013436026)

#endif

#ifndef     AO_LOG10E

#define     AO_LOG10E                                       ( 0.43429448190325182765112891891660508229439700580367)

#endif

#ifndef     AO_LOG2E

#define     AO_LOG2E                                        ( 1.44269504088896340735992468100189213742664595415299)

#endif

#ifndef     AO_PI

#define     AO_PI                                           ( 3.14159265358979323846264338327950288419716939937511)

#endif

#ifndef     AO_PI_2

#define     AO_PI_2                                         ( 1.57079632679489661923132169163975144209858469968755)

#endif

#ifndef     AO_PI_4

#define     AO_PI_4                                         ( 0.78539816339744830961566084581987572104929234984378)

#endif

#ifndef     AO_RADIANS_PER_DEGREE

#define     AO_RADIANS_PER_DEGREE                           ( 0.01745329251994329576923690768488612713442871888542)

#endif

#ifndef     AO_SQRT1_2

#define     AO_SQRT1_2                                      ( 0.70710678118654752440084436210484903928483593768847)

#endif

#ifndef     AO_SQRT2

#define     AO_SQRT2                                        ( 1.41421356237309504880168872420969807856967187537695)

#endif

#ifndef     ao_acosd

double      ao_acosd(double x);

#endif

#ifndef     ao_acosf

float       ao_acosf(float x);

#endif

#ifndef     ao_acosl

long double ao_acosl(long double x);

#endif

#ifndef     ao_acoshd

double      ao_acoshd(double x);

#endif

#ifndef     ao_acoshf

float       ao_acoshf(float x);

#endif

#ifndef     ao_acoshl

long double ao_acoshl(long double x);

#endif

#ifndef     ao_acotd

double      ao_acotd(double x);

#endif

#ifndef     ao_acotf

float       ao_acotf(float x);

#endif

#ifndef     ao_acotl

long double ao_acotl(long double x);

#endif

#ifndef     ao_acothd

double      ao_acothd(double x);

#endif

#ifndef     ao_acothf

float       ao_acothf(float x);

#endif

#ifndef     ao_acothl

long double ao_acothl(long double x);

#endif

#ifndef     ao_acscd

double      ao_acscd(double x);

#endif

#ifndef     ao_acscf

float       ao_acscf(float x);

#endif

#ifndef     ao_acscl

long double ao_acscl(long double x);

#endif

#ifndef     ao_acschd

double      ao_acschd(double x);

#endif

#ifndef     ao_acschf

float       ao_acschf(float x);

#endif

#ifndef     ao_acschl

long double ao_acschl(long double x);

#endif

#ifndef     ao_asecd

double      ao_asecd(double x);

#endif

#ifndef     ao_asecf

float       ao_asecf(float x);

#endif

#ifndef     ao_asecl

long double ao_asecl(long double x);

#endif

#ifndef     ao_asechd

double      ao_asechd(double x);

#endif

#ifndef     ao_asechf

float       ao_asechf(float x);

#endif

#ifndef     ao_asechl

long double ao_asechl(long double x);

#endif

#ifndef     ao_asind

double      ao_asind(double x);

#endif

#ifndef     ao_asinf

float       ao_asinf(float x);

#endif

#ifndef     ao_asinl

long double ao_asinl(long double x);

#endif

#ifndef     ao_asinhd

double      ao_asinhd(double x);

#endif

#ifndef     ao_asinhf

float       ao_asinhf(float x);

#endif

#ifndef     ao_asinhl

long double ao_asinhl(long double x);

#endif

#ifndef     ao_atand

double      ao_atand(double x);

#endif

#ifndef     ao_atanf

float       ao_atanf(float x);

#endif

#ifndef     ao_atanl

long double ao_atanl(long double x);

#endif

#ifndef     ao_atan2d

double      ao_atan2d(double y, double x);

#endif

#ifndef     ao_atan2f

float       ao_atan2f(float y, float x);

#endif

#ifndef     ao_atan2l

long double ao_atan2l(long double y, long double x);

#endif

#ifndef     ao_atanhd

double      ao_atanhd(double x);

#endif

#ifndef     ao_atanhf

float       ao_atanhf(float x);

#endif

#ifndef     ao_atanhl

long double ao_atanhl(long double x);

#endif

#ifndef     ao_cbrtd

double      ao_cbrtd(double x);

#endif

#ifndef     ao_cbrtf

float       ao_cbrtf(float x);

#endif

#ifndef     ao_cbrtl

long double ao_cbrtl(long double x);

#endif

#ifndef     ao_ceild

double      ao_ceild(double x);

#endif

#ifndef     ao_ceilf

float       ao_ceilf(float x);

#endif

#ifndef     ao_ceill

long double ao_ceill(long double x);

#endif

#ifndef     ao_cosd

double      ao_cosd(double x);

#endif

#ifndef     ao_cosf

float       ao_cosf(float x);

#endif

#ifndef     ao_cosl

long double ao_cosl(long double x);

#endif

#ifndef     ao_coshd

double      ao_coshd(double x);

#endif

#ifndef     ao_coshf

float       ao_coshf(float x);

#endif

#ifndef     ao_coshl

long double ao_coshl(long double x);

#endif

#ifndef     ao_cotd

double      ao_cotd(double x);

#endif

#ifndef     ao_cotf

float       ao_cotf(float x);

#endif

#ifndef     ao_cotl

long double ao_cotl(long double x);

#endif

#ifndef     ao_cothd

double      ao_cothd(double x);

#endif

#ifndef     ao_cothf

float       ao_cothf(float x);

#endif

#ifndef     ao_cothl

long double ao_cothl(long double x);

#endif

#ifndef     ao_cscd

double      ao_cscd(double x);

#endif

#ifndef     ao_cscf

float       ao_cscf(float x);

#endif

#ifndef     ao_cscl

long double ao_cscl(long double x);

#endif

#ifndef     ao_cschd

double      ao_cschd(double x);

#endif

#ifndef     ao_cschf

float       ao_cschf(float x);

#endif

#ifndef     ao_cschl

long double ao_cschl(long double x);

#endif

#ifndef     ao_deg2radd

double      ao_deg2radd(double x);

#endif

#ifndef     ao_deg2radf

float       ao_deg2radf(float x);

#endif

#ifndef     ao_deg2radl

long double ao_deg2radl(long double x);

#endif

#ifndef     ao_expd

double      ao_expd(double x);

#endif

#ifndef     ao_expf

float       ao_expf(float x);

#endif

#ifndef     ao_expl

long double ao_expl(long double x);

#endif

#ifndef     ao_exp2d

double      ao_exp2d(double x);

#endif

#ifndef     ao_exp2f

float       ao_exp2f(float x);

#endif

#ifndef     ao_exp2l

long double ao_exp2l(long double x);

#endif

#ifndef     ao_fabsd

double      ao_fabsd(double x);

#endif

#ifndef     ao_fabsf

float       ao_fabsf(float x);

#endif

#ifndef     ao_fabsl

long double ao_fabsl(long double x);

#endif

#ifndef     ao_floord

double      ao_floord(double x);

#endif

#ifndef     ao_floorf

float       ao_floorf(float x);

#endif

#ifndef     ao_floorl

long double ao_floorl(long double x);

#endif

#ifndef     ao_fmodd

double      ao_fmodd(double x, double y);

#endif

#ifndef     ao_fmodf

float       ao_fmodf(float x, float y);

#endif

#ifndef     ao_fmodl

long double ao_fmodl(long double x, long double y);

#endif

#ifndef     ao_frexpd

double      ao_frexpd(double x, int * exp);

#endif

#ifndef     ao_frexpf

float       ao_frexpf(float x, int * exp);

#endif

#ifndef     ao_frexpl

long double ao_frexpl(long double x, int * exp);

#endif

#ifndef     ao_frexp10d

double      ao_frexp10d(double x, int * exp);

#endif

#ifndef     ao_frexp10f

float       ao_frexp10f(float x, int * exp);

#endif

#ifndef     ao_frexp10l

long double ao_frexp10l(long double x, int * exp);

#endif

#ifndef     ao_hypotd

double      ao_hypotd(double x, double y);

#endif

#ifndef     ao_hypotf

float       ao_hypotf(float x, float y);

#endif

#ifndef     ao_hypotl

long double ao_hypotl(long double x, long double y);

#endif

#ifndef     ao_infd

double      ao_infd();

#endif

#ifndef     ao_inff

float       ao_inff();

#endif

#ifndef     ao_infl

long double ao_infl();

#endif

#ifndef     ao_isfinited

bool        ao_isfinited(double x);

#endif

#ifndef     ao_isfinitef

bool        ao_isfinitef(float x);

#endif

#ifndef     ao_isfinitel

bool        ao_isfinitel(long double x);

#endif

#ifndef     ao_isinfd

bool        ao_isinfd(double x);

#endif

#ifndef     ao_isinff

bool        ao_isinff(float x);

#endif

#ifndef     ao_isinfl

bool        ao_isinfl(long double x);

#endif

#ifndef     ao_isnand

bool        ao_isnand(double x);

#endif

#ifndef     ao_isnanf

bool        ao_isnanf(float x);

#endif

#ifndef     ao_isnanl

bool        ao_isnanl(long double x);

#endif

#ifndef     ao_ldexpd

double      ao_ldexpd(double x, int exp);

#endif

#ifndef     ao_ldexpf

float       ao_ldexpf(float x, int exp);

#endif

#ifndef     ao_ldexpl

long double ao_ldexpl(long double x, int exp);

#endif

#ifndef     ao_ldexp10d

double      ao_ldexp10d(double x, int exp);

#endif

#ifndef     ao_ldexp10f

float       ao_ldexp10f(float x, int exp);

#endif

#ifndef     ao_ldexp10l

long double ao_ldexp10l(long double x, int exp);

#endif

#ifndef     ao_logd

double      ao_logd(double x);

#endif

#ifndef     ao_logf

float       ao_logf(float x);

#endif

#ifndef     ao_logl

long double ao_logl(long double x);

#endif

#ifndef     ao_log10d

double      ao_log10d(double x);

#endif

#ifndef     ao_log10f

float       ao_log10f(float x);

#endif

#ifndef     ao_log10l

long double ao_log10l(long double x);

#endif

#ifndef     ao_log2d

double      ao_log2d(double x);

#endif

#ifndef     ao_log2f

float       ao_log2f(float x);

#endif

#ifndef     ao_log2l

long double ao_log2l(long double x);

#endif

#ifndef     ao_modfd

double      ao_modfd(double x, double * intpart);

#endif

#ifndef     ao_modff

float       ao_modff(float x, float * intpart);

#endif

#ifndef     ao_modfl

long double ao_modfl(long double x, long double * intpart);

#endif

#ifndef     ao_nand

double      ao_nand();

#endif

#ifndef     ao_nanf

float       ao_nanf();

#endif

#ifndef     ao_nanl

long double ao_nanl();

#endif

#ifndef     ao_powd

double      ao_powd(double x, double y);

#endif

#ifndef     ao_powf

float       ao_powf(float x, float y);

#endif

#ifndef     ao_powl

long double ao_powl(long double x, long double y);

#endif

#ifndef     ao_rad2degd

double      ao_rad2degd(double x);

#endif

#ifndef     ao_rad2degf

float       ao_rad2degf(float x);

#endif

#ifndef     ao_rad2degl

long double ao_rad2degl(long double x);

#endif

#ifndef     ao_roundd

#define     ao_roundd(x)                                    ao_roundd_half_away_from_zero(x)

#endif

#ifndef     ao_roundf

#define     ao_roundf(x)                                    ao_roundf_half_away_from_zero(x)

#endif

#ifndef     ao_roundl

#define     ao_roundl(x)                                    ao_roundl_half_away_from_zero(x)

#endif

#ifndef     ao_roundd_away_from_infinity

#define     ao_roundd_away_from_infinity(x)                 ao_truncd(x)

#endif

#ifndef     ao_roundf_away_from_infinity

#define     ao_roundf_away_from_infinity(x)                 ao_truncf(x)

#endif

#ifndef     ao_roundl_away_from_infinity

#define     ao_roundl_away_from_infinity(x)                 ao_truncl(x)

#endif

#ifndef     ao_roundd_away_from_negative_infinity

#define     ao_roundd_away_from_negative_infinity(x)        ao_ceild(x)

#endif

#ifndef     ao_roundf_away_from_negative_infinity

#define     ao_roundf_away_from_negative_infinity(x)        ao_ceilf(x)

#endif

#ifndef     ao_roundl_away_from_negative_infinity

#define     ao_roundl_away_from_negative_infinity(x)        ao_ceill(x)

#endif

#ifndef     ao_roundd_away_from_positive_infinity

#define     ao_roundd_away_from_positive_infinity(x)        ao_floord(x)

#endif

#ifndef     ao_roundf_away_from_positive_infinity

#define     ao_roundf_away_from_positive_infinity(x)        ao_floorf(x)

#endif

#ifndef     ao_roundl_away_from_positive_infinity

#define     ao_roundl_away_from_positive_infinity(x)        ao_floorl(x)

#endif

#ifndef     ao_roundd_away_from_zero

double      ao_roundd_away_from_zero(double x);

#endif

#ifndef     ao_roundf_away_from_zero

float       ao_roundf_away_from_zero(float x);

#endif

#ifndef     ao_roundl_away_from_zero

long double ao_roundl_away_from_zero(long double x);

#endif

#ifndef     ao_roundd_down

#define     ao_roundd_down(x)                               ao_floord(x)

#endif

#ifndef     ao_roundf_down

#define     ao_roundf_down(x)                               ao_floorf(x)

#endif

#ifndef     ao_roundl_down

#define     ao_roundl_down(x)                               ao_floorl(x)

#endif

#ifndef     ao_roundd_half_away_from_infinity

#define     ao_roundd_half_away_from_infinity(x)            ao_roundd_half_to_zero(x)

#endif

#ifndef     ao_roundf_half_away_from_infinity

#define     ao_roundf_half_away_from_infinity(x)            ao_roundf_half_to_zero(x)

#endif

#ifndef     ao_roundl_half_away_from_infinity

#define     ao_roundl_half_away_from_infinity(x)            ao_roundl_half_to_zero(x)

#endif

#ifndef     ao_roundd_half_away_from_negative_infinity

#define     ao_roundd_half_away_from_negative_infinity(x)   ao_roundd_half_up(x)

#endif

#ifndef     ao_roundf_half_away_from_negative_infinity

#define     ao_roundf_half_away_from_negative_infinity(x)   ao_roundf_half_up(x)

#endif

#ifndef     ao_roundl_half_away_from_negative_infinity

#define     ao_roundl_half_away_from_negative_infinity(x)   ao_roundl_half_up(x)

#endif

#ifndef     ao_roundd_half_away_from_positive_infinity

#define     ao_roundd_half_away_from_positive_infinity(x)   ao_roundd_half_down(x)

#endif

#ifndef     ao_roundf_half_away_from_positive_infinity

#define     ao_roundf_half_away_from_positive_infinity(x)   ao_roundf_half_down(x)

#endif

#ifndef     ao_roundl_half_away_from_positive_infinity

#define     ao_roundl_half_away_from_positive_infinity(x)   ao_roundl_half_down(x)

#endif

#ifndef     ao_roundd_half_away_from_zero

#define     ao_roundd_half_away_from_zero(x)                ao_roundd_half_to_infinity(x)

#endif

#ifndef     ao_roundf_half_away_from_zero

#define     ao_roundf_half_away_from_zero(x)                ao_roundf_half_to_infinity(x)

#endif

#ifndef     ao_roundl_half_away_from_zero

#define     ao_roundl_half_away_from_zero(x)                ao_roundl_half_to_infinity(x)

#endif

#ifndef     ao_roundd_half_down

double      ao_roundd_half_down(double x);

#endif

#ifndef     ao_roundf_half_down

float       ao_roundf_half_down(float x);

#endif

#ifndef     ao_roundl_half_down

long double ao_roundl_half_down(long double x);

#endif

#ifndef     ao_roundd_half_to_even

double      ao_roundd_half_to_even(double x);

#endif

#ifndef     ao_roundf_half_to_even

float       ao_roundf_half_to_even(float x);

#endif

#ifndef     ao_roundl_half_to_even

long double ao_roundl_half_to_even(long double x);

#endif

#ifndef     ao_roundd_half_to_infinity

double      ao_roundd_half_to_infinity(double x);

#endif

#ifndef     ao_roundf_half_to_infinity

float       ao_roundf_half_to_infinity(float x);

#endif

#ifndef     ao_roundl_half_to_infinity

long double ao_roundl_half_to_infinity(long double x);

#endif

#ifndef     ao_roundd_half_to_negative_infinity

#define     ao_roundd_half_to_negative_infinity(x)          ao_roundd_half_down(x)

#endif

#ifndef     ao_roundf_half_to_negative_infinity

#define     ao_roundf_half_to_negative_infinity(x)          ao_roundf_half_down(x)

#endif

#ifndef     ao_roundl_half_to_negative_infinity

#define     ao_roundl_half_to_negative_infinity(x)          ao_roundl_half_down(x)

#endif

#ifndef     ao_roundd_half_to_odd

double      ao_roundd_half_to_odd(double x);

#endif

#ifndef     ao_roundf_half_to_odd

float       ao_roundf_half_to_odd(float x);

#endif

#ifndef     ao_roundl_half_to_odd

long double ao_roundl_half_to_odd(long double x);

#endif

#ifndef     ao_roundd_half_to_positive_infinity

#define     ao_roundd_half_to_positive_infinity(x)          ao_roundd_half_up(x)

#endif

#ifndef     ao_roundf_half_to_positive_infinity

#define     ao_roundf_half_to_positive_infinity(x)          ao_roundf_half_up(x)

#endif

#ifndef     ao_roundl_half_to_positive_infinity

#define     ao_roundl_half_to_positive_infinity(x)          ao_roundl_half_up(x)

#endif

#ifndef     ao_roundd_half_to_zero

double      ao_roundd_half_to_zero(double x);

#endif

#ifndef     ao_roundf_half_to_zero

float       ao_roundf_half_to_zero(float x);

#endif

#ifndef     ao_roundl_half_to_zero

long double ao_roundl_half_to_zero(long double x);

#endif

#ifndef     ao_roundd_half_up

double      ao_roundd_half_up(double x);

#endif

#ifndef     ao_roundf_half_up

float       ao_roundf_half_up(float x);

#endif

#ifndef     ao_roundl_half_up

long double ao_roundl_half_up(long double x);

#endif

#ifndef     ao_roundd_to_infinity

#define     ao_roundd_to_infinity(x)                        ao_roundd_away_from_zero(x)

#endif

#ifndef     ao_roundf_to_infinity

#define     ao_roundf_to_infinity(x)                        ao_roundf_away_from_zero(x)

#endif

#ifndef     ao_roundl_to_infinity

#define     ao_roundl_to_infinity(x)                        ao_roundl_away_from_zero(x)

#endif

#ifndef     ao_roundd_to_negative_infinity

#define     ao_roundd_to_negative_infinity(x)               ao_floord(x)

#endif

#ifndef     ao_roundf_to_negative_infinity

#define     ao_roundf_to_negative_infinity(x)               ao_floorf(x)

#endif

#ifndef     ao_roundl_to_negative_infinity

#define     ao_roundl_to_negative_infinity(x)               ao_floorl(x)

#endif

#ifndef     ao_roundd_to_positive_infinity

#define     ao_roundd_to_positive_infinity(x)               ao_ceild(x)

#endif

#ifndef     ao_roundf_to_positive_infinity

#define     ao_roundf_to_positive_infinity(x)               ao_ceilf(x)

#endif

#ifndef     ao_roundl_to_positive_infinity

#define     ao_roundl_to_positive_infinity(x)               ao_ceill(x)

#endif

#ifndef     ao_roundd_to_zero

#define     ao_roundd_to_zero(x)                            ao_truncd(x)

#endif

#ifndef     ao_roundf_to_zero

#define     ao_roundf_to_zero(x)                            ao_truncf(x)

#endif

#ifndef     ao_roundl_to_zero

#define     ao_roundl_to_zero(x)                            ao_truncl(x)

#endif

#ifndef     ao_roundd_up

#define     ao_roundd_up(x)                                 ao_ceild(x)

#endif

#ifndef     ao_roundf_up

#define     ao_roundf_up(x)                                 ao_ceilf(x)

#endif

#ifndef     ao_roundl_up

#define     ao_roundl_up(x)                                 ao_ceill(x)

#endif

#ifndef     ao_secd

double      ao_secd(double x);

#endif

#ifndef     ao_secf

float       ao_secf(float x);

#endif

#ifndef     ao_secl

long double ao_secl(long double x);

#endif

#ifndef     ao_sechd

double      ao_sechd(double x);

#endif

#ifndef     ao_sechf

float       ao_sechf(float x);

#endif

#ifndef     ao_sechl

long double ao_sechl(long double x);

#endif

#ifndef     ao_signd

double      ao_signd(double x);

#endif

#ifndef     ao_signf

float       ao_signf(float x);

#endif

#ifndef     ao_signl

long double ao_signl(long double x);

#endif

#ifndef     ao_sind

double      ao_sind(double x);

#endif

#ifndef     ao_sinf

float       ao_sinf(float x);

#endif

#ifndef     ao_sinl

long double ao_sinl(long double x);

#endif

#ifndef     ao_sinhd

double      ao_sinhd(double x);

#endif

#ifndef     ao_sinhf

float       ao_sinhf(float x);

#endif

#ifndef     ao_sinhl

long double ao_sinhl(long double x);

#endif

#ifndef     ao_sqrtd

double      ao_sqrtd(double x);

#endif

#ifndef     ao_sqrtf

float       ao_sqrtf(float x);

#endif

#ifndef     ao_sqrtl

long double ao_sqrtl(long double x);

#endif

#ifndef     ao_tand

double      ao_tand(double x);

#endif

#ifndef     ao_tanf

float       ao_tanf(float x);

#endif

#ifndef     ao_tanl

long double ao_tanl(long double x);

#endif

#ifndef     ao_tanhd

double      ao_tanhd(double x);

#endif

#ifndef     ao_tanhf

float       ao_tanhf(float x);

#endif

#ifndef     ao_tanhl

long double ao_tanhl(long double x);

#endif

#ifndef     ao_truncd

double      ao_truncd(double x);

#endif

#ifndef     ao_truncf

float       ao_truncf(float x);

#endif

#ifndef     ao_truncl

long double ao_truncl(long double x);

#endif

#ifndef     ao_wrapd

double      ao_wrapd(double x, double beginning, double length);

#endif

#ifndef     ao_wrapf

float       ao_wrapf(float x, float beginning, float length);

#endif

#ifndef     ao_wrapl

long double ao_wrapl(long double x, long double beginning, long double length);

#endif

```
