---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_boot.h/
toc: true
---

# Include

```c
#include <ao_count.h>
#include <ao_ir.h>
```

# Functions

## `ao_boot_count`

Boot the [`ao_count.h`](ao_count.h.md) module.

```c
#define ao_boot_count()
```

## `ao_boot_ir_mvec`

Boot the [`ao_ir_mvec.h`](ao_ir_mvec.h.md) module. This function sets up the multi-vectored interrupt mode.

```c
#define ao_boot_ir_mvec()
```

## `ao_boot_ir_stack`

Boot the [`ao_ir_stack.h`](ao_ir_stack.h.md) module. This function sets up the interrupts stack.

```c
void ao_boot_ir_stack();
```

# Include Next

```c
#include_next <ao_boot.h>
```
