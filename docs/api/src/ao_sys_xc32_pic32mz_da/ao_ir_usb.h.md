---
author: "Stefan Wagner"
date: 2022-09-05
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz_da/ao_ir_usb.h/
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

The interrupt handler attribute.

```c
#define AO_IR_USB_ATTRIBUTE __ISR(_USB_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_USB_PRIO      (4)
#define AO_IR_USB_SUBPRIO   (0)
```

## `AO_IR_USBDMA`

The interrupt handler attribute.

```c
#define AO_IR_USBDMA_ATTRIBUTE __ISR(_USB_DMA_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_USBDMA_PRIO      (4)
#define AO_IR_USBDMA_SUBPRIO   (0)
```

## `AO_IR_USBSR`

The interrupt handler attribute.

```c
#define AO_IR_USBSR_ATTRIBUTE __ISR(_USB_SR_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_USBSR_PRIO      (4)
#define AO_IR_USBSR_SUBPRIO   (0)
```

# Functions

## `ao_ir_usb`

Enable or disable the interrupt.

```c
#define ao_ir_usb_enable()
#define ao_ir_usb_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_usb_request()
#define ao_ir_usb_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_usb_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_usb_is_pending()
```

## `ao_ir_usbdma`

Enable or disable the interrupt.

```c
#define ao_ir_usbdma_enable()
#define ao_ir_usbdma_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_usbdma_request()
#define ao_ir_usbdma_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_usbdma_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_usbdma_is_pending()
```

## `ao_ir_usbsr`

Enable or disable the interrupt.

```c
#define ao_ir_usbsr_enable()
#define ao_ir_usbsr_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_usbsr_request()
#define ao_ir_usbsr_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_usbsr_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_usbsr_is_pending()
```
