---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mk_gp/ao_ir_t.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mk_gp/ao_ir_t.h/
subtitle: ""
title: "ao_ir_t.h"
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
#define AO_IR_T1_ATTRIBUTE __ISR(_TIMER_1_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_T1_PRIO (4)
```

```c
#define AO_IR_T1_SUBPRIO (0)
```

```c
#define AO_IR_T2_ATTRIBUTE __ISR(_TIMER_2_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_T2_PRIO (4)
```

```c
#define AO_IR_T2_SUBPRIO (0)
```

```c
#define AO_IR_T3_ATTRIBUTE __ISR(_TIMER_3_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_T3_PRIO (4)
```

```c
#define AO_IR_T3_SUBPRIO (0)
```

```c
#define AO_IR_T4_ATTRIBUTE __ISR(_TIMER_4_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_T4_PRIO (4)
```

```c
#define AO_IR_T4_SUBPRIO (0)
```

```c
#define AO_IR_T5_ATTRIBUTE __ISR(_TIMER_5_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_T5_PRIO (4)
```

```c
#define AO_IR_T5_SUBPRIO (0)
```

```c
#define AO_IR_T6_ATTRIBUTE __ISR(_TIMER_6_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_T6_PRIO (4)
```

```c
#define AO_IR_T6_SUBPRIO (0)
```

```c
#define AO_IR_T7_ATTRIBUTE __ISR(_TIMER_7_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_T7_PRIO (4)
```

```c
#define AO_IR_T7_SUBPRIO (0)
```

```c
#define AO_IR_T8_ATTRIBUTE __ISR(_TIMER_8_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_T8_PRIO (4)
```

```c
#define AO_IR_T8_SUBPRIO (0)
```

```c
#define AO_IR_T9_ATTRIBUTE __ISR(_TIMER_9_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_T9_PRIO (4)
```

```c
#define AO_IR_T9_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_t1_disable()
```

```c
#define ao_ir_t1_enable()
```

```c
#define ao_ir_t1_is_enabled()
```

```c
#define ao_ir_t1_is_pending()
```

```c
#define ao_ir_t1_reply()
```

```c
#define ao_ir_t1_request()
```

```c
#define ao_ir_t2_disable()
```

```c
#define ao_ir_t2_enable()
```

```c
#define ao_ir_t2_is_enabled()
```

```c
#define ao_ir_t2_is_pending()
```

```c
#define ao_ir_t2_reply()
```

```c
#define ao_ir_t2_request()
```

```c
#define ao_ir_t3_disable()
```

```c
#define ao_ir_t3_enable()
```

```c
#define ao_ir_t3_is_enabled()
```

```c
#define ao_ir_t3_is_pending()
```

```c
#define ao_ir_t3_reply()
```

```c
#define ao_ir_t3_request()
```

```c
#define ao_ir_t4_disable()
```

```c
#define ao_ir_t4_enable()
```

```c
#define ao_ir_t4_is_enabled()
```

```c
#define ao_ir_t4_is_pending()
```

```c
#define ao_ir_t4_reply()
```

```c
#define ao_ir_t4_request()
```

```c
#define ao_ir_t5_disable()
```

```c
#define ao_ir_t5_enable()
```

```c
#define ao_ir_t5_is_enabled()
```

```c
#define ao_ir_t5_is_pending()
```

```c
#define ao_ir_t5_reply()
```

```c
#define ao_ir_t5_request()
```

```c
#define ao_ir_t6_disable()
```

```c
#define ao_ir_t6_enable()
```

```c
#define ao_ir_t6_is_enabled()
```

```c
#define ao_ir_t6_is_pending()
```

```c
#define ao_ir_t6_reply()
```

```c
#define ao_ir_t6_request()
```

```c
#define ao_ir_t7_disable()
```

```c
#define ao_ir_t7_enable()
```

```c
#define ao_ir_t7_is_enabled()
```

```c
#define ao_ir_t7_is_pending()
```

```c
#define ao_ir_t7_reply()
```

```c
#define ao_ir_t7_request()
```

```c
#define ao_ir_t8_disable()
```

```c
#define ao_ir_t8_enable()
```

```c
#define ao_ir_t8_is_enabled()
```

```c
#define ao_ir_t8_is_pending()
```

```c
#define ao_ir_t8_reply()
```

```c
#define ao_ir_t8_request()
```

```c
#define ao_ir_t9_disable()
```

```c
#define ao_ir_t9_enable()
```

```c
#define ao_ir_t9_is_enabled()
```

```c
#define ao_ir_t9_is_pending()
```

```c
#define ao_ir_t9_reply()
```

```c
#define ao_ir_t9_request()
```

