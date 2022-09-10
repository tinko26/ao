---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gp/ao_ir_cfdc.h/
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

```c
#define AO_IR_CFDC_ATTRIBUTE __ISR(_CORE_FAST_DEBUG_CHAN_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_CFDC_PRIO    (4)
#define AO_IR_CFDC_SUBPRIO (0)
```

The interrupt priority and subpriority.

# Functions

## `ao_ir_cfdc`

```c
#define ao_ir_cfdc_enable()
#define ao_ir_cfdc_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_cfdc_request()
#define ao_ir_cfdc_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_cfdc_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_cfdc_is_pending()
```

Checks whether the interrupt is pending.
