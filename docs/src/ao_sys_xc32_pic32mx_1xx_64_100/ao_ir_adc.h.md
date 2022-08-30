---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mx_1xx_64_100/ao_ir_adc.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32_pic32mx_1xx_64_100/ao_ir_adc.h/
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
#define AO_IR_ADC_ATTRIBUTE __ISR(_ADC_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_ADC_PRIO (4)
```

```c
#define AO_IR_ADC_SUBPRIO (0)
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

