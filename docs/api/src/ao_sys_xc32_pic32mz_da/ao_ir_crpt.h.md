---
api: true
author: "Stefan Wagner"
date: 2022-09-05
description: "The /src/ao_sys_xc32_pic32mz_da/ao_ir_crpt.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz_da/ao_ir_crpt.h/
subtitle: "Crypto engine interrupt"
title: "ao_ir_crpt.h"
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_CRPT`

The interrupt handler attribute.

```c
#define AO_IR_CRPT_ATTRIBUTE __ISR(_CRYPTO_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_CRPT_PRIO      (4)
#define AO_IR_CRPT_SUBPRIO   (0)
```

# Functions

## `ao_ir_crpt`

Enable or disable the interrupt.

```c
#define ao_ir_crpt_enable()
#define ao_ir_crpt_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_crpt_request()
#define ao_ir_crpt_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_crpt_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_crpt_is_pending()
```
