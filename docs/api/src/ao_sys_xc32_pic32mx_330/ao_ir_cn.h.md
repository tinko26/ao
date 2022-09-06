---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mx_330/ao_ir_cn.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_CN`

The interrupt handler attribute.

```c
#define AO_IR_CN_ATTRIBUTE __ISR(_CHANGE_NOTICE_VECTOR, IPL4SOFT)
```

The interrupt priority and subpriority.

```c
#define AO_IR_CN_PRIO      (4)
#define AO_IR_CN_SUBPRIO   (0)
```

# Functions

## `ao_ir_cna`

Enable or disable the interrupt.

```c
#define ao_ir_cna_enable()
#define ao_ir_cna_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_cna_request()
#define ao_ir_cna_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_cna_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_cna_is_pending()
```

## `ao_ir_cnb`

Enable or disable the interrupt.

```c
#define ao_ir_cnb_enable()
#define ao_ir_cnb_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_cnb_request()
#define ao_ir_cnb_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_cnb_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_cnb_is_pending()
```

## `ao_ir_cnc`

Enable or disable the interrupt.

```c
#define ao_ir_cnc_enable()
#define ao_ir_cnc_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_cnc_request()
#define ao_ir_cnc_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_cnc_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_cnc_is_pending()
```

## `ao_ir_cnd`

Enable or disable the interrupt.

```c
#define ao_ir_cnd_enable()
#define ao_ir_cnd_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_cnd_request()
#define ao_ir_cnd_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_cnd_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_cnd_is_pending()
```

## `ao_ir_cne`

Enable or disable the interrupt.

```c
#define ao_ir_cne_enable()
#define ao_ir_cne_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_cne_request()
#define ao_ir_cne_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_cne_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_cne_is_pending()
```

## `ao_ir_cnf`

Enable or disable the interrupt.

```c
#define ao_ir_cnf_enable()
#define ao_ir_cnf_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_cnf_request()
#define ao_ir_cnf_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_cnf_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_cnf_is_pending()
```

## `ao_ir_cng`

Enable or disable the interrupt.

```c
#define ao_ir_cng_enable()
#define ao_ir_cng_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_cng_request()
#define ao_ir_cng_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_cng_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_cng_is_pending()
```
