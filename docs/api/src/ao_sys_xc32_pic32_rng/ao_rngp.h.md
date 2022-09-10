---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32_rng/ao_rngp.h/
toc: true
---

# Include

```c
#include <stdint.h>
#include <xc.h>
```

# Functions

## `ao_rngp_enable`
## `ao_rngp_disable`

```c
#define ao_rngp_enable()
#define ao_rngp_disable()
```

Enables or disables the pseudo-random number generator.

## `ao_rngp_bits`
## `ao_rngp_bits_set`

```c
#define ao_rngp_bits()
#define ao_rngp_bits_set(x)
```

Gets or sets the maximum number of bits to generate.

## `ao_rngp_continuous_enable`
## `ao_rngp_continuous_disable`

```c
#define ao_rngp_continuous_enable()
#define ao_rngp_continuous_disable()
```

## `ao_rngp_poly`
## `ao_rngp_poly_set`

```c
#define ao_rngp_poly()
#define ao_rngp_poly_set(x)
```

## `ao_rngp_poly_hi`
## `ao_rngp_poly_hi_set`

```c
#define ao_rngp_poly_hi()
#define ao_rngp_poly_hi_set(x)
```

## `ao_rngp_poly_lo`
## `ao_rngp_poly_lo_set`

```c
#define ao_rngp_poly_lo()
#define ao_rngp_poly_lo_set(x)
```

## `ao_rngp_seed`

```c
#define ao_rngp_seed(x)
```

## `ao_rngp_seed_hi`
## `ao_rngp_seed_lo`

```c
#define ao_rngp_seed_hi(x)
#define ao_rngp_seed_lo(x)
```

## `ao_rngp_seed_true`

```c
#define ao_rngp_seed_true(x)
```

## `ao_rngp_value`
## `ao_rngp_value_set`

```c
#define ao_rngp_value()
#define ao_rngp_value_set(x)
```

## `ao_rngp_value_hi`
## `ao_rngp_value_hi_set`

```c
#define ao_rngp_value_hi()
#define ao_rngp_value_hi_set(x)
```

## `ao_rngp_value_lo`
## `ao_rngp_value_lo_set`

```c
#define ao_rngp_value_lo()
#define ao_rngp_value_lo_set(x)
```
