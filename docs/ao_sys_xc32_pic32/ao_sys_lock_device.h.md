---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32/ao_sys_lock_device.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32/ao_sys_lock_device.h/ 
subtitle: ""
title: "ao_sys_lock_device.h"
toc: true
---

# Overview

...

# Includes

```c
#include <stdint.h>

typedef struct  ao_sys_lock_device_t    ao_sys_lock_device_t;

#ifndef AO_SYS_LOCK_DEVICE

#define AO_SYS_LOCK_DEVICE

struct  ao_sys_lock_device_t
{
        uint32_t                        dma;

        uint32_t                        ie;
};

#endif

void    ao_sys_unlock_device(           ao_sys_lock_device_t * x);

void    ao_sys_lock_device(             ao_sys_lock_device_t * x);

```
