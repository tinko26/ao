---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz_ec/ao_ir_pre.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_PRE`

```c
#define AO_IR_PRE_ATTRIBUTE __ISR(_PREFETCH_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_PRE_PRIO    (4)
#define AO_IR_PRE_SUBPRIO (0)
```

The interrupt priority and subpriority.

# Functions

## `ao_ir_pre`

```c
#define ao_ir_pre_enable()
#define ao_ir_pre_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_pre_request()
#define ao_ir_pre_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_pre_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_pre_is_pending()
```

Checks whether the interrupt is pending.
