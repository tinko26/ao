---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mx_5xx/ao_ir_adc.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mx_5xx/ao_ir_adc.h/ 
subtitle: ""
title: "ao_ir_adc.h"
toc: true
---

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

#ifndef AO_IR_ADC_ATTRIBUTE

#define AO_IR_ADC_ATTRIBUTE     __ISR(_ADC_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_ADC_PRIO

#define AO_IR_ADC_PRIO          (4)

#endif

#ifndef AO_IR_ADC_SUBPRIO

#define AO_IR_ADC_SUBPRIO       (0)

#endif

#ifndef ao_ir_adc_disable

#define ao_ir_adc_disable()     { IEC1CLR = _IEC1_AD1IE_MASK; }

#endif

#ifndef ao_ir_adc_enable

#define ao_ir_adc_enable()      { IEC1SET = _IEC1_AD1IE_MASK; }

#endif

#ifndef ao_ir_adc_is_enabled

#define ao_ir_adc_is_enabled()  ((IEC1 & _IEC1_AD1IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adc_is_pending

#define ao_ir_adc_is_pending()  ((IFS1 & _IFS1_AD1IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adc_reply

#define ao_ir_adc_reply()       { IFS1CLR = _IFS1_AD1IF_MASK; }

#endif

#ifndef ao_ir_adc_request

#define ao_ir_adc_request()     { IFS1SET = _IFS1_AD1IF_MASK; }

#endif

```
