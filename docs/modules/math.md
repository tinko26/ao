---
author: "Stefan Wagner"
date: 2022-08-08
description: "The ao_math.h module of the ao real-time operating system."
draft: false
permalink: /modules/math/
title: "ao_math.h"
---

# ao_math.h

This module provides a number of useful mathematical operations. They are implemented as macro functions, that work for all fundamental scalar types. This is for two reasons. First, when called with constant parameter values, the result can be evaluated at compile time. Second, they can be used in the definition of macro constants. However, care must be taken for side effects, as some parameter values get evaluated more than once.

## Functions

Absolute value.

```c
#define AO_ABS(x)
```

Clamping.

```c
#define AO_CLAMP(x, min, max);
```

Comparison.

```c
#define AO_IS_EQUAL(x, y)
#define AO_IS_GREATER(x, y)
#define AO_IS_GREATER_EQUAL(x, y)
#define AO_IS_LESS(x, y)
#define AO_IS_LESS_EQUAL(x, y)
```

Sign.

```c
#define AO_IS_NEGATIVE(x)
#define AO_IS_POSITIVE(x)
#define AO_IS_ZERO(x)
```

Maximum and minimum.

```c
#define AO_MAX(x, y)
#define AO_MIN(x, y)
```
