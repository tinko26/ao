---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mk_gp/ao_ir_adc.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mk_gp/ao_ir_adc.h/ 
subtitle: ""
title: "ao_ir_adc.h"
toc: true
---

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

#ifndef AO_IR_AD1_ATTRIBUTE

#define AO_IR_AD1_ATTRIBUTE         __ISR(_ADC_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1_PRIO

#define AO_IR_AD1_PRIO              (4)

#endif

#ifndef AO_IR_AD1_SUBPRIO

#define AO_IR_AD1_SUBPRIO           (0)

#endif

#ifndef ao_ir_ad1_disable

#define ao_ir_ad1_disable()         { IEC2CLR = _IEC2_AD1IE_MASK; }

#endif

#ifndef ao_ir_ad1_enable

#define ao_ir_ad1_enable()          { IEC2SET = _IEC2_AD1IE_MASK; }

#endif

#ifndef ao_ir_ad1_is_enabled

#define ao_ir_ad1_is_enabled()      ((IEC2 & _IEC2_AD1IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1_is_pending

#define ao_ir_ad1_is_pending()      ((IFS2 & _IFS2_AD1IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1_reply

#define ao_ir_ad1_reply()           { IFS2CLR = _IFS2_AD1IF_MASK; }

#endif

#ifndef ao_ir_ad1_request

#define ao_ir_ad1_request()         { IFS2SET = _IFS2_AD1IF_MASK; }

#endif

#ifndef AO_IR_AD1AR_ATTRIBUTE

#define AO_IR_AD1AR_ATTRIBUTE       __ISR(_ADC_ARDY_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1AR_PRIO

#define AO_IR_AD1AR_PRIO            (4)

#endif

#ifndef AO_IR_AD1AR_SUBPRIO

#define AO_IR_AD1AR_SUBPRIO         (0)

#endif

#ifndef ao_ir_ad1ar_disable

#define ao_ir_ad1ar_disable()       { IEC3CLR = _IEC3_AD1ARIE_MASK; }

#endif

#ifndef ao_ir_ad1ar_enable

#define ao_ir_ad1ar_enable()        { IEC3SET = _IEC3_AD1ARIE_MASK; }

#endif

#ifndef ao_ir_ad1ar_is_enabled

#define ao_ir_ad1ar_is_enabled()    ((IEC3 & _IEC3_AD1ARIE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1ar_is_pending

#define ao_ir_ad1ar_is_pending()    ((IFS3 & _IFS3_AD1ARIF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1ar_reply

#define ao_ir_ad1ar_reply()         { IFS3CLR = _IFS3_AD1ARIF_MASK; }

#endif

#ifndef ao_ir_ad1ar_request

#define ao_ir_ad1ar_request()       { IFS3SET = _IFS3_AD1ARIF_MASK; }

#endif

#ifndef AO_IR_AD1D0_ATTRIBUTE

#define AO_IR_AD1D0_ATTRIBUTE       __ISR(_ADC_DATA0_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D0_PRIO

#define AO_IR_AD1D0_PRIO            (4)

#endif

#ifndef AO_IR_AD1D0_SUBPRIO

#define AO_IR_AD1D0_SUBPRIO         (0)

#endif

#ifndef ao_ir_ad1d0_disable

#define ao_ir_ad1d0_disable()       { IEC3CLR = _IEC3_AD1D0IE_MASK; }

#endif

#ifndef ao_ir_ad1d0_enable

#define ao_ir_ad1d0_enable()        { IEC3SET = _IEC3_AD1D0IE_MASK; }

#endif

#ifndef ao_ir_ad1d0_is_enabled

#define ao_ir_ad1d0_is_enabled()    ((IEC3 & _IEC3_AD1D0IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d0_is_pending

#define ao_ir_ad1d0_is_pending()    ((IFS3 & _IFS3_AD1D0IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d0_reply

#define ao_ir_ad1d0_reply()         { IFS3CLR = _IFS3_AD1D0IF_MASK; }

#endif

#ifndef ao_ir_ad1d0_request

#define ao_ir_ad1d0_request()       { IFS3SET = _IFS3_AD1D0IF_MASK; }

#endif

#ifndef AO_IR_AD1D1_ATTRIBUTE

#define AO_IR_AD1D1_ATTRIBUTE       __ISR(_ADC_DATA1_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D1_PRIO

#define AO_IR_AD1D1_PRIO            (4)

#endif

#ifndef AO_IR_AD1D1_SUBPRIO

#define AO_IR_AD1D1_SUBPRIO         (0)

#endif

#ifndef ao_ir_ad1d1_disable

#define ao_ir_ad1d1_disable()       { IEC3CLR = _IEC3_AD1D1IE_MASK; }

#endif

#ifndef ao_ir_ad1d1_enable

#define ao_ir_ad1d1_enable()        { IEC3SET = _IEC3_AD1D1IE_MASK; }

#endif

#ifndef ao_ir_ad1d1_is_enabled

#define ao_ir_ad1d1_is_enabled()    ((IEC3 & _IEC3_AD1D1IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d1_is_pending

#define ao_ir_ad1d1_is_pending()    ((IFS3 & _IFS3_AD1D1IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d1_reply

#define ao_ir_ad1d1_reply()         { IFS3CLR = _IFS3_AD1D1IF_MASK; }

#endif

#ifndef ao_ir_ad1d1_request

#define ao_ir_ad1d1_request()       { IFS3SET = _IFS3_AD1D1IF_MASK; }

#endif

#ifndef AO_IR_AD1D2_ATTRIBUTE

#define AO_IR_AD1D2_ATTRIBUTE       __ISR(_ADC_DATA2_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D2_PRIO

#define AO_IR_AD1D2_PRIO            (4)

#endif

#ifndef AO_IR_AD1D2_SUBPRIO

#define AO_IR_AD1D2_SUBPRIO         (0)

#endif

#ifndef ao_ir_ad1d2_disable

#define ao_ir_ad1d2_disable()       { IEC3CLR = _IEC3_AD1D2IE_MASK; }

#endif

#ifndef ao_ir_ad1d2_enable

#define ao_ir_ad1d2_enable()        { IEC3SET = _IEC3_AD1D2IE_MASK; }

#endif

#ifndef ao_ir_ad1d2_is_enabled

#define ao_ir_ad1d2_is_enabled()    ((IEC3 & _IEC3_AD1D2IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d2_is_pending

#define ao_ir_ad1d2_is_pending()    ((IFS3 & _IFS3_AD1D2IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d2_reply

#define ao_ir_ad1d2_reply()         { IFS3CLR = _IFS3_AD1D2IF_MASK; }

#endif

#ifndef ao_ir_ad1d2_request

#define ao_ir_ad1d2_request()       { IFS3SET = _IFS3_AD1D2IF_MASK; }

#endif

#ifndef AO_IR_AD1D3_ATTRIBUTE

#define AO_IR_AD1D3_ATTRIBUTE       __ISR(_ADC_DATA3_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D3_PRIO

#define AO_IR_AD1D3_PRIO            (4)

#endif

#ifndef AO_IR_AD1D3_SUBPRIO

#define AO_IR_AD1D3_SUBPRIO         (0)

#endif

#ifndef ao_ir_ad1d3_disable

#define ao_ir_ad1d3_disable()       { IEC3CLR = _IEC3_AD1D3IE_MASK; }

#endif

#ifndef ao_ir_ad1d3_enable

#define ao_ir_ad1d3_enable()        { IEC3SET = _IEC3_AD1D3IE_MASK; }

#endif

#ifndef ao_ir_ad1d3_is_enabled

#define ao_ir_ad1d3_is_enabled()    ((IEC3 & _IEC3_AD1D3IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d3_is_pending

#define ao_ir_ad1d3_is_pending()    ((IFS3 & _IFS3_AD1D3IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d3_reply

#define ao_ir_ad1d3_reply()         { IFS3CLR = _IFS3_AD1D3IF_MASK; }

#endif

#ifndef ao_ir_ad1d3_request

#define ao_ir_ad1d3_request()       { IFS3SET = _IFS3_AD1D3IF_MASK; }

#endif

#ifndef AO_IR_AD1D4_ATTRIBUTE

#define AO_IR_AD1D4_ATTRIBUTE       __ISR(_ADC_DATA4_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D4_PRIO

#define AO_IR_AD1D4_PRIO            (4)

#endif

#ifndef AO_IR_AD1D4_SUBPRIO

#define AO_IR_AD1D4_SUBPRIO         (0)

#endif

#ifndef ao_ir_ad1d4_disable

#define ao_ir_ad1d4_disable()       { IEC3CLR = _IEC3_AD1D4IE_MASK; }

#endif

#ifndef ao_ir_ad1d4_enable

#define ao_ir_ad1d4_enable()        { IEC3SET = _IEC3_AD1D4IE_MASK; }

#endif

#ifndef ao_ir_ad1d4_is_enabled

#define ao_ir_ad1d4_is_enabled()    ((IEC3 & _IEC3_AD1D4IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d4_is_pending

#define ao_ir_ad1d4_is_pending()    ((IFS3 & _IFS3_AD1D4IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d4_reply

#define ao_ir_ad1d4_reply()         { IFS3CLR = _IFS3_AD1D4IF_MASK; }

#endif

#ifndef ao_ir_ad1d4_request

#define ao_ir_ad1d4_request()       { IFS3SET = _IFS3_AD1D4IF_MASK; }

#endif

#ifndef AO_IR_AD1D5_ATTRIBUTE

#define AO_IR_AD1D5_ATTRIBUTE       __ISR(_ADC_DATA5_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D5_PRIO

#define AO_IR_AD1D5_PRIO            (4)

#endif

#ifndef AO_IR_AD1D5_SUBPRIO

#define AO_IR_AD1D5_SUBPRIO         (0)

#endif

#ifndef ao_ir_ad1d5_disable

#define ao_ir_ad1d5_disable()       { IEC3CLR = _IEC3_AD1D5IE_MASK; }

#endif

#ifndef ao_ir_ad1d5_enable

#define ao_ir_ad1d5_enable()        { IEC3SET = _IEC3_AD1D5IE_MASK; }

#endif

#ifndef ao_ir_ad1d5_is_enabled

#define ao_ir_ad1d5_is_enabled()    ((IEC3 & _IEC3_AD1D5IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d5_is_pending

#define ao_ir_ad1d5_is_pending()    ((IFS3 & _IFS3_AD1D5IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d5_reply

#define ao_ir_ad1d5_reply()         { IFS3CLR = _IFS3_AD1D5IF_MASK; }

#endif

#ifndef ao_ir_ad1d5_request

#define ao_ir_ad1d5_request()       { IFS3SET = _IFS3_AD1D5IF_MASK; }

#endif

#ifndef AO_IR_AD1D6_ATTRIBUTE

#define AO_IR_AD1D6_ATTRIBUTE       __ISR(_ADC_DATA6_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D6_PRIO

#define AO_IR_AD1D6_PRIO            (4)

#endif

#ifndef AO_IR_AD1D6_SUBPRIO

#define AO_IR_AD1D6_SUBPRIO         (0)

#endif

#ifndef ao_ir_ad1d6_disable

#define ao_ir_ad1d6_disable()       { IEC3CLR = _IEC3_AD1D6IE_MASK; }

#endif

#ifndef ao_ir_ad1d6_enable

#define ao_ir_ad1d6_enable()        { IEC3SET = _IEC3_AD1D6IE_MASK; }

#endif

#ifndef ao_ir_ad1d6_is_enabled

#define ao_ir_ad1d6_is_enabled()    ((IEC3 & _IEC3_AD1D6IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d6_is_pending

#define ao_ir_ad1d6_is_pending()    ((IFS3 & _IFS3_AD1D6IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d6_reply

#define ao_ir_ad1d6_reply()         { IFS3CLR = _IFS3_AD1D6IF_MASK; }

#endif

#ifndef ao_ir_ad1d6_request

#define ao_ir_ad1d6_request()       { IFS3SET = _IFS3_AD1D6IF_MASK; }

#endif

#ifndef AO_IR_AD1D7_ATTRIBUTE

#define AO_IR_AD1D7_ATTRIBUTE       __ISR(_ADC_DATA7_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D7_PRIO

#define AO_IR_AD1D7_PRIO            (4)

#endif

#ifndef AO_IR_AD1D7_SUBPRIO

#define AO_IR_AD1D7_SUBPRIO         (0)

#endif

#ifndef ao_ir_ad1d7_disable

#define ao_ir_ad1d7_disable()       { IEC3CLR = _IEC3_AD1D7IE_MASK; }

#endif

#ifndef ao_ir_ad1d7_enable

#define ao_ir_ad1d7_enable()        { IEC3SET = _IEC3_AD1D7IE_MASK; }

#endif

#ifndef ao_ir_ad1d7_is_enabled

#define ao_ir_ad1d7_is_enabled()    ((IEC3 & _IEC3_AD1D7IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d7_is_pending

#define ao_ir_ad1d7_is_pending()    ((IFS3 & _IFS3_AD1D7IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d7_reply

#define ao_ir_ad1d7_reply()         { IFS3CLR = _IFS3_AD1D7IF_MASK; }

#endif

#ifndef ao_ir_ad1d7_request

#define ao_ir_ad1d7_request()       { IFS3SET = _IFS3_AD1D7IF_MASK; }

#endif

#ifndef AO_IR_AD1D8_ATTRIBUTE

#define AO_IR_AD1D8_ATTRIBUTE       __ISR(_ADC_DATA8_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D8_PRIO

#define AO_IR_AD1D8_PRIO            (4)

#endif

#ifndef AO_IR_AD1D8_SUBPRIO

#define AO_IR_AD1D8_SUBPRIO         (0)

#endif

#ifndef ao_ir_ad1d8_disable

#define ao_ir_ad1d8_disable()       { IEC3CLR = _IEC3_AD1D8IE_MASK; }

#endif

#ifndef ao_ir_ad1d8_enable

#define ao_ir_ad1d8_enable()        { IEC3SET = _IEC3_AD1D8IE_MASK; }

#endif

#ifndef ao_ir_ad1d8_is_enabled

#define ao_ir_ad1d8_is_enabled()    ((IEC3 & _IEC3_AD1D8IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d8_is_pending

#define ao_ir_ad1d8_is_pending()    ((IFS3 & _IFS3_AD1D8IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d8_reply

#define ao_ir_ad1d8_reply()         { IFS3CLR = _IFS3_AD1D8IF_MASK; }

#endif

#ifndef ao_ir_ad1d8_request

#define ao_ir_ad1d8_request()       { IFS3SET = _IFS3_AD1D8IF_MASK; }

#endif

#ifndef AO_IR_AD1D9_ATTRIBUTE

#define AO_IR_AD1D9_ATTRIBUTE       __ISR(_ADC_DATA9_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D9_PRIO

#define AO_IR_AD1D9_PRIO            (4)

#endif

#ifndef AO_IR_AD1D9_SUBPRIO

#define AO_IR_AD1D9_SUBPRIO         (0)

#endif

#ifndef ao_ir_ad1d9_disable

#define ao_ir_ad1d9_disable()       { IEC3CLR = _IEC3_AD1D9IE_MASK; }

#endif

#ifndef ao_ir_ad1d9_enable

#define ao_ir_ad1d9_enable()        { IEC3SET = _IEC3_AD1D9IE_MASK; }

#endif

#ifndef ao_ir_ad1d9_is_enabled

#define ao_ir_ad1d9_is_enabled()    ((IEC3 & _IEC3_AD1D9IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d9_is_pending

#define ao_ir_ad1d9_is_pending()    ((IFS3 & _IFS3_AD1D9IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d9_reply

#define ao_ir_ad1d9_reply()         { IFS3CLR = _IFS3_AD1D9IF_MASK; }

#endif

#ifndef ao_ir_ad1d9_request

#define ao_ir_ad1d9_request()       { IFS3SET = _IFS3_AD1D9IF_MASK; }

#endif

#ifndef AO_IR_AD1D10_ATTRIBUTE

#define AO_IR_AD1D10_ATTRIBUTE      __ISR(_ADC_DATA10_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D10_PRIO

#define AO_IR_AD1D10_PRIO           (4)

#endif

#ifndef AO_IR_AD1D10_SUBPRIO

#define AO_IR_AD1D10_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d10_disable

#define ao_ir_ad1d10_disable()      { IEC3CLR = _IEC3_AD1D10IE_MASK; }

#endif

#ifndef ao_ir_ad1d10_enable

#define ao_ir_ad1d10_enable()       { IEC3SET = _IEC3_AD1D10IE_MASK; }

#endif

#ifndef ao_ir_ad1d10_is_enabled

#define ao_ir_ad1d10_is_enabled()   ((IEC3 & _IEC3_AD1D10IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d10_is_pending

#define ao_ir_ad1d10_is_pending()   ((IFS3 & _IFS3_AD1D10IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d10_reply

#define ao_ir_ad1d10_reply()        { IFS3CLR = _IFS3_AD1D10IF_MASK; }

#endif

#ifndef ao_ir_ad1d10_request

#define ao_ir_ad1d10_request()      { IFS3SET = _IFS3_AD1D10IF_MASK; }

#endif

#ifndef AO_IR_AD1D11_ATTRIBUTE

#define AO_IR_AD1D11_ATTRIBUTE      __ISR(_ADC_DATA11_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D11_PRIO

#define AO_IR_AD1D11_PRIO           (4)

#endif

#ifndef AO_IR_AD1D11_SUBPRIO

#define AO_IR_AD1D11_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d11_disable

#define ao_ir_ad1d11_disable()      { IEC3CLR = _IEC3_AD1D11IE_MASK; }

#endif

#ifndef ao_ir_ad1d11_enable

#define ao_ir_ad1d11_enable()       { IEC3SET = _IEC3_AD1D11IE_MASK; }

#endif

#ifndef ao_ir_ad1d11_is_enabled

#define ao_ir_ad1d11_is_enabled()   ((IEC3 & _IEC3_AD1D11IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d11_is_pending

#define ao_ir_ad1d11_is_pending()   ((IFS3 & _IFS3_AD1D11IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d11_reply

#define ao_ir_ad1d11_reply()        { IFS3CLR = _IFS3_AD1D11IF_MASK; }

#endif

#ifndef ao_ir_ad1d11_request

#define ao_ir_ad1d11_request()      { IFS3SET = _IFS3_AD1D11IF_MASK; }

#endif

#ifndef AO_IR_AD1D12_ATTRIBUTE

#define AO_IR_AD1D12_ATTRIBUTE      __ISR(_ADC_DATA12_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D12_PRIO

#define AO_IR_AD1D12_PRIO           (4)

#endif

#ifndef AO_IR_AD1D12_SUBPRIO

#define AO_IR_AD1D12_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d12_disable

#define ao_ir_ad1d12_disable()      { IEC3CLR = _IEC3_AD1D12IE_MASK; }

#endif

#ifndef ao_ir_ad1d12_enable

#define ao_ir_ad1d12_enable()       { IEC3SET = _IEC3_AD1D12IE_MASK; }

#endif

#ifndef ao_ir_ad1d12_is_enabled

#define ao_ir_ad1d12_is_enabled()   ((IEC3 & _IEC3_AD1D12IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d12_is_pending

#define ao_ir_ad1d12_is_pending()   ((IFS3 & _IFS3_AD1D12IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d12_reply

#define ao_ir_ad1d12_reply()        { IFS3CLR = _IFS3_AD1D12IF_MASK; }

#endif

#ifndef ao_ir_ad1d12_request

#define ao_ir_ad1d12_request()      { IFS3SET = _IFS3_AD1D12IF_MASK; }

#endif

#ifndef AO_IR_AD1D13_ATTRIBUTE

#define AO_IR_AD1D13_ATTRIBUTE      __ISR(_ADC_DATA13_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D13_PRIO

#define AO_IR_AD1D13_PRIO           (4)

#endif

#ifndef AO_IR_AD1D13_SUBPRIO

#define AO_IR_AD1D13_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d13_disable

#define ao_ir_ad1d13_disable()      { IEC3CLR = _IEC3_AD1D13IE_MASK; }

#endif

#ifndef ao_ir_ad1d13_enable

#define ao_ir_ad1d13_enable()       { IEC3SET = _IEC3_AD1D13IE_MASK; }

#endif

#ifndef ao_ir_ad1d13_is_enabled

#define ao_ir_ad1d13_is_enabled()   ((IEC3 & _IEC3_AD1D13IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d13_is_pending

#define ao_ir_ad1d13_is_pending()   ((IFS3 & _IFS3_AD1D13IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d13_reply

#define ao_ir_ad1d13_reply()        { IFS3CLR = _IFS3_AD1D13IF_MASK; }

#endif

#ifndef ao_ir_ad1d13_request

#define ao_ir_ad1d13_request()      { IFS3SET = _IFS3_AD1D13IF_MASK; }

#endif

#ifndef AO_IR_AD1D14_ATTRIBUTE

#define AO_IR_AD1D14_ATTRIBUTE      __ISR(_ADC_DATA14_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D14_PRIO

#define AO_IR_AD1D14_PRIO           (4)

#endif

#ifndef AO_IR_AD1D14_SUBPRIO

#define AO_IR_AD1D14_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d14_disable

#define ao_ir_ad1d14_disable()      { IEC3CLR = _IEC3_AD1D14IE_MASK; }

#endif

#ifndef ao_ir_ad1d14_enable

#define ao_ir_ad1d14_enable()       { IEC3SET = _IEC3_AD1D14IE_MASK; }

#endif

#ifndef ao_ir_ad1d14_is_enabled

#define ao_ir_ad1d14_is_enabled()   ((IEC3 & _IEC3_AD1D14IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d14_is_pending

#define ao_ir_ad1d14_is_pending()   ((IFS3 & _IFS3_AD1D14IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d14_reply

#define ao_ir_ad1d14_reply()        { IFS3CLR = _IFS3_AD1D14IF_MASK; }

#endif

#ifndef ao_ir_ad1d14_request

#define ao_ir_ad1d14_request()      { IFS3SET = _IFS3_AD1D14IF_MASK; }

#endif

#ifndef AO_IR_AD1D15_ATTRIBUTE

#define AO_IR_AD1D15_ATTRIBUTE      __ISR(_ADC_DATA15_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D15_PRIO

#define AO_IR_AD1D15_PRIO           (4)

#endif

#ifndef AO_IR_AD1D15_SUBPRIO

#define AO_IR_AD1D15_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d15_disable

#define ao_ir_ad1d15_disable()      { IEC3CLR = _IEC3_AD1D15IE_MASK; }

#endif

#ifndef ao_ir_ad1d15_enable

#define ao_ir_ad1d15_enable()       { IEC3SET = _IEC3_AD1D15IE_MASK; }

#endif

#ifndef ao_ir_ad1d15_is_enabled

#define ao_ir_ad1d15_is_enabled()   ((IEC3 & _IEC3_AD1D15IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d15_is_pending

#define ao_ir_ad1d15_is_pending()   ((IFS3 & _IFS3_AD1D15IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d15_reply

#define ao_ir_ad1d15_reply()        { IFS3CLR = _IFS3_AD1D15IF_MASK; }

#endif

#ifndef ao_ir_ad1d15_request

#define ao_ir_ad1d15_request()      { IFS3SET = _IFS3_AD1D15IF_MASK; }

#endif

#ifndef AO_IR_AD1D16_ATTRIBUTE

#define AO_IR_AD1D16_ATTRIBUTE      __ISR(_ADC_DATA16_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D16_PRIO

#define AO_IR_AD1D16_PRIO           (4)

#endif

#ifndef AO_IR_AD1D16_SUBPRIO

#define AO_IR_AD1D16_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d16_disable

#define ao_ir_ad1d16_disable()      { IEC3CLR = _IEC3_AD1D16IE_MASK; }

#endif

#ifndef ao_ir_ad1d16_enable

#define ao_ir_ad1d16_enable()       { IEC3SET = _IEC3_AD1D16IE_MASK; }

#endif

#ifndef ao_ir_ad1d16_is_enabled

#define ao_ir_ad1d16_is_enabled()   ((IEC3 & _IEC3_AD1D16IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d16_is_pending

#define ao_ir_ad1d16_is_pending()   ((IFS3 & _IFS3_AD1D16IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d16_reply

#define ao_ir_ad1d16_reply()        { IFS3CLR = _IFS3_AD1D16IF_MASK; }

#endif

#ifndef ao_ir_ad1d16_request

#define ao_ir_ad1d16_request()      { IFS3SET = _IFS3_AD1D16IF_MASK; }

#endif

#ifndef AO_IR_AD1D17_ATTRIBUTE

#define AO_IR_AD1D17_ATTRIBUTE      __ISR(_ADC_DATA17_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D17_PRIO

#define AO_IR_AD1D17_PRIO           (4)

#endif

#ifndef AO_IR_AD1D17_SUBPRIO

#define AO_IR_AD1D17_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d17_disable

#define ao_ir_ad1d17_disable()      { IEC3CLR = _IEC3_AD1D17IE_MASK; }

#endif

#ifndef ao_ir_ad1d17_enable

#define ao_ir_ad1d17_enable()       { IEC3SET = _IEC3_AD1D17IE_MASK; }

#endif

#ifndef ao_ir_ad1d17_is_enabled

#define ao_ir_ad1d17_is_enabled()   ((IEC3 & _IEC3_AD1D17IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d17_is_pending

#define ao_ir_ad1d17_is_pending()   ((IFS3 & _IFS3_AD1D17IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d17_reply

#define ao_ir_ad1d17_reply()        { IFS3CLR = _IFS3_AD1D17IF_MASK; }

#endif

#ifndef ao_ir_ad1d17_request

#define ao_ir_ad1d17_request()      { IFS3SET = _IFS3_AD1D17IF_MASK; }

#endif

#ifndef AO_IR_AD1D18_ATTRIBUTE

#define AO_IR_AD1D18_ATTRIBUTE      __ISR(_ADC_DATA18_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D18_PRIO

#define AO_IR_AD1D18_PRIO           (4)

#endif

#ifndef AO_IR_AD1D18_SUBPRIO

#define AO_IR_AD1D18_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d18_disable

#define ao_ir_ad1d18_disable()      { IEC3CLR = _IEC3_AD1D18IE_MASK; }

#endif

#ifndef ao_ir_ad1d18_enable

#define ao_ir_ad1d18_enable()       { IEC3SET = _IEC3_AD1D18IE_MASK; }

#endif

#ifndef ao_ir_ad1d18_is_enabled

#define ao_ir_ad1d18_is_enabled()   ((IEC3 & _IEC3_AD1D18IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d18_is_pending

#define ao_ir_ad1d18_is_pending()   ((IFS3 & _IFS3_AD1D18IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d18_reply

#define ao_ir_ad1d18_reply()        { IFS3CLR = _IFS3_AD1D18IF_MASK; }

#endif

#ifndef ao_ir_ad1d18_request

#define ao_ir_ad1d18_request()      { IFS3SET = _IFS3_AD1D18IF_MASK; }

#endif

#ifndef AO_IR_AD1D19_ATTRIBUTE

#define AO_IR_AD1D19_ATTRIBUTE      __ISR(_ADC_DATA19_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D19_PRIO

#define AO_IR_AD1D19_PRIO           (4)

#endif

#ifndef AO_IR_AD1D19_SUBPRIO

#define AO_IR_AD1D19_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d19_disable

#define ao_ir_ad1d19_disable()      { IEC3CLR = _IEC3_AD1D19IE_MASK; }

#endif

#ifndef ao_ir_ad1d19_enable

#define ao_ir_ad1d19_enable()       { IEC3SET = _IEC3_AD1D19IE_MASK; }

#endif

#ifndef ao_ir_ad1d19_is_enabled

#define ao_ir_ad1d19_is_enabled()   ((IEC3 & _IEC3_AD1D19IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d19_is_pending

#define ao_ir_ad1d19_is_pending()   ((IFS3 & _IFS3_AD1D19IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d19_reply

#define ao_ir_ad1d19_reply()        { IFS3CLR = _IFS3_AD1D19IF_MASK; }

#endif

#ifndef ao_ir_ad1d19_request

#define ao_ir_ad1d19_request()      { IFS3SET = _IFS3_AD1D19IF_MASK; }

#endif

#ifndef AO_IR_AD1D20_ATTRIBUTE

#define AO_IR_AD1D20_ATTRIBUTE      __ISR(_ADC_DATA20_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D20_PRIO

#define AO_IR_AD1D20_PRIO           (4)

#endif

#ifndef AO_IR_AD1D20_SUBPRIO

#define AO_IR_AD1D20_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d20_disable

#define ao_ir_ad1d20_disable()      { IEC3CLR = _IEC3_AD1D20IE_MASK; }

#endif

#ifndef ao_ir_ad1d20_enable

#define ao_ir_ad1d20_enable()       { IEC3SET = _IEC3_AD1D20IE_MASK; }

#endif

#ifndef ao_ir_ad1d20_is_enabled

#define ao_ir_ad1d20_is_enabled()   ((IEC3 & _IEC3_AD1D20IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d20_is_pending

#define ao_ir_ad1d20_is_pending()   ((IFS3 & _IFS3_AD1D20IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d20_reply

#define ao_ir_ad1d20_reply()        { IFS3CLR = _IFS3_AD1D20IF_MASK; }

#endif

#ifndef ao_ir_ad1d20_request

#define ao_ir_ad1d20_request()      { IFS3SET = _IFS3_AD1D20IF_MASK; }

#endif

#ifndef AO_IR_AD1D21_ATTRIBUTE

#define AO_IR_AD1D21_ATTRIBUTE      __ISR(_ADC_DATA21_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D21_PRIO

#define AO_IR_AD1D21_PRIO           (4)

#endif

#ifndef AO_IR_AD1D21_SUBPRIO

#define AO_IR_AD1D21_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d21_disable

#define ao_ir_ad1d21_disable()      { IEC3CLR = _IEC3_AD1D21IE_MASK; }

#endif

#ifndef ao_ir_ad1d21_enable

#define ao_ir_ad1d21_enable()       { IEC3SET = _IEC3_AD1D21IE_MASK; }

#endif

#ifndef ao_ir_ad1d21_is_enabled

#define ao_ir_ad1d21_is_enabled()   ((IEC3 & _IEC3_AD1D21IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d21_is_pending

#define ao_ir_ad1d21_is_pending()   ((IFS3 & _IFS3_AD1D21IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d21_reply

#define ao_ir_ad1d21_reply()        { IFS3CLR = _IFS3_AD1D21IF_MASK; }

#endif

#ifndef ao_ir_ad1d21_request

#define ao_ir_ad1d21_request()      { IFS3SET = _IFS3_AD1D21IF_MASK; }

#endif

#ifndef AO_IR_AD1D22_ATTRIBUTE

#define AO_IR_AD1D22_ATTRIBUTE      __ISR(_ADC_DATA22_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D22_PRIO

#define AO_IR_AD1D22_PRIO           (4)

#endif

#ifndef AO_IR_AD1D22_SUBPRIO

#define AO_IR_AD1D22_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d22_disable

#define ao_ir_ad1d22_disable()      { IEC4CLR = _IEC4_AD1D22IE_MASK; }

#endif

#ifndef ao_ir_ad1d22_enable

#define ao_ir_ad1d22_enable()       { IEC4SET = _IEC4_AD1D22IE_MASK; }

#endif

#ifndef ao_ir_ad1d22_is_enabled

#define ao_ir_ad1d22_is_enabled()   ((IEC4 & _IEC4_AD1D22IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d22_is_pending

#define ao_ir_ad1d22_is_pending()   ((IFS4 & _IFS4_AD1D22IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d22_reply

#define ao_ir_ad1d22_reply()        { IFS4CLR = _IFS4_AD1D22IF_MASK; }

#endif

#ifndef ao_ir_ad1d22_request

#define ao_ir_ad1d22_request()      { IFS4SET = _IFS4_AD1D22IF_MASK; }

#endif

#ifndef AO_IR_AD1D23_ATTRIBUTE

#define AO_IR_AD1D23_ATTRIBUTE      __ISR(_ADC_DATA23_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D23_PRIO

#define AO_IR_AD1D23_PRIO           (4)

#endif

#ifndef AO_IR_AD1D23_SUBPRIO

#define AO_IR_AD1D23_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d23_disable

#define ao_ir_ad1d23_disable()      { IEC4CLR = _IEC4_AD1D23IE_MASK; }

#endif

#ifndef ao_ir_ad1d23_enable

#define ao_ir_ad1d23_enable()       { IEC4SET = _IEC4_AD1D23IE_MASK; }

#endif

#ifndef ao_ir_ad1d23_is_enabled

#define ao_ir_ad1d23_is_enabled()   ((IEC4 & _IEC4_AD1D23IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d23_is_pending

#define ao_ir_ad1d23_is_pending()   ((IFS4 & _IFS4_AD1D23IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d23_reply

#define ao_ir_ad1d23_reply()        { IFS4CLR = _IFS4_AD1D23IF_MASK; }

#endif

#ifndef ao_ir_ad1d23_request

#define ao_ir_ad1d23_request()      { IFS4SET = _IFS4_AD1D23IF_MASK; }

#endif

#ifndef AO_IR_AD1D24_ATTRIBUTE

#define AO_IR_AD1D24_ATTRIBUTE      __ISR(_ADC_DATA24_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D24_PRIO

#define AO_IR_AD1D24_PRIO           (4)

#endif

#ifndef AO_IR_AD1D24_SUBPRIO

#define AO_IR_AD1D24_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d24_disable

#define ao_ir_ad1d24_disable()      { IEC4CLR = _IEC4_AD1D24IE_MASK; }

#endif

#ifndef ao_ir_ad1d24_enable

#define ao_ir_ad1d24_enable()       { IEC4SET = _IEC4_AD1D24IE_MASK; }

#endif

#ifndef ao_ir_ad1d24_is_enabled

#define ao_ir_ad1d24_is_enabled()   ((IEC4 & _IEC4_AD1D24IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d24_is_pending

#define ao_ir_ad1d24_is_pending()   ((IFS4 & _IFS4_AD1D24IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d24_reply

#define ao_ir_ad1d24_reply()        { IFS4CLR = _IFS4_AD1D24IF_MASK; }

#endif

#ifndef ao_ir_ad1d24_request

#define ao_ir_ad1d24_request()      { IFS4SET = _IFS4_AD1D24IF_MASK; }

#endif

#ifndef AO_IR_AD1D25_ATTRIBUTE

#define AO_IR_AD1D25_ATTRIBUTE      __ISR(_ADC_DATA25_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D25_PRIO

#define AO_IR_AD1D25_PRIO           (4)

#endif

#ifndef AO_IR_AD1D25_SUBPRIO

#define AO_IR_AD1D25_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d25_disable

#define ao_ir_ad1d25_disable()      { IEC4CLR = _IEC4_AD1D25IE_MASK; }

#endif

#ifndef ao_ir_ad1d25_enable

#define ao_ir_ad1d25_enable()       { IEC4SET = _IEC4_AD1D25IE_MASK; }

#endif

#ifndef ao_ir_ad1d25_is_enabled

#define ao_ir_ad1d25_is_enabled()   ((IEC4 & _IEC4_AD1D25IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d25_is_pending

#define ao_ir_ad1d25_is_pending()   ((IFS4 & _IFS4_AD1D25IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d25_reply

#define ao_ir_ad1d25_reply()        { IFS4CLR = _IFS4_AD1D25IF_MASK; }

#endif

#ifndef ao_ir_ad1d25_request

#define ao_ir_ad1d25_request()      { IFS4SET = _IFS4_AD1D25IF_MASK; }

#endif

#ifndef AO_IR_AD1D26_ATTRIBUTE

#define AO_IR_AD1D26_ATTRIBUTE      __ISR(_ADC_DATA26_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D26_PRIO

#define AO_IR_AD1D26_PRIO           (4)

#endif

#ifndef AO_IR_AD1D26_SUBPRIO

#define AO_IR_AD1D26_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d26_disable

#define ao_ir_ad1d26_disable()      { IEC4CLR = _IEC4_AD1D26IE_MASK; }

#endif

#ifndef ao_ir_ad1d26_enable

#define ao_ir_ad1d26_enable()       { IEC4SET = _IEC4_AD1D26IE_MASK; }

#endif

#ifndef ao_ir_ad1d26_is_enabled

#define ao_ir_ad1d26_is_enabled()   ((IEC4 & _IEC4_AD1D26IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d26_is_pending

#define ao_ir_ad1d26_is_pending()   ((IFS4 & _IFS4_AD1D26IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d26_reply

#define ao_ir_ad1d26_reply()        { IFS4CLR = _IFS4_AD1D26IF_MASK; }

#endif

#ifndef ao_ir_ad1d26_request

#define ao_ir_ad1d26_request()      { IFS4SET = _IFS4_AD1D26IF_MASK; }

#endif

#ifndef AO_IR_AD1D27_ATTRIBUTE

#define AO_IR_AD1D27_ATTRIBUTE      __ISR(_ADC_DATA27_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D27_PRIO

#define AO_IR_AD1D27_PRIO           (4)

#endif

#ifndef AO_IR_AD1D27_SUBPRIO

#define AO_IR_AD1D27_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d27_disable

#define ao_ir_ad1d27_disable()      { IEC4CLR = _IEC4_AD1D27IE_MASK; }

#endif

#ifndef ao_ir_ad1d27_enable

#define ao_ir_ad1d27_enable()       { IEC4SET = _IEC4_AD1D27IE_MASK; }

#endif

#ifndef ao_ir_ad1d27_is_enabled

#define ao_ir_ad1d27_is_enabled()   ((IEC4 & _IEC4_AD1D27IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d27_is_pending

#define ao_ir_ad1d27_is_pending()   ((IFS4 & _IFS4_AD1D27IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d27_reply

#define ao_ir_ad1d27_reply()        { IFS4CLR = _IFS4_AD1D27IF_MASK; }

#endif

#ifndef ao_ir_ad1d27_request

#define ao_ir_ad1d27_request()      { IFS4SET = _IFS4_AD1D27IF_MASK; }

#endif

#ifndef AO_IR_AD1D33_ATTRIBUTE

#define AO_IR_AD1D33_ATTRIBUTE      __ISR(_ADC_DATA33_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D33_PRIO

#define AO_IR_AD1D33_PRIO           (4)

#endif

#ifndef AO_IR_AD1D33_SUBPRIO

#define AO_IR_AD1D33_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d33_disable

#define ao_ir_ad1d33_disable()      { IEC4CLR = _IEC4_AD1D33IE_MASK; }

#endif

#ifndef ao_ir_ad1d33_enable

#define ao_ir_ad1d33_enable()       { IEC4SET = _IEC4_AD1D33IE_MASK; }

#endif

#ifndef ao_ir_ad1d33_is_enabled

#define ao_ir_ad1d33_is_enabled()   ((IEC4 & _IEC4_AD1D33IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d33_is_pending

#define ao_ir_ad1d33_is_pending()   ((IFS4 & _IFS4_AD1D33IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d33_reply

#define ao_ir_ad1d33_reply()        { IFS4CLR = _IFS4_AD1D33IF_MASK; }

#endif

#ifndef ao_ir_ad1d33_request

#define ao_ir_ad1d33_request()      { IFS4SET = _IFS4_AD1D33IF_MASK; }

#endif

#ifndef AO_IR_AD1D34_ATTRIBUTE

#define AO_IR_AD1D34_ATTRIBUTE      __ISR(_ADC_DATA34_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D34_PRIO

#define AO_IR_AD1D34_PRIO           (4)

#endif

#ifndef AO_IR_AD1D34_SUBPRIO

#define AO_IR_AD1D34_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d34_disable

#define ao_ir_ad1d34_disable()      { IEC4CLR = _IEC4_AD1D34IE_MASK; }

#endif

#ifndef ao_ir_ad1d34_enable

#define ao_ir_ad1d34_enable()       { IEC4SET = _IEC4_AD1D34IE_MASK; }

#endif

#ifndef ao_ir_ad1d34_is_enabled

#define ao_ir_ad1d34_is_enabled()   ((IEC4 & _IEC4_AD1D34IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d34_is_pending

#define ao_ir_ad1d34_is_pending()   ((IFS4 & _IFS4_AD1D34IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d34_reply

#define ao_ir_ad1d34_reply()        { IFS4CLR = _IFS4_AD1D34IF_MASK; }

#endif

#ifndef ao_ir_ad1d34_request

#define ao_ir_ad1d34_request()      { IFS4SET = _IFS4_AD1D34IF_MASK; }

#endif

#ifndef AO_IR_AD1D35_ATTRIBUTE

#define AO_IR_AD1D35_ATTRIBUTE      __ISR(_ADC_DATA35_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D35_PRIO

#define AO_IR_AD1D35_PRIO           (4)

#endif

#ifndef AO_IR_AD1D35_SUBPRIO

#define AO_IR_AD1D35_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d35_disable

#define ao_ir_ad1d35_disable()      { IEC4CLR = _IEC4_AD1D35IE_MASK; }

#endif

#ifndef ao_ir_ad1d35_enable

#define ao_ir_ad1d35_enable()       { IEC4SET = _IEC4_AD1D35IE_MASK; }

#endif

#ifndef ao_ir_ad1d35_is_enabled

#define ao_ir_ad1d35_is_enabled()   ((IEC4 & _IEC4_AD1D35IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d35_is_pending

#define ao_ir_ad1d35_is_pending()   ((IFS4 & _IFS4_AD1D35IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d35_reply

#define ao_ir_ad1d35_reply()        { IFS4CLR = _IFS4_AD1D35IF_MASK; }

#endif

#ifndef ao_ir_ad1d35_request

#define ao_ir_ad1d35_request()      { IFS4SET = _IFS4_AD1D35IF_MASK; }

#endif

#ifndef AO_IR_AD1D36_ATTRIBUTE

#define AO_IR_AD1D36_ATTRIBUTE      __ISR(_ADC_DATA36_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D36_PRIO

#define AO_IR_AD1D36_PRIO           (4)

#endif

#ifndef AO_IR_AD1D36_SUBPRIO

#define AO_IR_AD1D36_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d36_disable

#define ao_ir_ad1d36_disable()      { IEC4CLR = _IEC4_AD1D36IE_MASK; }

#endif

#ifndef ao_ir_ad1d36_enable

#define ao_ir_ad1d36_enable()       { IEC4SET = _IEC4_AD1D36IE_MASK; }

#endif

#ifndef ao_ir_ad1d36_is_enabled

#define ao_ir_ad1d36_is_enabled()   ((IEC4 & _IEC4_AD1D36IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d36_is_pending

#define ao_ir_ad1d36_is_pending()   ((IFS4 & _IFS4_AD1D36IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d36_reply

#define ao_ir_ad1d36_reply()        { IFS4CLR = _IFS4_AD1D36IF_MASK; }

#endif

#ifndef ao_ir_ad1d36_request

#define ao_ir_ad1d36_request()      { IFS4SET = _IFS4_AD1D36IF_MASK; }

#endif

#ifndef AO_IR_AD1D37_ATTRIBUTE

#define AO_IR_AD1D37_ATTRIBUTE      __ISR(_ADC_DATA37_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D37_PRIO

#define AO_IR_AD1D37_PRIO           (4)

#endif

#ifndef AO_IR_AD1D37_SUBPRIO

#define AO_IR_AD1D37_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d37_disable

#define ao_ir_ad1d37_disable()      { IEC4CLR = _IEC4_AD1D37IE_MASK; }

#endif

#ifndef ao_ir_ad1d37_enable

#define ao_ir_ad1d37_enable()       { IEC4SET = _IEC4_AD1D37IE_MASK; }

#endif

#ifndef ao_ir_ad1d37_is_enabled

#define ao_ir_ad1d37_is_enabled()   ((IEC4 & _IEC4_AD1D37IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d37_is_pending

#define ao_ir_ad1d37_is_pending()   ((IFS4 & _IFS4_AD1D37IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d37_reply

#define ao_ir_ad1d37_reply()        { IFS4CLR = _IFS4_AD1D37IF_MASK; }

#endif

#ifndef ao_ir_ad1d37_request

#define ao_ir_ad1d37_request()      { IFS4SET = _IFS4_AD1D37IF_MASK; }

#endif

#ifndef AO_IR_AD1D38_ATTRIBUTE

#define AO_IR_AD1D38_ATTRIBUTE      __ISR(_ADC_DATA38_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D38_PRIO

#define AO_IR_AD1D38_PRIO           (4)

#endif

#ifndef AO_IR_AD1D38_SUBPRIO

#define AO_IR_AD1D38_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d38_disable

#define ao_ir_ad1d38_disable()      { IEC4CLR = _IEC4_AD1D38IE_MASK; }

#endif

#ifndef ao_ir_ad1d38_enable

#define ao_ir_ad1d38_enable()       { IEC4SET = _IEC4_AD1D38IE_MASK; }

#endif

#ifndef ao_ir_ad1d38_is_enabled

#define ao_ir_ad1d38_is_enabled()   ((IEC4 & _IEC4_AD1D38IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d38_is_pending

#define ao_ir_ad1d38_is_pending()   ((IFS4 & _IFS4_AD1D38IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d38_reply

#define ao_ir_ad1d38_reply()        { IFS4CLR = _IFS4_AD1D38IF_MASK; }

#endif

#ifndef ao_ir_ad1d38_request

#define ao_ir_ad1d38_request()      { IFS4SET = _IFS4_AD1D38IF_MASK; }

#endif

#ifndef AO_IR_AD1D39_ATTRIBUTE

#define AO_IR_AD1D39_ATTRIBUTE      __ISR(_ADC_DATA39_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D39_PRIO

#define AO_IR_AD1D39_PRIO           (4)

#endif

#ifndef AO_IR_AD1D39_SUBPRIO

#define AO_IR_AD1D39_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d39_disable

#define ao_ir_ad1d39_disable()      { IEC4CLR = _IEC4_AD1D39IE_MASK; }

#endif

#ifndef ao_ir_ad1d39_enable

#define ao_ir_ad1d39_enable()       { IEC4SET = _IEC4_AD1D39IE_MASK; }

#endif

#ifndef ao_ir_ad1d39_is_enabled

#define ao_ir_ad1d39_is_enabled()   ((IEC4 & _IEC4_AD1D39IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d39_is_pending

#define ao_ir_ad1d39_is_pending()   ((IFS4 & _IFS4_AD1D39IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d39_reply

#define ao_ir_ad1d39_reply()        { IFS4CLR = _IFS4_AD1D39IF_MASK; }

#endif

#ifndef ao_ir_ad1d39_request

#define ao_ir_ad1d39_request()      { IFS4SET = _IFS4_AD1D39IF_MASK; }

#endif

#ifndef AO_IR_AD1D40_ATTRIBUTE

#define AO_IR_AD1D40_ATTRIBUTE      __ISR(_ADC_DATA40_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D40_PRIO

#define AO_IR_AD1D40_PRIO           (4)

#endif

#ifndef AO_IR_AD1D40_SUBPRIO

#define AO_IR_AD1D40_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d40_disable

#define ao_ir_ad1d40_disable()      { IEC4CLR = _IEC4_AD1D40IE_MASK; }

#endif

#ifndef ao_ir_ad1d40_enable

#define ao_ir_ad1d40_enable()       { IEC4SET = _IEC4_AD1D40IE_MASK; }

#endif

#ifndef ao_ir_ad1d40_is_enabled

#define ao_ir_ad1d40_is_enabled()   ((IEC4 & _IEC4_AD1D40IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d40_is_pending

#define ao_ir_ad1d40_is_pending()   ((IFS4 & _IFS4_AD1D40IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d40_reply

#define ao_ir_ad1d40_reply()        { IFS4CLR = _IFS4_AD1D40IF_MASK; }

#endif

#ifndef ao_ir_ad1d40_request

#define ao_ir_ad1d40_request()      { IFS4SET = _IFS4_AD1D40IF_MASK; }

#endif

#ifndef AO_IR_AD1D41_ATTRIBUTE

#define AO_IR_AD1D41_ATTRIBUTE      __ISR(_ADC_DATA41_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D41_PRIO

#define AO_IR_AD1D41_PRIO           (4)

#endif

#ifndef AO_IR_AD1D41_SUBPRIO

#define AO_IR_AD1D41_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d41_disable

#define ao_ir_ad1d41_disable()      { IEC4CLR = _IEC4_AD1D41IE_MASK; }

#endif

#ifndef ao_ir_ad1d41_enable

#define ao_ir_ad1d41_enable()       { IEC4SET = _IEC4_AD1D41IE_MASK; }

#endif

#ifndef ao_ir_ad1d41_is_enabled

#define ao_ir_ad1d41_is_enabled()   ((IEC4 & _IEC4_AD1D41IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d41_is_pending

#define ao_ir_ad1d41_is_pending()   ((IFS4 & _IFS4_AD1D41IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d41_reply

#define ao_ir_ad1d41_reply()        { IFS4CLR = _IFS4_AD1D41IF_MASK; }

#endif

#ifndef ao_ir_ad1d41_request

#define ao_ir_ad1d41_request()      { IFS4SET = _IFS4_AD1D41IF_MASK; }

#endif

#ifndef AO_IR_AD1D45_ATTRIBUTE

#define AO_IR_AD1D45_ATTRIBUTE      __ISR(_ADC_DATA45_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D45_PRIO

#define AO_IR_AD1D45_PRIO           (4)

#endif

#ifndef AO_IR_AD1D45_SUBPRIO

#define AO_IR_AD1D45_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d45_disable

#define ao_ir_ad1d45_disable()      { IEC4CLR = _IEC4_AD1D45IE_MASK; }

#endif

#ifndef ao_ir_ad1d45_enable

#define ao_ir_ad1d45_enable()       { IEC4SET = _IEC4_AD1D45IE_MASK; }

#endif

#ifndef ao_ir_ad1d45_is_enabled

#define ao_ir_ad1d45_is_enabled()   ((IEC4 & _IEC4_AD1D45IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d45_is_pending

#define ao_ir_ad1d45_is_pending()   ((IFS4 & _IFS4_AD1D45IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d45_reply

#define ao_ir_ad1d45_reply()        { IFS4CLR = _IFS4_AD1D45IF_MASK; }

#endif

#ifndef ao_ir_ad1d45_request

#define ao_ir_ad1d45_request()      { IFS4SET = _IFS4_AD1D45IF_MASK; }

#endif

#ifndef AO_IR_AD1D46_ATTRIBUTE

#define AO_IR_AD1D46_ATTRIBUTE      __ISR(_ADC_DATA46_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D46_PRIO

#define AO_IR_AD1D46_PRIO           (4)

#endif

#ifndef AO_IR_AD1D46_SUBPRIO

#define AO_IR_AD1D46_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d46_disable

#define ao_ir_ad1d46_disable()      { IEC4CLR = _IEC4_AD1D46IE_MASK; }

#endif

#ifndef ao_ir_ad1d46_enable

#define ao_ir_ad1d46_enable()       { IEC4SET = _IEC4_AD1D46IE_MASK; }

#endif

#ifndef ao_ir_ad1d46_is_enabled

#define ao_ir_ad1d46_is_enabled()   ((IEC4 & _IEC4_AD1D46IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d46_is_pending

#define ao_ir_ad1d46_is_pending()   ((IFS4 & _IFS4_AD1D46IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d46_reply

#define ao_ir_ad1d46_reply()        { IFS4CLR = _IFS4_AD1D46IF_MASK; }

#endif

#ifndef ao_ir_ad1d46_request

#define ao_ir_ad1d46_request()      { IFS4SET = _IFS4_AD1D46IF_MASK; }

#endif

#ifndef AO_IR_AD1D47_ATTRIBUTE

#define AO_IR_AD1D47_ATTRIBUTE      __ISR(_ADC_DATA47_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D47_PRIO

#define AO_IR_AD1D47_PRIO           (4)

#endif

#ifndef AO_IR_AD1D47_SUBPRIO

#define AO_IR_AD1D47_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d47_disable

#define ao_ir_ad1d47_disable()      { IEC4CLR = _IEC4_AD1D47IE_MASK; }

#endif

#ifndef ao_ir_ad1d47_enable

#define ao_ir_ad1d47_enable()       { IEC4SET = _IEC4_AD1D47IE_MASK; }

#endif

#ifndef ao_ir_ad1d47_is_enabled

#define ao_ir_ad1d47_is_enabled()   ((IEC4 & _IEC4_AD1D47IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d47_is_pending

#define ao_ir_ad1d47_is_pending()   ((IFS4 & _IFS4_AD1D47IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d47_reply

#define ao_ir_ad1d47_reply()        { IFS4CLR = _IFS4_AD1D47IF_MASK; }

#endif

#ifndef ao_ir_ad1d47_request

#define ao_ir_ad1d47_request()      { IFS4SET = _IFS4_AD1D47IF_MASK; }

#endif

#ifndef AO_IR_AD1D48_ATTRIBUTE

#define AO_IR_AD1D48_ATTRIBUTE      __ISR(_ADC_DATA48_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D48_PRIO

#define AO_IR_AD1D48_PRIO           (4)

#endif

#ifndef AO_IR_AD1D48_SUBPRIO

#define AO_IR_AD1D48_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d48_disable

#define ao_ir_ad1d48_disable()      { IEC4CLR = _IEC4_AD1D48IE_MASK; }

#endif

#ifndef ao_ir_ad1d48_enable

#define ao_ir_ad1d48_enable()       { IEC4SET = _IEC4_AD1D48IE_MASK; }

#endif

#ifndef ao_ir_ad1d48_is_enabled

#define ao_ir_ad1d48_is_enabled()   ((IEC4 & _IEC4_AD1D48IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d48_is_pending

#define ao_ir_ad1d48_is_pending()   ((IFS4 & _IFS4_AD1D48IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d48_reply

#define ao_ir_ad1d48_reply()        { IFS4CLR = _IFS4_AD1D48IF_MASK; }

#endif

#ifndef ao_ir_ad1d48_request

#define ao_ir_ad1d48_request()      { IFS4SET = _IFS4_AD1D48IF_MASK; }

#endif

#ifndef AO_IR_AD1D49_ATTRIBUTE

#define AO_IR_AD1D49_ATTRIBUTE      __ISR(_ADC_DATA49_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D49_PRIO

#define AO_IR_AD1D49_PRIO           (4)

#endif

#ifndef AO_IR_AD1D49_SUBPRIO

#define AO_IR_AD1D49_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d49_disable

#define ao_ir_ad1d49_disable()      { IEC4CLR = _IEC4_AD1D49IE_MASK; }

#endif

#ifndef ao_ir_ad1d49_enable

#define ao_ir_ad1d49_enable()       { IEC4SET = _IEC4_AD1D49IE_MASK; }

#endif

#ifndef ao_ir_ad1d49_is_enabled

#define ao_ir_ad1d49_is_enabled()   ((IEC4 & _IEC4_AD1D49IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d49_is_pending

#define ao_ir_ad1d49_is_pending()   ((IFS4 & _IFS4_AD1D49IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d49_reply

#define ao_ir_ad1d49_reply()        { IFS4CLR = _IFS4_AD1D49IF_MASK; }

#endif

#ifndef ao_ir_ad1d49_request

#define ao_ir_ad1d49_request()      { IFS4SET = _IFS4_AD1D49IF_MASK; }

#endif

#ifndef AO_IR_AD1D50_ATTRIBUTE

#define AO_IR_AD1D50_ATTRIBUTE      __ISR(_ADC_DATA50_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D50_PRIO

#define AO_IR_AD1D50_PRIO           (4)

#endif

#ifndef AO_IR_AD1D50_SUBPRIO

#define AO_IR_AD1D50_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d50_disable

#define ao_ir_ad1d50_disable()      { IEC4CLR = _IEC4_AD1D50IE_MASK; }

#endif

#ifndef ao_ir_ad1d50_enable

#define ao_ir_ad1d50_enable()       { IEC4SET = _IEC4_AD1D50IE_MASK; }

#endif

#ifndef ao_ir_ad1d50_is_enabled

#define ao_ir_ad1d50_is_enabled()   ((IEC4 & _IEC4_AD1D50IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d50_is_pending

#define ao_ir_ad1d50_is_pending()   ((IFS4 & _IFS4_AD1D50IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d50_reply

#define ao_ir_ad1d50_reply()        { IFS4CLR = _IFS4_AD1D50IF_MASK; }

#endif

#ifndef ao_ir_ad1d50_request

#define ao_ir_ad1d50_request()      { IFS4SET = _IFS4_AD1D50IF_MASK; }

#endif

#ifndef AO_IR_AD1D51_ATTRIBUTE

#define AO_IR_AD1D51_ATTRIBUTE      __ISR(_ADC_DATA51_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D51_PRIO

#define AO_IR_AD1D51_PRIO           (4)

#endif

#ifndef AO_IR_AD1D51_SUBPRIO

#define AO_IR_AD1D51_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d51_disable

#define ao_ir_ad1d51_disable()      { IEC4CLR = _IEC4_AD1D51IE_MASK; }

#endif

#ifndef ao_ir_ad1d51_enable

#define ao_ir_ad1d51_enable()       { IEC4SET = _IEC4_AD1D51IE_MASK; }

#endif

#ifndef ao_ir_ad1d51_is_enabled

#define ao_ir_ad1d51_is_enabled()   ((IEC4 & _IEC4_AD1D51IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d51_is_pending

#define ao_ir_ad1d51_is_pending()   ((IFS4 & _IFS4_AD1D51IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d51_reply

#define ao_ir_ad1d51_reply()        { IFS4CLR = _IFS4_AD1D51IF_MASK; }

#endif

#ifndef ao_ir_ad1d51_request

#define ao_ir_ad1d51_request()      { IFS4SET = _IFS4_AD1D51IF_MASK; }

#endif

#ifndef AO_IR_AD1D52_ATTRIBUTE

#define AO_IR_AD1D52_ATTRIBUTE      __ISR(_ADC_DATA52_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D52_PRIO

#define AO_IR_AD1D52_PRIO           (4)

#endif

#ifndef AO_IR_AD1D52_SUBPRIO

#define AO_IR_AD1D52_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d52_disable

#define ao_ir_ad1d52_disable()      { IEC4CLR = _IEC4_AD1D52IE_MASK; }

#endif

#ifndef ao_ir_ad1d52_enable

#define ao_ir_ad1d52_enable()       { IEC4SET = _IEC4_AD1D52IE_MASK; }

#endif

#ifndef ao_ir_ad1d52_is_enabled

#define ao_ir_ad1d52_is_enabled()   ((IEC4 & _IEC4_AD1D52IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d52_is_pending

#define ao_ir_ad1d52_is_pending()   ((IFS4 & _IFS4_AD1D52IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d52_reply

#define ao_ir_ad1d52_reply()        { IFS4CLR = _IFS4_AD1D52IF_MASK; }

#endif

#ifndef ao_ir_ad1d52_request

#define ao_ir_ad1d52_request()      { IFS4SET = _IFS4_AD1D52IF_MASK; }

#endif

#ifndef AO_IR_AD1D53_ATTRIBUTE

#define AO_IR_AD1D53_ATTRIBUTE      __ISR(_ADC_DATA53_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1D53_PRIO

#define AO_IR_AD1D53_PRIO           (4)

#endif

#ifndef AO_IR_AD1D53_SUBPRIO

#define AO_IR_AD1D53_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1d53_disable

#define ao_ir_ad1d53_disable()      { IEC4CLR = _IEC4_AD1D53IE_MASK; }

#endif

#ifndef ao_ir_ad1d53_enable

#define ao_ir_ad1d53_enable()       { IEC4SET = _IEC4_AD1D53IE_MASK; }

#endif

#ifndef ao_ir_ad1d53_is_enabled

#define ao_ir_ad1d53_is_enabled()   ((IEC4 & _IEC4_AD1D53IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d53_is_pending

#define ao_ir_ad1d53_is_pending()   ((IFS4 & _IFS4_AD1D53IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1d53_reply

#define ao_ir_ad1d53_reply()        { IFS4CLR = _IFS4_AD1D53IF_MASK; }

#endif

#ifndef ao_ir_ad1d53_request

#define ao_ir_ad1d53_request()      { IFS4SET = _IFS4_AD1D53IF_MASK; }

#endif

#ifndef AO_IR_AD1DC1_ATTRIBUTE

#define AO_IR_AD1DC1_ATTRIBUTE      __ISR(_ADC_DC1_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1DC1_PRIO

#define AO_IR_AD1DC1_PRIO           (4)

#endif

#ifndef AO_IR_AD1DC1_SUBPRIO

#define AO_IR_AD1DC1_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1dc1_disable

#define ao_ir_ad1dc1_disable()      { IEC2CLR = _IEC2_AD1DC1IE_MASK; }

#endif

#ifndef ao_ir_ad1dc1_enable

#define ao_ir_ad1dc1_enable()       { IEC2SET = _IEC2_AD1DC1IE_MASK; }

#endif

#ifndef ao_ir_ad1dc1_is_enabled

#define ao_ir_ad1dc1_is_enabled()   ((IEC2 & _IEC2_AD1DC1IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1dc1_is_pending

#define ao_ir_ad1dc1_is_pending()   ((IFS2 & _IFS2_AD1DC1IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1dc1_reply

#define ao_ir_ad1dc1_reply()        { IFS2CLR = _IFS2_AD1DC1IF_MASK; }

#endif

#ifndef ao_ir_ad1dc1_request

#define ao_ir_ad1dc1_request()      { IFS2SET = _IFS2_AD1DC1IF_MASK; }

#endif

#ifndef AO_IR_AD1DC2_ATTRIBUTE

#define AO_IR_AD1DC2_ATTRIBUTE      __ISR(_ADC_DC2_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1DC2_PRIO

#define AO_IR_AD1DC2_PRIO           (4)

#endif

#ifndef AO_IR_AD1DC2_SUBPRIO

#define AO_IR_AD1DC2_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1dc2_disable

#define ao_ir_ad1dc2_disable()      { IEC2CLR = _IEC2_AD1DC2IE_MASK; }

#endif

#ifndef ao_ir_ad1dc2_enable

#define ao_ir_ad1dc2_enable()       { IEC2SET = _IEC2_AD1DC2IE_MASK; }

#endif

#ifndef ao_ir_ad1dc2_is_enabled

#define ao_ir_ad1dc2_is_enabled()   ((IEC2 & _IEC2_AD1DC2IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1dc2_is_pending

#define ao_ir_ad1dc2_is_pending()   ((IFS2 & _IFS2_AD1DC2IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1dc2_reply

#define ao_ir_ad1dc2_reply()        { IFS2CLR = _IFS2_AD1DC2IF_MASK; }

#endif

#ifndef ao_ir_ad1dc2_request

#define ao_ir_ad1dc2_request()      { IFS2SET = _IFS2_AD1DC2IF_MASK; }

#endif

#ifndef AO_IR_AD1DC3_ATTRIBUTE

#define AO_IR_AD1DC3_ATTRIBUTE      __ISR(_ADC_DC3_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1DC3_PRIO

#define AO_IR_AD1DC3_PRIO           (4)

#endif

#ifndef AO_IR_AD1DC3_SUBPRIO

#define AO_IR_AD1DC3_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1dc3_disable

#define ao_ir_ad1dc3_disable()      { IEC7CLR = _IEC7_AD1DC3IE_MASK; }

#endif

#ifndef ao_ir_ad1dc3_enable

#define ao_ir_ad1dc3_enable()       { IEC7SET = _IEC7_AD1DC3IE_MASK; }

#endif

#ifndef ao_ir_ad1dc3_is_enabled

#define ao_ir_ad1dc3_is_enabled()   ((IEC7 & _IEC7_AD1DC3IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1dc3_is_pending

#define ao_ir_ad1dc3_is_pending()   ((IFS7 & _IFS7_AD1DC3IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1dc3_reply

#define ao_ir_ad1dc3_reply()        { IFS7CLR = _IFS7_AD1DC3IF_MASK; }

#endif

#ifndef ao_ir_ad1dc3_request

#define ao_ir_ad1dc3_request()      { IFS7SET = _IFS7_AD1DC3IF_MASK; }

#endif

#ifndef AO_IR_AD1DC4_ATTRIBUTE

#define AO_IR_AD1DC4_ATTRIBUTE      __ISR(_ADC_DC4_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1DC4_PRIO

#define AO_IR_AD1DC4_PRIO           (4)

#endif

#ifndef AO_IR_AD1DC4_SUBPRIO

#define AO_IR_AD1DC4_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1dc4_disable

#define ao_ir_ad1dc4_disable()      { IEC7CLR = _IEC7_AD1DC4IE_MASK; }

#endif

#ifndef ao_ir_ad1dc4_enable

#define ao_ir_ad1dc4_enable()       { IEC7SET = _IEC7_AD1DC4IE_MASK; }

#endif

#ifndef ao_ir_ad1dc4_is_enabled

#define ao_ir_ad1dc4_is_enabled()   ((IEC7 & _IEC7_AD1DC4IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1dc4_is_pending

#define ao_ir_ad1dc4_is_pending()   ((IFS7 & _IFS7_AD1DC4IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1dc4_reply

#define ao_ir_ad1dc4_reply()        { IFS7CLR = _IFS7_AD1DC4IF_MASK; }

#endif

#ifndef ao_ir_ad1dc4_request

#define ao_ir_ad1dc4_request()      { IFS7SET = _IFS7_AD1DC4IF_MASK; }

#endif

#ifndef AO_IR_AD1DF1_ATTRIBUTE

#define AO_IR_AD1DF1_ATTRIBUTE      __ISR(_ADC_DF1_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1DF1_PRIO

#define AO_IR_AD1DF1_PRIO           (4)

#endif

#ifndef AO_IR_AD1DF1_SUBPRIO

#define AO_IR_AD1DF1_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1df1_disable

#define ao_ir_ad1df1_disable()      { IEC3CLR = _IEC3_AD1DF1IE_MASK; }

#endif

#ifndef ao_ir_ad1df1_enable

#define ao_ir_ad1df1_enable()       { IEC3SET = _IEC3_AD1DF1IE_MASK; }

#endif

#ifndef ao_ir_ad1df1_is_enabled

#define ao_ir_ad1df1_is_enabled()   ((IEC3 & _IEC3_AD1DF1IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1df1_is_pending

#define ao_ir_ad1df1_is_pending()   ((IFS3 & _IFS3_AD1DF1IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1df1_reply

#define ao_ir_ad1df1_reply()        { IFS3CLR = _IFS3_AD1DF1IF_MASK; }

#endif

#ifndef ao_ir_ad1df1_request

#define ao_ir_ad1df1_request()      { IFS3SET = _IFS3_AD1DF1IF_MASK; }

#endif

#ifndef AO_IR_AD1DF2_ATTRIBUTE

#define AO_IR_AD1DF2_ATTRIBUTE      __ISR(_ADC_DF2_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1DF2_PRIO

#define AO_IR_AD1DF2_PRIO           (4)

#endif

#ifndef AO_IR_AD1DF2_SUBPRIO

#define AO_IR_AD1DF2_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1df2_disable

#define ao_ir_ad1df2_disable()      { IEC3CLR = _IEC3_AD1DF2IE_MASK; }

#endif

#ifndef ao_ir_ad1df2_enable

#define ao_ir_ad1df2_enable()       { IEC3SET = _IEC3_AD1DF2IE_MASK; }

#endif

#ifndef ao_ir_ad1df2_is_enabled

#define ao_ir_ad1df2_is_enabled()   ((IEC3 & _IEC3_AD1DF2IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1df2_is_pending

#define ao_ir_ad1df2_is_pending()   ((IFS3 & _IFS3_AD1DF2IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1df2_reply

#define ao_ir_ad1df2_reply()        { IFS3CLR = _IFS3_AD1DF2IF_MASK; }

#endif

#ifndef ao_ir_ad1df2_request

#define ao_ir_ad1df2_request()      { IFS3SET = _IFS3_AD1DF2IF_MASK; }

#endif

#ifndef AO_IR_AD1DF3_ATTRIBUTE

#define AO_IR_AD1DF3_ATTRIBUTE      __ISR(_ADC_DF3_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1DF3_PRIO

#define AO_IR_AD1DF3_PRIO           (4)

#endif

#ifndef AO_IR_AD1DF3_SUBPRIO

#define AO_IR_AD1DF3_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1df3_disable

#define ao_ir_ad1df3_disable()      { IEC3CLR = _IEC3_AD1DF3IE_MASK; }

#endif

#ifndef ao_ir_ad1df3_enable

#define ao_ir_ad1df3_enable()       { IEC3SET = _IEC3_AD1DF3IE_MASK; }

#endif

#ifndef ao_ir_ad1df3_is_enabled

#define ao_ir_ad1df3_is_enabled()   ((IEC3 & _IEC3_AD1DF3IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1df3_is_pending

#define ao_ir_ad1df3_is_pending()   ((IFS3 & _IFS3_AD1DF3IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1df3_reply

#define ao_ir_ad1df3_reply()        { IFS3CLR = _IFS3_AD1DF3IF_MASK; }

#endif

#ifndef ao_ir_ad1df3_request

#define ao_ir_ad1df3_request()      { IFS3SET = _IFS3_AD1DF3IF_MASK; }

#endif

#ifndef AO_IR_AD1DF4_ATTRIBUTE

#define AO_IR_AD1DF4_ATTRIBUTE      __ISR(_ADC_DF4_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1DF4_PRIO

#define AO_IR_AD1DF4_PRIO           (4)

#endif

#ifndef AO_IR_AD1DF4_SUBPRIO

#define AO_IR_AD1DF4_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1df4_disable

#define ao_ir_ad1df4_disable()      { IEC3CLR = _IEC3_AD1DF4IE_MASK; }

#endif

#ifndef ao_ir_ad1df4_enable

#define ao_ir_ad1df4_enable()       { IEC3SET = _IEC3_AD1DF4IE_MASK; }

#endif

#ifndef ao_ir_ad1df4_is_enabled

#define ao_ir_ad1df4_is_enabled()   ((IEC3 & _IEC3_AD1DF4IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1df4_is_pending

#define ao_ir_ad1df4_is_pending()   ((IFS3 & _IFS3_AD1DF4IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1df4_reply

#define ao_ir_ad1df4_reply()        { IFS3CLR = _IFS3_AD1DF4IF_MASK; }

#endif

#ifndef ao_ir_ad1df4_request

#define ao_ir_ad1df4_request()      { IFS3SET = _IFS3_AD1DF4IF_MASK; }

#endif

#ifndef AO_IR_AD1EOS_ATTRIBUTE

#define AO_IR_AD1EOS_ATTRIBUTE      __ISR(_ADC_EOS_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1EOS_PRIO

#define AO_IR_AD1EOS_PRIO           (4)

#endif

#ifndef AO_IR_AD1EOS_SUBPRIO

#define AO_IR_AD1EOS_SUBPRIO        (0)

#endif

#ifndef ao_ir_ad1eos_disable

#define ao_ir_ad1eos_disable()      { IEC3CLR = _IEC3_AD1EOSIE_MASK; }

#endif

#ifndef ao_ir_ad1eos_enable

#define ao_ir_ad1eos_enable()       { IEC3SET = _IEC3_AD1EOSIE_MASK; }

#endif

#ifndef ao_ir_ad1eos_is_enabled

#define ao_ir_ad1eos_is_enabled()   ((IEC3 & _IEC3_AD1EOSIE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1eos_is_pending

#define ao_ir_ad1eos_is_pending()   ((IFS3 & _IFS3_AD1EOSIF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1eos_reply

#define ao_ir_ad1eos_reply()        { IFS3CLR = _IFS3_AD1EOSIF_MASK; }

#endif

#ifndef ao_ir_ad1eos_request

#define ao_ir_ad1eos_request()      { IFS3SET = _IFS3_AD1EOSIF_MASK; }

#endif

#ifndef AO_IR_AD1FCBT_ATTRIBUTE

#define AO_IR_AD1FCBT_ATTRIBUTE     __ISR(_ADC_DMA_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1FCBT_PRIO

#define AO_IR_AD1FCBT_PRIO          (4)

#endif

#ifndef AO_IR_AD1FCBT_SUBPRIO

#define AO_IR_AD1FCBT_SUBPRIO       (0)

#endif

#ifndef ao_ir_ad1fcbt_disable

#define ao_ir_ad1fcbt_disable()     { IEC3CLR = _IEC3_AD1FCBTIE_MASK; }

#endif

#ifndef ao_ir_ad1fcbt_enable

#define ao_ir_ad1fcbt_enable()      { IEC3SET = _IEC3_AD1FCBTIE_MASK; }

#endif

#ifndef ao_ir_ad1fcbt_is_enabled

#define ao_ir_ad1fcbt_is_enabled()  ((IEC3 & _IEC3_AD1FCBTIE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1fcbt_is_pending

#define ao_ir_ad1fcbt_is_pending()  ((IFS3 & _IFS3_AD1FCBTIF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1fcbt_reply

#define ao_ir_ad1fcbt_reply()       { IFS3CLR = _IFS3_AD1FCBTIF_MASK; }

#endif

#ifndef ao_ir_ad1fcbt_request

#define ao_ir_ad1fcbt_request()     { IFS3SET = _IFS3_AD1FCBTIF_MASK; }

#endif

#ifndef AO_IR_AD1FI_ATTRIBUTE

#define AO_IR_AD1FI_ATTRIBUTE       __ISR(_ADC_FAULT_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1FI_PRIO

#define AO_IR_AD1FI_PRIO            (4)

#endif

#ifndef AO_IR_AD1FI_SUBPRIO

#define AO_IR_AD1FI_SUBPRIO         (0)

#endif

#ifndef ao_ir_ad1fi_disable

#define ao_ir_ad1fi_disable()       { IEC3CLR = _IEC3_AD1FIIE_MASK; }

#endif

#ifndef ao_ir_ad1fi_enable

#define ao_ir_ad1fi_enable()        { IEC3SET = _IEC3_AD1FIIE_MASK; }

#endif

#ifndef ao_ir_ad1fi_is_enabled

#define ao_ir_ad1fi_is_enabled()    ((IEC3 & _IEC3_AD1FIIE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1fi_is_pending

#define ao_ir_ad1fi_is_pending()    ((IFS3 & _IFS3_AD1FIIF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1fi_reply

#define ao_ir_ad1fi_reply()         { IFS3CLR = _IFS3_AD1FIIF_MASK; }

#endif

#ifndef ao_ir_ad1fi_request

#define ao_ir_ad1fi_request()       { IFS3SET = _IFS3_AD1FIIF_MASK; }

#endif

#ifndef AO_IR_AD1G_ATTRIBUTE

#define AO_IR_AD1G_ATTRIBUTE        __ISR(_ADC_EARLY_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1G_PRIO

#define AO_IR_AD1G_PRIO             (4)

#endif

#ifndef AO_IR_AD1G_SUBPRIO

#define AO_IR_AD1G_SUBPRIO          (0)

#endif

#ifndef ao_ir_ad1g_disable

#define ao_ir_ad1g_disable()        { IEC3CLR = _IEC3_AD1GIE_MASK; }

#endif

#ifndef ao_ir_ad1g_enable

#define ao_ir_ad1g_enable()         { IEC3SET = _IEC3_AD1GIE_MASK; }

#endif

#ifndef ao_ir_ad1g_is_enabled

#define ao_ir_ad1g_is_enabled()     ((IEC3 & _IEC3_AD1GIE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1g_is_pending

#define ao_ir_ad1g_is_pending()     ((IFS3 & _IFS3_AD1GIF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1g_reply

#define ao_ir_ad1g_reply()          { IFS3CLR = _IFS3_AD1GIF_MASK; }

#endif

#ifndef ao_ir_ad1g_request

#define ao_ir_ad1g_request()        { IFS3SET = _IFS3_AD1GIF_MASK; }

#endif

#ifndef AO_IR_AD1RS_ATTRIBUTE

#define AO_IR_AD1RS_ATTRIBUTE       __ISR(_ADC_URDY_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_AD1RS_PRIO

#define AO_IR_AD1RS_PRIO            (4)

#endif

#ifndef AO_IR_AD1RS_SUBPRIO

#define AO_IR_AD1RS_SUBPRIO         (0)

#endif

#ifndef ao_ir_ad1rs_disable

#define ao_ir_ad1rs_disable()       { IEC3CLR = _IEC3_AD1RSIE_MASK; }

#endif

#ifndef ao_ir_ad1rs_enable

#define ao_ir_ad1rs_enable()        { IEC3SET = _IEC3_AD1RSIE_MASK; }

#endif

#ifndef ao_ir_ad1rs_is_enabled

#define ao_ir_ad1rs_is_enabled()    ((IEC3 & _IEC3_AD1RSIE_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1rs_is_pending

#define ao_ir_ad1rs_is_pending()    ((IFS3 & _IFS3_AD1RSIF_MASK) ? true : false)

#endif

#ifndef ao_ir_ad1rs_reply

#define ao_ir_ad1rs_reply()         { IFS3CLR = _IFS3_AD1RSIF_MASK; }

#endif

#ifndef ao_ir_ad1rs_request

#define ao_ir_ad1rs_request()       { IFS3SET = _IFS3_AD1RSIF_MASK; }

#endif

```
