---
author: "Stefan Wagner"
date: 2022-09-25
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx/ao_sys_bmx.h/
toc: true
---

# Include

| `xc.h` |

# Identifier

```c
#define AO_SYS_BMX
```

# Functions

## `ao_sys_bmx_wsdram_disable`

```c
#define ao_sys_bmx_wsdram_disable()    \
{                                      \
    BMXCONCLR = _BMXCON_BMXWSDRM_MASK; \
}
```

Sets the data RAM access time defined in terms of SYSCLK wait states to 0.

## `ao_sys_bmx_wsdram_enable`

```c
#define ao_sys_bmx_wsdram_enable()     \
{                                      \
    BMXCONSET = _BMXCON_BMXWSDRM_MASK; \
}
```

Sets the data RAM access time defined in terms of SYSCLK wait states to 1.
