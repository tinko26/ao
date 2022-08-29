---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mz/ao_sys_kseg0.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mz/ao_sys_kseg0.h/ 
subtitle: "<code>ao_sys_xc32_pic32mz</code>"
title: "<code>ao_sys_kseg0.h</code>"
toc: true
---

#ifndef ao_sys_kseg0_cacheable_write_back_alloc

#define ao_sys_kseg0_cacheable_write_back_alloc()           _bcsc0(_CP0_CONFIG, _CP0_CONFIG_SELECT, 4, 3)

#endif

#ifndef ao_sys_kseg0_cacheable_write_through_alloc

#define ao_sys_kseg0_cacheable_write_through_alloc()        _bcsc0(_CP0_CONFIG, _CP0_CONFIG_SELECT, 6, 1)

#endif

#ifndef ao_sys_kseg0_cacheable_write_through_no_alloc

#define ao_sys_kseg0_cacheable_write_through_no_alloc()     _bcc0( _CP0_CONFIG, _CP0_CONFIG_SELECT, 7)

#endif

#ifndef ao_sys_kseg0_uncached

#define ao_sys_kseg0_uncached()                             _bcsc0(_CP0_CONFIG, _CP0_CONFIG_SELECT, 5, 2)

#endif

