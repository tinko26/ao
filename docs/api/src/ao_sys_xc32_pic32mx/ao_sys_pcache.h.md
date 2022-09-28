---
author: "Stefan Wagner"
date: 2022-09-25
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx/ao_sys_pcache.h/
toc: true
---

# Include

| `xc.h` |

# Functions

## `ao_sys_pfm_ws_set`

```c
#define ao_sys_pfm_ws_set(ws)                                           \
{                                                                       \
    CHECONSET = _CHECON_PFMWS_MASK;                                     \
    CHECONCLR = _CHECON_PFMWS_MASK & ~((ws) << _CHECON_PFMWS_POSITION); \
}
```

Sets the program flash memory (PFM) access time defined in terms of SYSCLK wait states.

## `ao_sys_pref_disable`

```c
#define ao_sys_pref_disable()        \
{                                    \
    CHECONCLR = _CHECON_PREFEN_MASK; \
}
```

Disables predictive prefetch.

## `ao_sys_pref_enable_both`

```c
#define ao_sys_pref_enable_both()    \
{                                    \
    CHECONSET = _CHECON_PREFEN_MASK; \
}
```

Enables predictive prefetch for both cacheable and non-cacheable regions.

## `ao_sys_pref_enable_cacheable`

```c
#define ao_sys_pref_enable_cacheable()                                \
{                                                                     \
    CHECONCLR = _CHECON_PREFEN_MASK;                                  \
    CHECONSET = _CHECON_PREFEN_MASK & (1 << _CHECON_PREFEN_POSITION); \
}
```

Enables predictive prefetch for cacheable regions.

## `ao_sys_pref_enable_non_cacheable`

```c
#define ao_sys_pref_enable_non_cacheable()                            \
{                                                                     \
    CHECONCLR = _CHECON_PREFEN_MASK;                                  \
    CHECONSET = _CHECON_PREFEN_MASK & (2 << _CHECON_PREFEN_POSITION); \
}
```

Enables predictive prefetch for non-cacheable regions.
