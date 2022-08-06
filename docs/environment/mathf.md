---
author: "Stefan Wagner"
date: 2022-08-06
description: "Mathematics for Floating-Point Numbers in the ao Real-Time Operating System (RTOS)."
draft: false
permalink: /environment/mathf/
title: "Mathematics for Floating-Point Numbers"
---

# Mathematics for Floating-Point Numbers

The `ao_mathf.h` module contains mathematical constants and functions for floating-point numbers. 

Although the standard library provides such constants and functions, too, they are not available in a freestanding runtime environment. Then again, many toolchains provide implementations, either in software or highly optimized for target platforms with a floating-point unit.

Therefore, the environment package does not provide an implementation for most of the functions. Consequently, an implementation must be provided by a hardware-specific package by overriding this module.

## Constants

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

## Functions

For each operation, there is a function for each of the three fundamental floating-point types. However, the following listing focuses on the respective double variant, only.

Absolute value.

```c
double ao_fabsd(double x);
```

Angles.

```c
double ao_deg2radd(double x);
double ao_rad2degd(double x);
```

Classification.

```c
bool ao_isfinited(double x);
bool ao_isinfd(double x);
bool ao_isnand(double x);
```

Division.

```c
double ao_fmodd(double x, double y);
```

Exponential functions.

```c
double ao_expd(double x);
double ao_exp2d(double x);
```

Generators.

```c
double ao_infd();
double ao_nand();
```

Hyperbolic functions.

```c
double ao_acoshd(double x);
double ao_acothd(double x);
double ao_acschd(double x);
double ao_asechd(double x);
double ao_asinhd(double x);
double ao_atanhd(double x);
double ao_coshd(double x);
double ao_cothd(double x);
double ao_cschd(double x);
double ao_sechd(double x);
double ao_sinhd(double x);
double ao_tanhd(double x);
```

Logarithmic functions.

```c
double ao_frexpd(double x, int * exp);
double ao_frexp10d(double x, int * exp);
double ao_logd(double x);
double ao_log10d(double x);
double ao_log2d(double x);
```

Power functions.

```c
double ao_cbrtd(double x);
double ao_hypotd(double x, double y);
double ao_ldexpd(double x, int exp);
double ao_ldexp10d(double x, int exp);
double ao_powd(double x, double y);
double ao_sqrtd(double x);
```

Rounding.

```c
double ao_ceild(double x);
double ao_floord(double x);
double ao_modfd(double x, double * intpart);
double ao_roundd(double x);
double ao_roundd_away_from_infinity(double x);
double ao_roundd_away_from_negative_infinity(double x);
double ao_roundd_away_from_positive_infinity(double x);
double ao_roundd_away_from_zero(double x);
double ao_roundd_down(double x);
double ao_roundd_half_away_from_infinity(double x);
double ao_roundd_half_away_from_negative_infinity(double x);
double ao_roundd_half_away_from_positive_infinity(double x);
double ao_roundd_half_away_from_zero(double x);
double ao_roundd_half_down(double x);
double ao_roundd_half_to_even(double x);
double ao_roundd_half_to_infinity(double x);
double ao_roundd_half_to_negative_infinity(double x);
double ao_roundd_half_to_odd(double x);
double ao_roundd_half_to_positive_infinity(double x);
double ao_roundd_half_to_zero(double x);
double ao_roundd_half_up(double x);
double ao_roundd_to_infinity(double x);
double ao_roundd_to_negative_infinity(double x);
double ao_roundd_to_positive_infinity(double x);
double ao_roundd_to_zero(double x);
double ao_roundd_up(double x);
double ao_truncd(double x);
```

Sign.

```c
double ao_signd(double x);
```

Trigonometric functions.

```c
double ao_acos(double x);
double ao_acotd(double x);
double ao_acscd(double x);
double ao_asecd(double x);
double ao_asind(double x);
double ao_atand(double x);
double ao_atan2d(double y, double x);
double ao_cosd(double x);
double ao_cotd(double x);
double ao_cscd(double x);
double ao_secd(double x);
double ao_sind(double x);
double ao_tand(double x);
```

Wrapping.

```c
double ao_wrapd(double x, double beginning, double length);
```
