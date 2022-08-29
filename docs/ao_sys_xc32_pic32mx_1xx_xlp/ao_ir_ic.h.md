---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mx_1xx_xlp/ao_ir_ic.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mx_1xx_xlp/ao_ir_ic.h/ 
subtitle: ""
title: "ao_ir_ic.h"
toc: true
---

# Overview

...

# Includes

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

#ifndef AO_IR_IC1_ATTRIBUTE

#define AO_IR_IC1_ATTRIBUTE         __ISR(_INPUT_CAPTURE_1_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_IC1_PRIO

#define AO_IR_IC1_PRIO              (4)

#endif

#ifndef AO_IR_IC1_SUBPRIO

#define AO_IR_IC1_SUBPRIO           (0)

#endif

#ifndef ao_ir_ic1_disable

#define ao_ir_ic1_disable()         { IEC0CLR = _IEC0_IC1IE_MASK; }

#endif

#ifndef ao_ir_ic1_enable

#define ao_ir_ic1_enable()          { IEC0SET = _IEC0_IC1IE_MASK; }

#endif

#ifndef ao_ir_ic1_is_enabled

#define ao_ir_ic1_is_enabled()      ((IEC0 & _IEC0_IC1IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ic1_is_pending

#define ao_ir_ic1_is_pending()      ((IFS0 & _IFS0_IC1IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ic1_reply

#define ao_ir_ic1_reply()           { IFS0CLR = _IFS0_IC1IF_MASK; }

#endif

#ifndef ao_ir_ic1_request

#define ao_ir_ic1_request()         { IFS0SET = _IFS0_IC1IF_MASK; }

#endif

#ifndef ao_ir_ic1e_disable

#define ao_ir_ic1e_disable()        { IEC0CLR = _IEC0_IC1EIE_MASK; }

#endif

#ifndef ao_ir_ic1e_enable

#define ao_ir_ic1e_enable()         { IEC0SET = _IEC0_IC1EIE_MASK; }

#endif

#ifndef ao_ir_ic1e_is_enabled

#define ao_ir_ic1e_is_enabled()     ((IEC0 & _IEC0_IC1EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_ic1e_is_pending

#define ao_ir_ic1e_is_pending()     ((IFS0 & _IFS0_IC1EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_ic1e_reply

#define ao_ir_ic1e_reply()          { IFS0CLR = _IFS0_IC1EIF_MASK; }

#endif

#ifndef ao_ir_ic1e_request

#define ao_ir_ic1e_request()        { IFS0SET = _IFS0_IC1EIF_MASK; }

#endif

#ifndef AO_IR_IC2_ATTRIBUTE

#define AO_IR_IC2_ATTRIBUTE         __ISR(_INPUT_CAPTURE_2_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_IC2_PRIO

#define AO_IR_IC2_PRIO              (4)

#endif

#ifndef AO_IR_IC2_SUBPRIO

#define AO_IR_IC2_SUBPRIO           (0)

#endif

#ifndef ao_ir_ic2_disable

#define ao_ir_ic2_disable()         { IEC0CLR = _IEC0_IC2IE_MASK; }

#endif

#ifndef ao_ir_ic2_enable

#define ao_ir_ic2_enable()          { IEC0SET = _IEC0_IC2IE_MASK; }

#endif

#ifndef ao_ir_ic2_is_enabled

#define ao_ir_ic2_is_enabled()      ((IEC0 & _IEC0_IC2IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ic2_is_pending

#define ao_ir_ic2_is_pending()      ((IFS0 & _IFS0_IC2IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ic2_reply

#define ao_ir_ic2_reply()           { IFS0CLR = _IFS0_IC2IF_MASK; }

#endif

#ifndef ao_ir_ic2_request

#define ao_ir_ic2_request()         { IFS0SET = _IFS0_IC2IF_MASK; }

#endif

#ifndef ao_ir_ic2e_disable

#define ao_ir_ic2e_disable()        { IEC0CLR = _IEC0_IC2EIE_MASK; }

#endif

#ifndef ao_ir_ic2e_enable

#define ao_ir_ic2e_enable()         { IEC0SET = _IEC0_IC2EIE_MASK; }

#endif

#ifndef ao_ir_ic2e_is_enabled

#define ao_ir_ic2e_is_enabled()     ((IEC0 & _IEC0_IC2EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_ic2e_is_pending

#define ao_ir_ic2e_is_pending()     ((IFS0 & _IFS0_IC2EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_ic2e_reply

#define ao_ir_ic2e_reply()          { IFS0CLR = _IFS0_IC2EIF_MASK; }

#endif

#ifndef ao_ir_ic2e_request

#define ao_ir_ic2e_request()        { IFS0SET = _IFS0_IC2EIF_MASK; }

#endif

#ifndef ao_ir_ic3_disable

#define ao_ir_ic3_disable()         { IEC0CLR = _IEC0_IC3IE_MASK; }

#endif

#ifndef ao_ir_ic3_enable

#define ao_ir_ic3_enable()          { IEC0SET = _IEC0_IC3IE_MASK; }

#endif

#ifndef ao_ir_ic3_is_enabled

#define ao_ir_ic3_is_enabled()      ((IEC0 & _IEC0_IC3IE_MASK) ? true : false)

#endif

#ifndef AO_IR_IC3_ATTRIBUTE

#define AO_IR_IC3_ATTRIBUTE         __ISR(_INPUT_CAPTURE_3_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_IC3_PRIO

#define AO_IR_IC3_PRIO              (4)

#endif

#ifndef AO_IR_IC3_SUBPRIO

#define AO_IR_IC3_SUBPRIO           (0)

#endif

#ifndef ao_ir_ic3_is_pending

#define ao_ir_ic3_is_pending()      ((IFS0 & _IFS0_IC3IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ic3_reply

#define ao_ir_ic3_reply()           { IFS0CLR = _IFS0_IC3IF_MASK; }

#endif

#ifndef ao_ir_ic3_request

#define ao_ir_ic3_request()         { IFS0SET = _IFS0_IC3IF_MASK; }

#endif

#ifndef ao_ir_ic3e_disable

#define ao_ir_ic3e_disable()        { IEC0CLR = _IEC0_IC3EIE_MASK; }

#endif

#ifndef ao_ir_ic3e_enable

#define ao_ir_ic3e_enable()         { IEC0SET = _IEC0_IC3EIE_MASK; }

#endif

#ifndef ao_ir_ic3e_is_enabled

#define ao_ir_ic3e_is_enabled()     ((IEC0 & _IEC0_IC3EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_ic3e_is_pending

#define ao_ir_ic3e_is_pending()     ((IFS0 & _IFS0_IC3EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_ic3e_reply

#define ao_ir_ic3e_reply()          { IFS0CLR = _IFS0_IC3EIF_MASK; }

#endif

#ifndef ao_ir_ic3e_request

#define ao_ir_ic3e_request()        { IFS0SET = _IFS0_IC3EIF_MASK; }

#endif

#ifndef AO_IR_IC4_ATTRIBUTE

#define AO_IR_IC4_ATTRIBUTE         __ISR(_INPUT_CAPTURE_4_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_IC4_PRIO

#define AO_IR_IC4_PRIO              (4)

#endif

#ifndef AO_IR_IC4_SUBPRIO

#define AO_IR_IC4_SUBPRIO           (0)

#endif

#ifndef ao_ir_ic4_disable

#define ao_ir_ic4_disable()         { IEC0CLR = _IEC0_IC4IE_MASK; }

#endif

#ifndef ao_ir_ic4_enable

#define ao_ir_ic4_enable()          { IEC0SET = _IEC0_IC4IE_MASK; }

#endif

#ifndef ao_ir_ic4_is_enabled

#define ao_ir_ic4_is_enabled()      ((IEC0 & _IEC0_IC4IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ic4_is_pending

#define ao_ir_ic4_is_pending()      ((IFS0 & _IFS0_IC4IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ic4_reply

#define ao_ir_ic4_reply()           { IFS0CLR = _IFS0_IC4IF_MASK; }

#endif

#ifndef ao_ir_ic4_request

#define ao_ir_ic4_request()         { IFS0SET = _IFS0_IC4IF_MASK; }

#endif

#ifndef ao_ir_ic4e_disable

#define ao_ir_ic4e_disable()        { IEC0CLR = _IEC0_IC4EIE_MASK; }

#endif

#ifndef ao_ir_ic4e_enable

#define ao_ir_ic4e_enable()         { IEC0SET = _IEC0_IC4EIE_MASK; }

#endif

#ifndef ao_ir_ic4e_is_enabled

#define ao_ir_ic4e_is_enabled()     ((IEC0 & _IEC0_IC4EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_ic4e_is_pending

#define ao_ir_ic4e_is_pending()     ((IFS0 & _IFS0_IC4EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_ic4e_reply

#define ao_ir_ic4e_reply()          { IFS0CLR = _IFS0_IC4EIF_MASK; }

#endif

#ifndef ao_ir_ic4e_request

#define ao_ir_ic4e_request()        { IFS0SET = _IFS0_IC4EIF_MASK; }

#endif

#ifndef AO_IR_IC5_ATTRIBUTE

#define AO_IR_IC5_ATTRIBUTE         __ISR(_INPUT_CAPTURE_5_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_IC5_PRIO

#define AO_IR_IC5_PRIO              (4)

#endif

#ifndef AO_IR_IC5_SUBPRIO

#define AO_IR_IC5_SUBPRIO           (0)

#endif

#ifndef ao_ir_ic5_disable

#define ao_ir_ic5_disable()         { IEC0CLR = _IEC0_IC5IE_MASK; }

#endif

#ifndef ao_ir_ic5_enable

#define ao_ir_ic5_enable()          { IEC0SET = _IEC0_IC5IE_MASK; }

#endif

#ifndef ao_ir_ic5_is_enabled

#define ao_ir_ic5_is_enabled()      ((IEC0 & _IEC0_IC5IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ic5_is_pending

#define ao_ir_ic5_is_pending()      ((IFS0 & _IFS0_IC5IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ic5_reply

#define ao_ir_ic5_reply()           { IFS0CLR = _IFS0_IC5IF_MASK; }

#endif

#ifndef ao_ir_ic5_request

#define ao_ir_ic5_request()         { IFS0SET = _IFS0_IC5IF_MASK; }

#endif

#ifndef ao_ir_ic5e_disable

#define ao_ir_ic5e_disable()        { IEC0CLR = _IEC0_IC5EIE_MASK; }

#endif

#ifndef ao_ir_ic5e_enable

#define ao_ir_ic5e_enable()         { IEC0SET = _IEC0_IC5EIE_MASK; }

#endif

#ifndef ao_ir_ic5e_is_enabled

#define ao_ir_ic5e_is_enabled()     ((IEC0 & _IEC0_IC5EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_ic5e_is_pending

#define ao_ir_ic5e_is_pending()     ((IFS0 & _IFS0_IC5EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_ic5e_reply

#define ao_ir_ic5e_reply()          { IFS0CLR = _IFS0_IC5EIF_MASK; }

#endif

#ifndef ao_ir_ic5e_request

#define ao_ir_ic5e_request()        { IFS0SET = _IFS0_IC5EIF_MASK; }

#endif

```
