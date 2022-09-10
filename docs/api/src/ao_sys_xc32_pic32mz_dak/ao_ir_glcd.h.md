---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz_dak/ao_ir_glcd.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_GLCD`

```c
#define AO_IR_GLCD_ATTRIBUTE __ISR(_GLCD_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_GLCD_PRIO    (4)
#define AO_IR_GLCD_SUBPRIO (0)
```

The interrupt priority and subpriority.

# Functions

## `ao_ir_glcd`

```c
#define ao_ir_glcd_enable()
#define ao_ir_glcd_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_glcd_request()
#define ao_ir_glcd_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_glcd_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_glcd_is_pending()
```

Checks whether the interrupt is pending.
