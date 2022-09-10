---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_1xx_xlp/ao_ir_fce.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_FCE`

```c
#define AO_IR_FCE_ATTRIBUTE __ISR(_FCE_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_FCE_PRIO    (4)
#define AO_IR_FCE_SUBPRIO (0)
```

The interrupt priority and subpriority.

# Functions

## `ao_ir_fce`

```c
#define ao_ir_fce_enable()
#define ao_ir_fce_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_fce_request()
#define ao_ir_fce_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_fce_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_fce_is_pending()
```

Checks whether the interrupt is pending.
