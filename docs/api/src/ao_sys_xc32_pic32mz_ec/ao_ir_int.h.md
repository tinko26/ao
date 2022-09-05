---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mz_ec/ao_ir_int.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz_ec/ao_ir_int.h/
subtitle: "External interrupts"
title: "ao_ir_int.h"
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
#define AO_IR_INT0_ATTRIBUTE __ISR(_EXTERNAL_0_VECTOR, IPL4SRS)
```

```c
#define AO_IR_INT0_PRIO (4)
```

```c
#define AO_IR_INT0_SUBPRIO (0)
```

```c
#define AO_IR_INT1_ATTRIBUTE __ISR(_EXTERNAL_1_VECTOR, IPL4SRS)
```

```c
#define AO_IR_INT1_PRIO (4)
```

```c
#define AO_IR_INT1_SUBPRIO (0)
```

```c
#define AO_IR_INT2_ATTRIBUTE __ISR(_EXTERNAL_2_VECTOR, IPL4SRS)
```

```c
#define AO_IR_INT2_PRIO (4)
```

```c
#define AO_IR_INT2_SUBPRIO (0)
```

```c
#define AO_IR_INT3_ATTRIBUTE __ISR(_EXTERNAL_3_VECTOR, IPL4SRS)
```

```c
#define AO_IR_INT3_PRIO (4)
```

```c
#define AO_IR_INT3_SUBPRIO (0)
```

```c
#define AO_IR_INT4_ATTRIBUTE __ISR(_EXTERNAL_4_VECTOR, IPL4SRS)
```

```c
#define AO_IR_INT4_PRIO (4)
```

```c
#define AO_IR_INT4_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_int0_disable()
```

```c
#define ao_ir_int0_enable()
```

```c
#define ao_ir_int0_is_enabled()
```

```c
#define ao_ir_int0_is_pending()
```

```c
#define ao_ir_int0_reply()
```

```c
#define ao_ir_int0_request()
```

```c
#define ao_ir_int0_falling()
```

```c
#define ao_ir_int0_is_falling()
```

```c
#define ao_ir_int0_is_rising()
```

```c
#define ao_ir_int0_rising()
```

```c
#define ao_ir_int1_disable()
```

```c
#define ao_ir_int1_enable()
```

```c
#define ao_ir_int1_is_enabled()
```

```c
#define ao_ir_int1_is_pending()
```

```c
#define ao_ir_int1_reply()
```

```c
#define ao_ir_int1_request()
```

```c
#define ao_ir_int1_falling()
```

```c
#define ao_ir_int1_is_falling()
```

```c
#define ao_ir_int1_is_rising()
```

```c
#define ao_ir_int1_rising()
```

```c
#define ao_ir_int2_disable()
```

```c
#define ao_ir_int2_enable()
```

```c
#define ao_ir_int2_is_enabled()
```

```c
#define ao_ir_int2_is_pending()
```

```c
#define ao_ir_int2_reply()
```

```c
#define ao_ir_int2_request()
```

```c
#define ao_ir_int2_falling()
```

```c
#define ao_ir_int2_is_falling()
```

```c
#define ao_ir_int2_is_rising()
```

```c
#define ao_ir_int2_rising()
```

```c
#define ao_ir_int3_disable()
```

```c
#define ao_ir_int3_enable()
```

```c
#define ao_ir_int3_is_enabled()
```

```c
#define ao_ir_int3_is_pending()
```

```c
#define ao_ir_int3_reply()
```

```c
#define ao_ir_int3_request()
```

```c
#define ao_ir_int3_falling()
```

```c
#define ao_ir_int3_is_falling()
```

```c
#define ao_ir_int3_is_rising()
```

```c
#define ao_ir_int3_rising()
```

```c
#define ao_ir_int4_disable()
```

```c
#define ao_ir_int4_enable()
```

```c
#define ao_ir_int4_is_enabled()
```

```c
#define ao_ir_int4_is_pending()
```

```c
#define ao_ir_int4_reply()
```

```c
#define ao_ir_int4_request()
```

```c
#define ao_ir_int4_falling()
```

```c
#define ao_ir_int4_is_falling()
```

```c
#define ao_ir_int4_is_rising()
```

```c
#define ao_ir_int4_rising()
```
