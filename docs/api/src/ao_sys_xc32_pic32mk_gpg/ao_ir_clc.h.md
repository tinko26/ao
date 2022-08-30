---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mk_gpg/ao_ir_clc.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gpg/ao_ir_clc.h/
subtitle: ""
title: "ao_ir_clc.h"
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
#define AO_IR_CLC1_ATTRIBUTE __ISR(_CLC1_VECTOR, IPL4SRS)
```

```c
#define AO_IR_CLC1_PRIO (4)
```

```c
#define AO_IR_CLC1_SUBPRIO (0)
```

```c
#define AO_IR_CLC2_ATTRIBUTE __ISR(_CLC2_VECTOR, IPL4SRS)
```

```c
#define AO_IR_CLC2_PRIO (4)
```

```c
#define AO_IR_CLC2_SUBPRIO (0)
```

```c
#define AO_IR_CLC3_ATTRIBUTE __ISR(_CLC3_VECTOR, IPL4SRS)
```

```c
#define AO_IR_CLC3_PRIO (4)
```

```c
#define AO_IR_CLC3_SUBPRIO (0)
```

```c
#define AO_IR_CLC4_ATTRIBUTE __ISR(_CLC4_VECTOR, IPL4SRS)
```

```c
#define AO_IR_CLC4_PRIO (4)
```

```c
#define AO_IR_CLC4_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_clc1_disable()
```

```c
#define ao_ir_clc1_enable()
```

```c
#define ao_ir_clc1_is_enabled()
```

```c
#define ao_ir_clc1_is_pending()
```

```c
#define ao_ir_clc1_reply()
```

```c
#define ao_ir_clc1_request()
```

```c
#define ao_ir_clc2_disable()
```

```c
#define ao_ir_clc2_enable()
```

```c
#define ao_ir_clc2_is_enabled()
```

```c
#define ao_ir_clc2_is_pending()
```

```c
#define ao_ir_clc2_reply()
```

```c
#define ao_ir_clc2_request()
```

```c
#define ao_ir_clc3_disable()
```

```c
#define ao_ir_clc3_enable()
```

```c
#define ao_ir_clc3_is_enabled()
```

```c
#define ao_ir_clc3_is_pending()
```

```c
#define ao_ir_clc3_reply()
```

```c
#define ao_ir_clc3_request()
```

```c
#define ao_ir_clc4_disable()
```

```c
#define ao_ir_clc4_enable()
```

```c
#define ao_ir_clc4_is_enabled()
```

```c
#define ao_ir_clc4_is_pending()
```

```c
#define ao_ir_clc4_reply()
```

```c
#define ao_ir_clc4_request()
```

