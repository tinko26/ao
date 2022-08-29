---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mx_3xx/ao_ir_u.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mx_3xx/ao_ir_u.h/ 
subtitle: ""
title: "ao_ir_u.h"
toc: true
---

# Overview

...

# Includes

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

#ifndef AO_IR_U1_ATTRIBUTE

#define AO_IR_U1_ATTRIBUTE          __ISR(_UART_1_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_U1_PRIO

#define AO_IR_U1_PRIO               (4)

#endif

#ifndef AO_IR_U1_SUBPRIO

#define AO_IR_U1_SUBPRIO            (0)

#endif

#ifndef ao_ir_u1e_disable

#define ao_ir_u1e_disable()         { IEC0CLR = _IEC0_U1EIE_MASK; }

#endif

#ifndef ao_ir_u1e_enable

#define ao_ir_u1e_enable()          { IEC0SET = _IEC0_U1EIE_MASK; }

#endif

#ifndef ao_ir_u1e_is_enabled

#define ao_ir_u1e_is_enabled()      ((IEC0 & _IEC0_U1EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_u1e_is_pending

#define ao_ir_u1e_is_pending()      ((IFS0 & _IFS0_U1EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_u1e_reply

#define ao_ir_u1e_reply()           { IFS0CLR = _IFS0_U1EIF_MASK; }

#endif

#ifndef ao_ir_u1e_request

#define ao_ir_u1e_request()         { IFS0SET = _IFS0_U1EIF_MASK; }

#endif

#ifndef ao_ir_u1rx_disable

#define ao_ir_u1rx_disable()        { IEC0CLR = _IEC0_U1RXIE_MASK; }

#endif

#ifndef ao_ir_u1rx_enable

#define ao_ir_u1rx_enable()         { IEC0SET = _IEC0_U1RXIE_MASK; }

#endif

#ifndef ao_ir_u1rx_is_enabled

#define ao_ir_u1rx_is_enabled()     ((IEC0 & _IEC0_U1RXIE_MASK) ? true : false)

#endif

#ifndef ao_ir_u1rx_is_pending

#define ao_ir_u1rx_is_pending()     ((IFS0 & _IFS0_U1RXIF_MASK) ? true : false)

#endif

#ifndef ao_ir_u1rx_reply

#define ao_ir_u1rx_reply()          { IFS0CLR = _IFS0_U1RXIF_MASK; }

#endif

#ifndef ao_ir_u1rx_request

#define ao_ir_u1rx_request()        { IFS0SET = _IFS0_U1RXIF_MASK; }

#endif

#ifndef ao_ir_u1tx_disable

#define ao_ir_u1tx_disable()        { IEC0CLR = _IEC0_U1TXIE_MASK; }

#endif

#ifndef ao_ir_u1tx_enable

#define ao_ir_u1tx_enable()         { IEC0SET = _IEC0_U1TXIE_MASK; }

#endif

#ifndef ao_ir_u1tx_is_enabled

#define ao_ir_u1tx_is_enabled()     ((IEC0 & _IEC0_U1TXIE_MASK) ? true : false)

#endif

#ifndef ao_ir_u1tx_is_pending

#define ao_ir_u1tx_is_pending()     ((IFS0 & _IFS0_U1TXIF_MASK) ? true : false)

#endif

#ifndef ao_ir_u1tx_reply

#define ao_ir_u1tx_reply()          { IFS0CLR = _IFS0_U1TXIF_MASK; }

#endif

#ifndef ao_ir_u1tx_request

#define ao_ir_u1tx_request()        { IFS0SET = _IFS0_U1TXIF_MASK; }

#endif

#ifndef AO_IR_U2_ATTRIBUTE

#define AO_IR_U2_ATTRIBUTE          __ISR(_UART_2_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_U2_PRIO

#define AO_IR_U2_PRIO               (4)

#endif

#ifndef AO_IR_U2_SUBPRIO

#define AO_IR_U2_SUBPRIO            (0)

#endif

#ifndef ao_ir_u2e_disable

#define ao_ir_u2e_disable()         { IEC1CLR = _IEC1_U2EIE_MASK; }

#endif

#ifndef ao_ir_u2e_enable

#define ao_ir_u2e_enable()          { IEC1SET = _IEC1_U2EIE_MASK; }

#endif

#ifndef ao_ir_u2e_is_enabled

#define ao_ir_u2e_is_enabled()      ((IEC1 & _IEC1_U2EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_u2e_is_pending

#define ao_ir_u2e_is_pending()      ((IFS1 & _IFS1_U2EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_u2e_reply

#define ao_ir_u2e_reply()           { IFS1CLR = _IFS1_U2EIF_MASK; }

#endif

#ifndef ao_ir_u2e_request

#define ao_ir_u2e_request()         { IFS1SET = _IFS1_U2EIF_MASK; }

#endif

#ifndef ao_ir_u2rx_disable

#define ao_ir_u2rx_disable()        { IEC1CLR = _IEC1_U2RXIE_MASK; }

#endif

#ifndef ao_ir_u2rx_enable

#define ao_ir_u2rx_enable()         { IEC1SET = _IEC1_U2RXIE_MASK; }

#endif

#ifndef ao_ir_u2rx_is_enabled

#define ao_ir_u2rx_is_enabled()     ((IEC1 & _IEC1_U2RXIE_MASK) ? true : false)

#endif

#ifndef ao_ir_u2rx_is_pending

#define ao_ir_u2rx_is_pending()     ((IFS1 & _IFS1_U2RXIF_MASK) ? true : false)

#endif

#ifndef ao_ir_u2rx_reply

#define ao_ir_u2rx_reply()          { IFS1CLR = _IFS1_U2RXIF_MASK; }

#endif

#ifndef ao_ir_u2rx_request

#define ao_ir_u2rx_request()        { IFS1SET = _IFS1_U2RXIF_MASK; }

#endif

#ifndef ao_ir_u2tx_disable

#define ao_ir_u2tx_disable()        { IEC1CLR = _IEC1_U2TXIE_MASK; }

#endif

#ifndef ao_ir_u2tx_enable

#define ao_ir_u2tx_enable()         { IEC1SET = _IEC1_U2TXIE_MASK; }

#endif

#ifndef ao_ir_u2tx_is_enabled

#define ao_ir_u2tx_is_enabled()     ((IEC1 & _IEC1_U2TXIE_MASK) ? true : false)

#endif

#ifndef ao_ir_u2tx_is_pending

#define ao_ir_u2tx_is_pending()     ((IFS1 & _IFS1_U2TXIF_MASK) ? true : false)

#endif

#ifndef ao_ir_u2tx_reply

#define ao_ir_u2tx_reply()          { IFS1CLR = _IFS1_U2TXIF_MASK; }

#endif

#ifndef ao_ir_u2tx_request

#define ao_ir_u2tx_request()        { IFS1SET = _IFS1_U2TXIF_MASK; }

#endif

```
