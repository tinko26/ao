---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_1xx/ao_ir_cn.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_CN`

```c
#define AO_IR_CN_ATTRIBUTE __ISR(_CHANGE_NOTICE_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_CN_PRIO    (4)
#define AO_IR_CN_SUBPRIO (0)
```

The interrupt priority and subpriority.

# Functions

## `ao_ir_cna`

```c
#define ao_ir_cna_enable()
#define ao_ir_cna_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_cna_request()
#define ao_ir_cna_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_cna_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_cna_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_cnb`

```c
#define ao_ir_cnb_enable()
#define ao_ir_cnb_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_cnb_request()
#define ao_ir_cnb_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_cnb_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_cnb_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_cnc`

```c
#define ao_ir_cnc_enable()
#define ao_ir_cnc_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_cnc_request()
#define ao_ir_cnc_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_cnc_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_cnc_is_pending()
```

Checks whether the interrupt is pending.
