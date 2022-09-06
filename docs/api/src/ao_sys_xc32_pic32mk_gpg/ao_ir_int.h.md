---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gpg/ao_ir_int.h/
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

The interrupt handler attribute.

```c
#define AO_IR_INT0_ATTRIBUTE __ISR(_EXTERNAL_0_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_INT0_PRIO      (4)
#define AO_IR_INT0_SUBPRIO   (0)
```

## `AO_IR_INT1`

The interrupt handler attribute.

```c
#define AO_IR_INT1_ATTRIBUTE __ISR(_EXTERNAL_1_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_INT1_PRIO      (4)
#define AO_IR_INT1_SUBPRIO   (0)
```

## `AO_IR_INT2`

The interrupt handler attribute.

```c
#define AO_IR_INT2_ATTRIBUTE __ISR(_EXTERNAL_2_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_INT2_PRIO      (4)
#define AO_IR_INT2_SUBPRIO   (0)
```

## `AO_IR_INT3`

The interrupt handler attribute.

```c
#define AO_IR_INT3_ATTRIBUTE __ISR(_EXTERNAL_3_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_INT3_PRIO      (4)
#define AO_IR_INT3_SUBPRIO   (0)
```

## `AO_IR_INT4`

The interrupt handler attribute.

```c
#define AO_IR_INT4_ATTRIBUTE __ISR(_EXTERNAL_4_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_INT4_PRIO      (4)
#define AO_IR_INT4_SUBPRIO   (0)
```

# Functions

## `ao_ir_int0`

Enable or disable the interrupt.

```c
#define ao_ir_int0_enable()
#define ao_ir_int0_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_int0_request()
#define ao_ir_int0_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_int0_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_int0_is_pending()
```

## `ao_ir_int1`

Enable or disable the interrupt.

```c
#define ao_ir_int1_enable()
#define ao_ir_int1_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_int1_request()
#define ao_ir_int1_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_int1_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_int1_is_pending()
```

## `ao_ir_int2`

Enable or disable the interrupt.

```c
#define ao_ir_int2_enable()
#define ao_ir_int2_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_int2_request()
#define ao_ir_int2_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_int2_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_int2_is_pending()
```

## `ao_ir_int3`

Enable or disable the interrupt.

```c
#define ao_ir_int3_enable()
#define ao_ir_int3_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_int3_request()
#define ao_ir_int3_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_int3_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_int3_is_pending()
```

## `ao_ir_int4`

Enable or disable the interrupt.

```c
#define ao_ir_int4_enable()
#define ao_ir_int4_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_int4_request()
#define ao_ir_int4_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_int4_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_int4_is_pending()
```
