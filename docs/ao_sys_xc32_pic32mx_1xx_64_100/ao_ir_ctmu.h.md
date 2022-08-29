---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mx_1xx_64_100/ao_ir_ctmu.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mx_1xx_64_100/ao_ir_ctmu.h/ 
subtitle: "<code>ao_sys_xc32_pic32mx_1xx_64_100</code>"
title: "<code>ao_ir_ctmu.h</code>"
toc: true
---

#ifndef AO_IR_CTMU_ATTRIBUTE

#define AO_IR_CTMU_ATTRIBUTE        __ISR(_CTMU_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_CTMU_PRIO

#define AO_IR_CTMU_PRIO             (4)

#endif

#ifndef AO_IR_CTMU_SUBPRIO

#define AO_IR_CTMU_SUBPRIO          (0)

#endif

#ifndef ao_ir_ctmu_disable

#define ao_ir_ctmu_disable()        { IEC2CLR = _IEC2_CTMUIE_MASK; }

#endif

#ifndef ao_ir_ctmu_enable

#define ao_ir_ctmu_enable()         { IEC2SET = _IEC2_CTMUIE_MASK; }

#endif

#ifndef ao_ir_ctmu_is_enabled

#define ao_ir_ctmu_is_enabled()     ((IEC2 & _IEC2_CTMUIE_MASK) ? true : false)

#endif

#ifndef ao_ir_ctmu_is_pending

#define ao_ir_ctmu_is_pending()     ((IFS2 & _IFS2_CTMUIF_MASK) ? true : false)

#endif

#ifndef ao_ir_ctmu_reply

#define ao_ir_ctmu_reply()          { IFS2CLR = _IFS2_CTMUIF_MASK; }

#endif

#ifndef ao_ir_ctmu_request

#define ao_ir_ctmu_request()        { IFS2SET = _IFS2_CTMUIF_MASK; }

#endif

