---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gpg/ao_ir_cmp.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_CMP1`

```c
#define AO_IR_CMP1_ATTRIBUTE __ISR(_COMPARATOR_1_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_CMP1_PRIO    (4)
#define AO_IR_CMP1_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_CMP2`

```c
#define AO_IR_CMP2_ATTRIBUTE __ISR(_COMPARATOR_2_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_CMP2_PRIO    (4)
#define AO_IR_CMP2_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_CMP3`

```c
#define AO_IR_CMP3_ATTRIBUTE __ISR(_COMPARATOR_3_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_CMP3_PRIO    (4)
#define AO_IR_CMP3_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_CMP4`

```c
#define AO_IR_CMP4_ATTRIBUTE __ISR(_COMPARATOR_4_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_CMP4_PRIO    (4)
#define AO_IR_CMP4_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_CMP5`

```c
#define AO_IR_CMP5_ATTRIBUTE __ISR(_COMPARATOR_5_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_CMP5_PRIO    (4)
#define AO_IR_CMP5_SUBPRIO (0)
```

The interrupt priority and subpriority.

# Functions

## `ao_ir_cmp1`

```c
#define ao_ir_cmp1_enable()
#define ao_ir_cmp1_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_cmp1_request()
#define ao_ir_cmp1_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_cmp1_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_cmp1_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_cmp2`

```c
#define ao_ir_cmp2_enable()
#define ao_ir_cmp2_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_cmp2_request()
#define ao_ir_cmp2_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_cmp2_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_cmp2_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_cmp3`

```c
#define ao_ir_cmp3_enable()
#define ao_ir_cmp3_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_cmp3_request()
#define ao_ir_cmp3_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_cmp3_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_cmp3_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_cmp4`

```c
#define ao_ir_cmp4_enable()
#define ao_ir_cmp4_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_cmp4_request()
#define ao_ir_cmp4_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_cmp4_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_cmp4_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_cmp5`

```c
#define ao_ir_cmp5_enable()
#define ao_ir_cmp5_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_cmp5_request()
#define ao_ir_cmp5_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_cmp5_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_cmp5_is_pending()
```

Checks whether the interrupt is pending.
