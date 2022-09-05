---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mk_gpk/ao_ir_adc.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gpk/ao_ir_adc.h/
subtitle: "ADC interrupts"
title: "ao_ir_adc.h"
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Constants

```c
#define AO_IR_AD1_ATTRIBUTE __ISR(_ADC_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1_PRIO (4)
```

```c
#define AO_IR_AD1_SUBPRIO (0)
```

```c
#define AO_IR_AD1AR_ATTRIBUTE __ISR(_ADC_ARDY_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1AR_PRIO (4)
```

```c
#define AO_IR_AD1AR_SUBPRIO (0)
```

```c
#define AO_IR_AD1D0_ATTRIBUTE __ISR(_ADC_DATA0_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D0_PRIO (4)
```

```c
#define AO_IR_AD1D0_SUBPRIO (0)
```

```c
#define AO_IR_AD1D1_ATTRIBUTE __ISR(_ADC_DATA1_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D1_PRIO (4)
```

```c
#define AO_IR_AD1D1_SUBPRIO (0)
```

```c
#define AO_IR_AD1D10_ATTRIBUTE __ISR(_ADC_DATA10_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D10_PRIO (4)
```

```c
#define AO_IR_AD1D10_SUBPRIO (0)
```

```c
#define AO_IR_AD1D11_ATTRIBUTE __ISR(_ADC_DATA11_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D11_PRIO (4)
```

```c
#define AO_IR_AD1D11_SUBPRIO (0)
```

```c
#define AO_IR_AD1D12_ATTRIBUTE __ISR(_ADC_DATA12_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D12_PRIO (4)
```

```c
#define AO_IR_AD1D12_SUBPRIO (0)
```

```c
#define AO_IR_AD1D13_ATTRIBUTE __ISR(_ADC_DATA13_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D13_PRIO (4)
```

```c
#define AO_IR_AD1D13_SUBPRIO (0)
```

```c
#define AO_IR_AD1D14_ATTRIBUTE __ISR(_ADC_DATA14_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D14_PRIO (4)
```

```c
#define AO_IR_AD1D14_SUBPRIO (0)
```

```c
#define AO_IR_AD1D15_ATTRIBUTE __ISR(_ADC_DATA15_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D15_PRIO (4)
```

```c
#define AO_IR_AD1D15_SUBPRIO (0)
```

```c
#define AO_IR_AD1D16_ATTRIBUTE __ISR(_ADC_DATA16_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D16_PRIO (4)
```

```c
#define AO_IR_AD1D16_SUBPRIO (0)
```

```c
#define AO_IR_AD1D17_ATTRIBUTE __ISR(_ADC_DATA17_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D17_PRIO (4)
```

```c
#define AO_IR_AD1D17_SUBPRIO (0)
```

```c
#define AO_IR_AD1D18_ATTRIBUTE __ISR(_ADC_DATA18_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D18_PRIO (4)
```

```c
#define AO_IR_AD1D18_SUBPRIO (0)
```

```c
#define AO_IR_AD1D19_ATTRIBUTE __ISR(_ADC_DATA19_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D19_PRIO (4)
```

```c
#define AO_IR_AD1D19_SUBPRIO (0)
```

```c
#define AO_IR_AD1D2_ATTRIBUTE __ISR(_ADC_DATA2_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D2_PRIO (4)
```

```c
#define AO_IR_AD1D2_SUBPRIO (0)
```

```c
#define AO_IR_AD1D20_ATTRIBUTE __ISR(_ADC_DATA20_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D20_PRIO (4)
```

```c
#define AO_IR_AD1D20_SUBPRIO (0)
```

```c
#define AO_IR_AD1D21_ATTRIBUTE __ISR(_ADC_DATA21_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D21_PRIO (4)
```

```c
#define AO_IR_AD1D21_SUBPRIO (0)
```

```c
#define AO_IR_AD1D22_ATTRIBUTE __ISR(_ADC_DATA22_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D22_PRIO (4)
```

```c
#define AO_IR_AD1D22_SUBPRIO (0)
```

```c
#define AO_IR_AD1D23_ATTRIBUTE __ISR(_ADC_DATA23_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D23_PRIO (4)
```

```c
#define AO_IR_AD1D23_SUBPRIO (0)
```

```c
#define AO_IR_AD1D24_ATTRIBUTE __ISR(_ADC_DATA24_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D24_PRIO (4)
```

```c
#define AO_IR_AD1D24_SUBPRIO (0)
```

```c
#define AO_IR_AD1D25_ATTRIBUTE __ISR(_ADC_DATA25_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D25_PRIO (4)
```

```c
#define AO_IR_AD1D25_SUBPRIO (0)
```

```c
#define AO_IR_AD1D26_ATTRIBUTE __ISR(_ADC_DATA26_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D26_PRIO (4)
```

```c
#define AO_IR_AD1D26_SUBPRIO (0)
```

```c
#define AO_IR_AD1D27_ATTRIBUTE __ISR(_ADC_DATA27_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D27_PRIO (4)
```

```c
#define AO_IR_AD1D27_SUBPRIO (0)
```

```c
#define AO_IR_AD1D3_ATTRIBUTE __ISR(_ADC_DATA3_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D3_PRIO (4)
```

```c
#define AO_IR_AD1D3_SUBPRIO (0)
```

```c
#define AO_IR_AD1D33_ATTRIBUTE __ISR(_ADC_DATA33_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D33_PRIO (4)
```

```c
#define AO_IR_AD1D33_SUBPRIO (0)
```

```c
#define AO_IR_AD1D34_ATTRIBUTE __ISR(_ADC_DATA34_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D34_PRIO (4)
```

```c
#define AO_IR_AD1D34_SUBPRIO (0)
```

```c
#define AO_IR_AD1D35_ATTRIBUTE __ISR(_ADC_DATA35_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D35_PRIO (4)
```

```c
#define AO_IR_AD1D35_SUBPRIO (0)
```

```c
#define AO_IR_AD1D36_ATTRIBUTE __ISR(_ADC_DATA36_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D36_PRIO (4)
```

```c
#define AO_IR_AD1D36_SUBPRIO (0)
```

```c
#define AO_IR_AD1D37_ATTRIBUTE __ISR(_ADC_DATA37_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D37_PRIO (4)
```

```c
#define AO_IR_AD1D37_SUBPRIO (0)
```

```c
#define AO_IR_AD1D38_ATTRIBUTE __ISR(_ADC_DATA38_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D38_PRIO (4)
```

```c
#define AO_IR_AD1D38_SUBPRIO (0)
```

```c
#define AO_IR_AD1D39_ATTRIBUTE __ISR(_ADC_DATA39_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D39_PRIO (4)
```

```c
#define AO_IR_AD1D39_SUBPRIO (0)
```

```c
#define AO_IR_AD1D4_ATTRIBUTE __ISR(_ADC_DATA4_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D4_PRIO (4)
```

```c
#define AO_IR_AD1D4_SUBPRIO (0)
```

```c
#define AO_IR_AD1D40_ATTRIBUTE __ISR(_ADC_DATA40_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D40_PRIO (4)
```

```c
#define AO_IR_AD1D40_SUBPRIO (0)
```

```c
#define AO_IR_AD1D41_ATTRIBUTE __ISR(_ADC_DATA41_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D41_PRIO (4)
```

```c
#define AO_IR_AD1D41_SUBPRIO (0)
```

```c
#define AO_IR_AD1D45_ATTRIBUTE __ISR(_ADC_DATA45_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D45_PRIO (4)
```

```c
#define AO_IR_AD1D45_SUBPRIO (0)
```

```c
#define AO_IR_AD1D46_ATTRIBUTE __ISR(_ADC_DATA46_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D46_PRIO (4)
```

```c
#define AO_IR_AD1D46_SUBPRIO (0)
```

```c
#define AO_IR_AD1D47_ATTRIBUTE __ISR(_ADC_DATA47_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D47_PRIO (4)
```

```c
#define AO_IR_AD1D47_SUBPRIO (0)
```

```c
#define AO_IR_AD1D48_ATTRIBUTE __ISR(_ADC_DATA48_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D48_PRIO (4)
```

```c
#define AO_IR_AD1D48_SUBPRIO (0)
```

```c
#define AO_IR_AD1D49_ATTRIBUTE __ISR(_ADC_DATA49_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D49_PRIO (4)
```

```c
#define AO_IR_AD1D49_SUBPRIO (0)
```

```c
#define AO_IR_AD1D5_ATTRIBUTE __ISR(_ADC_DATA5_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D5_PRIO (4)
```

```c
#define AO_IR_AD1D5_SUBPRIO (0)
```

```c
#define AO_IR_AD1D50_ATTRIBUTE __ISR(_ADC_DATA50_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D50_PRIO (4)
```

```c
#define AO_IR_AD1D50_SUBPRIO (0)
```

```c
#define AO_IR_AD1D53_ATTRIBUTE __ISR(_ADC_DATA53_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D53_PRIO (4)
```

```c
#define AO_IR_AD1D53_SUBPRIO (0)
```

```c
#define AO_IR_AD1D6_ATTRIBUTE __ISR(_ADC_DATA6_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D6_PRIO (4)
```

```c
#define AO_IR_AD1D6_SUBPRIO (0)
```

```c
#define AO_IR_AD1D7_ATTRIBUTE __ISR(_ADC_DATA7_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D7_PRIO (4)
```

```c
#define AO_IR_AD1D7_SUBPRIO (0)
```

```c
#define AO_IR_AD1D8_ATTRIBUTE __ISR(_ADC_DATA8_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D8_PRIO (4)
```

```c
#define AO_IR_AD1D8_SUBPRIO (0)
```

```c
#define AO_IR_AD1D9_ATTRIBUTE __ISR(_ADC_DATA9_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1D9_PRIO (4)
```

```c
#define AO_IR_AD1D9_SUBPRIO (0)
```

```c
#define AO_IR_AD1DC1_ATTRIBUTE __ISR(_ADC_DC1_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1DC1_PRIO (4)
```

```c
#define AO_IR_AD1DC1_SUBPRIO (0)
```

```c
#define AO_IR_AD1DC2_ATTRIBUTE __ISR(_ADC_DC2_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1DC2_PRIO (4)
```

```c
#define AO_IR_AD1DC2_SUBPRIO (0)
```

```c
#define AO_IR_AD1DC3_ATTRIBUTE __ISR(_ADC_DC3_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1DC3_PRIO (4)
```

```c
#define AO_IR_AD1DC3_SUBPRIO (0)
```

```c
#define AO_IR_AD1DC4_ATTRIBUTE __ISR(_ADC_DC4_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1DC4_PRIO (4)
```

```c
#define AO_IR_AD1DC4_SUBPRIO (0)
```

```c
#define AO_IR_AD1DF1_ATTRIBUTE __ISR(_ADC_DF1_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1DF1_PRIO (4)
```

```c
#define AO_IR_AD1DF1_SUBPRIO (0)
```

```c
#define AO_IR_AD1DF2_ATTRIBUTE __ISR(_ADC_DF2_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1DF2_PRIO (4)
```

```c
#define AO_IR_AD1DF2_SUBPRIO (0)
```

```c
#define AO_IR_AD1DF3_ATTRIBUTE __ISR(_ADC_DF3_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1DF3_PRIO (4)
```

```c
#define AO_IR_AD1DF3_SUBPRIO (0)
```

```c
#define AO_IR_AD1DF4_ATTRIBUTE __ISR(_ADC_DF4_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1DF4_PRIO (4)
```

```c
#define AO_IR_AD1DF4_SUBPRIO (0)
```

```c
#define AO_IR_AD1EOS_ATTRIBUTE __ISR(_ADC_EOS_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1EOS_PRIO (4)
```

```c
#define AO_IR_AD1EOS_SUBPRIO (0)
```

```c
#define AO_IR_AD1FCBT_ATTRIBUTE __ISR(_ADC_DMA_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1FCBT_PRIO (4)
```

```c
#define AO_IR_AD1FCBT_SUBPRIO (0)
```

```c
#define AO_IR_AD1FI_ATTRIBUTE __ISR(_ADC_FAULT_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1FI_PRIO (4)
```

```c
#define AO_IR_AD1FI_SUBPRIO (0)
```

```c
#define AO_IR_AD1G_ATTRIBUTE __ISR(_ADC_EARLY_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1G_PRIO (4)
```

```c
#define AO_IR_AD1G_SUBPRIO (0)
```

```c
#define AO_IR_AD1RS_ATTRIBUTE __ISR(_ADC_URDY_VECTOR, IPL4SRS)
```

```c
#define AO_IR_AD1RS_PRIO (4)
```

```c
#define AO_IR_AD1RS_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_ad1_disable()
```

```c
#define ao_ir_ad1_enable()
```

```c
#define ao_ir_ad1_is_enabled()
```

```c
#define ao_ir_ad1_is_pending()
```

```c
#define ao_ir_ad1_reply()
```

```c
#define ao_ir_ad1_request()
```

```c
#define ao_ir_ad1ar_disable()
```

```c
#define ao_ir_ad1ar_enable()
```

```c
#define ao_ir_ad1ar_is_enabled()
```

```c
#define ao_ir_ad1ar_is_pending()
```

```c
#define ao_ir_ad1ar_reply()
```

```c
#define ao_ir_ad1ar_request()
```

```c
#define ao_ir_ad1d0_disable()
```

```c
#define ao_ir_ad1d0_enable()
```

```c
#define ao_ir_ad1d0_is_enabled()
```

```c
#define ao_ir_ad1d0_is_pending()
```

```c
#define ao_ir_ad1d0_reply()
```

```c
#define ao_ir_ad1d0_request()
```

```c
#define ao_ir_ad1d1_disable()
```

```c
#define ao_ir_ad1d1_enable()
```

```c
#define ao_ir_ad1d1_is_enabled()
```

```c
#define ao_ir_ad1d1_is_pending()
```

```c
#define ao_ir_ad1d1_reply()
```

```c
#define ao_ir_ad1d1_request()
```

```c
#define ao_ir_ad1d2_disable()
```

```c
#define ao_ir_ad1d2_enable()
```

```c
#define ao_ir_ad1d2_is_enabled()
```

```c
#define ao_ir_ad1d2_is_pending()
```

```c
#define ao_ir_ad1d2_reply()
```

```c
#define ao_ir_ad1d2_request()
```

```c
#define ao_ir_ad1d3_disable()
```

```c
#define ao_ir_ad1d3_enable()
```

```c
#define ao_ir_ad1d3_is_enabled()
```

```c
#define ao_ir_ad1d3_is_pending()
```

```c
#define ao_ir_ad1d3_reply()
```

```c
#define ao_ir_ad1d3_request()
```

```c
#define ao_ir_ad1d4_disable()
```

```c
#define ao_ir_ad1d4_enable()
```

```c
#define ao_ir_ad1d4_is_enabled()
```

```c
#define ao_ir_ad1d4_is_pending()
```

```c
#define ao_ir_ad1d4_reply()
```

```c
#define ao_ir_ad1d4_request()
```

```c
#define ao_ir_ad1d5_disable()
```

```c
#define ao_ir_ad1d5_enable()
```

```c
#define ao_ir_ad1d5_is_enabled()
```

```c
#define ao_ir_ad1d5_is_pending()
```

```c
#define ao_ir_ad1d5_reply()
```

```c
#define ao_ir_ad1d5_request()
```

```c
#define ao_ir_ad1d6_disable()
```

```c
#define ao_ir_ad1d6_enable()
```

```c
#define ao_ir_ad1d6_is_enabled()
```

```c
#define ao_ir_ad1d6_is_pending()
```

```c
#define ao_ir_ad1d6_reply()
```

```c
#define ao_ir_ad1d6_request()
```

```c
#define ao_ir_ad1d7_disable()
```

```c
#define ao_ir_ad1d7_enable()
```

```c
#define ao_ir_ad1d7_is_enabled()
```

```c
#define ao_ir_ad1d7_is_pending()
```

```c
#define ao_ir_ad1d7_reply()
```

```c
#define ao_ir_ad1d7_request()
```

```c
#define ao_ir_ad1d8_disable()
```

```c
#define ao_ir_ad1d8_enable()
```

```c
#define ao_ir_ad1d8_is_enabled()
```

```c
#define ao_ir_ad1d8_is_pending()
```

```c
#define ao_ir_ad1d8_reply()
```

```c
#define ao_ir_ad1d8_request()
```

```c
#define ao_ir_ad1d9_disable()
```

```c
#define ao_ir_ad1d9_enable()
```

```c
#define ao_ir_ad1d9_is_enabled()
```

```c
#define ao_ir_ad1d9_is_pending()
```

```c
#define ao_ir_ad1d9_reply()
```

```c
#define ao_ir_ad1d9_request()
```

```c
#define ao_ir_ad1d10_disable()
```

```c
#define ao_ir_ad1d10_enable()
```

```c
#define ao_ir_ad1d10_is_enabled()
```

```c
#define ao_ir_ad1d10_is_pending()
```

```c
#define ao_ir_ad1d10_reply()
```

```c
#define ao_ir_ad1d10_request()
```

```c
#define ao_ir_ad1d11_disable()
```

```c
#define ao_ir_ad1d11_enable()
```

```c
#define ao_ir_ad1d11_is_enabled()
```

```c
#define ao_ir_ad1d11_is_pending()
```

```c
#define ao_ir_ad1d11_reply()
```

```c
#define ao_ir_ad1d11_request()
```

```c
#define ao_ir_ad1d12_disable()
```

```c
#define ao_ir_ad1d12_enable()
```

```c
#define ao_ir_ad1d12_is_enabled()
```

```c
#define ao_ir_ad1d12_is_pending()
```

```c
#define ao_ir_ad1d12_reply()
```

```c
#define ao_ir_ad1d12_request()
```

```c
#define ao_ir_ad1d13_disable()
```

```c
#define ao_ir_ad1d13_enable()
```

```c
#define ao_ir_ad1d13_is_enabled()
```

```c
#define ao_ir_ad1d13_is_pending()
```

```c
#define ao_ir_ad1d13_reply()
```

```c
#define ao_ir_ad1d13_request()
```

```c
#define ao_ir_ad1d14_disable()
```

```c
#define ao_ir_ad1d14_enable()
```

```c
#define ao_ir_ad1d14_is_enabled()
```

```c
#define ao_ir_ad1d14_is_pending()
```

```c
#define ao_ir_ad1d14_reply()
```

```c
#define ao_ir_ad1d14_request()
```

```c
#define ao_ir_ad1d15_disable()
```

```c
#define ao_ir_ad1d15_enable()
```

```c
#define ao_ir_ad1d15_is_enabled()
```

```c
#define ao_ir_ad1d15_is_pending()
```

```c
#define ao_ir_ad1d15_reply()
```

```c
#define ao_ir_ad1d15_request()
```

```c
#define ao_ir_ad1d16_disable()
```

```c
#define ao_ir_ad1d16_enable()
```

```c
#define ao_ir_ad1d16_is_enabled()
```

```c
#define ao_ir_ad1d16_is_pending()
```

```c
#define ao_ir_ad1d16_reply()
```

```c
#define ao_ir_ad1d16_request()
```

```c
#define ao_ir_ad1d17_disable()
```

```c
#define ao_ir_ad1d17_enable()
```

```c
#define ao_ir_ad1d17_is_enabled()
```

```c
#define ao_ir_ad1d17_is_pending()
```

```c
#define ao_ir_ad1d17_reply()
```

```c
#define ao_ir_ad1d17_request()
```

```c
#define ao_ir_ad1d18_disable()
```

```c
#define ao_ir_ad1d18_enable()
```

```c
#define ao_ir_ad1d18_is_enabled()
```

```c
#define ao_ir_ad1d18_is_pending()
```

```c
#define ao_ir_ad1d18_reply()
```

```c
#define ao_ir_ad1d18_request()
```

```c
#define ao_ir_ad1d19_disable()
```

```c
#define ao_ir_ad1d19_enable()
```

```c
#define ao_ir_ad1d19_is_enabled()
```

```c
#define ao_ir_ad1d19_is_pending()
```

```c
#define ao_ir_ad1d19_reply()
```

```c
#define ao_ir_ad1d19_request()
```

```c
#define ao_ir_ad1d20_disable()
```

```c
#define ao_ir_ad1d20_enable()
```

```c
#define ao_ir_ad1d20_is_enabled()
```

```c
#define ao_ir_ad1d20_is_pending()
```

```c
#define ao_ir_ad1d20_reply()
```

```c
#define ao_ir_ad1d20_request()
```

```c
#define ao_ir_ad1d21_disable()
```

```c
#define ao_ir_ad1d21_enable()
```

```c
#define ao_ir_ad1d21_is_enabled()
```

```c
#define ao_ir_ad1d21_is_pending()
```

```c
#define ao_ir_ad1d21_reply()
```

```c
#define ao_ir_ad1d21_request()
```

```c
#define ao_ir_ad1d22_disable()
```

```c
#define ao_ir_ad1d22_enable()
```

```c
#define ao_ir_ad1d22_is_enabled()
```

```c
#define ao_ir_ad1d22_is_pending()
```

```c
#define ao_ir_ad1d22_reply()
```

```c
#define ao_ir_ad1d22_request()
```

```c
#define ao_ir_ad1d23_disable()
```

```c
#define ao_ir_ad1d23_enable()
```

```c
#define ao_ir_ad1d23_is_enabled()
```

```c
#define ao_ir_ad1d23_is_pending()
```

```c
#define ao_ir_ad1d23_reply()
```

```c
#define ao_ir_ad1d23_request()
```

```c
#define ao_ir_ad1d24_disable()
```

```c
#define ao_ir_ad1d24_enable()
```

```c
#define ao_ir_ad1d24_is_enabled()
```

```c
#define ao_ir_ad1d24_is_pending()
```

```c
#define ao_ir_ad1d24_reply()
```

```c
#define ao_ir_ad1d24_request()
```

```c
#define ao_ir_ad1d25_disable()
```

```c
#define ao_ir_ad1d25_enable()
```

```c
#define ao_ir_ad1d25_is_enabled()
```

```c
#define ao_ir_ad1d25_is_pending()
```

```c
#define ao_ir_ad1d25_reply()
```

```c
#define ao_ir_ad1d25_request()
```

```c
#define ao_ir_ad1d26_disable()
```

```c
#define ao_ir_ad1d26_enable()
```

```c
#define ao_ir_ad1d26_is_enabled()
```

```c
#define ao_ir_ad1d26_is_pending()
```

```c
#define ao_ir_ad1d26_reply()
```

```c
#define ao_ir_ad1d26_request()
```

```c
#define ao_ir_ad1d27_disable()
```

```c
#define ao_ir_ad1d27_enable()
```

```c
#define ao_ir_ad1d27_is_enabled()
```

```c
#define ao_ir_ad1d27_is_pending()
```

```c
#define ao_ir_ad1d27_reply()
```

```c
#define ao_ir_ad1d27_request()
```

```c
#define ao_ir_ad1d33_disable()
```

```c
#define ao_ir_ad1d33_enable()
```

```c
#define ao_ir_ad1d33_is_enabled()
```

```c
#define ao_ir_ad1d33_is_pending()
```

```c
#define ao_ir_ad1d33_reply()
```

```c
#define ao_ir_ad1d33_request()
```

```c
#define ao_ir_ad1d34_disable()
```

```c
#define ao_ir_ad1d34_enable()
```

```c
#define ao_ir_ad1d34_is_enabled()
```

```c
#define ao_ir_ad1d34_is_pending()
```

```c
#define ao_ir_ad1d34_reply()
```

```c
#define ao_ir_ad1d34_request()
```

```c
#define ao_ir_ad1d35_disable()
```

```c
#define ao_ir_ad1d35_enable()
```

```c
#define ao_ir_ad1d35_is_enabled()
```

```c
#define ao_ir_ad1d35_is_pending()
```

```c
#define ao_ir_ad1d35_reply()
```

```c
#define ao_ir_ad1d35_request()
```

```c
#define ao_ir_ad1d36_disable()
```

```c
#define ao_ir_ad1d36_enable()
```

```c
#define ao_ir_ad1d36_is_enabled()
```

```c
#define ao_ir_ad1d36_is_pending()
```

```c
#define ao_ir_ad1d36_reply()
```

```c
#define ao_ir_ad1d36_request()
```

```c
#define ao_ir_ad1d37_disable()
```

```c
#define ao_ir_ad1d37_enable()
```

```c
#define ao_ir_ad1d37_is_enabled()
```

```c
#define ao_ir_ad1d37_is_pending()
```

```c
#define ao_ir_ad1d37_reply()
```

```c
#define ao_ir_ad1d37_request()
```

```c
#define ao_ir_ad1d38_disable()
```

```c
#define ao_ir_ad1d38_enable()
```

```c
#define ao_ir_ad1d38_is_enabled()
```

```c
#define ao_ir_ad1d38_is_pending()
```

```c
#define ao_ir_ad1d38_reply()
```

```c
#define ao_ir_ad1d38_request()
```

```c
#define ao_ir_ad1d39_disable()
```

```c
#define ao_ir_ad1d39_enable()
```

```c
#define ao_ir_ad1d39_is_enabled()
```

```c
#define ao_ir_ad1d39_is_pending()
```

```c
#define ao_ir_ad1d39_reply()
```

```c
#define ao_ir_ad1d39_request()
```

```c
#define ao_ir_ad1d40_disable()
```

```c
#define ao_ir_ad1d40_enable()
```

```c
#define ao_ir_ad1d40_is_enabled()
```

```c
#define ao_ir_ad1d40_is_pending()
```

```c
#define ao_ir_ad1d40_reply()
```

```c
#define ao_ir_ad1d40_request()
```

```c
#define ao_ir_ad1d41_disable()
```

```c
#define ao_ir_ad1d41_enable()
```

```c
#define ao_ir_ad1d41_is_enabled()
```

```c
#define ao_ir_ad1d41_is_pending()
```

```c
#define ao_ir_ad1d41_reply()
```

```c
#define ao_ir_ad1d41_request()
```

```c
#define ao_ir_ad1d45_disable()
```

```c
#define ao_ir_ad1d45_enable()
```

```c
#define ao_ir_ad1d45_is_enabled()
```

```c
#define ao_ir_ad1d45_is_pending()
```

```c
#define ao_ir_ad1d45_reply()
```

```c
#define ao_ir_ad1d45_request()
```

```c
#define ao_ir_ad1d46_disable()
```

```c
#define ao_ir_ad1d46_enable()
```

```c
#define ao_ir_ad1d46_is_enabled()
```

```c
#define ao_ir_ad1d46_is_pending()
```

```c
#define ao_ir_ad1d46_reply()
```

```c
#define ao_ir_ad1d46_request()
```

```c
#define ao_ir_ad1d47_disable()
```

```c
#define ao_ir_ad1d47_enable()
```

```c
#define ao_ir_ad1d47_is_enabled()
```

```c
#define ao_ir_ad1d47_is_pending()
```

```c
#define ao_ir_ad1d47_reply()
```

```c
#define ao_ir_ad1d47_request()
```

```c
#define ao_ir_ad1d48_disable()
```

```c
#define ao_ir_ad1d48_enable()
```

```c
#define ao_ir_ad1d48_is_enabled()
```

```c
#define ao_ir_ad1d48_is_pending()
```

```c
#define ao_ir_ad1d48_reply()
```

```c
#define ao_ir_ad1d48_request()
```

```c
#define ao_ir_ad1d49_disable()
```

```c
#define ao_ir_ad1d49_enable()
```

```c
#define ao_ir_ad1d49_is_enabled()
```

```c
#define ao_ir_ad1d49_is_pending()
```

```c
#define ao_ir_ad1d49_reply()
```

```c
#define ao_ir_ad1d49_request()
```

```c
#define ao_ir_ad1d50_disable()
```

```c
#define ao_ir_ad1d50_enable()
```

```c
#define ao_ir_ad1d50_is_enabled()
```

```c
#define ao_ir_ad1d50_is_pending()
```

```c
#define ao_ir_ad1d50_reply()
```

```c
#define ao_ir_ad1d50_request()
```

```c
#define ao_ir_ad1d53_disable()
```

```c
#define ao_ir_ad1d53_enable()
```

```c
#define ao_ir_ad1d53_is_enabled()
```

```c
#define ao_ir_ad1d53_is_pending()
```

```c
#define ao_ir_ad1d53_reply()
```

```c
#define ao_ir_ad1d53_request()
```

```c
#define ao_ir_ad1dc1_disable()
```

```c
#define ao_ir_ad1dc1_enable()
```

```c
#define ao_ir_ad1dc1_is_enabled()
```

```c
#define ao_ir_ad1dc1_is_pending()
```

```c
#define ao_ir_ad1dc1_reply()
```

```c
#define ao_ir_ad1dc1_request()
```

```c
#define ao_ir_ad1dc2_disable()
```

```c
#define ao_ir_ad1dc2_enable()
```

```c
#define ao_ir_ad1dc2_is_enabled()
```

```c
#define ao_ir_ad1dc2_is_pending()
```

```c
#define ao_ir_ad1dc2_reply()
```

```c
#define ao_ir_ad1dc2_request()
```

```c
#define ao_ir_ad1dc3_disable()
```

```c
#define ao_ir_ad1dc3_enable()
```

```c
#define ao_ir_ad1dc3_is_enabled()
```

```c
#define ao_ir_ad1dc3_is_pending()
```

```c
#define ao_ir_ad1dc3_reply()
```

```c
#define ao_ir_ad1dc3_request()
```

```c
#define ao_ir_ad1dc4_disable()
```

```c
#define ao_ir_ad1dc4_enable()
```

```c
#define ao_ir_ad1dc4_is_enabled()
```

```c
#define ao_ir_ad1dc4_is_pending()
```

```c
#define ao_ir_ad1dc4_reply()
```

```c
#define ao_ir_ad1dc4_request()
```

```c
#define ao_ir_ad1df1_disable()
```

```c
#define ao_ir_ad1df1_enable()
```

```c
#define ao_ir_ad1df1_is_enabled()
```

```c
#define ao_ir_ad1df1_is_pending()
```

```c
#define ao_ir_ad1df1_reply()
```

```c
#define ao_ir_ad1df1_request()
```

```c
#define ao_ir_ad1df2_disable()
```

```c
#define ao_ir_ad1df2_enable()
```

```c
#define ao_ir_ad1df2_is_enabled()
```

```c
#define ao_ir_ad1df2_is_pending()
```

```c
#define ao_ir_ad1df2_reply()
```

```c
#define ao_ir_ad1df2_request()
```

```c
#define ao_ir_ad1df3_disable()
```

```c
#define ao_ir_ad1df3_enable()
```

```c
#define ao_ir_ad1df3_is_enabled()
```

```c
#define ao_ir_ad1df3_is_pending()
```

```c
#define ao_ir_ad1df3_reply()
```

```c
#define ao_ir_ad1df3_request()
```

```c
#define ao_ir_ad1df4_disable()
```

```c
#define ao_ir_ad1df4_enable()
```

```c
#define ao_ir_ad1df4_is_enabled()
```

```c
#define ao_ir_ad1df4_is_pending()
```

```c
#define ao_ir_ad1df4_reply()
```

```c
#define ao_ir_ad1df4_request()
```

```c
#define ao_ir_ad1eos_disable()
```

```c
#define ao_ir_ad1eos_enable()
```

```c
#define ao_ir_ad1eos_is_enabled()
```

```c
#define ao_ir_ad1eos_is_pending()
```

```c
#define ao_ir_ad1eos_reply()
```

```c
#define ao_ir_ad1eos_request()
```

```c
#define ao_ir_ad1fcbt_disable()
```

```c
#define ao_ir_ad1fcbt_enable()
```

```c
#define ao_ir_ad1fcbt_is_enabled()
```

```c
#define ao_ir_ad1fcbt_is_pending()
```

```c
#define ao_ir_ad1fcbt_reply()
```

```c
#define ao_ir_ad1fcbt_request()
```

```c
#define ao_ir_ad1fi_disable()
```

```c
#define ao_ir_ad1fi_enable()
```

```c
#define ao_ir_ad1fi_is_enabled()
```

```c
#define ao_ir_ad1fi_is_pending()
```

```c
#define ao_ir_ad1fi_reply()
```

```c
#define ao_ir_ad1fi_request()
```

```c
#define ao_ir_ad1g_disable()
```

```c
#define ao_ir_ad1g_enable()
```

```c
#define ao_ir_ad1g_is_enabled()
```

```c
#define ao_ir_ad1g_is_pending()
```

```c
#define ao_ir_ad1g_reply()
```

```c
#define ao_ir_ad1g_request()
```

```c
#define ao_ir_ad1rs_disable()
```

```c
#define ao_ir_ad1rs_enable()
```

```c
#define ao_ir_ad1rs_is_enabled()
```

```c
#define ao_ir_ad1rs_is_pending()
```

```c
#define ao_ir_ad1rs_reply()
```

```c
#define ao_ir_ad1rs_request()
```
