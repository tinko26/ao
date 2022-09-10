---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gpk/ao_ir_pcache.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_PCACHE`

```c
#define AO_IR_PCACHE_ATTRIBUTE __ISR(_PCACHE_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_PCACHE_PRIO    (4)
#define AO_IR_PCACHE_SUBPRIO (0)
```

The interrupt priority and subpriority.

# Functions

## `ao_ir_pcache`

```c
#define ao_ir_pcache_enable()
#define ao_ir_pcache_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_pcache_request()
#define ao_ir_pcache_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_pcache_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_pcache_is_pending()
```

Checks whether the interrupt is pending.
