---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mz_da/ao_ir_glcd.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mz_da/ao_ir_glcd.h/ 
subtitle: "<code>ao_sys_xc32_pic32mz_da</code>"
title: "<code>ao_ir_glcd.h</code>"
toc: true
---

#ifndef AO_IR_GLCD_ATTRIBUTE

#define AO_IR_GLCD_ATTRIBUTE        __ISR(_GLCD_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_GLCD_PRIO

#define AO_IR_GLCD_PRIO             (4)

#endif

#ifndef AO_IR_GLCD_SUBPRIO

#define AO_IR_GLCD_SUBPRIO          (0)

#endif

#ifndef ao_ir_glcd_disable

#define ao_ir_glcd_disable()        { IEC6CLR = _IEC6_GLCDIE_MASK; }

#endif

#ifndef ao_ir_glcd_enable

#define ao_ir_glcd_enable()         { IEC6SET = _IEC6_GLCDIE_MASK; }

#endif

#ifndef ao_ir_glcd_is_enabled

#define ao_ir_glcd_is_enabled()     ((IEC6 & _IEC6_GLCDIE_MASK) ? true : false)

#endif

#ifndef ao_ir_glcd_is_pending

#define ao_ir_glcd_is_pending()     ((IFS6 & _IFS6_GLCDIF_MASK) ? true : false)

#endif

#ifndef ao_ir_glcd_reply

#define ao_ir_glcd_reply()          { IFS6CLR = _IFS6_GLCDIF_MASK; }

#endif

#ifndef ao_ir_glcd_request

#define ao_ir_glcd_request()        { IFS6SET = _IFS6_GLCDIF_MASK; }

#endif

