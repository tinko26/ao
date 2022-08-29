---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mz_ec/ao_ir_int.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32_pic32mz_ec/ao_ir_int.h/ 
subtitle: ""
title: "ao_ir_int.h"
toc: true
---

# Overview

...

# Includes

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

#ifndef AO_IR_INT0_ATTRIBUTE

#define AO_IR_INT0_ATTRIBUTE        __ISR(_EXTERNAL_0_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_INT0_PRIO

#define AO_IR_INT0_PRIO             (4)

#endif

#ifndef AO_IR_INT0_SUBPRIO

#define AO_IR_INT0_SUBPRIO          (0)

#endif

#ifndef ao_ir_int0_disable

#define ao_ir_int0_disable()        { IEC0CLR = _IEC0_INT0IE_MASK; }

#endif

#ifndef ao_ir_int0_enable

#define ao_ir_int0_enable()         { IEC0SET = _IEC0_INT0IE_MASK; }

#endif

#ifndef ao_ir_int0_is_enabled

#define ao_ir_int0_is_enabled()     ((IEC0 & _IEC0_INT0IE_MASK) ? true : false)

#endif

#ifndef ao_ir_int0_is_pending

#define ao_ir_int0_is_pending()     ((IFS0 & _IFS0_INT0IF_MASK) ? true : false)

#endif

#ifndef ao_ir_int0_reply

#define ao_ir_int0_reply()          { IFS0CLR = _IFS0_INT0IF_MASK; }

#endif

#ifndef ao_ir_int0_request

#define ao_ir_int0_request()        { IFS0SET = _IFS0_INT0IF_MASK; }

#endif

#ifndef ao_ir_int0_falling

#define ao_ir_int0_falling()        { INTCONCLR = _INTCON_INT0EP_MASK; }

#endif

#ifndef ao_ir_int0_is_falling

#define ao_ir_int0_is_falling()     ((INTCON & _INTCON_INT0EP_MASK) ? false : true)

#endif

#ifndef ao_ir_int0_is_rising

#define ao_ir_int0_is_rising()      ((INTCON & _INTCON_INT0EP_MASK) ? true : false)

#endif

#ifndef ao_ir_int0_rising

#define ao_ir_int0_rising()         { INTCONSET = _INTCON_INT0EP_MASK; }

#endif

#ifndef AO_IR_INT1_ATTRIBUTE

#define AO_IR_INT1_ATTRIBUTE        __ISR(_EXTERNAL_1_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_INT1_PRIO

#define AO_IR_INT1_PRIO             (4)

#endif

#ifndef AO_IR_INT1_SUBPRIO

#define AO_IR_INT1_SUBPRIO          (0)

#endif

#ifndef ao_ir_int1_disable

#define ao_ir_int1_disable()        { IEC0CLR = _IEC0_INT1IE_MASK; }

#endif

#ifndef ao_ir_int1_enable

#define ao_ir_int1_enable()         { IEC0SET = _IEC0_INT1IE_MASK; }

#endif

#ifndef ao_ir_int1_is_enabled

#define ao_ir_int1_is_enabled()     ((IEC0 & _IEC0_INT1IE_MASK) ? true : false)

#endif

#ifndef ao_ir_int1_is_pending

#define ao_ir_int1_is_pending()     ((IFS0 & _IFS0_INT1IF_MASK) ? true : false)

#endif

#ifndef ao_ir_int1_reply

#define ao_ir_int1_reply()          { IFS0CLR = _IFS0_INT1IF_MASK; }

#endif

#ifndef ao_ir_int1_request

#define ao_ir_int1_request()        { IFS0SET = _IFS0_INT1IF_MASK; }

#endif

#ifndef ao_ir_int1_falling

#define ao_ir_int1_falling()        { INTCONCLR = _INTCON_INT1EP_MASK; }

#endif

#ifndef ao_ir_int1_is_falling

#define ao_ir_int1_is_falling()     ((INTCON & _INTCON_INT1EP_MASK) ? false : true)

#endif

#ifndef ao_ir_int1_is_rising

#define ao_ir_int1_is_rising()      ((INTCON & _INTCON_INT1EP_MASK) ? true : false)

#endif

#ifndef ao_ir_int1_rising

#define ao_ir_int1_rising()         { INTCONSET = _INTCON_INT1EP_MASK; }

#endif

#ifndef AO_IR_INT2_ATTRIBUTE

#define AO_IR_INT2_ATTRIBUTE        __ISR(_EXTERNAL_2_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_INT2_PRIO

#define AO_IR_INT2_PRIO             (4)

#endif

#ifndef AO_IR_INT2_SUBPRIO

#define AO_IR_INT2_SUBPRIO          (0)

#endif

#ifndef ao_ir_int2_disable

#define ao_ir_int2_disable()        { IEC0CLR = _IEC0_INT2IE_MASK; }

#endif

#ifndef ao_ir_int2_enable

#define ao_ir_int2_enable()         { IEC0SET = _IEC0_INT2IE_MASK; }

#endif

#ifndef ao_ir_int2_is_enabled

#define ao_ir_int2_is_enabled()     ((IEC0 & _IEC0_INT2IE_MASK) ? true : false)

#endif

#ifndef ao_ir_int2_is_pending

#define ao_ir_int2_is_pending()     ((IFS0 & _IFS0_INT2IF_MASK) ? true : false)

#endif

#ifndef ao_ir_int2_reply

#define ao_ir_int2_reply()          { IFS0CLR = _IFS0_INT2IF_MASK; }

#endif

#ifndef ao_ir_int2_request

#define ao_ir_int2_request()        { IFS0SET = _IFS0_INT2IF_MASK; }

#endif

#ifndef ao_ir_int2_falling

#define ao_ir_int2_falling()        { INTCONCLR = _INTCON_INT2EP_MASK; }

#endif

#ifndef ao_ir_int2_is_falling

#define ao_ir_int2_is_falling()     ((INTCON & _INTCON_INT2EP_MASK) ? false : true)

#endif

#ifndef ao_ir_int2_is_rising

#define ao_ir_int2_is_rising()      ((INTCON & _INTCON_INT2EP_MASK) ? true : false)

#endif

#ifndef ao_ir_int2_rising

#define ao_ir_int2_rising()         { INTCONSET = _INTCON_INT2EP_MASK; }

#endif

#ifndef AO_IR_INT3_ATTRIBUTE

#define AO_IR_INT3_ATTRIBUTE        __ISR(_EXTERNAL_3_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_INT3_PRIO

#define AO_IR_INT3_PRIO             (4)

#endif

#ifndef AO_IR_INT3_SUBPRIO

#define AO_IR_INT3_SUBPRIO          (0)

#endif

#ifndef ao_ir_int3_disable

#define ao_ir_int3_disable()        { IEC0CLR = _IEC0_INT3IE_MASK; }

#endif

#ifndef ao_ir_int3_enable

#define ao_ir_int3_enable()         { IEC0SET = _IEC0_INT3IE_MASK; }

#endif

#ifndef ao_ir_int3_is_enabled

#define ao_ir_int3_is_enabled()     ((IEC0 & _IEC0_INT3IE_MASK) ? true : false)

#endif

#ifndef ao_ir_int3_is_pending

#define ao_ir_int3_is_pending()     ((IFS0 & _IFS0_INT3IF_MASK) ? true : false)

#endif

#ifndef ao_ir_int3_reply

#define ao_ir_int3_reply()          { IFS0CLR = _IFS0_INT3IF_MASK; }

#endif

#ifndef ao_ir_int3_request

#define ao_ir_int3_request()        { IFS0SET = _IFS0_INT3IF_MASK; }

#endif

#ifndef ao_ir_int3_falling

#define ao_ir_int3_falling()        { INTCONCLR = _INTCON_INT3EP_MASK; }

#endif

#ifndef ao_ir_int3_is_falling

#define ao_ir_int3_is_falling()     ((INTCON & _INTCON_INT3EP_MASK) ? false : true)

#endif

#ifndef ao_ir_int3_is_rising

#define ao_ir_int3_is_rising()      ((INTCON & _INTCON_INT3EP_MASK) ? true : false)

#endif

#ifndef ao_ir_int3_rising

#define ao_ir_int3_rising()         { INTCONSET = _INTCON_INT3EP_MASK; }

#endif

#ifndef AO_IR_INT4_ATTRIBUTE

#define AO_IR_INT4_ATTRIBUTE        __ISR(_EXTERNAL_4_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_INT4_PRIO

#define AO_IR_INT4_PRIO             (4)

#endif

#ifndef AO_IR_INT4_SUBPRIO

#define AO_IR_INT4_SUBPRIO          (0)

#endif

#ifndef ao_ir_int4_disable

#define ao_ir_int4_disable()        { IEC0CLR = _IEC0_INT4IE_MASK; }

#endif

#ifndef ao_ir_int4_enable

#define ao_ir_int4_enable()         { IEC0SET = _IEC0_INT4IE_MASK; }

#endif

#ifndef ao_ir_int4_is_enabled

#define ao_ir_int4_is_enabled()     ((IEC0 & _IEC0_INT4IE_MASK) ? true : false)

#endif

#ifndef ao_ir_int4_is_pending

#define ao_ir_int4_is_pending()     ((IFS0 & _IFS0_INT4IF_MASK) ? true : false)

#endif

#ifndef ao_ir_int4_reply

#define ao_ir_int4_reply()          { IFS0CLR = _IFS0_INT4IF_MASK; }

#endif

#ifndef ao_ir_int4_request

#define ao_ir_int4_request()        { IFS0SET = _IFS0_INT4IF_MASK; }

#endif

#ifndef ao_ir_int4_falling

#define ao_ir_int4_falling()        { INTCONCLR = _INTCON_INT4EP_MASK; }

#endif

#ifndef ao_ir_int4_is_falling

#define ao_ir_int4_is_falling()     ((INTCON & _INTCON_INT4EP_MASK) ? false : true)

#endif

#ifndef ao_ir_int4_is_rising

#define ao_ir_int4_is_rising()      ((INTCON & _INTCON_INT4EP_MASK) ? true : false)

#endif

#ifndef ao_ir_int4_rising

#define ao_ir_int4_rising()         { INTCONSET = _INTCON_INT4EP_MASK; }

#endif

```
