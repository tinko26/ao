---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_1xx/ao_ir_ctmu.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_CTMU`

The interrupt handler attribute.

```c
#define AO_IR_CTMU_ATTRIBUTE __ISR(_CTMU_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_CTMU_PRIO      (4)
#define AO_IR_CTMU_SUBPRIO   (0)
```

# Functions

## `ao_ir_ctmu`

Enable or disable the interrupt.

```c
#define ao_ir_ctmu_enable()
#define ao_ir_ctmu_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_ctmu_request()
#define ao_ir_ctmu_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_ctmu_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_ctmu_is_pending()
```
