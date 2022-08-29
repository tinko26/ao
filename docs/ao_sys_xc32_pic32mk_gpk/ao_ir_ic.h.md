---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mk_gpk/ao_ir_ic.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mk_gpk/ao_ir_ic.h/ 
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

#define AO_IR_IC1_ATTRIBUTE         __ISR(_INPUT_CAPTURE_1_VECTOR, IPL4SRS)

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

#ifndef AO_IR_IC1E_ATTRIBUTE

#define AO_IR_IC1E_ATTRIBUTE        __ISR(_INPUT_CAPTURE_1_ERROR_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_IC1E_PRIO

#define AO_IR_IC1E_PRIO             (4)

#endif

#ifndef AO_IR_IC1E_SUBPRIO

#define AO_IR_IC1E_SUBPRIO          (0)

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

#define AO_IR_IC2_ATTRIBUTE         __ISR(_INPUT_CAPTURE_2_VECTOR, IPL4SRS)

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

#ifndef AO_IR_IC2E_ATTRIBUTE

#define AO_IR_IC2E_ATTRIBUTE        __ISR(_INPUT_CAPTURE_2_ERROR_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_IC2E_PRIO

#define AO_IR_IC2E_PRIO             (4)

#endif

#ifndef AO_IR_IC2E_SUBPRIO

#define AO_IR_IC2E_SUBPRIO          (0)

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

#ifndef AO_IR_IC3_ATTRIBUTE

#define AO_IR_IC3_ATTRIBUTE         __ISR(_INPUT_CAPTURE_3_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_IC3_PRIO

#define AO_IR_IC3_PRIO              (4)

#endif

#ifndef AO_IR_IC3_SUBPRIO

#define AO_IR_IC3_SUBPRIO           (0)

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

#ifndef ao_ir_ic3_is_pending

#define ao_ir_ic3_is_pending()      ((IFS0 & _IFS0_IC3IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ic3_reply

#define ao_ir_ic3_reply()           { IFS0CLR = _IFS0_IC3IF_MASK; }

#endif

#ifndef ao_ir_ic3_request

#define ao_ir_ic3_request()         { IFS0SET = _IFS0_IC3IF_MASK; }

#endif

#ifndef AO_IR_IC3E_ATTRIBUTE

#define AO_IR_IC3E_ATTRIBUTE        __ISR(_INPUT_CAPTURE_3_ERROR_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_IC3E_PRIO

#define AO_IR_IC3E_PRIO             (4)

#endif

#ifndef AO_IR_IC3E_SUBPRIO

#define AO_IR_IC3E_SUBPRIO          (0)

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

#define AO_IR_IC4_ATTRIBUTE         __ISR(_INPUT_CAPTURE_4_VECTOR, IPL4SRS)

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

#ifndef AO_IR_IC4E_ATTRIBUTE

#define AO_IR_IC4E_ATTRIBUTE        __ISR(_INPUT_CAPTURE_4_ERROR_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_IC4E_PRIO

#define AO_IR_IC4E_PRIO             (4)

#endif

#ifndef AO_IR_IC4E_SUBPRIO

#define AO_IR_IC4E_SUBPRIO          (0)

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

#define AO_IR_IC5_ATTRIBUTE         __ISR(_INPUT_CAPTURE_5_VECTOR, IPL4SRS)

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

#ifndef AO_IR_IC5E_ATTRIBUTE

#define AO_IR_IC5E_ATTRIBUTE        __ISR(_INPUT_CAPTURE_5_ERROR_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_IC5E_PRIO

#define AO_IR_IC5E_PRIO             (4)

#endif

#ifndef AO_IR_IC5E_SUBPRIO

#define AO_IR_IC5E_SUBPRIO          (0)

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

#ifndef AO_IR_IC6_ATTRIBUTE

#define AO_IR_IC6_ATTRIBUTE         __ISR(_INPUT_CAPTURE_6_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_IC6_PRIO

#define AO_IR_IC6_PRIO              (4)

#endif

#ifndef AO_IR_IC6_SUBPRIO

#define AO_IR_IC6_SUBPRIO           (0)

#endif

#ifndef ao_ir_ic6_disable

#define ao_ir_ic6_disable()         { IEC2CLR = _IEC2_IC6IE_MASK; }

#endif

#ifndef ao_ir_ic6_enable

#define ao_ir_ic6_enable()          { IEC2SET = _IEC2_IC6IE_MASK; }

#endif

#ifndef ao_ir_ic6_is_enabled

#define ao_ir_ic6_is_enabled()      ((IEC2 & _IEC2_IC6IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ic6_is_pending

#define ao_ir_ic6_is_pending()      ((IFS2 & _IFS2_IC6IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ic6_reply

#define ao_ir_ic6_reply()           { IFS2CLR = _IFS2_IC6IF_MASK; }

#endif

#ifndef ao_ir_ic6_request

#define ao_ir_ic6_request()         { IFS2SET = _IFS2_IC6IF_MASK; }

#endif

#ifndef AO_IR_IC6E_ATTRIBUTE

#define AO_IR_IC6E_ATTRIBUTE        __ISR(_INPUT_CAPTURE_6_ERROR_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_IC6E_PRIO

#define AO_IR_IC6E_PRIO             (4)

#endif

#ifndef AO_IR_IC6E_SUBPRIO

#define AO_IR_IC6E_SUBPRIO          (0)

#endif

#ifndef ao_ir_ic6e_disable

#define ao_ir_ic6e_disable()        { IEC2CLR = _IEC2_IC6EIE_MASK; }

#endif

#ifndef ao_ir_ic6e_enable

#define ao_ir_ic6e_enable()         { IEC2SET = _IEC2_IC6EIE_MASK; }

#endif

#ifndef ao_ir_ic6e_is_enabled

#define ao_ir_ic6e_is_enabled()     ((IEC2 & _IEC2_IC6EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_ic6e_is_pending

#define ao_ir_ic6e_is_pending()     ((IFS2 & _IFS2_IC6EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_ic6e_reply

#define ao_ir_ic6e_reply()          { IFS2CLR = _IFS2_IC6EIF_MASK; }

#endif

#ifndef ao_ir_ic6e_request

#define ao_ir_ic6e_request()        { IFS2SET = _IFS2_IC6EIF_MASK; }

#endif

#ifndef AO_IR_IC7_ATTRIBUTE

#define AO_IR_IC7_ATTRIBUTE         __ISR(_INPUT_CAPTURE_7_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_IC7_PRIO

#define AO_IR_IC7_PRIO              (4)

#endif

#ifndef AO_IR_IC7_SUBPRIO

#define AO_IR_IC7_SUBPRIO           (0)

#endif

#ifndef ao_ir_ic7_disable

#define ao_ir_ic7_disable()         { IEC2CLR = _IEC2_IC7IE_MASK; }

#endif

#ifndef ao_ir_ic7_enable

#define ao_ir_ic7_enable()          { IEC2SET = _IEC2_IC7IE_MASK; }

#endif

#ifndef ao_ir_ic7_is_enabled

#define ao_ir_ic7_is_enabled()      ((IEC2 & _IEC2_IC7IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ic7_is_pending

#define ao_ir_ic7_is_pending()      ((IFS2 & _IFS2_IC7IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ic7_reply

#define ao_ir_ic7_reply()           { IFS2CLR = _IFS2_IC7IF_MASK; }

#endif

#ifndef ao_ir_ic7_request

#define ao_ir_ic7_request()         { IFS2SET = _IFS2_IC7IF_MASK; }

#endif

#ifndef AO_IR_IC7E_ATTRIBUTE

#define AO_IR_IC7E_ATTRIBUTE        __ISR(_INPUT_CAPTURE_7_ERROR_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_IC7E_PRIO

#define AO_IR_IC7E_PRIO             (4)

#endif

#ifndef AO_IR_IC7E_SUBPRIO

#define AO_IR_IC7E_SUBPRIO          (0)

#endif

#ifndef ao_ir_ic7e_disable

#define ao_ir_ic7e_disable()        { IEC2CLR = _IEC2_IC7EIE_MASK; }

#endif

#ifndef ao_ir_ic7e_enable

#define ao_ir_ic7e_enable()         { IEC2SET = _IEC2_IC7EIE_MASK; }

#endif

#ifndef ao_ir_ic7e_is_enabled

#define ao_ir_ic7e_is_enabled()     ((IEC2 & _IEC2_IC7EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_ic7e_is_pending

#define ao_ir_ic7e_is_pending()     ((IFS2 & _IFS2_IC7EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_ic7e_reply

#define ao_ir_ic7e_reply()          { IFS2CLR = _IFS2_IC7EIF_MASK; }

#endif

#ifndef ao_ir_ic7e_request

#define ao_ir_ic7e_request()        { IFS2SET = _IFS2_IC7EIF_MASK; }

#endif

#ifndef AO_IR_IC8_ATTRIBUTE

#define AO_IR_IC8_ATTRIBUTE         __ISR(_INPUT_CAPTURE_8_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_IC8_PRIO

#define AO_IR_IC8_PRIO              (4)

#endif

#ifndef AO_IR_IC8_SUBPRIO

#define AO_IR_IC8_SUBPRIO           (0)

#endif

#ifndef ao_ir_ic8_disable

#define ao_ir_ic8_disable()         { IEC2CLR = _IEC2_IC8IE_MASK; }

#endif

#ifndef ao_ir_ic8_enable

#define ao_ir_ic8_enable()          { IEC2SET = _IEC2_IC8IE_MASK; }

#endif

#ifndef ao_ir_ic8_is_enabled

#define ao_ir_ic8_is_enabled()      ((IEC2 & _IEC2_IC8IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ic8_is_pending

#define ao_ir_ic8_is_pending()      ((IFS2 & _IFS2_IC8IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ic8_reply

#define ao_ir_ic8_reply()           { IFS2CLR = _IFS2_IC8IF_MASK; }

#endif

#ifndef ao_ir_ic8_request

#define ao_ir_ic8_request()         { IFS2SET = _IFS2_IC8IF_MASK; }

#endif

#ifndef AO_IR_IC8E_ATTRIBUTE

#define AO_IR_IC8E_ATTRIBUTE        __ISR(_INPUT_CAPTURE_8_ERROR_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_IC8E_PRIO

#define AO_IR_IC8E_PRIO             (4)

#endif

#ifndef AO_IR_IC8E_SUBPRIO

#define AO_IR_IC8E_SUBPRIO          (0)

#endif

#ifndef ao_ir_ic8e_disable

#define ao_ir_ic8e_disable()        { IEC2CLR = _IEC2_IC8EIE_MASK; }

#endif

#ifndef ao_ir_ic8e_enable

#define ao_ir_ic8e_enable()         { IEC2SET = _IEC2_IC8EIE_MASK; }

#endif

#ifndef ao_ir_ic8e_is_enabled

#define ao_ir_ic8e_is_enabled()     ((IEC2 & _IEC2_IC8EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_ic8e_is_pending

#define ao_ir_ic8e_is_pending()     ((IFS2 & _IFS2_IC8EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_ic8e_reply

#define ao_ir_ic8e_reply()          { IFS2CLR = _IFS2_IC8EIF_MASK; }

#endif

#ifndef ao_ir_ic8e_request

#define ao_ir_ic8e_request()        { IFS2SET = _IFS2_IC8EIF_MASK; }

#endif

#ifndef AO_IR_IC9_ATTRIBUTE

#define AO_IR_IC9_ATTRIBUTE         __ISR(_INPUT_CAPTURE_9_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_IC9_PRIO

#define AO_IR_IC9_PRIO              (4)

#endif

#ifndef AO_IR_IC9_SUBPRIO

#define AO_IR_IC9_SUBPRIO           (0)

#endif

#ifndef ao_ir_ic9_disable

#define ao_ir_ic9_disable()         { IEC2CLR = _IEC2_IC9IE_MASK; }

#endif

#ifndef ao_ir_ic9_enable

#define ao_ir_ic9_enable()          { IEC2SET = _IEC2_IC9IE_MASK; }

#endif

#ifndef ao_ir_ic9_is_enabled

#define ao_ir_ic9_is_enabled()      ((IEC2 & _IEC2_IC9IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ic9_is_pending

#define ao_ir_ic9_is_pending()      ((IFS2 & _IFS2_IC9IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ic9_reply

#define ao_ir_ic9_reply()           { IFS2CLR = _IFS2_IC9IF_MASK; }

#endif

#ifndef ao_ir_ic9_request

#define ao_ir_ic9_request()         { IFS2SET = _IFS2_IC9IF_MASK; }

#endif

#ifndef AO_IR_IC9E_ATTRIBUTE

#define AO_IR_IC9E_ATTRIBUTE        __ISR(_INPUT_CAPTURE_9_ERROR_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_IC9E_PRIO

#define AO_IR_IC9E_PRIO             (4)

#endif

#ifndef AO_IR_IC9E_SUBPRIO

#define AO_IR_IC9E_SUBPRIO          (0)

#endif

#ifndef ao_ir_ic9e_disable

#define ao_ir_ic9e_disable()        { IEC2CLR = _IEC2_IC9EIE_MASK; }

#endif

#ifndef ao_ir_ic9e_enable

#define ao_ir_ic9e_enable()         { IEC2SET = _IEC2_IC9EIE_MASK; }

#endif

#ifndef ao_ir_ic9e_is_enabled

#define ao_ir_ic9e_is_enabled()     ((IEC2 & _IEC2_IC9EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_ic9e_is_pending

#define ao_ir_ic9e_is_pending()     ((IFS2 & _IFS2_IC9EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_ic9e_reply

#define ao_ir_ic9e_reply()          { IFS2CLR = _IFS2_IC9EIF_MASK; }

#endif

#ifndef ao_ir_ic9e_request

#define ao_ir_ic9e_request()        { IFS2SET = _IFS2_IC9EIF_MASK; }

#endif

#ifndef AO_IR_IC10_ATTRIBUTE

#define AO_IR_IC10_ATTRIBUTE        __ISR(_INPUT_CAPTURE_10_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_IC10_PRIO

#define AO_IR_IC10_PRIO             (4)

#endif

#ifndef AO_IR_IC10_SUBPRIO

#define AO_IR_IC10_SUBPRIO          (0)

#endif

#ifndef ao_ir_ic10_disable

#define ao_ir_ic10_disable()        { IEC6CLR = _IEC6_IC10IE_MASK; }

#endif

#ifndef ao_ir_ic10_enable

#define ao_ir_ic10_enable()         { IEC6SET = _IEC6_IC10IE_MASK; }

#endif

#ifndef ao_ir_ic10_is_enabled

#define ao_ir_ic10_is_enabled()     ((IEC6 & _IEC6_IC10IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ic10_is_pending

#define ao_ir_ic10_is_pending()     ((IFS6 & _IFS6_IC10IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ic10_reply

#define ao_ir_ic10_reply()          { IFS6CLR = _IFS6_IC10IF_MASK; }

#endif

#ifndef ao_ir_ic10_request

#define ao_ir_ic10_request()        { IFS6SET = _IFS6_IC10IF_MASK; }

#endif

#ifndef AO_IR_IC10E_ATTRIBUTE

#define AO_IR_IC10E_ATTRIBUTE       __ISR(_INPUT_CAPTURE_10_ERROR_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_IC10E_PRIO

#define AO_IR_IC10E_PRIO            (4)

#endif

#ifndef AO_IR_IC10E_SUBPRIO

#define AO_IR_IC10E_SUBPRIO         (0)

#endif

#ifndef ao_ir_ic10e_disable

#define ao_ir_ic10e_disable()       { IEC6CLR = _IEC6_IC10EIE_MASK; }

#endif

#ifndef ao_ir_ic10e_enable

#define ao_ir_ic10e_enable()        { IEC6SET = _IEC6_IC10EIE_MASK; }

#endif

#ifndef ao_ir_ic10e_is_enabled

#define ao_ir_ic10e_is_enabled()    ((IEC6 & _IEC6_IC10EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_ic10e_is_pending

#define ao_ir_ic10e_is_pending()    ((IFS6 & _IFS6_IC10EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_ic10e_reply

#define ao_ir_ic10e_reply()         { IFS6CLR = _IFS6_IC10EIF_MASK; }

#endif

#ifndef ao_ir_ic10e_request

#define ao_ir_ic10e_request()       { IFS6SET = _IFS6_IC10EIF_MASK; }

#endif

#ifndef AO_IR_IC11_ATTRIBUTE

#define AO_IR_IC11_ATTRIBUTE        __ISR(_INPUT_CAPTURE_11_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_IC11_PRIO

#define AO_IR_IC11_PRIO             (4)

#endif

#ifndef AO_IR_IC11_SUBPRIO

#define AO_IR_IC11_SUBPRIO          (0)

#endif

#ifndef ao_ir_ic11_disable

#define ao_ir_ic11_disable()        { IEC6CLR = _IEC6_IC11IE_MASK; }

#endif

#ifndef ao_ir_ic11_enable

#define ao_ir_ic11_enable()         { IEC6SET = _IEC6_IC11IE_MASK; }

#endif

#ifndef ao_ir_ic11_is_enabled

#define ao_ir_ic11_is_enabled()     ((IEC6 & _IEC6_IC11IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ic11_is_pending

#define ao_ir_ic11_is_pending()     ((IFS6 & _IFS6_IC11IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ic11_reply

#define ao_ir_ic11_reply()          { IFS6CLR = _IFS6_IC11IF_MASK; }

#endif

#ifndef ao_ir_ic11_request

#define ao_ir_ic11_request()        { IFS6SET = _IFS6_IC11IF_MASK; }

#endif

#ifndef AO_IR_IC11E_ATTRIBUTE

#define AO_IR_IC11E_ATTRIBUTE       __ISR(_INPUT_CAPTURE_11_ERROR_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_IC11E_PRIO

#define AO_IR_IC11E_PRIO            (4)

#endif

#ifndef AO_IR_IC11E_SUBPRIO

#define AO_IR_IC11E_SUBPRIO         (0)

#endif

#ifndef ao_ir_ic11e_disable

#define ao_ir_ic11e_disable()       { IEC6CLR = _IEC6_IC11EIE_MASK; }

#endif

#ifndef ao_ir_ic11e_enable

#define ao_ir_ic11e_enable()        { IEC6SET = _IEC6_IC11EIE_MASK; }

#endif

#ifndef ao_ir_ic11e_is_enabled

#define ao_ir_ic11e_is_enabled()    ((IEC6 & _IEC6_IC11EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_ic11e_is_pending

#define ao_ir_ic11e_is_pending()    ((IFS6 & _IFS6_IC11EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_ic11e_reply

#define ao_ir_ic11e_reply()         { IFS6CLR = _IFS6_IC11EIF_MASK; }

#endif

#ifndef ao_ir_ic11e_request

#define ao_ir_ic11e_request()       { IFS6SET = _IFS6_IC11EIF_MASK; }

#endif

#ifndef AO_IR_IC12_ATTRIBUTE

#define AO_IR_IC12_ATTRIBUTE        __ISR(_INPUT_CAPTURE_12_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_IC12_PRIO

#define AO_IR_IC12_PRIO             (4)

#endif

#ifndef AO_IR_IC12_SUBPRIO

#define AO_IR_IC12_SUBPRIO          (0)

#endif

#ifndef ao_ir_ic12_disable

#define ao_ir_ic12_disable()        { IEC6CLR = _IEC6_IC12IE_MASK; }

#endif

#ifndef ao_ir_ic12_enable

#define ao_ir_ic12_enable()         { IEC6SET = _IEC6_IC12IE_MASK; }

#endif

#ifndef ao_ir_ic12_is_enabled

#define ao_ir_ic12_is_enabled()     ((IEC6 & _IEC6_IC12IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ic12_is_pending

#define ao_ir_ic12_is_pending()     ((IFS6 & _IFS6_IC12IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ic12_reply

#define ao_ir_ic12_reply()          { IFS6CLR = _IFS6_IC12IF_MASK; }

#endif

#ifndef ao_ir_ic12_request

#define ao_ir_ic12_request()        { IFS6SET = _IFS6_IC12IF_MASK; }

#endif

#ifndef AO_IR_IC12E_ATTRIBUTE

#define AO_IR_IC12E_ATTRIBUTE       __ISR(_INPUT_CAPTURE_12_ERROR_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_IC12E_PRIO

#define AO_IR_IC12E_PRIO            (4)

#endif

#ifndef AO_IR_IC12E_SUBPRIO

#define AO_IR_IC12E_SUBPRIO         (0)

#endif

#ifndef ao_ir_ic12e_disable

#define ao_ir_ic12e_disable()       { IEC6CLR = _IEC6_IC12EIE_MASK; }

#endif

#ifndef ao_ir_ic12e_enable

#define ao_ir_ic12e_enable()        { IEC6SET = _IEC6_IC12EIE_MASK; }

#endif

#ifndef ao_ir_ic12e_is_enabled

#define ao_ir_ic12e_is_enabled()    ((IEC6 & _IEC6_IC12EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_ic12e_is_pending

#define ao_ir_ic12e_is_pending()    ((IFS6 & _IFS6_IC12EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_ic12e_reply

#define ao_ir_ic12e_reply()         { IFS6CLR = _IFS6_IC12EIF_MASK; }

#endif

#ifndef ao_ir_ic12e_request

#define ao_ir_ic12e_request()       { IFS6SET = _IFS6_IC12EIF_MASK; }

#endif

#ifndef AO_IR_IC13_ATTRIBUTE

#define AO_IR_IC13_ATTRIBUTE        __ISR(_INPUT_CAPTURE_13_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_IC13_PRIO

#define AO_IR_IC13_PRIO             (4)

#endif

#ifndef AO_IR_IC13_SUBPRIO

#define AO_IR_IC13_SUBPRIO          (0)

#endif

#ifndef ao_ir_ic13_disable

#define ao_ir_ic13_disable()        { IEC6CLR = _IEC6_IC13IE_MASK; }

#endif

#ifndef ao_ir_ic13_enable

#define ao_ir_ic13_enable()         { IEC6SET = _IEC6_IC13IE_MASK; }

#endif

#ifndef ao_ir_ic13_is_enabled

#define ao_ir_ic13_is_enabled()     ((IEC6 & _IEC6_IC13IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ic13_is_pending

#define ao_ir_ic13_is_pending()     ((IFS6 & _IFS6_IC13IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ic13_reply

#define ao_ir_ic13_reply()          { IFS6CLR = _IFS6_IC13IF_MASK; }

#endif

#ifndef ao_ir_ic13_request

#define ao_ir_ic13_request()        { IFS6SET = _IFS6_IC13IF_MASK; }

#endif

#ifndef AO_IR_IC13E_ATTRIBUTE

#define AO_IR_IC13E_ATTRIBUTE       __ISR(_INPUT_CAPTURE_13_ERROR_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_IC13E_PRIO

#define AO_IR_IC13E_PRIO            (4)

#endif

#ifndef AO_IR_IC13E_SUBPRIO

#define AO_IR_IC13E_SUBPRIO         (0)

#endif

#ifndef ao_ir_ic13e_disable

#define ao_ir_ic13e_disable()       { IEC6CLR = _IEC6_IC13EIE_MASK; }

#endif

#ifndef ao_ir_ic13e_enable

#define ao_ir_ic13e_enable()        { IEC6SET = _IEC6_IC13EIE_MASK; }

#endif

#ifndef ao_ir_ic13e_is_enabled

#define ao_ir_ic13e_is_enabled()    ((IEC6 & _IEC6_IC13EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_ic13e_is_pending

#define ao_ir_ic13e_is_pending()    ((IFS6 & _IFS6_IC13EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_ic13e_reply

#define ao_ir_ic13e_reply()         { IFS6CLR = _IFS6_IC13EIF_MASK; }

#endif

#ifndef ao_ir_ic13e_request

#define ao_ir_ic13e_request()       { IFS6SET = _IFS6_IC13EIF_MASK; }

#endif

#ifndef AO_IR_IC14_ATTRIBUTE

#define AO_IR_IC14_ATTRIBUTE        __ISR(_INPUT_CAPTURE_14_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_IC14_PRIO

#define AO_IR_IC14_PRIO             (4)

#endif

#ifndef AO_IR_IC14_SUBPRIO

#define AO_IR_IC14_SUBPRIO          (0)

#endif

#ifndef ao_ir_ic14_disable

#define ao_ir_ic14_disable()        { IEC6CLR = _IEC6_IC14IE_MASK; }

#endif

#ifndef ao_ir_ic14_enable

#define ao_ir_ic14_enable()         { IEC6SET = _IEC6_IC14IE_MASK; }

#endif

#ifndef ao_ir_ic14_is_enabled

#define ao_ir_ic14_is_enabled()     ((IEC6 & _IEC6_IC14IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ic14_is_pending

#define ao_ir_ic14_is_pending()     ((IFS6 & _IFS6_IC14IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ic14_reply

#define ao_ir_ic14_reply()          { IFS6CLR = _IFS6_IC14IF_MASK; }

#endif

#ifndef ao_ir_ic14_request

#define ao_ir_ic14_request()        { IFS6SET = _IFS6_IC14IF_MASK; }

#endif

#ifndef AO_IR_IC14E_ATTRIBUTE

#define AO_IR_IC14E_ATTRIBUTE       __ISR(_INPUT_CAPTURE_14_ERROR_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_IC14E_PRIO

#define AO_IR_IC14E_PRIO            (4)

#endif

#ifndef AO_IR_IC14E_SUBPRIO

#define AO_IR_IC14E_SUBPRIO         (0)

#endif

#ifndef ao_ir_ic14e_disable

#define ao_ir_ic14e_disable()       { IEC6CLR = _IEC6_IC14EIE_MASK; }

#endif

#ifndef ao_ir_ic14e_enable

#define ao_ir_ic14e_enable()        { IEC6SET = _IEC6_IC14EIE_MASK; }

#endif

#ifndef ao_ir_ic14e_is_enabled

#define ao_ir_ic14e_is_enabled()    ((IEC6 & _IEC6_IC14EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_ic14e_is_pending

#define ao_ir_ic14e_is_pending()    ((IFS6 & _IFS6_IC14EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_ic14e_reply

#define ao_ir_ic14e_reply()         { IFS6CLR = _IFS6_IC14EIF_MASK; }

#endif

#ifndef ao_ir_ic14e_request

#define ao_ir_ic14e_request()       { IFS6SET = _IFS6_IC14EIF_MASK; }

#endif

#ifndef AO_IR_IC15_ATTRIBUTE

#define AO_IR_IC15_ATTRIBUTE        __ISR(_INPUT_CAPTURE_15_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_IC15_PRIO

#define AO_IR_IC15_PRIO             (4)

#endif

#ifndef AO_IR_IC15_SUBPRIO

#define AO_IR_IC15_SUBPRIO          (0)

#endif

#ifndef ao_ir_ic15_disable

#define ao_ir_ic15_disable()        { IEC6CLR = _IEC6_IC15IE_MASK; }

#endif

#ifndef ao_ir_ic15_enable

#define ao_ir_ic15_enable()         { IEC6SET = _IEC6_IC15IE_MASK; }

#endif

#ifndef ao_ir_ic15_is_enabled

#define ao_ir_ic15_is_enabled()     ((IEC6 & _IEC6_IC15IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ic15_is_pending

#define ao_ir_ic15_is_pending()     ((IFS6 & _IFS6_IC15IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ic15_reply

#define ao_ir_ic15_reply()          { IFS6CLR = _IFS6_IC15IF_MASK; }

#endif

#ifndef ao_ir_ic15_request

#define ao_ir_ic15_request()        { IFS6SET = _IFS6_IC15IF_MASK; }

#endif

#ifndef AO_IR_IC15E_ATTRIBUTE

#define AO_IR_IC15E_ATTRIBUTE       __ISR(_INPUT_CAPTURE_15_ERROR_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_IC15E_PRIO

#define AO_IR_IC15E_PRIO            (4)

#endif

#ifndef AO_IR_IC15E_SUBPRIO

#define AO_IR_IC15E_SUBPRIO         (0)

#endif

#ifndef ao_ir_ic15e_disable

#define ao_ir_ic15e_disable()       { IEC6CLR = _IEC6_IC15EIE_MASK; }

#endif

#ifndef ao_ir_ic15e_enable

#define ao_ir_ic15e_enable()        { IEC6SET = _IEC6_IC15EIE_MASK; }

#endif

#ifndef ao_ir_ic15e_is_enabled

#define ao_ir_ic15e_is_enabled()    ((IEC6 & _IEC6_IC15EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_ic15e_is_pending

#define ao_ir_ic15e_is_pending()    ((IFS6 & _IFS6_IC15EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_ic15e_reply

#define ao_ir_ic15e_reply()         { IFS6CLR = _IFS6_IC15EIF_MASK; }

#endif

#ifndef ao_ir_ic15e_request

#define ao_ir_ic15e_request()       { IFS6SET = _IFS6_IC15EIF_MASK; }

#endif

#ifndef AO_IR_IC16_ATTRIBUTE

#define AO_IR_IC16_ATTRIBUTE        __ISR(_INPUT_CAPTURE_16_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_IC16_PRIO

#define AO_IR_IC16_PRIO             (4)

#endif

#ifndef AO_IR_IC16_SUBPRIO

#define AO_IR_IC16_SUBPRIO          (0)

#endif

#ifndef ao_ir_ic16_disable

#define ao_ir_ic16_disable()        { IEC6CLR = _IEC6_IC16IE_MASK; }

#endif

#ifndef ao_ir_ic16_enable

#define ao_ir_ic16_enable()         { IEC6SET = _IEC6_IC16IE_MASK; }

#endif

#ifndef ao_ir_ic16_is_enabled

#define ao_ir_ic16_is_enabled()     ((IEC6 & _IEC6_IC16IE_MASK) ? true : false)

#endif

#ifndef ao_ir_ic16_is_pending

#define ao_ir_ic16_is_pending()     ((IFS6 & _IFS6_IC16IF_MASK) ? true : false)

#endif

#ifndef ao_ir_ic16_reply

#define ao_ir_ic16_reply()          { IFS6CLR = _IFS6_IC16IF_MASK; }

#endif

#ifndef ao_ir_ic16_request

#define ao_ir_ic16_request()        { IFS6SET = _IFS6_IC16IF_MASK; }

#endif

#ifndef AO_IR_IC16E_ATTRIBUTE

#define AO_IR_IC16E_ATTRIBUTE       __ISR(_INPUT_CAPTURE_16_ERROR_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_IC16E_PRIO

#define AO_IR_IC16E_PRIO            (4)

#endif

#ifndef AO_IR_IC16E_SUBPRIO

#define AO_IR_IC16E_SUBPRIO         (0)

#endif

#ifndef ao_ir_ic16e_disable

#define ao_ir_ic16e_disable()       { IEC6CLR = _IEC6_IC16EIE_MASK; }

#endif

#ifndef ao_ir_ic16e_enable

#define ao_ir_ic16e_enable()        { IEC6SET = _IEC6_IC16EIE_MASK; }

#endif

#ifndef ao_ir_ic16e_is_enabled

#define ao_ir_ic16e_is_enabled()    ((IEC6 & _IEC6_IC16EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_ic16e_is_pending

#define ao_ir_ic16e_is_pending()    ((IFS6 & _IFS6_IC16EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_ic16e_reply

#define ao_ir_ic16e_reply()         { IFS6CLR = _IFS6_IC16EIF_MASK; }

#endif

#ifndef ao_ir_ic16e_request

#define ao_ir_ic16e_request()       { IFS6SET = _IFS6_IC16EIF_MASK; }

#endif

```
