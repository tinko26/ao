---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_1xx_64_100/ao_ir_adc.h/
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
#define AO_IR_ADC_ATTRIBUTE __ISR(_ADC_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_ADC_PRIO      (4)
#define AO_IR_ADC_SUBPRIO   (0)
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
