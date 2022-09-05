---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mx_3xx/ao_ir_ic.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_3xx/ao_ir_ic.h/
subtitle: "Input capture interrupts"
title: "ao_ir_ic.h"
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
#define AO_IR_IC1_ATTRIBUTE __ISR(_INPUT_CAPTURE_1_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_IC1_PRIO (4)
```

```c
#define AO_IR_IC1_SUBPRIO (0)
```

```c
#define AO_IR_IC2_ATTRIBUTE __ISR(_INPUT_CAPTURE_2_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_IC2_PRIO (4)
```

```c
#define AO_IR_IC2_SUBPRIO (0)
```

```c
#define AO_IR_IC3_ATTRIBUTE __ISR(_INPUT_CAPTURE_3_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_IC3_PRIO (4)
```

```c
#define AO_IR_IC3_SUBPRIO (0)
```

```c
#define AO_IR_IC4_ATTRIBUTE __ISR(_INPUT_CAPTURE_4_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_IC4_PRIO (4)
```

```c
#define AO_IR_IC4_SUBPRIO (0)
```

```c
#define AO_IR_IC5_ATTRIBUTE __ISR(_INPUT_CAPTURE_5_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_IC5_PRIO (4)
```

```c
#define AO_IR_IC5_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_ic1_disable()
```

```c
#define ao_ir_ic1_enable()
```

```c
#define ao_ir_ic1_is_enabled()
```

```c
#define ao_ir_ic1_is_pending()
```

```c
#define ao_ir_ic1_reply()
```

```c
#define ao_ir_ic1_request()
```

```c
#define ao_ir_ic2_disable()
```

```c
#define ao_ir_ic2_enable()
```

```c
#define ao_ir_ic2_is_enabled()
```

```c
#define ao_ir_ic2_is_pending()
```

```c
#define ao_ir_ic2_reply()
```

```c
#define ao_ir_ic2_request()
```

```c
#define ao_ir_ic3_disable()
```

```c
#define ao_ir_ic3_enable()
```

```c
#define ao_ir_ic3_is_enabled()
```

```c
#define ao_ir_ic3_is_pending()
```

```c
#define ao_ir_ic3_reply()
```

```c
#define ao_ir_ic3_request()
```

```c
#define ao_ir_ic4_disable()
```

```c
#define ao_ir_ic4_enable()
```

```c
#define ao_ir_ic4_is_enabled()
```

```c
#define ao_ir_ic4_is_pending()
```

```c
#define ao_ir_ic4_reply()
```

```c
#define ao_ir_ic4_request()
```

```c
#define ao_ir_ic5_disable()
```

```c
#define ao_ir_ic5_enable()
```

```c
#define ao_ir_ic5_is_enabled()
```

```c
#define ao_ir_ic5_is_pending()
```

```c
#define ao_ir_ic5_reply()
```

```c
#define ao_ir_ic5_request()
```
