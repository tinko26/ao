---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gp/ao_ir_adc.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_AD1`

```c
#define AO_IR_AD1_ATTRIBUTE __ISR(_ADC_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1_PRIO    (4)
#define AO_IR_AD1_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1AR`

```c
#define AO_IR_AD1AR_ATTRIBUTE __ISR(_ADC_ARDY_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1AR_PRIO    (4)
#define AO_IR_AD1AR_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D0`

```c
#define AO_IR_AD1D0_ATTRIBUTE __ISR(_ADC_DATA0_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D0_PRIO    (4)
#define AO_IR_AD1D0_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D1`

```c
#define AO_IR_AD1D1_ATTRIBUTE __ISR(_ADC_DATA1_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D1_PRIO    (4)
#define AO_IR_AD1D1_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D10`

```c
#define AO_IR_AD1D10_ATTRIBUTE __ISR(_ADC_DATA10_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D10_PRIO    (4)
#define AO_IR_AD1D10_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D11`

```c
#define AO_IR_AD1D11_ATTRIBUTE __ISR(_ADC_DATA11_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D11_PRIO    (4)
#define AO_IR_AD1D11_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D12`

```c
#define AO_IR_AD1D12_ATTRIBUTE __ISR(_ADC_DATA12_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D12_PRIO    (4)
#define AO_IR_AD1D12_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D13`

```c
#define AO_IR_AD1D13_ATTRIBUTE __ISR(_ADC_DATA13_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D13_PRIO    (4)
#define AO_IR_AD1D13_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D14`

```c
#define AO_IR_AD1D14_ATTRIBUTE __ISR(_ADC_DATA14_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D14_PRIO    (4)
#define AO_IR_AD1D14_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D15`

```c
#define AO_IR_AD1D15_ATTRIBUTE __ISR(_ADC_DATA15_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D15_PRIO    (4)
#define AO_IR_AD1D15_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D16`

```c
#define AO_IR_AD1D16_ATTRIBUTE __ISR(_ADC_DATA16_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D16_PRIO    (4)
#define AO_IR_AD1D16_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D17`

```c
#define AO_IR_AD1D17_ATTRIBUTE __ISR(_ADC_DATA17_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D17_PRIO    (4)
#define AO_IR_AD1D17_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D18`

```c
#define AO_IR_AD1D18_ATTRIBUTE __ISR(_ADC_DATA18_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D18_PRIO    (4)
#define AO_IR_AD1D18_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D19`

```c
#define AO_IR_AD1D19_ATTRIBUTE __ISR(_ADC_DATA19_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D19_PRIO    (4)
#define AO_IR_AD1D19_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D2`

```c
#define AO_IR_AD1D2_ATTRIBUTE __ISR(_ADC_DATA2_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D2_PRIO    (4)
#define AO_IR_AD1D2_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D20`

```c
#define AO_IR_AD1D20_ATTRIBUTE __ISR(_ADC_DATA20_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D20_PRIO    (4)
#define AO_IR_AD1D20_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D21`

```c
#define AO_IR_AD1D21_ATTRIBUTE __ISR(_ADC_DATA21_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D21_PRIO    (4)
#define AO_IR_AD1D21_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D22`

```c
#define AO_IR_AD1D22_ATTRIBUTE __ISR(_ADC_DATA22_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D22_PRIO    (4)
#define AO_IR_AD1D22_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D23`

```c
#define AO_IR_AD1D23_ATTRIBUTE __ISR(_ADC_DATA23_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D23_PRIO    (4)
#define AO_IR_AD1D23_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D24`

```c
#define AO_IR_AD1D24_ATTRIBUTE __ISR(_ADC_DATA24_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D24_PRIO    (4)
#define AO_IR_AD1D24_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D25`

```c
#define AO_IR_AD1D25_ATTRIBUTE __ISR(_ADC_DATA25_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D25_PRIO    (4)
#define AO_IR_AD1D25_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D26`

```c
#define AO_IR_AD1D26_ATTRIBUTE __ISR(_ADC_DATA26_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D26_PRIO    (4)
#define AO_IR_AD1D26_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D27`

```c
#define AO_IR_AD1D27_ATTRIBUTE __ISR(_ADC_DATA27_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D27_PRIO    (4)
#define AO_IR_AD1D27_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D3`

```c
#define AO_IR_AD1D3_ATTRIBUTE __ISR(_ADC_DATA3_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D3_PRIO    (4)
#define AO_IR_AD1D3_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D33`

```c
#define AO_IR_AD1D33_ATTRIBUTE __ISR(_ADC_DATA33_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D33_PRIO    (4)
#define AO_IR_AD1D33_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D34`

```c
#define AO_IR_AD1D34_ATTRIBUTE __ISR(_ADC_DATA34_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D34_PRIO    (4)
#define AO_IR_AD1D34_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D35`

```c
#define AO_IR_AD1D35_ATTRIBUTE __ISR(_ADC_DATA35_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D35_PRIO    (4)
#define AO_IR_AD1D35_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D36`

```c
#define AO_IR_AD1D36_ATTRIBUTE __ISR(_ADC_DATA36_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D36_PRIO    (4)
#define AO_IR_AD1D36_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D37`

```c
#define AO_IR_AD1D37_ATTRIBUTE __ISR(_ADC_DATA37_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D37_PRIO    (4)
#define AO_IR_AD1D37_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D38`

```c
#define AO_IR_AD1D38_ATTRIBUTE __ISR(_ADC_DATA38_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D38_PRIO    (4)
#define AO_IR_AD1D38_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D39`

```c
#define AO_IR_AD1D39_ATTRIBUTE __ISR(_ADC_DATA39_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D39_PRIO    (4)
#define AO_IR_AD1D39_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D4`

```c
#define AO_IR_AD1D4_ATTRIBUTE __ISR(_ADC_DATA4_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D4_PRIO    (4)
#define AO_IR_AD1D4_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D40`

```c
#define AO_IR_AD1D40_ATTRIBUTE __ISR(_ADC_DATA40_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D40_PRIO    (4)
#define AO_IR_AD1D40_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D41`

```c
#define AO_IR_AD1D41_ATTRIBUTE __ISR(_ADC_DATA41_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D41_PRIO    (4)
#define AO_IR_AD1D41_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D45`

```c
#define AO_IR_AD1D45_ATTRIBUTE __ISR(_ADC_DATA45_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D45_PRIO    (4)
#define AO_IR_AD1D45_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D46`

```c
#define AO_IR_AD1D46_ATTRIBUTE __ISR(_ADC_DATA46_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D46_PRIO    (4)
#define AO_IR_AD1D46_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D47`

```c
#define AO_IR_AD1D47_ATTRIBUTE __ISR(_ADC_DATA47_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D47_PRIO    (4)
#define AO_IR_AD1D47_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D48`

```c
#define AO_IR_AD1D48_ATTRIBUTE __ISR(_ADC_DATA48_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D48_PRIO    (4)
#define AO_IR_AD1D48_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D49`

```c
#define AO_IR_AD1D49_ATTRIBUTE __ISR(_ADC_DATA49_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D49_PRIO    (4)
#define AO_IR_AD1D49_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D5`

```c
#define AO_IR_AD1D5_ATTRIBUTE __ISR(_ADC_DATA5_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D5_PRIO    (4)
#define AO_IR_AD1D5_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D50`

```c
#define AO_IR_AD1D50_ATTRIBUTE __ISR(_ADC_DATA50_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D50_PRIO    (4)
#define AO_IR_AD1D50_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D51`

```c
#define AO_IR_AD1D51_ATTRIBUTE __ISR(_ADC_DATA51_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D51_PRIO    (4)
#define AO_IR_AD1D51_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D52`

```c
#define AO_IR_AD1D52_ATTRIBUTE __ISR(_ADC_DATA52_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D52_PRIO    (4)
#define AO_IR_AD1D52_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D53`

```c
#define AO_IR_AD1D53_ATTRIBUTE __ISR(_ADC_DATA53_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D53_PRIO    (4)
#define AO_IR_AD1D53_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D6`

```c
#define AO_IR_AD1D6_ATTRIBUTE __ISR(_ADC_DATA6_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D6_PRIO    (4)
#define AO_IR_AD1D6_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D7`

```c
#define AO_IR_AD1D7_ATTRIBUTE __ISR(_ADC_DATA7_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D7_PRIO    (4)
#define AO_IR_AD1D7_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D8`

```c
#define AO_IR_AD1D8_ATTRIBUTE __ISR(_ADC_DATA8_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D8_PRIO    (4)
#define AO_IR_AD1D8_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1D9`

```c
#define AO_IR_AD1D9_ATTRIBUTE __ISR(_ADC_DATA9_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1D9_PRIO    (4)
#define AO_IR_AD1D9_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1DC1`

```c
#define AO_IR_AD1DC1_ATTRIBUTE __ISR(_ADC_DC1_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1DC1_PRIO    (4)
#define AO_IR_AD1DC1_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1DC2`

```c
#define AO_IR_AD1DC2_ATTRIBUTE __ISR(_ADC_DC2_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1DC2_PRIO    (4)
#define AO_IR_AD1DC2_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1DC3`

```c
#define AO_IR_AD1DC3_ATTRIBUTE __ISR(_ADC_DC3_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1DC3_PRIO    (4)
#define AO_IR_AD1DC3_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1DC4`

```c
#define AO_IR_AD1DC4_ATTRIBUTE __ISR(_ADC_DC4_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1DC4_PRIO    (4)
#define AO_IR_AD1DC4_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1DF1`

```c
#define AO_IR_AD1DF1_ATTRIBUTE __ISR(_ADC_DF1_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1DF1_PRIO    (4)
#define AO_IR_AD1DF1_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1DF2`

```c
#define AO_IR_AD1DF2_ATTRIBUTE __ISR(_ADC_DF2_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1DF2_PRIO    (4)
#define AO_IR_AD1DF2_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1DF3`

```c
#define AO_IR_AD1DF3_ATTRIBUTE __ISR(_ADC_DF3_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1DF3_PRIO    (4)
#define AO_IR_AD1DF3_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1DF4`

```c
#define AO_IR_AD1DF4_ATTRIBUTE __ISR(_ADC_DF4_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1DF4_PRIO    (4)
#define AO_IR_AD1DF4_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1EOS`

```c
#define AO_IR_AD1EOS_ATTRIBUTE __ISR(_ADC_EOS_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1EOS_PRIO    (4)
#define AO_IR_AD1EOS_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1FCBT`

```c
#define AO_IR_AD1FCBT_ATTRIBUTE __ISR(_ADC_DMA_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1FCBT_PRIO    (4)
#define AO_IR_AD1FCBT_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1FI`

```c
#define AO_IR_AD1FI_ATTRIBUTE __ISR(_ADC_FAULT_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1FI_PRIO    (4)
#define AO_IR_AD1FI_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1G`

```c
#define AO_IR_AD1G_ATTRIBUTE __ISR(_ADC_EARLY_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1G_PRIO    (4)
#define AO_IR_AD1G_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_AD1RS`

```c
#define AO_IR_AD1RS_ATTRIBUTE __ISR(_ADC_URDY_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_AD1RS_PRIO    (4)
#define AO_IR_AD1RS_SUBPRIO (0)
```

The interrupt priority and subpriority.

# Functions

## `ao_ir_ad1`

```c
#define ao_ir_ad1_enable()
#define ao_ir_ad1_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1_request()
#define ao_ir_ad1_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1ar`

```c
#define ao_ir_ad1ar_enable()
#define ao_ir_ad1ar_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1ar_request()
#define ao_ir_ad1ar_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1ar_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1ar_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d0`

```c
#define ao_ir_ad1d0_enable()
#define ao_ir_ad1d0_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d0_request()
#define ao_ir_ad1d0_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d0_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d0_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d1`

```c
#define ao_ir_ad1d1_enable()
#define ao_ir_ad1d1_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d1_request()
#define ao_ir_ad1d1_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d1_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d1_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d2`

```c
#define ao_ir_ad1d2_enable()
#define ao_ir_ad1d2_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d2_request()
#define ao_ir_ad1d2_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d2_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d2_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d3`

```c
#define ao_ir_ad1d3_enable()
#define ao_ir_ad1d3_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d3_request()
#define ao_ir_ad1d3_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d3_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d3_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d4`

```c
#define ao_ir_ad1d4_enable()
#define ao_ir_ad1d4_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d4_request()
#define ao_ir_ad1d4_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d4_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d4_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d5`

```c
#define ao_ir_ad1d5_enable()
#define ao_ir_ad1d5_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d5_request()
#define ao_ir_ad1d5_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d5_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d5_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d6`

```c
#define ao_ir_ad1d6_enable()
#define ao_ir_ad1d6_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d6_request()
#define ao_ir_ad1d6_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d6_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d6_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d7`

```c
#define ao_ir_ad1d7_enable()
#define ao_ir_ad1d7_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d7_request()
#define ao_ir_ad1d7_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d7_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d7_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d8`

```c
#define ao_ir_ad1d8_enable()
#define ao_ir_ad1d8_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d8_request()
#define ao_ir_ad1d8_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d8_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d8_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d9`

```c
#define ao_ir_ad1d9_enable()
#define ao_ir_ad1d9_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d9_request()
#define ao_ir_ad1d9_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d9_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d9_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d10`

```c
#define ao_ir_ad1d10_enable()
#define ao_ir_ad1d10_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d10_request()
#define ao_ir_ad1d10_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d10_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d10_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d11`

```c
#define ao_ir_ad1d11_enable()
#define ao_ir_ad1d11_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d11_request()
#define ao_ir_ad1d11_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d11_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d11_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d12`

```c
#define ao_ir_ad1d12_enable()
#define ao_ir_ad1d12_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d12_request()
#define ao_ir_ad1d12_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d12_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d12_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d13`

```c
#define ao_ir_ad1d13_enable()
#define ao_ir_ad1d13_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d13_request()
#define ao_ir_ad1d13_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d13_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d13_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d14`

```c
#define ao_ir_ad1d14_enable()
#define ao_ir_ad1d14_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d14_request()
#define ao_ir_ad1d14_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d14_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d14_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d15`

```c
#define ao_ir_ad1d15_enable()
#define ao_ir_ad1d15_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d15_request()
#define ao_ir_ad1d15_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d15_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d15_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d16`

```c
#define ao_ir_ad1d16_enable()
#define ao_ir_ad1d16_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d16_request()
#define ao_ir_ad1d16_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d16_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d16_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d17`

```c
#define ao_ir_ad1d17_enable()
#define ao_ir_ad1d17_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d17_request()
#define ao_ir_ad1d17_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d17_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d17_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d18`

```c
#define ao_ir_ad1d18_enable()
#define ao_ir_ad1d18_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d18_request()
#define ao_ir_ad1d18_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d18_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d18_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d19`

```c
#define ao_ir_ad1d19_enable()
#define ao_ir_ad1d19_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d19_request()
#define ao_ir_ad1d19_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d19_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d19_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d20`

```c
#define ao_ir_ad1d20_enable()
#define ao_ir_ad1d20_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d20_request()
#define ao_ir_ad1d20_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d20_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d20_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d21`

```c
#define ao_ir_ad1d21_enable()
#define ao_ir_ad1d21_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d21_request()
#define ao_ir_ad1d21_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d21_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d21_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d22`

```c
#define ao_ir_ad1d22_enable()
#define ao_ir_ad1d22_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d22_request()
#define ao_ir_ad1d22_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d22_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d22_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d23`

```c
#define ao_ir_ad1d23_enable()
#define ao_ir_ad1d23_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d23_request()
#define ao_ir_ad1d23_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d23_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d23_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d24`

```c
#define ao_ir_ad1d24_enable()
#define ao_ir_ad1d24_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d24_request()
#define ao_ir_ad1d24_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d24_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d24_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d25`

```c
#define ao_ir_ad1d25_enable()
#define ao_ir_ad1d25_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d25_request()
#define ao_ir_ad1d25_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d25_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d25_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d26`

```c
#define ao_ir_ad1d26_enable()
#define ao_ir_ad1d26_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d26_request()
#define ao_ir_ad1d26_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d26_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d26_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d27`

```c
#define ao_ir_ad1d27_enable()
#define ao_ir_ad1d27_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d27_request()
#define ao_ir_ad1d27_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d27_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d27_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d33`

```c
#define ao_ir_ad1d33_enable()
#define ao_ir_ad1d33_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d33_request()
#define ao_ir_ad1d33_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d33_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d33_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d34`

```c
#define ao_ir_ad1d34_enable()
#define ao_ir_ad1d34_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d34_request()
#define ao_ir_ad1d34_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d34_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d34_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d35`

```c
#define ao_ir_ad1d35_enable()
#define ao_ir_ad1d35_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d35_request()
#define ao_ir_ad1d35_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d35_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d35_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d36`

```c
#define ao_ir_ad1d36_enable()
#define ao_ir_ad1d36_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d36_request()
#define ao_ir_ad1d36_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d36_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d36_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d37`

```c
#define ao_ir_ad1d37_enable()
#define ao_ir_ad1d37_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d37_request()
#define ao_ir_ad1d37_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d37_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d37_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d38`

```c
#define ao_ir_ad1d38_enable()
#define ao_ir_ad1d38_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d38_request()
#define ao_ir_ad1d38_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d38_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d38_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d39`

```c
#define ao_ir_ad1d39_enable()
#define ao_ir_ad1d39_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d39_request()
#define ao_ir_ad1d39_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d39_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d39_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d40`

```c
#define ao_ir_ad1d40_enable()
#define ao_ir_ad1d40_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d40_request()
#define ao_ir_ad1d40_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d40_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d40_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d41`

```c
#define ao_ir_ad1d41_enable()
#define ao_ir_ad1d41_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d41_request()
#define ao_ir_ad1d41_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d41_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d41_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d45`

```c
#define ao_ir_ad1d45_enable()
#define ao_ir_ad1d45_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d45_request()
#define ao_ir_ad1d45_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d45_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d45_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d46`

```c
#define ao_ir_ad1d46_enable()
#define ao_ir_ad1d46_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d46_request()
#define ao_ir_ad1d46_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d46_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d46_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d47`

```c
#define ao_ir_ad1d47_enable()
#define ao_ir_ad1d47_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d47_request()
#define ao_ir_ad1d47_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d47_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d47_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d48`

```c
#define ao_ir_ad1d48_enable()
#define ao_ir_ad1d48_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d48_request()
#define ao_ir_ad1d48_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d48_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d48_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d49`

```c
#define ao_ir_ad1d49_enable()
#define ao_ir_ad1d49_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d49_request()
#define ao_ir_ad1d49_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d49_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d49_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d50`

```c
#define ao_ir_ad1d50_enable()
#define ao_ir_ad1d50_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d50_request()
#define ao_ir_ad1d50_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d50_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d50_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d51`

```c
#define ao_ir_ad1d51_enable()
#define ao_ir_ad1d51_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d51_request()
#define ao_ir_ad1d51_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d51_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d51_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d52`

```c
#define ao_ir_ad1d52_enable()
#define ao_ir_ad1d52_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d52_request()
#define ao_ir_ad1d52_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d52_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d52_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1d53`

```c
#define ao_ir_ad1d53_enable()
#define ao_ir_ad1d53_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1d53_request()
#define ao_ir_ad1d53_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1d53_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1d53_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1dc1`

```c
#define ao_ir_ad1dc1_enable()
#define ao_ir_ad1dc1_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1dc1_request()
#define ao_ir_ad1dc1_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1dc1_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1dc1_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1dc2`

```c
#define ao_ir_ad1dc2_enable()
#define ao_ir_ad1dc2_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1dc2_request()
#define ao_ir_ad1dc2_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1dc2_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1dc2_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1dc3`

```c
#define ao_ir_ad1dc3_enable()
#define ao_ir_ad1dc3_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1dc3_request()
#define ao_ir_ad1dc3_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1dc3_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1dc3_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1dc4`

```c
#define ao_ir_ad1dc4_enable()
#define ao_ir_ad1dc4_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1dc4_request()
#define ao_ir_ad1dc4_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1dc4_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1dc4_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1df1`

```c
#define ao_ir_ad1df1_enable()
#define ao_ir_ad1df1_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1df1_request()
#define ao_ir_ad1df1_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1df1_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1df1_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1df2`

```c
#define ao_ir_ad1df2_enable()
#define ao_ir_ad1df2_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1df2_request()
#define ao_ir_ad1df2_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1df2_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1df2_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1df3`

```c
#define ao_ir_ad1df3_enable()
#define ao_ir_ad1df3_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1df3_request()
#define ao_ir_ad1df3_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1df3_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1df3_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1df4`

```c
#define ao_ir_ad1df4_enable()
#define ao_ir_ad1df4_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1df4_request()
#define ao_ir_ad1df4_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1df4_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1df4_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1eos`

```c
#define ao_ir_ad1eos_enable()
#define ao_ir_ad1eos_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1eos_request()
#define ao_ir_ad1eos_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1eos_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1eos_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1fcbt`

```c
#define ao_ir_ad1fcbt_enable()
#define ao_ir_ad1fcbt_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1fcbt_request()
#define ao_ir_ad1fcbt_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1fcbt_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1fcbt_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1fi`

```c
#define ao_ir_ad1fi_enable()
#define ao_ir_ad1fi_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1fi_request()
#define ao_ir_ad1fi_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1fi_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1fi_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1g`

```c
#define ao_ir_ad1g_enable()
#define ao_ir_ad1g_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1g_request()
#define ao_ir_ad1g_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1g_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1g_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_ad1rs`

```c
#define ao_ir_ad1rs_enable()
#define ao_ir_ad1rs_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ad1rs_request()
#define ao_ir_ad1rs_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ad1rs_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ad1rs_is_pending()
```

Checks whether the interrupt is pending.
