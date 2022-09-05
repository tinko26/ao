---
api: true
author: "Stefan Wagner"
date: 2022-09-05
description: "The /src/ao_sys_xc32_pic32mk_gpg/ao_ir_adc.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gpg/ao_ir_adc.h/
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

# Configuration

## `AO_IR_AD1`

The interrupt handler attribute.

```c
#define AO_IR_AD1_ATTRIBUTE __ISR(_ADC_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1_PRIO      (4)
#define AO_IR_AD1_SUBPRIO   (0)
```

## `AO_IR_AD1AR`

The interrupt handler attribute.

```c
#define AO_IR_AD1AR_ATTRIBUTE __ISR(_ADC_ARDY_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1AR_PRIO      (4)
#define AO_IR_AD1AR_SUBPRIO   (0)
```

## `AO_IR_AD1D0`

The interrupt handler attribute.

```c
#define AO_IR_AD1D0_ATTRIBUTE __ISR(_ADC_DATA0_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1D0_PRIO      (4)
#define AO_IR_AD1D0_SUBPRIO   (0)
```

## `AO_IR_AD1D1`

The interrupt handler attribute.

```c
#define AO_IR_AD1D1_ATTRIBUTE __ISR(_ADC_DATA1_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1D1_PRIO      (4)
#define AO_IR_AD1D1_SUBPRIO   (0)
```

## `AO_IR_AD1D10`

The interrupt handler attribute.

```c
#define AO_IR_AD1D10_ATTRIBUTE __ISR(_ADC_DATA10_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1D10_PRIO      (4)
#define AO_IR_AD1D10_SUBPRIO   (0)
```

## `AO_IR_AD1D11`

The interrupt handler attribute.

```c
#define AO_IR_AD1D11_ATTRIBUTE __ISR(_ADC_DATA11_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1D11_PRIO      (4)
#define AO_IR_AD1D11_SUBPRIO   (0)
```

## `AO_IR_AD1D12`

The interrupt handler attribute.

```c
#define AO_IR_AD1D12_ATTRIBUTE __ISR(_ADC_DATA12_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1D12_PRIO      (4)
#define AO_IR_AD1D12_SUBPRIO   (0)
```

## `AO_IR_AD1D13`

The interrupt handler attribute.

```c
#define AO_IR_AD1D13_ATTRIBUTE __ISR(_ADC_DATA13_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1D13_PRIO      (4)
#define AO_IR_AD1D13_SUBPRIO   (0)
```

## `AO_IR_AD1D14`

The interrupt handler attribute.

```c
#define AO_IR_AD1D14_ATTRIBUTE __ISR(_ADC_DATA14_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1D14_PRIO      (4)
#define AO_IR_AD1D14_SUBPRIO   (0)
```

## `AO_IR_AD1D15`

The interrupt handler attribute.

```c
#define AO_IR_AD1D15_ATTRIBUTE __ISR(_ADC_DATA15_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1D15_PRIO      (4)
#define AO_IR_AD1D15_SUBPRIO   (0)
```

## `AO_IR_AD1D16`

The interrupt handler attribute.

```c
#define AO_IR_AD1D16_ATTRIBUTE __ISR(_ADC_DATA16_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1D16_PRIO      (4)
#define AO_IR_AD1D16_SUBPRIO   (0)
```

## `AO_IR_AD1D17`

The interrupt handler attribute.

```c
#define AO_IR_AD1D17_ATTRIBUTE __ISR(_ADC_DATA17_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1D17_PRIO      (4)
#define AO_IR_AD1D17_SUBPRIO   (0)
```

## `AO_IR_AD1D18`

The interrupt handler attribute.

```c
#define AO_IR_AD1D18_ATTRIBUTE __ISR(_ADC_DATA18_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1D18_PRIO      (4)
#define AO_IR_AD1D18_SUBPRIO   (0)
```

## `AO_IR_AD1D19`

The interrupt handler attribute.

```c
#define AO_IR_AD1D19_ATTRIBUTE __ISR(_ADC_DATA19_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1D19_PRIO      (4)
#define AO_IR_AD1D19_SUBPRIO   (0)
```

## `AO_IR_AD1D2`

The interrupt handler attribute.

```c
#define AO_IR_AD1D2_ATTRIBUTE __ISR(_ADC_DATA2_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1D2_PRIO      (4)
#define AO_IR_AD1D2_SUBPRIO   (0)
```

## `AO_IR_AD1D24`

The interrupt handler attribute.

```c
#define AO_IR_AD1D24_ATTRIBUTE __ISR(_ADC_DATA24_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1D24_PRIO      (4)
#define AO_IR_AD1D24_SUBPRIO   (0)
```

## `AO_IR_AD1D25`

The interrupt handler attribute.

```c
#define AO_IR_AD1D25_ATTRIBUTE __ISR(_ADC_DATA25_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1D25_PRIO      (4)
#define AO_IR_AD1D25_SUBPRIO   (0)
```

## `AO_IR_AD1D26`

The interrupt handler attribute.

```c
#define AO_IR_AD1D26_ATTRIBUTE __ISR(_ADC_DATA26_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1D26_PRIO      (4)
#define AO_IR_AD1D26_SUBPRIO   (0)
```

## `AO_IR_AD1D27`

The interrupt handler attribute.

```c
#define AO_IR_AD1D27_ATTRIBUTE __ISR(_ADC_DATA27_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1D27_PRIO      (4)
#define AO_IR_AD1D27_SUBPRIO   (0)
```

## `AO_IR_AD1D3`

The interrupt handler attribute.

```c
#define AO_IR_AD1D3_ATTRIBUTE __ISR(_ADC_DATA3_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1D3_PRIO      (4)
#define AO_IR_AD1D3_SUBPRIO   (0)
```

## `AO_IR_AD1D4`

The interrupt handler attribute.

```c
#define AO_IR_AD1D4_ATTRIBUTE __ISR(_ADC_DATA4_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1D4_PRIO      (4)
#define AO_IR_AD1D4_SUBPRIO   (0)
```

## `AO_IR_AD1D40`

The interrupt handler attribute.

```c
#define AO_IR_AD1D40_ATTRIBUTE __ISR(_ADC_DATA40_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1D40_PRIO      (4)
#define AO_IR_AD1D40_SUBPRIO   (0)
```

## `AO_IR_AD1D41`

The interrupt handler attribute.

```c
#define AO_IR_AD1D41_ATTRIBUTE __ISR(_ADC_DATA41_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1D41_PRIO      (4)
#define AO_IR_AD1D41_SUBPRIO   (0)
```

## `AO_IR_AD1D46`

The interrupt handler attribute.

```c
#define AO_IR_AD1D46_ATTRIBUTE __ISR(_ADC_DATA46_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1D46_PRIO      (4)
#define AO_IR_AD1D46_SUBPRIO   (0)
```

## `AO_IR_AD1D47`

The interrupt handler attribute.

```c
#define AO_IR_AD1D47_ATTRIBUTE __ISR(_ADC_DATA47_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1D47_PRIO      (4)
#define AO_IR_AD1D47_SUBPRIO   (0)
```

## `AO_IR_AD1D48`

The interrupt handler attribute.

```c
#define AO_IR_AD1D48_ATTRIBUTE __ISR(_ADC_DATA48_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1D48_PRIO      (4)
#define AO_IR_AD1D48_SUBPRIO   (0)
```

## `AO_IR_AD1D49`

The interrupt handler attribute.

```c
#define AO_IR_AD1D49_ATTRIBUTE __ISR(_ADC_DATA49_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1D49_PRIO      (4)
#define AO_IR_AD1D49_SUBPRIO   (0)
```

## `AO_IR_AD1D5`

The interrupt handler attribute.

```c
#define AO_IR_AD1D5_ATTRIBUTE __ISR(_ADC_DATA5_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1D5_PRIO      (4)
#define AO_IR_AD1D5_SUBPRIO   (0)
```

## `AO_IR_AD1D50`

The interrupt handler attribute.

```c
#define AO_IR_AD1D50_ATTRIBUTE __ISR(_ADC_DATA50_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1D50_PRIO      (4)
#define AO_IR_AD1D50_SUBPRIO   (0)
```

## `AO_IR_AD1D53`

The interrupt handler attribute.

```c
#define AO_IR_AD1D53_ATTRIBUTE __ISR(_ADC_DATA53_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1D53_PRIO      (4)
#define AO_IR_AD1D53_SUBPRIO   (0)
```

## `AO_IR_AD1D6`

The interrupt handler attribute.

```c
#define AO_IR_AD1D6_ATTRIBUTE __ISR(_ADC_DATA6_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1D6_PRIO      (4)
#define AO_IR_AD1D6_SUBPRIO   (0)
```

## `AO_IR_AD1D7`

The interrupt handler attribute.

```c
#define AO_IR_AD1D7_ATTRIBUTE __ISR(_ADC_DATA7_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1D7_PRIO      (4)
#define AO_IR_AD1D7_SUBPRIO   (0)
```

## `AO_IR_AD1D8`

The interrupt handler attribute.

```c
#define AO_IR_AD1D8_ATTRIBUTE __ISR(_ADC_DATA8_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1D8_PRIO      (4)
#define AO_IR_AD1D8_SUBPRIO   (0)
```

## `AO_IR_AD1D9`

The interrupt handler attribute.

```c
#define AO_IR_AD1D9_ATTRIBUTE __ISR(_ADC_DATA9_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1D9_PRIO      (4)
#define AO_IR_AD1D9_SUBPRIO   (0)
```

## `AO_IR_AD1DC1`

The interrupt handler attribute.

```c
#define AO_IR_AD1DC1_ATTRIBUTE __ISR(_ADC_DC1_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1DC1_PRIO      (4)
#define AO_IR_AD1DC1_SUBPRIO   (0)
```

## `AO_IR_AD1DC2`

The interrupt handler attribute.

```c
#define AO_IR_AD1DC2_ATTRIBUTE __ISR(_ADC_DC2_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1DC2_PRIO      (4)
#define AO_IR_AD1DC2_SUBPRIO   (0)
```

## `AO_IR_AD1DC3`

The interrupt handler attribute.

```c
#define AO_IR_AD1DC3_ATTRIBUTE __ISR(_ADC_DC3_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1DC3_PRIO      (4)
#define AO_IR_AD1DC3_SUBPRIO   (0)
```

## `AO_IR_AD1DC4`

The interrupt handler attribute.

```c
#define AO_IR_AD1DC4_ATTRIBUTE __ISR(_ADC_DC4_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1DC4_PRIO      (4)
#define AO_IR_AD1DC4_SUBPRIO   (0)
```

## `AO_IR_AD1DF1`

The interrupt handler attribute.

```c
#define AO_IR_AD1DF1_ATTRIBUTE __ISR(_ADC_DF1_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1DF1_PRIO      (4)
#define AO_IR_AD1DF1_SUBPRIO   (0)
```

## `AO_IR_AD1DF2`

The interrupt handler attribute.

```c
#define AO_IR_AD1DF2_ATTRIBUTE __ISR(_ADC_DF2_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1DF2_PRIO      (4)
#define AO_IR_AD1DF2_SUBPRIO   (0)
```

## `AO_IR_AD1DF3`

The interrupt handler attribute.

```c
#define AO_IR_AD1DF3_ATTRIBUTE __ISR(_ADC_DF3_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1DF3_PRIO      (4)
#define AO_IR_AD1DF3_SUBPRIO   (0)
```

## `AO_IR_AD1DF4`

The interrupt handler attribute.

```c
#define AO_IR_AD1DF4_ATTRIBUTE __ISR(_ADC_DF4_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1DF4_PRIO      (4)
#define AO_IR_AD1DF4_SUBPRIO   (0)
```

## `AO_IR_AD1EOS`

The interrupt handler attribute.

```c
#define AO_IR_AD1EOS_ATTRIBUTE __ISR(_ADC_EOS_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1EOS_PRIO      (4)
#define AO_IR_AD1EOS_SUBPRIO   (0)
```

## `AO_IR_AD1FCBT`

The interrupt handler attribute.

```c
#define AO_IR_AD1FCBT_ATTRIBUTE __ISR(_ADC_DMA_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1FCBT_PRIO      (4)
#define AO_IR_AD1FCBT_SUBPRIO   (0)
```

## `AO_IR_AD1FI`

The interrupt handler attribute.

```c
#define AO_IR_AD1FI_ATTRIBUTE __ISR(_ADC_FAULT_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1FI_PRIO      (4)
#define AO_IR_AD1FI_SUBPRIO   (0)
```

## `AO_IR_AD1G`

The interrupt handler attribute.

```c
#define AO_IR_AD1G_ATTRIBUTE __ISR(_ADC_EARLY_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1G_PRIO      (4)
#define AO_IR_AD1G_SUBPRIO   (0)
```

## `AO_IR_AD1RS`

The interrupt handler attribute.

```c
#define AO_IR_AD1RS_ATTRIBUTE __ISR(_ADC_URDY_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_AD1RS_PRIO      (4)
#define AO_IR_AD1RS_SUBPRIO   (0)
```

# Functions

## `ao_ir_ad1`

Enable or disable the interrupt.

```c
#define ao_ir_ad1_enable()
#define ao_ir_ad1_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1_request()
#define ao_ir_ad1_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1_is_pending()
```

## `ao_ir_ad1ar`

Enable or disable the interrupt.

```c
#define ao_ir_ad1ar_enable()
#define ao_ir_ad1ar_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1ar_request()
#define ao_ir_ad1ar_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1ar_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1ar_is_pending()
```

## `ao_ir_ad1d0`

Enable or disable the interrupt.

```c
#define ao_ir_ad1d0_enable()
#define ao_ir_ad1d0_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1d0_request()
#define ao_ir_ad1d0_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1d0_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1d0_is_pending()
```

## `ao_ir_ad1d1`

Enable or disable the interrupt.

```c
#define ao_ir_ad1d1_enable()
#define ao_ir_ad1d1_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1d1_request()
#define ao_ir_ad1d1_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1d1_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1d1_is_pending()
```

## `ao_ir_ad1d2`

Enable or disable the interrupt.

```c
#define ao_ir_ad1d2_enable()
#define ao_ir_ad1d2_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1d2_request()
#define ao_ir_ad1d2_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1d2_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1d2_is_pending()
```

## `ao_ir_ad1d3`

Enable or disable the interrupt.

```c
#define ao_ir_ad1d3_enable()
#define ao_ir_ad1d3_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1d3_request()
#define ao_ir_ad1d3_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1d3_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1d3_is_pending()
```

## `ao_ir_ad1d4`

Enable or disable the interrupt.

```c
#define ao_ir_ad1d4_enable()
#define ao_ir_ad1d4_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1d4_request()
#define ao_ir_ad1d4_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1d4_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1d4_is_pending()
```

## `ao_ir_ad1d5`

Enable or disable the interrupt.

```c
#define ao_ir_ad1d5_enable()
#define ao_ir_ad1d5_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1d5_request()
#define ao_ir_ad1d5_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1d5_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1d5_is_pending()
```

## `ao_ir_ad1d6`

Enable or disable the interrupt.

```c
#define ao_ir_ad1d6_enable()
#define ao_ir_ad1d6_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1d6_request()
#define ao_ir_ad1d6_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1d6_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1d6_is_pending()
```

## `ao_ir_ad1d7`

Enable or disable the interrupt.

```c
#define ao_ir_ad1d7_enable()
#define ao_ir_ad1d7_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1d7_request()
#define ao_ir_ad1d7_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1d7_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1d7_is_pending()
```

## `ao_ir_ad1d8`

Enable or disable the interrupt.

```c
#define ao_ir_ad1d8_enable()
#define ao_ir_ad1d8_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1d8_request()
#define ao_ir_ad1d8_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1d8_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1d8_is_pending()
```

## `ao_ir_ad1d9`

Enable or disable the interrupt.

```c
#define ao_ir_ad1d9_enable()
#define ao_ir_ad1d9_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1d9_request()
#define ao_ir_ad1d9_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1d9_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1d9_is_pending()
```

## `ao_ir_ad1d10`

Enable or disable the interrupt.

```c
#define ao_ir_ad1d10_enable()
#define ao_ir_ad1d10_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1d10_request()
#define ao_ir_ad1d10_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1d10_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1d10_is_pending()
```

## `ao_ir_ad1d11`

Enable or disable the interrupt.

```c
#define ao_ir_ad1d11_enable()
#define ao_ir_ad1d11_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1d11_request()
#define ao_ir_ad1d11_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1d11_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1d11_is_pending()
```

## `ao_ir_ad1d12`

Enable or disable the interrupt.

```c
#define ao_ir_ad1d12_enable()
#define ao_ir_ad1d12_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1d12_request()
#define ao_ir_ad1d12_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1d12_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1d12_is_pending()
```

## `ao_ir_ad1d13`

Enable or disable the interrupt.

```c
#define ao_ir_ad1d13_enable()
#define ao_ir_ad1d13_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1d13_request()
#define ao_ir_ad1d13_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1d13_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1d13_is_pending()
```

## `ao_ir_ad1d14`

Enable or disable the interrupt.

```c
#define ao_ir_ad1d14_enable()
#define ao_ir_ad1d14_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1d14_request()
#define ao_ir_ad1d14_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1d14_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1d14_is_pending()
```

## `ao_ir_ad1d15`

Enable or disable the interrupt.

```c
#define ao_ir_ad1d15_enable()
#define ao_ir_ad1d15_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1d15_request()
#define ao_ir_ad1d15_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1d15_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1d15_is_pending()
```

## `ao_ir_ad1d16`

Enable or disable the interrupt.

```c
#define ao_ir_ad1d16_enable()
#define ao_ir_ad1d16_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1d16_request()
#define ao_ir_ad1d16_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1d16_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1d16_is_pending()
```

## `ao_ir_ad1d17`

Enable or disable the interrupt.

```c
#define ao_ir_ad1d17_enable()
#define ao_ir_ad1d17_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1d17_request()
#define ao_ir_ad1d17_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1d17_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1d17_is_pending()
```

## `ao_ir_ad1d18`

Enable or disable the interrupt.

```c
#define ao_ir_ad1d18_enable()
#define ao_ir_ad1d18_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1d18_request()
#define ao_ir_ad1d18_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1d18_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1d18_is_pending()
```

## `ao_ir_ad1d19`

Enable or disable the interrupt.

```c
#define ao_ir_ad1d19_enable()
#define ao_ir_ad1d19_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1d19_request()
#define ao_ir_ad1d19_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1d19_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1d19_is_pending()
```

## `ao_ir_ad1d24`

Enable or disable the interrupt.

```c
#define ao_ir_ad1d24_enable()
#define ao_ir_ad1d24_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1d24_request()
#define ao_ir_ad1d24_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1d24_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1d24_is_pending()
```

## `ao_ir_ad1d25`

Enable or disable the interrupt.

```c
#define ao_ir_ad1d25_enable()
#define ao_ir_ad1d25_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1d25_request()
#define ao_ir_ad1d25_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1d25_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1d25_is_pending()
```

## `ao_ir_ad1d26`

Enable or disable the interrupt.

```c
#define ao_ir_ad1d26_enable()
#define ao_ir_ad1d26_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1d26_request()
#define ao_ir_ad1d26_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1d26_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1d26_is_pending()
```

## `ao_ir_ad1d27`

Enable or disable the interrupt.

```c
#define ao_ir_ad1d27_enable()
#define ao_ir_ad1d27_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1d27_request()
#define ao_ir_ad1d27_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1d27_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1d27_is_pending()
```

## `ao_ir_ad1d40`

Enable or disable the interrupt.

```c
#define ao_ir_ad1d40_enable()
#define ao_ir_ad1d40_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1d40_request()
#define ao_ir_ad1d40_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1d40_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1d40_is_pending()
```

## `ao_ir_ad1d41`

Enable or disable the interrupt.

```c
#define ao_ir_ad1d41_enable()
#define ao_ir_ad1d41_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1d41_request()
#define ao_ir_ad1d41_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1d41_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1d41_is_pending()
```

## `ao_ir_ad1d46`

Enable or disable the interrupt.

```c
#define ao_ir_ad1d46_enable()
#define ao_ir_ad1d46_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1d46_request()
#define ao_ir_ad1d46_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1d46_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1d46_is_pending()
```

## `ao_ir_ad1d47`

Enable or disable the interrupt.

```c
#define ao_ir_ad1d47_enable()
#define ao_ir_ad1d47_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1d47_request()
#define ao_ir_ad1d47_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1d47_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1d47_is_pending()
```

## `ao_ir_ad1d48`

Enable or disable the interrupt.

```c
#define ao_ir_ad1d48_enable()
#define ao_ir_ad1d48_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1d48_request()
#define ao_ir_ad1d48_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1d48_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1d48_is_pending()
```

## `ao_ir_ad1d49`

Enable or disable the interrupt.

```c
#define ao_ir_ad1d49_enable()
#define ao_ir_ad1d49_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1d49_request()
#define ao_ir_ad1d49_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1d49_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1d49_is_pending()
```

## `ao_ir_ad1d50`

Enable or disable the interrupt.

```c
#define ao_ir_ad1d50_enable()
#define ao_ir_ad1d50_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1d50_request()
#define ao_ir_ad1d50_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1d50_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1d50_is_pending()
```

## `ao_ir_ad1d53`

Enable or disable the interrupt.

```c
#define ao_ir_ad1d53_enable()
#define ao_ir_ad1d53_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1d53_request()
#define ao_ir_ad1d53_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1d53_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1d53_is_pending()
```

## `ao_ir_ad1dc1`

Enable or disable the interrupt.

```c
#define ao_ir_ad1dc1_enable()
#define ao_ir_ad1dc1_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1dc1_request()
#define ao_ir_ad1dc1_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1dc1_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1dc1_is_pending()
```

## `ao_ir_ad1dc2`

Enable or disable the interrupt.

```c
#define ao_ir_ad1dc2_enable()
#define ao_ir_ad1dc2_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1dc2_request()
#define ao_ir_ad1dc2_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1dc2_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1dc2_is_pending()
```

## `ao_ir_ad1dc3`

Enable or disable the interrupt.

```c
#define ao_ir_ad1dc3_enable()
#define ao_ir_ad1dc3_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1dc3_request()
#define ao_ir_ad1dc3_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1dc3_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1dc3_is_pending()
```

## `ao_ir_ad1dc4`

Enable or disable the interrupt.

```c
#define ao_ir_ad1dc4_enable()
#define ao_ir_ad1dc4_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1dc4_request()
#define ao_ir_ad1dc4_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1dc4_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1dc4_is_pending()
```

## `ao_ir_ad1df1`

Enable or disable the interrupt.

```c
#define ao_ir_ad1df1_enable()
#define ao_ir_ad1df1_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1df1_request()
#define ao_ir_ad1df1_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1df1_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1df1_is_pending()
```

## `ao_ir_ad1df2`

Enable or disable the interrupt.

```c
#define ao_ir_ad1df2_enable()
#define ao_ir_ad1df2_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1df2_request()
#define ao_ir_ad1df2_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1df2_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1df2_is_pending()
```

## `ao_ir_ad1df3`

Enable or disable the interrupt.

```c
#define ao_ir_ad1df3_enable()
#define ao_ir_ad1df3_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1df3_request()
#define ao_ir_ad1df3_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1df3_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1df3_is_pending()
```

## `ao_ir_ad1df4`

Enable or disable the interrupt.

```c
#define ao_ir_ad1df4_enable()
#define ao_ir_ad1df4_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1df4_request()
#define ao_ir_ad1df4_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1df4_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1df4_is_pending()
```

## `ao_ir_ad1eos`

Enable or disable the interrupt.

```c
#define ao_ir_ad1eos_enable()
#define ao_ir_ad1eos_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1eos_request()
#define ao_ir_ad1eos_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1eos_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1eos_is_pending()
```

## `ao_ir_ad1fcbt`

Enable or disable the interrupt.

```c
#define ao_ir_ad1fcbt_enable()
#define ao_ir_ad1fcbt_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1fcbt_request()
#define ao_ir_ad1fcbt_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1fcbt_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1fcbt_is_pending()
```

## `ao_ir_ad1fi`

Enable or disable the interrupt.

```c
#define ao_ir_ad1fi_enable()
#define ao_ir_ad1fi_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1fi_request()
#define ao_ir_ad1fi_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1fi_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1fi_is_pending()
```

## `ao_ir_ad1g`

Enable or disable the interrupt.

```c
#define ao_ir_ad1g_enable()
#define ao_ir_ad1g_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1g_request()
#define ao_ir_ad1g_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1g_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1g_is_pending()
```

## `ao_ir_ad1rs`

Enable or disable the interrupt.

```c
#define ao_ir_ad1rs_enable()
#define ao_ir_ad1rs_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ad1rs_request()
#define ao_ir_ad1rs_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ad1rs_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ad1rs_is_pending()
```
