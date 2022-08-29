---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mx/ao_sys_lock_ir.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mx/ao_sys_lock_ir.h/ 
subtitle: ""
title: "ao_sys_lock_ir.h"
toc: true
---

```c
#include <stdint.h>
#include <xc.h>

#ifndef AO_SYS_LOCK_IR

#define AO_SYS_LOCK_IR

static uint32_t ao_sys_lock_ir(uint32_t p2)
{
    uint32_t x1;

    uint32_t x2;

    uint32_t p1;

    if (p2 == 7)
    {
        x1 = __builtin_disable_interrupts();
    }

    else
    {
        x1 = _CP0_GET_STATUS();

        p1 = (x1 & _CP0_STATUS_IPL_MASK) >> _CP0_STATUS_IPL_POSITION;

        if (p1 < p2)
        {
            x2 = x1 & (~_CP0_STATUS_IPL_MASK);

            x2 = x2 | (p2 << _CP0_STATUS_IPL_POSITION);

            _CP0_SET_STATUS(x2);
        }
    }

    return x1;
}

static void ao_sys_unlock_ir(uint32_t x)
{
    _CP0_SET_STATUS(x);
}

#endif

```
