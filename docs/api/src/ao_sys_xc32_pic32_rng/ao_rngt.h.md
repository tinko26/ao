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

```c
#define ao_rngt_enable()
#define ao_rngt_disable()
```

Enables or disables the true random number generator.

## `ao_rngt_bits`

```c
#define ao_rngt_bits()
```

Gets the number of bits that have been generate since the last read.

## `ao_rngt_value`

```c
#define ao_rngt_value()
```

Reads the generated value.

## `ao_rngt_value_hi`
## `ao_rngt_value_lo`

```c
#define ao_rngt_value_hi()
#define ao_rngt_value_lo()
```

Reads the most or least significant 32 bits of the generated value.
