---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32mk/ao_sys_lock_pps.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mk/ao_sys_lock_pps.h/ 
subtitle: "<code>ao_sys_xc32_pic32mk</code>"
title: "<code>ao_sys_lock_pps.h</code>"
toc: true
---

```c
typedef struct  ao_sys_lock_pps_t   ao_sys_lock_pps_t;

#ifndef AO_SYS_LOCK_PPS

#define AO_SYS_LOCK_PPS

struct  ao_sys_lock_pps_t
{
        ao_sys_lock_device_t        device;

        uint32_t                    io;
};

#endif

void    ao_sys_unlock_pps(          ao_sys_lock_pps_t * x);

void    ao_sys_lock_pps(            ao_sys_lock_pps_t * x);

```
