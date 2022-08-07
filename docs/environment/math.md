---
author: "Stefan Wagner"
date: 2022-08-07
description: "Mathematics in the ao Real-Time Operating System (RTOS)."
draft: false
permalink: /environment/math/
title: "Mathematics"
---

# Mathematics

The `math.h` module provides a number of useful mathematical operations. They are implemented as macro functions, that work for all fundamental arithmetic types. This is for two reasons. First, when called with constant parameter values, the result can be evaluated at compile time. Second, they can be used in the definition of macro constants. However, care must be taken for side effects, as some parameter values get evaluated more than once.

## Functions

Absolute value.

```c
double x = AO_ABS(-3.2);
```

Clamping.

```c
double y = AO_CLAMP(x, -2, 2);
```

Comparison.

```c
if (AO_IS_EQUAL(x, y)) { }
if (AO_IS_GREATER(x, y)) { }
if (AO_IS_GREATER_EQUAL(x, y)) { }
if (AO_IS_LESS(x, y)) { }
if (AO_IS_LESS_EQUAL(x, y)) { }
```

Sign.

```c
if (AO_IS_NEGATIVE(x)) { }
if (AO_IS_POSITIVE(x)) { }
if (AO_IS_ZERO(x)) { }
```

Maximum and minimum.

```c
double z1 = AO_MAX(x, y);
double z2 = AO_MIN(x, y);
```
