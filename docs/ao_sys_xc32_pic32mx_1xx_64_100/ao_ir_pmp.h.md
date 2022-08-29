---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mx_1xx_64_100/ao_ir_pmp.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mx_1xx_64_100/ao_ir_pmp.h/ 
subtitle: "<code>ao_sys_xc32_pic32mx_1xx_64_100</code>"
title: "<code>ao_ir_pmp.h</code>"
toc: true
---

#ifndef AO_IR_PMP_ATTRIBUTE

#define AO_IR_PMP_ATTRIBUTE         __ISR(_PMP_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_PMP_PRIO

#define AO_IR_PMP_PRIO              (4)

#endif

#ifndef AO_IR_PMP_SUBPRIO

#define AO_IR_PMP_SUBPRIO           (0)

#endif

#ifndef ao_ir_pmp_disable

#define ao_ir_pmp_disable()         { IEC1CLR = _IEC1_PMPIE_MASK; }

#endif

#ifndef ao_ir_pmp_enable

#define ao_ir_pmp_enable()          { IEC1SET = _IEC1_PMPIE_MASK; }

#endif

#ifndef ao_ir_pmp_is_enabled

#define ao_ir_pmp_is_enabled()      ((IEC1 & _IEC1_PMPIE_MASK) ? true : false)

#endif

#ifndef ao_ir_pmp_is_pending

#define ao_ir_pmp_is_pending()      ((IFS1 & _IFS1_PMPIF_MASK) ? true : false)

#endif

#ifndef ao_ir_pmp_reply

#define ao_ir_pmp_reply()           { IFS1CLR = _IFS1_PMPIF_MASK; }

#endif

#ifndef ao_ir_pmp_request

#define ao_ir_pmp_request()         { IFS1SET = _IFS1_PMPIF_MASK; }

#endif

#ifndef ao_ir_pmpe_disable

#define ao_ir_pmpe_disable()        { IEC1CLR = _IEC1_PMPEIE_MASK; }

#endif

#ifndef ao_ir_pmpe_enable

#define ao_ir_pmpe_enable()         { IEC1SET = _IEC1_PMPEIE_MASK; }

#endif

#ifndef ao_ir_pmpe_is_enabled

#define ao_ir_pmpe_is_enabled()     ((IEC1 & _IEC1_PMPEIE_MASK) ? true : false)

#endif

#ifndef ao_ir_pmpe_is_pending

#define ao_ir_pmpe_is_pending()     ((IFS1 & _IFS1_PMPEIF_MASK) ? true : false)

#endif

#ifndef ao_ir_pmpe_reply

#define ao_ir_pmpe_reply()          { IFS1CLR = _IFS1_PMPEIF_MASK; }

#endif

#ifndef ao_ir_pmpe_request

#define ao_ir_pmpe_request()        { IFS1SET = _IFS1_PMPEIF_MASK; }

#endif

