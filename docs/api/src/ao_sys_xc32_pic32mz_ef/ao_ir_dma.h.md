---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz_ef/ao_ir_dma.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_DMA0`

```c
#define AO_IR_DMA0_ATTRIBUTE __ISR(_DMA0_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_DMA0_PRIO    (4)
#define AO_IR_DMA0_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_DMA1`

```c
#define AO_IR_DMA1_ATTRIBUTE __ISR(_DMA1_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_DMA1_PRIO    (4)
#define AO_IR_DMA1_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_DMA2`

```c
#define AO_IR_DMA2_ATTRIBUTE __ISR(_DMA2_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_DMA2_PRIO    (4)
#define AO_IR_DMA2_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_DMA3`

```c
#define AO_IR_DMA3_ATTRIBUTE __ISR(_DMA3_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_DMA3_PRIO    (4)
#define AO_IR_DMA3_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_DMA4`

```c
#define AO_IR_DMA4_ATTRIBUTE __ISR(_DMA4_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_DMA4_PRIO    (4)
#define AO_IR_DMA4_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_DMA5`

```c
#define AO_IR_DMA5_ATTRIBUTE __ISR(_DMA5_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_DMA5_PRIO    (4)
#define AO_IR_DMA5_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_DMA6`

```c
#define AO_IR_DMA6_ATTRIBUTE __ISR(_DMA6_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_DMA6_PRIO    (4)
#define AO_IR_DMA6_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_DMA7`

```c
#define AO_IR_DMA7_ATTRIBUTE __ISR(_DMA7_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_DMA7_PRIO    (4)
#define AO_IR_DMA7_SUBPRIO (0)
```

The interrupt priority and subpriority.

# Functions

## `ao_ir_dma0`

```c
#define ao_ir_dma0_enable()
#define ao_ir_dma0_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_dma0_request()
#define ao_ir_dma0_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_dma0_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_dma0_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_dma1`

```c
#define ao_ir_dma1_enable()
#define ao_ir_dma1_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_dma1_request()
#define ao_ir_dma1_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_dma1_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_dma1_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_dma2`

```c
#define ao_ir_dma2_enable()
#define ao_ir_dma2_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_dma2_request()
#define ao_ir_dma2_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_dma2_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_dma2_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_dma3`

```c
#define ao_ir_dma3_enable()
#define ao_ir_dma3_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_dma3_request()
#define ao_ir_dma3_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_dma3_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_dma3_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_dma4`

```c
#define ao_ir_dma4_enable()
#define ao_ir_dma4_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_dma4_request()
#define ao_ir_dma4_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_dma4_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_dma4_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_dma5`

```c
#define ao_ir_dma5_enable()
#define ao_ir_dma5_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_dma5_request()
#define ao_ir_dma5_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_dma5_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_dma5_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_dma6`

```c
#define ao_ir_dma6_enable()
#define ao_ir_dma6_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_dma6_request()
#define ao_ir_dma6_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_dma6_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_dma6_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_dma7`

```c
#define ao_ir_dma7_enable()
#define ao_ir_dma7_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_dma7_request()
#define ao_ir_dma7_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_dma7_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_dma7_is_pending()
```

Checks whether the interrupt is pending.
