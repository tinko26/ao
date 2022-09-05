---
api: true
author: "Stefan Wagner"
date: 2022-09-05
description: "The /src/ao_sys_xc32_pic32/ao_ir_cs.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_ir_cs.h/
subtitle: "Core software interrupts"
title: "ao_ir_cs.h"
toc: true
---

# Include

```c
#include <stdbool.h>
```

# Functions

## Core software interrupt 0

Enable or disable the interrupt.

```c
void ao_ir_cs0_enable();
void ao_ir_cs0_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_cs0_request();
void ao_ir_cs0_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_cs0_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_cs0_is_pending();
```

## Core software interrupt 1

Enable or disable the interrupt.

```c
void ao_ir_cs1_enable();
void ao_ir_cs1_disable();
```

Request the interrupt or reply thereto.

```c
void ao_ir_cs1_request();
void ao_ir_cs1_reply();
```

Check whether the interrupt is enabled.

```c
bool ao_ir_cs1_is_enabled();
```

Check whether the interrupt is pending.

```c
bool ao_ir_cs1_is_pending();
```
