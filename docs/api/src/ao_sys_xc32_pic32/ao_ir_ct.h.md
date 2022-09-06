---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_ir_ct.h/
toc: true
---

# Include

```c
#include <stdbool.h>
```

# Functions

## `ao_ir_ct`

Enable or disable the interrupt.

```c
void ao_ir_ct_enable();
void ao_ir_ct_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_ct_request();
void ao_ir_ct_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_ct_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_ct_is_pending();
```
