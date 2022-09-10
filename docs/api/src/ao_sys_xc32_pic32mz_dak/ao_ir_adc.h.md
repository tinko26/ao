---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz_dak/ao_ir_adc.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_ADC`

```c
#define AO_IR_ADC_ATTRIBUTE __ISR(_ADC_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADC_PRIO    (4)
#define AO_IR_ADC_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADC0E`

```c
#define AO_IR_ADC0E_ATTRIBUTE __ISR(_ADC0_EARLY_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADC0E_PRIO    (4)
#define AO_IR_ADC0E_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADC0W`

```c
#define AO_IR_ADC0W_ATTRIBUTE __ISR(_ADC0_WARM_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADC0W_PRIO    (4)
#define AO_IR_ADC0W_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADC1E`

```c
#define AO_IR_ADC1E_ATTRIBUTE __ISR(_ADC1_EARLY_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADC1E_PRIO    (4)
#define AO_IR_ADC1E_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADC1W`

```c
#define AO_IR_ADC1W_ATTRIBUTE __ISR(_ADC1_WARM_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADC1W_PRIO    (4)
#define AO_IR_ADC1W_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADC2E`

```c
#define AO_IR_ADC2E_ATTRIBUTE __ISR(_ADC2_EARLY_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADC2E_PRIO    (4)
#define AO_IR_ADC2E_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADC2W`

```c
#define AO_IR_ADC2W_ATTRIBUTE __ISR(_ADC2_WARM_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADC2W_PRIO    (4)
#define AO_IR_ADC2W_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADC3E`

```c
#define AO_IR_ADC3E_ATTRIBUTE __ISR(_ADC3_EARLY_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADC3E_PRIO    (4)
#define AO_IR_ADC3E_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADC3W`

```c
#define AO_IR_ADC3W_ATTRIBUTE __ISR(_ADC3_WARM_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADC3W_PRIO    (4)
#define AO_IR_ADC3W_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADC4E`

```c
#define AO_IR_ADC4E_ATTRIBUTE __ISR(_ADC4_EARLY_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADC4E_PRIO    (4)
#define AO_IR_ADC4E_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADC4W`

```c
#define AO_IR_ADC4W_ATTRIBUTE __ISR(_ADC4_WARM_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADC4W_PRIO    (4)
#define AO_IR_ADC4W_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADC7E`

```c
#define AO_IR_ADC7E_ATTRIBUTE __ISR(_ADC7_EARLY_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADC7E_PRIO    (4)
#define AO_IR_ADC7E_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADC7W`

```c
#define AO_IR_ADC7W_ATTRIBUTE __ISR(_ADC7_WARM_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADC7W_PRIO    (4)
#define AO_IR_ADC7W_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCARDY`

```c
#define AO_IR_ADCARDY_ATTRIBUTE __ISR(_ADC_ARDY_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCARDY_PRIO    (4)
#define AO_IR_ADCARDY_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD0`

```c
#define AO_IR_ADCD0_ATTRIBUTE __ISR(_ADC_DATA0_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD0_PRIO    (4)
#define AO_IR_ADCD0_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD1`

```c
#define AO_IR_ADCD1_ATTRIBUTE __ISR(_ADC_DATA1_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD1_PRIO    (4)
#define AO_IR_ADCD1_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD10`

```c
#define AO_IR_ADCD10_ATTRIBUTE __ISR(_ADC_DATA10_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD10_PRIO    (4)
#define AO_IR_ADCD10_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD11`

```c
#define AO_IR_ADCD11_ATTRIBUTE __ISR(_ADC_DATA11_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD11_PRIO    (4)
#define AO_IR_ADCD11_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD12`

```c
#define AO_IR_ADCD12_ATTRIBUTE __ISR(_ADC_DATA12_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD12_PRIO    (4)
#define AO_IR_ADCD12_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD13`

```c
#define AO_IR_ADCD13_ATTRIBUTE __ISR(_ADC_DATA13_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD13_PRIO    (4)
#define AO_IR_ADCD13_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD14`

```c
#define AO_IR_ADCD14_ATTRIBUTE __ISR(_ADC_DATA14_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD14_PRIO    (4)
#define AO_IR_ADCD14_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD15`

```c
#define AO_IR_ADCD15_ATTRIBUTE __ISR(_ADC_DATA15_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD15_PRIO    (4)
#define AO_IR_ADCD15_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD16`

```c
#define AO_IR_ADCD16_ATTRIBUTE __ISR(_ADC_DATA16_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD16_PRIO    (4)
#define AO_IR_ADCD16_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD17`

```c
#define AO_IR_ADCD17_ATTRIBUTE __ISR(_ADC_DATA17_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD17_PRIO    (4)
#define AO_IR_ADCD17_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD18`

```c
#define AO_IR_ADCD18_ATTRIBUTE __ISR(_ADC_DATA18_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD18_PRIO    (4)
#define AO_IR_ADCD18_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD19`

```c
#define AO_IR_ADCD19_ATTRIBUTE __ISR(_ADC_DATA19_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD19_PRIO    (4)
#define AO_IR_ADCD19_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD2`

```c
#define AO_IR_ADCD2_ATTRIBUTE __ISR(_ADC_DATA2_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD2_PRIO    (4)
#define AO_IR_ADCD2_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD20`

```c
#define AO_IR_ADCD20_ATTRIBUTE __ISR(_ADC_DATA20_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD20_PRIO    (4)
#define AO_IR_ADCD20_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD21`

```c
#define AO_IR_ADCD21_ATTRIBUTE __ISR(_ADC_DATA21_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD21_PRIO    (4)
#define AO_IR_ADCD21_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD22`

```c
#define AO_IR_ADCD22_ATTRIBUTE __ISR(_ADC_DATA22_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD22_PRIO    (4)
#define AO_IR_ADCD22_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD23`

```c
#define AO_IR_ADCD23_ATTRIBUTE __ISR(_ADC_DATA23_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD23_PRIO    (4)
#define AO_IR_ADCD23_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD24`

```c
#define AO_IR_ADCD24_ATTRIBUTE __ISR(_ADC_DATA24_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD24_PRIO    (4)
#define AO_IR_ADCD24_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD25`

```c
#define AO_IR_ADCD25_ATTRIBUTE __ISR(_ADC_DATA25_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD25_PRIO    (4)
#define AO_IR_ADCD25_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD26`

```c
#define AO_IR_ADCD26_ATTRIBUTE __ISR(_ADC_DATA26_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD26_PRIO    (4)
#define AO_IR_ADCD26_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD27`

```c
#define AO_IR_ADCD27_ATTRIBUTE __ISR(_ADC_DATA27_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD27_PRIO    (4)
#define AO_IR_ADCD27_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD28`

```c
#define AO_IR_ADCD28_ATTRIBUTE __ISR(_ADC_DATA28_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD28_PRIO    (4)
#define AO_IR_ADCD28_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD29`

```c
#define AO_IR_ADCD29_ATTRIBUTE __ISR(_ADC_DATA29_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD29_PRIO    (4)
#define AO_IR_ADCD29_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD3`

```c
#define AO_IR_ADCD3_ATTRIBUTE __ISR(_ADC_DATA3_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD3_PRIO    (4)
#define AO_IR_ADCD3_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD30`

```c
#define AO_IR_ADCD30_ATTRIBUTE __ISR(_ADC_DATA30_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD30_PRIO    (4)
#define AO_IR_ADCD30_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD31`

```c
#define AO_IR_ADCD31_ATTRIBUTE __ISR(_ADC_DATA31_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD31_PRIO    (4)
#define AO_IR_ADCD31_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD32`

```c
#define AO_IR_ADCD32_ATTRIBUTE __ISR(_ADC_DATA32_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD32_PRIO    (4)
#define AO_IR_ADCD32_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD33`

```c
#define AO_IR_ADCD33_ATTRIBUTE __ISR(_ADC_DATA33_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD33_PRIO    (4)
#define AO_IR_ADCD33_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD34`

```c
#define AO_IR_ADCD34_ATTRIBUTE __ISR(_ADC_DATA34_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD34_PRIO    (4)
#define AO_IR_ADCD34_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD35`

```c
#define AO_IR_ADCD35_ATTRIBUTE __ISR(_ADC_DATA35_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD35_PRIO    (4)
#define AO_IR_ADCD35_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD36`

```c
#define AO_IR_ADCD36_ATTRIBUTE __ISR(_ADC_DATA36_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD36_PRIO    (4)
#define AO_IR_ADCD36_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD37`

```c
#define AO_IR_ADCD37_ATTRIBUTE __ISR(_ADC_DATA37_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD37_PRIO    (4)
#define AO_IR_ADCD37_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD38`

```c
#define AO_IR_ADCD38_ATTRIBUTE __ISR(_ADC_DATA38_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD38_PRIO    (4)
#define AO_IR_ADCD38_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD39`

```c
#define AO_IR_ADCD39_ATTRIBUTE __ISR(_ADC_DATA39_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD39_PRIO    (4)
#define AO_IR_ADCD39_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD4`

```c
#define AO_IR_ADCD4_ATTRIBUTE __ISR(_ADC_DATA4_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD4_PRIO    (4)
#define AO_IR_ADCD4_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD40`

```c
#define AO_IR_ADCD40_ATTRIBUTE __ISR(_ADC_DATA40_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD40_PRIO    (4)
#define AO_IR_ADCD40_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD41`

```c
#define AO_IR_ADCD41_ATTRIBUTE __ISR(_ADC_DATA41_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD41_PRIO    (4)
#define AO_IR_ADCD41_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD42`

```c
#define AO_IR_ADCD42_ATTRIBUTE __ISR(_ADC_DATA42_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD42_PRIO    (4)
#define AO_IR_ADCD42_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD43`

```c
#define AO_IR_ADCD43_ATTRIBUTE __ISR(_ADC_DATA43_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD43_PRIO    (4)
#define AO_IR_ADCD43_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD5`

```c
#define AO_IR_ADCD5_ATTRIBUTE __ISR(_ADC_DATA5_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD5_PRIO    (4)
#define AO_IR_ADCD5_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD6`

```c
#define AO_IR_ADCD6_ATTRIBUTE __ISR(_ADC_DATA6_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD6_PRIO    (4)
#define AO_IR_ADCD6_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD7`

```c
#define AO_IR_ADCD7_ATTRIBUTE __ISR(_ADC_DATA7_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD7_PRIO    (4)
#define AO_IR_ADCD7_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD8`

```c
#define AO_IR_ADCD8_ATTRIBUTE __ISR(_ADC_DATA8_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD8_PRIO    (4)
#define AO_IR_ADCD8_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCD9`

```c
#define AO_IR_ADCD9_ATTRIBUTE __ISR(_ADC_DATA9_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCD9_PRIO    (4)
#define AO_IR_ADCD9_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCDC1`

```c
#define AO_IR_ADCDC1_ATTRIBUTE __ISR(_ADC_DC1_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCDC1_PRIO    (4)
#define AO_IR_ADCDC1_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCDC2`

```c
#define AO_IR_ADCDC2_ATTRIBUTE __ISR(_ADC_DC2_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCDC2_PRIO    (4)
#define AO_IR_ADCDC2_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCDC3`

```c
#define AO_IR_ADCDC3_ATTRIBUTE __ISR(_ADC_DC3_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCDC3_PRIO    (4)
#define AO_IR_ADCDC3_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCDC4`

```c
#define AO_IR_ADCDC4_ATTRIBUTE __ISR(_ADC_DC4_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCDC4_PRIO    (4)
#define AO_IR_ADCDC4_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCDC5`

```c
#define AO_IR_ADCDC5_ATTRIBUTE __ISR(_ADC_DC5_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCDC5_PRIO    (4)
#define AO_IR_ADCDC5_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCDC6`

```c
#define AO_IR_ADCDC6_ATTRIBUTE __ISR(_ADC_DC6_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCDC6_PRIO    (4)
#define AO_IR_ADCDC6_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCDF1`

```c
#define AO_IR_ADCDF1_ATTRIBUTE __ISR(_ADC_DF1_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCDF1_PRIO    (4)
#define AO_IR_ADCDF1_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCDF2`

```c
#define AO_IR_ADCDF2_ATTRIBUTE __ISR(_ADC_DF2_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCDF2_PRIO    (4)
#define AO_IR_ADCDF2_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCDF3`

```c
#define AO_IR_ADCDF3_ATTRIBUTE __ISR(_ADC_DF3_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCDF3_PRIO    (4)
#define AO_IR_ADCDF3_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCDF4`

```c
#define AO_IR_ADCDF4_ATTRIBUTE __ISR(_ADC_DF4_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCDF4_PRIO    (4)
#define AO_IR_ADCDF4_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCDF5`

```c
#define AO_IR_ADCDF5_ATTRIBUTE __ISR(_ADC_DF5_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCDF5_PRIO    (4)
#define AO_IR_ADCDF5_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCDF6`

```c
#define AO_IR_ADCDF6_ATTRIBUTE __ISR(_ADC_DF6_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCDF6_PRIO    (4)
#define AO_IR_ADCDF6_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCEOS`

```c
#define AO_IR_ADCEOS_ATTRIBUTE __ISR(_ADC_EOS_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCEOS_PRIO    (4)
#define AO_IR_ADCEOS_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCFIFO`

```c
#define AO_IR_ADCFIFO_ATTRIBUTE __ISR(_ADC_FIFO_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCFIFO_PRIO    (4)
#define AO_IR_ADCFIFO_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCFLT`

```c
#define AO_IR_ADCFLT_ATTRIBUTE __ISR(_ADC_FAULT_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCFLT_PRIO    (4)
#define AO_IR_ADCFLT_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCGRP`

```c
#define AO_IR_ADCGRP_ATTRIBUTE __ISR(_ADC_EARLY_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCGRP_PRIO    (4)
#define AO_IR_ADCGRP_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_ADCURDY`

```c
#define AO_IR_ADCURDY_ATTRIBUTE __ISR(_ADC_URDY_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_ADCURDY_PRIO    (4)
#define AO_IR_ADCURDY_SUBPRIO (0)
```

The interrupt priority and subpriority.

# Functions

## `ao_ir_adc`

```c
#define ao_ir_adc_enable()
#define ao_ir_adc_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adc_request()
#define ao_ir_adc_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adc_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adc_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adc0e`

```c
#define ao_ir_adc0e_enable()
#define ao_ir_adc0e_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adc0e_request()
#define ao_ir_adc0e_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adc0e_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adc0e_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adc0w`

```c
#define ao_ir_adc0w_enable()
#define ao_ir_adc0w_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adc0w_request()
#define ao_ir_adc0w_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adc0w_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adc0w_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adc1e`

```c
#define ao_ir_adc1e_enable()
#define ao_ir_adc1e_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adc1e_request()
#define ao_ir_adc1e_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adc1e_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adc1e_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adc1w`

```c
#define ao_ir_adc1w_enable()
#define ao_ir_adc1w_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adc1w_request()
#define ao_ir_adc1w_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adc1w_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adc1w_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adc2e`

```c
#define ao_ir_adc2e_enable()
#define ao_ir_adc2e_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adc2e_request()
#define ao_ir_adc2e_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adc2e_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adc2e_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adc2w`

```c
#define ao_ir_adc2w_enable()
#define ao_ir_adc2w_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adc2w_request()
#define ao_ir_adc2w_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adc2w_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adc2w_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adc3e`

```c
#define ao_ir_adc3e_enable()
#define ao_ir_adc3e_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adc3e_request()
#define ao_ir_adc3e_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adc3e_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adc3e_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adc3w`

```c
#define ao_ir_adc3w_enable()
#define ao_ir_adc3w_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adc3w_request()
#define ao_ir_adc3w_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adc3w_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adc3w_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adc4e`

```c
#define ao_ir_adc4e_enable()
#define ao_ir_adc4e_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adc4e_request()
#define ao_ir_adc4e_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adc4e_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adc4e_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adc4w`

```c
#define ao_ir_adc4w_enable()
#define ao_ir_adc4w_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adc4w_request()
#define ao_ir_adc4w_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adc4w_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adc4w_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adc7e`

```c
#define ao_ir_adc7e_enable()
#define ao_ir_adc7e_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adc7e_request()
#define ao_ir_adc7e_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adc7e_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adc7e_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adc7w`

```c
#define ao_ir_adc7w_enable()
#define ao_ir_adc7w_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adc7w_request()
#define ao_ir_adc7w_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adc7w_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adc7w_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcardy`

```c
#define ao_ir_adcardy_enable()
#define ao_ir_adcardy_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcardy_request()
#define ao_ir_adcardy_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcardy_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcardy_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd0`

```c
#define ao_ir_adcd0_enable()
#define ao_ir_adcd0_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd0_request()
#define ao_ir_adcd0_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd0_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd0_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd1`

```c
#define ao_ir_adcd1_enable()
#define ao_ir_adcd1_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd1_request()
#define ao_ir_adcd1_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd1_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd1_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd2`

```c
#define ao_ir_adcd2_enable()
#define ao_ir_adcd2_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd2_request()
#define ao_ir_adcd2_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd2_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd2_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd3`

```c
#define ao_ir_adcd3_enable()
#define ao_ir_adcd3_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd3_request()
#define ao_ir_adcd3_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd3_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd3_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd4`

```c
#define ao_ir_adcd4_enable()
#define ao_ir_adcd4_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd4_request()
#define ao_ir_adcd4_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd4_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd4_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd5`

```c
#define ao_ir_adcd5_enable()
#define ao_ir_adcd5_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd5_request()
#define ao_ir_adcd5_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd5_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd5_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd6`

```c
#define ao_ir_adcd6_enable()
#define ao_ir_adcd6_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd6_request()
#define ao_ir_adcd6_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd6_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd6_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd7`

```c
#define ao_ir_adcd7_enable()
#define ao_ir_adcd7_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd7_request()
#define ao_ir_adcd7_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd7_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd7_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd8`

```c
#define ao_ir_adcd8_enable()
#define ao_ir_adcd8_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd8_request()
#define ao_ir_adcd8_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd8_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd8_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd9`

```c
#define ao_ir_adcd9_enable()
#define ao_ir_adcd9_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd9_request()
#define ao_ir_adcd9_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd9_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd9_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd10`

```c
#define ao_ir_adcd10_enable()
#define ao_ir_adcd10_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd10_request()
#define ao_ir_adcd10_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd10_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd10_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd11`

```c
#define ao_ir_adcd11_enable()
#define ao_ir_adcd11_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd11_request()
#define ao_ir_adcd11_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd11_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd11_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd12`

```c
#define ao_ir_adcd12_enable()
#define ao_ir_adcd12_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd12_request()
#define ao_ir_adcd12_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd12_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd12_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd13`

```c
#define ao_ir_adcd13_enable()
#define ao_ir_adcd13_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd13_request()
#define ao_ir_adcd13_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd13_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd13_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd14`

```c
#define ao_ir_adcd14_enable()
#define ao_ir_adcd14_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd14_request()
#define ao_ir_adcd14_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd14_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd14_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd15`

```c
#define ao_ir_adcd15_enable()
#define ao_ir_adcd15_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd15_request()
#define ao_ir_adcd15_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd15_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd15_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd16`

```c
#define ao_ir_adcd16_enable()
#define ao_ir_adcd16_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd16_request()
#define ao_ir_adcd16_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd16_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd16_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd17`

```c
#define ao_ir_adcd17_enable()
#define ao_ir_adcd17_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd17_request()
#define ao_ir_adcd17_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd17_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd17_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd18`

```c
#define ao_ir_adcd18_enable()
#define ao_ir_adcd18_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd18_request()
#define ao_ir_adcd18_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd18_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd18_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd19`

```c
#define ao_ir_adcd19_enable()
#define ao_ir_adcd19_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd19_request()
#define ao_ir_adcd19_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd19_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd19_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd20`

```c
#define ao_ir_adcd20_enable()
#define ao_ir_adcd20_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd20_request()
#define ao_ir_adcd20_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd20_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd20_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd21`

```c
#define ao_ir_adcd21_enable()
#define ao_ir_adcd21_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd21_request()
#define ao_ir_adcd21_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd21_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd21_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd22`

```c
#define ao_ir_adcd22_enable()
#define ao_ir_adcd22_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd22_request()
#define ao_ir_adcd22_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd22_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd22_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd23`

```c
#define ao_ir_adcd23_enable()
#define ao_ir_adcd23_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd23_request()
#define ao_ir_adcd23_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd23_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd23_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd24`

```c
#define ao_ir_adcd24_enable()
#define ao_ir_adcd24_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd24_request()
#define ao_ir_adcd24_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd24_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd24_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd25`

```c
#define ao_ir_adcd25_enable()
#define ao_ir_adcd25_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd25_request()
#define ao_ir_adcd25_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd25_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd25_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd26`

```c
#define ao_ir_adcd26_enable()
#define ao_ir_adcd26_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd26_request()
#define ao_ir_adcd26_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd26_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd26_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd27`

```c
#define ao_ir_adcd27_enable()
#define ao_ir_adcd27_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd27_request()
#define ao_ir_adcd27_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd27_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd27_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd28`

```c
#define ao_ir_adcd28_enable()
#define ao_ir_adcd28_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd28_request()
#define ao_ir_adcd28_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd28_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd28_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd29`

```c
#define ao_ir_adcd29_enable()
#define ao_ir_adcd29_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd29_request()
#define ao_ir_adcd29_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd29_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd29_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd30`

```c
#define ao_ir_adcd30_enable()
#define ao_ir_adcd30_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd30_request()
#define ao_ir_adcd30_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd30_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd30_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd31`

```c
#define ao_ir_adcd31_enable()
#define ao_ir_adcd31_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd31_request()
#define ao_ir_adcd31_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd31_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd31_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd32`

```c
#define ao_ir_adcd32_enable()
#define ao_ir_adcd32_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd32_request()
#define ao_ir_adcd32_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd32_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd32_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd33`

```c
#define ao_ir_adcd33_enable()
#define ao_ir_adcd33_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd33_request()
#define ao_ir_adcd33_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd33_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd33_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd34`

```c
#define ao_ir_adcd34_enable()
#define ao_ir_adcd34_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd34_request()
#define ao_ir_adcd34_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd34_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd34_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd35`

```c
#define ao_ir_adcd35_enable()
#define ao_ir_adcd35_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd35_request()
#define ao_ir_adcd35_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd35_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd35_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd36`

```c
#define ao_ir_adcd36_enable()
#define ao_ir_adcd36_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd36_request()
#define ao_ir_adcd36_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd36_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd36_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd37`

```c
#define ao_ir_adcd37_enable()
#define ao_ir_adcd37_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd37_request()
#define ao_ir_adcd37_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd37_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd37_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd38`

```c
#define ao_ir_adcd38_enable()
#define ao_ir_adcd38_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd38_request()
#define ao_ir_adcd38_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd38_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd38_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd39`

```c
#define ao_ir_adcd39_enable()
#define ao_ir_adcd39_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd39_request()
#define ao_ir_adcd39_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd39_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd39_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd40`

```c
#define ao_ir_adcd40_enable()
#define ao_ir_adcd40_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd40_request()
#define ao_ir_adcd40_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd40_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd40_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd41`

```c
#define ao_ir_adcd41_enable()
#define ao_ir_adcd41_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd41_request()
#define ao_ir_adcd41_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd41_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd41_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd42`

```c
#define ao_ir_adcd42_enable()
#define ao_ir_adcd42_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd42_request()
#define ao_ir_adcd42_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd42_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd42_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcd43`

```c
#define ao_ir_adcd43_enable()
#define ao_ir_adcd43_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcd43_request()
#define ao_ir_adcd43_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcd43_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcd43_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcdc1`

```c
#define ao_ir_adcdc1_enable()
#define ao_ir_adcdc1_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcdc1_request()
#define ao_ir_adcdc1_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcdc1_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcdc1_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcdc2`

```c
#define ao_ir_adcdc2_enable()
#define ao_ir_adcdc2_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcdc2_request()
#define ao_ir_adcdc2_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcdc2_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcdc2_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcdc3`

```c
#define ao_ir_adcdc3_enable()
#define ao_ir_adcdc3_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcdc3_request()
#define ao_ir_adcdc3_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcdc3_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcdc3_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcdc4`

```c
#define ao_ir_adcdc4_enable()
#define ao_ir_adcdc4_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcdc4_request()
#define ao_ir_adcdc4_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcdc4_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcdc4_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcdc5`

```c
#define ao_ir_adcdc5_enable()
#define ao_ir_adcdc5_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcdc5_request()
#define ao_ir_adcdc5_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcdc5_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcdc5_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcdc6`

```c
#define ao_ir_adcdc6_enable()
#define ao_ir_adcdc6_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcdc6_request()
#define ao_ir_adcdc6_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcdc6_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcdc6_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcdf1`

```c
#define ao_ir_adcdf1_enable()
#define ao_ir_adcdf1_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcdf1_request()
#define ao_ir_adcdf1_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcdf1_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcdf1_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcdf2`

```c
#define ao_ir_adcdf2_enable()
#define ao_ir_adcdf2_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcdf2_request()
#define ao_ir_adcdf2_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcdf2_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcdf2_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcdf3`

```c
#define ao_ir_adcdf3_enable()
#define ao_ir_adcdf3_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcdf3_request()
#define ao_ir_adcdf3_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcdf3_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcdf3_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcdf4`

```c
#define ao_ir_adcdf4_enable()
#define ao_ir_adcdf4_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcdf4_request()
#define ao_ir_adcdf4_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcdf4_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcdf4_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcdf5`

```c
#define ao_ir_adcdf5_enable()
#define ao_ir_adcdf5_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcdf5_request()
#define ao_ir_adcdf5_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcdf5_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcdf5_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcdf6`

```c
#define ao_ir_adcdf6_enable()
#define ao_ir_adcdf6_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcdf6_request()
#define ao_ir_adcdf6_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcdf6_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcdf6_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adceos`

```c
#define ao_ir_adceos_enable()
#define ao_ir_adceos_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adceos_request()
#define ao_ir_adceos_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adceos_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adceos_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcfifo`

```c
#define ao_ir_adcfifo_enable()
#define ao_ir_adcfifo_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcfifo_request()
#define ao_ir_adcfifo_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcfifo_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcfifo_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcflt`

```c
#define ao_ir_adcflt_enable()
#define ao_ir_adcflt_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcflt_request()
#define ao_ir_adcflt_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcflt_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcflt_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcgrp`

```c
#define ao_ir_adcgrp_enable()
#define ao_ir_adcgrp_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcgrp_request()
#define ao_ir_adcgrp_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcgrp_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcgrp_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_adcurdy`

```c
#define ao_ir_adcurdy_enable()
#define ao_ir_adcurdy_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_adcurdy_request()
#define ao_ir_adcurdy_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_adcurdy_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_adcurdy_is_pending()
```

Checks whether the interrupt is pending.
