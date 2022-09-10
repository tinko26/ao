---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_1xx_xlp/ao_ir_pmp.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_PMP`

```c
#define AO_IR_PMP_ATTRIBUTE __ISR(_PMP_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_PMP_PRIO    (4)
#define AO_IR_PMP_SUBPRIO (0)
```

The interrupt priority and subpriority.

# Functions

## `ao_ir_pmp`

```c
#define ao_ir_pmp_enable()
#define ao_ir_pmp_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_pmp_request()
#define ao_ir_pmp_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_pmp_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_pmp_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_pmpe`

```c
#define ao_ir_pmpe_enable()
#define ao_ir_pmpe_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_pmpe_request()
#define ao_ir_pmpe_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_pmpe_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_pmpe_is_pending()
```

Checks whether the interrupt is pending.
