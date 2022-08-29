---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mz/ao_sys_lock_ir.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mz/ao_sys_lock_ir.h/ 
subtitle: ""
title: "ao_sys_lock_ir.h"
toc: true
---

```c
#include <stdint.h>
#include <xc.h>

#ifndef AO_SYS_LOCK_IR

#define AO_SYS_LOCK_IR

static uint32_t ao_sys_lock_ir(uint32_t p)
{
    uint32_t x = _CP0_GET_VIEW_IPL();

    p = p << 2;

    if (x < p)
    {
        _CP0_SET_VIEW_IPL(p);
    }

    return x;
}

static void ao_sys_unlock_ir(uint32_t x)
{
    _CP0_SET_VIEW_IPL(x);
}

#endif

```
