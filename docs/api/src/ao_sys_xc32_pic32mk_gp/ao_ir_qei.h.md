---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mk_gp/ao_ir_qei.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mk_gp/ao_ir_qei.h/
subtitle: ""
title: "ao_ir_qei.h"
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
#define AO_IR_QEI1_ATTRIBUTE __ISR(_QEI1_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_QEI1_PRIO (4)
```

```c
#define AO_IR_QEI1_SUBPRIO (0)
```

```c
#define AO_IR_QEI2_ATTRIBUTE __ISR(_QEI2_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_QEI2_PRIO (4)
```

```c
#define AO_IR_QEI2_SUBPRIO (0)
```

```c
#define AO_IR_QEI3_ATTRIBUTE __ISR(_QEI3_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_QEI3_PRIO (4)
```

```c
#define AO_IR_QEI3_SUBPRIO (0)
```

```c
#define AO_IR_QEI4_ATTRIBUTE __ISR(_QEI4_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_QEI4_PRIO (4)
```

```c
#define AO_IR_QEI4_SUBPRIO (0)
```

```c
#define AO_IR_QEI5_ATTRIBUTE __ISR(_QEI5_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_QEI5_PRIO (4)
```

```c
#define AO_IR_QEI5_SUBPRIO (0)
```

```c
#define AO_IR_QEI6_ATTRIBUTE __ISR(_QEI6_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_QEI6_PRIO (4)
```

```c
#define AO_IR_QEI6_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_qei1_disable()
```

```c
#define ao_ir_qei1_enable()
```

```c
#define ao_ir_qei1_is_enabled()
```

```c
#define ao_ir_qei1_is_pending()
```

```c
#define ao_ir_qei1_reply()
```

```c
#define ao_ir_qei1_request()
```

```c
#define ao_ir_qei2_disable()
```

```c
#define ao_ir_qei2_enable()
```

```c
#define ao_ir_qei2_is_enabled()
```

```c
#define ao_ir_qei2_is_pending()
```

```c
#define ao_ir_qei2_reply()
```

```c
#define ao_ir_qei2_request()
```

```c
#define ao_ir_qei3_disable()
```

```c
#define ao_ir_qei3_enable()
```

```c
#define ao_ir_qei3_is_enabled()
```

```c
#define ao_ir_qei3_is_pending()
```

```c
#define ao_ir_qei3_reply()
```

```c
#define ao_ir_qei3_request()
```

```c
#define ao_ir_qei4_disable()
```

```c
#define ao_ir_qei4_enable()
```

```c
#define ao_ir_qei4_is_enabled()
```

```c
#define ao_ir_qei4_is_pending()
```

```c
#define ao_ir_qei4_reply()
```

```c
#define ao_ir_qei4_request()
```

```c
#define ao_ir_qei5_disable()
```

```c
#define ao_ir_qei5_enable()
```

```c
#define ao_ir_qei5_is_enabled()
```

```c
#define ao_ir_qei5_is_pending()
```

```c
#define ao_ir_qei5_reply()
```

```c
#define ao_ir_qei5_request()
```

```c
#define ao_ir_qei6_disable()
```

```c
#define ao_ir_qei6_enable()
```

```c
#define ao_ir_qei6_is_enabled()
```

```c
#define ao_ir_qei6_is_pending()
```

```c
#define ao_ir_qei6_reply()
```

```c
#define ao_ir_qei6_request()
```

