---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_1xx_xlp/ao_ir_ct.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_CT`

```c
#define AO_IR_CT_ATTRIBUTE __ISR(_CORE_TIMER_VECTOR, IPL3SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_CT_PRIO    (3)
#define AO_IR_CT_SUBPRIO (0)
```

The interrupt priority and subpriority.

# Functions

## `ao_ir_ct`

```c
#define ao_ir_ct_enable()
#define ao_ir_ct_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_ct_request()
#define ao_ir_ct_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_ct_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_ct_is_pending()
```

Checks whether the interrupt is pending.
