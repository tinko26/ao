---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32/ao_ir_mvec.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32/ao_ir_mvec.h/ 
subtitle: "<code>ao_sys_xc32_pic32</code>"
title: "<code>ao_ir_mvec.h</code>"
toc: true
---

#ifndef ao_ir_mvec_disable

#define ao_ir_mvec_disable()    { INTCONCLR = _INTCON_MVEC_MASK; }

#endif

#ifndef ao_ir_mvec_enable

#define ao_ir_mvec_enable()     { INTCONSET = _INTCON_MVEC_MASK; }

#endif

