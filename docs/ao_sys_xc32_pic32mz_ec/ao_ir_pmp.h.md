---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32mz_ec/ao_ir_pmp.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mz_ec/ao_ir_pmp.h/ 
subtitle: "<code>ao_sys_xc32_pic32mz_ec</code>"
title: "<code>ao_ir_pmp.h</code>"
toc: true
---

#ifndef AO_IR_PMP_ATTRIBUTE

#define AO_IR_PMP_ATTRIBUTE         __ISR(_PMP_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_PMP_PRIO

#define AO_IR_PMP_PRIO              (4)

#endif

#ifndef AO_IR_PMP_SUBPRIO

#define AO_IR_PMP_SUBPRIO           (0)

#endif

#ifndef ao_ir_pmp_disable

#define ao_ir_pmp_disable()         { IEC4CLR = _IEC4_PMPIE_MASK; }

#endif

#ifndef ao_ir_pmp_enable

#define ao_ir_pmp_enable()          { IEC4SET = _IEC4_PMPIE_MASK; }

#endif

#ifndef ao_ir_pmp_is_enabled

#define ao_ir_pmp_is_enabled()      ((IEC4 & _IEC4_PMPIE_MASK) ? true : false)

#endif

#ifndef ao_ir_pmp_is_pending

#define ao_ir_pmp_is_pending()      ((IFS4 & _IFS4_PMPIF_MASK) ? true : false)

#endif

#ifndef ao_ir_pmp_reply

#define ao_ir_pmp_reply()           { IFS4CLR = _IFS4_PMPIF_MASK; }

#endif

#ifndef ao_ir_pmp_request

#define ao_ir_pmp_request()         { IFS4SET = _IFS4_PMPIF_MASK; }

#endif

#ifndef AO_IR_PMPE_ATTRIBUTE

#define AO_IR_PMPE_ATTRIBUTE        __ISR(_PMP_ERROR_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_PMPE_PRIO

#define AO_IR_PMPE_PRIO             (4)

#endif

#ifndef AO_IR_PMPE_SUBPRIO

#define AO_IR_PMPE_SUBPRIO          (0)

#endif

#ifndef ao_ir_pmpe_disable

#define ao_ir_pmpe_disable()        { IEC4CLR = _IEC4_PMPEIE_MASK; }

#endif

#ifndef ao_ir_pmpe_enable

#define ao_ir_pmpe_enable()         { IEC4SET = _IEC4_PMPEIE_MASK; }

#endif

#ifndef ao_ir_pmpe_is_enabled

#define ao_ir_pmpe_is_enabled()     ((IEC4 & _IEC4_PMPEIE_MASK) ? true : false)

#endif

#ifndef ao_ir_pmpe_is_pending

#define ao_ir_pmpe_is_pending()     ((IFS4 & _IFS4_PMPEIF_MASK) ? true : false)

#endif

#ifndef ao_ir_pmpe_reply

#define ao_ir_pmpe_reply()          { IFS4CLR = _IFS4_PMPEIF_MASK; }

#endif

#ifndef ao_ir_pmpe_request

#define ao_ir_pmpe_request()        { IFS4SET = _IFS4_PMPEIF_MASK; }

#endif

