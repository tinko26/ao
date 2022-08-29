---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mk_gp/ao_ir_pmp.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mk_gp/ao_ir_pmp.h/ 
subtitle: ""
title: "ao_ir_pmp.h"
toc: true
---

# Includes

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

```c
#define AO_IR_PMP_ATTRIBUTE         __ISR(_PMP_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_PMP_PRIO              (4)
```

```c
#define AO_IR_PMP_SUBPRIO           (0)
```

```c
#define ao_ir_pmp_disable()
```

```c
#define ao_ir_pmp_enable()
```

```c
#define ao_ir_pmp_is_enabled()
```

```c
#define ao_ir_pmp_is_pending()
```

```c
#define ao_ir_pmp_reply()
```

```c
#define ao_ir_pmp_request()
```

```c
#define AO_IR_PMPE_ATTRIBUTE        __ISR(_PMP_ERROR_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_PMPE_PRIO             (4)
```

```c
#define AO_IR_PMPE_SUBPRIO          (0)
```

```c
#define ao_ir_pmpe_disable()
```

```c
#define ao_ir_pmpe_enable()
```

```c
#define ao_ir_pmpe_is_enabled()
```

```c
#define ao_ir_pmpe_is_pending()
```

```c
#define ao_ir_pmpe_reply()
```

```c
#define ao_ir_pmpe_request()
```

