---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gpg/ao_ir_clc.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_CLC1`

The interrupt handler attribute.

```c
#define AO_IR_CLC1_ATTRIBUTE __ISR(_CLC1_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_CLC1_PRIO      (4)
#define AO_IR_CLC1_SUBPRIO   (0)
```

## `AO_IR_CLC2`

The interrupt handler attribute.

```c
#define AO_IR_CLC2_ATTRIBUTE __ISR(_CLC2_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_CLC2_PRIO      (4)
#define AO_IR_CLC2_SUBPRIO   (0)
```

## `AO_IR_CLC3`

The interrupt handler attribute.

```c
#define AO_IR_CLC3_ATTRIBUTE __ISR(_CLC3_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_CLC3_PRIO      (4)
#define AO_IR_CLC3_SUBPRIO   (0)
```

## `AO_IR_CLC4`

The interrupt handler attribute.

```c
#define AO_IR_CLC4_ATTRIBUTE __ISR(_CLC4_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_CLC4_PRIO      (4)
#define AO_IR_CLC4_SUBPRIO   (0)
```

# Functions

## `ao_ir_clc1`

Enable or disable the interrupt.

```c
#define ao_ir_clc1_enable()
#define ao_ir_clc1_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_clc1_request()
#define ao_ir_clc1_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_clc1_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_clc1_is_pending()
```

## `ao_ir_clc2`

Enable or disable the interrupt.

```c
#define ao_ir_clc2_enable()
#define ao_ir_clc2_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_clc2_request()
#define ao_ir_clc2_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_clc2_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_clc2_is_pending()
```

## `ao_ir_clc3`

Enable or disable the interrupt.

```c
#define ao_ir_clc3_enable()
#define ao_ir_clc3_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_clc3_request()
#define ao_ir_clc3_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_clc3_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_clc3_is_pending()
```

## `ao_ir_clc4`

Enable or disable the interrupt.

```c
#define ao_ir_clc4_enable()
#define ao_ir_clc4_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_clc4_request()
#define ao_ir_clc4_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_clc4_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_clc4_is_pending()
```
