---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32mx_5xx/ao_ir_u.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mx_5xx/ao_ir_u.h/ 
subtitle: "<code>ao_sys_xc32_pic32mx_5xx</code>"
title: "<code>ao_ir_u.h</code>"
toc: true
---

```c
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

#ifndef AO_IR_U3_ATTRIBUTE

#define AO_IR_U3_ATTRIBUTE          __ISR(_UART_3_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_U3_PRIO

#define AO_IR_U3_PRIO               (4)

#endif

#ifndef AO_IR_U3_SUBPRIO

#define AO_IR_U3_SUBPRIO            (0)

#endif

#ifndef ao_ir_u3e_disable

#define ao_ir_u3e_disable()         { IEC1CLR = _IEC1_U3EIE_MASK; }

#endif

#ifndef ao_ir_u3e_enable

#define ao_ir_u3e_enable()          { IEC1SET = _IEC1_U3EIE_MASK; }

#endif

#ifndef ao_ir_u3e_is_enabled

#define ao_ir_u3e_is_enabled()      ((IEC1 & _IEC1_U3EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_u3e_is_pending

#define ao_ir_u3e_is_pending()      ((IFS1 & _IFS1_U3EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_u3e_reply

#define ao_ir_u3e_reply()           { IFS1CLR = _IFS1_U3EIF_MASK; }

#endif

#ifndef ao_ir_u3e_request

#define ao_ir_u3e_request()         { IFS1SET = _IFS1_U3EIF_MASK; }

#endif

#ifndef ao_ir_u3rx_disable

#define ao_ir_u3rx_disable()        { IEC1CLR = _IEC1_U3RXIE_MASK; }

#endif

#ifndef ao_ir_u3rx_enable

#define ao_ir_u3rx_enable()         { IEC1SET = _IEC1_U3RXIE_MASK; }

#endif

#ifndef ao_ir_u3rx_is_enabled

#define ao_ir_u3rx_is_enabled()     ((IEC1 & _IEC1_U3RXIE_MASK) ? true : false)

#endif

#ifndef ao_ir_u3rx_is_pending

#define ao_ir_u3rx_is_pending()     ((IFS1 & _IFS1_U3RXIF_MASK) ? true : false)

#endif

#ifndef ao_ir_u3rx_reply

#define ao_ir_u3rx_reply()          { IFS1CLR = _IFS1_U3RXIF_MASK; }

#endif

#ifndef ao_ir_u3rx_request

#define ao_ir_u3rx_request()        { IFS1SET = _IFS1_U3RXIF_MASK; }

#endif

#ifndef ao_ir_u3tx_disable

#define ao_ir_u3tx_disable()        { IEC1CLR = _IEC1_U3TXIE_MASK; }

#endif

#ifndef ao_ir_u3tx_enable

#define ao_ir_u3tx_enable()         { IEC1SET = _IEC1_U3TXIE_MASK; }

#endif

#ifndef ao_ir_u3tx_is_enabled

#define ao_ir_u3tx_is_enabled()     ((IEC1 & _IEC1_U3TXIE_MASK) ? true : false)

#endif

#ifndef ao_ir_u3tx_is_pending

#define ao_ir_u3tx_is_pending()     ((IFS1 & _IFS1_U3TXIF_MASK) ? true : false)

#endif

#ifndef ao_ir_u3tx_reply

#define ao_ir_u3tx_reply()          { IFS1CLR = _IFS1_U3TXIF_MASK; }

#endif

#ifndef ao_ir_u3tx_request

#define ao_ir_u3tx_request()        { IFS1SET = _IFS1_U3TXIF_MASK; }

#endif

#ifndef AO_IR_U4_ATTRIBUTE

#define AO_IR_U4_ATTRIBUTE          __ISR(_UART_4_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_U4_PRIO

#define AO_IR_U4_PRIO               (4)

#endif

#ifndef AO_IR_U4_SUBPRIO

#define AO_IR_U4_SUBPRIO            (0)

#endif

#ifndef ao_ir_u4e_disable

#define ao_ir_u4e_disable()         { IEC2CLR = _IEC2_U4EIE_MASK; }

#endif

#ifndef ao_ir_u4e_enable

#define ao_ir_u4e_enable()          { IEC2SET = _IEC2_U4EIE_MASK; }

#endif

#ifndef ao_ir_u4e_is_enabled

#define ao_ir_u4e_is_enabled()      ((IEC2 & _IEC2_U4EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_u4e_is_pending

#define ao_ir_u4e_is_pending()      ((IFS2 & _IFS2_U4EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_u4e_reply

#define ao_ir_u4e_reply()           { IFS2CLR = _IFS2_U4EIF_MASK; }

#endif

#ifndef ao_ir_u4e_request

#define ao_ir_u4e_request()         { IFS2SET = _IFS2_U4EIF_MASK; }

#endif

#ifndef ao_ir_u4rx_disable

#define ao_ir_u4rx_disable()        { IEC2CLR = _IEC2_U4RXIE_MASK; }

#endif

#ifndef ao_ir_u4rx_enable

#define ao_ir_u4rx_enable()         { IEC2SET = _IEC2_U4RXIE_MASK; }

#endif

#ifndef ao_ir_u4rx_is_enabled

#define ao_ir_u4rx_is_enabled()     ((IEC2 & _IEC2_U4RXIE_MASK) ? true : false)

#endif

#ifndef ao_ir_u4rx_is_pending

#define ao_ir_u4rx_is_pending()     ((IFS2 & _IFS2_U4RXIF_MASK) ? true : false)

#endif

#ifndef ao_ir_u4rx_reply

#define ao_ir_u4rx_reply()          { IFS2CLR = _IFS2_U4RXIF_MASK; }

#endif

#ifndef ao_ir_u4rx_request

#define ao_ir_u4rx_request()        { IFS2SET = _IFS2_U4RXIF_MASK; }

#endif

#ifndef ao_ir_u4tx_disable

#define ao_ir_u4tx_disable()        { IEC2CLR = _IEC2_U4TXIE_MASK; }

#endif

#ifndef ao_ir_u4tx_enable

#define ao_ir_u4tx_enable()         { IEC2SET = _IEC2_U4TXIE_MASK; }

#endif

#ifndef ao_ir_u4tx_is_enabled

#define ao_ir_u4tx_is_enabled()     ((IEC2 & _IEC2_U4TXIE_MASK) ? true : false)

#endif

#ifndef ao_ir_u4tx_is_pending

#define ao_ir_u4tx_is_pending()     ((IFS2 & _IFS2_U4TXIF_MASK) ? true : false)

#endif

#ifndef ao_ir_u4tx_reply

#define ao_ir_u4tx_reply()          { IFS2CLR = _IFS2_U4TXIF_MASK; }

#endif

#ifndef ao_ir_u4tx_request

#define ao_ir_u4tx_request()        { IFS2SET = _IFS2_U4TXIF_MASK; }

#endif

#ifndef AO_IR_U5_ATTRIBUTE

#define AO_IR_U5_ATTRIBUTE          __ISR(_UART_5_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_U5_PRIO

#define AO_IR_U5_PRIO               (4)

#endif

#ifndef AO_IR_U5_SUBPRIO

#define AO_IR_U5_SUBPRIO            (0)

#endif

#ifndef ao_ir_u5e_disable

#define ao_ir_u5e_disable()         { IEC2CLR = _IEC2_U5EIE_MASK; }

#endif

#ifndef ao_ir_u5e_enable

#define ao_ir_u5e_enable()          { IEC2SET = _IEC2_U5EIE_MASK; }

#endif

#ifndef ao_ir_u5e_is_enabled

#define ao_ir_u5e_is_enabled()      ((IEC2 & _IEC2_U5EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_u5e_is_pending

#define ao_ir_u5e_is_pending()      ((IFS2 & _IFS2_U5EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_u5e_reply

#define ao_ir_u5e_reply()           { IFS2CLR = _IFS2_U5EIF_MASK; }

#endif

#ifndef ao_ir_u5e_request

#define ao_ir_u5e_request()         { IFS2SET = _IFS2_U5EIF_MASK; }

#endif

#ifndef ao_ir_u5rx_disable

#define ao_ir_u5rx_disable()        { IEC2CLR = _IEC2_U5RXIE_MASK; }

#endif

#ifndef ao_ir_u5rx_enable

#define ao_ir_u5rx_enable()         { IEC2SET = _IEC2_U5RXIE_MASK; }

#endif

#ifndef ao_ir_u5rx_is_enabled

#define ao_ir_u5rx_is_enabled()     ((IEC2 & _IEC2_U5RXIE_MASK) ? true : false)

#endif

#ifndef ao_ir_u5rx_is_pending

#define ao_ir_u5rx_is_pending()     ((IFS2 & _IFS2_U5RXIF_MASK) ? true : false)

#endif

#ifndef ao_ir_u5rx_reply

#define ao_ir_u5rx_reply()          { IFS2CLR = _IFS2_U5RXIF_MASK; }

#endif

#ifndef ao_ir_u5rx_request

#define ao_ir_u5rx_request()        { IFS2SET = _IFS2_U5RXIF_MASK; }

#endif

#ifndef ao_ir_u5tx_disable

#define ao_ir_u5tx_disable()        { IEC2CLR = _IEC2_U5TXIE_MASK; }

#endif

#ifndef ao_ir_u5tx_enable

#define ao_ir_u5tx_enable()         { IEC2SET = _IEC2_U5TXIE_MASK; }

#endif

#ifndef ao_ir_u5tx_is_enabled

#define ao_ir_u5tx_is_enabled()     ((IEC2 & _IEC2_U5TXIE_MASK) ? true : false)

#endif

#ifndef ao_ir_u5tx_is_pending

#define ao_ir_u5tx_is_pending()     ((IFS2 & _IFS2_U5TXIF_MASK) ? true : false)

#endif

#ifndef ao_ir_u5tx_reply

#define ao_ir_u5tx_reply()          { IFS2CLR = _IFS2_U5TXIF_MASK; }

#endif

#ifndef ao_ir_u5tx_request

#define ao_ir_u5tx_request()        { IFS2SET = _IFS2_U5TXIF_MASK; }

#endif

#ifndef AO_IR_U6_ATTRIBUTE

#define AO_IR_U6_ATTRIBUTE          __ISR(_UART_6_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_U6_PRIO

#define AO_IR_U6_PRIO               (4)

#endif

#ifndef AO_IR_U6_SUBPRIO

#define AO_IR_U6_SUBPRIO            (0)

#endif

#ifndef ao_ir_u6e_disable

#define ao_ir_u6e_disable()         { IEC2CLR = _IEC2_U6EIE_MASK; }

#endif

#ifndef ao_ir_u6e_enable

#define ao_ir_u6e_enable()          { IEC2SET = _IEC2_U6EIE_MASK; }

#endif

#ifndef ao_ir_u6e_is_enabled

#define ao_ir_u6e_is_enabled()      ((IEC2 & _IEC2_U6EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_u6e_is_pending

#define ao_ir_u6e_is_pending()      ((IFS2 & _IFS2_U6EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_u6e_reply

#define ao_ir_u6e_reply()           { IFS2CLR = _IFS2_U6EIF_MASK; }

#endif

#ifndef ao_ir_u6e_request

#define ao_ir_u6e_request()         { IFS2SET = _IFS2_U6EIF_MASK; }

#endif

#ifndef ao_ir_u6rx_disable

#define ao_ir_u6rx_disable()        { IEC2CLR = _IEC2_U6RXIE_MASK; }

#endif

#ifndef ao_ir_u6rx_enable

#define ao_ir_u6rx_enable()         { IEC2SET = _IEC2_U6RXIE_MASK; }

#endif

#ifndef ao_ir_u6rx_is_enabled

#define ao_ir_u6rx_is_enabled()     ((IEC2 & _IEC2_U6RXIE_MASK) ? true : false)

#endif

#ifndef ao_ir_u6rx_is_pending

#define ao_ir_u6rx_is_pending()     ((IFS2 & _IFS2_U6RXIF_MASK) ? true : false)

#endif

#ifndef ao_ir_u6rx_reply

#define ao_ir_u6rx_reply()          { IFS2CLR = _IFS2_U6RXIF_MASK; }

#endif

#ifndef ao_ir_u6rx_request

#define ao_ir_u6rx_request()        { IFS2SET = _IFS2_U6RXIF_MASK; }

#endif

#ifndef ao_ir_u6tx_disable

#define ao_ir_u6tx_disable()        { IEC2CLR = _IEC2_U6TXIE_MASK; }

#endif

#ifndef ao_ir_u6tx_enable

#define ao_ir_u6tx_enable()         { IEC2SET = _IEC2_U6TXIE_MASK; }

#endif

#ifndef ao_ir_u6tx_is_enabled

#define ao_ir_u6tx_is_enabled()     ((IEC2 & _IEC2_U6TXIE_MASK) ? true : false)

#endif

#ifndef ao_ir_u6tx_is_pending

#define ao_ir_u6tx_is_pending()     ((IFS2 & _IFS2_U6TXIF_MASK) ? true : false)

#endif

#ifndef ao_ir_u6tx_reply

#define ao_ir_u6tx_reply()          { IFS2CLR = _IFS2_U6TXIF_MASK; }

#endif

#ifndef ao_ir_u6tx_request

#define ao_ir_u6tx_request()        { IFS2SET = _IFS2_U6TXIF_MASK; }

#endif

```
