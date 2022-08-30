---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mx_1xx_64_100/ao_ir_oc.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_1xx_64_100/ao_ir_oc.h/
subtitle: ""
title: "ao_ir_oc.h"
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Constants

```c
#define AO_IR_OC1_ATTRIBUTE __ISR(_OUTPUT_COMPARE_1_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_OC1_PRIO (4)
```

```c
#define AO_IR_OC1_SUBPRIO (0)
```

```c
#define AO_IR_OC2_ATTRIBUTE __ISR(_OUTPUT_COMPARE_2_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_OC2_PRIO (4)
```

```c
#define AO_IR_OC2_SUBPRIO (0)
```

```c
#define AO_IR_OC3_ATTRIBUTE __ISR(_OUTPUT_COMPARE_3_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_OC3_PRIO (4)
```

```c
#define AO_IR_OC3_SUBPRIO (0)
```

```c
#define AO_IR_OC4_ATTRIBUTE __ISR(_OUTPUT_COMPARE_4_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_OC4_PRIO (4)
```

```c
#define AO_IR_OC4_SUBPRIO (0)
```

```c
#define AO_IR_OC5_ATTRIBUTE __ISR(_OUTPUT_COMPARE_5_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_OC5_PRIO (4)
```

```c
#define AO_IR_OC5_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_oc1_disable()
```

```c
#define ao_ir_oc1_enable()
```

```c
#define ao_ir_oc1_is_enabled()
```

```c
#define ao_ir_oc1_is_pending()
```

```c
#define ao_ir_oc1_reply()
```

```c
#define ao_ir_oc1_request()
```

```c
#define ao_ir_oc2_disable()
```

```c
#define ao_ir_oc2_enable()
```

```c
#define ao_ir_oc2_is_enabled()
```

```c
#define ao_ir_oc2_is_pending()
```

```c
#define ao_ir_oc2_reply()
```

```c
#define ao_ir_oc2_request()
```

```c
#define ao_ir_oc3_disable()
```

```c
#define ao_ir_oc3_enable()
```

```c
#define ao_ir_oc3_is_enabled()
```

```c
#define ao_ir_oc3_is_pending()
```

```c
#define ao_ir_oc3_reply()
```

```c
#define ao_ir_oc3_request()
```

```c
#define ao_ir_oc4_disable()
```

```c
#define ao_ir_oc4_enable()
```

```c
#define ao_ir_oc4_is_enabled()
```

```c
#define ao_ir_oc4_is_pending()
```

```c
#define ao_ir_oc4_reply()
```

```c
#define ao_ir_oc4_request()
```

```c
#define ao_ir_oc5_disable()
```

```c
#define ao_ir_oc5_enable()
```

```c
#define ao_ir_oc5_is_enabled()
```

```c
#define ao_ir_oc5_is_pending()
```

```c
#define ao_ir_oc5_reply()
```

```c
#define ao_ir_oc5_request()
```
