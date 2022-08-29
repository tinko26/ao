---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mk_gpg/ao_ir_sb.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mk_gpg/ao_ir_sb.h/ 
subtitle: "<code>ao_sys_xc32_pic32mk_gpg</code>"
title: "<code>ao_ir_sb.h</code>"
toc: true
---

#ifndef AO_IR_SB_ATTRIBUTE

#define AO_IR_SB_ATTRIBUTE      __ISR(_SYSTEM_BUS_PROTECTION_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_SB_PRIO

#define AO_IR_SB_PRIO           (4)

#endif

#ifndef AO_IR_SB_SUBPRIO

#define AO_IR_SB_SUBPRIO        (0)

#endif

#ifndef ao_ir_sb_disable

#define ao_ir_sb_disable()      { IEC7CLR = _IEC7_SBIE_MASK; }

#endif

#ifndef ao_ir_sb_enable

#define ao_ir_sb_enable()       { IEC7SET = _IEC7_SBIE_MASK; }

#endif

#ifndef ao_ir_sb_is_enabled

#define ao_ir_sb_is_enabled()   ((IEC7 & _IEC7_SBIE_MASK) ? true : false)

#endif

#ifndef ao_ir_sb_is_pending

#define ao_ir_sb_is_pending()   ((IFS7 & _IFS7_SBIF_MASK) ? true : false)

#endif

#ifndef ao_ir_sb_reply

#define ao_ir_sb_reply()        { IFS7CLR = _IFS7_SBIF_MASK; }

#endif

#ifndef ao_ir_sb_request

#define ao_ir_sb_request()      { IFS7SET = _IFS7_SBIF_MASK; }

#endif

