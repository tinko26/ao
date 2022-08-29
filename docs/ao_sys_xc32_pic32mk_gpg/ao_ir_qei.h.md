---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32mk_gpg/ao_ir_qei.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mk_gpg/ao_ir_qei.h/ 
subtitle: "<code>ao_sys_xc32_pic32mk_gpg</code>"
title: "<code>ao_ir_qei.h</code>"
toc: true
---

```c
#ifndef AO_IR_QEI1_ATTRIBUTE

#define AO_IR_QEI1_ATTRIBUTE        __ISR(_QEI1_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_QEI1_PRIO

#define AO_IR_QEI1_PRIO             (4)

#endif

#ifndef AO_IR_QEI1_SUBPRIO

#define AO_IR_QEI1_SUBPRIO          (0)

#endif

#ifndef ao_ir_qei1_disable

#define ao_ir_qei1_disable()        { IEC5CLR = _IEC5_QEI1IE_MASK; }

#endif

#ifndef ao_ir_qei1_enable

#define ao_ir_qei1_enable()         { IEC5SET = _IEC5_QEI1IE_MASK; }

#endif

#ifndef ao_ir_qei1_is_enabled

#define ao_ir_qei1_is_enabled()     ((IEC5 & _IEC5_QEI1IE_MASK) ? true : false)

#endif

#ifndef ao_ir_qei1_is_pending

#define ao_ir_qei1_is_pending()     ((IFS5 & _IFS5_QEI1IF_MASK) ? true : false)

#endif

#ifndef ao_ir_qei1_reply

#define ao_ir_qei1_reply()          { IFS5CLR = _IFS5_QEI1IF_MASK; }

#endif

#ifndef ao_ir_qei1_request

#define ao_ir_qei1_request()        { IFS5SET = _IFS5_QEI1IF_MASK; }

#endif

#ifndef AO_IR_QEI2_ATTRIBUTE

#define AO_IR_QEI2_ATTRIBUTE        __ISR(_QEI2_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_QEI2_PRIO

#define AO_IR_QEI2_PRIO             (4)

#endif

#ifndef AO_IR_QEI2_SUBPRIO

#define AO_IR_QEI2_SUBPRIO          (0)

#endif

#ifndef ao_ir_qei2_disable

#define ao_ir_qei2_disable()        { IEC5CLR = _IEC5_QEI2IE_MASK; }

#endif

#ifndef ao_ir_qei2_enable

#define ao_ir_qei2_enable()         { IEC5SET = _IEC5_QEI2IE_MASK; }

#endif

#ifndef ao_ir_qei2_is_enabled

#define ao_ir_qei2_is_enabled()     ((IEC5 & _IEC5_QEI2IE_MASK) ? true : false)

#endif

#ifndef ao_ir_qei2_is_pending

#define ao_ir_qei2_is_pending()     ((IFS5 & _IFS5_QEI2IF_MASK) ? true : false)

#endif

#ifndef ao_ir_qei2_reply

#define ao_ir_qei2_reply()          { IFS5CLR = _IFS5_QEI2IF_MASK; }

#endif

#ifndef ao_ir_qei2_request

#define ao_ir_qei2_request()        { IFS5SET = _IFS5_QEI2IF_MASK; }

#endif

#ifndef AO_IR_QEI3_ATTRIBUTE

#define AO_IR_QEI3_ATTRIBUTE        __ISR(_QEI3_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_QEI3_PRIO

#define AO_IR_QEI3_PRIO             (4)

#endif

#ifndef AO_IR_QEI3_SUBPRIO

#define AO_IR_QEI3_SUBPRIO          (0)

#endif

#ifndef ao_ir_qei3_disable

#define ao_ir_qei3_disable()        { IEC5CLR = _IEC5_QEI3IE_MASK; }

#endif

#ifndef ao_ir_qei3_enable

#define ao_ir_qei3_enable()         { IEC5SET = _IEC5_QEI3IE_MASK; }

#endif

#ifndef ao_ir_qei3_is_enabled

#define ao_ir_qei3_is_enabled()     ((IEC5 & _IEC5_QEI3IE_MASK) ? true : false)

#endif

#ifndef ao_ir_qei3_is_pending

#define ao_ir_qei3_is_pending()     ((IFS5 & _IFS5_QEI3IF_MASK) ? true : false)

#endif

#ifndef ao_ir_qei3_reply

#define ao_ir_qei3_reply()          { IFS5CLR = _IFS5_QEI3IF_MASK; }

#endif

#ifndef ao_ir_qei3_request

#define ao_ir_qei3_request()        { IFS5SET = _IFS5_QEI3IF_MASK; }

#endif

```
