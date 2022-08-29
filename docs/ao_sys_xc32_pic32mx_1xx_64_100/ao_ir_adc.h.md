---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32mx_1xx_64_100/ao_ir_adc.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mx_1xx_64_100/ao_ir_adc.h/ 
subtitle: "<code>ao_sys_xc32_pic32mx_1xx_64_100</code>"
title: "<code>ao_ir_adc.h</code>"
toc: true
---

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

#define ao_ir_adc_disable()     { IEC0CLR = _IEC0_AD1IE_MASK; }

#endif

#ifndef ao_ir_adc_enable

#define ao_ir_adc_enable()      { IEC0SET = _IEC0_AD1IE_MASK; }

#endif

#ifndef ao_ir_adc_is_enabled

#define ao_ir_adc_is_enabled()  ((IEC0 & _IEC0_AD1IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adc_is_pending

#define ao_ir_adc_is_pending()  ((IFS0 & _IFS0_AD1IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adc_reply

#define ao_ir_adc_reply()       { IFS0CLR = _IFS0_AD1IF_MASK; }

#endif

#ifndef ao_ir_adc_request

#define ao_ir_adc_request()     { IFS0SET = _IFS0_AD1IF_MASK; }

#endif

