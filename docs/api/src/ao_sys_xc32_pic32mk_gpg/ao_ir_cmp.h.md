---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mk_gpg/ao_ir_cmp.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gpg/ao_ir_cmp.h/
subtitle: ""
title: "ao_ir_cmp.h"
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
#define AO_IR_CMP1_ATTRIBUTE __ISR(_COMPARATOR_1_VECTOR, IPL4SRS)
```

```c
#define AO_IR_CMP1_PRIO (4)
```

```c
#define AO_IR_CMP1_SUBPRIO (0)
```

```c
#define AO_IR_CMP2_ATTRIBUTE __ISR(_COMPARATOR_2_VECTOR, IPL4SRS)
```

```c
#define AO_IR_CMP2_PRIO (4)
```

```c
#define AO_IR_CMP2_SUBPRIO (0)
```

```c
#define AO_IR_CMP3_ATTRIBUTE __ISR(_COMPARATOR_3_VECTOR, IPL4SRS)
```

```c
#define AO_IR_CMP3_PRIO (4)
```

```c
#define AO_IR_CMP3_SUBPRIO (0)
```

```c
#define AO_IR_CMP4_ATTRIBUTE __ISR(_COMPARATOR_4_VECTOR, IPL4SRS)
```

```c
#define AO_IR_CMP4_PRIO (4)
```

```c
#define AO_IR_CMP4_SUBPRIO (0)
```

```c
#define AO_IR_CMP5_ATTRIBUTE __ISR(_COMPARATOR_5_VECTOR, IPL4SRS)
```

```c
#define AO_IR_CMP5_PRIO (4)
```

```c
#define AO_IR_CMP5_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_cmp1_disable()
```

```c
#define ao_ir_cmp1_enable()
```

```c
#define ao_ir_cmp1_is_enabled()
```

```c
#define ao_ir_cmp1_is_pending()
```

```c
#define ao_ir_cmp1_reply()
```

```c
#define ao_ir_cmp1_request()
```

```c
#define ao_ir_cmp2_disable()
```

```c
#define ao_ir_cmp2_enable()
```

```c
#define ao_ir_cmp2_is_enabled()
```

```c
#define ao_ir_cmp2_is_pending()
```

```c
#define ao_ir_cmp2_reply()
```

```c
#define ao_ir_cmp2_request()
```

```c
#define ao_ir_cmp3_disable()
```

```c
#define ao_ir_cmp3_enable()
```

```c
#define ao_ir_cmp3_is_enabled()
```

```c
#define ao_ir_cmp3_is_pending()
```

```c
#define ao_ir_cmp3_reply()
```

```c
#define ao_ir_cmp3_request()
```

```c
#define ao_ir_cmp4_disable()
```

```c
#define ao_ir_cmp4_enable()
```

```c
#define ao_ir_cmp4_is_enabled()
```

```c
#define ao_ir_cmp4_is_pending()
```

```c
#define ao_ir_cmp4_reply()
```

```c
#define ao_ir_cmp4_request()
```

```c
#define ao_ir_cmp5_disable()
```

```c
#define ao_ir_cmp5_enable()
```

```c
#define ao_ir_cmp5_is_enabled()
```

```c
#define ao_ir_cmp5_is_pending()
```

```c
#define ao_ir_cmp5_reply()
```

```c
#define ao_ir_cmp5_request()
```

