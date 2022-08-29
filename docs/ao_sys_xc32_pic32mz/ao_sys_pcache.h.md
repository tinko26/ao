---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32mz/ao_sys_pcache.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mz/ao_sys_pcache.h/ 
subtitle: "<code>ao_sys_xc32_pic32mz</code>"
title: "<code>ao_sys_pcache.h</code>"
toc: true
---

```c
#ifndef ao_sys_pfm_ws_set

#define ao_sys_pfm_ws_set(ws)                                               \
{                                                                           \
        PRECONSET = _PRECON_PFMWS_MASK;                                     \
        PRECONCLR = _PRECON_PFMWS_MASK & ~((ws) << _PRECON_PFMWS_POSITION); \
}

#endif

#ifndef ao_sys_pref_disable

#define ao_sys_pref_disable()                                               \
{                                                                           \
        PRECONCLR = _PRECON_PREFEN_MASK;                                    \
}

#endif

#ifndef ao_sys_pref_enable_any

#define ao_sys_pref_enable_any()                                            \
{                                                                           \
        PRECONSET = _PRECON_PREFEN_MASK;                                    \
}

#endif

#ifndef ao_sys_pref_enable_instructions

#define ao_sys_pref_enable_instructions()                                   \
{                                                                           \
        PRECONCLR = _PRECON_PREFEN_MASK;                                    \
        PRECONSET = _PRECON_PREFEN_MASK & (1 << _PRECON_PREFEN_POSITION);   \
}

#endif

#ifndef ao_sys_pref_enable_instructions_and_data

#define ao_sys_pref_enable_instructions_and_data()                          \
{                                                                           \
        PRECONCLR = _PRECON_PREFEN_MASK;                                    \
        PRECONSET = _PRECON_PREFEN_MASK & (2 << _PRECON_PREFEN_POSITION);   \
}

#endif

```
