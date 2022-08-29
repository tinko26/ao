---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mx_1xx_xlp/ao_ir_cmp.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mx_1xx_xlp/ao_ir_cmp.h/ 
subtitle: "<code>ao_sys_xc32_pic32mx_1xx_xlp</code>"
title: "<code>ao_ir_cmp.h</code>"
toc: true
---

#ifndef AO_IR_CMP1_ATTRIBUTE

#define AO_IR_CMP1_ATTRIBUTE        __ISR(_COMPARATOR_1_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_CMP1_PRIO

#define AO_IR_CMP1_PRIO             (4)

#endif

#ifndef AO_IR_CMP1_SUBPRIO

#define AO_IR_CMP1_SUBPRIO          (0)

#endif

#ifndef ao_ir_cmp1_disable

#define ao_ir_cmp1_disable()        { IEC1CLR = _IEC1_CMP1IE_MASK; }

#endif

#ifndef ao_ir_cmp1_enable

#define ao_ir_cmp1_enable()         { IEC1SET = _IEC1_CMP1IE_MASK; }

#endif

#ifndef ao_ir_cmp1_is_enabled

#define ao_ir_cmp1_is_enabled()     ((IEC1 & _IEC1_CMP1IE_MASK) ? true : false)

#endif

#ifndef ao_ir_cmp1_is_pending

#define ao_ir_cmp1_is_pending()     ((IFS1 & _IFS1_CMP1IF_MASK) ? true : false)

#endif

#ifndef ao_ir_cmp1_reply

#define ao_ir_cmp1_reply()          { IFS1CLR = _IFS1_CMP1IF_MASK; }

#endif

#ifndef ao_ir_cmp1_request

#define ao_ir_cmp1_request()        { IFS1SET = _IFS1_CMP1IF_MASK; }

#endif

#ifndef AO_IR_CMP2_ATTRIBUTE

#define AO_IR_CMP2_ATTRIBUTE        __ISR(_COMPARATOR_2_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_CMP2_PRIO

#define AO_IR_CMP2_PRIO             (4)

#endif

#ifndef AO_IR_CMP2_SUBPRIO

#define AO_IR_CMP2_SUBPRIO          (0)

#endif

#ifndef ao_ir_cmp2_disable

#define ao_ir_cmp2_disable()        { IEC1CLR = _IEC1_CMP2IE_MASK; }

#endif

#ifndef ao_ir_cmp2_enable

#define ao_ir_cmp2_enable()         { IEC1SET = _IEC1_CMP2IE_MASK; }

#endif

#ifndef ao_ir_cmp2_is_enabled

#define ao_ir_cmp2_is_enabled()     ((IEC1 & _IEC1_CMP2IE_MASK) ? true : false)

#endif

#ifndef ao_ir_cmp2_is_pending

#define ao_ir_cmp2_is_pending()     ((IFS1 & _IFS1_CMP2IF_MASK) ? true : false)

#endif

#ifndef ao_ir_cmp2_reply

#define ao_ir_cmp2_reply()          { IFS1CLR = _IFS1_CMP2IF_MASK; }

#endif

#ifndef ao_ir_cmp2_request

#define ao_ir_cmp2_request()        { IFS1SET = _IFS1_CMP2IF_MASK; }

#endif

#ifndef AO_IR_CMP3_ATTRIBUTE

#define AO_IR_CMP3_ATTRIBUTE        __ISR(_COMPARATOR_3_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_CMP3_PRIO

#define AO_IR_CMP3_PRIO             (4)

#endif

#ifndef AO_IR_CMP3_SUBPRIO

#define AO_IR_CMP3_SUBPRIO          (0)

#endif

#ifndef ao_ir_cmp3_disable

#define ao_ir_cmp3_disable()        { IEC1CLR = _IEC1_CMP3IE_MASK; }

#endif

#ifndef ao_ir_cmp3_enable

#define ao_ir_cmp3_enable()         { IEC1SET = _IEC1_CMP3IE_MASK; }

#endif

#ifndef ao_ir_cmp3_is_enabled

#define ao_ir_cmp3_is_enabled()     ((IEC1 & _IEC1_CMP3IE_MASK) ? true : false)

#endif

#ifndef ao_ir_cmp3_is_pending

#define ao_ir_cmp3_is_pending()     ((IFS1 & _IFS1_CMP3IF_MASK) ? true : false)

#endif

#ifndef ao_ir_cmp3_reply

#define ao_ir_cmp3_reply()          { IFS1CLR = _IFS1_CMP3IF_MASK; }

#endif

#ifndef ao_ir_cmp3_request

#define ao_ir_cmp3_request()        { IFS1SET = _IFS1_CMP3IF_MASK; }

#endif

