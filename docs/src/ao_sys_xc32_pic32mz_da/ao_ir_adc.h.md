---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mz_da/ao_ir_adc.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32_pic32mz_da/ao_ir_adc.h/ 
subtitle: ""
title: "ao_ir_adc.h"
toc: true
---

# Overview

...

# Includes

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

#ifndef AO_IR_ADC_ATTRIBUTE

#define AO_IR_ADC_ATTRIBUTE         __ISR(_ADC_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADC_PRIO

#define AO_IR_ADC_PRIO              (4)

#endif

#ifndef AO_IR_ADC_SUBPRIO

#define AO_IR_ADC_SUBPRIO           (0)

#endif

#ifndef ao_ir_adc_disable

#define ao_ir_adc_disable()         { IEC1CLR = _IEC1_ADCIE_MASK; }

#endif

#ifndef ao_ir_adc_enable

#define ao_ir_adc_enable()          { IEC1SET = _IEC1_ADCIE_MASK; }

#endif

#ifndef ao_ir_adc_is_enabled

#define ao_ir_adc_is_enabled()      ((IEC1 & _IEC1_ADCIE_MASK) ? true : false)

#endif

#ifndef ao_ir_adc_is_pending

#define ao_ir_adc_is_pending()      ((IFS1 & _IFS1_ADCIF_MASK) ? true : false)

#endif

#ifndef ao_ir_adc_reply

#define ao_ir_adc_reply()           { IFS1CLR = _IFS1_ADCIF_MASK; }

#endif

#ifndef ao_ir_adc_request

#define ao_ir_adc_request()         { IFS1SET = _IFS1_ADCIF_MASK; }

#endif

#ifndef AO_IR_ADC0E_ATTRIBUTE

#define AO_IR_ADC0E_ATTRIBUTE       __ISR(_ADC0_EARLY_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADC0E_PRIO

#define AO_IR_ADC0E_PRIO            (4)

#endif

#ifndef AO_IR_ADC0E_SUBPRIO

#define AO_IR_ADC0E_SUBPRIO         (0)

#endif

#ifndef ao_ir_adc0e_disable

#define ao_ir_adc0e_disable()       { IEC6CLR = _IEC6_ADC0EIE_MASK; }

#endif

#ifndef ao_ir_adc0e_enable

#define ao_ir_adc0e_enable()        { IEC6SET = _IEC6_ADC0EIE_MASK; }

#endif

#ifndef ao_ir_adc0e_is_enabled

#define ao_ir_adc0e_is_enabled()    ((IEC6 & _IEC6_ADC0EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_adc0e_is_pending

#define ao_ir_adc0e_is_pending()    ((IFS6 & _IFS6_ADC0EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_adc0e_reply

#define ao_ir_adc0e_reply()         { IFS6CLR = _IFS6_ADC0EIF_MASK; }

#endif

#ifndef ao_ir_adc0e_request

#define ao_ir_adc0e_request()       { IFS6SET = _IFS6_ADC0EIF_MASK; }

#endif

#ifndef AO_IR_ADC0W_ATTRIBUTE

#define AO_IR_ADC0W_ATTRIBUTE       __ISR(_ADC0_WARM_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADC0W_PRIO

#define AO_IR_ADC0W_PRIO            (4)

#endif

#ifndef AO_IR_ADC0W_SUBPRIO

#define AO_IR_ADC0W_SUBPRIO         (0)

#endif

#ifndef ao_ir_adc0w_disable

#define ao_ir_adc0w_disable()       { IEC6CLR = _IEC6_ADC0WIE_MASK; }

#endif

#ifndef ao_ir_adc0w_enable

#define ao_ir_adc0w_enable()        { IEC6SET = _IEC6_ADC0WIE_MASK; }

#endif

#ifndef ao_ir_adc0w_is_enabled

#define ao_ir_adc0w_is_enabled()    ((IEC6 & _IEC6_ADC0WIE_MASK) ? true : false)

#endif

#ifndef ao_ir_adc0w_is_pending

#define ao_ir_adc0w_is_pending()    ((IFS6 & _IFS6_ADC0WIF_MASK) ? true : false)

#endif

#ifndef ao_ir_adc0w_reply

#define ao_ir_adc0w_reply()         { IFS6CLR = _IFS6_ADC0WIF_MASK; }

#endif

#ifndef ao_ir_adc0w_request

#define ao_ir_adc0w_request()       { IFS6SET = _IFS6_ADC0WIF_MASK; }

#endif

#ifndef AO_IR_ADC1E_ATTRIBUTE

#define AO_IR_ADC1E_ATTRIBUTE       __ISR(_ADC1_EARLY_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADC1E_PRIO

#define AO_IR_ADC1E_PRIO            (4)

#endif

#ifndef AO_IR_ADC1E_SUBPRIO

#define AO_IR_ADC1E_SUBPRIO         (0)

#endif

#ifndef ao_ir_adc1e_disable

#define ao_ir_adc1e_disable()       { IEC6CLR = _IEC6_ADC1EIE_MASK; }

#endif

#ifndef ao_ir_adc1e_enable

#define ao_ir_adc1e_enable()        { IEC6SET = _IEC6_ADC1EIE_MASK; }

#endif

#ifndef ao_ir_adc1e_is_enabled

#define ao_ir_adc1e_is_enabled()    ((IEC6 & _IEC6_ADC1EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_adc1e_is_pending

#define ao_ir_adc1e_is_pending()    ((IFS6 & _IFS6_ADC1EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_adc1e_reply

#define ao_ir_adc1e_reply()         { IFS6CLR = _IFS6_ADC1EIF_MASK; }

#endif

#ifndef ao_ir_adc1e_request

#define ao_ir_adc1e_request()       { IFS6SET = _IFS6_ADC1EIF_MASK; }

#endif

#ifndef AO_IR_ADC1W_ATTRIBUTE

#define AO_IR_ADC1W_ATTRIBUTE       __ISR(_ADC1_WARM_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADC1W_PRIO

#define AO_IR_ADC1W_PRIO            (4)

#endif

#ifndef AO_IR_ADC1W_SUBPRIO

#define AO_IR_ADC1W_SUBPRIO         (0)

#endif

#ifndef ao_ir_adc1w_disable

#define ao_ir_adc1w_disable()       { IEC6CLR = _IEC6_ADC1WIE_MASK; }

#endif

#ifndef ao_ir_adc1w_enable

#define ao_ir_adc1w_enable()        { IEC6SET = _IEC6_ADC1WIE_MASK; }

#endif

#ifndef ao_ir_adc1w_is_enabled

#define ao_ir_adc1w_is_enabled()    ((IEC6 & _IEC6_ADC1WIE_MASK) ? true : false)

#endif

#ifndef ao_ir_adc1w_is_pending

#define ao_ir_adc1w_is_pending()    ((IFS6 & _IFS6_ADC1WIF_MASK) ? true : false)

#endif

#ifndef ao_ir_adc1w_reply

#define ao_ir_adc1w_reply()         { IFS6CLR = _IFS6_ADC1WIF_MASK; }

#endif

#ifndef ao_ir_adc1w_request

#define ao_ir_adc1w_request()       { IFS6SET = _IFS6_ADC1WIF_MASK; }

#endif

#ifndef AO_IR_ADC2E_ATTRIBUTE

#define AO_IR_ADC2E_ATTRIBUTE       __ISR(_ADC2_EARLY_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADC2E_PRIO

#define AO_IR_ADC2E_PRIO            (4)

#endif

#ifndef AO_IR_ADC2E_SUBPRIO

#define AO_IR_ADC2E_SUBPRIO         (0)

#endif

#ifndef ao_ir_adc2e_disable

#define ao_ir_adc2e_disable()       { IEC6CLR = _IEC6_ADC2EIE_MASK; }

#endif

#ifndef ao_ir_adc2e_enable

#define ao_ir_adc2e_enable()        { IEC6SET = _IEC6_ADC2EIE_MASK; }

#endif

#ifndef ao_ir_adc2e_is_enabled

#define ao_ir_adc2e_is_enabled()    ((IEC6 & _IEC6_ADC2EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_adc2e_is_pending

#define ao_ir_adc2e_is_pending()    ((IFS6 & _IFS6_ADC2EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_adc2e_reply

#define ao_ir_adc2e_reply()         { IFS6CLR = _IFS6_ADC2EIF_MASK; }

#endif

#ifndef ao_ir_adc2e_request

#define ao_ir_adc2e_request()       { IFS6SET = _IFS6_ADC2EIF_MASK; }

#endif

#ifndef AO_IR_ADC2W_ATTRIBUTE

#define AO_IR_ADC2W_ATTRIBUTE       __ISR(_ADC2_WARM_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADC2W_PRIO

#define AO_IR_ADC2W_PRIO            (4)

#endif

#ifndef AO_IR_ADC2W_SUBPRIO

#define AO_IR_ADC2W_SUBPRIO         (0)

#endif

#ifndef ao_ir_adc2w_disable

#define ao_ir_adc2w_disable()       { IEC6CLR = _IEC6_ADC2WIE_MASK; }

#endif

#ifndef ao_ir_adc2w_enable

#define ao_ir_adc2w_enable()        { IEC6SET = _IEC6_ADC2WIE_MASK; }

#endif

#ifndef ao_ir_adc2w_is_enabled

#define ao_ir_adc2w_is_enabled()    ((IEC6 & _IEC6_ADC2WIE_MASK) ? true : false)

#endif

#ifndef ao_ir_adc2w_is_pending

#define ao_ir_adc2w_is_pending()    ((IFS6 & _IFS6_ADC2WIF_MASK) ? true : false)

#endif

#ifndef ao_ir_adc2w_reply

#define ao_ir_adc2w_reply()         { IFS6CLR = _IFS6_ADC2WIF_MASK; }

#endif

#ifndef ao_ir_adc2w_request

#define ao_ir_adc2w_request()       { IFS6SET = _IFS6_ADC2WIF_MASK; }

#endif

#ifndef AO_IR_ADC3E_ATTRIBUTE

#define AO_IR_ADC3E_ATTRIBUTE       __ISR(_ADC3_EARLY_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADC3E_PRIO

#define AO_IR_ADC3E_PRIO            (4)

#endif

#ifndef AO_IR_ADC3E_SUBPRIO

#define AO_IR_ADC3E_SUBPRIO         (0)

#endif

#ifndef ao_ir_adc3e_disable

#define ao_ir_adc3e_disable()       { IEC6CLR = _IEC6_ADC3EIE_MASK; }

#endif

#ifndef ao_ir_adc3e_enable

#define ao_ir_adc3e_enable()        { IEC6SET = _IEC6_ADC3EIE_MASK; }

#endif

#ifndef ao_ir_adc3e_is_enabled

#define ao_ir_adc3e_is_enabled()    ((IEC6 & _IEC6_ADC3EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_adc3e_is_pending

#define ao_ir_adc3e_is_pending()    ((IFS6 & _IFS6_ADC3EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_adc3e_reply

#define ao_ir_adc3e_reply()         { IFS6CLR = _IFS6_ADC3EIF_MASK; }

#endif

#ifndef ao_ir_adc3e_request

#define ao_ir_adc3e_request()       { IFS6SET = _IFS6_ADC3EIF_MASK; }

#endif

#ifndef AO_IR_ADC3W_ATTRIBUTE

#define AO_IR_ADC3W_ATTRIBUTE       __ISR(_ADC3_WARM_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADC3W_PRIO

#define AO_IR_ADC3W_PRIO            (4)

#endif

#ifndef AO_IR_ADC3W_SUBPRIO

#define AO_IR_ADC3W_SUBPRIO         (0)

#endif

#ifndef ao_ir_adc3w_disable

#define ao_ir_adc3w_disable()       { IEC6CLR = _IEC6_ADC3WIE_MASK; }

#endif

#ifndef ao_ir_adc3w_enable

#define ao_ir_adc3w_enable()        { IEC6SET = _IEC6_ADC3WIE_MASK; }

#endif

#ifndef ao_ir_adc3w_is_enabled

#define ao_ir_adc3w_is_enabled()    ((IEC6 & _IEC6_ADC3WIE_MASK) ? true : false)

#endif

#ifndef ao_ir_adc3w_is_pending

#define ao_ir_adc3w_is_pending()    ((IFS6 & _IFS6_ADC3WIF_MASK) ? true : false)

#endif

#ifndef ao_ir_adc3w_reply

#define ao_ir_adc3w_reply()         { IFS6CLR = _IFS6_ADC3WIF_MASK; }

#endif

#ifndef ao_ir_adc3w_request

#define ao_ir_adc3w_request()       { IFS6SET = _IFS6_ADC3WIF_MASK; }

#endif

#ifndef AO_IR_ADC4E_ATTRIBUTE

#define AO_IR_ADC4E_ATTRIBUTE       __ISR(_ADC4_EARLY_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADC4E_PRIO

#define AO_IR_ADC4E_PRIO            (4)

#endif

#ifndef AO_IR_ADC4E_SUBPRIO

#define AO_IR_ADC4E_SUBPRIO         (0)

#endif

#ifndef ao_ir_adc4e_disable

#define ao_ir_adc4e_disable()       { IEC6CLR = _IEC6_ADC4EIE_MASK; }

#endif

#ifndef ao_ir_adc4e_enable

#define ao_ir_adc4e_enable()        { IEC6SET = _IEC6_ADC4EIE_MASK; }

#endif

#ifndef ao_ir_adc4e_is_enabled

#define ao_ir_adc4e_is_enabled()    ((IEC6 & _IEC6_ADC4EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_adc4e_is_pending

#define ao_ir_adc4e_is_pending()    ((IFS6 & _IFS6_ADC4EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_adc4e_reply

#define ao_ir_adc4e_reply()         { IFS6CLR = _IFS6_ADC4EIF_MASK; }

#endif

#ifndef ao_ir_adc4e_request

#define ao_ir_adc4e_request()       { IFS6SET = _IFS6_ADC4EIF_MASK; }

#endif

#ifndef AO_IR_ADC4W_ATTRIBUTE

#define AO_IR_ADC4W_ATTRIBUTE       __ISR(_ADC4_WARM_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADC4W_PRIO

#define AO_IR_ADC4W_PRIO            (4)

#endif

#ifndef AO_IR_ADC4W_SUBPRIO

#define AO_IR_ADC4W_SUBPRIO         (0)

#endif

#ifndef ao_ir_adc4w_disable

#define ao_ir_adc4w_disable()       { IEC6CLR = _IEC6_ADC4WIE_MASK; }

#endif

#ifndef ao_ir_adc4w_enable

#define ao_ir_adc4w_enable()        { IEC6SET = _IEC6_ADC4WIE_MASK; }

#endif

#ifndef ao_ir_adc4w_is_enabled

#define ao_ir_adc4w_is_enabled()    ((IEC6 & _IEC6_ADC4WIE_MASK) ? true : false)

#endif

#ifndef ao_ir_adc4w_is_pending

#define ao_ir_adc4w_is_pending()    ((IFS6 & _IFS6_ADC4WIF_MASK) ? true : false)

#endif

#ifndef ao_ir_adc4w_reply

#define ao_ir_adc4w_reply()         { IFS6CLR = _IFS6_ADC4WIF_MASK; }

#endif

#ifndef ao_ir_adc4w_request

#define ao_ir_adc4w_request()       { IFS6SET = _IFS6_ADC4WIF_MASK; }

#endif

#ifndef AO_IR_ADC7E_ATTRIBUTE

#define AO_IR_ADC7E_ATTRIBUTE       __ISR(_ADC7_EARLY_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADC7E_PRIO

#define AO_IR_ADC7E_PRIO            (4)

#endif

#ifndef AO_IR_ADC7E_SUBPRIO

#define AO_IR_ADC7E_SUBPRIO         (0)

#endif

#ifndef ao_ir_adc7e_disable

#define ao_ir_adc7e_disable()       { IEC6CLR = _IEC6_ADC7EIE_MASK; }

#endif

#ifndef ao_ir_adc7e_enable

#define ao_ir_adc7e_enable()        { IEC6SET = _IEC6_ADC7EIE_MASK; }

#endif

#ifndef ao_ir_adc7e_is_enabled

#define ao_ir_adc7e_is_enabled()    ((IEC6 & _IEC6_ADC7EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_adc7e_is_pending

#define ao_ir_adc7e_is_pending()    ((IFS6 & _IFS6_ADC7EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_adc7e_reply

#define ao_ir_adc7e_reply()         { IFS6CLR = _IFS6_ADC7EIF_MASK; }

#endif

#ifndef ao_ir_adc7e_request

#define ao_ir_adc7e_request()       { IFS6SET = _IFS6_ADC7EIF_MASK; }

#endif

#ifndef AO_IR_ADC7W_ATTRIBUTE

#define AO_IR_ADC7W_ATTRIBUTE       __ISR(_ADC7_WARM_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADC7W_PRIO

#define AO_IR_ADC7W_PRIO            (4)

#endif

#ifndef AO_IR_ADC7W_SUBPRIO

#define AO_IR_ADC7W_SUBPRIO         (0)

#endif

#ifndef ao_ir_adc7w_disable

#define ao_ir_adc7w_disable()       { IEC6CLR = _IEC6_ADC7WIE_MASK; }

#endif

#ifndef ao_ir_adc7w_enable

#define ao_ir_adc7w_enable()        { IEC6SET = _IEC6_ADC7WIE_MASK; }

#endif

#ifndef ao_ir_adc7w_is_enabled

#define ao_ir_adc7w_is_enabled()    ((IEC6 & _IEC6_ADC7WIE_MASK) ? true : false)

#endif

#ifndef ao_ir_adc7w_is_pending

#define ao_ir_adc7w_is_pending()    ((IFS6 & _IFS6_ADC7WIF_MASK) ? true : false)

#endif

#ifndef ao_ir_adc7w_reply

#define ao_ir_adc7w_reply()         { IFS6CLR = _IFS6_ADC7WIF_MASK; }

#endif

#ifndef ao_ir_adc7w_request

#define ao_ir_adc7w_request()       { IFS6SET = _IFS6_ADC7WIF_MASK; }

#endif

#ifndef AO_IR_ADCARDY_ATTRIBUTE

#define AO_IR_ADCARDY_ATTRIBUTE     __ISR(_ADC_ARDY_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCARDY_PRIO

#define AO_IR_ADCARDY_PRIO          (4)

#endif

#ifndef AO_IR_ADCARDY_SUBPRIO

#define AO_IR_ADCARDY_SUBPRIO       (0)

#endif

#ifndef ao_ir_adcardy_disable

#define ao_ir_adcardy_disable()     { IEC6CLR = _IEC6_ADCARDYIE_MASK; }

#endif

#ifndef ao_ir_adcardy_enable

#define ao_ir_adcardy_enable()      { IEC6SET = _IEC6_ADCARDYIE_MASK; }

#endif

#ifndef ao_ir_adcardy_is_enabled

#define ao_ir_adcardy_is_enabled()  ((IEC6 & _IEC6_ADCARDYIE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcardy_is_pending

#define ao_ir_adcardy_is_pending()  ((IFS6 & _IFS6_ADCARDYIF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcardy_reply

#define ao_ir_adcardy_reply()       { IFS6CLR = _IFS6_ADCARDYIF_MASK; }

#endif

#ifndef ao_ir_adcardy_request

#define ao_ir_adcardy_request()     { IFS6SET = _IFS6_ADCARDYIF_MASK; }

#endif

#ifndef AO_IR_ADCD0_ATTRIBUTE

#define AO_IR_ADCD0_ATTRIBUTE       __ISR(_ADC_DATA0_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD0_PRIO

#define AO_IR_ADCD0_PRIO            (4)

#endif

#ifndef AO_IR_ADCD0_SUBPRIO

#define AO_IR_ADCD0_SUBPRIO         (0)

#endif

#ifndef ao_ir_adcd0_disable

#define ao_ir_adcd0_disable()       { IEC1CLR = _IEC1_ADCD0IE_MASK; }

#endif

#ifndef ao_ir_adcd0_enable

#define ao_ir_adcd0_enable()        { IEC1SET = _IEC1_ADCD0IE_MASK; }

#endif

#ifndef ao_ir_adcd0_is_enabled

#define ao_ir_adcd0_is_enabled()    ((IEC1 & _IEC1_ADCD0IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd0_is_pending

#define ao_ir_adcd0_is_pending()    ((IFS1 & _IFS1_ADCD0IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd0_reply

#define ao_ir_adcd0_reply()         { IFS1CLR = _IFS1_ADCD0IF_MASK; }

#endif

#ifndef ao_ir_adcd0_request

#define ao_ir_adcd0_request()       { IFS1SET = _IFS1_ADCD0IF_MASK; }

#endif

#ifndef AO_IR_ADCD1_ATTRIBUTE

#define AO_IR_ADCD1_ATTRIBUTE       __ISR(_ADC_DATA1_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD1_PRIO

#define AO_IR_ADCD1_PRIO            (4)

#endif

#ifndef AO_IR_ADCD1_SUBPRIO

#define AO_IR_ADCD1_SUBPRIO         (0)

#endif

#ifndef ao_ir_adcd1_disable

#define ao_ir_adcd1_disable()       { IEC1CLR = _IEC1_ADCD1IE_MASK; }

#endif

#ifndef ao_ir_adcd1_enable

#define ao_ir_adcd1_enable()        { IEC1SET = _IEC1_ADCD1IE_MASK; }

#endif

#ifndef ao_ir_adcd1_is_enabled

#define ao_ir_adcd1_is_enabled()    ((IEC1 & _IEC1_ADCD1IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd1_is_pending

#define ao_ir_adcd1_is_pending()    ((IFS1 & _IFS1_ADCD1IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd1_reply

#define ao_ir_adcd1_reply()         { IFS1CLR = _IFS1_ADCD1IF_MASK; }

#endif

#ifndef ao_ir_adcd1_request

#define ao_ir_adcd1_request()       { IFS1SET = _IFS1_ADCD1IF_MASK; }

#endif

#ifndef AO_IR_ADCD2_ATTRIBUTE

#define AO_IR_ADCD2_ATTRIBUTE       __ISR(_ADC_DATA2_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD2_PRIO

#define AO_IR_ADCD2_PRIO            (4)

#endif

#ifndef AO_IR_ADCD2_SUBPRIO

#define AO_IR_ADCD2_SUBPRIO         (0)

#endif

#ifndef ao_ir_adcd2_disable

#define ao_ir_adcd2_disable()       { IEC1CLR = _IEC1_ADCD2IE_MASK; }

#endif

#ifndef ao_ir_adcd2_enable

#define ao_ir_adcd2_enable()        { IEC1SET = _IEC1_ADCD2IE_MASK; }

#endif

#ifndef ao_ir_adcd2_is_enabled

#define ao_ir_adcd2_is_enabled()    ((IEC1 & _IEC1_ADCD2IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd2_is_pending

#define ao_ir_adcd2_is_pending()    ((IFS1 & _IFS1_ADCD2IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd2_reply

#define ao_ir_adcd2_reply()         { IFS1CLR = _IFS1_ADCD2IF_MASK; }

#endif

#ifndef ao_ir_adcd2_request

#define ao_ir_adcd2_request()       { IFS1SET = _IFS1_ADCD2IF_MASK; }

#endif

#ifndef AO_IR_ADCD3_ATTRIBUTE

#define AO_IR_ADCD3_ATTRIBUTE       __ISR(_ADC_DATA3_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD3_PRIO

#define AO_IR_ADCD3_PRIO            (4)

#endif

#ifndef AO_IR_ADCD3_SUBPRIO

#define AO_IR_ADCD3_SUBPRIO         (0)

#endif

#ifndef ao_ir_adcd3_disable

#define ao_ir_adcd3_disable()       { IEC1CLR = _IEC1_ADCD3IE_MASK; }

#endif

#ifndef ao_ir_adcd3_enable

#define ao_ir_adcd3_enable()        { IEC1SET = _IEC1_ADCD3IE_MASK; }

#endif

#ifndef ao_ir_adcd3_is_enabled

#define ao_ir_adcd3_is_enabled()    ((IEC1 & _IEC1_ADCD3IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd3_is_pending

#define ao_ir_adcd3_is_pending()    ((IFS1 & _IFS1_ADCD3IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd3_reply

#define ao_ir_adcd3_reply()         { IFS1CLR = _IFS1_ADCD3IF_MASK; }

#endif

#ifndef ao_ir_adcd3_request

#define ao_ir_adcd3_request()       { IFS1SET = _IFS1_ADCD3IF_MASK; }

#endif

#ifndef AO_IR_ADCD4_ATTRIBUTE

#define AO_IR_ADCD4_ATTRIBUTE       __ISR(_ADC_DATA4_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD4_PRIO

#define AO_IR_ADCD4_PRIO            (4)

#endif

#ifndef AO_IR_ADCD4_SUBPRIO

#define AO_IR_ADCD4_SUBPRIO         (0)

#endif

#ifndef ao_ir_adcd4_disable

#define ao_ir_adcd4_disable()       { IEC1CLR = _IEC1_ADCD4IE_MASK; }

#endif

#ifndef ao_ir_adcd4_enable

#define ao_ir_adcd4_enable()        { IEC1SET = _IEC1_ADCD4IE_MASK; }

#endif

#ifndef ao_ir_adcd4_is_enabled

#define ao_ir_adcd4_is_enabled()    ((IEC1 & _IEC1_ADCD4IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd4_is_pending

#define ao_ir_adcd4_is_pending()    ((IFS1 & _IFS1_ADCD4IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd4_reply

#define ao_ir_adcd4_reply()         { IFS1CLR = _IFS1_ADCD4IF_MASK; }

#endif

#ifndef ao_ir_adcd4_request

#define ao_ir_adcd4_request()       { IFS1SET = _IFS1_ADCD4IF_MASK; }

#endif

#ifndef AO_IR_ADCD5_ATTRIBUTE

#define AO_IR_ADCD5_ATTRIBUTE       __ISR(_ADC_DATA5_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD5_PRIO

#define AO_IR_ADCD5_PRIO            (4)

#endif

#ifndef AO_IR_ADCD5_SUBPRIO

#define AO_IR_ADCD5_SUBPRIO         (0)

#endif

#ifndef ao_ir_adcd5_disable

#define ao_ir_adcd5_disable()       { IEC2CLR = _IEC2_ADCD5IE_MASK; }

#endif

#ifndef ao_ir_adcd5_enable

#define ao_ir_adcd5_enable()        { IEC2SET = _IEC2_ADCD5IE_MASK; }

#endif

#ifndef ao_ir_adcd5_is_enabled

#define ao_ir_adcd5_is_enabled()    ((IEC2 & _IEC2_ADCD5IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd5_is_pending

#define ao_ir_adcd5_is_pending()    ((IFS2 & _IFS2_ADCD5IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd5_reply

#define ao_ir_adcd5_reply()         { IFS2CLR = _IFS2_ADCD5IF_MASK; }

#endif

#ifndef ao_ir_adcd5_request

#define ao_ir_adcd5_request()       { IFS2SET = _IFS2_ADCD5IF_MASK; }

#endif

#ifndef AO_IR_ADCD6_ATTRIBUTE

#define AO_IR_ADCD6_ATTRIBUTE       __ISR(_ADC_DATA6_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD6_PRIO

#define AO_IR_ADCD6_PRIO            (4)

#endif

#ifndef AO_IR_ADCD6_SUBPRIO

#define AO_IR_ADCD6_SUBPRIO         (0)

#endif

#ifndef ao_ir_adcd6_disable

#define ao_ir_adcd6_disable()       { IEC2CLR = _IEC2_ADCD6IE_MASK; }

#endif

#ifndef ao_ir_adcd6_enable

#define ao_ir_adcd6_enable()        { IEC2SET = _IEC2_ADCD6IE_MASK; }

#endif

#ifndef ao_ir_adcd6_is_enabled

#define ao_ir_adcd6_is_enabled()    ((IEC2 & _IEC2_ADCD6IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd6_is_pending

#define ao_ir_adcd6_is_pending()    ((IFS2 & _IFS2_ADCD6IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd6_reply

#define ao_ir_adcd6_reply()         { IFS2CLR = _IFS2_ADCD6IF_MASK; }

#endif

#ifndef ao_ir_adcd6_request

#define ao_ir_adcd6_request()       { IFS2SET = _IFS2_ADCD6IF_MASK; }

#endif

#ifndef AO_IR_ADCD7_ATTRIBUTE

#define AO_IR_ADCD7_ATTRIBUTE       __ISR(_ADC_DATA7_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD7_PRIO

#define AO_IR_ADCD7_PRIO            (4)

#endif

#ifndef AO_IR_ADCD7_SUBPRIO

#define AO_IR_ADCD7_SUBPRIO         (0)

#endif

#ifndef ao_ir_adcd7_disable

#define ao_ir_adcd7_disable()       { IEC2CLR = _IEC2_ADCD7IE_MASK; }

#endif

#ifndef ao_ir_adcd7_enable

#define ao_ir_adcd7_enable()        { IEC2SET = _IEC2_ADCD7IE_MASK; }

#endif

#ifndef ao_ir_adcd7_is_enabled

#define ao_ir_adcd7_is_enabled()    ((IEC2 & _IEC2_ADCD7IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd7_is_pending

#define ao_ir_adcd7_is_pending()    ((IFS2 & _IFS2_ADCD7IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd7_reply

#define ao_ir_adcd7_reply()         { IFS2CLR = _IFS2_ADCD7IF_MASK; }

#endif

#ifndef ao_ir_adcd7_request

#define ao_ir_adcd7_request()       { IFS2SET = _IFS2_ADCD7IF_MASK; }

#endif

#ifndef AO_IR_ADCD8_ATTRIBUTE

#define AO_IR_ADCD8_ATTRIBUTE       __ISR(_ADC_DATA8_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD8_PRIO

#define AO_IR_ADCD8_PRIO            (4)

#endif

#ifndef AO_IR_ADCD8_SUBPRIO

#define AO_IR_ADCD8_SUBPRIO         (0)

#endif

#ifndef ao_ir_adcd8_disable

#define ao_ir_adcd8_disable()       { IEC2CLR = _IEC2_ADCD8IE_MASK; }

#endif

#ifndef ao_ir_adcd8_enable

#define ao_ir_adcd8_enable()        { IEC2SET = _IEC2_ADCD8IE_MASK; }

#endif

#ifndef ao_ir_adcd8_is_enabled

#define ao_ir_adcd8_is_enabled()    ((IEC2 & _IEC2_ADCD8IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd8_is_pending

#define ao_ir_adcd8_is_pending()    ((IFS2 & _IFS2_ADCD8IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd8_reply

#define ao_ir_adcd8_reply()         { IFS2CLR = _IFS2_ADCD8IF_MASK; }

#endif

#ifndef ao_ir_adcd8_request

#define ao_ir_adcd8_request()       { IFS2SET = _IFS2_ADCD8IF_MASK; }

#endif

#ifndef AO_IR_ADCD9_ATTRIBUTE

#define AO_IR_ADCD9_ATTRIBUTE       __ISR(_ADC_DATA9_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD9_PRIO

#define AO_IR_ADCD9_PRIO            (4)

#endif

#ifndef AO_IR_ADCD9_SUBPRIO

#define AO_IR_ADCD9_SUBPRIO         (0)

#endif

#ifndef ao_ir_adcd9_disable

#define ao_ir_adcd9_disable()       { IEC2CLR = _IEC2_ADCD9IE_MASK; }

#endif

#ifndef ao_ir_adcd9_enable

#define ao_ir_adcd9_enable()        { IEC2SET = _IEC2_ADCD9IE_MASK; }

#endif

#ifndef ao_ir_adcd9_is_enabled

#define ao_ir_adcd9_is_enabled()    ((IEC2 & _IEC2_ADCD9IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd9_is_pending

#define ao_ir_adcd9_is_pending()    ((IFS2 & _IFS2_ADCD9IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd9_reply

#define ao_ir_adcd9_reply()         { IFS2CLR = _IFS2_ADCD9IF_MASK; }

#endif

#ifndef ao_ir_adcd9_request

#define ao_ir_adcd9_request()       { IFS2SET = _IFS2_ADCD9IF_MASK; }

#endif

#ifndef AO_IR_ADCD10_ATTRIBUTE

#define AO_IR_ADCD10_ATTRIBUTE      __ISR(_ADC_DATA10_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD10_PRIO

#define AO_IR_ADCD10_PRIO           (4)

#endif

#ifndef AO_IR_ADCD10_SUBPRIO

#define AO_IR_ADCD10_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcd10_disable

#define ao_ir_adcd10_disable()      { IEC2CLR = _IEC2_ADCD10IE_MASK; }

#endif

#ifndef ao_ir_adcd10_enable

#define ao_ir_adcd10_enable()       { IEC2SET = _IEC2_ADCD10IE_MASK; }

#endif

#ifndef ao_ir_adcd10_is_enabled

#define ao_ir_adcd10_is_enabled()   ((IEC2 & _IEC2_ADCD10IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd10_is_pending

#define ao_ir_adcd10_is_pending()   ((IFS2 & _IFS2_ADCD10IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd10_reply

#define ao_ir_adcd10_reply()        { IFS2CLR = _IFS2_ADCD10IF_MASK; }

#endif

#ifndef ao_ir_adcd10_request

#define ao_ir_adcd10_request()      { IFS2SET = _IFS2_ADCD10IF_MASK; }

#endif

#ifndef AO_IR_ADCD11_ATTRIBUTE

#define AO_IR_ADCD11_ATTRIBUTE      __ISR(_ADC_DATA11_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD11_PRIO

#define AO_IR_ADCD11_PRIO           (4)

#endif

#ifndef AO_IR_ADCD11_SUBPRIO

#define AO_IR_ADCD11_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcd11_disable

#define ao_ir_adcd11_disable()      { IEC2CLR = _IEC2_ADCD11IE_MASK; }

#endif

#ifndef ao_ir_adcd11_enable

#define ao_ir_adcd11_enable()       { IEC2SET = _IEC2_ADCD11IE_MASK; }

#endif

#ifndef ao_ir_adcd11_is_enabled

#define ao_ir_adcd11_is_enabled()   ((IEC2 & _IEC2_ADCD11IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd11_is_pending

#define ao_ir_adcd11_is_pending()   ((IFS2 & _IFS2_ADCD11IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd11_reply

#define ao_ir_adcd11_reply()        { IFS2CLR = _IFS2_ADCD11IF_MASK; }

#endif

#ifndef ao_ir_adcd11_request

#define ao_ir_adcd11_request()      { IFS2SET = _IFS2_ADCD11IF_MASK; }

#endif

#ifndef AO_IR_ADCD12_ATTRIBUTE

#define AO_IR_ADCD12_ATTRIBUTE      __ISR(_ADC_DATA12_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD12_PRIO

#define AO_IR_ADCD12_PRIO           (4)

#endif

#ifndef AO_IR_ADCD12_SUBPRIO

#define AO_IR_ADCD12_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcd12_disable

#define ao_ir_adcd12_disable()      { IEC2CLR = _IEC2_ADCD12IE_MASK; }

#endif

#ifndef ao_ir_adcd12_enable

#define ao_ir_adcd12_enable()       { IEC2SET = _IEC2_ADCD12IE_MASK; }

#endif

#ifndef ao_ir_adcd12_is_enabled

#define ao_ir_adcd12_is_enabled()   ((IEC2 & _IEC2_ADCD12IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd12_is_pending

#define ao_ir_adcd12_is_pending()   ((IFS2 & _IFS2_ADCD12IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd12_reply

#define ao_ir_adcd12_reply()        { IFS2CLR = _IFS2_ADCD12IF_MASK; }

#endif

#ifndef ao_ir_adcd12_request

#define ao_ir_adcd12_request()      { IFS2SET = _IFS2_ADCD12IF_MASK; }

#endif

#ifndef AO_IR_ADCD13_ATTRIBUTE

#define AO_IR_ADCD13_ATTRIBUTE      __ISR(_ADC_DATA13_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD13_PRIO

#define AO_IR_ADCD13_PRIO           (4)

#endif

#ifndef AO_IR_ADCD13_SUBPRIO

#define AO_IR_ADCD13_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcd13_disable

#define ao_ir_adcd13_disable()      { IEC2CLR = _IEC2_ADCD13IE_MASK; }

#endif

#ifndef ao_ir_adcd13_enable

#define ao_ir_adcd13_enable()       { IEC2SET = _IEC2_ADCD13IE_MASK; }

#endif

#ifndef ao_ir_adcd13_is_enabled

#define ao_ir_adcd13_is_enabled()   ((IEC2 & _IEC2_ADCD13IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd13_is_pending

#define ao_ir_adcd13_is_pending()   ((IFS2 & _IFS2_ADCD13IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd13_reply

#define ao_ir_adcd13_reply()        { IFS2CLR = _IFS2_ADCD13IF_MASK; }

#endif

#ifndef ao_ir_adcd13_request

#define ao_ir_adcd13_request()      { IFS2SET = _IFS2_ADCD13IF_MASK; }

#endif

#ifndef AO_IR_ADCD14_ATTRIBUTE

#define AO_IR_ADCD14_ATTRIBUTE      __ISR(_ADC_DATA14_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD14_PRIO

#define AO_IR_ADCD14_PRIO           (4)

#endif

#ifndef AO_IR_ADCD14_SUBPRIO

#define AO_IR_ADCD14_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcd14_disable

#define ao_ir_adcd14_disable()      { IEC2CLR = _IEC2_ADCD14IE_MASK; }

#endif

#ifndef ao_ir_adcd14_enable

#define ao_ir_adcd14_enable()       { IEC2SET = _IEC2_ADCD14IE_MASK; }

#endif

#ifndef ao_ir_adcd14_is_enabled

#define ao_ir_adcd14_is_enabled()   ((IEC2 & _IEC2_ADCD14IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd14_is_pending

#define ao_ir_adcd14_is_pending()   ((IFS2 & _IFS2_ADCD14IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd14_reply

#define ao_ir_adcd14_reply()        { IFS2CLR = _IFS2_ADCD14IF_MASK; }

#endif

#ifndef ao_ir_adcd14_request

#define ao_ir_adcd14_request()      { IFS2SET = _IFS2_ADCD14IF_MASK; }

#endif

#ifndef AO_IR_ADCD15_ATTRIBUTE

#define AO_IR_ADCD15_ATTRIBUTE      __ISR(_ADC_DATA15_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD15_PRIO

#define AO_IR_ADCD15_PRIO           (4)

#endif

#ifndef AO_IR_ADCD15_SUBPRIO

#define AO_IR_ADCD15_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcd15_disable

#define ao_ir_adcd15_disable()      { IEC2CLR = _IEC2_ADCD15IE_MASK; }

#endif

#ifndef ao_ir_adcd15_enable

#define ao_ir_adcd15_enable()       { IEC2SET = _IEC2_ADCD15IE_MASK; }

#endif

#ifndef ao_ir_adcd15_is_enabled

#define ao_ir_adcd15_is_enabled()   ((IEC2 & _IEC2_ADCD15IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd15_is_pending

#define ao_ir_adcd15_is_pending()   ((IFS2 & _IFS2_ADCD15IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd15_reply

#define ao_ir_adcd15_reply()        { IFS2CLR = _IFS2_ADCD15IF_MASK; }

#endif

#ifndef ao_ir_adcd15_request

#define ao_ir_adcd15_request()      { IFS2SET = _IFS2_ADCD15IF_MASK; }

#endif

#ifndef AO_IR_ADCD16_ATTRIBUTE

#define AO_IR_ADCD16_ATTRIBUTE      __ISR(_ADC_DATA16_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD16_PRIO

#define AO_IR_ADCD16_PRIO           (4)

#endif

#ifndef AO_IR_ADCD16_SUBPRIO

#define AO_IR_ADCD16_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcd16_disable

#define ao_ir_adcd16_disable()      { IEC2CLR = _IEC2_ADCD16IE_MASK; }

#endif

#ifndef ao_ir_adcd16_enable

#define ao_ir_adcd16_enable()       { IEC2SET = _IEC2_ADCD16IE_MASK; }

#endif

#ifndef ao_ir_adcd16_is_enabled

#define ao_ir_adcd16_is_enabled()   ((IEC2 & _IEC2_ADCD16IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd16_is_pending

#define ao_ir_adcd16_is_pending()   ((IFS2 & _IFS2_ADCD16IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd16_reply

#define ao_ir_adcd16_reply()        { IFS2CLR = _IFS2_ADCD16IF_MASK; }

#endif

#ifndef ao_ir_adcd16_request

#define ao_ir_adcd16_request()      { IFS2SET = _IFS2_ADCD16IF_MASK; }

#endif

#ifndef AO_IR_ADCD17_ATTRIBUTE

#define AO_IR_ADCD17_ATTRIBUTE      __ISR(_ADC_DATA17_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD17_PRIO

#define AO_IR_ADCD17_PRIO           (4)

#endif

#ifndef AO_IR_ADCD17_SUBPRIO

#define AO_IR_ADCD17_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcd17_disable

#define ao_ir_adcd17_disable()      { IEC2CLR = _IEC2_ADCD17IE_MASK; }

#endif

#ifndef ao_ir_adcd17_enable

#define ao_ir_adcd17_enable()       { IEC2SET = _IEC2_ADCD17IE_MASK; }

#endif

#ifndef ao_ir_adcd17_is_enabled

#define ao_ir_adcd17_is_enabled()   ((IEC2 & _IEC2_ADCD17IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd17_is_pending

#define ao_ir_adcd17_is_pending()   ((IFS2 & _IFS2_ADCD17IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd17_reply

#define ao_ir_adcd17_reply()        { IFS2CLR = _IFS2_ADCD17IF_MASK; }

#endif

#ifndef ao_ir_adcd17_request

#define ao_ir_adcd17_request()      { IFS2SET = _IFS2_ADCD17IF_MASK; }

#endif

#ifndef AO_IR_ADCD18_ATTRIBUTE

#define AO_IR_ADCD18_ATTRIBUTE      __ISR(_ADC_DATA18_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD18_PRIO

#define AO_IR_ADCD18_PRIO           (4)

#endif

#ifndef AO_IR_ADCD18_SUBPRIO

#define AO_IR_ADCD18_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcd18_disable

#define ao_ir_adcd18_disable()      { IEC2CLR = _IEC2_ADCD18IE_MASK; }

#endif

#ifndef ao_ir_adcd18_enable

#define ao_ir_adcd18_enable()       { IEC2SET = _IEC2_ADCD18IE_MASK; }

#endif

#ifndef ao_ir_adcd18_is_enabled

#define ao_ir_adcd18_is_enabled()   ((IEC2 & _IEC2_ADCD18IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd18_is_pending

#define ao_ir_adcd18_is_pending()   ((IFS2 & _IFS2_ADCD18IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd18_reply

#define ao_ir_adcd18_reply()        { IFS2CLR = _IFS2_ADCD18IF_MASK; }

#endif

#ifndef ao_ir_adcd18_request

#define ao_ir_adcd18_request()      { IFS2SET = _IFS2_ADCD18IF_MASK; }

#endif

#ifndef AO_IR_ADCD19_ATTRIBUTE

#define AO_IR_ADCD19_ATTRIBUTE      __ISR(_ADC_DATA19_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD19_PRIO

#define AO_IR_ADCD19_PRIO           (4)

#endif

#ifndef AO_IR_ADCD19_SUBPRIO

#define AO_IR_ADCD19_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcd19_disable

#define ao_ir_adcd19_disable()      { IEC2CLR = _IEC2_ADCD19IE_MASK; }

#endif

#ifndef ao_ir_adcd19_enable

#define ao_ir_adcd19_enable()       { IEC2SET = _IEC2_ADCD19IE_MASK; }

#endif

#ifndef ao_ir_adcd19_is_enabled

#define ao_ir_adcd19_is_enabled()   ((IEC2 & _IEC2_ADCD19IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd19_is_pending

#define ao_ir_adcd19_is_pending()   ((IFS2 & _IFS2_ADCD19IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd19_reply

#define ao_ir_adcd19_reply()        { IFS2CLR = _IFS2_ADCD19IF_MASK; }

#endif

#ifndef ao_ir_adcd19_request

#define ao_ir_adcd19_request()      { IFS2SET = _IFS2_ADCD19IF_MASK; }

#endif

#ifndef AO_IR_ADCD20_ATTRIBUTE

#define AO_IR_ADCD20_ATTRIBUTE      __ISR(_ADC_DATA20_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD20_PRIO

#define AO_IR_ADCD20_PRIO           (4)

#endif

#ifndef AO_IR_ADCD20_SUBPRIO

#define AO_IR_ADCD20_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcd20_disable

#define ao_ir_adcd20_disable()      { IEC2CLR = _IEC2_ADCD20IE_MASK; }

#endif

#ifndef ao_ir_adcd20_enable

#define ao_ir_adcd20_enable()       { IEC2SET = _IEC2_ADCD20IE_MASK; }

#endif

#ifndef ao_ir_adcd20_is_enabled

#define ao_ir_adcd20_is_enabled()   ((IEC2 & _IEC2_ADCD20IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd20_is_pending

#define ao_ir_adcd20_is_pending()   ((IFS2 & _IFS2_ADCD20IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd20_reply

#define ao_ir_adcd20_reply()        { IFS2CLR = _IFS2_ADCD20IF_MASK; }

#endif

#ifndef ao_ir_adcd20_request

#define ao_ir_adcd20_request()      { IFS2SET = _IFS2_ADCD20IF_MASK; }

#endif

#ifndef AO_IR_ADCD21_ATTRIBUTE

#define AO_IR_ADCD21_ATTRIBUTE      __ISR(_ADC_DATA21_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD21_PRIO

#define AO_IR_ADCD21_PRIO           (4)

#endif

#ifndef AO_IR_ADCD21_SUBPRIO

#define AO_IR_ADCD21_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcd21_disable

#define ao_ir_adcd21_disable()      { IEC2CLR = _IEC2_ADCD21IE_MASK; }

#endif

#ifndef ao_ir_adcd21_enable

#define ao_ir_adcd21_enable()       { IEC2SET = _IEC2_ADCD21IE_MASK; }

#endif

#ifndef ao_ir_adcd21_is_enabled

#define ao_ir_adcd21_is_enabled()   ((IEC2 & _IEC2_ADCD21IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd21_is_pending

#define ao_ir_adcd21_is_pending()   ((IFS2 & _IFS2_ADCD21IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd21_reply

#define ao_ir_adcd21_reply()        { IFS2CLR = _IFS2_ADCD21IF_MASK; }

#endif

#ifndef ao_ir_adcd21_request

#define ao_ir_adcd21_request()      { IFS2SET = _IFS2_ADCD21IF_MASK; }

#endif

#ifndef AO_IR_ADCD22_ATTRIBUTE

#define AO_IR_ADCD22_ATTRIBUTE      __ISR(_ADC_DATA22_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD22_PRIO

#define AO_IR_ADCD22_PRIO           (4)

#endif

#ifndef AO_IR_ADCD22_SUBPRIO

#define AO_IR_ADCD22_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcd22_disable

#define ao_ir_adcd22_disable()      { IEC2CLR = _IEC2_ADCD22IE_MASK; }

#endif

#ifndef ao_ir_adcd22_enable

#define ao_ir_adcd22_enable()       { IEC2SET = _IEC2_ADCD22IE_MASK; }

#endif

#ifndef ao_ir_adcd22_is_enabled

#define ao_ir_adcd22_is_enabled()   ((IEC2 & _IEC2_ADCD22IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd22_is_pending

#define ao_ir_adcd22_is_pending()   ((IFS2 & _IFS2_ADCD22IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd22_reply

#define ao_ir_adcd22_reply()        { IFS2CLR = _IFS2_ADCD22IF_MASK; }

#endif

#ifndef ao_ir_adcd22_request

#define ao_ir_adcd22_request()      { IFS2SET = _IFS2_ADCD22IF_MASK; }

#endif

#ifndef AO_IR_ADCD23_ATTRIBUTE

#define AO_IR_ADCD23_ATTRIBUTE      __ISR(_ADC_DATA23_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD23_PRIO

#define AO_IR_ADCD23_PRIO           (4)

#endif

#ifndef AO_IR_ADCD23_SUBPRIO

#define AO_IR_ADCD23_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcd23_disable

#define ao_ir_adcd23_disable()      { IEC2CLR = _IEC2_ADCD23IE_MASK; }

#endif

#ifndef ao_ir_adcd23_enable

#define ao_ir_adcd23_enable()       { IEC2SET = _IEC2_ADCD23IE_MASK; }

#endif

#ifndef ao_ir_adcd23_is_enabled

#define ao_ir_adcd23_is_enabled()   ((IEC2 & _IEC2_ADCD23IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd23_is_pending

#define ao_ir_adcd23_is_pending()   ((IFS2 & _IFS2_ADCD23IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd23_reply

#define ao_ir_adcd23_reply()        { IFS2CLR = _IFS2_ADCD23IF_MASK; }

#endif

#ifndef ao_ir_adcd23_request

#define ao_ir_adcd23_request()      { IFS2SET = _IFS2_ADCD23IF_MASK; }

#endif

#ifndef AO_IR_ADCD24_ATTRIBUTE

#define AO_IR_ADCD24_ATTRIBUTE      __ISR(_ADC_DATA24_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD24_PRIO

#define AO_IR_ADCD24_PRIO           (4)

#endif

#ifndef AO_IR_ADCD24_SUBPRIO

#define AO_IR_ADCD24_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcd24_disable

#define ao_ir_adcd24_disable()      { IEC2CLR = _IEC2_ADCD24IE_MASK; }

#endif

#ifndef ao_ir_adcd24_enable

#define ao_ir_adcd24_enable()       { IEC2SET = _IEC2_ADCD24IE_MASK; }

#endif

#ifndef ao_ir_adcd24_is_enabled

#define ao_ir_adcd24_is_enabled()   ((IEC2 & _IEC2_ADCD24IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd24_is_pending

#define ao_ir_adcd24_is_pending()   ((IFS2 & _IFS2_ADCD24IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd24_reply

#define ao_ir_adcd24_reply()        { IFS2CLR = _IFS2_ADCD24IF_MASK; }

#endif

#ifndef ao_ir_adcd24_request

#define ao_ir_adcd24_request()      { IFS2SET = _IFS2_ADCD24IF_MASK; }

#endif

#ifndef AO_IR_ADCD25_ATTRIBUTE

#define AO_IR_ADCD25_ATTRIBUTE      __ISR(_ADC_DATA25_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD25_PRIO

#define AO_IR_ADCD25_PRIO           (4)

#endif

#ifndef AO_IR_ADCD25_SUBPRIO

#define AO_IR_ADCD25_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcd25_disable

#define ao_ir_adcd25_disable()      { IEC2CLR = _IEC2_ADCD25IE_MASK; }

#endif

#ifndef ao_ir_adcd25_enable

#define ao_ir_adcd25_enable()       { IEC2SET = _IEC2_ADCD25IE_MASK; }

#endif

#ifndef ao_ir_adcd25_is_enabled

#define ao_ir_adcd25_is_enabled()   ((IEC2 & _IEC2_ADCD25IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd25_is_pending

#define ao_ir_adcd25_is_pending()   ((IFS2 & _IFS2_ADCD25IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd25_reply

#define ao_ir_adcd25_reply()        { IFS2CLR = _IFS2_ADCD25IF_MASK; }

#endif

#ifndef ao_ir_adcd25_request

#define ao_ir_adcd25_request()      { IFS2SET = _IFS2_ADCD25IF_MASK; }

#endif

#ifndef AO_IR_ADCD26_ATTRIBUTE

#define AO_IR_ADCD26_ATTRIBUTE      __ISR(_ADC_DATA26_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD26_PRIO

#define AO_IR_ADCD26_PRIO           (4)

#endif

#ifndef AO_IR_ADCD26_SUBPRIO

#define AO_IR_ADCD26_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcd26_disable

#define ao_ir_adcd26_disable()      { IEC2CLR = _IEC2_ADCD26IE_MASK; }

#endif

#ifndef ao_ir_adcd26_enable

#define ao_ir_adcd26_enable()       { IEC2SET = _IEC2_ADCD26IE_MASK; }

#endif

#ifndef ao_ir_adcd26_is_enabled

#define ao_ir_adcd26_is_enabled()   ((IEC2 & _IEC2_ADCD26IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd26_is_pending

#define ao_ir_adcd26_is_pending()   ((IFS2 & _IFS2_ADCD26IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd26_reply

#define ao_ir_adcd26_reply()        { IFS2CLR = _IFS2_ADCD26IF_MASK; }

#endif

#ifndef ao_ir_adcd26_request

#define ao_ir_adcd26_request()      { IFS2SET = _IFS2_ADCD26IF_MASK; }

#endif

#ifndef AO_IR_ADCD27_ATTRIBUTE

#define AO_IR_ADCD27_ATTRIBUTE      __ISR(_ADC_DATA27_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD27_PRIO

#define AO_IR_ADCD27_PRIO           (4)

#endif

#ifndef AO_IR_ADCD27_SUBPRIO

#define AO_IR_ADCD27_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcd27_disable

#define ao_ir_adcd27_disable()      { IEC2CLR = _IEC2_ADCD27IE_MASK; }

#endif

#ifndef ao_ir_adcd27_enable

#define ao_ir_adcd27_enable()       { IEC2SET = _IEC2_ADCD27IE_MASK; }

#endif

#ifndef ao_ir_adcd27_is_enabled

#define ao_ir_adcd27_is_enabled()   ((IEC2 & _IEC2_ADCD27IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd27_is_pending

#define ao_ir_adcd27_is_pending()   ((IFS2 & _IFS2_ADCD27IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd27_reply

#define ao_ir_adcd27_reply()        { IFS2CLR = _IFS2_ADCD27IF_MASK; }

#endif

#ifndef ao_ir_adcd27_request

#define ao_ir_adcd27_request()      { IFS2SET = _IFS2_ADCD27IF_MASK; }

#endif

#ifndef AO_IR_ADCD28_ATTRIBUTE

#define AO_IR_ADCD28_ATTRIBUTE      __ISR(_ADC_DATA28_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD28_PRIO

#define AO_IR_ADCD28_PRIO           (4)

#endif

#ifndef AO_IR_ADCD28_SUBPRIO

#define AO_IR_ADCD28_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcd28_disable

#define ao_ir_adcd28_disable()      { IEC2CLR = _IEC2_ADCD28IE_MASK; }

#endif

#ifndef ao_ir_adcd28_enable

#define ao_ir_adcd28_enable()       { IEC2SET = _IEC2_ADCD28IE_MASK; }

#endif

#ifndef ao_ir_adcd28_is_enabled

#define ao_ir_adcd28_is_enabled()   ((IEC2 & _IEC2_ADCD28IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd28_is_pending

#define ao_ir_adcd28_is_pending()   ((IFS2 & _IFS2_ADCD28IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd28_reply

#define ao_ir_adcd28_reply()        { IFS2CLR = _IFS2_ADCD28IF_MASK; }

#endif

#ifndef ao_ir_adcd28_request

#define ao_ir_adcd28_request()      { IFS2SET = _IFS2_ADCD28IF_MASK; }

#endif

#ifndef AO_IR_ADCD29_ATTRIBUTE

#define AO_IR_ADCD29_ATTRIBUTE      __ISR(_ADC_DATA29_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD29_PRIO

#define AO_IR_ADCD29_PRIO           (4)

#endif

#ifndef AO_IR_ADCD29_SUBPRIO

#define AO_IR_ADCD29_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcd29_disable

#define ao_ir_adcd29_disable()      { IEC2CLR = _IEC2_ADCD29IE_MASK; }

#endif

#ifndef ao_ir_adcd29_enable

#define ao_ir_adcd29_enable()       { IEC2SET = _IEC2_ADCD29IE_MASK; }

#endif

#ifndef ao_ir_adcd29_is_enabled

#define ao_ir_adcd29_is_enabled()   ((IEC2 & _IEC2_ADCD29IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd29_is_pending

#define ao_ir_adcd29_is_pending()   ((IFS2 & _IFS2_ADCD29IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd29_reply

#define ao_ir_adcd29_reply()        { IFS2CLR = _IFS2_ADCD29IF_MASK; }

#endif

#ifndef ao_ir_adcd29_request

#define ao_ir_adcd29_request()      { IFS2SET = _IFS2_ADCD29IF_MASK; }

#endif

#ifndef AO_IR_ADCD30_ATTRIBUTE

#define AO_IR_ADCD30_ATTRIBUTE      __ISR(_ADC_DATA30_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD30_PRIO

#define AO_IR_ADCD30_PRIO           (4)

#endif

#ifndef AO_IR_ADCD30_SUBPRIO

#define AO_IR_ADCD30_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcd30_disable

#define ao_ir_adcd30_disable()      { IEC2CLR = _IEC2_ADCD30IE_MASK; }

#endif

#ifndef ao_ir_adcd30_enable

#define ao_ir_adcd30_enable()       { IEC2SET = _IEC2_ADCD30IE_MASK; }

#endif

#ifndef ao_ir_adcd30_is_enabled

#define ao_ir_adcd30_is_enabled()   ((IEC2 & _IEC2_ADCD30IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd30_is_pending

#define ao_ir_adcd30_is_pending()   ((IFS2 & _IFS2_ADCD30IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd30_reply

#define ao_ir_adcd30_reply()        { IFS2CLR = _IFS2_ADCD30IF_MASK; }

#endif

#ifndef ao_ir_adcd30_request

#define ao_ir_adcd30_request()      { IFS2SET = _IFS2_ADCD30IF_MASK; }

#endif

#ifndef AO_IR_ADCD31_ATTRIBUTE

#define AO_IR_ADCD31_ATTRIBUTE      __ISR(_ADC_DATA31_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD31_PRIO

#define AO_IR_ADCD31_PRIO           (4)

#endif

#ifndef AO_IR_ADCD31_SUBPRIO

#define AO_IR_ADCD31_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcd31_disable

#define ao_ir_adcd31_disable()      { IEC2CLR = _IEC2_ADCD31IE_MASK; }

#endif

#ifndef ao_ir_adcd31_enable

#define ao_ir_adcd31_enable()       { IEC2SET = _IEC2_ADCD31IE_MASK; }

#endif

#ifndef ao_ir_adcd31_is_enabled

#define ao_ir_adcd31_is_enabled()   ((IEC2 & _IEC2_ADCD31IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd31_is_pending

#define ao_ir_adcd31_is_pending()   ((IFS2 & _IFS2_ADCD31IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd31_reply

#define ao_ir_adcd31_reply()        { IFS2CLR = _IFS2_ADCD31IF_MASK; }

#endif

#ifndef ao_ir_adcd31_request

#define ao_ir_adcd31_request()      { IFS2SET = _IFS2_ADCD31IF_MASK; }

#endif

#ifndef AO_IR_ADCD32_ATTRIBUTE

#define AO_IR_ADCD32_ATTRIBUTE      __ISR(_ADC_DATA32_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD32_PRIO

#define AO_IR_ADCD32_PRIO           (4)

#endif

#ifndef AO_IR_ADCD32_SUBPRIO

#define AO_IR_ADCD32_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcd32_disable

#define ao_ir_adcd32_disable()      { IEC2CLR = _IEC2_ADCD32IE_MASK; }

#endif

#ifndef ao_ir_adcd32_enable

#define ao_ir_adcd32_enable()       { IEC2SET = _IEC2_ADCD32IE_MASK; }

#endif

#ifndef ao_ir_adcd32_is_enabled

#define ao_ir_adcd32_is_enabled()   ((IEC2 & _IEC2_ADCD32IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd32_is_pending

#define ao_ir_adcd32_is_pending()   ((IFS2 & _IFS2_ADCD32IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd32_reply

#define ao_ir_adcd32_reply()        { IFS2CLR = _IFS2_ADCD32IF_MASK; }

#endif

#ifndef ao_ir_adcd32_request

#define ao_ir_adcd32_request()      { IFS2SET = _IFS2_ADCD32IF_MASK; }

#endif

#ifndef AO_IR_ADCD33_ATTRIBUTE

#define AO_IR_ADCD33_ATTRIBUTE      __ISR(_ADC_DATA33_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD33_PRIO

#define AO_IR_ADCD33_PRIO           (4)

#endif

#ifndef AO_IR_ADCD33_SUBPRIO

#define AO_IR_ADCD33_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcd33_disable

#define ao_ir_adcd33_disable()      { IEC2CLR = _IEC2_ADCD33IE_MASK; }

#endif

#ifndef ao_ir_adcd33_enable

#define ao_ir_adcd33_enable()       { IEC2SET = _IEC2_ADCD33IE_MASK; }

#endif

#ifndef ao_ir_adcd33_is_enabled

#define ao_ir_adcd33_is_enabled()   ((IEC2 & _IEC2_ADCD33IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd33_is_pending

#define ao_ir_adcd33_is_pending()   ((IFS2 & _IFS2_ADCD33IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd33_reply

#define ao_ir_adcd33_reply()        { IFS2CLR = _IFS2_ADCD33IF_MASK; }

#endif

#ifndef ao_ir_adcd33_request

#define ao_ir_adcd33_request()      { IFS2SET = _IFS2_ADCD33IF_MASK; }

#endif

#ifndef AO_IR_ADCD34_ATTRIBUTE

#define AO_IR_ADCD34_ATTRIBUTE      __ISR(_ADC_DATA34_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD34_PRIO

#define AO_IR_ADCD34_PRIO           (4)

#endif

#ifndef AO_IR_ADCD34_SUBPRIO

#define AO_IR_ADCD34_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcd34_disable

#define ao_ir_adcd34_disable()      { IEC2CLR = _IEC2_ADCD34IE_MASK; }

#endif

#ifndef ao_ir_adcd34_enable

#define ao_ir_adcd34_enable()       { IEC2SET = _IEC2_ADCD34IE_MASK; }

#endif

#ifndef ao_ir_adcd34_is_enabled

#define ao_ir_adcd34_is_enabled()   ((IEC2 & _IEC2_ADCD34IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd34_is_pending

#define ao_ir_adcd34_is_pending()   ((IFS2 & _IFS2_ADCD34IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd34_reply

#define ao_ir_adcd34_reply()        { IFS2CLR = _IFS2_ADCD34IF_MASK; }

#endif

#ifndef ao_ir_adcd34_request

#define ao_ir_adcd34_request()      { IFS2SET = _IFS2_ADCD34IF_MASK; }

#endif

#ifndef AO_IR_ADCD35_ATTRIBUTE

#define AO_IR_ADCD35_ATTRIBUTE      __ISR(_ADC_DATA35_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD35_PRIO

#define AO_IR_ADCD35_PRIO           (4)

#endif

#ifndef AO_IR_ADCD35_SUBPRIO

#define AO_IR_ADCD35_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcd35_disable

#define ao_ir_adcd35_disable()      { IEC2CLR = _IEC2_ADCD35IE_MASK; }

#endif

#ifndef ao_ir_adcd35_enable

#define ao_ir_adcd35_enable()       { IEC2SET = _IEC2_ADCD35IE_MASK; }

#endif

#ifndef ao_ir_adcd35_is_enabled

#define ao_ir_adcd35_is_enabled()   ((IEC2 & _IEC2_ADCD35IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd35_is_pending

#define ao_ir_adcd35_is_pending()   ((IFS2 & _IFS2_ADCD35IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd35_reply

#define ao_ir_adcd35_reply()        { IFS2CLR = _IFS2_ADCD35IF_MASK; }

#endif

#ifndef ao_ir_adcd35_request

#define ao_ir_adcd35_request()      { IFS2SET = _IFS2_ADCD35IF_MASK; }

#endif

#ifndef AO_IR_ADCD36_ATTRIBUTE

#define AO_IR_ADCD36_ATTRIBUTE      __ISR(_ADC_DATA36_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD36_PRIO

#define AO_IR_ADCD36_PRIO           (4)

#endif

#ifndef AO_IR_ADCD36_SUBPRIO

#define AO_IR_ADCD36_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcd36_disable

#define ao_ir_adcd36_disable()      { IEC2CLR = _IEC2_ADCD36IE_MASK; }

#endif

#ifndef ao_ir_adcd36_enable

#define ao_ir_adcd36_enable()       { IEC2SET = _IEC2_ADCD36IE_MASK; }

#endif

#ifndef ao_ir_adcd36_is_enabled

#define ao_ir_adcd36_is_enabled()   ((IEC2 & _IEC2_ADCD36IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd36_is_pending

#define ao_ir_adcd36_is_pending()   ((IFS2 & _IFS2_ADCD36IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd36_reply

#define ao_ir_adcd36_reply()        { IFS2CLR = _IFS2_ADCD36IF_MASK; }

#endif

#ifndef ao_ir_adcd36_request

#define ao_ir_adcd36_request()      { IFS2SET = _IFS2_ADCD36IF_MASK; }

#endif

#ifndef AO_IR_ADCD37_ATTRIBUTE

#define AO_IR_ADCD37_ATTRIBUTE      __ISR(_ADC_DATA37_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD37_PRIO

#define AO_IR_ADCD37_PRIO           (4)

#endif

#ifndef AO_IR_ADCD37_SUBPRIO

#define AO_IR_ADCD37_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcd37_disable

#define ao_ir_adcd37_disable()      { IEC3CLR = _IEC3_ADCD37IE_MASK; }

#endif

#ifndef ao_ir_adcd37_enable

#define ao_ir_adcd37_enable()       { IEC3SET = _IEC3_ADCD37IE_MASK; }

#endif

#ifndef ao_ir_adcd37_is_enabled

#define ao_ir_adcd37_is_enabled()   ((IEC3 & _IEC3_ADCD37IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd37_is_pending

#define ao_ir_adcd37_is_pending()   ((IFS3 & _IFS3_ADCD37IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd37_reply

#define ao_ir_adcd37_reply()        { IFS3CLR = _IFS3_ADCD37IF_MASK; }

#endif

#ifndef ao_ir_adcd37_request

#define ao_ir_adcd37_request()      { IFS3SET = _IFS3_ADCD37IF_MASK; }

#endif

#ifndef AO_IR_ADCD38_ATTRIBUTE

#define AO_IR_ADCD38_ATTRIBUTE      __ISR(_ADC_DATA38_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD38_PRIO

#define AO_IR_ADCD38_PRIO           (4)

#endif

#ifndef AO_IR_ADCD38_SUBPRIO

#define AO_IR_ADCD38_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcd38_disable

#define ao_ir_adcd38_disable()      { IEC3CLR = _IEC3_ADCD38IE_MASK; }

#endif

#ifndef ao_ir_adcd38_enable

#define ao_ir_adcd38_enable()       { IEC3SET = _IEC3_ADCD38IE_MASK; }

#endif

#ifndef ao_ir_adcd38_is_enabled

#define ao_ir_adcd38_is_enabled()   ((IEC3 & _IEC3_ADCD38IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd38_is_pending

#define ao_ir_adcd38_is_pending()   ((IFS3 & _IFS3_ADCD38IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd38_reply

#define ao_ir_adcd38_reply()        { IFS3CLR = _IFS3_ADCD38IF_MASK; }

#endif

#ifndef ao_ir_adcd38_request

#define ao_ir_adcd38_request()      { IFS3SET = _IFS3_ADCD38IF_MASK; }

#endif

#ifndef AO_IR_ADCD39_ATTRIBUTE

#define AO_IR_ADCD39_ATTRIBUTE      __ISR(_ADC_DATA39_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD39_PRIO

#define AO_IR_ADCD39_PRIO           (4)

#endif

#ifndef AO_IR_ADCD39_SUBPRIO

#define AO_IR_ADCD39_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcd39_disable

#define ao_ir_adcd39_disable()      { IEC3CLR = _IEC3_ADCD39IE_MASK; }

#endif

#ifndef ao_ir_adcd39_enable

#define ao_ir_adcd39_enable()       { IEC3SET = _IEC3_ADCD39IE_MASK; }

#endif

#ifndef ao_ir_adcd39_is_enabled

#define ao_ir_adcd39_is_enabled()   ((IEC3 & _IEC3_ADCD39IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd39_is_pending

#define ao_ir_adcd39_is_pending()   ((IFS3 & _IFS3_ADCD39IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd39_reply

#define ao_ir_adcd39_reply()        { IFS3CLR = _IFS3_ADCD39IF_MASK; }

#endif

#ifndef ao_ir_adcd39_request

#define ao_ir_adcd39_request()      { IFS3SET = _IFS3_ADCD39IF_MASK; }

#endif

#ifndef AO_IR_ADCD40_ATTRIBUTE

#define AO_IR_ADCD40_ATTRIBUTE      __ISR(_ADC_DATA40_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD40_PRIO

#define AO_IR_ADCD40_PRIO           (4)

#endif

#ifndef AO_IR_ADCD40_SUBPRIO

#define AO_IR_ADCD40_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcd40_disable

#define ao_ir_adcd40_disable()      { IEC3CLR = _IEC3_ADCD40IE_MASK; }

#endif

#ifndef ao_ir_adcd40_enable

#define ao_ir_adcd40_enable()       { IEC3SET = _IEC3_ADCD40IE_MASK; }

#endif

#ifndef ao_ir_adcd40_is_enabled

#define ao_ir_adcd40_is_enabled()   ((IEC3 & _IEC3_ADCD40IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd40_is_pending

#define ao_ir_adcd40_is_pending()   ((IFS3 & _IFS3_ADCD40IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd40_reply

#define ao_ir_adcd40_reply()        { IFS3CLR = _IFS3_ADCD40IF_MASK; }

#endif

#ifndef ao_ir_adcd40_request

#define ao_ir_adcd40_request()      { IFS3SET = _IFS3_ADCD40IF_MASK; }

#endif

#ifndef AO_IR_ADCD41_ATTRIBUTE

#define AO_IR_ADCD41_ATTRIBUTE      __ISR(_ADC_DATA41_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD41_PRIO

#define AO_IR_ADCD41_PRIO           (4)

#endif

#ifndef AO_IR_ADCD41_SUBPRIO

#define AO_IR_ADCD41_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcd41_disable

#define ao_ir_adcd41_disable()      { IEC3CLR = _IEC3_ADCD41IE_MASK; }

#endif

#ifndef ao_ir_adcd41_enable

#define ao_ir_adcd41_enable()       { IEC3SET = _IEC3_ADCD41IE_MASK; }

#endif

#ifndef ao_ir_adcd41_is_enabled

#define ao_ir_adcd41_is_enabled()   ((IEC3 & _IEC3_ADCD41IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd41_is_pending

#define ao_ir_adcd41_is_pending()   ((IFS3 & _IFS3_ADCD41IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd41_reply

#define ao_ir_adcd41_reply()        { IFS3CLR = _IFS3_ADCD41IF_MASK; }

#endif

#ifndef ao_ir_adcd41_request

#define ao_ir_adcd41_request()      { IFS3SET = _IFS3_ADCD41IF_MASK; }

#endif

#ifndef AO_IR_ADCD42_ATTRIBUTE

#define AO_IR_ADCD42_ATTRIBUTE      __ISR(_ADC_DATA42_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD42_PRIO

#define AO_IR_ADCD42_PRIO           (4)

#endif

#ifndef AO_IR_ADCD42_SUBPRIO

#define AO_IR_ADCD42_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcd42_disable

#define ao_ir_adcd42_disable()      { IEC3CLR = _IEC3_ADCD42IE_MASK; }

#endif

#ifndef ao_ir_adcd42_enable

#define ao_ir_adcd42_enable()       { IEC3SET = _IEC3_ADCD42IE_MASK; }

#endif

#ifndef ao_ir_adcd42_is_enabled

#define ao_ir_adcd42_is_enabled()   ((IEC3 & _IEC3_ADCD42IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd42_is_pending

#define ao_ir_adcd42_is_pending()   ((IFS3 & _IFS3_ADCD42IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd42_reply

#define ao_ir_adcd42_reply()        { IFS3CLR = _IFS3_ADCD42IF_MASK; }

#endif

#ifndef ao_ir_adcd42_request

#define ao_ir_adcd42_request()      { IFS3SET = _IFS3_ADCD42IF_MASK; }

#endif

#ifndef AO_IR_ADCD43_ATTRIBUTE

#define AO_IR_ADCD43_ATTRIBUTE      __ISR(_ADC_DATA43_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCD43_PRIO

#define AO_IR_ADCD43_PRIO           (4)

#endif

#ifndef AO_IR_ADCD43_SUBPRIO

#define AO_IR_ADCD43_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcd43_disable

#define ao_ir_adcd43_disable()      { IEC3CLR = _IEC3_ADCD43IE_MASK; }

#endif

#ifndef ao_ir_adcd43_enable

#define ao_ir_adcd43_enable()       { IEC3SET = _IEC3_ADCD43IE_MASK; }

#endif

#ifndef ao_ir_adcd43_is_enabled

#define ao_ir_adcd43_is_enabled()   ((IEC3 & _IEC3_ADCD43IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd43_is_pending

#define ao_ir_adcd43_is_pending()   ((IFS3 & _IFS3_ADCD43IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcd43_reply

#define ao_ir_adcd43_reply()        { IFS3CLR = _IFS3_ADCD43IF_MASK; }

#endif

#ifndef ao_ir_adcd43_request

#define ao_ir_adcd43_request()      { IFS3SET = _IFS3_ADCD43IF_MASK; }

#endif

#ifndef AO_IR_ADCDC1_ATTRIBUTE

#define AO_IR_ADCDC1_ATTRIBUTE      __ISR(_ADC_DC1_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCDC1_PRIO

#define AO_IR_ADCDC1_PRIO           (4)

#endif

#ifndef AO_IR_ADCDC1_SUBPRIO

#define AO_IR_ADCDC1_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcdc1_disable

#define ao_ir_adcdc1_disable()      { IEC1CLR = _IEC1_ADCDC1IE_MASK; }

#endif

#ifndef ao_ir_adcdc1_enable

#define ao_ir_adcdc1_enable()       { IEC1SET = _IEC1_ADCDC1IE_MASK; }

#endif

#ifndef ao_ir_adcdc1_is_enabled

#define ao_ir_adcdc1_is_enabled()   ((IEC1 & _IEC1_ADCDC1IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcdc1_is_pending

#define ao_ir_adcdc1_is_pending()   ((IFS1 & _IFS1_ADCDC1IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcdc1_reply

#define ao_ir_adcdc1_reply()        { IFS1CLR = _IFS1_ADCDC1IF_MASK; }

#endif

#ifndef ao_ir_adcdc1_request

#define ao_ir_adcdc1_request()      { IFS1SET = _IFS1_ADCDC1IF_MASK; }

#endif

#ifndef AO_IR_ADCDC2_ATTRIBUTE

#define AO_IR_ADCDC2_ATTRIBUTE      __ISR(_ADC_DC2_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCDC2_PRIO

#define AO_IR_ADCDC2_PRIO           (4)

#endif

#ifndef AO_IR_ADCDC2_SUBPRIO

#define AO_IR_ADCDC2_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcdc2_disable

#define ao_ir_adcdc2_disable()      { IEC1CLR = _IEC1_ADCDC2IE_MASK; }

#endif

#ifndef ao_ir_adcdc2_enable

#define ao_ir_adcdc2_enable()       { IEC1SET = _IEC1_ADCDC2IE_MASK; }

#endif

#ifndef ao_ir_adcdc2_is_enabled

#define ao_ir_adcdc2_is_enabled()   ((IEC1 & _IEC1_ADCDC2IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcdc2_is_pending

#define ao_ir_adcdc2_is_pending()   ((IFS1 & _IFS1_ADCDC2IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcdc2_reply

#define ao_ir_adcdc2_reply()        { IFS1CLR = _IFS1_ADCDC2IF_MASK; }

#endif

#ifndef ao_ir_adcdc2_request

#define ao_ir_adcdc2_request()      { IFS1SET = _IFS1_ADCDC2IF_MASK; }

#endif

#ifndef AO_IR_ADCDC3_ATTRIBUTE

#define AO_IR_ADCDC3_ATTRIBUTE      __ISR(_ADC_DC3_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCDC3_PRIO

#define AO_IR_ADCDC3_PRIO           (4)

#endif

#ifndef AO_IR_ADCDC3_SUBPRIO

#define AO_IR_ADCDC3_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcdc3_disable

#define ao_ir_adcdc3_disable()      { IEC1CLR = _IEC1_ADCDC3IE_MASK; }

#endif

#ifndef ao_ir_adcdc3_enable

#define ao_ir_adcdc3_enable()       { IEC1SET = _IEC1_ADCDC3IE_MASK; }

#endif

#ifndef ao_ir_adcdc3_is_enabled

#define ao_ir_adcdc3_is_enabled()   ((IEC1 & _IEC1_ADCDC3IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcdc3_is_pending

#define ao_ir_adcdc3_is_pending()   ((IFS1 & _IFS1_ADCDC3IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcdc3_reply

#define ao_ir_adcdc3_reply()        { IFS1CLR = _IFS1_ADCDC3IF_MASK; }

#endif

#ifndef ao_ir_adcdc3_request

#define ao_ir_adcdc3_request()      { IFS1SET = _IFS1_ADCDC3IF_MASK; }

#endif

#ifndef AO_IR_ADCDC4_ATTRIBUTE

#define AO_IR_ADCDC4_ATTRIBUTE      __ISR(_ADC_DC4_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCDC4_PRIO

#define AO_IR_ADCDC4_PRIO           (4)

#endif

#ifndef AO_IR_ADCDC4_SUBPRIO

#define AO_IR_ADCDC4_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcdc4_disable

#define ao_ir_adcdc4_disable()      { IEC1CLR = _IEC1_ADCDC4IE_MASK; }

#endif

#ifndef ao_ir_adcdc4_enable

#define ao_ir_adcdc4_enable()       { IEC1SET = _IEC1_ADCDC4IE_MASK; }

#endif

#ifndef ao_ir_adcdc4_is_enabled

#define ao_ir_adcdc4_is_enabled()   ((IEC1 & _IEC1_ADCDC4IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcdc4_is_pending

#define ao_ir_adcdc4_is_pending()   ((IFS1 & _IFS1_ADCDC4IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcdc4_reply

#define ao_ir_adcdc4_reply()        { IFS1CLR = _IFS1_ADCDC4IF_MASK; }

#endif

#ifndef ao_ir_adcdc4_request

#define ao_ir_adcdc4_request()      { IFS1SET = _IFS1_ADCDC4IF_MASK; }

#endif

#ifndef AO_IR_ADCDC5_ATTRIBUTE

#define AO_IR_ADCDC5_ATTRIBUTE      __ISR(_ADC_DC5_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCDC5_PRIO

#define AO_IR_ADCDC5_PRIO           (4)

#endif

#ifndef AO_IR_ADCDC5_SUBPRIO

#define AO_IR_ADCDC5_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcdc5_disable

#define ao_ir_adcdc5_disable()      { IEC1CLR = _IEC1_ADCDC5IE_MASK; }

#endif

#ifndef ao_ir_adcdc5_enable

#define ao_ir_adcdc5_enable()       { IEC1SET = _IEC1_ADCDC5IE_MASK; }

#endif

#ifndef ao_ir_adcdc5_is_enabled

#define ao_ir_adcdc5_is_enabled()   ((IEC1 & _IEC1_ADCDC5IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcdc5_is_pending

#define ao_ir_adcdc5_is_pending()   ((IFS1 & _IFS1_ADCDC5IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcdc5_reply

#define ao_ir_adcdc5_reply()        { IFS1CLR = _IFS1_ADCDC5IF_MASK; }

#endif

#ifndef ao_ir_adcdc5_request

#define ao_ir_adcdc5_request()      { IFS1SET = _IFS1_ADCDC5IF_MASK; }

#endif

#ifndef AO_IR_ADCDC6_ATTRIBUTE

#define AO_IR_ADCDC6_ATTRIBUTE      __ISR(_ADC_DC6_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCDC6_PRIO

#define AO_IR_ADCDC6_PRIO           (4)

#endif

#ifndef AO_IR_ADCDC6_SUBPRIO

#define AO_IR_ADCDC6_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcdc6_disable

#define ao_ir_adcdc6_disable()      { IEC1CLR = _IEC1_ADCDC6IE_MASK; }

#endif

#ifndef ao_ir_adcdc6_enable

#define ao_ir_adcdc6_enable()       { IEC1SET = _IEC1_ADCDC6IE_MASK; }

#endif

#ifndef ao_ir_adcdc6_is_enabled

#define ao_ir_adcdc6_is_enabled()   ((IEC1 & _IEC1_ADCDC6IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcdc6_is_pending

#define ao_ir_adcdc6_is_pending()   ((IFS1 & _IFS1_ADCDC6IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcdc6_reply

#define ao_ir_adcdc6_reply()        { IFS1CLR = _IFS1_ADCDC6IF_MASK; }

#endif

#ifndef ao_ir_adcdc6_request

#define ao_ir_adcdc6_request()      { IFS1SET = _IFS1_ADCDC6IF_MASK; }

#endif

#ifndef AO_IR_ADCDF1_ATTRIBUTE

#define AO_IR_ADCDF1_ATTRIBUTE      __ISR(_ADC_DF1_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCDF1_PRIO

#define AO_IR_ADCDF1_PRIO           (4)

#endif

#ifndef AO_IR_ADCDF1_SUBPRIO

#define AO_IR_ADCDF1_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcdf1_disable

#define ao_ir_adcdf1_disable()      { IEC1CLR = _IEC1_ADCDF1IE_MASK; }

#endif

#ifndef ao_ir_adcdf1_enable

#define ao_ir_adcdf1_enable()       { IEC1SET = _IEC1_ADCDF1IE_MASK; }

#endif

#ifndef ao_ir_adcdf1_is_enabled

#define ao_ir_adcdf1_is_enabled()   ((IEC1 & _IEC1_ADCDF1IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcdf1_is_pending

#define ao_ir_adcdf1_is_pending()   ((IFS1 & _IFS1_ADCDF1IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcdf1_reply

#define ao_ir_adcdf1_reply()        { IFS1CLR = _IFS1_ADCDF1IF_MASK; }

#endif

#ifndef ao_ir_adcdf1_request

#define ao_ir_adcdf1_request()      { IFS1SET = _IFS1_ADCDF1IF_MASK; }

#endif

#ifndef AO_IR_ADCDF2_ATTRIBUTE

#define AO_IR_ADCDF2_ATTRIBUTE      __ISR(_ADC_DF2_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCDF2_PRIO

#define AO_IR_ADCDF2_PRIO           (4)

#endif

#ifndef AO_IR_ADCDF2_SUBPRIO

#define AO_IR_ADCDF2_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcdf2_disable

#define ao_ir_adcdf2_disable()      { IEC1CLR = _IEC1_ADCDF2IE_MASK; }

#endif

#ifndef ao_ir_adcdf2_enable

#define ao_ir_adcdf2_enable()       { IEC1SET = _IEC1_ADCDF2IE_MASK; }

#endif

#ifndef ao_ir_adcdf2_is_enabled

#define ao_ir_adcdf2_is_enabled()   ((IEC1 & _IEC1_ADCDF2IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcdf2_is_pending

#define ao_ir_adcdf2_is_pending()   ((IFS1 & _IFS1_ADCDF2IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcdf2_reply

#define ao_ir_adcdf2_reply()        { IFS1CLR = _IFS1_ADCDF2IF_MASK; }

#endif

#ifndef ao_ir_adcdf2_request

#define ao_ir_adcdf2_request()      { IFS1SET = _IFS1_ADCDF2IF_MASK; }

#endif

#ifndef AO_IR_ADCDF3_ATTRIBUTE

#define AO_IR_ADCDF3_ATTRIBUTE      __ISR(_ADC_DF3_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCDF3_PRIO

#define AO_IR_ADCDF3_PRIO           (4)

#endif

#ifndef AO_IR_ADCDF3_SUBPRIO

#define AO_IR_ADCDF3_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcdf3_disable

#define ao_ir_adcdf3_disable()      { IEC1CLR = _IEC1_ADCDF3IE_MASK; }

#endif

#ifndef ao_ir_adcdf3_enable

#define ao_ir_adcdf3_enable()       { IEC1SET = _IEC1_ADCDF3IE_MASK; }

#endif

#ifndef ao_ir_adcdf3_is_enabled

#define ao_ir_adcdf3_is_enabled()   ((IEC1 & _IEC1_ADCDF3IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcdf3_is_pending

#define ao_ir_adcdf3_is_pending()   ((IFS1 & _IFS1_ADCDF3IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcdf3_reply

#define ao_ir_adcdf3_reply()        { IFS1CLR = _IFS1_ADCDF3IF_MASK; }

#endif

#ifndef ao_ir_adcdf3_request

#define ao_ir_adcdf3_request()      { IFS1SET = _IFS1_ADCDF3IF_MASK; }

#endif

#ifndef AO_IR_ADCDF4_ATTRIBUTE

#define AO_IR_ADCDF4_ATTRIBUTE      __ISR(_ADC_DF4_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCDF4_PRIO

#define AO_IR_ADCDF4_PRIO           (4)

#endif

#ifndef AO_IR_ADCDF4_SUBPRIO

#define AO_IR_ADCDF4_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcdf4_disable

#define ao_ir_adcdf4_disable()      { IEC1CLR = _IEC1_ADCDF4IE_MASK; }

#endif

#ifndef ao_ir_adcdf4_enable

#define ao_ir_adcdf4_enable()       { IEC1SET = _IEC1_ADCDF4IE_MASK; }

#endif

#ifndef ao_ir_adcdf4_is_enabled

#define ao_ir_adcdf4_is_enabled()   ((IEC1 & _IEC1_ADCDF4IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcdf4_is_pending

#define ao_ir_adcdf4_is_pending()   ((IFS1 & _IFS1_ADCDF4IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcdf4_reply

#define ao_ir_adcdf4_reply()        { IFS1CLR = _IFS1_ADCDF4IF_MASK; }

#endif

#ifndef ao_ir_adcdf4_request

#define ao_ir_adcdf4_request()      { IFS1SET = _IFS1_ADCDF4IF_MASK; }

#endif

#ifndef AO_IR_ADCDF5_ATTRIBUTE

#define AO_IR_ADCDF5_ATTRIBUTE      __ISR(_ADC_DF5_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCDF5_PRIO

#define AO_IR_ADCDF5_PRIO           (4)

#endif

#ifndef AO_IR_ADCDF5_SUBPRIO

#define AO_IR_ADCDF5_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcdf5_disable

#define ao_ir_adcdf5_disable()      { IEC1CLR = _IEC1_ADCDF5IE_MASK; }

#endif

#ifndef ao_ir_adcdf5_enable

#define ao_ir_adcdf5_enable()       { IEC1SET = _IEC1_ADCDF5IE_MASK; }

#endif

#ifndef ao_ir_adcdf5_is_enabled

#define ao_ir_adcdf5_is_enabled()   ((IEC1 & _IEC1_ADCDF5IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcdf5_is_pending

#define ao_ir_adcdf5_is_pending()   ((IFS1 & _IFS1_ADCDF5IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcdf5_reply

#define ao_ir_adcdf5_reply()        { IFS1CLR = _IFS1_ADCDF5IF_MASK; }

#endif

#ifndef ao_ir_adcdf5_request

#define ao_ir_adcdf5_request()      { IFS1SET = _IFS1_ADCDF5IF_MASK; }

#endif

#ifndef AO_IR_ADCDF6_ATTRIBUTE

#define AO_IR_ADCDF6_ATTRIBUTE      __ISR(_ADC_DF6_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCDF6_PRIO

#define AO_IR_ADCDF6_PRIO           (4)

#endif

#ifndef AO_IR_ADCDF6_SUBPRIO

#define AO_IR_ADCDF6_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcdf6_disable

#define ao_ir_adcdf6_disable()      { IEC1CLR = _IEC1_ADCDF6IE_MASK; }

#endif

#ifndef ao_ir_adcdf6_enable

#define ao_ir_adcdf6_enable()       { IEC1SET = _IEC1_ADCDF6IE_MASK; }

#endif

#ifndef ao_ir_adcdf6_is_enabled

#define ao_ir_adcdf6_is_enabled()   ((IEC1 & _IEC1_ADCDF6IE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcdf6_is_pending

#define ao_ir_adcdf6_is_pending()   ((IFS1 & _IFS1_ADCDF6IF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcdf6_reply

#define ao_ir_adcdf6_reply()        { IFS1CLR = _IFS1_ADCDF6IF_MASK; }

#endif

#ifndef ao_ir_adcdf6_request

#define ao_ir_adcdf6_request()      { IFS1SET = _IFS1_ADCDF6IF_MASK; }

#endif

#ifndef AO_IR_ADCEOS_ATTRIBUTE

#define AO_IR_ADCEOS_ATTRIBUTE      __ISR(_ADC_EOS_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCEOS_PRIO

#define AO_IR_ADCEOS_PRIO           (4)

#endif

#ifndef AO_IR_ADCEOS_SUBPRIO

#define AO_IR_ADCEOS_SUBPRIO        (0)

#endif

#ifndef ao_ir_adceos_disable

#define ao_ir_adceos_disable()      { IEC6CLR = _IEC6_ADCEOSIE_MASK; }

#endif

#ifndef ao_ir_adceos_enable

#define ao_ir_adceos_enable()       { IEC6SET = _IEC6_ADCEOSIE_MASK; }

#endif

#ifndef ao_ir_adceos_is_enabled

#define ao_ir_adceos_is_enabled()   ((IEC6 & _IEC6_ADCEOSIE_MASK) ? true : false)

#endif

#ifndef ao_ir_adceos_is_pending

#define ao_ir_adceos_is_pending()   ((IFS6 & _IFS6_ADCEOSIF_MASK) ? true : false)

#endif

#ifndef ao_ir_adceos_reply

#define ao_ir_adceos_reply()        { IFS6CLR = _IFS6_ADCEOSIF_MASK; }

#endif

#ifndef ao_ir_adceos_request

#define ao_ir_adceos_request()      { IFS6SET = _IFS6_ADCEOSIF_MASK; }

#endif

#ifndef AO_IR_ADCFIFO_ATTRIBUTE

#define AO_IR_ADCFIFO_ATTRIBUTE     __ISR(_ADC_FIFO_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCFIFO_PRIO

#define AO_IR_ADCFIFO_PRIO          (4)

#endif

#ifndef AO_IR_ADCFIFO_SUBPRIO

#define AO_IR_ADCFIFO_SUBPRIO       (0)

#endif

#ifndef ao_ir_adcfifo_disable

#define ao_ir_adcfifo_disable()     { IEC1CLR = _IEC1_ADCFIFOIE_MASK; }

#endif

#ifndef ao_ir_adcfifo_enable

#define ao_ir_adcfifo_enable()      { IEC1SET = _IEC1_ADCFIFOIE_MASK; }

#endif

#ifndef ao_ir_adcfifo_is_enabled

#define ao_ir_adcfifo_is_enabled()  ((IEC1 & _IEC1_ADCFIFOIE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcfifo_is_pending

#define ao_ir_adcfifo_is_pending()  ((IFS1 & _IFS1_ADCFIFOIF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcfifo_reply

#define ao_ir_adcfifo_reply()       { IFS1CLR = _IFS1_ADCFIFOIF_MASK; }

#endif

#ifndef ao_ir_adcfifo_request

#define ao_ir_adcfifo_request()     { IFS1SET = _IFS1_ADCFIFOIF_MASK; }

#endif

#ifndef AO_IR_ADCFLT_ATTRIBUTE

#define AO_IR_ADCFLT_ATTRIBUTE      __ISR(_ADC_FAULT_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCFLT_PRIO

#define AO_IR_ADCFLT_PRIO           (4)

#endif

#ifndef AO_IR_ADCFLT_SUBPRIO

#define AO_IR_ADCFLT_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcflt_disable

#define ao_ir_adcflt_disable()      { IEC1CLR = _IEC1_ADCFLTIE_MASK; }

#endif

#ifndef ao_ir_adcflt_enable

#define ao_ir_adcflt_enable()       { IEC1SET = _IEC1_ADCFLTIE_MASK; }

#endif

#ifndef ao_ir_adcflt_is_enabled

#define ao_ir_adcflt_is_enabled()   ((IEC1 & _IEC1_ADCFLTIE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcflt_is_pending

#define ao_ir_adcflt_is_pending()   ((IFS1 & _IFS1_ADCFLTIF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcflt_reply

#define ao_ir_adcflt_reply()        { IFS1CLR = _IFS1_ADCFLTIF_MASK; }

#endif

#ifndef ao_ir_adcflt_request

#define ao_ir_adcflt_request()      { IFS1SET = _IFS1_ADCFLTIF_MASK; }

#endif

#ifndef AO_IR_ADCGRP_ATTRIBUTE

#define AO_IR_ADCGRP_ATTRIBUTE      __ISR(_ADC_EARLY_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCGRP_PRIO

#define AO_IR_ADCGRP_PRIO           (4)

#endif

#ifndef AO_IR_ADCGRP_SUBPRIO

#define AO_IR_ADCGRP_SUBPRIO        (0)

#endif

#ifndef ao_ir_adcgrp_disable

#define ao_ir_adcgrp_disable()      { IEC6CLR = _IEC6_ADCGRPIE_MASK; }

#endif

#ifndef ao_ir_adcgrp_enable

#define ao_ir_adcgrp_enable()       { IEC6SET = _IEC6_ADCGRPIE_MASK; }

#endif

#ifndef ao_ir_adcgrp_is_enabled

#define ao_ir_adcgrp_is_enabled()   ((IEC6 & _IEC6_ADCGRPIE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcgrp_is_pending

#define ao_ir_adcgrp_is_pending()   ((IFS6 & _IFS6_ADCGRPIF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcgrp_reply

#define ao_ir_adcgrp_reply()        { IFS6CLR = _IFS6_ADCGRPIF_MASK; }

#endif

#ifndef ao_ir_adcgrp_request

#define ao_ir_adcgrp_request()      { IFS6SET = _IFS6_ADCGRPIF_MASK; }

#endif

#ifndef AO_IR_ADCURDY_ATTRIBUTE

#define AO_IR_ADCURDY_ATTRIBUTE     __ISR(_ADC_URDY_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ADCURDY_PRIO

#define AO_IR_ADCURDY_PRIO          (4)

#endif

#ifndef AO_IR_ADCURDY_SUBPRIO

#define AO_IR_ADCURDY_SUBPRIO       (0)

#endif

#ifndef ao_ir_adcurdy_disable

#define ao_ir_adcurdy_disable()     { IEC6CLR = _IEC6_ADCURDYIE_MASK; }

#endif

#ifndef ao_ir_adcurdy_enable

#define ao_ir_adcurdy_enable()      { IEC6SET = _IEC6_ADCURDYIE_MASK; }

#endif

#ifndef ao_ir_adcurdy_is_enabled

#define ao_ir_adcurdy_is_enabled()  ((IEC6 & _IEC6_ADCURDYIE_MASK) ? true : false)

#endif

#ifndef ao_ir_adcurdy_is_pending

#define ao_ir_adcurdy_is_pending()  ((IFS6 & _IFS6_ADCURDYIF_MASK) ? true : false)

#endif

#ifndef ao_ir_adcurdy_reply

#define ao_ir_adcurdy_reply()       { IFS6CLR = _IFS6_ADCURDYIF_MASK; }

#endif

#ifndef ao_ir_adcurdy_request

#define ao_ir_adcurdy_request()     { IFS6SET = _IFS6_ADCURDYIF_MASK; }

#endif

```
