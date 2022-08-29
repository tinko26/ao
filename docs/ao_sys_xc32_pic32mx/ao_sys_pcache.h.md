---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mx/ao_sys_pcache.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mx/ao_sys_pcache.h/ 
subtitle: ""
title: "ao_sys_pcache.h"
toc: true
---

# Overview

...

# Includes

```c
#include <xc.h>

#ifndef ao_sys_pfm_ws_set

#define ao_sys_pfm_ws_set(ws)                                               \
{                                                                           \
        CHECONSET = _CHECON_PFMWS_MASK;                                     \
        CHECONCLR = _CHECON_PFMWS_MASK & ~((ws) << _CHECON_PFMWS_POSITION); \
}

#endif

#ifndef ao_sys_pref_disable

#define ao_sys_pref_disable()                                               \
{                                                                           \
        CHECONCLR = _CHECON_PREFEN_MASK;                                    \
}

#endif

#ifndef ao_sys_pref_enable_both

#define ao_sys_pref_enable_both()                                           \
{                                                                           \
        CHECONSET = _CHECON_PREFEN_MASK;                                    \
}

#endif

#ifndef ao_sys_pref_enable_cacheable

#define ao_sys_pref_enable_cacheable()                                      \
{                                                                           \
        CHECONCLR = _CHECON_PREFEN_MASK;                                    \
        CHECONSET = _CHECON_PREFEN_MASK & (1 << _CHECON_PREFEN_POSITION);   \
}

#endif

#ifndef ao_sys_pref_enable_non_cacheable

#define ao_sys_pref_enable_non_cacheable()                                  \
{                                                                           \
        CHECONCLR = _CHECON_PREFEN_MASK;                                    \
        CHECONSET = _CHECON_PREFEN_MASK & (2 << _CHECON_PREFEN_POSITION);   \
}

#endif

```
