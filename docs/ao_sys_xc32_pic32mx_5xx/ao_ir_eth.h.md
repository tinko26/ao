---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mx_5xx/ao_ir_eth.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mx_5xx/ao_ir_eth.h/ 
subtitle: "<code>ao_sys_xc32_pic32mx_5xx</code>"
title: "<code>ao_ir_eth.h</code>"
toc: true
---

#ifndef AO_IR_ETH_ATTRIBUTE

#define AO_IR_ETH_ATTRIBUTE     __ISR(_ETH_VECTOR, IPL4SOFT)

#endif

#ifndef AO_IR_ETH_PRIO

#define AO_IR_ETH_PRIO          (4)

#endif

#ifndef AO_IR_ETH_SUBPRIO

#define AO_IR_ETH_SUBPRIO       (0)

#endif

#ifndef ao_ir_eth_disable

#define ao_ir_eth_disable()     { IEC1CLR = _IEC1_ETHIE_MASK; }

#endif

#ifndef ao_ir_eth_enable

#define ao_ir_eth_enable()      { IEC1SET = _IEC1_ETHIE_MASK; }

#endif

#ifndef ao_ir_eth_is_enabled

#define ao_ir_eth_is_enabled()  ((IEC1 & _IEC1_ETHIE_MASK) ? true : false)

#endif

#ifndef ao_ir_eth_is_pending

#define ao_ir_eth_is_pending()  ((IFS1 & _IFS1_ETHIF_MASK) ? true : false)

#endif

#ifndef ao_ir_eth_reply

#define ao_ir_eth_reply()       { IFS1CLR = _IFS1_ETHIF_MASK; }

#endif

#ifndef ao_ir_eth_request

#define ao_ir_eth_request()     { IFS1SET = _IFS1_ETHIF_MASK; }

#endif

