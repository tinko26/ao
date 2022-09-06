---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gp/ao_ir_cpc.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_CPC`

The interrupt handler attribute.

```c
#define AO_IR_CPC_ATTRIBUTE __ISR(_CORE_PERF_COUNT_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_CPC_PRIO      (4)
#define AO_IR_CPC_SUBPRIO   (0)
```

# Functions

## `ao_ir_cpc`

Enable or disable the interrupt.

```c
#define ao_ir_cpc_enable()
#define ao_ir_cpc_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_cpc_request()
#define ao_ir_cpc_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_cpc_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_cpc_is_pending()
```
