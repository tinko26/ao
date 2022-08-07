---
author: "Stefan Wagner"
date: 2022-08-07
description: "Mathematics in the ao Real-Time Operating System (RTOS)."
draft: false
permalink: /environment/math/
title: "Mathematics"
---

# Mathematics

The `math.h` module provides a number of useful mathematical operations. They are implemented as macro functions, that work for all fundamental arithmetic types. This is for two reasons. First, when called with constant parameter values, the result can be evaluated at compile time. Second, they can be used in the definition of macro constants, which some kernel functions make use of. However, care must be taken for side effects, as some parameter values get evaluated more than once.

## Functions

Absolute value.

```c
double x = ao_abs(-3.2);
```

Clamping.

```c
double y = ao_clamp(x, -2, 2);
```

Comparison.

```c
if (ao_is_equal(x, y)) { }
if (ao_is_greater(x, y)) { }
if (ao_is_greater_equal(x, y)) { }
if (ao_is_less(x, y)) { }
if (ao_is_less_equal(x, y)) { }
```

Sign.

```c
if (ao_is_negative(x)) { }
if (ao_is_positive(x)) { }
if (ao_is_zero(x)) { }
```

Maximum and minimum.

```c
double z1 = ao_max(x, y);
double z2 = ao_min(x, y);
```
