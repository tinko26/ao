---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32mx/ao_sys_exc.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mx/ao_sys_exc.h/ 
subtitle: "<code>ao_sys_xc32_pic32mx</code>"
title: "<code>ao_sys_exc.h</code>"
toc: true
---

```c
typedef enum    ao_sys_exc_t    ao_sys_exc_t;

#ifndef AO_SYS_EXC

#define AO_SYS_EXC

enum    ao_sys_exc_t
{
        AO_SYS_EXC_INT          = 0x00,

        AO_SYS_EXC_ADEL         = 0x04,

        AO_SYS_EXC_ADES         = 0x05,

        AO_SYS_EXC_IBE          = 0x06,

        AO_SYS_EXC_DBE          = 0x07,

        AO_SYS_EXC_SYS          = 0x08,

        AO_SYS_EXC_BP           = 0x09,

        AO_SYS_EXC_RI           = 0x0A,

        AO_SYS_EXC_CPU          = 0x0B,

        AO_SYS_EXC_OV           = 0x0C,

        AO_SYS_EXC_TR           = 0x0D
};

#endif

```
