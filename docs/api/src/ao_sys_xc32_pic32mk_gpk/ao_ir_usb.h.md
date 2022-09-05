---
api: true
author: "Stefan Wagner"
date: 2022-09-05
description: "The /src/ao_sys_xc32_pic32mk_gpk/ao_ir_usb.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gpk/ao_ir_usb.h/
subtitle: "USB interrupts"
title: "ao_ir_usb.h"
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_USB1`

The interrupt handler attribute.

```c
#define AO_IR_USB1_ATTRIBUTE __ISR(_USB_1_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_USB1_PRIO      (4)
#define AO_IR_USB1_SUBPRIO   (0)
```

## `AO_IR_USB2`

The interrupt handler attribute.

```c
#define AO_IR_USB2_ATTRIBUTE __ISR(_USB_2_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_USB2_PRIO      (4)
#define AO_IR_USB2_SUBPRIO   (0)
```

# Functions

## `ao_ir_usb1`

Enable or disable the interrupt.

```c
#define ao_ir_usb1_enable()
#define ao_ir_usb1_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_usb1_request()
#define ao_ir_usb1_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_usb1_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_usb1_is_pending()
```

## `ao_ir_usb2`

Enable or disable the interrupt.

```c
#define ao_ir_usb2_enable()
#define ao_ir_usb2_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_usb2_request()
#define ao_ir_usb2_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_usb2_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_usb2_is_pending()
```
