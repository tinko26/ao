---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mx_330/ao_ir_usb.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32_pic32mx_330/ao_ir_usb.h/ 
subtitle: ""
title: "ao_ir_usb.h"
toc: true
---

# Overview

...

# Includes

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

#ifndef AO_IR_USB_ATTRIBUTE

#define AO_IR_USB_ATTRIBUTE     __ISR(_USB_1_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_USB_PRIO

#define AO_IR_USB_PRIO          (4)

#endif

#ifndef AO_IR_USB_SUBPRIO

#define AO_IR_USB_SUBPRIO       (0)

#endif

#ifndef ao_ir_usb_disable

#define ao_ir_usb_disable()     { IEC1CLR = _IEC1_USBIE_MASK; }

#endif

#ifndef ao_ir_usb_enable

#define ao_ir_usb_enable()      { IEC1SET = _IEC1_USBIE_MASK; }

#endif

#ifndef ao_ir_usb_is_enabled

#define ao_ir_usb_is_enabled()  ((IEC1 & _IEC1_USBIE_MASK) ? true : false)

#endif

#ifndef ao_ir_usb_is_pending

#define ao_ir_usb_is_pending()  ((IFS1 & _IFS1_USBIF_MASK) ? true : false)

#endif

#ifndef ao_ir_usb_reply

#define ao_ir_usb_reply()       { IFS1CLR = _IFS1_USBIF_MASK; }

#endif

#ifndef ao_ir_usb_request

#define ao_ir_usb_request()     { IFS1SET = _IFS1_USBIF_MASK; }

#endif

```
