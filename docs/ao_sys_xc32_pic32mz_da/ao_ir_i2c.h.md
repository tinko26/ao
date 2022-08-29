---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32mz_da/ao_ir_i2c.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mz_da/ao_ir_i2c.h/ 
subtitle: "<code>ao_sys_xc32_pic32mz_da</code>"
title: "<code>ao_ir_i2c.h</code>"
toc: true
---

```c
#ifndef AO_IR_I2C1B_ATTRIBUTE

#define AO_IR_I2C1B_ATTRIBUTE       __ISR(_I2C1_BUS_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_I2C1B_PRIO

#define AO_IR_I2C1B_PRIO            (4)

#endif

#ifndef AO_IR_I2C1B_SUBPRIO

#define AO_IR_I2C1B_SUBPRIO         (0)

#endif

#ifndef ao_ir_i2c1b_disable

#define ao_ir_i2c1b_disable()       { IEC3CLR = _IEC3_I2C1BIE_MASK; }

#endif

#ifndef ao_ir_i2c1b_enable

#define ao_ir_i2c1b_enable()        { IEC3SET = _IEC3_I2C1BIE_MASK; }

#endif

#ifndef ao_ir_i2c1b_is_enabled

#define ao_ir_i2c1b_is_enabled()    ((IEC3 & _IEC3_I2C1BIE_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c1b_is_pending

#define ao_ir_i2c1b_is_pending()    ((IFS3 & _IFS3_I2C1BIF_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c1b_reply

#define ao_ir_i2c1b_reply()         { IFS3CLR = _IFS3_I2C1BIF_MASK; }

#endif

#ifndef ao_ir_i2c1b_request

#define ao_ir_i2c1b_request()       { IFS3SET = _IFS3_I2C1BIF_MASK; }

#endif

#ifndef AO_IR_I2C1M_ATTRIBUTE

#define AO_IR_I2C1M_ATTRIBUTE       __ISR(_I2C1_MASTER_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_I2C1M_PRIO

#define AO_IR_I2C1M_PRIO            (4)

#endif

#ifndef AO_IR_I2C1M_SUBPRIO

#define AO_IR_I2C1M_SUBPRIO         (0)

#endif

#ifndef ao_ir_i2c1m_disable

#define ao_ir_i2c1m_disable()       { IEC3CLR = _IEC3_I2C1MIE_MASK; }

#endif

#ifndef ao_ir_i2c1m_enable

#define ao_ir_i2c1m_enable()        { IEC3SET = _IEC3_I2C1MIE_MASK; }

#endif

#ifndef ao_ir_i2c1m_is_enabled

#define ao_ir_i2c1m_is_enabled()    ((IEC3 & _IEC3_I2C1MIE_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c1m_is_pending

#define ao_ir_i2c1m_is_pending()    ((IFS3 & _IFS3_I2C1MIF_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c1m_reply

#define ao_ir_i2c1m_reply()         { IFS3CLR = _IFS3_I2C1MIF_MASK; }

#endif

#ifndef ao_ir_i2c1m_request

#define ao_ir_i2c1m_request()       { IFS3SET = _IFS3_I2C1MIF_MASK; }

#endif

#ifndef AO_IR_I2C1S_ATTRIBUTE

#define AO_IR_I2C1S_ATTRIBUTE       __ISR(_I2C1_SLAVE_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_I2C1S_PRIO

#define AO_IR_I2C1S_PRIO            (4)

#endif

#ifndef AO_IR_I2C1S_SUBPRIO

#define AO_IR_I2C1S_SUBPRIO         (0)

#endif

#ifndef ao_ir_i2c1s_disable

#define ao_ir_i2c1s_disable()       { IEC3CLR = _IEC3_I2C1SIE_MASK; }

#endif

#ifndef ao_ir_i2c1s_enable

#define ao_ir_i2c1s_enable()        { IEC3SET = _IEC3_I2C1SIE_MASK; }

#endif

#ifndef ao_ir_i2c1s_is_enabled

#define ao_ir_i2c1s_is_enabled()    ((IEC3 & _IEC3_I2C1SIE_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c1s_is_pending

#define ao_ir_i2c1s_is_pending()    ((IFS3 & _IFS3_I2C1SIF_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c1s_reply

#define ao_ir_i2c1s_reply()         { IFS3CLR = _IFS3_I2C1SIF_MASK; }

#endif

#ifndef ao_ir_i2c1s_request

#define ao_ir_i2c1s_request()       { IFS3SET = _IFS3_I2C1SIF_MASK; }

#endif

#ifndef AO_IR_I2C2B_ATTRIBUTE

#define AO_IR_I2C2B_ATTRIBUTE       __ISR(_I2C2_BUS_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_I2C2B_PRIO

#define AO_IR_I2C2B_PRIO            (4)

#endif

#ifndef AO_IR_I2C2B_SUBPRIO

#define AO_IR_I2C2B_SUBPRIO         (0)

#endif

#ifndef ao_ir_i2c2b_disable

#define ao_ir_i2c2b_disable()       { IEC4CLR = _IEC4_I2C2BIE_MASK; }

#endif

#ifndef ao_ir_i2c2b_enable

#define ao_ir_i2c2b_enable()        { IEC4SET = _IEC4_I2C2BIE_MASK; }

#endif

#ifndef ao_ir_i2c2b_is_enabled

#define ao_ir_i2c2b_is_enabled()    ((IEC4 & _IEC4_I2C2BIE_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c2b_is_pending

#define ao_ir_i2c2b_is_pending()    ((IFS4 & _IFS4_I2C2BIF_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c2b_reply

#define ao_ir_i2c2b_reply()         { IFS4CLR = _IFS4_I2C2BIF_MASK; }

#endif

#ifndef ao_ir_i2c2b_request

#define ao_ir_i2c2b_request()       { IFS4SET = _IFS4_I2C2BIF_MASK; }

#endif

#ifndef AO_IR_I2C2M_ATTRIBUTE

#define AO_IR_I2C2M_ATTRIBUTE       __ISR(_I2C2_MASTER_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_I2C2M_PRIO

#define AO_IR_I2C2M_PRIO            (4)

#endif

#ifndef AO_IR_I2C2M_SUBPRIO

#define AO_IR_I2C2M_SUBPRIO         (0)

#endif

#ifndef ao_ir_i2c2m_disable

#define ao_ir_i2c2m_disable()       { IEC4CLR = _IEC4_I2C2MIE_MASK; }

#endif

#ifndef ao_ir_i2c2m_enable

#define ao_ir_i2c2m_enable()        { IEC4SET = _IEC4_I2C2MIE_MASK; }

#endif

#ifndef ao_ir_i2c2m_is_enabled

#define ao_ir_i2c2m_is_enabled()    ((IEC4 & _IEC4_I2C2MIE_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c2m_is_pending

#define ao_ir_i2c2m_is_pending()    ((IFS4 & _IFS4_I2C2MIF_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c2m_reply

#define ao_ir_i2c2m_reply()         { IFS4CLR = _IFS4_I2C2MIF_MASK; }

#endif

#ifndef ao_ir_i2c2m_request

#define ao_ir_i2c2m_request()       { IFS4SET = _IFS4_I2C2MIF_MASK; }

#endif

#ifndef AO_IR_I2C2S_ATTRIBUTE

#define AO_IR_I2C2S_ATTRIBUTE       __ISR(_I2C2_SLAVE_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_I2C2S_PRIO

#define AO_IR_I2C2S_PRIO            (4)

#endif

#ifndef AO_IR_I2C2S_SUBPRIO

#define AO_IR_I2C2S_SUBPRIO         (0)

#endif

#ifndef ao_ir_i2c2s_disable

#define ao_ir_i2c2s_disable()       { IEC4CLR = _IEC4_I2C2SIE_MASK; }

#endif

#ifndef ao_ir_i2c2s_enable

#define ao_ir_i2c2s_enable()        { IEC4SET = _IEC4_I2C2SIE_MASK; }

#endif

#ifndef ao_ir_i2c2s_is_enabled

#define ao_ir_i2c2s_is_enabled()    ((IEC4 & _IEC4_I2C2SIE_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c2s_is_pending

#define ao_ir_i2c2s_is_pending()    ((IFS4 & _IFS4_I2C2SIF_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c2s_reply

#define ao_ir_i2c2s_reply()         { IFS4CLR = _IFS4_I2C2SIF_MASK; }

#endif

#ifndef ao_ir_i2c2s_request

#define ao_ir_i2c2s_request()       { IFS4SET = _IFS4_I2C2SIF_MASK; }

#endif

#ifndef AO_IR_I2C3B_ATTRIBUTE

#define AO_IR_I2C3B_ATTRIBUTE       __ISR(_I2C3_BUS_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_I2C3B_PRIO

#define AO_IR_I2C3B_PRIO            (4)

#endif

#ifndef AO_IR_I2C3B_SUBPRIO

#define AO_IR_I2C3B_SUBPRIO         (0)

#endif

#ifndef ao_ir_i2c3b_disable

#define ao_ir_i2c3b_disable()       { IEC5CLR = _IEC5_I2C3BIE_MASK; }

#endif

#ifndef ao_ir_i2c3b_enable

#define ao_ir_i2c3b_enable()        { IEC5SET = _IEC5_I2C3BIE_MASK; }

#endif

#ifndef ao_ir_i2c3b_is_enabled

#define ao_ir_i2c3b_is_enabled()    ((IEC5 & _IEC5_I2C3BIE_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c3b_is_pending

#define ao_ir_i2c3b_is_pending()    ((IFS5 & _IFS5_I2C3BIF_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c3b_reply

#define ao_ir_i2c3b_reply()         { IFS5CLR = _IFS5_I2C3BIF_MASK; }

#endif

#ifndef ao_ir_i2c3b_request

#define ao_ir_i2c3b_request()       { IFS5SET = _IFS5_I2C3BIF_MASK; }

#endif

#ifndef AO_IR_I2C3M_ATTRIBUTE

#define AO_IR_I2C3M_ATTRIBUTE       __ISR(_I2C3_MASTER_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_I2C3M_PRIO

#define AO_IR_I2C3M_PRIO            (4)

#endif

#ifndef AO_IR_I2C3M_SUBPRIO

#define AO_IR_I2C3M_SUBPRIO         (0)

#endif

#ifndef ao_ir_i2c3m_disable

#define ao_ir_i2c3m_disable()       { IEC5CLR = _IEC5_I2C3MIE_MASK; }

#endif

#ifndef ao_ir_i2c3m_enable

#define ao_ir_i2c3m_enable()        { IEC5SET = _IEC5_I2C3MIE_MASK; }

#endif

#ifndef ao_ir_i2c3m_is_enabled

#define ao_ir_i2c3m_is_enabled()    ((IEC5 & _IEC5_I2C3MIE_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c3m_is_pending

#define ao_ir_i2c3m_is_pending()    ((IFS5 & _IFS5_I2C3MIF_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c3m_reply

#define ao_ir_i2c3m_reply()         { IFS5CLR = _IFS5_I2C3MIF_MASK; }

#endif

#ifndef ao_ir_i2c3m_request

#define ao_ir_i2c3m_request()       { IFS5SET = _IFS5_I2C3MIF_MASK; }

#endif

#ifndef AO_IR_I2C3S_ATTRIBUTE

#define AO_IR_I2C3S_ATTRIBUTE       __ISR(_I2C3_SLAVE_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_I2C3S_PRIO

#define AO_IR_I2C3S_PRIO            (4)

#endif

#ifndef AO_IR_I2C3S_SUBPRIO

#define AO_IR_I2C3S_SUBPRIO         (0)

#endif

#ifndef ao_ir_i2c3s_disable

#define ao_ir_i2c3s_disable()       { IEC5CLR = _IEC5_I2C3SIE_MASK; }

#endif

#ifndef ao_ir_i2c3s_enable

#define ao_ir_i2c3s_enable()        { IEC5SET = _IEC5_I2C3SIE_MASK; }

#endif

#ifndef ao_ir_i2c3s_is_enabled

#define ao_ir_i2c3s_is_enabled()    ((IEC5 & _IEC5_I2C3SIE_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c3s_is_pending

#define ao_ir_i2c3s_is_pending()    ((IFS5 & _IFS5_I2C3SIF_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c3s_reply

#define ao_ir_i2c3s_reply()         { IFS5CLR = _IFS5_I2C3SIF_MASK; }

#endif

#ifndef ao_ir_i2c3s_request

#define ao_ir_i2c3s_request()       { IFS5SET = _IFS5_I2C3SIF_MASK; }

#endif

#ifndef AO_IR_I2C4B_ATTRIBUTE

#define AO_IR_I2C4B_ATTRIBUTE       __ISR(_I2C4_BUS_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_I2C4B_PRIO

#define AO_IR_I2C4B_PRIO            (4)

#endif

#ifndef AO_IR_I2C4B_SUBPRIO

#define AO_IR_I2C4B_SUBPRIO         (0)

#endif

#ifndef ao_ir_i2c4b_disable

#define ao_ir_i2c4b_disable()       { IEC5CLR = _IEC5_I2C4BIE_MASK; }

#endif

#ifndef ao_ir_i2c4b_enable

#define ao_ir_i2c4b_enable()        { IEC5SET = _IEC5_I2C4BIE_MASK; }

#endif

#ifndef ao_ir_i2c4b_is_enabled

#define ao_ir_i2c4b_is_enabled()    ((IEC5 & _IEC5_I2C4BIE_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c4b_is_pending

#define ao_ir_i2c4b_is_pending()    ((IFS5 & _IFS5_I2C4BIF_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c4b_reply

#define ao_ir_i2c4b_reply()         { IFS5CLR = _IFS5_I2C4BIF_MASK; }

#endif

#ifndef ao_ir_i2c4b_request

#define ao_ir_i2c4b_request()       { IFS5SET = _IFS5_I2C4BIF_MASK; }

#endif

#ifndef AO_IR_I2C4M_ATTRIBUTE

#define AO_IR_I2C4M_ATTRIBUTE       __ISR(_I2C4_MASTER_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_I2C4M_PRIO

#define AO_IR_I2C4M_PRIO            (4)

#endif

#ifndef AO_IR_I2C4M_SUBPRIO

#define AO_IR_I2C4M_SUBPRIO         (0)

#endif

#ifndef ao_ir_i2c4m_disable

#define ao_ir_i2c4m_disable()       { IEC5CLR = _IEC5_I2C4MIE_MASK; }

#endif

#ifndef ao_ir_i2c4m_enable

#define ao_ir_i2c4m_enable()        { IEC5SET = _IEC5_I2C4MIE_MASK; }

#endif

#ifndef ao_ir_i2c4m_is_enabled

#define ao_ir_i2c4m_is_enabled()    ((IEC5 & _IEC5_I2C4MIE_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c4m_is_pending

#define ao_ir_i2c4m_is_pending()    ((IFS5 & _IFS5_I2C4MIF_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c4m_reply

#define ao_ir_i2c4m_reply()         { IFS5CLR = _IFS5_I2C4MIF_MASK; }

#endif

#ifndef ao_ir_i2c4m_request

#define ao_ir_i2c4m_request()       { IFS5SET = _IFS5_I2C4MIF_MASK; }

#endif

#ifndef AO_IR_I2C4S_ATTRIBUTE

#define AO_IR_I2C4S_ATTRIBUTE       __ISR(_I2C4_SLAVE_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_I2C4S_PRIO

#define AO_IR_I2C4S_PRIO            (4)

#endif

#ifndef AO_IR_I2C4S_SUBPRIO

#define AO_IR_I2C4S_SUBPRIO         (0)

#endif

#ifndef ao_ir_i2c4s_disable

#define ao_ir_i2c4s_disable()       { IEC5CLR = _IEC5_I2C4SIE_MASK; }

#endif

#ifndef ao_ir_i2c4s_enable

#define ao_ir_i2c4s_enable()        { IEC5SET = _IEC5_I2C4SIE_MASK; }

#endif

#ifndef ao_ir_i2c4s_is_enabled

#define ao_ir_i2c4s_is_enabled()    ((IEC5 & _IEC5_I2C4SIE_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c4s_is_pending

#define ao_ir_i2c4s_is_pending()    ((IFS5 & _IFS5_I2C4SIF_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c4s_reply

#define ao_ir_i2c4s_reply()         { IFS5CLR = _IFS5_I2C4SIF_MASK; }

#endif

#ifndef ao_ir_i2c4s_request

#define ao_ir_i2c4s_request()       { IFS5SET = _IFS5_I2C4SIF_MASK; }

#endif

#ifndef AO_IR_I2C5B_ATTRIBUTE

#define AO_IR_I2C5B_ATTRIBUTE       __ISR(_I2C5_BUS_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_I2C5B_PRIO

#define AO_IR_I2C5B_PRIO            (4)

#endif

#ifndef AO_IR_I2C5B_SUBPRIO

#define AO_IR_I2C5B_SUBPRIO         (0)

#endif

#ifndef ao_ir_i2c5b_disable

#define ao_ir_i2c5b_disable()       { IEC5CLR = _IEC5_I2C5BIE_MASK; }

#endif

#ifndef ao_ir_i2c5b_enable

#define ao_ir_i2c5b_enable()        { IEC5SET = _IEC5_I2C5BIE_MASK; }

#endif

#ifndef ao_ir_i2c5b_is_enabled

#define ao_ir_i2c5b_is_enabled()    ((IEC5 & _IEC5_I2C5BIE_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c5b_is_pending

#define ao_ir_i2c5b_is_pending()    ((IFS5 & _IFS5_I2C5BIF_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c5b_reply

#define ao_ir_i2c5b_reply()         { IFS5CLR = _IFS5_I2C5BIF_MASK; }

#endif

#ifndef ao_ir_i2c5b_request

#define ao_ir_i2c5b_request()       { IFS5SET = _IFS5_I2C5BIF_MASK; }

#endif

#ifndef AO_IR_I2C5M_ATTRIBUTE

#define AO_IR_I2C5M_ATTRIBUTE       __ISR(_I2C5_MASTER_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_I2C5M_PRIO

#define AO_IR_I2C5M_PRIO            (4)

#endif

#ifndef AO_IR_I2C5M_SUBPRIO

#define AO_IR_I2C5M_SUBPRIO         (0)

#endif

#ifndef ao_ir_i2c5m_disable

#define ao_ir_i2c5m_disable()       { IEC5CLR = _IEC5_I2C5MIE_MASK; }

#endif

#ifndef ao_ir_i2c5m_enable

#define ao_ir_i2c5m_enable()        { IEC5SET = _IEC5_I2C5MIE_MASK; }

#endif

#ifndef ao_ir_i2c5m_is_enabled

#define ao_ir_i2c5m_is_enabled()    ((IEC5 & _IEC5_I2C5MIE_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c5m_is_pending

#define ao_ir_i2c5m_is_pending()    ((IFS5 & _IFS5_I2C5MIF_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c5m_reply

#define ao_ir_i2c5m_reply()         { IFS5CLR = _IFS5_I2C5MIF_MASK; }

#endif

#ifndef ao_ir_i2c5m_request

#define ao_ir_i2c5m_request()       { IFS5SET = _IFS5_I2C5MIF_MASK; }

#endif

#ifndef AO_IR_I2C5S_ATTRIBUTE

#define AO_IR_I2C5S_ATTRIBUTE       __ISR(_I2C5_SLAVE_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_I2C5S_PRIO

#define AO_IR_I2C5S_PRIO            (4)

#endif

#ifndef AO_IR_I2C5S_SUBPRIO

#define AO_IR_I2C5S_SUBPRIO         (0)

#endif

#ifndef ao_ir_i2c5s_disable

#define ao_ir_i2c5s_disable()       { IEC5CLR = _IEC5_I2C5SIE_MASK; }

#endif

#ifndef ao_ir_i2c5s_enable

#define ao_ir_i2c5s_enable()        { IEC5SET = _IEC5_I2C5SIE_MASK; }

#endif

#ifndef ao_ir_i2c5s_is_enabled

#define ao_ir_i2c5s_is_enabled()    ((IEC5 & _IEC5_I2C5SIE_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c5s_is_pending

#define ao_ir_i2c5s_is_pending()    ((IFS5 & _IFS5_I2C5SIF_MASK) ? true : false)

#endif

#ifndef ao_ir_i2c5s_reply

#define ao_ir_i2c5s_reply()         { IFS5CLR = _IFS5_I2C5SIF_MASK; }

#endif

#ifndef ao_ir_i2c5s_request

#define ao_ir_i2c5s_request()       { IFS5SET = _IFS5_I2C5SIF_MASK; }

#endif

```
