---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32/ao_ir_enable.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32/ao_ir_enable.h/ 
subtitle: "<code>ao_sys_xc32_pic32</code>"
title: "<code>ao_ir_enable.h</code>"
toc: true
---

#ifndef ao_ir_disable

#define ao_ir_disable()     __builtin_disable_interrupts()

#endif

#ifndef ao_ir_enable

#define ao_ir_enable()      __builtin_enable_interrupts()

#endif

