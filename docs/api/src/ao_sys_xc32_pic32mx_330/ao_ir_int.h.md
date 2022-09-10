---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_330/ao_ir_int.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_INT0`

```c
#define AO_IR_INT0_ATTRIBUTE __ISR(_EXTERNAL_0_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_INT0_PRIO    (4)
#define AO_IR_INT0_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_INT1`

```c
#define AO_IR_INT1_ATTRIBUTE __ISR(_EXTERNAL_1_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_INT1_PRIO    (4)
#define AO_IR_INT1_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_INT2`

```c
#define AO_IR_INT2_ATTRIBUTE __ISR(_EXTERNAL_2_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_INT2_PRIO    (4)
#define AO_IR_INT2_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_INT3`

```c
#define AO_IR_INT3_ATTRIBUTE __ISR(_EXTERNAL_3_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_INT3_PRIO    (4)
#define AO_IR_INT3_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_INT4`

```c
#define AO_IR_INT4_ATTRIBUTE __ISR(_EXTERNAL_4_VECTOR, IPL4SOFT)
```

The interrupt handler attribute.

```c
#define AO_IR_INT4_PRIO    (4)
#define AO_IR_INT4_SUBPRIO (0)
```

The interrupt priority and subpriority.

# Functions

## `ao_ir_int0`

```c
#define ao_ir_int0_enable()
#define ao_ir_int0_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_int0_request()
#define ao_ir_int0_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_int0_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_int0_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_int1`

```c
#define ao_ir_int1_enable()
#define ao_ir_int1_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_int1_request()
#define ao_ir_int1_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_int1_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_int1_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_int2`

```c
#define ao_ir_int2_enable()
#define ao_ir_int2_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_int2_request()
#define ao_ir_int2_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_int2_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_int2_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_int3`

```c
#define ao_ir_int3_enable()
#define ao_ir_int3_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_int3_request()
#define ao_ir_int3_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_int3_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_int3_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_int4`

```c
#define ao_ir_int4_enable()
#define ao_ir_int4_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_int4_request()
#define ao_ir_int4_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_int4_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_int4_is_pending()
```

Checks whether the interrupt is pending.
