---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mx_5xx/ao_ir_dma.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_5xx/ao_ir_dma.h/
subtitle: "DMA interrupts"
title: "ao_ir_dma.h"
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
#define AO_IR_DMA0_ATTRIBUTE __ISR(_DMA_0_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_DMA0_PRIO (4)
```

```c
#define AO_IR_DMA0_SUBPRIO (0)
```

```c
#define AO_IR_DMA1_ATTRIBUTE __ISR(_DMA_1_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_DMA1_PRIO (4)
```

```c
#define AO_IR_DMA1_SUBPRIO (0)
```

```c
#define AO_IR_DMA2_ATTRIBUTE __ISR(_DMA_2_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_DMA2_PRIO (4)
```

```c
#define AO_IR_DMA2_SUBPRIO (0)
```

```c
#define AO_IR_DMA3_ATTRIBUTE __ISR(_DMA_3_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_DMA3_PRIO (4)
```

```c
#define AO_IR_DMA3_SUBPRIO (0)
```

```c
#define AO_IR_DMA4_ATTRIBUTE __ISR(_DMA_4_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_DMA4_PRIO (4)
```

```c
#define AO_IR_DMA4_SUBPRIO (0)
```

```c
#define AO_IR_DMA5_ATTRIBUTE __ISR(_DMA_5_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_DMA5_PRIO (4)
```

```c
#define AO_IR_DMA5_SUBPRIO (0)
```

```c
#define AO_IR_DMA6_ATTRIBUTE __ISR(_DMA_6_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_DMA6_PRIO (4)
```

```c
#define AO_IR_DMA6_SUBPRIO (0)
```

```c
#define AO_IR_DMA7_ATTRIBUTE __ISR(_DMA_7_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_DMA7_PRIO (4)
```

```c
#define AO_IR_DMA7_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_dma0_disable()
```

```c
#define ao_ir_dma0_enable()
```

```c
#define ao_ir_dma0_is_enabled()
```

```c
#define ao_ir_dma0_is_pending()
```

```c
#define ao_ir_dma0_reply()
```

```c
#define ao_ir_dma0_request()
```

```c
#define ao_ir_dma1_disable()
```

```c
#define ao_ir_dma1_enable()
```

```c
#define ao_ir_dma1_is_enabled()
```

```c
#define ao_ir_dma1_is_pending()
```

```c
#define ao_ir_dma1_reply()
```

```c
#define ao_ir_dma1_request()
```

```c
#define ao_ir_dma2_disable()
```

```c
#define ao_ir_dma2_enable()
```

```c
#define ao_ir_dma2_is_enabled()
```

```c
#define ao_ir_dma2_is_pending()
```

```c
#define ao_ir_dma2_reply()
```

```c
#define ao_ir_dma2_request()
```

```c
#define ao_ir_dma3_disable()
```

```c
#define ao_ir_dma3_enable()
```

```c
#define ao_ir_dma3_is_enabled()
```

```c
#define ao_ir_dma3_is_pending()
```

```c
#define ao_ir_dma3_reply()
```

```c
#define ao_ir_dma3_request()
```

```c
#define ao_ir_dma4_disable()
```

```c
#define ao_ir_dma4_enable()
```

```c
#define ao_ir_dma4_is_enabled()
```

```c
#define ao_ir_dma4_is_pending()
```

```c
#define ao_ir_dma4_reply()
```

```c
#define ao_ir_dma4_request()
```

```c
#define ao_ir_dma5_disable()
```

```c
#define ao_ir_dma5_enable()
```

```c
#define ao_ir_dma5_is_enabled()
```

```c
#define ao_ir_dma5_is_pending()
```

```c
#define ao_ir_dma5_reply()
```

```c
#define ao_ir_dma5_request()
```

```c
#define ao_ir_dma6_disable()
```

```c
#define ao_ir_dma6_enable()
```

```c
#define ao_ir_dma6_is_enabled()
```

```c
#define ao_ir_dma6_is_pending()
```

```c
#define ao_ir_dma6_reply()
```

```c
#define ao_ir_dma6_request()
```

```c
#define ao_ir_dma7_disable()
```

```c
#define ao_ir_dma7_enable()
```

```c
#define ao_ir_dma7_is_enabled()
```

```c
#define ao_ir_dma7_is_pending()
```

```c
#define ao_ir_dma7_reply()
```

```c
#define ao_ir_dma7_request()
```
