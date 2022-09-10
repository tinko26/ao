---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_1xx_xlp/ao_ir_cs.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_CS0`

```c
#define AO_IR_CS0_ATTRIBUTE __ISR(_CORE_SOFTWARE_0_VECTOR, IPL2SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_CS0_PRIO    (2)
#define AO_IR_CS0_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_CS1`

```c
#define AO_IR_CS1_ATTRIBUTE __attribute__ ((naked, vector(_CORE_SOFTWARE_1_VECTOR)))
```

The interrupt handler attribute.

```c
#define AO_IR_CS1_PRIO    (1)
#define AO_IR_CS1_SUBPRIO (0)
```

The interrupt priority and subpriority.

# Functions

## `ao_ir_cs0`

```c
#define ao_ir_cs0_enable()
#define ao_ir_cs0_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_cs0_request()
#define ao_ir_cs0_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_cs0_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_cs0_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_cs1`

```c
#define ao_ir_cs1_enable()
#define ao_ir_cs1_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_cs1_request()
#define ao_ir_cs1_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_cs1_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_cs1_is_pending()
```

Checks whether the interrupt is pending.
