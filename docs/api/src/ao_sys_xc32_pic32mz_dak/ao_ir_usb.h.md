---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz_dak/ao_ir_usb.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_USB`

```c
#define AO_IR_USB_ATTRIBUTE __ISR(_USB_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_USB_PRIO    (4)
#define AO_IR_USB_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_USBDMA`

```c
#define AO_IR_USBDMA_ATTRIBUTE __ISR(_USB_DMA_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_USBDMA_PRIO    (4)
#define AO_IR_USBDMA_SUBPRIO (0)
```

The interrupt priority and subpriority.

## `AO_IR_USBSR`

```c
#define AO_IR_USBSR_ATTRIBUTE __ISR(_USB_SR_VECTOR, IPL4SRS)
```

The interrupt handler attribute.

```c
#define AO_IR_USBSR_PRIO    (4)
#define AO_IR_USBSR_SUBPRIO (0)
```

The interrupt priority and subpriority.

# Functions

## `ao_ir_usb`

```c
#define ao_ir_usb_enable()
#define ao_ir_usb_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_usb_request()
#define ao_ir_usb_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_usb_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_usb_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_usbdma`

```c
#define ao_ir_usbdma_enable()
#define ao_ir_usbdma_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_usbdma_request()
#define ao_ir_usbdma_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_usbdma_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_usbdma_is_pending()
```

Checks whether the interrupt is pending.

## `ao_ir_usbsr`

```c
#define ao_ir_usbsr_enable()
#define ao_ir_usbsr_disable()
```

Enables or disables the interrupt.

```c
#define ao_ir_usbsr_request()
#define ao_ir_usbsr_reply()
```

Requests the interrupt or replies thereto.

```c
#define ao_ir_usbsr_is_enabled()
```

Checks whether the interrupt is enabled.

```c
#define ao_ir_usbsr_is_pending()
```

Checks whether the interrupt is pending.
