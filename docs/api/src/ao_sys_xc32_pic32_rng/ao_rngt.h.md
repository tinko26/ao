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

Enable or disable the true random number generator.

```c
#define ao_rngt_enable()
#define ao_rngt_disable()
```

Get the number of bits that have been generate since the last read.

```c
#define ao_rngt_bits()
```

Read the generated value.

```c
#define ao_rngt_value()
```

Read the most or least significant 32 bits of the generated value.

```c
#define ao_rngt_value_hi()
#define ao_rngt_value_lo()
```
