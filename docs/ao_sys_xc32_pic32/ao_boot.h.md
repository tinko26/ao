---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32/ao_boot.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32/ao_boot.h/ 
subtitle: "<code>ao_sys_xc32_pic32</code>"
title: "<code>ao_boot.h</code>"
toc: true
---

```c
#ifndef ao_boot_count

#define ao_boot_count()     ao_count_debug_stop()

#endif

#ifndef ao_boot_ir_mvec

#define ao_boot_ir_mvec()   ao_ir_mvec_enable()

#endif

void    ao_boot_ir_stack();

```
