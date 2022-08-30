---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mk_gp/ao_ir_usb.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mk_gp/ao_ir_usb.h/
subtitle: ""
title: "ao_ir_usb.h"
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Constants

```c
#define AO_IR_USB1_ATTRIBUTE __ISR(_USB_1_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_USB1_PRIO (4)
```

```c
#define AO_IR_USB1_SUBPRIO (0)
```

```c
#define AO_IR_USB2_ATTRIBUTE __ISR(_USB_2_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_USB2_PRIO (4)
```

```c
#define AO_IR_USB2_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_usb1_disable()
```

```c
#define ao_ir_usb1_enable()
```

```c
#define ao_ir_usb1_is_enabled()
```

```c
#define ao_ir_usb1_is_pending()
```

```c
#define ao_ir_usb1_reply()
```

```c
#define ao_ir_usb1_request()
```

```c
#define ao_ir_usb2_disable()
```

```c
#define ao_ir_usb2_enable()
```

```c
#define ao_ir_usb2_is_enabled()
```

```c
#define ao_ir_usb2_is_pending()
```

```c
#define ao_ir_usb2_reply()
```

```c
#define ao_ir_usb2_request()
```

