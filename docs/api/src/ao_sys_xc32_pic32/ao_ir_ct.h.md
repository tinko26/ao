---
author: "Stefan Wagner"
date: 2022-09-25
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_ir_ct.h/
toc: true
---

# Include

| `stdbool.h` |

# Functions

## `ao_ir_ct_*`

```c
void ao_ir_ct_enable();
void ao_ir_ct_disable();
```

Enables or disables the interrupt.

```c
void ao_ir_ct_request();
void ao_ir_ct_reply();
```

Requests the interrupt or replies thereto.

```c
bool ao_ir_ct_is_enabled();
```

Checks whether the interrupt is enabled.

```c
bool ao_ir_ct_is_pending();
```

Checks whether the interrupt is pending.
