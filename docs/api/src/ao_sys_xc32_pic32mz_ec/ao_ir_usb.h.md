---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mz_ec/ao_ir_usb.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz_ec/ao_ir_usb.h/
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
#define AO_IR_USB_ATTRIBUTE __ISR(_USB_VECTOR, IPL4SRS)
```

```c
#define AO_IR_USB_PRIO (4)
```

```c
#define AO_IR_USB_SUBPRIO (0)
```

```c
#define AO_IR_USBDMA_ATTRIBUTE __ISR(_USB_DMA_VECTOR, IPL4SRS)
```

```c
#define AO_IR_USBDMA_PRIO (4)
```

```c
#define AO_IR_USBDMA_SUBPRIO (0)
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

```c
#define ao_ir_usbdma_disable()
```

```c
#define ao_ir_usbdma_enable()
```

```c
#define ao_ir_usbdma_is_enabled()
```

```c
#define ao_ir_usbdma_is_pending()
```

```c
#define ao_ir_usbdma_reply()
```

```c
#define ao_ir_usbdma_request()
```
