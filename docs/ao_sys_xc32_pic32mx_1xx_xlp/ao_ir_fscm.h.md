---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32mx_1xx_xlp/ao_ir_fscm.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mx_1xx_xlp/ao_ir_fscm.h/ 
subtitle: "<code>ao_sys_xc32_pic32mx_1xx_xlp</code>"
title: "<code>ao_ir_fscm.h</code>"
toc: true
---

#ifndef AO_IR_FSCM_ATTRIBUTE

#define AO_IR_FSCM_ATTRIBUTE        __ISR(_FAIL_SAFE_MONITOR_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_FSCM_PRIO

#define AO_IR_FSCM_PRIO             (4)

#endif

#ifndef AO_IR_FSCM_SUBPRIO

#define AO_IR_FSCM_SUBPRIO          (0)

#endif

#ifndef ao_ir_fscm_disable

#define ao_ir_fscm_disable()        { IEC0CLR = _IEC0_FSCMIE_MASK; }

#endif

#ifndef ao_ir_fscm_enable

#define ao_ir_fscm_enable()         { IEC0SET = _IEC0_FSCMIE_MASK; }

#endif

#ifndef ao_ir_fscm_is_enabled

#define ao_ir_fscm_is_enabled()     ((IEC0 & _IEC0_FSCMIE_MASK) ? true : false)

#endif

#ifndef ao_ir_fscm_is_pending

#define ao_ir_fscm_is_pending()     ((IFS0 & _IFS0_FSCMIF_MASK) ? true : false)

#endif

#ifndef ao_ir_fscm_reply

#define ao_ir_fscm_reply()          { IFS0CLR = _IFS0_FSCMIF_MASK; }

#endif

#ifndef ao_ir_fscm_request

#define ao_ir_fscm_request()        { IFS0SET = _IFS0_FSCMIF_MASK; }

#endif

