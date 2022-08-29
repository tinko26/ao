---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32mk_gp/ao_ir_usb.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mk_gp/ao_ir_usb.h/ 
subtitle: "<code>ao_sys_xc32_pic32mk_gp</code>"
title: "<code>ao_ir_usb.h</code>"
toc: true
---

```c
#ifndef AO_IR_USB1_ATTRIBUTE

#define AO_IR_USB1_ATTRIBUTE        __ISR(_USB_1_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_USB1_PRIO

#define AO_IR_USB1_PRIO             (4)

#endif

#ifndef AO_IR_USB1_SUBPRIO

#define AO_IR_USB1_SUBPRIO          (0)

#endif

#ifndef ao_ir_usb1_disable

#define ao_ir_usb1_disable()        { IEC1CLR = _IEC1_USB1IE_MASK; }

#endif

#ifndef ao_ir_usb1_enable

#define ao_ir_usb1_enable()         { IEC1SET = _IEC1_USB1IE_MASK; }

#endif

#ifndef ao_ir_usb1_is_enabled

#define ao_ir_usb1_is_enabled()     ((IEC1 & _IEC1_USB1IE_MASK) ? true : false)

#endif

#ifndef ao_ir_usb1_is_pending

#define ao_ir_usb1_is_pending()     ((IFS1 & _IFS1_USB1IF_MASK) ? true : false)

#endif

#ifndef ao_ir_usb1_reply

#define ao_ir_usb1_reply()          { IFS1CLR = _IFS1_USB1IF_MASK; }

#endif

#ifndef ao_ir_usb1_request

#define ao_ir_usb1_request()        { IFS1SET = _IFS1_USB1IF_MASK; }

#endif

#ifndef AO_IR_USB2_ATTRIBUTE

#define AO_IR_USB2_ATTRIBUTE        __ISR(_USB_2_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_USB2_PRIO

#define AO_IR_USB2_PRIO             (4)

#endif

#ifndef AO_IR_USB2_SUBPRIO

#define AO_IR_USB2_SUBPRIO          (0)

#endif

#ifndef ao_ir_usb2_disable

#define ao_ir_usb2_disable()        { IEC7CLR = _IEC7_USB2IE_MASK; }

#endif

#ifndef ao_ir_usb2_enable

#define ao_ir_usb2_enable()         { IEC7SET = _IEC7_USB2IE_MASK; }

#endif

#ifndef ao_ir_usb2_is_enabled

#define ao_ir_usb2_is_enabled()     ((IEC7 & _IEC7_USB2IE_MASK) ? true : false)

#endif

#ifndef ao_ir_usb2_is_pending

#define ao_ir_usb2_is_pending()     ((IFS7 & _IFS7_USB2IF_MASK) ? true : false)

#endif

#ifndef ao_ir_usb2_reply

#define ao_ir_usb2_reply()          { IFS7CLR = _IFS7_USB2IF_MASK; }

#endif

#ifndef ao_ir_usb2_request

#define ao_ir_usb2_request()        { IFS7SET = _IFS7_USB2IF_MASK; }

#endif

```
