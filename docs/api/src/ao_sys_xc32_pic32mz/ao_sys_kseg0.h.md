---
author: "Stefan Wagner"
date: 2022-09-25
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz/ao_sys_kseg0.h/
toc: true
---

# Include

| `xc.h` |

# Functions

## `ao_sys_kseg0_cacheable_write_back_alloc`

```c
#define ao_sys_kseg0_cacheable_write_back_alloc() \
(                                                 \
    _bcsc0(_CP0_CONFIG, _CP0_CONFIG_SELECT, 4, 3) \
)
```

Sets the KSEG0 cache coherency algorithm to cacheable, non-coherent, write-back, write allocate.

## `ao_sys_kseg0_cacheable_write_through_alloc`

```c
#define ao_sys_kseg0_cacheable_write_through_alloc() \
(                                                    \
    _bcsc0(_CP0_CONFIG, _CP0_CONFIG_SELECT, 6, 1)    \
)
```

Sets the KSEG0 cache coherency algorithm to cacheable, non-coherent, write-through, write allocate.

## `ao_sys_kseg0_cacheable_write_through_no_alloc`

```c
#define ao_sys_kseg0_cacheable_write_through_no_alloc() \
(                                                       \
    _bcc0( _CP0_CONFIG, _CP0_CONFIG_SELECT, 7)          \
)
```

Sets the KSEG0 cache coherency algorithm to cacheable, non-coherent, write-through, no write allocate.

## `ao_sys_kseg0_uncached`

```c
#define ao_sys_kseg0_uncached()                   \
(                                                 \
    _bcsc0(_CP0_CONFIG, _CP0_CONFIG_SELECT, 5, 2) \
)
```

Sets the KSEG0 cache coherency algorithm to uncached.
