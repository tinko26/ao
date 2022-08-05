---
author: "Stefan Wagner"
date: 2022-08-05
description: "Mathematics in the ao Real-Time Operating System (RTOS)."
draft: false
permalink: /environment/math/
title: "Mathematics"
---

# Mathematics

The `math.h` module defines a number of useful macro functions for mathematical operations, that work with all fundamental arithmetic types. Because these are macro functions, care must be taken for side effects, as some parameters get evaluated more than once.

| Macro Function | |
|----------------|-|
| `ao_abs(x)` | Returns the absolute value. |
| `ao_clamp(x, min, max)` | Returns `min` if `x` is less than `min`. Returns `max` if `x` is greater than `max`. Returns `x` otherwise. |
| `ao_is_equal(x, y)` | Compares two values. |
| `ao_is_greater(x, y)` | Compares two values. |
| `ao_is_greater_equal(x, y)` | Compares two values. |
| `ao_is_less(x, y)` | Compares two values. |
| `ao_is_less_equal(x, y)` | Compares two values. |
| `ao_is_negative(x)` | Checks is a value is negative. |
| `ao_is_positive(x)` | Checks is a value is positive. |
| `ao_is_zero(x)` | Checks is a value equals zero. |
| `ao_max(x, y)` | Returns the maximum of two values. |
| `ao_min(x, y)` | Returns the minimum of two values. |
