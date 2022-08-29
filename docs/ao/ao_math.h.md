---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao/ao_math.h module of the ao real-time operating system."
draft: true
permalink: /ao/ao_math.h/ 
subtitle: "<code>ao</code>"
title: "<code>ao_math.h</code>"
toc: true
---

#ifndef AO_ABS

#define AO_ABS(x)                   ((x) < (0) ? -(x) : (x))

#endif

#ifndef AO_CLAMP

#define AO_CLAMP(x, x_min, x_max)   ((x) <= (x_min) ? (x_min) : ((x) >= (x_max) ? (x_max) : (x)))

#endif

#ifndef AO_IS_EQUAL

#define AO_IS_EQUAL(x, y)           ((x) == (y) ? true : false)

#endif

#ifndef AO_IS_GREATER

#define AO_IS_GREATER(x, y)         ((x) >  (y) ? true : false)

#endif

#ifndef AO_IS_GREATER_EQUAL

#define AO_IS_GREATER_EQUAL(x, y)   ((x) >= (y) ? true : false)

#endif

#ifndef AO_IS_LESS

#define AO_IS_LESS(x, y)            ((x) <  (y) ? true : false)

#endif

#ifndef AO_IS_LESS_EQUAL

#define AO_IS_LESS_EQUAL(x, y)      ((x) <= (y) ? true : false)

#endif

#ifndef AO_IS_NEGATIVE

#define AO_IS_NEGATIVE(x)           ((x) <  (0) ? true : false)

#endif

#ifndef AO_IS_POSITIVE

#define AO_IS_POSITIVE(x)           ((x) >  (0) ? true : false)

#endif

#ifndef AO_IS_ZERO

#define AO_IS_ZERO(x)               ((x) == (0) ? true : false)

#endif

#ifndef AO_MAX

#define AO_MAX(x, y)                ((x) >= (y) ? (x) : (y))

#endif

#ifndef AO_MIN

#define AO_MIN(x, y)                ((x) <= (y) ? (x) : (y))

#endif

