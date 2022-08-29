---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mz_ef/ao_ir_dma.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mz_ef/ao_ir_dma.h/ 
subtitle: ""
title: "ao_ir_dma.h"
toc: true
---

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

#ifndef AO_IR_DMA0_ATTRIBUTE

#define AO_IR_DMA0_ATTRIBUTE        __ISR(_DMA0_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_DMA0_PRIO

#define AO_IR_DMA0_PRIO             (4)

#endif

#ifndef AO_IR_DMA0_SUBPRIO

#define AO_IR_DMA0_SUBPRIO          (0)

#endif

#ifndef ao_ir_dma0_disable

#define ao_ir_dma0_disable()        { IEC4CLR = _IEC4_DMA0IE_MASK; }

#endif

#ifndef ao_ir_dma0_enable

#define ao_ir_dma0_enable()         { IEC4SET = _IEC4_DMA0IE_MASK; }

#endif

#ifndef ao_ir_dma0_is_enabled

#define ao_ir_dma0_is_enabled()     ((IEC4 & _IEC4_DMA0IE_MASK) ? true : false)

#endif

#ifndef ao_ir_dma0_is_pending

#define ao_ir_dma0_is_pending()     ((IFS4 & _IFS4_DMA0IF_MASK) ? true : false)

#endif

#ifndef ao_ir_dma0_reply

#define ao_ir_dma0_reply()          { IFS4CLR = _IFS4_DMA0IF_MASK; }

#endif

#ifndef ao_ir_dma0_request

#define ao_ir_dma0_request()        { IFS4SET = _IFS4_DMA0IF_MASK; }

#endif

#ifndef AO_IR_DMA1_ATTRIBUTE

#define AO_IR_DMA1_ATTRIBUTE        __ISR(_DMA1_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_DMA1_PRIO

#define AO_IR_DMA1_PRIO             (4)

#endif

#ifndef AO_IR_DMA1_SUBPRIO

#define AO_IR_DMA1_SUBPRIO          (0)

#endif

#ifndef ao_ir_dma1_disable

#define ao_ir_dma1_disable()        { IEC4CLR = _IEC4_DMA1IE_MASK; }

#endif

#ifndef ao_ir_dma1_enable

#define ao_ir_dma1_enable()         { IEC4SET = _IEC4_DMA1IE_MASK; }

#endif

#ifndef ao_ir_dma1_is_enabled

#define ao_ir_dma1_is_enabled()     ((IEC4 & _IEC4_DMA1IE_MASK) ? true : false)

#endif

#ifndef ao_ir_dma1_is_pending

#define ao_ir_dma1_is_pending()     ((IFS4 & _IFS4_DMA1IF_MASK) ? true : false)

#endif

#ifndef ao_ir_dma1_reply

#define ao_ir_dma1_reply()          { IFS4CLR = _IFS4_DMA1IF_MASK; }

#endif

#ifndef ao_ir_dma1_request

#define ao_ir_dma1_request()        { IFS4SET = _IFS4_DMA1IF_MASK; }

#endif

#ifndef AO_IR_DMA2_ATTRIBUTE

#define AO_IR_DMA2_ATTRIBUTE        __ISR(_DMA2_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_DMA2_PRIO

#define AO_IR_DMA2_PRIO             (4)

#endif

#ifndef AO_IR_DMA2_SUBPRIO

#define AO_IR_DMA2_SUBPRIO          (0)

#endif

#ifndef ao_ir_dma2_disable

#define ao_ir_dma2_disable()        { IEC4CLR = _IEC4_DMA2IE_MASK; }

#endif

#ifndef ao_ir_dma2_enable

#define ao_ir_dma2_enable()         { IEC4SET = _IEC4_DMA2IE_MASK; }

#endif

#ifndef ao_ir_dma2_is_enabled

#define ao_ir_dma2_is_enabled()     ((IEC4 & _IEC4_DMA2IE_MASK) ? true : false)

#endif

#ifndef ao_ir_dma2_is_pending

#define ao_ir_dma2_is_pending()     ((IFS4 & _IFS4_DMA2IF_MASK) ? true : false)

#endif

#ifndef ao_ir_dma2_reply

#define ao_ir_dma2_reply()          { IFS4CLR = _IFS4_DMA2IF_MASK; }

#endif

#ifndef ao_ir_dma2_request

#define ao_ir_dma2_request()        { IFS4SET = _IFS4_DMA2IF_MASK; }

#endif

#ifndef AO_IR_DMA3_ATTRIBUTE

#define AO_IR_DMA3_ATTRIBUTE        __ISR(_DMA3_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_DMA3_PRIO

#define AO_IR_DMA3_PRIO             (4)

#endif

#ifndef AO_IR_DMA3_SUBPRIO

#define AO_IR_DMA3_SUBPRIO          (0)

#endif

#ifndef ao_ir_dma3_disable

#define ao_ir_dma3_disable()        { IEC4CLR = _IEC4_DMA3IE_MASK; }

#endif

#ifndef ao_ir_dma3_enable

#define ao_ir_dma3_enable()         { IEC4SET = _IEC4_DMA3IE_MASK; }

#endif

#ifndef ao_ir_dma3_is_enabled

#define ao_ir_dma3_is_enabled()     ((IEC4 & _IEC4_DMA3IE_MASK) ? true : false)

#endif

#ifndef ao_ir_dma3_is_pending

#define ao_ir_dma3_is_pending()     ((IFS4 & _IFS4_DMA3IF_MASK) ? true : false)

#endif

#ifndef ao_ir_dma3_reply

#define ao_ir_dma3_reply()          { IFS4CLR = _IFS4_DMA3IF_MASK; }

#endif

#ifndef ao_ir_dma3_request

#define ao_ir_dma3_request()        { IFS4SET = _IFS4_DMA3IF_MASK; }

#endif

#ifndef AO_IR_DMA4_ATTRIBUTE

#define AO_IR_DMA4_ATTRIBUTE        __ISR(_DMA4_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_DMA4_PRIO

#define AO_IR_DMA4_PRIO             (4)

#endif

#ifndef AO_IR_DMA4_SUBPRIO

#define AO_IR_DMA4_SUBPRIO          (0)

#endif

#ifndef ao_ir_dma4_disable

#define ao_ir_dma4_disable()        { IEC4CLR = _IEC4_DMA4IE_MASK; }

#endif

#ifndef ao_ir_dma4_enable

#define ao_ir_dma4_enable()         { IEC4SET = _IEC4_DMA4IE_MASK; }

#endif

#ifndef ao_ir_dma4_is_enabled

#define ao_ir_dma4_is_enabled()     ((IEC4 & _IEC4_DMA4IE_MASK) ? true : false)

#endif

#ifndef ao_ir_dma4_is_pending

#define ao_ir_dma4_is_pending()     ((IFS4 & _IFS4_DMA4IF_MASK) ? true : false)

#endif

#ifndef ao_ir_dma4_reply

#define ao_ir_dma4_reply()          { IFS4CLR = _IFS4_DMA4IF_MASK; }

#endif

#ifndef ao_ir_dma4_request

#define ao_ir_dma4_request()        { IFS4SET = _IFS4_DMA4IF_MASK; }

#endif

#ifndef AO_IR_DMA5_ATTRIBUTE

#define AO_IR_DMA5_ATTRIBUTE        __ISR(_DMA5_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_DMA5_PRIO

#define AO_IR_DMA5_PRIO             (4)

#endif

#ifndef AO_IR_DMA5_SUBPRIO

#define AO_IR_DMA5_SUBPRIO          (0)

#endif

#ifndef ao_ir_dma5_disable

#define ao_ir_dma5_disable()        { IEC4CLR = _IEC4_DMA5IE_MASK; }

#endif

#ifndef ao_ir_dma5_enable

#define ao_ir_dma5_enable()         { IEC4SET = _IEC4_DMA5IE_MASK; }

#endif

#ifndef ao_ir_dma5_is_enabled

#define ao_ir_dma5_is_enabled()     ((IEC4 & _IEC4_DMA5IE_MASK) ? true : false)

#endif

#ifndef ao_ir_dma5_is_pending

#define ao_ir_dma5_is_pending()     ((IFS4 & _IFS4_DMA5IF_MASK) ? true : false)

#endif

#ifndef ao_ir_dma5_reply

#define ao_ir_dma5_reply()          { IFS4CLR = _IFS4_DMA5IF_MASK; }

#endif

#ifndef ao_ir_dma5_request

#define ao_ir_dma5_request()        { IFS4SET = _IFS4_DMA5IF_MASK; }

#endif

#ifndef AO_IR_DMA6_ATTRIBUTE

#define AO_IR_DMA6_ATTRIBUTE        __ISR(_DMA6_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_DMA6_PRIO

#define AO_IR_DMA6_PRIO             (4)

#endif

#ifndef AO_IR_DMA6_SUBPRIO

#define AO_IR_DMA6_SUBPRIO          (0)

#endif

#ifndef ao_ir_dma6_disable

#define ao_ir_dma6_disable()        { IEC4CLR = _IEC4_DMA6IE_MASK; }

#endif

#ifndef ao_ir_dma6_enable

#define ao_ir_dma6_enable()         { IEC4SET = _IEC4_DMA6IE_MASK; }

#endif

#ifndef ao_ir_dma6_is_enabled

#define ao_ir_dma6_is_enabled()     ((IEC4 & _IEC4_DMA6IE_MASK) ? true : false)

#endif

#ifndef ao_ir_dma6_is_pending

#define ao_ir_dma6_is_pending()     ((IFS4 & _IFS4_DMA6IF_MASK) ? true : false)

#endif

#ifndef ao_ir_dma6_reply

#define ao_ir_dma6_reply()          { IFS4CLR = _IFS4_DMA6IF_MASK; }

#endif

#ifndef ao_ir_dma6_request

#define ao_ir_dma6_request()        { IFS4SET = _IFS4_DMA6IF_MASK; }

#endif

#ifndef AO_IR_DMA7_ATTRIBUTE

#define AO_IR_DMA7_ATTRIBUTE        __ISR(_DMA7_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_DMA7_PRIO

#define AO_IR_DMA7_PRIO             (4)

#endif

#ifndef AO_IR_DMA7_SUBPRIO

#define AO_IR_DMA7_SUBPRIO          (0)

#endif

#ifndef ao_ir_dma7_disable

#define ao_ir_dma7_disable()        { IEC4CLR = _IEC4_DMA7IE_MASK; }

#endif

#ifndef ao_ir_dma7_enable

#define ao_ir_dma7_enable()         { IEC4SET = _IEC4_DMA7IE_MASK; }

#endif

#ifndef ao_ir_dma7_is_enabled

#define ao_ir_dma7_is_enabled()     ((IEC4 & _IEC4_DMA7IE_MASK) ? true : false)

#endif

#ifndef ao_ir_dma7_is_pending

#define ao_ir_dma7_is_pending()     ((IFS4 & _IFS4_DMA7IF_MASK) ? true : false)

#endif

#ifndef ao_ir_dma7_reply

#define ao_ir_dma7_reply()          { IFS4CLR = _IFS4_DMA7IF_MASK; }

#endif

#ifndef ao_ir_dma7_request

#define ao_ir_dma7_request()        { IFS4SET = _IFS4_DMA7IF_MASK; }

#endif

```
