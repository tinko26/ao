---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mk_gp/ao_ir_spi.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mk_gp/ao_ir_spi.h/ 
subtitle: "<code>ao_sys_xc32_pic32mk_gp</code>"
title: "<code>ao_ir_spi.h</code>"
toc: true
---

#ifndef AO_IR_SPI1E_ATTRIBUTE

#define AO_IR_SPI1E_ATTRIBUTE       __ISR(_SPI1_FAULT_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_SPI1E_PRIO

#define AO_IR_SPI1E_PRIO            (4)

#endif

#ifndef AO_IR_SPI1E_SUBPRIO

#define AO_IR_SPI1E_SUBPRIO         (0)

#endif

#ifndef ao_ir_spi1e_disable

#define ao_ir_spi1e_disable()       { IEC1CLR = _IEC1_SPI1EIE_MASK; }

#endif

#ifndef ao_ir_spi1e_enable

#define ao_ir_spi1e_enable()        { IEC1SET = _IEC1_SPI1EIE_MASK; }

#endif

#ifndef ao_ir_spi1e_is_enabled

#define ao_ir_spi1e_is_enabled()    ((IEC1 & _IEC1_SPI1EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_spi1e_is_pending

#define ao_ir_spi1e_is_pending()    ((IFS1 & _IFS1_SPI1EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_spi1e_reply

#define ao_ir_spi1e_reply()         { IFS1CLR = _IFS1_SPI1EIF_MASK; }

#endif

#ifndef ao_ir_spi1e_request

#define ao_ir_spi1e_request()       { IFS1SET = _IFS1_SPI1EIF_MASK; }

#endif

#ifndef AO_IR_SPI1RX_ATTRIBUTE

#define AO_IR_SPI1RX_ATTRIBUTE      __ISR(_SPI1_RX_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_SPI1RX_PRIO

#define AO_IR_SPI1RX_PRIO           (4)

#endif

#ifndef AO_IR_SPI1RX_SUBPRIO

#define AO_IR_SPI1RX_SUBPRIO        (0)

#endif

#ifndef ao_ir_spi1rx_disable

#define ao_ir_spi1rx_disable()      { IEC1CLR = _IEC1_SPI1RXIE_MASK; }

#endif

#ifndef ao_ir_spi1rx_enable

#define ao_ir_spi1rx_enable()       { IEC1SET = _IEC1_SPI1RXIE_MASK; }

#endif

#ifndef ao_ir_spi1rx_is_enabled

#define ao_ir_spi1rx_is_enabled()   ((IEC1 & _IEC1_SPI1RXIE_MASK) ? true : false)

#endif

#ifndef ao_ir_spi1rx_is_pending

#define ao_ir_spi1rx_is_pending()   ((IFS1 & _IFS1_SPI1RXIF_MASK) ? true : false)

#endif

#ifndef ao_ir_spi1rx_reply

#define ao_ir_spi1rx_reply()        { IFS1CLR = _IFS1_SPI1RXIF_MASK; }

#endif

#ifndef ao_ir_spi1rx_request

#define ao_ir_spi1rx_request()      { IFS1SET = _IFS1_SPI1RXIF_MASK; }

#endif

#ifndef AO_IR_SPI1TX_ATTRIBUTE

#define AO_IR_SPI1TX_ATTRIBUTE      __ISR(_SPI1_TX_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_SPI1TX_PRIO

#define AO_IR_SPI1TX_PRIO           (4)

#endif

#ifndef AO_IR_SPI1TX_SUBPRIO

#define AO_IR_SPI1TX_SUBPRIO        (0)

#endif

#ifndef ao_ir_spi1tx_disable

#define ao_ir_spi1tx_disable()      { IEC1CLR = _IEC1_SPI1TXIE_MASK; }

#endif

#ifndef ao_ir_spi1tx_enable

#define ao_ir_spi1tx_enable()       { IEC1SET = _IEC1_SPI1TXIE_MASK; }

#endif

#ifndef ao_ir_spi1tx_is_enabled

#define ao_ir_spi1tx_is_enabled()   ((IEC1 & _IEC1_SPI1TXIE_MASK) ? true : false)

#endif

#ifndef ao_ir_spi1tx_is_pending

#define ao_ir_spi1tx_is_pending()   ((IFS1 & _IFS1_SPI1TXIF_MASK) ? true : false)

#endif

#ifndef ao_ir_spi1tx_reply

#define ao_ir_spi1tx_reply()        { IFS1CLR = _IFS1_SPI1TXIF_MASK; }

#endif

#ifndef ao_ir_spi1tx_request

#define ao_ir_spi1tx_request()      { IFS1SET = _IFS1_SPI1TXIF_MASK; }

#endif

#ifndef AO_IR_SPI2E_ATTRIBUTE

#define AO_IR_SPI2E_ATTRIBUTE       __ISR(_SPI2_FAULT_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_SPI2E_PRIO

#define AO_IR_SPI2E_PRIO            (4)

#endif

#ifndef AO_IR_SPI2E_SUBPRIO

#define AO_IR_SPI2E_SUBPRIO         (0)

#endif

#ifndef ao_ir_spi2e_disable

#define ao_ir_spi2e_disable()       { IEC1CLR = _IEC1_SPI2EIE_MASK; }

#endif

#ifndef ao_ir_spi2e_enable

#define ao_ir_spi2e_enable()        { IEC1SET = _IEC1_SPI2EIE_MASK; }

#endif

#ifndef ao_ir_spi2e_is_enabled

#define ao_ir_spi2e_is_enabled()    ((IEC1 & _IEC1_SPI2EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_spi2e_is_pending

#define ao_ir_spi2e_is_pending()    ((IFS1 & _IFS1_SPI2EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_spi2e_reply

#define ao_ir_spi2e_reply()         { IFS1CLR = _IFS1_SPI2EIF_MASK; }

#endif

#ifndef ao_ir_spi2e_request

#define ao_ir_spi2e_request()       { IFS1SET = _IFS1_SPI2EIF_MASK; }

#endif

#ifndef AO_IR_SPI2RX_ATTRIBUTE

#define AO_IR_SPI2RX_ATTRIBUTE      __ISR(_SPI2_RX_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_SPI2RX_PRIO

#define AO_IR_SPI2RX_PRIO           (4)

#endif

#ifndef AO_IR_SPI2RX_SUBPRIO

#define AO_IR_SPI2RX_SUBPRIO        (0)

#endif

#ifndef ao_ir_spi2rx_disable

#define ao_ir_spi2rx_disable()      { IEC1CLR = _IEC1_SPI2RXIE_MASK; }

#endif

#ifndef ao_ir_spi2rx_enable

#define ao_ir_spi2rx_enable()       { IEC1SET = _IEC1_SPI2RXIE_MASK; }

#endif

#ifndef ao_ir_spi2rx_is_enabled

#define ao_ir_spi2rx_is_enabled()   ((IEC1 & _IEC1_SPI2RXIE_MASK) ? true : false)

#endif

#ifndef ao_ir_spi2rx_is_pending

#define ao_ir_spi2rx_is_pending()   ((IFS1 & _IFS1_SPI2RXIF_MASK) ? true : false)

#endif

#ifndef ao_ir_spi2rx_reply

#define ao_ir_spi2rx_reply()        { IFS1CLR = _IFS1_SPI2RXIF_MASK; }

#endif

#ifndef ao_ir_spi2rx_request

#define ao_ir_spi2rx_request()      { IFS1SET = _IFS1_SPI2RXIF_MASK; }

#endif

#ifndef AO_IR_SPI2TX_ATTRIBUTE

#define AO_IR_SPI2TX_ATTRIBUTE      __ISR(_SPI2_TX_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_SPI2TX_PRIO

#define AO_IR_SPI2TX_PRIO           (4)

#endif

#ifndef AO_IR_SPI2TX_SUBPRIO

#define AO_IR_SPI2TX_SUBPRIO        (0)

#endif

#ifndef ao_ir_spi2tx_disable

#define ao_ir_spi2tx_disable()      { IEC1CLR = _IEC1_SPI2TXIE_MASK; }

#endif

#ifndef ao_ir_spi2tx_enable

#define ao_ir_spi2tx_enable()       { IEC1SET = _IEC1_SPI2TXIE_MASK; }

#endif

#ifndef ao_ir_spi2tx_is_enabled

#define ao_ir_spi2tx_is_enabled()   ((IEC1 & _IEC1_SPI2TXIE_MASK) ? true : false)

#endif

#ifndef ao_ir_spi2tx_is_pending

#define ao_ir_spi2tx_is_pending()   ((IFS1 & _IFS1_SPI2TXIF_MASK) ? true : false)

#endif

#ifndef ao_ir_spi2tx_reply

#define ao_ir_spi2tx_reply()        { IFS1CLR = _IFS1_SPI2TXIF_MASK; }

#endif

#ifndef ao_ir_spi2tx_request

#define ao_ir_spi2tx_request()      { IFS1SET = _IFS1_SPI2TXIF_MASK; }

#endif

#ifndef AO_IR_SPI3E_ATTRIBUTE

#define AO_IR_SPI3E_ATTRIBUTE       __ISR(_SPI3_FAULT_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_SPI3E_PRIO

#define AO_IR_SPI3E_PRIO            (4)

#endif

#ifndef AO_IR_SPI3E_SUBPRIO

#define AO_IR_SPI3E_SUBPRIO         (0)

#endif

#ifndef ao_ir_spi3e_disable

#define ao_ir_spi3e_disable()       { IEC6CLR = _IEC6_SPI3EIE_MASK; }

#endif

#ifndef ao_ir_spi3e_enable

#define ao_ir_spi3e_enable()        { IEC6SET = _IEC6_SPI3EIE_MASK; }

#endif

#ifndef ao_ir_spi3e_is_enabled

#define ao_ir_spi3e_is_enabled()    ((IEC6 & _IEC6_SPI3EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_spi3e_is_pending

#define ao_ir_spi3e_is_pending()    ((IFS6 & _IFS6_SPI3EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_spi3e_reply

#define ao_ir_spi3e_reply()         { IFS6CLR = _IFS6_SPI3EIF_MASK; }

#endif

#ifndef ao_ir_spi3e_request

#define ao_ir_spi3e_request()       { IFS6SET = _IFS6_SPI3EIF_MASK; }

#endif

#ifndef AO_IR_SPI3RX_ATTRIBUTE

#define AO_IR_SPI3RX_ATTRIBUTE      __ISR(_SPI3_RX_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_SPI3RX_PRIO

#define AO_IR_SPI3RX_PRIO           (4)

#endif

#ifndef AO_IR_SPI3RX_SUBPRIO

#define AO_IR_SPI3RX_SUBPRIO        (0)

#endif

#ifndef ao_ir_spi3rx_disable

#define ao_ir_spi3rx_disable()      { IEC6CLR = _IEC6_SPI3RXIE_MASK; }

#endif

#ifndef ao_ir_spi3rx_enable

#define ao_ir_spi3rx_enable()       { IEC6SET = _IEC6_SPI3RXIE_MASK; }

#endif

#ifndef ao_ir_spi3rx_is_enabled

#define ao_ir_spi3rx_is_enabled()   ((IEC6 & _IEC6_SPI3RXIE_MASK) ? true : false)

#endif

#ifndef ao_ir_spi3rx_is_pending

#define ao_ir_spi3rx_is_pending()   ((IFS6 & _IFS6_SPI3RXIF_MASK) ? true : false)

#endif

#ifndef ao_ir_spi3rx_reply

#define ao_ir_spi3rx_reply()        { IFS6CLR = _IFS6_SPI3RXIF_MASK; }

#endif

#ifndef ao_ir_spi3rx_request

#define ao_ir_spi3rx_request()      { IFS6SET = _IFS6_SPI3RXIF_MASK; }

#endif

#ifndef AO_IR_SPI3TX_ATTRIBUTE

#define AO_IR_SPI3TX_ATTRIBUTE      __ISR(_SPI3_TX_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_SPI3TX_PRIO

#define AO_IR_SPI3TX_PRIO           (4)

#endif

#ifndef AO_IR_SPI3TX_SUBPRIO

#define AO_IR_SPI3TX_SUBPRIO        (0)

#endif

#ifndef ao_ir_spi3tx_disable

#define ao_ir_spi3tx_disable()      { IEC6CLR = _IEC6_SPI3TXIE_MASK; }

#endif

#ifndef ao_ir_spi3tx_enable

#define ao_ir_spi3tx_enable()       { IEC6SET = _IEC6_SPI3TXIE_MASK; }

#endif

#ifndef ao_ir_spi3tx_is_enabled

#define ao_ir_spi3tx_is_enabled()   ((IEC6 & _IEC6_SPI3TXIE_MASK) ? true : false)

#endif

#ifndef ao_ir_spi3tx_is_pending

#define ao_ir_spi3tx_is_pending()   ((IFS6 & _IFS6_SPI3TXIF_MASK) ? true : false)

#endif

#ifndef ao_ir_spi3tx_reply

#define ao_ir_spi3tx_reply()        { IFS6CLR = _IFS6_SPI3TXIF_MASK; }

#endif

#ifndef ao_ir_spi3tx_request

#define ao_ir_spi3tx_request()      { IFS6SET = _IFS6_SPI3TXIF_MASK; }

#endif

#ifndef AO_IR_SPI4E_ATTRIBUTE

#define AO_IR_SPI4E_ATTRIBUTE       __ISR(_SPI4_FAULT_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_SPI4E_PRIO

#define AO_IR_SPI4E_PRIO            (4)

#endif

#ifndef AO_IR_SPI4E_SUBPRIO

#define AO_IR_SPI4E_SUBPRIO         (0)

#endif

#ifndef ao_ir_spi4e_disable

#define ao_ir_spi4e_disable()       { IEC6CLR = _IEC6_SPI4EIE_MASK; }

#endif

#ifndef ao_ir_spi4e_enable

#define ao_ir_spi4e_enable()        { IEC6SET = _IEC6_SPI4EIE_MASK; }

#endif

#ifndef ao_ir_spi4e_is_enabled

#define ao_ir_spi4e_is_enabled()    ((IEC6 & _IEC6_SPI4EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_spi4e_is_pending

#define ao_ir_spi4e_is_pending()    ((IFS6 & _IFS6_SPI4EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_spi4e_reply

#define ao_ir_spi4e_reply()         { IFS6CLR = _IFS6_SPI4EIF_MASK; }

#endif

#ifndef ao_ir_spi4e_request

#define ao_ir_spi4e_request()       { IFS6SET = _IFS6_SPI4EIF_MASK; }

#endif

#ifndef AO_IR_SPI4RX_ATTRIBUTE

#define AO_IR_SPI4RX_ATTRIBUTE      __ISR(_SPI4_RX_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_SPI4RX_PRIO

#define AO_IR_SPI4RX_PRIO           (4)

#endif

#ifndef AO_IR_SPI4RX_SUBPRIO

#define AO_IR_SPI4RX_SUBPRIO        (0)

#endif

#ifndef ao_ir_spi4rx_disable

#define ao_ir_spi4rx_disable()      { IEC6CLR = _IEC6_SPI4RXIE_MASK; }

#endif

#ifndef ao_ir_spi4rx_enable

#define ao_ir_spi4rx_enable()       { IEC6SET = _IEC6_SPI4RXIE_MASK; }

#endif

#ifndef ao_ir_spi4rx_is_enabled

#define ao_ir_spi4rx_is_enabled()   ((IEC6 & _IEC6_SPI4RXIE_MASK) ? true : false)

#endif

#ifndef ao_ir_spi4rx_is_pending

#define ao_ir_spi4rx_is_pending()   ((IFS6 & _IFS6_SPI4RXIF_MASK) ? true : false)

#endif

#ifndef ao_ir_spi4rx_reply

#define ao_ir_spi4rx_reply()        { IFS6CLR = _IFS6_SPI4RXIF_MASK; }

#endif

#ifndef ao_ir_spi4rx_request

#define ao_ir_spi4rx_request()      { IFS6SET = _IFS6_SPI4RXIF_MASK; }

#endif

#ifndef AO_IR_SPI4TX_ATTRIBUTE

#define AO_IR_SPI4TX_ATTRIBUTE      __ISR(_SPI4_TX_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_SPI4TX_PRIO

#define AO_IR_SPI4TX_PRIO           (4)

#endif

#ifndef AO_IR_SPI4TX_SUBPRIO

#define AO_IR_SPI4TX_SUBPRIO        (0)

#endif

#ifndef ao_ir_spi4tx_disable

#define ao_ir_spi4tx_disable()      { IEC6CLR = _IEC6_SPI4TXIE_MASK; }

#endif

#ifndef ao_ir_spi4tx_enable

#define ao_ir_spi4tx_enable()       { IEC6SET = _IEC6_SPI4TXIE_MASK; }

#endif

#ifndef ao_ir_spi4tx_is_enabled

#define ao_ir_spi4tx_is_enabled()   ((IEC6 & _IEC6_SPI4TXIE_MASK) ? true : false)

#endif

#ifndef ao_ir_spi4tx_is_pending

#define ao_ir_spi4tx_is_pending()   ((IFS6 & _IFS6_SPI4TXIF_MASK) ? true : false)

#endif

#ifndef ao_ir_spi4tx_reply

#define ao_ir_spi4tx_reply()        { IFS6CLR = _IFS6_SPI4TXIF_MASK; }

#endif

#ifndef ao_ir_spi4tx_request

#define ao_ir_spi4tx_request()      { IFS6SET = _IFS6_SPI4TXIF_MASK; }

#endif

#ifndef AO_IR_SPI5E_ATTRIBUTE

#define AO_IR_SPI5E_ATTRIBUTE       __ISR(_SPI5_FAULT_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_SPI5E_PRIO

#define AO_IR_SPI5E_PRIO            (4)

#endif

#ifndef AO_IR_SPI5E_SUBPRIO

#define AO_IR_SPI5E_SUBPRIO         (0)

#endif

#ifndef ao_ir_spi5e_disable

#define ao_ir_spi5e_disable()       { IEC7CLR = _IEC7_SPI5EIE_MASK; }

#endif

#ifndef ao_ir_spi5e_enable

#define ao_ir_spi5e_enable()        { IEC7SET = _IEC7_SPI5EIE_MASK; }

#endif

#ifndef ao_ir_spi5e_is_enabled

#define ao_ir_spi5e_is_enabled()    ((IEC7 & _IEC7_SPI5EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_spi5e_is_pending

#define ao_ir_spi5e_is_pending()    ((IFS7 & _IFS7_SPI5EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_spi5e_reply

#define ao_ir_spi5e_reply()         { IFS7CLR = _IFS7_SPI5EIF_MASK; }

#endif

#ifndef ao_ir_spi5e_request

#define ao_ir_spi5e_request()       { IFS7SET = _IFS7_SPI5EIF_MASK; }

#endif

#ifndef AO_IR_SPI5RX_ATTRIBUTE

#define AO_IR_SPI5RX_ATTRIBUTE      __ISR(_SPI5_RX_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_SPI5RX_PRIO

#define AO_IR_SPI5RX_PRIO           (4)

#endif

#ifndef AO_IR_SPI5RX_SUBPRIO

#define AO_IR_SPI5RX_SUBPRIO        (0)

#endif

#ifndef ao_ir_spi5rx_disable

#define ao_ir_spi5rx_disable()      { IEC7CLR = _IEC7_SPI5RXIE_MASK; }

#endif

#ifndef ao_ir_spi5rx_enable

#define ao_ir_spi5rx_enable()       { IEC7SET = _IEC7_SPI5RXIE_MASK; }

#endif

#ifndef ao_ir_spi5rx_is_enabled

#define ao_ir_spi5rx_is_enabled()   ((IEC7 & _IEC7_SPI5RXIE_MASK) ? true : false)

#endif

#ifndef ao_ir_spi5rx_is_pending

#define ao_ir_spi5rx_is_pending()   ((IFS7 & _IFS7_SPI5RXIF_MASK) ? true : false)

#endif

#ifndef ao_ir_spi5rx_reply

#define ao_ir_spi5rx_reply()        { IFS7CLR = _IFS7_SPI5RXIF_MASK; }

#endif

#ifndef ao_ir_spi5rx_request

#define ao_ir_spi5rx_request()      { IFS7SET = _IFS7_SPI5RXIF_MASK; }

#endif

#ifndef AO_IR_SPI5TX_ATTRIBUTE

#define AO_IR_SPI5TX_ATTRIBUTE      __ISR(_SPI5_TX_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_SPI5TX_PRIO

#define AO_IR_SPI5TX_PRIO           (4)

#endif

#ifndef AO_IR_SPI5TX_SUBPRIO

#define AO_IR_SPI5TX_SUBPRIO        (0)

#endif

#ifndef ao_ir_spi5tx_disable

#define ao_ir_spi5tx_disable()      { IEC7CLR = _IEC7_SPI5TXIE_MASK; }

#endif

#ifndef ao_ir_spi5tx_enable

#define ao_ir_spi5tx_enable()       { IEC7SET = _IEC7_SPI5TXIE_MASK; }

#endif

#ifndef ao_ir_spi5tx_is_enabled

#define ao_ir_spi5tx_is_enabled()   ((IEC7 & _IEC7_SPI5TXIE_MASK) ? true : false)

#endif

#ifndef ao_ir_spi5tx_is_pending

#define ao_ir_spi5tx_is_pending()   ((IFS7 & _IFS7_SPI5TXIF_MASK) ? true : false)

#endif

#ifndef ao_ir_spi5tx_reply

#define ao_ir_spi5tx_reply()        { IFS7CLR = _IFS7_SPI5TXIF_MASK; }

#endif

#ifndef ao_ir_spi5tx_request

#define ao_ir_spi5tx_request()      { IFS7SET = _IFS7_SPI5TXIF_MASK; }

#endif

#ifndef AO_IR_SPI6E_ATTRIBUTE

#define AO_IR_SPI6E_ATTRIBUTE       __ISR(_SPI6_FAULT_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_SPI6E_PRIO

#define AO_IR_SPI6E_PRIO            (4)

#endif

#ifndef AO_IR_SPI6E_SUBPRIO

#define AO_IR_SPI6E_SUBPRIO         (0)

#endif

#ifndef ao_ir_spi6e_disable

#define ao_ir_spi6e_disable()       { IEC7CLR = _IEC7_SPI6EIE_MASK; }

#endif

#ifndef ao_ir_spi6e_enable

#define ao_ir_spi6e_enable()        { IEC7SET = _IEC7_SPI6EIE_MASK; }

#endif

#ifndef ao_ir_spi6e_is_enabled

#define ao_ir_spi6e_is_enabled()    ((IEC7 & _IEC7_SPI6EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_spi6e_is_pending

#define ao_ir_spi6e_is_pending()    ((IFS7 & _IFS7_SPI6EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_spi6e_reply

#define ao_ir_spi6e_reply()         { IFS7CLR = _IFS7_SPI6EIF_MASK; }

#endif

#ifndef ao_ir_spi6e_request

#define ao_ir_spi6e_request()       { IFS7SET = _IFS7_SPI6EIF_MASK; }

#endif

#ifndef AO_IR_SPI6RX_ATTRIBUTE

#define AO_IR_SPI6RX_ATTRIBUTE      __ISR(_SPI6_RX_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_SPI6RX_PRIO

#define AO_IR_SPI6RX_PRIO           (4)

#endif

#ifndef AO_IR_SPI6RX_SUBPRIO

#define AO_IR_SPI6RX_SUBPRIO        (0)

#endif

#ifndef ao_ir_spi6rx_disable

#define ao_ir_spi6rx_disable()      { IEC7CLR = _IEC7_SPI6RXIE_MASK; }

#endif

#ifndef ao_ir_spi6rx_enable

#define ao_ir_spi6rx_enable()       { IEC7SET = _IEC7_SPI6RXIE_MASK; }

#endif

#ifndef ao_ir_spi6rx_is_enabled

#define ao_ir_spi6rx_is_enabled()   ((IEC7 & _IEC7_SPI6RXIE_MASK) ? true : false)

#endif

#ifndef ao_ir_spi6rx_is_pending

#define ao_ir_spi6rx_is_pending()   ((IFS7 & _IFS7_SPI6RXIF_MASK) ? true : false)

#endif

#ifndef ao_ir_spi6rx_reply

#define ao_ir_spi6rx_reply()        { IFS7CLR = _IFS7_SPI6RXIF_MASK; }

#endif

#ifndef ao_ir_spi6rx_request

#define ao_ir_spi6rx_request()      { IFS7SET = _IFS7_SPI6RXIF_MASK; }

#endif

#ifndef AO_IR_SPI6TX_ATTRIBUTE

#define AO_IR_SPI6TX_ATTRIBUTE      __ISR(_SPI6_TX_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_SPI6TX_PRIO

#define AO_IR_SPI6TX_PRIO           (4)

#endif

#ifndef AO_IR_SPI6TX_SUBPRIO

#define AO_IR_SPI6TX_SUBPRIO        (0)

#endif

#ifndef ao_ir_spi6tx_disable

#define ao_ir_spi6tx_disable()      { IEC7CLR = _IEC7_SPI6TXIE_MASK; }

#endif

#ifndef ao_ir_spi6tx_enable

#define ao_ir_spi6tx_enable()       { IEC7SET = _IEC7_SPI6TXIE_MASK; }

#endif

#ifndef ao_ir_spi6tx_is_enabled

#define ao_ir_spi6tx_is_enabled()   ((IEC7 & _IEC7_SPI6TXIE_MASK) ? true : false)

#endif

#ifndef ao_ir_spi6tx_is_pending

#define ao_ir_spi6tx_is_pending()   ((IFS7 & _IFS7_SPI6TXIF_MASK) ? true : false)

#endif

#ifndef ao_ir_spi6tx_reply

#define ao_ir_spi6tx_reply()        { IFS7CLR = _IFS7_SPI6TXIF_MASK; }

#endif

#ifndef ao_ir_spi6tx_request

#define ao_ir_spi6tx_request()      { IFS7SET = _IFS7_SPI6TXIF_MASK; }

#endif

