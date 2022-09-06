---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gpk/ao_ir_cfdc.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_CFDC`

The interrupt handler attribute.

```c
#define AO_IR_CFDC_ATTRIBUTE __ISR(_CORE_FAST_DEBUG_CHAN_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_CFDC_PRIO      (4)
#define AO_IR_CFDC_SUBPRIO   (0)
```

# Functions

## `ao_ir_cfdc`

Enable or disable the interrupt.

```c
#define ao_ir_cfdc_enable()
#define ao_ir_cfdc_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_cfdc_request()
#define ao_ir_cfdc_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_cfdc_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_cfdc_is_pending()
```
