---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz_da/ao_ir_pmp.h/
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

The interrupt handler attribute.

```c
#define AO_IR_PMP_ATTRIBUTE __ISR(_PMP_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_PMP_PRIO      (4)
#define AO_IR_PMP_SUBPRIO   (0)
```

## `AO_IR_PMPE`

The interrupt handler attribute.

```c
#define AO_IR_PMPE_ATTRIBUTE __ISR(_PMP_ERROR_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_PMPE_PRIO      (4)
#define AO_IR_PMPE_SUBPRIO   (0)
```

# Functions

## `ao_ir_pmp`

Enable or disable the interrupt.

```c
#define ao_ir_pmp_enable()
#define ao_ir_pmp_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_pmp_request()
#define ao_ir_pmp_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_pmp_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_pmp_is_pending()
```

## `ao_ir_pmpe`

Enable or disable the interrupt.

```c
#define ao_ir_pmpe_enable()
#define ao_ir_pmpe_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_pmpe_request()
#define ao_ir_pmpe_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_pmpe_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_pmpe_is_pending()
```
