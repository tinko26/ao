---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32_wdt/ao_wdt.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32_wdt/ao_wdt.h/ 
subtitle: ""
title: "ao_wdt.h"
toc: true
---

# Overview

...

# Includes

```c
#include <stdbool.h>
#include <xc.h>

#ifndef AO_WDT

#define AO_WDT

#endif

#ifndef ao_wdt_disable

#define ao_wdt_disable()        { WDTCONCLR = _WDTCON_ON_MASK; }

#endif

#ifndef ao_wdt_enable

#define ao_wdt_enable()         { WDTCONSET = _WDTCON_ON_MASK; }

#endif

#ifndef ao_wdt_is_enabled

#define ao_wdt_is_enabled()     (WDTCON & _WDTCON_ON_MASK ? true : false)

#endif

void    ao_wdt_reset();

```
