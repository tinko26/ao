---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mz_dak/ao_ir_cn.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32_pic32mz_dak/ao_ir_cn.h/
subtitle: ""
title: "ao_ir_cn.h"
toc: true
---

# Include

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

# Constants

```c
#define AO_IR_CNA_ATTRIBUTE __ISR(_CHANGE_NOTICE_A_VECTOR, IPL4SRS)
```

```c
#define AO_IR_CNA_PRIO (4)
```

```c
#define AO_IR_CNA_SUBPRIO (0)
```

```c
#define AO_IR_CNB_ATTRIBUTE __ISR(_CHANGE_NOTICE_B_VECTOR, IPL4SRS)
```

```c
#define AO_IR_CNB_PRIO (4)
```

```c
#define AO_IR_CNB_SUBPRIO (0)
```

```c
#define AO_IR_CNC_ATTRIBUTE __ISR(_CHANGE_NOTICE_C_VECTOR, IPL4SRS)
```

```c
#define AO_IR_CNC_PRIO (4)
```

```c
#define AO_IR_CNC_SUBPRIO (0)
```

```c
#define AO_IR_CND_ATTRIBUTE __ISR(_CHANGE_NOTICE_D_VECTOR, IPL4SRS)
```

```c
#define AO_IR_CND_PRIO (4)
```

```c
#define AO_IR_CND_SUBPRIO (0)
```

```c
#define AO_IR_CNE_ATTRIBUTE __ISR(_CHANGE_NOTICE_E_VECTOR, IPL4SRS)
```

```c
#define AO_IR_CNE_PRIO (4)
```

```c
#define AO_IR_CNE_SUBPRIO (0)
```

```c
#define AO_IR_CNF_ATTRIBUTE __ISR(_CHANGE_NOTICE_F_VECTOR, IPL4SRS)
```

```c
#define AO_IR_CNF_PRIO (4)
```

```c
#define AO_IR_CNF_SUBPRIO (0)
```

```c
#define AO_IR_CNG_ATTRIBUTE __ISR(_CHANGE_NOTICE_G_VECTOR, IPL4SRS)
```

```c
#define AO_IR_CNG_PRIO (4)
```

```c
#define AO_IR_CNG_SUBPRIO (0)
```

```c
#define AO_IR_CNH_ATTRIBUTE __ISR(_CHANGE_NOTICE_H_VECTOR, IPL4SRS)
```

```c
#define AO_IR_CNH_PRIO (4)
```

```c
#define AO_IR_CNH_SUBPRIO (0)
```

```c
#define AO_IR_CNJ_ATTRIBUTE __ISR(_CHANGE_NOTICE_J_VECTOR, IPL4SRS)
```

```c
#define AO_IR_CNJ_PRIO (4)
```

```c
#define AO_IR_CNJ_SUBPRIO (0)
```

```c
#define AO_IR_CNK_ATTRIBUTE __ISR(_CHANGE_NOTICE_K_VECTOR, IPL4SRS)
```

```c
#define AO_IR_CNK_PRIO (4)
```

```c
#define AO_IR_CNK_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_cna_disable()
```

```c
#define ao_ir_cna_enable()
```

```c
#define ao_ir_cna_is_enabled()
```

```c
#define ao_ir_cna_is_pending()
```

```c
#define ao_ir_cna_reply()
```

```c
#define ao_ir_cna_request()
```

```c
#define ao_ir_cnb_disable()
```

```c
#define ao_ir_cnb_enable()
```

```c
#define ao_ir_cnb_is_enabled()
```

```c
#define ao_ir_cnb_is_pending()
```

```c
#define ao_ir_cnb_reply()
```

```c
#define ao_ir_cnb_request()
```

```c
#define ao_ir_cnc_disable()
```

```c
#define ao_ir_cnc_enable()
```

```c
#define ao_ir_cnc_is_enabled()
```

```c
#define ao_ir_cnc_is_pending()
```

```c
#define ao_ir_cnc_reply()
```

```c
#define ao_ir_cnc_request()
```

```c
#define ao_ir_cnd_disable()
```

```c
#define ao_ir_cnd_enable()
```

```c
#define ao_ir_cnd_is_enabled()
```

```c
#define ao_ir_cnd_is_pending()
```

```c
#define ao_ir_cnd_reply()
```

```c
#define ao_ir_cnd_request()
```

```c
#define ao_ir_cne_disable()
```

```c
#define ao_ir_cne_enable()
```

```c
#define ao_ir_cne_is_enabled()
```

```c
#define ao_ir_cne_is_pending()
```

```c
#define ao_ir_cne_reply()
```

```c
#define ao_ir_cne_request()
```

```c
#define ao_ir_cnf_disable()
```

```c
#define ao_ir_cnf_enable()
```

```c
#define ao_ir_cnf_is_enabled()
```

```c
#define ao_ir_cnf_is_pending()
```

```c
#define ao_ir_cnf_reply()
```

```c
#define ao_ir_cnf_request()
```

```c
#define ao_ir_cng_disable()
```

```c
#define ao_ir_cng_enable()
```

```c
#define ao_ir_cng_is_enabled()
```

```c
#define ao_ir_cng_is_pending()
```

```c
#define ao_ir_cng_reply()
```

```c
#define ao_ir_cng_request()
```

```c
#define ao_ir_cnh_disable()
```

```c
#define ao_ir_cnh_enable()
```

```c
#define ao_ir_cnh_is_enabled()
```

```c
#define ao_ir_cnh_is_pending()
```

```c
#define ao_ir_cnh_reply()
```

```c
#define ao_ir_cnh_request()
```

```c
#define ao_ir_cnj_disable()
```

```c
#define ao_ir_cnj_enable()
```

```c
#define ao_ir_cnj_is_enabled()
```

```c
#define ao_ir_cnj_is_pending()
```

```c
#define ao_ir_cnj_reply()
```

```c
#define ao_ir_cnj_request()
```

```c
#define ao_ir_cnk_disable()
```

```c
#define ao_ir_cnk_enable()
```

```c
#define ao_ir_cnk_is_enabled()
```

```c
#define ao_ir_cnk_is_pending()
```

```c
#define ao_ir_cnk_reply()
```

```c
#define ao_ir_cnk_request()
```

