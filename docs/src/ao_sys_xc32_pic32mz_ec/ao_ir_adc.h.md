---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mz_ec/ao_ir_adc.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32_pic32mz_ec/ao_ir_adc.h/
subtitle: ""
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
#define AO_IR_ADC_ATTRIBUTE __ISR(_ADC1_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADC_PRIO (4)
```

```c
#define AO_IR_ADC_SUBPRIO (0)
```

```c
#define AO_IR_ADCD0_ATTRIBUTE __ISR(_ADC1_DATA0_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD0_PRIO (4)
```

```c
#define AO_IR_ADCD0_SUBPRIO (0)
```

```c
#define AO_IR_ADCD1_ATTRIBUTE __ISR(_ADC1_DATA1_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD1_PRIO (4)
```

```c
#define AO_IR_ADCD1_SUBPRIO (0)
```

```c
#define AO_IR_ADCD10_ATTRIBUTE __ISR(_ADC1_DATA10_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD10_PRIO (4)
```

```c
#define AO_IR_ADCD10_SUBPRIO (0)
```

```c
#define AO_IR_ADCD11_ATTRIBUTE __ISR(_ADC1_DATA11_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD11_PRIO (4)
```

```c
#define AO_IR_ADCD11_SUBPRIO (0)
```

```c
#define AO_IR_ADCD12_ATTRIBUTE __ISR(_ADC1_DATA12_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD12_PRIO (4)
```

```c
#define AO_IR_ADCD12_SUBPRIO (0)
```

```c
#define AO_IR_ADCD13_ATTRIBUTE __ISR(_ADC1_DATA13_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD13_PRIO (4)
```

```c
#define AO_IR_ADCD13_SUBPRIO (0)
```

```c
#define AO_IR_ADCD14_ATTRIBUTE __ISR(_ADC1_DATA14_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD14_PRIO (4)
```

```c
#define AO_IR_ADCD14_SUBPRIO (0)
```

```c
#define AO_IR_ADCD15_ATTRIBUTE __ISR(_ADC1_DATA15_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD15_PRIO (4)
```

```c
#define AO_IR_ADCD15_SUBPRIO (0)
```

```c
#define AO_IR_ADCD16_ATTRIBUTE __ISR(_ADC1_DATA16_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD16_PRIO (4)
```

```c
#define AO_IR_ADCD16_SUBPRIO (0)
```

```c
#define AO_IR_ADCD17_ATTRIBUTE __ISR(_ADC1_DATA17_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD17_PRIO (4)
```

```c
#define AO_IR_ADCD17_SUBPRIO (0)
```

```c
#define AO_IR_ADCD18_ATTRIBUTE __ISR(_ADC1_DATA18_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD18_PRIO (4)
```

```c
#define AO_IR_ADCD18_SUBPRIO (0)
```

```c
#define AO_IR_ADCD19_ATTRIBUTE __ISR(_ADC1_DATA19_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD19_PRIO (4)
```

```c
#define AO_IR_ADCD19_SUBPRIO (0)
```

```c
#define AO_IR_ADCD2_ATTRIBUTE __ISR(_ADC1_DATA2_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD2_PRIO (4)
```

```c
#define AO_IR_ADCD2_SUBPRIO (0)
```

```c
#define AO_IR_ADCD20_ATTRIBUTE __ISR(_ADC1_DATA20_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD20_PRIO (4)
```

```c
#define AO_IR_ADCD20_SUBPRIO (0)
```

```c
#define AO_IR_ADCD21_ATTRIBUTE __ISR(_ADC1_DATA21_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD21_PRIO (4)
```

```c
#define AO_IR_ADCD21_SUBPRIO (0)
```

```c
#define AO_IR_ADCD22_ATTRIBUTE __ISR(_ADC1_DATA22_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD22_PRIO (4)
```

```c
#define AO_IR_ADCD22_SUBPRIO (0)
```

```c
#define AO_IR_ADCD23_ATTRIBUTE __ISR(_ADC1_DATA23_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD23_PRIO (4)
```

```c
#define AO_IR_ADCD23_SUBPRIO (0)
```

```c
#define AO_IR_ADCD24_ATTRIBUTE __ISR(_ADC1_DATA24_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD24_PRIO (4)
```

```c
#define AO_IR_ADCD24_SUBPRIO (0)
```

```c
#define AO_IR_ADCD25_ATTRIBUTE __ISR(_ADC1_DATA25_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD25_PRIO (4)
```

```c
#define AO_IR_ADCD25_SUBPRIO (0)
```

```c
#define AO_IR_ADCD26_ATTRIBUTE __ISR(_ADC1_DATA26_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD26_PRIO (4)
```

```c
#define AO_IR_ADCD26_SUBPRIO (0)
```

```c
#define AO_IR_ADCD27_ATTRIBUTE __ISR(_ADC1_DATA27_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD27_PRIO (4)
```

```c
#define AO_IR_ADCD27_SUBPRIO (0)
```

```c
#define AO_IR_ADCD28_ATTRIBUTE __ISR(_ADC1_DATA28_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD28_PRIO (4)
```

```c
#define AO_IR_ADCD28_SUBPRIO (0)
```

```c
#define AO_IR_ADCD29_ATTRIBUTE __ISR(_ADC1_DATA29_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD29_PRIO (4)
```

```c
#define AO_IR_ADCD29_SUBPRIO (0)
```

```c
#define AO_IR_ADCD3_ATTRIBUTE __ISR(_ADC1_DATA3_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD3_PRIO (4)
```

```c
#define AO_IR_ADCD3_SUBPRIO (0)
```

```c
#define AO_IR_ADCD30_ATTRIBUTE __ISR(_ADC1_DATA30_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD30_PRIO (4)
```

```c
#define AO_IR_ADCD30_SUBPRIO (0)
```

```c
#define AO_IR_ADCD31_ATTRIBUTE __ISR(_ADC1_DATA31_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD31_PRIO (4)
```

```c
#define AO_IR_ADCD31_SUBPRIO (0)
```

```c
#define AO_IR_ADCD32_ATTRIBUTE __ISR(_ADC1_DATA32_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD32_PRIO (4)
```

```c
#define AO_IR_ADCD32_SUBPRIO (0)
```

```c
#define AO_IR_ADCD33_ATTRIBUTE __ISR(_ADC1_DATA33_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD33_PRIO (4)
```

```c
#define AO_IR_ADCD33_SUBPRIO (0)
```

```c
#define AO_IR_ADCD34_ATTRIBUTE __ISR(_ADC1_DATA34_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD34_PRIO (4)
```

```c
#define AO_IR_ADCD34_SUBPRIO (0)
```

```c
#define AO_IR_ADCD35_ATTRIBUTE __ISR(_ADC1_DATA35_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD35_PRIO (4)
```

```c
#define AO_IR_ADCD35_SUBPRIO (0)
```

```c
#define AO_IR_ADCD36_ATTRIBUTE __ISR(_ADC1_DATA36_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD36_PRIO (4)
```

```c
#define AO_IR_ADCD36_SUBPRIO (0)
```

```c
#define AO_IR_ADCD37_ATTRIBUTE __ISR(_ADC1_DATA37_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD37_PRIO (4)
```

```c
#define AO_IR_ADCD37_SUBPRIO (0)
```

```c
#define AO_IR_ADCD38_ATTRIBUTE __ISR(_ADC1_DATA38_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD38_PRIO (4)
```

```c
#define AO_IR_ADCD38_SUBPRIO (0)
```

```c
#define AO_IR_ADCD39_ATTRIBUTE __ISR(_ADC1_DATA39_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD39_PRIO (4)
```

```c
#define AO_IR_ADCD39_SUBPRIO (0)
```

```c
#define AO_IR_ADCD4_ATTRIBUTE __ISR(_ADC1_DATA4_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD4_PRIO (4)
```

```c
#define AO_IR_ADCD4_SUBPRIO (0)
```

```c
#define AO_IR_ADCD40_ATTRIBUTE __ISR(_ADC1_DATA40_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD40_PRIO (4)
```

```c
#define AO_IR_ADCD40_SUBPRIO (0)
```

```c
#define AO_IR_ADCD41_ATTRIBUTE __ISR(_ADC1_DATA41_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD41_PRIO (4)
```

```c
#define AO_IR_ADCD41_SUBPRIO (0)
```

```c
#define AO_IR_ADCD42_ATTRIBUTE __ISR(_ADC1_DATA42_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD42_PRIO (4)
```

```c
#define AO_IR_ADCD42_SUBPRIO (0)
```

```c
#define AO_IR_ADCD43_ATTRIBUTE __ISR(_ADC1_DATA43_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD43_PRIO (4)
```

```c
#define AO_IR_ADCD43_SUBPRIO (0)
```

```c
#define AO_IR_ADCD44_ATTRIBUTE __ISR(_ADC1_DATA44_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD44_PRIO (4)
```

```c
#define AO_IR_ADCD44_SUBPRIO (0)
```

```c
#define AO_IR_ADCD5_ATTRIBUTE __ISR(_ADC1_DATA5_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD5_PRIO (4)
```

```c
#define AO_IR_ADCD5_SUBPRIO (0)
```

```c
#define AO_IR_ADCD6_ATTRIBUTE __ISR(_ADC1_DATA6_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD6_PRIO (4)
```

```c
#define AO_IR_ADCD6_SUBPRIO (0)
```

```c
#define AO_IR_ADCD7_ATTRIBUTE __ISR(_ADC1_DATA7_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD7_PRIO (4)
```

```c
#define AO_IR_ADCD7_SUBPRIO (0)
```

```c
#define AO_IR_ADCD8_ATTRIBUTE __ISR(_ADC1_DATA8_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD8_PRIO (4)
```

```c
#define AO_IR_ADCD8_SUBPRIO (0)
```

```c
#define AO_IR_ADCD9_ATTRIBUTE __ISR(_ADC1_DATA9_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCD9_PRIO (4)
```

```c
#define AO_IR_ADCD9_SUBPRIO (0)
```

```c
#define AO_IR_ADCDC1_ATTRIBUTE __ISR(_ADC1_DC1_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCDC1_PRIO (4)
```

```c
#define AO_IR_ADCDC1_SUBPRIO (0)
```

```c
#define AO_IR_ADCDC2_ATTRIBUTE __ISR(_ADC1_DC2_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCDC2_PRIO (4)
```

```c
#define AO_IR_ADCDC2_SUBPRIO (0)
```

```c
#define AO_IR_ADCDC3_ATTRIBUTE __ISR(_ADC1_DC3_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCDC3_PRIO (4)
```

```c
#define AO_IR_ADCDC3_SUBPRIO (0)
```

```c
#define AO_IR_ADCDC4_ATTRIBUTE __ISR(_ADC1_DC4_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCDC4_PRIO (4)
```

```c
#define AO_IR_ADCDC4_SUBPRIO (0)
```

```c
#define AO_IR_ADCDC5_ATTRIBUTE __ISR(_ADC1_DC5_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCDC5_PRIO (4)
```

```c
#define AO_IR_ADCDC5_SUBPRIO (0)
```

```c
#define AO_IR_ADCDC6_ATTRIBUTE __ISR(_ADC1_DC6_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCDC6_PRIO (4)
```

```c
#define AO_IR_ADCDC6_SUBPRIO (0)
```

```c
#define AO_IR_ADCDF1_ATTRIBUTE __ISR(_ADC1_DF1_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCDF1_PRIO (4)
```

```c
#define AO_IR_ADCDF1_SUBPRIO (0)
```

```c
#define AO_IR_ADCDF2_ATTRIBUTE __ISR(_ADC1_DF2_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCDF2_PRIO (4)
```

```c
#define AO_IR_ADCDF2_SUBPRIO (0)
```

```c
#define AO_IR_ADCDF3_ATTRIBUTE __ISR(_ADC1_DF3_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCDF3_PRIO (4)
```

```c
#define AO_IR_ADCDF3_SUBPRIO (0)
```

```c
#define AO_IR_ADCDF4_ATTRIBUTE __ISR(_ADC1_DF4_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCDF4_PRIO (4)
```

```c
#define AO_IR_ADCDF4_SUBPRIO (0)
```

```c
#define AO_IR_ADCDF5_ATTRIBUTE __ISR(_ADC1_DF5_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCDF5_PRIO (4)
```

```c
#define AO_IR_ADCDF5_SUBPRIO (0)
```

```c
#define AO_IR_ADCDF6_ATTRIBUTE __ISR(_ADC1_DF6_VECTOR, IPL4SRS)
```

```c
#define AO_IR_ADCDF6_PRIO (4)
```

```c
#define AO_IR_ADCDF6_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_adc_disable()
```

```c
#define ao_ir_adc_enable()
```

```c
#define ao_ir_adc_is_enabled()
```

```c
#define ao_ir_adc_is_pending()
```

```c
#define ao_ir_adc_reply()
```

```c
#define ao_ir_adc_request()
```

```c
#define ao_ir_adcd0_disable()
```

```c
#define ao_ir_adcd0_enable()
```

```c
#define ao_ir_adcd0_is_enabled()
```

```c
#define ao_ir_adcd0_is_pending()
```

```c
#define ao_ir_adcd0_reply()
```

```c
#define ao_ir_adcd0_request()
```

```c
#define ao_ir_adcd1_disable()
```

```c
#define ao_ir_adcd1_enable()
```

```c
#define ao_ir_adcd1_is_enabled()
```

```c
#define ao_ir_adcd1_is_pending()
```

```c
#define ao_ir_adcd1_reply()
```

```c
#define ao_ir_adcd1_request()
```

```c
#define ao_ir_adcd2_disable()
```

```c
#define ao_ir_adcd2_enable()
```

```c
#define ao_ir_adcd2_is_enabled()
```

```c
#define ao_ir_adcd2_is_pending()
```

```c
#define ao_ir_adcd2_reply()
```

```c
#define ao_ir_adcd2_request()
```

```c
#define ao_ir_adcd3_disable()
```

```c
#define ao_ir_adcd3_enable()
```

```c
#define ao_ir_adcd3_is_enabled()
```

```c
#define ao_ir_adcd3_is_pending()
```

```c
#define ao_ir_adcd3_reply()
```

```c
#define ao_ir_adcd3_request()
```

```c
#define ao_ir_adcd4_disable()
```

```c
#define ao_ir_adcd4_enable()
```

```c
#define ao_ir_adcd4_is_enabled()
```

```c
#define ao_ir_adcd4_is_pending()
```

```c
#define ao_ir_adcd4_reply()
```

```c
#define ao_ir_adcd4_request()
```

```c
#define ao_ir_adcd5_disable()
```

```c
#define ao_ir_adcd5_enable()
```

```c
#define ao_ir_adcd5_is_enabled()
```

```c
#define ao_ir_adcd5_is_pending()
```

```c
#define ao_ir_adcd5_reply()
```

```c
#define ao_ir_adcd5_request()
```

```c
#define ao_ir_adcd6_disable()
```

```c
#define ao_ir_adcd6_enable()
```

```c
#define ao_ir_adcd6_is_enabled()
```

```c
#define ao_ir_adcd6_is_pending()
```

```c
#define ao_ir_adcd6_reply()
```

```c
#define ao_ir_adcd6_request()
```

```c
#define ao_ir_adcd7_disable()
```

```c
#define ao_ir_adcd7_enable()
```

```c
#define ao_ir_adcd7_is_enabled()
```

```c
#define ao_ir_adcd7_is_pending()
```

```c
#define ao_ir_adcd7_reply()
```

```c
#define ao_ir_adcd7_request()
```

```c
#define ao_ir_adcd8_disable()
```

```c
#define ao_ir_adcd8_enable()
```

```c
#define ao_ir_adcd8_is_enabled()
```

```c
#define ao_ir_adcd8_is_pending()
```

```c
#define ao_ir_adcd8_reply()
```

```c
#define ao_ir_adcd8_request()
```

```c
#define ao_ir_adcd9_disable()
```

```c
#define ao_ir_adcd9_enable()
```

```c
#define ao_ir_adcd9_is_enabled()
```

```c
#define ao_ir_adcd9_is_pending()
```

```c
#define ao_ir_adcd9_reply()
```

```c
#define ao_ir_adcd9_request()
```

```c
#define ao_ir_adcd10_disable()
```

```c
#define ao_ir_adcd10_enable()
```

```c
#define ao_ir_adcd10_is_enabled()
```

```c
#define ao_ir_adcd10_is_pending()
```

```c
#define ao_ir_adcd10_reply()
```

```c
#define ao_ir_adcd10_request()
```

```c
#define ao_ir_adcd11_disable()
```

```c
#define ao_ir_adcd11_enable()
```

```c
#define ao_ir_adcd11_is_enabled()
```

```c
#define ao_ir_adcd11_is_pending()
```

```c
#define ao_ir_adcd11_reply()
```

```c
#define ao_ir_adcd11_request()
```

```c
#define ao_ir_adcd12_disable()
```

```c
#define ao_ir_adcd12_enable()
```

```c
#define ao_ir_adcd12_is_enabled()
```

```c
#define ao_ir_adcd12_is_pending()
```

```c
#define ao_ir_adcd12_reply()
```

```c
#define ao_ir_adcd12_request()
```

```c
#define ao_ir_adcd13_disable()
```

```c
#define ao_ir_adcd13_enable()
```

```c
#define ao_ir_adcd13_is_enabled()
```

```c
#define ao_ir_adcd13_is_pending()
```

```c
#define ao_ir_adcd13_reply()
```

```c
#define ao_ir_adcd13_request()
```

```c
#define ao_ir_adcd14_disable()
```

```c
#define ao_ir_adcd14_enable()
```

```c
#define ao_ir_adcd14_is_enabled()
```

```c
#define ao_ir_adcd14_is_pending()
```

```c
#define ao_ir_adcd14_reply()
```

```c
#define ao_ir_adcd14_request()
```

```c
#define ao_ir_adcd15_disable()
```

```c
#define ao_ir_adcd15_enable()
```

```c
#define ao_ir_adcd15_is_enabled()
```

```c
#define ao_ir_adcd15_is_pending()
```

```c
#define ao_ir_adcd15_reply()
```

```c
#define ao_ir_adcd15_request()
```

```c
#define ao_ir_adcd16_disable()
```

```c
#define ao_ir_adcd16_enable()
```

```c
#define ao_ir_adcd16_is_enabled()
```

```c
#define ao_ir_adcd16_is_pending()
```

```c
#define ao_ir_adcd16_reply()
```

```c
#define ao_ir_adcd16_request()
```

```c
#define ao_ir_adcd17_disable()
```

```c
#define ao_ir_adcd17_enable()
```

```c
#define ao_ir_adcd17_is_enabled()
```

```c
#define ao_ir_adcd17_is_pending()
```

```c
#define ao_ir_adcd17_reply()
```

```c
#define ao_ir_adcd17_request()
```

```c
#define ao_ir_adcd18_disable()
```

```c
#define ao_ir_adcd18_enable()
```

```c
#define ao_ir_adcd18_is_enabled()
```

```c
#define ao_ir_adcd18_is_pending()
```

```c
#define ao_ir_adcd18_reply()
```

```c
#define ao_ir_adcd18_request()
```

```c
#define ao_ir_adcd19_disable()
```

```c
#define ao_ir_adcd19_enable()
```

```c
#define ao_ir_adcd19_is_enabled()
```

```c
#define ao_ir_adcd19_is_pending()
```

```c
#define ao_ir_adcd19_reply()
```

```c
#define ao_ir_adcd19_request()
```

```c
#define ao_ir_adcd20_disable()
```

```c
#define ao_ir_adcd20_enable()
```

```c
#define ao_ir_adcd20_is_enabled()
```

```c
#define ao_ir_adcd20_is_pending()
```

```c
#define ao_ir_adcd20_reply()
```

```c
#define ao_ir_adcd20_request()
```

```c
#define ao_ir_adcd21_disable()
```

```c
#define ao_ir_adcd21_enable()
```

```c
#define ao_ir_adcd21_is_enabled()
```

```c
#define ao_ir_adcd21_is_pending()
```

```c
#define ao_ir_adcd21_reply()
```

```c
#define ao_ir_adcd21_request()
```

```c
#define ao_ir_adcd22_disable()
```

```c
#define ao_ir_adcd22_enable()
```

```c
#define ao_ir_adcd22_is_enabled()
```

```c
#define ao_ir_adcd22_is_pending()
```

```c
#define ao_ir_adcd22_reply()
```

```c
#define ao_ir_adcd22_request()
```

```c
#define ao_ir_adcd23_disable()
```

```c
#define ao_ir_adcd23_enable()
```

```c
#define ao_ir_adcd23_is_enabled()
```

```c
#define ao_ir_adcd23_is_pending()
```

```c
#define ao_ir_adcd23_reply()
```

```c
#define ao_ir_adcd23_request()
```

```c
#define ao_ir_adcd24_disable()
```

```c
#define ao_ir_adcd24_enable()
```

```c
#define ao_ir_adcd24_is_enabled()
```

```c
#define ao_ir_adcd24_is_pending()
```

```c
#define ao_ir_adcd24_reply()
```

```c
#define ao_ir_adcd24_request()
```

```c
#define ao_ir_adcd25_disable()
```

```c
#define ao_ir_adcd25_enable()
```

```c
#define ao_ir_adcd25_is_enabled()
```

```c
#define ao_ir_adcd25_is_pending()
```

```c
#define ao_ir_adcd25_reply()
```

```c
#define ao_ir_adcd25_request()
```

```c
#define ao_ir_adcd26_disable()
```

```c
#define ao_ir_adcd26_enable()
```

```c
#define ao_ir_adcd26_is_enabled()
```

```c
#define ao_ir_adcd26_is_pending()
```

```c
#define ao_ir_adcd26_reply()
```

```c
#define ao_ir_adcd26_request()
```

```c
#define ao_ir_adcd27_disable()
```

```c
#define ao_ir_adcd27_enable()
```

```c
#define ao_ir_adcd27_is_enabled()
```

```c
#define ao_ir_adcd27_is_pending()
```

```c
#define ao_ir_adcd27_reply()
```

```c
#define ao_ir_adcd27_request()
```

```c
#define ao_ir_adcd28_disable()
```

```c
#define ao_ir_adcd28_enable()
```

```c
#define ao_ir_adcd28_is_enabled()
```

```c
#define ao_ir_adcd28_is_pending()
```

```c
#define ao_ir_adcd28_reply()
```

```c
#define ao_ir_adcd28_request()
```

```c
#define ao_ir_adcd29_disable()
```

```c
#define ao_ir_adcd29_enable()
```

```c
#define ao_ir_adcd29_is_enabled()
```

```c
#define ao_ir_adcd29_is_pending()
```

```c
#define ao_ir_adcd29_reply()
```

```c
#define ao_ir_adcd29_request()
```

```c
#define ao_ir_adcd30_disable()
```

```c
#define ao_ir_adcd30_enable()
```

```c
#define ao_ir_adcd30_is_enabled()
```

```c
#define ao_ir_adcd30_is_pending()
```

```c
#define ao_ir_adcd30_reply()
```

```c
#define ao_ir_adcd30_request()
```

```c
#define ao_ir_adcd31_disable()
```

```c
#define ao_ir_adcd31_enable()
```

```c
#define ao_ir_adcd31_is_enabled()
```

```c
#define ao_ir_adcd31_is_pending()
```

```c
#define ao_ir_adcd31_reply()
```

```c
#define ao_ir_adcd31_request()
```

```c
#define ao_ir_adcd32_disable()
```

```c
#define ao_ir_adcd32_enable()
```

```c
#define ao_ir_adcd32_is_enabled()
```

```c
#define ao_ir_adcd32_is_pending()
```

```c
#define ao_ir_adcd32_reply()
```

```c
#define ao_ir_adcd32_request()
```

```c
#define ao_ir_adcd33_disable()
```

```c
#define ao_ir_adcd33_enable()
```

```c
#define ao_ir_adcd33_is_enabled()
```

```c
#define ao_ir_adcd33_is_pending()
```

```c
#define ao_ir_adcd33_reply()
```

```c
#define ao_ir_adcd33_request()
```

```c
#define ao_ir_adcd34_disable()
```

```c
#define ao_ir_adcd34_enable()
```

```c
#define ao_ir_adcd34_is_enabled()
```

```c
#define ao_ir_adcd34_is_pending()
```

```c
#define ao_ir_adcd34_reply()
```

```c
#define ao_ir_adcd34_request()
```

```c
#define ao_ir_adcd35_disable()
```

```c
#define ao_ir_adcd35_enable()
```

```c
#define ao_ir_adcd35_is_enabled()
```

```c
#define ao_ir_adcd35_is_pending()
```

```c
#define ao_ir_adcd35_reply()
```

```c
#define ao_ir_adcd35_request()
```

```c
#define ao_ir_adcd36_disable()
```

```c
#define ao_ir_adcd36_enable()
```

```c
#define ao_ir_adcd36_is_enabled()
```

```c
#define ao_ir_adcd36_is_pending()
```

```c
#define ao_ir_adcd36_reply()
```

```c
#define ao_ir_adcd36_request()
```

```c
#define ao_ir_adcd37_disable()
```

```c
#define ao_ir_adcd37_enable()
```

```c
#define ao_ir_adcd37_is_enabled()
```

```c
#define ao_ir_adcd37_is_pending()
```

```c
#define ao_ir_adcd37_reply()
```

```c
#define ao_ir_adcd37_request()
```

```c
#define ao_ir_adcd38_disable()
```

```c
#define ao_ir_adcd38_enable()
```

```c
#define ao_ir_adcd38_is_enabled()
```

```c
#define ao_ir_adcd38_is_pending()
```

```c
#define ao_ir_adcd38_reply()
```

```c
#define ao_ir_adcd38_request()
```

```c
#define ao_ir_adcd39_disable()
```

```c
#define ao_ir_adcd39_enable()
```

```c
#define ao_ir_adcd39_is_enabled()
```

```c
#define ao_ir_adcd39_is_pending()
```

```c
#define ao_ir_adcd39_reply()
```

```c
#define ao_ir_adcd39_request()
```

```c
#define ao_ir_adcd40_disable()
```

```c
#define ao_ir_adcd40_enable()
```

```c
#define ao_ir_adcd40_is_enabled()
```

```c
#define ao_ir_adcd40_is_pending()
```

```c
#define ao_ir_adcd40_reply()
```

```c
#define ao_ir_adcd40_request()
```

```c
#define ao_ir_adcd41_disable()
```

```c
#define ao_ir_adcd41_enable()
```

```c
#define ao_ir_adcd41_is_enabled()
```

```c
#define ao_ir_adcd41_is_pending()
```

```c
#define ao_ir_adcd41_reply()
```

```c
#define ao_ir_adcd41_request()
```

```c
#define ao_ir_adcd42_disable()
```

```c
#define ao_ir_adcd42_enable()
```

```c
#define ao_ir_adcd42_is_enabled()
```

```c
#define ao_ir_adcd42_is_pending()
```

```c
#define ao_ir_adcd42_reply()
```

```c
#define ao_ir_adcd42_request()
```

```c
#define ao_ir_adcd43_disable()
```

```c
#define ao_ir_adcd43_enable()
```

```c
#define ao_ir_adcd43_is_enabled()
```

```c
#define ao_ir_adcd43_is_pending()
```

```c
#define ao_ir_adcd43_reply()
```

```c
#define ao_ir_adcd43_request()
```

```c
#define ao_ir_adcd44_disable()
```

```c
#define ao_ir_adcd44_enable()
```

```c
#define ao_ir_adcd44_is_enabled()
```

```c
#define ao_ir_adcd44_is_pending()
```

```c
#define ao_ir_adcd44_reply()
```

```c
#define ao_ir_adcd44_request()
```

```c
#define ao_ir_adcdc1_disable()
```

```c
#define ao_ir_adcdc1_enable()
```

```c
#define ao_ir_adcdc1_is_enabled()
```

```c
#define ao_ir_adcdc1_is_pending()
```

```c
#define ao_ir_adcdc1_reply()
```

```c
#define ao_ir_adcdc1_request()
```

```c
#define ao_ir_adcdc2_disable()
```

```c
#define ao_ir_adcdc2_enable()
```

```c
#define ao_ir_adcdc2_is_enabled()
```

```c
#define ao_ir_adcdc2_is_pending()
```

```c
#define ao_ir_adcdc2_reply()
```

```c
#define ao_ir_adcdc2_request()
```

```c
#define ao_ir_adcdc3_disable()
```

```c
#define ao_ir_adcdc3_enable()
```

```c
#define ao_ir_adcdc3_is_enabled()
```

```c
#define ao_ir_adcdc3_is_pending()
```

```c
#define ao_ir_adcdc3_reply()
```

```c
#define ao_ir_adcdc3_request()
```

```c
#define ao_ir_adcdc4_disable()
```

```c
#define ao_ir_adcdc4_enable()
```

```c
#define ao_ir_adcdc4_is_enabled()
```

```c
#define ao_ir_adcdc4_is_pending()
```

```c
#define ao_ir_adcdc4_reply()
```

```c
#define ao_ir_adcdc4_request()
```

```c
#define ao_ir_adcdc5_disable()
```

```c
#define ao_ir_adcdc5_enable()
```

```c
#define ao_ir_adcdc5_is_enabled()
```

```c
#define ao_ir_adcdc5_is_pending()
```

```c
#define ao_ir_adcdc5_reply()
```

```c
#define ao_ir_adcdc5_request()
```

```c
#define ao_ir_adcdc6_disable()
```

```c
#define ao_ir_adcdc6_enable()
```

```c
#define ao_ir_adcdc6_is_enabled()
```

```c
#define ao_ir_adcdc6_is_pending()
```

```c
#define ao_ir_adcdc6_reply()
```

```c
#define ao_ir_adcdc6_request()
```

```c
#define ao_ir_adcdf1_disable()
```

```c
#define ao_ir_adcdf1_enable()
```

```c
#define ao_ir_adcdf1_is_enabled()
```

```c
#define ao_ir_adcdf1_is_pending()
```

```c
#define ao_ir_adcdf1_reply()
```

```c
#define ao_ir_adcdf1_request()
```

```c
#define ao_ir_adcdf2_disable()
```

```c
#define ao_ir_adcdf2_enable()
```

```c
#define ao_ir_adcdf2_is_enabled()
```

```c
#define ao_ir_adcdf2_is_pending()
```

```c
#define ao_ir_adcdf2_reply()
```

```c
#define ao_ir_adcdf2_request()
```

```c
#define ao_ir_adcdf3_disable()
```

```c
#define ao_ir_adcdf3_enable()
```

```c
#define ao_ir_adcdf3_is_enabled()
```

```c
#define ao_ir_adcdf3_is_pending()
```

```c
#define ao_ir_adcdf3_reply()
```

```c
#define ao_ir_adcdf3_request()
```

```c
#define ao_ir_adcdf4_disable()
```

```c
#define ao_ir_adcdf4_enable()
```

```c
#define ao_ir_adcdf4_is_enabled()
```

```c
#define ao_ir_adcdf4_is_pending()
```

```c
#define ao_ir_adcdf4_reply()
```

```c
#define ao_ir_adcdf4_request()
```

```c
#define ao_ir_adcdf5_disable()
```

```c
#define ao_ir_adcdf5_enable()
```

```c
#define ao_ir_adcdf5_is_enabled()
```

```c
#define ao_ir_adcdf5_is_pending()
```

```c
#define ao_ir_adcdf5_reply()
```

```c
#define ao_ir_adcdf5_request()
```

```c
#define ao_ir_adcdf6_disable()
```

```c
#define ao_ir_adcdf6_enable()
```

```c
#define ao_ir_adcdf6_is_enabled()
```

```c
#define ao_ir_adcdf6_is_pending()
```

```c
#define ao_ir_adcdf6_reply()
```

```c
#define ao_ir_adcdf6_request()
```

