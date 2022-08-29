---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32/ao_sys.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32/ao_sys.h/ 
subtitle: ""
title: "ao_sys.h"
toc: true
---

# Overview

...

# Includes

```c
#include <ao_sys_clock.h>
#include <ao_sys_lock_device.h>
#include <ao_sys_lock_dma.h>
#include <ao_sys_lock_ie.h>
#include <ao_sys_lock_ir.h>
#include <ao_sys_power.h>
#include <ao_sys_reset.h>

#ifndef AO_SYS_XC32_PIC32

#define AO_SYS_XC32_PIC32

#endif

#include_next <ao_sys.h>

```
