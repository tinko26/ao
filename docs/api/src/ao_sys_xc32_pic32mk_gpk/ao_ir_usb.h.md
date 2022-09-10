---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mk_gpk/ao_ir_usb.h/
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

```c
#define AO_IR_USB1_ATTRIBUTE __ISR(_USB_1_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_USB1_PRIO    (4)
#define AO_IR_USB1_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_USB2`

```c
#define AO_IR_USB2_ATTRIBUTE __ISR(_USB_2_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_USB2_PRIO    (4)
#define AO_IR_USB2_SUBPRIO (0)
```

The interrupt priority and subpriority.

# Functions

## `ao_ir_usb1`

```c
#define ao_ir_usb1_enable()
#define ao_ir_usb1_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_usb1_request()
#define ao_ir_usb1_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_usb1_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_usb1_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_usb2`

```c
#define ao_ir_usb2_enable()
#define ao_ir_usb2_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_usb2_request()
#define ao_ir_usb2_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_usb2_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_usb2_is_pending()
```

Checks whether the interrupt is pending.
