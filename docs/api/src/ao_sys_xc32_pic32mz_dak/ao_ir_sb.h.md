---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz_dak/ao_ir_sb.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_SB`

```c
#define AO_IR_SB_ATTRIBUTE __ISR(_SYSTEM_BUS_PROTECTION_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_SB_PRIO    (4)
#define AO_IR_SB_SUBPRIO (0)
```

The interrupt priority and subpriority.

# Functions

## `ao_ir_sb`

```c
#define ao_ir_sb_enable()
#define ao_ir_sb_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_sb_request()
#define ao_ir_sb_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_sb_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_sb_is_pending()
```

Checks whether the interrupt is pending.
