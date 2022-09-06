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

The interrupt handler attribute.

```c
#define AO_IR_CMP1_ATTRIBUTE __ISR(_COMPARATOR_1_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_CMP1_PRIO      (4)
#define AO_IR_CMP1_SUBPRIO   (0)
```

## `AO_IR_CMP2`

The interrupt handler attribute.

```c
#define AO_IR_CMP2_ATTRIBUTE __ISR(_COMPARATOR_2_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_CMP2_PRIO      (4)
#define AO_IR_CMP2_SUBPRIO   (0)
```

## `AO_IR_CMP3`

The interrupt handler attribute.

```c
#define AO_IR_CMP3_ATTRIBUTE __ISR(_COMPARATOR_3_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_CMP3_PRIO      (4)
#define AO_IR_CMP3_SUBPRIO   (0)
```

## `AO_IR_CMP4`

The interrupt handler attribute.

```c
#define AO_IR_CMP4_ATTRIBUTE __ISR(_COMPARATOR_4_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_CMP4_PRIO      (4)
#define AO_IR_CMP4_SUBPRIO   (0)
```

## `AO_IR_CMP5`

The interrupt handler attribute.

```c
#define AO_IR_CMP5_ATTRIBUTE __ISR(_COMPARATOR_5_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_CMP5_PRIO      (4)
#define AO_IR_CMP5_SUBPRIO   (0)
```

# Functions

## `ao_ir_cmp1`

Enable or disable the interrupt.

```c
#define ao_ir_cmp1_enable()
#define ao_ir_cmp1_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_cmp1_request()
#define ao_ir_cmp1_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_cmp1_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_cmp1_is_pending()
```

## `ao_ir_cmp2`

Enable or disable the interrupt.

```c
#define ao_ir_cmp2_enable()
#define ao_ir_cmp2_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_cmp2_request()
#define ao_ir_cmp2_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_cmp2_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_cmp2_is_pending()
```

## `ao_ir_cmp3`

Enable or disable the interrupt.

```c
#define ao_ir_cmp3_enable()
#define ao_ir_cmp3_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_cmp3_request()
#define ao_ir_cmp3_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_cmp3_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_cmp3_is_pending()
```

## `ao_ir_cmp4`

Enable or disable the interrupt.

```c
#define ao_ir_cmp4_enable()
#define ao_ir_cmp4_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_cmp4_request()
#define ao_ir_cmp4_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_cmp4_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_cmp4_is_pending()
```

## `ao_ir_cmp5`

Enable or disable the interrupt.

```c
#define ao_ir_cmp5_enable()
#define ao_ir_cmp5_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_cmp5_request()
#define ao_ir_cmp5_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_cmp5_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_cmp5_is_pending()
```
