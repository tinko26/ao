---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mx/ao_sys_bmx.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mx/ao_sys_bmx.h/ 
subtitle: ""
title: "ao_sys_bmx.h"
toc: true
---

# Overview

...

# Includes

```c
#include <xc.h>

#ifndef ao_sys_bmx_wsdram_disable

#define ao_sys_bmx_wsdram_disable()     { BMXCONCLR = _BMXCON_BMXWSDRM_MASK; }

#endif

#ifndef ao_sys_bmx_wsdram_enable

#define ao_sys_bmx_wsdram_enable()      { BMXCONSET = _BMXCON_BMXWSDRM_MASK; }

#endif

```
