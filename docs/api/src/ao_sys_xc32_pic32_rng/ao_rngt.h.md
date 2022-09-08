---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32_rng/ao_rngt.h/
toc: true
---

# Include

```c
#include <stdint.h>
#include <xc.h>
```

# Functions

## `ao_rngt_enable`
## `ao_rngt_disable`

Enable or disable the true random number generator.

```c
#define ao_rngt_enable()
#define ao_rngt_disable()
```

## `ao_rngt_bits`

Get the number of bits that have been generate since the last read.

```c
#define ao_rngt_bits()
```

## `ao_rngt_value`

Read the generated value.

```c
#define ao_rngt_value()
```

## `ao_rngt_value_hi`
## `ao_rngt_value_lo`

Read the most or least significant 32 bits of the generated value.

```c
#define ao_rngt_value_hi()
#define ao_rngt_value_lo()
```
