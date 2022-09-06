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

The interrupt handler attribute.

```c
#define AO_IR_GLCD_ATTRIBUTE __ISR(_GLCD_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_GLCD_PRIO      (4)
#define AO_IR_GLCD_SUBPRIO   (0)
```

# Functions

## `ao_ir_glcd`

Enable or disable the interrupt.

```c
#define ao_ir_glcd_enable()
#define ao_ir_glcd_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_glcd_request()
#define ao_ir_glcd_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_glcd_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_glcd_is_pending()
```
