---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32mx_1xx_64_100/ao_ir_spi.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mx_1xx_64_100/ao_ir_spi.h/ 
subtitle: "<code>ao_sys_xc32_pic32mx_1xx_64_100</code>"
title: "<code>ao_ir_spi.h</code>"
toc: true
---

#ifndef AO_IR_SPI1_ATTRIBUTE

#define AO_IR_SPI1_ATTRIBUTE        __ISR(_SPI_1_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_SPI1_PRIO

#define AO_IR_SPI1_PRIO             (4)

#endif

#ifndef AO_IR_SPI1_SUBPRIO

#define AO_IR_SPI1_SUBPRIO          (0)

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

#ifndef AO_IR_SPI2_ATTRIBUTE

#define AO_IR_SPI2_ATTRIBUTE        __ISR(_SPI_2_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_SPI2_PRIO

#define AO_IR_SPI2_PRIO             (4)

#endif

#ifndef AO_IR_SPI2_SUBPRIO

#define AO_IR_SPI2_SUBPRIO          (0)

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

#ifndef AO_IR_SPI3_ATTRIBUTE

#define AO_IR_SPI3_ATTRIBUTE        __ISR(_SPI_3_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_SPI3_PRIO

#define AO_IR_SPI3_PRIO             (4)

#endif

#ifndef AO_IR_SPI3_SUBPRIO

#define AO_IR_SPI3_SUBPRIO          (0)

#endif

#ifndef ao_ir_spi3e_disable

#define ao_ir_spi3e_disable()       { IEC2CLR = _IEC2_SPI3EIE_MASK; }

#endif

#ifndef ao_ir_spi3e_enable

#define ao_ir_spi3e_enable()        { IEC2SET = _IEC2_SPI3EIE_MASK; }

#endif

#ifndef ao_ir_spi3e_is_enabled

#define ao_ir_spi3e_is_enabled()    ((IEC2 & _IEC2_SPI3EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_spi3e_is_pending

#define ao_ir_spi3e_is_pending()    ((IFS2 & _IFS2_SPI3EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_spi3e_reply

#define ao_ir_spi3e_reply()         { IFS2CLR = _IFS2_SPI3EIF_MASK; }

#endif

#ifndef ao_ir_spi3e_request

#define ao_ir_spi3e_request()       { IFS2SET = _IFS2_SPI3EIF_MASK; }

#endif

#ifndef ao_ir_spi3rx_disable

#define ao_ir_spi3rx_disable()      { IEC2CLR = _IEC2_SPI3RXIE_MASK; }

#endif

#ifndef ao_ir_spi3rx_enable

#define ao_ir_spi3rx_enable()       { IEC2SET = _IEC2_SPI3RXIE_MASK; }

#endif

#ifndef ao_ir_spi3rx_is_enabled

#define ao_ir_spi3rx_is_enabled()   ((IEC2 & _IEC2_SPI3RXIE_MASK) ? true : false)

#endif

#ifndef ao_ir_spi3rx_is_pending

#define ao_ir_spi3rx_is_pending()   ((IFS2 & _IFS2_SPI3RXIF_MASK) ? true : false)

#endif

#ifndef ao_ir_spi3rx_reply

#define ao_ir_spi3rx_reply()        { IFS2CLR = _IFS2_SPI3RXIF_MASK; }

#endif

#ifndef ao_ir_spi3rx_request

#define ao_ir_spi3rx_request()      { IFS2SET = _IFS2_SPI3RXIF_MASK; }

#endif

#ifndef ao_ir_spi3tx_disable

#define ao_ir_spi3tx_disable()      { IEC2CLR = _IEC2_SPI3TXIE_MASK; }

#endif

#ifndef ao_ir_spi3tx_enable

#define ao_ir_spi3tx_enable()       { IEC2SET = _IEC2_SPI3TXIE_MASK; }

#endif

#ifndef ao_ir_spi3tx_is_enabled

#define ao_ir_spi3tx_is_enabled()   ((IEC2 & _IEC2_SPI3TXIE_MASK) ? true : false)

#endif

#ifndef ao_ir_spi3tx_is_pending

#define ao_ir_spi3tx_is_pending()   ((IFS2 & _IFS2_SPI3TXIF_MASK) ? true : false)

#endif

#ifndef ao_ir_spi3tx_reply

#define ao_ir_spi3tx_reply()        { IFS2CLR = _IFS2_SPI3TXIF_MASK; }

#endif

#ifndef ao_ir_spi3tx_request

#define ao_ir_spi3tx_request()      { IFS2SET = _IFS2_SPI3TXIF_MASK; }

#endif

#ifndef AO_IR_SPI4_ATTRIBUTE

#define AO_IR_SPI4_ATTRIBUTE        __ISR(_SPI_4_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_SPI4_PRIO

#define AO_IR_SPI4_PRIO             (4)

#endif

#ifndef AO_IR_SPI4_SUBPRIO

#define AO_IR_SPI4_SUBPRIO          (0)

#endif

#ifndef ao_ir_spi4e_disable

#define ao_ir_spi4e_disable()       { IEC2CLR = _IEC2_SPI4EIE_MASK; }

#endif

#ifndef ao_ir_spi4e_enable

#define ao_ir_spi4e_enable()        { IEC2SET = _IEC2_SPI4EIE_MASK; }

#endif

#ifndef ao_ir_spi4e_is_enabled

#define ao_ir_spi4e_is_enabled()    ((IEC2 & _IEC2_SPI4EIE_MASK) ? true : false)

#endif

#ifndef ao_ir_spi4e_is_pending

#define ao_ir_spi4e_is_pending()    ((IFS2 & _IFS2_SPI4EIF_MASK) ? true : false)

#endif

#ifndef ao_ir_spi4e_reply

#define ao_ir_spi4e_reply()         { IFS2CLR = _IFS2_SPI4EIF_MASK; }

#endif

#ifndef ao_ir_spi4e_request

#define ao_ir_spi4e_request()       { IFS2SET = _IFS2_SPI4EIF_MASK; }

#endif

#ifndef ao_ir_spi4rx_disable

#define ao_ir_spi4rx_disable()      { IEC2CLR = _IEC2_SPI4RXIE_MASK; }

#endif

#ifndef ao_ir_spi4rx_enable

#define ao_ir_spi4rx_enable()       { IEC2SET = _IEC2_SPI4RXIE_MASK; }

#endif

#ifndef ao_ir_spi4rx_is_enabled

#define ao_ir_spi4rx_is_enabled()   ((IEC2 & _IEC2_SPI4RXIE_MASK) ? true : false)

#endif

#ifndef ao_ir_spi4rx_is_pending

#define ao_ir_spi4rx_is_pending()   ((IFS2 & _IFS2_SPI4RXIF_MASK) ? true : false)

#endif

#ifndef ao_ir_spi4rx_reply

#define ao_ir_spi4rx_reply()        { IFS2CLR = _IFS2_SPI4RXIF_MASK; }

#endif

#ifndef ao_ir_spi4rx_request

#define ao_ir_spi4rx_request()      { IFS2SET = _IFS2_SPI4RXIF_MASK; }

#endif

#ifndef ao_ir_spi4tx_disable

#define ao_ir_spi4tx_disable()      { IEC2CLR = _IEC2_SPI4TXIE_MASK; }

#endif

#ifndef ao_ir_spi4tx_enable

#define ao_ir_spi4tx_enable()       { IEC2SET = _IEC2_SPI4TXIE_MASK; }

#endif

#ifndef ao_ir_spi4tx_is_enabled

#define ao_ir_spi4tx_is_enabled()   ((IEC2 & _IEC2_SPI4TXIE_MASK) ? true : false)

#endif

#ifndef ao_ir_spi4tx_is_pending

#define ao_ir_spi4tx_is_pending()   ((IFS2 & _IFS2_SPI4TXIF_MASK) ? true : false)

#endif

#ifndef ao_ir_spi4tx_reply

#define ao_ir_spi4tx_reply()        { IFS2CLR = _IFS2_SPI4TXIF_MASK; }

#endif

#ifndef ao_ir_spi4tx_request

#define ao_ir_spi4tx_request()      { IFS2SET = _IFS2_SPI4TXIF_MASK; }

#endif

