---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_330/ao_ir_fscm.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_FSCM`

```c
#define AO_IR_FSCM_ATTRIBUTE __ISR(_FAIL_SAFE_MONITOR_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_FSCM_PRIO    (4)
#define AO_IR_FSCM_SUBPRIO (0)
```

The interrupt priority and subpriority.

# Functions

## `ao_ir_fscm`

```c
#define ao_ir_fscm_enable()
#define ao_ir_fscm_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_fscm_request()
#define ao_ir_fscm_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_fscm_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_fscm_is_pending()
```

Checks whether the interrupt is pending.
