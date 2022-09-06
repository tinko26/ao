---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz_ef/ao_ir_adc.h/
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

The interrupt handler attribute.

```c
#define AO_IR_ADC_ATTRIBUTE __ISR(_ADC_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADC_PRIO      (4)
#define AO_IR_ADC_SUBPRIO   (0)
```

## `AO_IR_ADC0E`

The interrupt handler attribute.

```c
#define AO_IR_ADC0E_ATTRIBUTE __ISR(_ADC0_EARLY_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADC0E_PRIO      (4)
#define AO_IR_ADC0E_SUBPRIO   (0)
```

## `AO_IR_ADC0W`

The interrupt handler attribute.

```c
#define AO_IR_ADC0W_ATTRIBUTE __ISR(_ADC0_WARM_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADC0W_PRIO      (4)
#define AO_IR_ADC0W_SUBPRIO   (0)
```

## `AO_IR_ADC1E`

The interrupt handler attribute.

```c
#define AO_IR_ADC1E_ATTRIBUTE __ISR(_ADC1_EARLY_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADC1E_PRIO      (4)
#define AO_IR_ADC1E_SUBPRIO   (0)
```

## `AO_IR_ADC1W`

The interrupt handler attribute.

```c
#define AO_IR_ADC1W_ATTRIBUTE __ISR(_ADC1_WARM_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADC1W_PRIO      (4)
#define AO_IR_ADC1W_SUBPRIO   (0)
```

## `AO_IR_ADC2E`

The interrupt handler attribute.

```c
#define AO_IR_ADC2E_ATTRIBUTE __ISR(_ADC2_EARLY_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADC2E_PRIO      (4)
#define AO_IR_ADC2E_SUBPRIO   (0)
```

## `AO_IR_ADC2W`

The interrupt handler attribute.

```c
#define AO_IR_ADC2W_ATTRIBUTE __ISR(_ADC2_WARM_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADC2W_PRIO      (4)
#define AO_IR_ADC2W_SUBPRIO   (0)
```

## `AO_IR_ADC3E`

The interrupt handler attribute.

```c
#define AO_IR_ADC3E_ATTRIBUTE __ISR(_ADC3_EARLY_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADC3E_PRIO      (4)
#define AO_IR_ADC3E_SUBPRIO   (0)
```

## `AO_IR_ADC3W`

The interrupt handler attribute.

```c
#define AO_IR_ADC3W_ATTRIBUTE __ISR(_ADC3_WARM_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADC3W_PRIO      (4)
#define AO_IR_ADC3W_SUBPRIO   (0)
```

## `AO_IR_ADC4E`

The interrupt handler attribute.

```c
#define AO_IR_ADC4E_ATTRIBUTE __ISR(_ADC4_EARLY_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADC4E_PRIO      (4)
#define AO_IR_ADC4E_SUBPRIO   (0)
```

## `AO_IR_ADC4W`

The interrupt handler attribute.

```c
#define AO_IR_ADC4W_ATTRIBUTE __ISR(_ADC4_WARM_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADC4W_PRIO      (4)
#define AO_IR_ADC4W_SUBPRIO   (0)
```

## `AO_IR_ADC7E`

The interrupt handler attribute.

```c
#define AO_IR_ADC7E_ATTRIBUTE __ISR(_ADC7_EARLY_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADC7E_PRIO      (4)
#define AO_IR_ADC7E_SUBPRIO   (0)
```

## `AO_IR_ADC7W`

The interrupt handler attribute.

```c
#define AO_IR_ADC7W_ATTRIBUTE __ISR(_ADC7_WARM_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADC7W_PRIO      (4)
#define AO_IR_ADC7W_SUBPRIO   (0)
```

## `AO_IR_ADCARDY`

The interrupt handler attribute.

```c
#define AO_IR_ADCARDY_ATTRIBUTE __ISR(_ADC_ARDY_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCARDY_PRIO      (4)
#define AO_IR_ADCARDY_SUBPRIO   (0)
```

## `AO_IR_ADCD0`

The interrupt handler attribute.

```c
#define AO_IR_ADCD0_ATTRIBUTE __ISR(_ADC_DATA0_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD0_PRIO      (4)
#define AO_IR_ADCD0_SUBPRIO   (0)
```

## `AO_IR_ADCD1`

The interrupt handler attribute.

```c
#define AO_IR_ADCD1_ATTRIBUTE __ISR(_ADC_DATA1_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD1_PRIO      (4)
#define AO_IR_ADCD1_SUBPRIO   (0)
```

## `AO_IR_ADCD10`

The interrupt handler attribute.

```c
#define AO_IR_ADCD10_ATTRIBUTE __ISR(_ADC_DATA10_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD10_PRIO      (4)
#define AO_IR_ADCD10_SUBPRIO   (0)
```

## `AO_IR_ADCD11`

The interrupt handler attribute.

```c
#define AO_IR_ADCD11_ATTRIBUTE __ISR(_ADC_DATA11_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD11_PRIO      (4)
#define AO_IR_ADCD11_SUBPRIO   (0)
```

## `AO_IR_ADCD12`

The interrupt handler attribute.

```c
#define AO_IR_ADCD12_ATTRIBUTE __ISR(_ADC_DATA12_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD12_PRIO      (4)
#define AO_IR_ADCD12_SUBPRIO   (0)
```

## `AO_IR_ADCD13`

The interrupt handler attribute.

```c
#define AO_IR_ADCD13_ATTRIBUTE __ISR(_ADC_DATA13_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD13_PRIO      (4)
#define AO_IR_ADCD13_SUBPRIO   (0)
```

## `AO_IR_ADCD14`

The interrupt handler attribute.

```c
#define AO_IR_ADCD14_ATTRIBUTE __ISR(_ADC_DATA14_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD14_PRIO      (4)
#define AO_IR_ADCD14_SUBPRIO   (0)
```

## `AO_IR_ADCD15`

The interrupt handler attribute.

```c
#define AO_IR_ADCD15_ATTRIBUTE __ISR(_ADC_DATA15_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD15_PRIO      (4)
#define AO_IR_ADCD15_SUBPRIO   (0)
```

## `AO_IR_ADCD16`

The interrupt handler attribute.

```c
#define AO_IR_ADCD16_ATTRIBUTE __ISR(_ADC_DATA16_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD16_PRIO      (4)
#define AO_IR_ADCD16_SUBPRIO   (0)
```

## `AO_IR_ADCD17`

The interrupt handler attribute.

```c
#define AO_IR_ADCD17_ATTRIBUTE __ISR(_ADC_DATA17_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD17_PRIO      (4)
#define AO_IR_ADCD17_SUBPRIO   (0)
```

## `AO_IR_ADCD18`

The interrupt handler attribute.

```c
#define AO_IR_ADCD18_ATTRIBUTE __ISR(_ADC_DATA18_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD18_PRIO      (4)
#define AO_IR_ADCD18_SUBPRIO   (0)
```

## `AO_IR_ADCD19`

The interrupt handler attribute.

```c
#define AO_IR_ADCD19_ATTRIBUTE __ISR(_ADC_DATA19_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD19_PRIO      (4)
#define AO_IR_ADCD19_SUBPRIO   (0)
```

## `AO_IR_ADCD2`

The interrupt handler attribute.

```c
#define AO_IR_ADCD2_ATTRIBUTE __ISR(_ADC_DATA2_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD2_PRIO      (4)
#define AO_IR_ADCD2_SUBPRIO   (0)
```

## `AO_IR_ADCD20`

The interrupt handler attribute.

```c
#define AO_IR_ADCD20_ATTRIBUTE __ISR(_ADC_DATA20_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD20_PRIO      (4)
#define AO_IR_ADCD20_SUBPRIO   (0)
```

## `AO_IR_ADCD21`

The interrupt handler attribute.

```c
#define AO_IR_ADCD21_ATTRIBUTE __ISR(_ADC_DATA21_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD21_PRIO      (4)
#define AO_IR_ADCD21_SUBPRIO   (0)
```

## `AO_IR_ADCD22`

The interrupt handler attribute.

```c
#define AO_IR_ADCD22_ATTRIBUTE __ISR(_ADC_DATA22_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD22_PRIO      (4)
#define AO_IR_ADCD22_SUBPRIO   (0)
```

## `AO_IR_ADCD23`

The interrupt handler attribute.

```c
#define AO_IR_ADCD23_ATTRIBUTE __ISR(_ADC_DATA23_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD23_PRIO      (4)
#define AO_IR_ADCD23_SUBPRIO   (0)
```

## `AO_IR_ADCD24`

The interrupt handler attribute.

```c
#define AO_IR_ADCD24_ATTRIBUTE __ISR(_ADC_DATA24_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD24_PRIO      (4)
#define AO_IR_ADCD24_SUBPRIO   (0)
```

## `AO_IR_ADCD25`

The interrupt handler attribute.

```c
#define AO_IR_ADCD25_ATTRIBUTE __ISR(_ADC_DATA25_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD25_PRIO      (4)
#define AO_IR_ADCD25_SUBPRIO   (0)
```

## `AO_IR_ADCD26`

The interrupt handler attribute.

```c
#define AO_IR_ADCD26_ATTRIBUTE __ISR(_ADC_DATA26_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD26_PRIO      (4)
#define AO_IR_ADCD26_SUBPRIO   (0)
```

## `AO_IR_ADCD27`

The interrupt handler attribute.

```c
#define AO_IR_ADCD27_ATTRIBUTE __ISR(_ADC_DATA27_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD27_PRIO      (4)
#define AO_IR_ADCD27_SUBPRIO   (0)
```

## `AO_IR_ADCD28`

The interrupt handler attribute.

```c
#define AO_IR_ADCD28_ATTRIBUTE __ISR(_ADC_DATA28_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD28_PRIO      (4)
#define AO_IR_ADCD28_SUBPRIO   (0)
```

## `AO_IR_ADCD29`

The interrupt handler attribute.

```c
#define AO_IR_ADCD29_ATTRIBUTE __ISR(_ADC_DATA29_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD29_PRIO      (4)
#define AO_IR_ADCD29_SUBPRIO   (0)
```

## `AO_IR_ADCD3`

The interrupt handler attribute.

```c
#define AO_IR_ADCD3_ATTRIBUTE __ISR(_ADC_DATA3_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD3_PRIO      (4)
#define AO_IR_ADCD3_SUBPRIO   (0)
```

## `AO_IR_ADCD30`

The interrupt handler attribute.

```c
#define AO_IR_ADCD30_ATTRIBUTE __ISR(_ADC_DATA30_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD30_PRIO      (4)
#define AO_IR_ADCD30_SUBPRIO   (0)
```

## `AO_IR_ADCD31`

The interrupt handler attribute.

```c
#define AO_IR_ADCD31_ATTRIBUTE __ISR(_ADC_DATA31_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD31_PRIO      (4)
#define AO_IR_ADCD31_SUBPRIO   (0)
```

## `AO_IR_ADCD32`

The interrupt handler attribute.

```c
#define AO_IR_ADCD32_ATTRIBUTE __ISR(_ADC_DATA32_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD32_PRIO      (4)
#define AO_IR_ADCD32_SUBPRIO   (0)
```

## `AO_IR_ADCD33`

The interrupt handler attribute.

```c
#define AO_IR_ADCD33_ATTRIBUTE __ISR(_ADC_DATA33_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD33_PRIO      (4)
#define AO_IR_ADCD33_SUBPRIO   (0)
```

## `AO_IR_ADCD34`

The interrupt handler attribute.

```c
#define AO_IR_ADCD34_ATTRIBUTE __ISR(_ADC_DATA34_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD34_PRIO      (4)
#define AO_IR_ADCD34_SUBPRIO   (0)
```

## `AO_IR_ADCD35`

The interrupt handler attribute.

```c
#define AO_IR_ADCD35_ATTRIBUTE __ISR(_ADC_DATA35_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD35_PRIO      (4)
#define AO_IR_ADCD35_SUBPRIO   (0)
```

## `AO_IR_ADCD36`

The interrupt handler attribute.

```c
#define AO_IR_ADCD36_ATTRIBUTE __ISR(_ADC_DATA36_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD36_PRIO      (4)
#define AO_IR_ADCD36_SUBPRIO   (0)
```

## `AO_IR_ADCD37`

The interrupt handler attribute.

```c
#define AO_IR_ADCD37_ATTRIBUTE __ISR(_ADC_DATA37_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD37_PRIO      (4)
#define AO_IR_ADCD37_SUBPRIO   (0)
```

## `AO_IR_ADCD38`

The interrupt handler attribute.

```c
#define AO_IR_ADCD38_ATTRIBUTE __ISR(_ADC_DATA38_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD38_PRIO      (4)
#define AO_IR_ADCD38_SUBPRIO   (0)
```

## `AO_IR_ADCD39`

The interrupt handler attribute.

```c
#define AO_IR_ADCD39_ATTRIBUTE __ISR(_ADC_DATA39_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD39_PRIO      (4)
#define AO_IR_ADCD39_SUBPRIO   (0)
```

## `AO_IR_ADCD4`

The interrupt handler attribute.

```c
#define AO_IR_ADCD4_ATTRIBUTE __ISR(_ADC_DATA4_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD4_PRIO      (4)
#define AO_IR_ADCD4_SUBPRIO   (0)
```

## `AO_IR_ADCD40`

The interrupt handler attribute.

```c
#define AO_IR_ADCD40_ATTRIBUTE __ISR(_ADC_DATA40_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD40_PRIO      (4)
#define AO_IR_ADCD40_SUBPRIO   (0)
```

## `AO_IR_ADCD41`

The interrupt handler attribute.

```c
#define AO_IR_ADCD41_ATTRIBUTE __ISR(_ADC_DATA41_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD41_PRIO      (4)
#define AO_IR_ADCD41_SUBPRIO   (0)
```

## `AO_IR_ADCD42`

The interrupt handler attribute.

```c
#define AO_IR_ADCD42_ATTRIBUTE __ISR(_ADC_DATA42_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD42_PRIO      (4)
#define AO_IR_ADCD42_SUBPRIO   (0)
```

## `AO_IR_ADCD43`

The interrupt handler attribute.

```c
#define AO_IR_ADCD43_ATTRIBUTE __ISR(_ADC_DATA43_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD43_PRIO      (4)
#define AO_IR_ADCD43_SUBPRIO   (0)
```

## `AO_IR_ADCD44`

The interrupt handler attribute.

```c
#define AO_IR_ADCD44_ATTRIBUTE __ISR(_ADC_DATA44_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD44_PRIO      (4)
#define AO_IR_ADCD44_SUBPRIO   (0)
```

## `AO_IR_ADCD5`

The interrupt handler attribute.

```c
#define AO_IR_ADCD5_ATTRIBUTE __ISR(_ADC_DATA5_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD5_PRIO      (4)
#define AO_IR_ADCD5_SUBPRIO   (0)
```

## `AO_IR_ADCD6`

The interrupt handler attribute.

```c
#define AO_IR_ADCD6_ATTRIBUTE __ISR(_ADC_DATA6_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD6_PRIO      (4)
#define AO_IR_ADCD6_SUBPRIO   (0)
```

## `AO_IR_ADCD7`

The interrupt handler attribute.

```c
#define AO_IR_ADCD7_ATTRIBUTE __ISR(_ADC_DATA7_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD7_PRIO      (4)
#define AO_IR_ADCD7_SUBPRIO   (0)
```

## `AO_IR_ADCD8`

The interrupt handler attribute.

```c
#define AO_IR_ADCD8_ATTRIBUTE __ISR(_ADC_DATA8_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD8_PRIO      (4)
#define AO_IR_ADCD8_SUBPRIO   (0)
```

## `AO_IR_ADCD9`

The interrupt handler attribute.

```c
#define AO_IR_ADCD9_ATTRIBUTE __ISR(_ADC_DATA9_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCD9_PRIO      (4)
#define AO_IR_ADCD9_SUBPRIO   (0)
```

## `AO_IR_ADCDC1`

The interrupt handler attribute.

```c
#define AO_IR_ADCDC1_ATTRIBUTE __ISR(_ADC_DC1_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCDC1_PRIO      (4)
#define AO_IR_ADCDC1_SUBPRIO   (0)
```

## `AO_IR_ADCDC2`

The interrupt handler attribute.

```c
#define AO_IR_ADCDC2_ATTRIBUTE __ISR(_ADC_DC2_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCDC2_PRIO      (4)
#define AO_IR_ADCDC2_SUBPRIO   (0)
```

## `AO_IR_ADCDC3`

The interrupt handler attribute.

```c
#define AO_IR_ADCDC3_ATTRIBUTE __ISR(_ADC_DC3_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCDC3_PRIO      (4)
#define AO_IR_ADCDC3_SUBPRIO   (0)
```

## `AO_IR_ADCDC4`

The interrupt handler attribute.

```c
#define AO_IR_ADCDC4_ATTRIBUTE __ISR(_ADC_DC4_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCDC4_PRIO      (4)
#define AO_IR_ADCDC4_SUBPRIO   (0)
```

## `AO_IR_ADCDC5`

The interrupt handler attribute.

```c
#define AO_IR_ADCDC5_ATTRIBUTE __ISR(_ADC_DC5_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCDC5_PRIO      (4)
#define AO_IR_ADCDC5_SUBPRIO   (0)
```

## `AO_IR_ADCDC6`

The interrupt handler attribute.

```c
#define AO_IR_ADCDC6_ATTRIBUTE __ISR(_ADC_DC6_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCDC6_PRIO      (4)
#define AO_IR_ADCDC6_SUBPRIO   (0)
```

## `AO_IR_ADCDF1`

The interrupt handler attribute.

```c
#define AO_IR_ADCDF1_ATTRIBUTE __ISR(_ADC_DF1_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCDF1_PRIO      (4)
#define AO_IR_ADCDF1_SUBPRIO   (0)
```

## `AO_IR_ADCDF2`

The interrupt handler attribute.

```c
#define AO_IR_ADCDF2_ATTRIBUTE __ISR(_ADC_DF2_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCDF2_PRIO      (4)
#define AO_IR_ADCDF2_SUBPRIO   (0)
```

## `AO_IR_ADCDF3`

The interrupt handler attribute.

```c
#define AO_IR_ADCDF3_ATTRIBUTE __ISR(_ADC_DF3_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCDF3_PRIO      (4)
#define AO_IR_ADCDF3_SUBPRIO   (0)
```

## `AO_IR_ADCDF4`

The interrupt handler attribute.

```c
#define AO_IR_ADCDF4_ATTRIBUTE __ISR(_ADC_DF4_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCDF4_PRIO      (4)
#define AO_IR_ADCDF4_SUBPRIO   (0)
```

## `AO_IR_ADCDF5`

The interrupt handler attribute.

```c
#define AO_IR_ADCDF5_ATTRIBUTE __ISR(_ADC_DF5_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCDF5_PRIO      (4)
#define AO_IR_ADCDF5_SUBPRIO   (0)
```

## `AO_IR_ADCDF6`

The interrupt handler attribute.

```c
#define AO_IR_ADCDF6_ATTRIBUTE __ISR(_ADC_DF6_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCDF6_PRIO      (4)
#define AO_IR_ADCDF6_SUBPRIO   (0)
```

## `AO_IR_ADCEOS`

The interrupt handler attribute.

```c
#define AO_IR_ADCEOS_ATTRIBUTE __ISR(_ADC_EOS_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCEOS_PRIO      (4)
#define AO_IR_ADCEOS_SUBPRIO   (0)
```

## `AO_IR_ADCFIFO`

The interrupt handler attribute.

```c
#define AO_IR_ADCFIFO_ATTRIBUTE __ISR(_ADC_FIFO_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCFIFO_PRIO      (4)
#define AO_IR_ADCFIFO_SUBPRIO   (0)
```

## `AO_IR_ADCFLT`

The interrupt handler attribute.

```c
#define AO_IR_ADCFLT_ATTRIBUTE __ISR(_ADC_FAULT_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCFLT_PRIO      (4)
#define AO_IR_ADCFLT_SUBPRIO   (0)
```

## `AO_IR_ADCGRP`

The interrupt handler attribute.

```c
#define AO_IR_ADCGRP_ATTRIBUTE __ISR(_ADC_EARLY_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCGRP_PRIO      (4)
#define AO_IR_ADCGRP_SUBPRIO   (0)
```

## `AO_IR_ADCURDY`

The interrupt handler attribute.

```c
#define AO_IR_ADCURDY_ATTRIBUTE __ISR(_ADC_URDY_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADCURDY_PRIO      (4)
#define AO_IR_ADCURDY_SUBPRIO   (0)
```

# Functions

## `ao_ir_adc`

Enable or disable the interrupt.

```c
#define ao_ir_adc_enable()
#define ao_ir_adc_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adc_request()
#define ao_ir_adc_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adc_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adc_is_pending()
```

## `ao_ir_adc0e`

Enable or disable the interrupt.

```c
#define ao_ir_adc0e_enable()
#define ao_ir_adc0e_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adc0e_request()
#define ao_ir_adc0e_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adc0e_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adc0e_is_pending()
```

## `ao_ir_adc0w`

Enable or disable the interrupt.

```c
#define ao_ir_adc0w_enable()
#define ao_ir_adc0w_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adc0w_request()
#define ao_ir_adc0w_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adc0w_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adc0w_is_pending()
```

## `ao_ir_adc1e`

Enable or disable the interrupt.

```c
#define ao_ir_adc1e_enable()
#define ao_ir_adc1e_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adc1e_request()
#define ao_ir_adc1e_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adc1e_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adc1e_is_pending()
```

## `ao_ir_adc1w`

Enable or disable the interrupt.

```c
#define ao_ir_adc1w_enable()
#define ao_ir_adc1w_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adc1w_request()
#define ao_ir_adc1w_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adc1w_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adc1w_is_pending()
```

## `ao_ir_adc2e`

Enable or disable the interrupt.

```c
#define ao_ir_adc2e_enable()
#define ao_ir_adc2e_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adc2e_request()
#define ao_ir_adc2e_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adc2e_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adc2e_is_pending()
```

## `ao_ir_adc2w`

Enable or disable the interrupt.

```c
#define ao_ir_adc2w_enable()
#define ao_ir_adc2w_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adc2w_request()
#define ao_ir_adc2w_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adc2w_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adc2w_is_pending()
```

## `ao_ir_adc3e`

Enable or disable the interrupt.

```c
#define ao_ir_adc3e_enable()
#define ao_ir_adc3e_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adc3e_request()
#define ao_ir_adc3e_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adc3e_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adc3e_is_pending()
```

## `ao_ir_adc3w`

Enable or disable the interrupt.

```c
#define ao_ir_adc3w_enable()
#define ao_ir_adc3w_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adc3w_request()
#define ao_ir_adc3w_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adc3w_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adc3w_is_pending()
```

## `ao_ir_adc4e`

Enable or disable the interrupt.

```c
#define ao_ir_adc4e_enable()
#define ao_ir_adc4e_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adc4e_request()
#define ao_ir_adc4e_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adc4e_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adc4e_is_pending()
```

## `ao_ir_adc4w`

Enable or disable the interrupt.

```c
#define ao_ir_adc4w_enable()
#define ao_ir_adc4w_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adc4w_request()
#define ao_ir_adc4w_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adc4w_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adc4w_is_pending()
```

## `ao_ir_adc7e`

Enable or disable the interrupt.

```c
#define ao_ir_adc7e_enable()
#define ao_ir_adc7e_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adc7e_request()
#define ao_ir_adc7e_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adc7e_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adc7e_is_pending()
```

## `ao_ir_adc7w`

Enable or disable the interrupt.

```c
#define ao_ir_adc7w_enable()
#define ao_ir_adc7w_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adc7w_request()
#define ao_ir_adc7w_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adc7w_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adc7w_is_pending()
```

## `ao_ir_adcardy`

Enable or disable the interrupt.

```c
#define ao_ir_adcardy_enable()
#define ao_ir_adcardy_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcardy_request()
#define ao_ir_adcardy_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcardy_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcardy_is_pending()
```

## `ao_ir_adcd0`

Enable or disable the interrupt.

```c
#define ao_ir_adcd0_enable()
#define ao_ir_adcd0_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd0_request()
#define ao_ir_adcd0_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd0_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd0_is_pending()
```

## `ao_ir_adcd1`

Enable or disable the interrupt.

```c
#define ao_ir_adcd1_enable()
#define ao_ir_adcd1_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd1_request()
#define ao_ir_adcd1_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd1_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd1_is_pending()
```

## `ao_ir_adcd2`

Enable or disable the interrupt.

```c
#define ao_ir_adcd2_enable()
#define ao_ir_adcd2_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd2_request()
#define ao_ir_adcd2_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd2_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd2_is_pending()
```

## `ao_ir_adcd3`

Enable or disable the interrupt.

```c
#define ao_ir_adcd3_enable()
#define ao_ir_adcd3_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd3_request()
#define ao_ir_adcd3_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd3_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd3_is_pending()
```

## `ao_ir_adcd4`

Enable or disable the interrupt.

```c
#define ao_ir_adcd4_enable()
#define ao_ir_adcd4_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd4_request()
#define ao_ir_adcd4_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd4_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd4_is_pending()
```

## `ao_ir_adcd5`

Enable or disable the interrupt.

```c
#define ao_ir_adcd5_enable()
#define ao_ir_adcd5_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd5_request()
#define ao_ir_adcd5_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd5_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd5_is_pending()
```

## `ao_ir_adcd6`

Enable or disable the interrupt.

```c
#define ao_ir_adcd6_enable()
#define ao_ir_adcd6_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd6_request()
#define ao_ir_adcd6_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd6_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd6_is_pending()
```

## `ao_ir_adcd7`

Enable or disable the interrupt.

```c
#define ao_ir_adcd7_enable()
#define ao_ir_adcd7_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd7_request()
#define ao_ir_adcd7_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd7_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd7_is_pending()
```

## `ao_ir_adcd8`

Enable or disable the interrupt.

```c
#define ao_ir_adcd8_enable()
#define ao_ir_adcd8_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd8_request()
#define ao_ir_adcd8_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd8_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd8_is_pending()
```

## `ao_ir_adcd9`

Enable or disable the interrupt.

```c
#define ao_ir_adcd9_enable()
#define ao_ir_adcd9_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd9_request()
#define ao_ir_adcd9_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd9_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd9_is_pending()
```

## `ao_ir_adcd10`

Enable or disable the interrupt.

```c
#define ao_ir_adcd10_enable()
#define ao_ir_adcd10_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd10_request()
#define ao_ir_adcd10_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd10_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd10_is_pending()
```

## `ao_ir_adcd11`

Enable or disable the interrupt.

```c
#define ao_ir_adcd11_enable()
#define ao_ir_adcd11_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd11_request()
#define ao_ir_adcd11_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd11_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd11_is_pending()
```

## `ao_ir_adcd12`

Enable or disable the interrupt.

```c
#define ao_ir_adcd12_enable()
#define ao_ir_adcd12_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd12_request()
#define ao_ir_adcd12_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd12_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd12_is_pending()
```

## `ao_ir_adcd13`

Enable or disable the interrupt.

```c
#define ao_ir_adcd13_enable()
#define ao_ir_adcd13_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd13_request()
#define ao_ir_adcd13_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd13_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd13_is_pending()
```

## `ao_ir_adcd14`

Enable or disable the interrupt.

```c
#define ao_ir_adcd14_enable()
#define ao_ir_adcd14_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd14_request()
#define ao_ir_adcd14_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd14_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd14_is_pending()
```

## `ao_ir_adcd15`

Enable or disable the interrupt.

```c
#define ao_ir_adcd15_enable()
#define ao_ir_adcd15_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd15_request()
#define ao_ir_adcd15_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd15_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd15_is_pending()
```

## `ao_ir_adcd16`

Enable or disable the interrupt.

```c
#define ao_ir_adcd16_enable()
#define ao_ir_adcd16_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd16_request()
#define ao_ir_adcd16_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd16_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd16_is_pending()
```

## `ao_ir_adcd17`

Enable or disable the interrupt.

```c
#define ao_ir_adcd17_enable()
#define ao_ir_adcd17_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd17_request()
#define ao_ir_adcd17_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd17_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd17_is_pending()
```

## `ao_ir_adcd18`

Enable or disable the interrupt.

```c
#define ao_ir_adcd18_enable()
#define ao_ir_adcd18_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd18_request()
#define ao_ir_adcd18_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd18_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd18_is_pending()
```

## `ao_ir_adcd19`

Enable or disable the interrupt.

```c
#define ao_ir_adcd19_enable()
#define ao_ir_adcd19_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd19_request()
#define ao_ir_adcd19_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd19_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd19_is_pending()
```

## `ao_ir_adcd20`

Enable or disable the interrupt.

```c
#define ao_ir_adcd20_enable()
#define ao_ir_adcd20_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd20_request()
#define ao_ir_adcd20_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd20_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd20_is_pending()
```

## `ao_ir_adcd21`

Enable or disable the interrupt.

```c
#define ao_ir_adcd21_enable()
#define ao_ir_adcd21_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd21_request()
#define ao_ir_adcd21_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd21_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd21_is_pending()
```

## `ao_ir_adcd22`

Enable or disable the interrupt.

```c
#define ao_ir_adcd22_enable()
#define ao_ir_adcd22_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd22_request()
#define ao_ir_adcd22_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd22_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd22_is_pending()
```

## `ao_ir_adcd23`

Enable or disable the interrupt.

```c
#define ao_ir_adcd23_enable()
#define ao_ir_adcd23_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd23_request()
#define ao_ir_adcd23_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd23_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd23_is_pending()
```

## `ao_ir_adcd24`

Enable or disable the interrupt.

```c
#define ao_ir_adcd24_enable()
#define ao_ir_adcd24_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd24_request()
#define ao_ir_adcd24_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd24_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd24_is_pending()
```

## `ao_ir_adcd25`

Enable or disable the interrupt.

```c
#define ao_ir_adcd25_enable()
#define ao_ir_adcd25_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd25_request()
#define ao_ir_adcd25_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd25_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd25_is_pending()
```

## `ao_ir_adcd26`

Enable or disable the interrupt.

```c
#define ao_ir_adcd26_enable()
#define ao_ir_adcd26_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd26_request()
#define ao_ir_adcd26_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd26_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd26_is_pending()
```

## `ao_ir_adcd27`

Enable or disable the interrupt.

```c
#define ao_ir_adcd27_enable()
#define ao_ir_adcd27_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd27_request()
#define ao_ir_adcd27_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd27_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd27_is_pending()
```

## `ao_ir_adcd28`

Enable or disable the interrupt.

```c
#define ao_ir_adcd28_enable()
#define ao_ir_adcd28_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd28_request()
#define ao_ir_adcd28_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd28_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd28_is_pending()
```

## `ao_ir_adcd29`

Enable or disable the interrupt.

```c
#define ao_ir_adcd29_enable()
#define ao_ir_adcd29_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd29_request()
#define ao_ir_adcd29_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd29_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd29_is_pending()
```

## `ao_ir_adcd30`

Enable or disable the interrupt.

```c
#define ao_ir_adcd30_enable()
#define ao_ir_adcd30_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd30_request()
#define ao_ir_adcd30_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd30_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd30_is_pending()
```

## `ao_ir_adcd31`

Enable or disable the interrupt.

```c
#define ao_ir_adcd31_enable()
#define ao_ir_adcd31_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd31_request()
#define ao_ir_adcd31_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd31_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd31_is_pending()
```

## `ao_ir_adcd32`

Enable or disable the interrupt.

```c
#define ao_ir_adcd32_enable()
#define ao_ir_adcd32_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd32_request()
#define ao_ir_adcd32_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd32_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd32_is_pending()
```

## `ao_ir_adcd33`

Enable or disable the interrupt.

```c
#define ao_ir_adcd33_enable()
#define ao_ir_adcd33_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd33_request()
#define ao_ir_adcd33_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd33_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd33_is_pending()
```

## `ao_ir_adcd34`

Enable or disable the interrupt.

```c
#define ao_ir_adcd34_enable()
#define ao_ir_adcd34_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd34_request()
#define ao_ir_adcd34_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd34_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd34_is_pending()
```

## `ao_ir_adcd35`

Enable or disable the interrupt.

```c
#define ao_ir_adcd35_enable()
#define ao_ir_adcd35_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd35_request()
#define ao_ir_adcd35_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd35_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd35_is_pending()
```

## `ao_ir_adcd36`

Enable or disable the interrupt.

```c
#define ao_ir_adcd36_enable()
#define ao_ir_adcd36_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd36_request()
#define ao_ir_adcd36_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd36_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd36_is_pending()
```

## `ao_ir_adcd37`

Enable or disable the interrupt.

```c
#define ao_ir_adcd37_enable()
#define ao_ir_adcd37_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd37_request()
#define ao_ir_adcd37_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd37_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd37_is_pending()
```

## `ao_ir_adcd38`

Enable or disable the interrupt.

```c
#define ao_ir_adcd38_enable()
#define ao_ir_adcd38_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd38_request()
#define ao_ir_adcd38_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd38_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd38_is_pending()
```

## `ao_ir_adcd39`

Enable or disable the interrupt.

```c
#define ao_ir_adcd39_enable()
#define ao_ir_adcd39_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd39_request()
#define ao_ir_adcd39_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd39_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd39_is_pending()
```

## `ao_ir_adcd40`

Enable or disable the interrupt.

```c
#define ao_ir_adcd40_enable()
#define ao_ir_adcd40_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd40_request()
#define ao_ir_adcd40_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd40_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd40_is_pending()
```

## `ao_ir_adcd41`

Enable or disable the interrupt.

```c
#define ao_ir_adcd41_enable()
#define ao_ir_adcd41_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd41_request()
#define ao_ir_adcd41_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd41_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd41_is_pending()
```

## `ao_ir_adcd42`

Enable or disable the interrupt.

```c
#define ao_ir_adcd42_enable()
#define ao_ir_adcd42_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd42_request()
#define ao_ir_adcd42_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd42_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd42_is_pending()
```

## `ao_ir_adcd43`

Enable or disable the interrupt.

```c
#define ao_ir_adcd43_enable()
#define ao_ir_adcd43_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd43_request()
#define ao_ir_adcd43_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd43_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd43_is_pending()
```

## `ao_ir_adcd44`

Enable or disable the interrupt.

```c
#define ao_ir_adcd44_enable()
#define ao_ir_adcd44_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcd44_request()
#define ao_ir_adcd44_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcd44_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcd44_is_pending()
```

## `ao_ir_adcdc1`

Enable or disable the interrupt.

```c
#define ao_ir_adcdc1_enable()
#define ao_ir_adcdc1_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcdc1_request()
#define ao_ir_adcdc1_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcdc1_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcdc1_is_pending()
```

## `ao_ir_adcdc2`

Enable or disable the interrupt.

```c
#define ao_ir_adcdc2_enable()
#define ao_ir_adcdc2_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcdc2_request()
#define ao_ir_adcdc2_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcdc2_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcdc2_is_pending()
```

## `ao_ir_adcdc3`

Enable or disable the interrupt.

```c
#define ao_ir_adcdc3_enable()
#define ao_ir_adcdc3_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcdc3_request()
#define ao_ir_adcdc3_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcdc3_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcdc3_is_pending()
```

## `ao_ir_adcdc4`

Enable or disable the interrupt.

```c
#define ao_ir_adcdc4_enable()
#define ao_ir_adcdc4_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcdc4_request()
#define ao_ir_adcdc4_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcdc4_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcdc4_is_pending()
```

## `ao_ir_adcdc5`

Enable or disable the interrupt.

```c
#define ao_ir_adcdc5_enable()
#define ao_ir_adcdc5_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcdc5_request()
#define ao_ir_adcdc5_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcdc5_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcdc5_is_pending()
```

## `ao_ir_adcdc6`

Enable or disable the interrupt.

```c
#define ao_ir_adcdc6_enable()
#define ao_ir_adcdc6_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcdc6_request()
#define ao_ir_adcdc6_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcdc6_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcdc6_is_pending()
```

## `ao_ir_adcdf1`

Enable or disable the interrupt.

```c
#define ao_ir_adcdf1_enable()
#define ao_ir_adcdf1_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcdf1_request()
#define ao_ir_adcdf1_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcdf1_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcdf1_is_pending()
```

## `ao_ir_adcdf2`

Enable or disable the interrupt.

```c
#define ao_ir_adcdf2_enable()
#define ao_ir_adcdf2_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcdf2_request()
#define ao_ir_adcdf2_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcdf2_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcdf2_is_pending()
```

## `ao_ir_adcdf3`

Enable or disable the interrupt.

```c
#define ao_ir_adcdf3_enable()
#define ao_ir_adcdf3_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcdf3_request()
#define ao_ir_adcdf3_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcdf3_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcdf3_is_pending()
```

## `ao_ir_adcdf4`

Enable or disable the interrupt.

```c
#define ao_ir_adcdf4_enable()
#define ao_ir_adcdf4_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcdf4_request()
#define ao_ir_adcdf4_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcdf4_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcdf4_is_pending()
```

## `ao_ir_adcdf5`

Enable or disable the interrupt.

```c
#define ao_ir_adcdf5_enable()
#define ao_ir_adcdf5_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcdf5_request()
#define ao_ir_adcdf5_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcdf5_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcdf5_is_pending()
```

## `ao_ir_adcdf6`

Enable or disable the interrupt.

```c
#define ao_ir_adcdf6_enable()
#define ao_ir_adcdf6_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcdf6_request()
#define ao_ir_adcdf6_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcdf6_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcdf6_is_pending()
```

## `ao_ir_adceos`

Enable or disable the interrupt.

```c
#define ao_ir_adceos_enable()
#define ao_ir_adceos_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adceos_request()
#define ao_ir_adceos_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adceos_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adceos_is_pending()
```

## `ao_ir_adcflt`

Enable or disable the interrupt.

```c
#define ao_ir_adcflt_enable()
#define ao_ir_adcflt_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcflt_request()
#define ao_ir_adcflt_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcflt_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcflt_is_pending()
```

## `ao_ir_adcfifo`

Enable or disable the interrupt.

```c
#define ao_ir_adcfifo_enable()
#define ao_ir_adcfifo_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcfifo_request()
#define ao_ir_adcfifo_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcfifo_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcfifo_is_pending()
```

## `ao_ir_adcgrp`

Enable or disable the interrupt.

```c
#define ao_ir_adcgrp_enable()
#define ao_ir_adcgrp_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcgrp_request()
#define ao_ir_adcgrp_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcgrp_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcgrp_is_pending()
```

## `ao_ir_adcurdy`

Enable or disable the interrupt.

```c
#define ao_ir_adcurdy_enable()
#define ao_ir_adcurdy_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_adcurdy_request()
#define ao_ir_adcurdy_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_adcurdy_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_adcurdy_is_pending()
```
