---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mx_3xx/ao_ir_i2c.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mx_3xx/ao_ir_i2c.h/ 
subtitle: "ao_sys_xc32_pic32mx_3xx"
title: "ao_ir_i2c.h"
toc: true
---

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

#ifndef AO_IR_I2C1_ATTRIBUTE

#define AO_IR_I2C1_ATTRIBUTE        __ISR(_I2C_1_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_I2C1_PRIO

#define AO_IR_I2C1_PRIO             (4)

#endif

#ifndef AO_IR_I2C1_SUBPRIO

#define AO_IR_I2C1_SUBPRIO          (0)

#endif

#ifndef ao_ir_i2c1b_disable

#define ao_ir_i2c1b_disable()       { IEC0CLR = _IEC0_I2C1BIE_MASK; }

#endif

#ifndef ao_ir_i2c1b_enable

#define ao_ir_i2c1b_enable()        { IEC0SET = _IEC0_I2C1BIE_MASK; }

#endif

#ifndef ao_ir_i2c1b_is_enabled

#define ao_ir_i2c1b_is_enabled()    ((IEC0 & _IEC0_I2C1BIE_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c1b_is_pending

#define ao_ir_i2c1b_is_pending()    ((IFS0 & _IFS0_I2C1BIF_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c1b_reply

#define ao_ir_i2c1b_reply()         { IFS0CLR = _IFS0_I2C1BIF_MASK; }

#endif

#ifndef ao_ir_i2c1b_request

#define ao_ir_i2c1b_request()       { IFS0SET = _IFS0_I2C1BIF_MASK; }

#endif

#ifndef ao_ir_i2c1m_disable

#define ao_ir_i2c1m_disable()       { IEC0CLR = _IEC0_I2C1MIE_MASK; }

#endif

#ifndef ao_ir_i2c1m_enable

#define ao_ir_i2c1m_enable()        { IEC0SET = _IEC0_I2C1MIE_MASK; }

#endif

#ifndef ao_ir_i2c1m_is_enabled

#define ao_ir_i2c1m_is_enabled()    ((IEC0 & _IEC0_I2C1MIE_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c1m_is_pending

#define ao_ir_i2c1m_is_pending()    ((IFS0 & _IFS0_I2C1MIF_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c1m_reply

#define ao_ir_i2c1m_reply()         { IFS0CLR = _IFS0_I2C1MIF_MASK; }

#endif

#ifndef ao_ir_i2c1m_request

#define ao_ir_i2c1m_request()       { IFS0SET = _IFS0_I2C1MIF_MASK; }

#endif

#ifndef ao_ir_i2c1s_disable

#define ao_ir_i2c1s_disable()       { IEC0CLR = _IEC0_I2C1SIE_MASK; }

#endif

#ifndef ao_ir_i2c1s_enable

#define ao_ir_i2c1s_enable()        { IEC0SET = _IEC0_I2C1SIE_MASK; }

#endif

#ifndef ao_ir_i2c1s_is_enabled

#define ao_ir_i2c1s_is_enabled()    ((IEC0 & _IEC0_I2C1SIE_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c1s_is_pending

#define ao_ir_i2c1s_is_pending()    ((IFS0 & _IFS0_I2C1SIF_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c1s_reply

#define ao_ir_i2c1s_reply()         { IFS0CLR = _IFS0_I2C1SIF_MASK; }

#endif

#ifndef ao_ir_i2c1s_request

#define ao_ir_i2c1s_request()       { IFS0SET = _IFS0_I2C1SIF_MASK; }

#endif

#ifndef AO_IR_I2C2_ATTRIBUTE

#define AO_IR_I2C2_ATTRIBUTE        __ISR(_I2C_2_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_I2C2_PRIO

#define AO_IR_I2C2_PRIO             (4)

#endif

#ifndef AO_IR_I2C2_SUBPRIO

#define AO_IR_I2C2_SUBPRIO          (0)

#endif

#ifndef ao_ir_i2c2b_disable

#define ao_ir_i2c2b_disable()       { IEC1CLR = _IEC1_I2C2BIE_MASK; }

#endif

#ifndef ao_ir_i2c2b_enable

#define ao_ir_i2c2b_enable()        { IEC1SET = _IEC1_I2C2BIE_MASK; }

#endif

#ifndef ao_ir_i2c2b_is_enabled

#define ao_ir_i2c2b_is_enabled()    ((IEC1 & _IEC1_I2C2BIE_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c2b_is_pending

#define ao_ir_i2c2b_is_pending()    ((IFS1 & _IFS1_I2C2BIF_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c2b_reply

#define ao_ir_i2c2b_reply()         { IFS1CLR = _IFS1_I2C2BIF_MASK; }

#endif

#ifndef ao_ir_i2c2b_request

#define ao_ir_i2c2b_request()       { IFS1SET = _IFS1_I2C2BIF_MASK; }

#endif

#ifndef ao_ir_i2c2m_disable

#define ao_ir_i2c2m_disable()       { IEC1CLR = _IEC1_I2C2MIE_MASK; }

#endif

#ifndef ao_ir_i2c2m_enable

#define ao_ir_i2c2m_enable()        { IEC1SET = _IEC1_I2C2MIE_MASK; }

#endif

#ifndef ao_ir_i2c2m_is_enabled

#define ao_ir_i2c2m_is_enabled()    ((IEC1 & _IEC1_I2C2MIE_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c2m_is_pending

#define ao_ir_i2c2m_is_pending()    ((IFS1 & _IFS1_I2C2MIF_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c2m_reply

#define ao_ir_i2c2m_reply()         { IFS1CLR = _IFS1_I2C2MIF_MASK; }

#endif

#ifndef ao_ir_i2c2m_request

#define ao_ir_i2c2m_request()       { IFS1SET = _IFS1_I2C2MIF_MASK; }

#endif

#ifndef ao_ir_i2c2s_disable

#define ao_ir_i2c2s_disable()       { IEC1CLR = _IEC1_I2C2SIE_MASK; }

#endif

#ifndef ao_ir_i2c2s_enable

#define ao_ir_i2c2s_enable()        { IEC1SET = _IEC1_I2C2SIE_MASK; }

#endif

#ifndef ao_ir_i2c2s_is_enabled

#define ao_ir_i2c2s_is_enabled()    ((IEC1 & _IEC1_I2C2SIE_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c2s_is_pending

#define ao_ir_i2c2s_is_pending()    ((IFS1 & _IFS1_I2C2SIF_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c2s_reply

#define ao_ir_i2c2s_reply()         { IFS1CLR = _IFS1_I2C2SIF_MASK; }

#endif

#ifndef ao_ir_i2c2s_request

#define ao_ir_i2c2s_request()       { IFS1SET = _IFS1_I2C2SIF_MASK; }

#endif

```
