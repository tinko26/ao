---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32mx/ao_sys_bmx.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mx/ao_sys_bmx.h/ 
subtitle: "<code>ao_sys_xc32_pic32mx</code>"
title: "<code>ao_sys_bmx.h</code>"
toc: true
---

#ifndef ao_sys_bmx_wsdram_disable

#define ao_sys_bmx_wsdram_disable()     { BMXCONCLR = _BMXCON_BMXWSDRM_MASK; }

#endif

#ifndef ao_sys_bmx_wsdram_enable

#define ao_sys_bmx_wsdram_enable()      { BMXCONSET = _BMXCON_BMXWSDRM_MASK; }

#endif

