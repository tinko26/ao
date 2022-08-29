---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32/ao_boot.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32/ao_boot.h/ 
subtitle: "ao_sys_xc32_pic32"
title: "ao_boot.h"
toc: true
---

```c
#include <ao_count.h>
#include <ao_ir.h>

#ifndef ao_boot_count

#define ao_boot_count()     ao_count_debug_stop()

#endif

#ifndef ao_boot_ir_mvec

#define ao_boot_ir_mvec()   ao_ir_mvec_enable()

#endif

void    ao_boot_ir_stack();

#include_next <ao_boot.h>

```
