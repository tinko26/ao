---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mx_1xx_xlp/ao_ir_rtcc.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mx_1xx_xlp/ao_ir_rtcc.h/ 
subtitle: "<code>ao_sys_xc32_pic32mx_1xx_xlp</code>"
title: "<code>ao_ir_rtcc.h</code>"
toc: true
---

#ifndef AO_IR_RTCC_ATTRIBUTE

#define AO_IR_RTCC_ATTRIBUTE        __ISR(_RTCC_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_RTCC_PRIO

#define AO_IR_RTCC_PRIO             (4)

#endif

#ifndef AO_IR_RTCC_SUBPRIO

#define AO_IR_RTCC_SUBPRIO          (0)

#endif

#ifndef ao_ir_rtcc_disable

#define ao_ir_rtcc_disable()        { IEC0CLR = _IEC0_RTCCIE_MASK; }

#endif

#ifndef ao_ir_rtcc_enable

#define ao_ir_rtcc_enable()         { IEC0SET = _IEC0_RTCCIE_MASK; }

#endif

#ifndef ao_ir_rtcc_is_enabled

#define ao_ir_rtcc_is_enabled()     ((IEC0 & _IEC0_RTCCIE_MASK) ? true : false)

#endif

#ifndef ao_ir_rtcc_is_pending

#define ao_ir_rtcc_is_pending()     ((IFS0 & _IFS0_RTCCIF_MASK) ? true : false)

#endif

#ifndef ao_ir_rtcc_reply

#define ao_ir_rtcc_reply()          { IFS0CLR = _IFS0_RTCCIF_MASK; }

#endif

#ifndef ao_ir_rtcc_request

#define ao_ir_rtcc_request()        { IFS0SET = _IFS0_RTCCIF_MASK; }

#endif

