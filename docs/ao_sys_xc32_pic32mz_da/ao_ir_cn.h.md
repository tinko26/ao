---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mz_da/ao_ir_cn.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mz_da/ao_ir_cn.h/ 
subtitle: "ao_sys_xc32_pic32mz_da"
title: "ao_ir_cn.h"
toc: true
---

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>

#ifndef AO_IR_CNA_ATTRIBUTE

#define AO_IR_CNA_ATTRIBUTE     __ISR(_CHANGE_NOTICE_A_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_CNA_PRIO

#define AO_IR_CNA_PRIO          (4)

#endif

#ifndef AO_IR_CNA_SUBPRIO

#define AO_IR_CNA_SUBPRIO       (0)

#endif

#ifndef ao_ir_cna_disable

#define ao_ir_cna_disable()     { IEC3CLR = _IEC3_CNAIE_MASK; }

#endif

#ifndef ao_ir_cna_enable

#define ao_ir_cna_enable()      { IEC3SET = _IEC3_CNAIE_MASK; }

#endif

#ifndef ao_ir_cna_is_enabled

#define ao_ir_cna_is_enabled()  ((IEC3 & _IEC3_CNAIE_MASK) ? true : false)

#endif

#ifndef ao_ir_cna_is_pending

#define ao_ir_cna_is_pending()  ((IFS3 & _IFS3_CNAIF_MASK) ? true : false)

#endif

#ifndef ao_ir_cna_reply

#define ao_ir_cna_reply()       { IFS3CLR = _IFS3_CNAIF_MASK; }

#endif

#ifndef ao_ir_cna_request

#define ao_ir_cna_request()     { IFS3SET = _IFS3_CNAIF_MASK; }

#endif

#ifndef AO_IR_CNB_ATTRIBUTE

#define AO_IR_CNB_ATTRIBUTE     __ISR(_CHANGE_NOTICE_B_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_CNB_PRIO

#define AO_IR_CNB_PRIO          (4)

#endif

#ifndef AO_IR_CNB_SUBPRIO

#define AO_IR_CNB_SUBPRIO       (0)

#endif

#ifndef ao_ir_cnb_disable

#define ao_ir_cnb_disable()     { IEC3CLR = _IEC3_CNBIE_MASK; }

#endif

#ifndef ao_ir_cnb_enable

#define ao_ir_cnb_enable()      { IEC3SET = _IEC3_CNBIE_MASK; }

#endif

#ifndef ao_ir_cnb_is_enabled

#define ao_ir_cnb_is_enabled()  ((IEC3 & _IEC3_CNBIE_MASK) ? true : false)

#endif

#ifndef ao_ir_cnb_is_pending

#define ao_ir_cnb_is_pending()  ((IFS3 & _IFS3_CNBIF_MASK) ? true : false)

#endif

#ifndef ao_ir_cnb_reply

#define ao_ir_cnb_reply()       { IFS3CLR = _IFS3_CNBIF_MASK; }

#endif

#ifndef ao_ir_cnb_request

#define ao_ir_cnb_request()     { IFS3SET = _IFS3_CNBIF_MASK; }

#endif

#ifndef AO_IR_CNC_ATTRIBUTE

#define AO_IR_CNC_ATTRIBUTE     __ISR(_CHANGE_NOTICE_C_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_CNC_PRIO

#define AO_IR_CNC_PRIO          (4)

#endif

#ifndef AO_IR_CNC_SUBPRIO

#define AO_IR_CNC_SUBPRIO       (0)

#endif

#ifndef ao_ir_cnc_disable

#define ao_ir_cnc_disable()     { IEC3CLR = _IEC3_CNCIE_MASK; }

#endif

#ifndef ao_ir_cnc_enable

#define ao_ir_cnc_enable()      { IEC3SET = _IEC3_CNCIE_MASK; }

#endif

#ifndef ao_ir_cnc_is_enabled

#define ao_ir_cnc_is_enabled()  ((IEC3 & _IEC3_CNCIE_MASK) ? true : false)

#endif

#ifndef ao_ir_cnc_is_pending

#define ao_ir_cnc_is_pending()  ((IFS3 & _IFS3_CNCIF_MASK) ? true : false)

#endif

#ifndef ao_ir_cnc_reply

#define ao_ir_cnc_reply()       { IFS3CLR = _IFS3_CNCIF_MASK; }

#endif

#ifndef ao_ir_cnc_request

#define ao_ir_cnc_request()     { IFS3SET = _IFS3_CNCIF_MASK; }

#endif

#ifndef AO_IR_CND_ATTRIBUTE

#define AO_IR_CND_ATTRIBUTE     __ISR(_CHANGE_NOTICE_D_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_CND_PRIO

#define AO_IR_CND_PRIO          (4)

#endif

#ifndef AO_IR_CND_SUBPRIO

#define AO_IR_CND_SUBPRIO       (0)

#endif

#ifndef ao_ir_cnd_disable

#define ao_ir_cnd_disable()     { IEC3CLR = _IEC3_CNDIE_MASK; }

#endif

#ifndef ao_ir_cnd_enable

#define ao_ir_cnd_enable()      { IEC3SET = _IEC3_CNDIE_MASK; }

#endif

#ifndef ao_ir_cnd_is_enabled

#define ao_ir_cnd_is_enabled()  ((IEC3 & _IEC3_CNDIE_MASK) ? true : false)

#endif

#ifndef ao_ir_cnd_is_pending

#define ao_ir_cnd_is_pending()  ((IFS3 & _IFS3_CNDIF_MASK) ? true : false)

#endif

#ifndef ao_ir_cnd_reply

#define ao_ir_cnd_reply()       { IFS3CLR = _IFS3_CNDIF_MASK; }

#endif

#ifndef ao_ir_cnd_request

#define ao_ir_cnd_request()     { IFS3SET = _IFS3_CNDIF_MASK; }

#endif

#ifndef AO_IR_CNE_ATTRIBUTE

#define AO_IR_CNE_ATTRIBUTE     __ISR(_CHANGE_NOTICE_E_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_CNE_PRIO

#define AO_IR_CNE_PRIO          (4)

#endif

#ifndef AO_IR_CNE_SUBPRIO

#define AO_IR_CNE_SUBPRIO       (0)

#endif

#ifndef ao_ir_cne_disable

#define ao_ir_cne_disable()     { IEC3CLR = _IEC3_CNEIE_MASK; }

#endif

#ifndef ao_ir_cne_enable

#define ao_ir_cne_enable()      { IEC3SET = _IEC3_CNEIE_MASK; }

#endif

#ifndef ao_ir_cne_is_enabled

#define ao_ir_cne_is_enabled()  ((IEC3 & _IEC3_CNEIE_MASK) ? true : false)

#endif

#ifndef ao_ir_cne_is_pending

#define ao_ir_cne_is_pending()  ((IFS3 & _IFS3_CNEIF_MASK) ? true : false)

#endif

#ifndef ao_ir_cne_reply

#define ao_ir_cne_reply()       { IFS3CLR = _IFS3_CNEIF_MASK; }

#endif

#ifndef ao_ir_cne_request

#define ao_ir_cne_request()     { IFS3SET = _IFS3_CNEIF_MASK; }

#endif

#ifndef AO_IR_CNF_ATTRIBUTE

#define AO_IR_CNF_ATTRIBUTE     __ISR(_CHANGE_NOTICE_F_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_CNF_PRIO

#define AO_IR_CNF_PRIO          (4)

#endif

#ifndef AO_IR_CNF_SUBPRIO

#define AO_IR_CNF_SUBPRIO       (0)

#endif

#ifndef ao_ir_cnf_disable

#define ao_ir_cnf_disable()     { IEC3CLR = _IEC3_CNFIE_MASK; }

#endif

#ifndef ao_ir_cnf_enable

#define ao_ir_cnf_enable()      { IEC3SET = _IEC3_CNFIE_MASK; }

#endif

#ifndef ao_ir_cnf_is_enabled

#define ao_ir_cnf_is_enabled()  ((IEC3 & _IEC3_CNFIE_MASK) ? true : false)

#endif

#ifndef ao_ir_cnf_is_pending

#define ao_ir_cnf_is_pending()  ((IFS3 & _IFS3_CNFIF_MASK) ? true : false)

#endif

#ifndef ao_ir_cnf_reply

#define ao_ir_cnf_reply()       { IFS3CLR = _IFS3_CNFIF_MASK; }

#endif

#ifndef ao_ir_cnf_request

#define ao_ir_cnf_request()     { IFS3SET = _IFS3_CNFIF_MASK; }

#endif

#ifndef AO_IR_CNG_ATTRIBUTE

#define AO_IR_CNG_ATTRIBUTE     __ISR(_CHANGE_NOTICE_G_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_CNG_PRIO

#define AO_IR_CNG_PRIO          (4)

#endif

#ifndef AO_IR_CNG_SUBPRIO

#define AO_IR_CNG_SUBPRIO       (0)

#endif

#ifndef ao_ir_cng_disable

#define ao_ir_cng_disable()     { IEC3CLR = _IEC3_CNGIE_MASK; }

#endif

#ifndef ao_ir_cng_enable

#define ao_ir_cng_enable()      { IEC3SET = _IEC3_CNGIE_MASK; }

#endif

#ifndef ao_ir_cng_is_enabled

#define ao_ir_cng_is_enabled()  ((IEC3 & _IEC3_CNGIE_MASK) ? true : false)

#endif

#ifndef ao_ir_cng_is_pending

#define ao_ir_cng_is_pending()  ((IFS3 & _IFS3_CNGIF_MASK) ? true : false)

#endif

#ifndef ao_ir_cng_reply

#define ao_ir_cng_reply()       { IFS3CLR = _IFS3_CNGIF_MASK; }

#endif

#ifndef ao_ir_cng_request

#define ao_ir_cng_request()     { IFS3SET = _IFS3_CNGIF_MASK; }

#endif

#ifndef AO_IR_CNH_ATTRIBUTE

#define AO_IR_CNH_ATTRIBUTE     __ISR(_CHANGE_NOTICE_H_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_CNH_PRIO

#define AO_IR_CNH_PRIO          (4)

#endif

#ifndef AO_IR_CNH_SUBPRIO

#define AO_IR_CNH_SUBPRIO       (0)

#endif

#ifndef ao_ir_cnh_disable

#define ao_ir_cnh_disable()     { IEC3CLR = _IEC3_CNHIE_MASK; }

#endif

#ifndef ao_ir_cnh_enable

#define ao_ir_cnh_enable()      { IEC3SET = _IEC3_CNHIE_MASK; }

#endif

#ifndef ao_ir_cnh_is_enabled

#define ao_ir_cnh_is_enabled()  ((IEC3 & _IEC3_CNHIE_MASK) ? true : false)

#endif

#ifndef ao_ir_cnh_is_pending

#define ao_ir_cnh_is_pending()  ((IFS3 & _IFS3_CNHIF_MASK) ? true : false)

#endif

#ifndef ao_ir_cnh_reply

#define ao_ir_cnh_reply()       { IFS3CLR = _IFS3_CNHIF_MASK; }

#endif

#ifndef ao_ir_cnh_request

#define ao_ir_cnh_request()     { IFS3SET = _IFS3_CNHIF_MASK; }

#endif

#ifndef AO_IR_CNJ_ATTRIBUTE

#define AO_IR_CNJ_ATTRIBUTE     __ISR(_CHANGE_NOTICE_J_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_CNJ_PRIO

#define AO_IR_CNJ_PRIO          (4)

#endif

#ifndef AO_IR_CNJ_SUBPRIO

#define AO_IR_CNJ_SUBPRIO       (0)

#endif

#ifndef ao_ir_cnj_disable

#define ao_ir_cnj_disable()     { IEC3CLR = _IEC3_CNJIE_MASK; }

#endif

#ifndef ao_ir_cnj_enable

#define ao_ir_cnj_enable()      { IEC3SET = _IEC3_CNJIE_MASK; }

#endif

#ifndef ao_ir_cnj_is_enabled

#define ao_ir_cnj_is_enabled()  ((IEC3 & _IEC3_CNJIE_MASK) ? true : false)

#endif

#ifndef ao_ir_cnj_is_pending

#define ao_ir_cnj_is_pending()  ((IFS3 & _IFS3_CNJIF_MASK) ? true : false)

#endif

#ifndef ao_ir_cnj_reply

#define ao_ir_cnj_reply()       { IFS3CLR = _IFS3_CNJIF_MASK; }

#endif

#ifndef ao_ir_cnj_request

#define ao_ir_cnj_request()     { IFS3SET = _IFS3_CNJIF_MASK; }

#endif

#ifndef AO_IR_CNK_ATTRIBUTE

#define AO_IR_CNK_ATTRIBUTE     __ISR(_CHANGE_NOTICE_K_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_CNK_PRIO

#define AO_IR_CNK_PRIO          (4)

#endif

#ifndef AO_IR_CNK_SUBPRIO

#define AO_IR_CNK_SUBPRIO       (0)

#endif

#ifndef ao_ir_cnk_disable

#define ao_ir_cnk_disable()     { IEC3CLR = _IEC3_CNKIE_MASK; }

#endif

#ifndef ao_ir_cnk_enable

#define ao_ir_cnk_enable()      { IEC3SET = _IEC3_CNKIE_MASK; }

#endif

#ifndef ao_ir_cnk_is_enabled

#define ao_ir_cnk_is_enabled()  ((IEC3 & _IEC3_CNKIE_MASK) ? true : false)

#endif

#ifndef ao_ir_cnk_is_pending

#define ao_ir_cnk_is_pending()  ((IFS3 & _IFS3_CNKIF_MASK) ? true : false)

#endif

#ifndef ao_ir_cnk_reply

#define ao_ir_cnk_reply()       { IFS3CLR = _IFS3_CNKIF_MASK; }

#endif

#ifndef ao_ir_cnk_request

#define ao_ir_cnk_request()     { IFS3SET = _IFS3_CNKIF_MASK; }

#endif

```
