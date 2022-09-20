---
author: "Stefan Wagner"
date: 2022-09-20
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx/ao_sys_kseg0.h/
toc: true
---

# Include

```c
#include <xc.h>
```

# Functions

## `ao_sys_kseg0_cacheable`

```c
#define ao_sys_kseg0_cacheable()                  \
(                                                 \
    _bcsc0(_CP0_CONFIG, _CP0_CONFIG_SELECT, 4, 3) \
)
```

Sets the KSEG0 cache coherency algorithm to cacheable.

## `ao_sys_kseg0_uncached`

```c
#define ao_sys_kseg0_uncached()                   \
(                                                 \
    _bcsc0(_CP0_CONFIG, _CP0_CONFIG_SELECT, 5, 2) \
)
```

Sets the KSEG0 cache coherency algorithm to uncached.
