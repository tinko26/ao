---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mk_gpg/ao_ir_qei.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gpg/ao_ir_qei.h/
subtitle: "QEI interrupts"
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
#define AO_IR_QEI1_ATTRIBUTE __ISR(_QEI1_VECTOR, IPL4SRS)
```

```c
#define AO_IR_QEI1_PRIO (4)
```

```c
#define AO_IR_QEI1_SUBPRIO (0)
```

```c
#define AO_IR_QEI2_ATTRIBUTE __ISR(_QEI2_VECTOR, IPL4SRS)
```

```c
#define AO_IR_QEI2_PRIO (4)
```

```c
#define AO_IR_QEI2_SUBPRIO (0)
```

```c
#define AO_IR_QEI3_ATTRIBUTE __ISR(_QEI3_VECTOR, IPL4SRS)
```

```c
#define AO_IR_QEI3_PRIO (4)
```

```c
#define AO_IR_QEI3_SUBPRIO (0)
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
