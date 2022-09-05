---
api: true
author: "Stefan Wagner"
date: 2022-09-05
description: "The /src/ao_sys_xc32_pic32_rng/ao_rngp.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32_rng/ao_rngp.h/
subtitle: "Pseudo-random number generator"
title: "ao_rngp.h"
toc: true
---

# Include

```c
#include <stdint.h>
#include <xc.h>
```

# Functions

Enable or disable the pseudo-random number generator.

```c
#define ao_rngp_enable()
#define ao_rngp_disable()
```

Get or set the maximum number of bits to generate.

```c
#define ao_rngp_bits()
#define ao_rngp_bits_set(x)
```

```c
#define ao_rngp_continuous_enable()
#define ao_rngp_continuous_disable()
```

```c
#define ao_rngp_poly()
#define ao_rngp_poly_set(x)
```

```c
#define ao_rngp_poly_hi()
#define ao_rngp_poly_hi_set(x)
```

```c
#define ao_rngp_poly_lo()
#define ao_rngp_poly_lo_set(x)
```

```c
#define ao_rngp_seed(x)
```

```c
#define ao_rngp_seed_hi(x)
#define ao_rngp_seed_lo(x)
```

```c
#define ao_rngp_seed_true(x)
```

```c
#define ao_rngp_value()
#define ao_rngp_value_set(x)
```

```c
#define ao_rngp_value_hi()
#define ao_rngp_value_hi_set(x)
```

```c
#define ao_rngp_value_lo()
#define ao_rngp_value_lo_set(x)
```
