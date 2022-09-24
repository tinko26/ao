---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_ir_enable.h/
toc: true
---

# Identifier

```c
#define AO_IR_ENABLE
```

# Functions

## `ao_ir_enable`
## `ao_ir_disable`

```c
#define ao_ir_enable()  __builtin_enable_interrupts()
#define ao_ir_disable() __builtin_disable_interrupts()
```

Enables or disables, respectively, interrupts globally.
