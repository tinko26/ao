---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mk/ao_sys.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32_pic32mk/ao_sys.h/ 
subtitle: ""
title: "ao_sys.h"
toc: true
---

# Overview

...

# Includes

```c
#include <ao_sys_exc.h>
#include <ao_sys_kseg0.h>
#include <ao_sys_lock_ir.h>
#include <ao_sys_lock_pps.h>
#include <ao_sys_pcache.h>

#ifndef AO_SYS_XC32_PIC32MK

#define AO_SYS_XC32_PIC32MK

#endif

#include_next <ao_sys.h>

```
