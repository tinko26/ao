---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32mz_ec/ao_ir_cmp.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mz_ec/ao_ir_cmp.h/ 
subtitle: "<code>ao_sys_xc32_pic32mz_ec</code>"
title: "<code>ao_ir_cmp.h</code>"
toc: true
---

#ifndef AO_IR_CMP1_ATTRIBUTE

#define AO_IR_CMP1_ATTRIBUTE        __ISR(_COMPARATOR_1_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_CMP1_PRIO

#define AO_IR_CMP1_PRIO             (4)

#endif

#ifndef AO_IR_CMP1_SUBPRIO

#define AO_IR_CMP1_SUBPRIO          (0)

#endif

#ifndef ao_ir_cmp1_disable

#define ao_ir_cmp1_disable()        { IEC4CLR = _IEC4_CMP1IE_MASK; }

#endif

#ifndef ao_ir_cmp1_enable

#define ao_ir_cmp1_enable()         { IEC4SET = _IEC4_CMP1IE_MASK; }

#endif

#ifndef ao_ir_cmp1_is_enabled

#define ao_ir_cmp1_is_enabled()     ((IEC4 & _IEC4_CMP1IE_MASK) ? true : false)

#endif

#ifndef ao_ir_cmp1_is_pending

#define ao_ir_cmp1_is_pending()     ((IFS4 & _IFS4_CMP1IF_MASK) ? true : false)

#endif

#ifndef ao_ir_cmp1_reply

#define ao_ir_cmp1_reply()          { IFS4CLR = _IFS4_CMP1IF_MASK; }

#endif

#ifndef ao_ir_cmp1_request

#define ao_ir_cmp1_request()        { IFS4SET = _IFS4_CMP1IF_MASK; }

#endif

#ifndef AO_IR_CMP2_ATTRIBUTE

#define AO_IR_CMP2_ATTRIBUTE        __ISR(_COMPARATOR_2_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_CMP2_PRIO

#define AO_IR_CMP2_PRIO             (4)

#endif

#ifndef AO_IR_CMP2_SUBPRIO

#define AO_IR_CMP2_SUBPRIO          (0)

#endif

#ifndef ao_ir_cmp2_disable

#define ao_ir_cmp2_disable()        { IEC4CLR = _IEC4_CMP2IE_MASK; }

#endif

#ifndef ao_ir_cmp2_enable

#define ao_ir_cmp2_enable()         { IEC4SET = _IEC4_CMP2IE_MASK; }

#endif

#ifndef ao_ir_cmp2_is_enabled

#define ao_ir_cmp2_is_enabled()     ((IEC4 & _IEC4_CMP2IE_MASK) ? true : false)

#endif

#ifndef ao_ir_cmp2_is_pending

#define ao_ir_cmp2_is_pending()     ((IFS4 & _IFS4_CMP2IF_MASK) ? true : false)

#endif

#ifndef ao_ir_cmp2_reply

#define ao_ir_cmp2_reply()          { IFS4CLR = _IFS4_CMP2IF_MASK; }

#endif

#ifndef ao_ir_cmp2_request

#define ao_ir_cmp2_request()        { IFS4SET = _IFS4_CMP2IF_MASK; }

#endif

