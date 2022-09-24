---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_boot.h/
toc: true
---

# Include

[`ao_count.h`](ao_count.h.md) <br/>
[`ao_ir.h`](ao_ir.h.md)

# Functions

## `ao_boot_count`

```c
#define ao_boot_count()    \
{                          \
    ao_count_debug_stop(); \
}
```

Boots the [`ao_count.h`](ao_count.h.md) module.

## `ao_boot_ir_mvec`

```c
#define ao_boot_ir_mvec() \
{                         \
    ao_ir_mvec_enable();  \
}
```

Boots the [`ao_ir_mvec.h`](ao_ir_mvec.h.md) module. This function sets up the multi-vectored interrupt mode.

## `ao_boot_ir_stack`

```c
void ao_boot_ir_stack();
```

Boots the [`ao_ir_stack.h`](ao_ir_stack.h.md) module. This function sets up the interrupts stack.

# Include Next

[`ao_boot.h`](../ao_sys/ao_boot.h.md)
