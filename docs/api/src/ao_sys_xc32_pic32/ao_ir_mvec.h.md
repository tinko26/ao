---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_ir_mvec.h/
toc: true
---

# Include

| `xc.h` |

# Functions

## `ao_ir_mvec_enable`
## `ao_ir_mvec_disable`

```c
#define ao_ir_mvec_enable()  { INTCONSET = _INTCON_MVEC_MASK; }
#define ao_ir_mvec_disable() { INTCONCLR = _INTCON_MVEC_MASK; }
```

Enables or disables, respectively, the multi-vectored interrupt mode.
