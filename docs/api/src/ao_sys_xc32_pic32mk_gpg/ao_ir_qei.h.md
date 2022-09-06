---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gpg/ao_ir_qei.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_QEI1`

The interrupt handler attribute.

```c
#define AO_IR_QEI1_ATTRIBUTE __ISR(_QEI1_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_QEI1_PRIO      (4)
#define AO_IR_QEI1_SUBPRIO   (0)
```

## `AO_IR_QEI2`

The interrupt handler attribute.

```c
#define AO_IR_QEI2_ATTRIBUTE __ISR(_QEI2_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_QEI2_PRIO      (4)
#define AO_IR_QEI2_SUBPRIO   (0)
```

## `AO_IR_QEI3`

The interrupt handler attribute.

```c
#define AO_IR_QEI3_ATTRIBUTE __ISR(_QEI3_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_QEI3_PRIO      (4)
#define AO_IR_QEI3_SUBPRIO   (0)
```

# Functions

## `ao_ir_qei1`

Enable or disable the interrupt.

```c
#define ao_ir_qei1_enable()
#define ao_ir_qei1_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_qei1_request()
#define ao_ir_qei1_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_qei1_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_qei1_is_pending()
```

## `ao_ir_qei2`

Enable or disable the interrupt.

```c
#define ao_ir_qei2_enable()
#define ao_ir_qei2_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_qei2_request()
#define ao_ir_qei2_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_qei2_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_qei2_is_pending()
```

## `ao_ir_qei3`

Enable or disable the interrupt.

```c
#define ao_ir_qei3_enable()
#define ao_ir_qei3_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_qei3_request()
#define ao_ir_qei3_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_qei3_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_qei3_is_pending()
```
