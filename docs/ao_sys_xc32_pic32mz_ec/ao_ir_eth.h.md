---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mz_ec/ao_ir_eth.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mz_ec/ao_ir_eth.h/ 
subtitle: "<code>ao_sys_xc32_pic32mz_ec</code>"
title: "<code>ao_ir_eth.h</code>"
toc: true
---

#ifndef AO_IR_ETH_ATTRIBUTE

#define AO_IR_ETH_ATTRIBUTE     __ISR(_ETHERNET_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_ETH_PRIO

#define AO_IR_ETH_PRIO          (4)

#endif

#ifndef AO_IR_ETH_SUBPRIO

#define AO_IR_ETH_SUBPRIO       (0)

#endif

#ifndef ao_ir_eth_disable

#define ao_ir_eth_disable()     { IEC4CLR = _IEC4_ETHIE_MASK; }

#endif

#ifndef ao_ir_eth_enable

#define ao_ir_eth_enable()      { IEC4SET = _IEC4_ETHIE_MASK; }

#endif

#ifndef ao_ir_eth_is_enabled

#define ao_ir_eth_is_enabled()  ((IEC4 & _IEC4_ETHIE_MASK) ? true : false)

#endif

#ifndef ao_ir_eth_is_pending

#define ao_ir_eth_is_pending()  ((IFS4 & _IFS4_ETHIF_MASK) ? true : false)

#endif

#ifndef ao_ir_eth_reply

#define ao_ir_eth_reply()       { IFS4CLR = _IFS4_ETHIF_MASK; }

#endif

#ifndef ao_ir_eth_request

#define ao_ir_eth_request()     { IFS4SET = _IFS4_ETHIF_MASK; }

#endif

