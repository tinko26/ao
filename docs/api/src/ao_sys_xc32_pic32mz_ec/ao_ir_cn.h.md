---
api: true
author: "Stefan Wagner"
date: 2022-09-05
description: "The /src/ao_sys_xc32_pic32mz_ec/ao_ir_cn.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz_ec/ao_ir_cn.h/
subtitle: "Change notification interrupts"
title: "ao_ir_cn.h"
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Configuration

## `AO_IR_CNA`

The interrupt handler attribute.

```c
#define AO_IR_CNA_ATTRIBUTE __ISR(_CHANGE_NOTICE_A_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_CNA_PRIO      (4)
#define AO_IR_CNA_SUBPRIO   (0)
```

## `AO_IR_CNB`

The interrupt handler attribute.

```c
#define AO_IR_CNB_ATTRIBUTE __ISR(_CHANGE_NOTICE_B_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_CNB_PRIO      (4)
#define AO_IR_CNB_SUBPRIO   (0)
```

## `AO_IR_CNC`

The interrupt handler attribute.

```c
#define AO_IR_CNC_ATTRIBUTE __ISR(_CHANGE_NOTICE_C_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_CNC_PRIO      (4)
#define AO_IR_CNC_SUBPRIO   (0)
```

## `AO_IR_CND`

The interrupt handler attribute.

```c
#define AO_IR_CND_ATTRIBUTE __ISR(_CHANGE_NOTICE_D_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_CND_PRIO      (4)
#define AO_IR_CND_SUBPRIO   (0)
```

## `AO_IR_CNE`

The interrupt handler attribute.

```c
#define AO_IR_CNE_ATTRIBUTE __ISR(_CHANGE_NOTICE_E_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_CNE_PRIO      (4)
#define AO_IR_CNE_SUBPRIO   (0)
```

## `AO_IR_CNF`

The interrupt handler attribute.

```c
#define AO_IR_CNF_ATTRIBUTE __ISR(_CHANGE_NOTICE_F_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_CNF_PRIO      (4)
#define AO_IR_CNF_SUBPRIO   (0)
```

## `AO_IR_CNG`

The interrupt handler attribute.

```c
#define AO_IR_CNG_ATTRIBUTE __ISR(_CHANGE_NOTICE_G_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_CNG_PRIO      (4)
#define AO_IR_CNG_SUBPRIO   (0)
```

## `AO_IR_CNH`

The interrupt handler attribute.

```c
#define AO_IR_CNH_ATTRIBUTE __ISR(_CHANGE_NOTICE_H_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_CNH_PRIO      (4)
#define AO_IR_CNH_SUBPRIO   (0)
```

## `AO_IR_CNJ`

The interrupt handler attribute.

```c
#define AO_IR_CNJ_ATTRIBUTE __ISR(_CHANGE_NOTICE_J_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_CNJ_PRIO      (4)
#define AO_IR_CNJ_SUBPRIO   (0)
```

## `AO_IR_CNK`

The interrupt handler attribute.

```c
#define AO_IR_CNK_ATTRIBUTE __ISR(_CHANGE_NOTICE_K_VECTOR, IPL4SRS)
```

The interrupt priority and subpriority.

```c
#define AO_IR_CNK_PRIO      (4)
#define AO_IR_CNK_SUBPRIO   (0)
```

# Functions

## `ao_ir_cna`

Enable or disable the interrupt.

```c
#define ao_ir_cna_enable()
#define ao_ir_cna_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_cna_request()
#define ao_ir_cna_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_cna_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_cna_is_pending()
```

## `ao_ir_cnb`

Enable or disable the interrupt.

```c
#define ao_ir_cnb_enable()
#define ao_ir_cnb_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_cnb_request()
#define ao_ir_cnb_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_cnb_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_cnb_is_pending()
```

## `ao_ir_cnc`

Enable or disable the interrupt.

```c
#define ao_ir_cnc_enable()
#define ao_ir_cnc_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_cnc_request()
#define ao_ir_cnc_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_cnc_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_cnc_is_pending()
```

## `ao_ir_cnd`

Enable or disable the interrupt.

```c
#define ao_ir_cnd_enable()
#define ao_ir_cnd_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_cnd_request()
#define ao_ir_cnd_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_cnd_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_cnd_is_pending()
```

## `ao_ir_cne`

Enable or disable the interrupt.

```c
#define ao_ir_cne_enable()
#define ao_ir_cne_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_cne_request()
#define ao_ir_cne_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_cne_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_cne_is_pending()
```

## `ao_ir_cnf`

Enable or disable the interrupt.

```c
#define ao_ir_cnf_enable()
#define ao_ir_cnf_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_cnf_request()
#define ao_ir_cnf_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_cnf_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_cnf_is_pending()
```

## `ao_ir_cng`

Enable or disable the interrupt.

```c
#define ao_ir_cng_enable()
#define ao_ir_cng_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_cng_request()
#define ao_ir_cng_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_cng_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_cng_is_pending()
```

## `ao_ir_cnh`

Enable or disable the interrupt.

```c
#define ao_ir_cnh_enable()
#define ao_ir_cnh_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_cnh_request()
#define ao_ir_cnh_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_cnh_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_cnh_is_pending()
```

## `ao_ir_cnj`

Enable or disable the interrupt.

```c
#define ao_ir_cnj_enable()
#define ao_ir_cnj_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_cnj_request()
#define ao_ir_cnj_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_cnj_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_cnj_is_pending()
```

## `ao_ir_cnk`

Enable or disable the interrupt.

```c
#define ao_ir_cnk_enable()
#define ao_ir_cnk_disable()
```

Request the interrupt or reply thereto.

```c
#define ao_ir_cnk_request()
#define ao_ir_cnk_reply()
```

Check whether the interrupt is enabled.

```c
#define ao_ir_cnk_is_enabled()
```

Check whether the interrupt is pending.

```c
#define ao_ir_cnk_is_pending()
```
