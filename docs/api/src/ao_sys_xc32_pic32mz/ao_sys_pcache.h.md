---
author: "Stefan Wagner"
date: 2022-09-25
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz/ao_sys_pcache.h/
toc: true
---

# Include

| `xc.h` |

# Functions

## `ao_sys_pfm_ws_set`

```c
#define ao_sys_pfm_ws_set(ws)                                           \
{                                                                       \
    PRECONSET = _PRECON_PFMWS_MASK;                                     \
    PRECONCLR = _PRECON_PFMWS_MASK & ~((ws) << _PRECON_PFMWS_POSITION); \
}
```

Sets the program flash memory (PFM) access time defined in terms of SYSCLK wait states.

## `ao_sys_pref_disable`

```c
#define ao_sys_pref_disable()        \
{                                    \
    PRECONCLR = _PRECON_PREFEN_MASK; \
}
```

Disables predictive prefetch.

## `ao_sys_pref_enable_any`

```c
#define ao_sys_pref_enable_any()     \
{                                    \
    PRECONSET = _PRECON_PREFEN_MASK; \
}
```

Enables predictive prefetch for any address.

## `ao_sys_pref_enable_instructions`

```c
#define ao_sys_pref_enable_instructions()                             \
{                                                                     \
    PRECONCLR = _PRECON_PREFEN_MASK;                                  \
    PRECONSET = _PRECON_PREFEN_MASK & (1 << _PRECON_PREFEN_POSITION); \
}
```

Enables predictive prefetch for CPU instructions only.

## `ao_sys_pref_enable_instructions_and_data`

```c
#define ao_sys_pref_enable_instructions_and_data()                    \
{                                                                     \
    PRECONCLR = _PRECON_PREFEN_MASK;                                  \
    PRECONSET = _PRECON_PREFEN_MASK & (2 << _PRECON_PREFEN_POSITION); \
}
```

Enables predictive prefetch for CPU instructions and CPU data.
