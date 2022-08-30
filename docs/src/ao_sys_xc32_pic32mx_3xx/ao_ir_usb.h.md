---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mx_3xx/ao_ir_usb.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32_pic32mx_3xx/ao_ir_usb.h/
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
#define AO_IR_USB_ATTRIBUTE __ISR(_USB_1_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_USB_PRIO (4)
```

```c
#define AO_IR_USB_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_usb_disable()
```

```c
#define ao_ir_usb_enable()
```

```c
#define ao_ir_usb_is_enabled()
```

```c
#define ao_ir_usb_is_pending()
```

```c
#define ao_ir_usb_reply()
```

```c
#define ao_ir_usb_request()
```

