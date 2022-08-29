---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mz_dak/ao_ir_usb.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mz_dak/ao_ir_usb.h/ 
subtitle: "ao_sys_xc32_pic32mz_dak"
title: "ao_ir_usb.h"
toc: true
---

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

#ifndef AO_IR_USB_ATTRIBUTE

#define AO_IR_USB_ATTRIBUTE         __ISR(_USB_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_USB_PRIO

#define AO_IR_USB_PRIO              (4)

#endif

#ifndef AO_IR_USB_SUBPRIO

#define AO_IR_USB_SUBPRIO           (0)

#endif

#ifndef ao_ir_usb_disable

#define ao_ir_usb_disable()         { IEC4CLR = _IEC4_USBIE_MASK; }

#endif

#ifndef ao_ir_usb_enable

#define ao_ir_usb_enable()          { IEC4SET = _IEC4_USBIE_MASK; }

#endif

#ifndef ao_ir_usb_is_enabled

#define ao_ir_usb_is_enabled()      ((IEC4 & _IEC4_USBIE_MASK) ? true : false)

#endif

#ifndef ao_ir_usb_is_pending

#define ao_ir_usb_is_pending()      ((IFS4 & _IFS4_USBIF_MASK) ? true : false)

#endif

#ifndef ao_ir_usb_reply

#define ao_ir_usb_reply()           { IFS4CLR = _IFS4_USBIF_MASK; }

#endif

#ifndef ao_ir_usb_request

#define ao_ir_usb_request()         { IFS4SET = _IFS4_USBIF_MASK; }

#endif

#ifndef AO_IR_USBDMA_ATTRIBUTE

#define AO_IR_USBDMA_ATTRIBUTE      __ISR(_USB_DMA_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_USBDMA_PRIO

#define AO_IR_USBDMA_PRIO           (4)

#endif

#ifndef AO_IR_USBDMA_SUBPRIO

#define AO_IR_USBDMA_SUBPRIO        (0)

#endif

#ifndef ao_ir_usbdma_disable

#define ao_ir_usbdma_disable()      { IEC4CLR = _IEC4_USBDMAIE_MASK; }

#endif

#ifndef ao_ir_usbdma_enable

#define ao_ir_usbdma_enable()       { IEC4SET = _IEC4_USBDMAIE_MASK; }

#endif

#ifndef ao_ir_usbdma_is_enabled

#define ao_ir_usbdma_is_enabled()   ((IEC4 & _IEC4_USBDMAIE_MASK) ? true : false)

#endif

#ifndef ao_ir_usbdma_is_pending

#define ao_ir_usbdma_is_pending()   ((IFS4 & _IFS4_USBDMAIF_MASK) ? true : false)

#endif

#ifndef ao_ir_usbdma_reply

#define ao_ir_usbdma_reply()        { IFS4CLR = _IFS4_USBDMAIF_MASK; }

#endif

#ifndef ao_ir_usbdma_request

#define ao_ir_usbdma_request()      { IFS4SET = _IFS4_USBDMAIF_MASK; }

#endif

#ifndef AO_IR_USBSR_ATTRIBUTE

#define AO_IR_USBSR_ATTRIBUTE       __ISR(_USB_SR_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_USBSR_PRIO

#define AO_IR_USBSR_PRIO            (4)

#endif

#ifndef AO_IR_USBSR_SUBPRIO

#define AO_IR_USBSR_SUBPRIO         (0)

#endif

#ifndef ao_ir_usbsr_disable

#define ao_ir_usbsr_disable()       { IEC3CLR = _IEC3_USBSRIE_MASK; }

#endif

#ifndef ao_ir_usbsr_enable

#define ao_ir_usbsr_enable()        { IEC3SET = _IEC3_USBSRIE_MASK; }

#endif

#ifndef ao_ir_usbsr_is_enabled

#define ao_ir_usbsr_is_enabled()    ((IEC3 & _IEC3_USBSRIE_MASK) ? true : false)

#endif

#ifndef ao_ir_usbsr_is_pending

#define ao_ir_usbsr_is_pending()    ((IFS3 & _IFS3_USBSRIF_MASK) ? true : false)

#endif

#ifndef ao_ir_usbsr_reply

#define ao_ir_usbsr_reply()         { IFS3CLR = _IFS3_USBSRIF_MASK; }

#endif

#ifndef ao_ir_usbsr_request

#define ao_ir_usbsr_request()       { IFS3SET = _IFS3_USBSRIF_MASK; }

#endif

```
