---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mx_5xx/ao_ir_i2c.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32_pic32mx_5xx/ao_ir_i2c.h/ 
subtitle: ""
title: "ao_ir_i2c.h"
toc: true
---

# Overview

...

# Includes

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

#ifndef AO_IR_I2C3_ATTRIBUTE

#define AO_IR_I2C3_ATTRIBUTE        __ISR(_I2C_3_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_I2C3_PRIO

#define AO_IR_I2C3_PRIO             (4)

#endif

#ifndef AO_IR_I2C3_SUBPRIO

#define AO_IR_I2C3_SUBPRIO          (0)

#endif

#ifndef ao_ir_i2c3b_disable

#define ao_ir_i2c3b_disable()       { IEC0CLR = _IEC0_I2C3BIE_MASK; }

#endif

#ifndef ao_ir_i2c3b_enable

#define ao_ir_i2c3b_enable()        { IEC0SET = _IEC0_I2C3BIE_MASK; }

#endif

#ifndef ao_ir_i2c3b_is_enabled

#define ao_ir_i2c3b_is_enabled()    ((IEC0 & _IEC0_I2C3BIE_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c3b_is_pending

#define ao_ir_i2c3b_is_pending()    ((IFS0 & _IFS0_I2C3BIF_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c3b_reply

#define ao_ir_i2c3b_reply()         { IFS0CLR = _IFS0_I2C3BIF_MASK; }

#endif

#ifndef ao_ir_i2c3b_request

#define ao_ir_i2c3b_request()       { IFS0SET = _IFS0_I2C3BIF_MASK; }

#endif

#ifndef ao_ir_i2c3m_disable

#define ao_ir_i2c3m_disable()       { IEC0CLR = _IEC0_I2C3MIE_MASK; }

#endif

#ifndef ao_ir_i2c3m_enable

#define ao_ir_i2c3m_enable()        { IEC0SET = _IEC0_I2C3MIE_MASK; }

#endif

#ifndef ao_ir_i2c3m_is_enabled

#define ao_ir_i2c3m_is_enabled()    ((IEC0 & _IEC0_I2C3MIE_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c3m_is_pending

#define ao_ir_i2c3m_is_pending()    ((IFS0 & _IFS0_I2C3MIF_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c3m_reply

#define ao_ir_i2c3m_reply()         { IFS0CLR = _IFS0_I2C3MIF_MASK; }

#endif

#ifndef ao_ir_i2c3m_request

#define ao_ir_i2c3m_request()       { IFS0SET = _IFS0_I2C3MIF_MASK; }

#endif

#ifndef ao_ir_i2c3s_disable

#define ao_ir_i2c3s_disable()       { IEC0CLR = _IEC0_I2C3SIE_MASK; }

#endif

#ifndef ao_ir_i2c3s_enable

#define ao_ir_i2c3s_enable()        { IEC0SET = _IEC0_I2C3SIE_MASK; }

#endif

#ifndef ao_ir_i2c3s_is_enabled

#define ao_ir_i2c3s_is_enabled()    ((IEC0 & _IEC0_I2C3SIE_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c3s_is_pending

#define ao_ir_i2c3s_is_pending()    ((IFS0 & _IFS0_I2C3SIF_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c3s_reply

#define ao_ir_i2c3s_reply()         { IFS0CLR = _IFS0_I2C3SIF_MASK; }

#endif

#ifndef ao_ir_i2c3s_request

#define ao_ir_i2c3s_request()       { IFS0SET = _IFS0_I2C3SIF_MASK; }

#endif

#ifndef AO_IR_I2C4_ATTRIBUTE

#define AO_IR_I2C4_ATTRIBUTE        __ISR(_I2C_4_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_I2C4_PRIO

#define AO_IR_I2C4_PRIO             (4)

#endif

#ifndef AO_IR_I2C4_SUBPRIO

#define AO_IR_I2C4_SUBPRIO          (0)

#endif

#ifndef ao_ir_i2c4b_disable

#define ao_ir_i2c4b_disable()       { IEC1CLR = _IEC1_I2C4BIE_MASK; }

#endif

#ifndef ao_ir_i2c4b_enable

#define ao_ir_i2c4b_enable()        { IEC1SET = _IEC1_I2C4BIE_MASK; }

#endif

#ifndef ao_ir_i2c4b_is_enabled

#define ao_ir_i2c4b_is_enabled()    ((IEC1 & _IEC1_I2C4BIE_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c4b_is_pending

#define ao_ir_i2c4b_is_pending()    ((IFS1 & _IFS1_I2C4BIF_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c4b_reply

#define ao_ir_i2c4b_reply()         { IFS1CLR = _IFS1_I2C4BIF_MASK; }

#endif

#ifndef ao_ir_i2c4b_request

#define ao_ir_i2c4b_request()       { IFS1SET = _IFS1_I2C4BIF_MASK; }

#endif

#ifndef ao_ir_i2c4m_disable

#define ao_ir_i2c4m_disable()       { IEC1CLR = _IEC1_I2C4MIE_MASK; }

#endif

#ifndef ao_ir_i2c4m_enable

#define ao_ir_i2c4m_enable()        { IEC1SET = _IEC1_I2C4MIE_MASK; }

#endif

#ifndef ao_ir_i2c4m_is_enabled

#define ao_ir_i2c4m_is_enabled()    ((IEC1 & _IEC1_I2C4MIE_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c4m_is_pending

#define ao_ir_i2c4m_is_pending()    ((IFS1 & _IFS1_I2C4MIF_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c4m_reply

#define ao_ir_i2c4m_reply()         { IFS1CLR = _IFS1_I2C4MIF_MASK; }

#endif

#ifndef ao_ir_i2c4m_request

#define ao_ir_i2c4m_request()       { IFS1SET = _IFS1_I2C4MIF_MASK; }

#endif

#ifndef ao_ir_i2c4s_disable

#define ao_ir_i2c4s_disable()       { IEC1CLR = _IEC1_I2C4SIE_MASK; }

#endif

#ifndef ao_ir_i2c4s_enable

#define ao_ir_i2c4s_enable()        { IEC1SET = _IEC1_I2C4SIE_MASK; }

#endif

#ifndef ao_ir_i2c4s_is_enabled

#define ao_ir_i2c4s_is_enabled()    ((IEC1 & _IEC1_I2C4SIE_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c4s_is_pending

#define ao_ir_i2c4s_is_pending()    ((IFS1 & _IFS1_I2C4SIF_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c4s_reply

#define ao_ir_i2c4s_reply()         { IFS1CLR = _IFS1_I2C4SIF_MASK; }

#endif

#ifndef ao_ir_i2c4s_request

#define ao_ir_i2c4s_request()       { IFS1SET = _IFS1_I2C4SIF_MASK; }

#endif

#ifndef AO_IR_I2C5_ATTRIBUTE

#define AO_IR_I2C5_ATTRIBUTE        __ISR(_I2C_5_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_I2C5_PRIO

#define AO_IR_I2C5_PRIO             (4)

#endif

#ifndef AO_IR_I2C5_SUBPRIO

#define AO_IR_I2C5_SUBPRIO          (0)

#endif

#ifndef ao_ir_i2c5b_disable

#define ao_ir_i2c5b_disable()       { IEC1CLR = _IEC1_I2C5BIE_MASK; }

#endif

#ifndef ao_ir_i2c5b_enable

#define ao_ir_i2c5b_enable()        { IEC1SET = _IEC1_I2C5BIE_MASK; }

#endif

#ifndef ao_ir_i2c5b_is_enabled

#define ao_ir_i2c5b_is_enabled()    ((IEC1 & _IEC1_I2C5BIE_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c5b_is_pending

#define ao_ir_i2c5b_is_pending()    ((IFS1 & _IFS1_I2C5BIF_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c5b_reply

#define ao_ir_i2c5b_reply()         { IFS1CLR = _IFS1_I2C5BIF_MASK; }

#endif

#ifndef ao_ir_i2c5b_request

#define ao_ir_i2c5b_request()       { IFS1SET = _IFS1_I2C5BIF_MASK; }

#endif

#ifndef ao_ir_i2c5m_disable

#define ao_ir_i2c5m_disable()       { IEC1CLR = _IEC1_I2C5MIE_MASK; }

#endif

#ifndef ao_ir_i2c5m_enable

#define ao_ir_i2c5m_enable()        { IEC1SET = _IEC1_I2C5MIE_MASK; }

#endif

#ifndef ao_ir_i2c5m_is_enabled

#define ao_ir_i2c5m_is_enabled()    ((IEC1 & _IEC1_I2C5MIE_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c5m_is_pending

#define ao_ir_i2c5m_is_pending()    ((IFS1 & _IFS1_I2C5MIF_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c5m_reply

#define ao_ir_i2c5m_reply()         { IFS1CLR = _IFS1_I2C5MIF_MASK; }

#endif

#ifndef ao_ir_i2c5m_request

#define ao_ir_i2c5m_request()       { IFS1SET = _IFS1_I2C5MIF_MASK; }

#endif

#ifndef ao_ir_i2c5s_disable

#define ao_ir_i2c5s_disable()       { IEC1CLR = _IEC1_I2C5SIE_MASK; }

#endif

#ifndef ao_ir_i2c5s_enable

#define ao_ir_i2c5s_enable()        { IEC1SET = _IEC1_I2C5SIE_MASK; }

#endif

#ifndef ao_ir_i2c5s_is_enabled

#define ao_ir_i2c5s_is_enabled()    ((IEC1 & _IEC1_I2C5SIE_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c5s_is_pending

#define ao_ir_i2c5s_is_pending()    ((IFS1 & _IFS1_I2C5SIF_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c5s_reply

#define ao_ir_i2c5s_reply()         { IFS1CLR = _IFS1_I2C5SIF_MASK; }

#endif

#ifndef ao_ir_i2c5s_request

#define ao_ir_i2c5s_request()       { IFS1SET = _IFS1_I2C5SIF_MASK; }

#endif

```
