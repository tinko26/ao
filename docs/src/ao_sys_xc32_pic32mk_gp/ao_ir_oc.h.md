---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mk_gp/ao_ir_oc.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32_pic32mk_gp/ao_ir_oc.h/ 
subtitle: ""
title: "ao_ir_oc.h"
toc: true
---

# Includes

```c
#include <stdbool.h>
#include <sys/attribs.h>
#include <xc.h>
```

```c
#define AO_IR_OC1_ATTRIBUTE     __ISR(_OUTPUT_COMPARE_1_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_OC1_PRIO          (4)
```

```c
#define AO_IR_OC1_SUBPRIO       (0)
```

```c
#define ao_ir_oc1_disable()
```

```c
#define ao_ir_oc1_enable()
```

```c
#define ao_ir_oc1_is_enabled()
```

```c
#define ao_ir_oc1_is_pending()
```

```c
#define ao_ir_oc1_reply()
```

```c
#define ao_ir_oc1_request()
```

```c
#define AO_IR_OC2_ATTRIBUTE     __ISR(_OUTPUT_COMPARE_2_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_OC2_PRIO          (4)
```

```c
#define AO_IR_OC2_SUBPRIO       (0)
```

```c
#define ao_ir_oc2_disable()
```

```c
#define ao_ir_oc2_enable()
```

```c
#define ao_ir_oc2_is_enabled()
```

```c
#define ao_ir_oc2_is_pending()
```

```c
#define ao_ir_oc2_reply()
```

```c
#define ao_ir_oc2_request()
```

```c
#define AO_IR_OC3_ATTRIBUTE     __ISR(_OUTPUT_COMPARE_3_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_OC3_PRIO          (4)
```

```c
#define AO_IR_OC3_SUBPRIO       (0)
```

```c
#define ao_ir_oc3_disable()
```

```c
#define ao_ir_oc3_enable()
```

```c
#define ao_ir_oc3_is_enabled()
```

```c
#define ao_ir_oc3_is_pending()
```

```c
#define ao_ir_oc3_reply()
```

```c
#define ao_ir_oc3_request()
```

```c
#define AO_IR_OC4_ATTRIBUTE     __ISR(_OUTPUT_COMPARE_4_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_OC4_PRIO          (4)
```

```c
#define AO_IR_OC4_SUBPRIO       (0)
```

```c
#define ao_ir_oc4_disable()
```

```c
#define ao_ir_oc4_enable()
```

```c
#define ao_ir_oc4_is_enabled()
```

```c
#define ao_ir_oc4_is_pending()
```

```c
#define ao_ir_oc4_reply()
```

```c
#define ao_ir_oc4_request()
```

```c
#define AO_IR_OC5_ATTRIBUTE     __ISR(_OUTPUT_COMPARE_5_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_OC5_PRIO          (4)
```

```c
#define AO_IR_OC5_SUBPRIO       (0)
```

```c
#define ao_ir_oc5_disable()
```

```c
#define ao_ir_oc5_enable()
```

```c
#define ao_ir_oc5_is_enabled()
```

```c
#define ao_ir_oc5_is_pending()
```

```c
#define ao_ir_oc5_reply()
```

```c
#define ao_ir_oc5_request()
```

```c
#define AO_IR_OC6_ATTRIBUTE     __ISR(_OUTPUT_COMPARE_6_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_OC6_PRIO          (4)
```

```c
#define AO_IR_OC6_SUBPRIO       (0)
```

```c
#define ao_ir_oc6_disable()
```

```c
#define ao_ir_oc6_enable()
```

```c
#define ao_ir_oc6_is_enabled()
```

```c
#define ao_ir_oc6_is_pending()
```

```c
#define ao_ir_oc6_reply()
```

```c
#define ao_ir_oc6_request()
```

```c
#define AO_IR_OC7_ATTRIBUTE     __ISR(_OUTPUT_COMPARE_7_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_OC7_PRIO          (4)
```

```c
#define AO_IR_OC7_SUBPRIO       (0)
```

```c
#define ao_ir_oc7_disable()
```

```c
#define ao_ir_oc7_enable()
```

```c
#define ao_ir_oc7_is_enabled()
```

```c
#define ao_ir_oc7_is_pending()
```

```c
#define ao_ir_oc7_reply()
```

```c
#define ao_ir_oc7_request()
```

```c
#define AO_IR_OC8_ATTRIBUTE     __ISR(_OUTPUT_COMPARE_8_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_OC8_PRIO          (4)
```

```c
#define AO_IR_OC8_SUBPRIO       (0)
```

```c
#define ao_ir_oc8_disable()
```

```c
#define ao_ir_oc8_enable()
```

```c
#define ao_ir_oc8_is_enabled()
```

```c
#define ao_ir_oc8_is_pending()
```

```c
#define ao_ir_oc8_reply()
```

```c
#define ao_ir_oc8_request()
```

```c
#define AO_IR_OC9_ATTRIBUTE     __ISR(_OUTPUT_COMPARE_9_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_OC9_PRIO          (4)
```

```c
#define AO_IR_OC9_SUBPRIO       (0)
```

```c
#define ao_ir_oc9_disable()
```

```c
#define ao_ir_oc9_enable()
```

```c
#define ao_ir_oc9_is_enabled()
```

```c
#define ao_ir_oc9_is_pending()
```

```c
#define ao_ir_oc9_reply()
```

```c
#define ao_ir_oc9_request()
```

```c
#define AO_IR_OC10_ATTRIBUTE    __ISR(_OUTPUT_COMPARE_10_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_OC10_PRIO         (4)
```

```c
#define AO_IR_OC10_SUBPRIO      (0)
```

```c
#define ao_ir_oc10_disable()
```

```c
#define ao_ir_oc10_enable()
```

```c
#define ao_ir_oc10_is_enabled()
```

```c
#define ao_ir_oc10_is_pending()
```

```c
#define ao_ir_oc10_reply()
```

```c
#define ao_ir_oc10_request()
```

```c
#define AO_IR_OC11_ATTRIBUTE    __ISR(_OUTPUT_COMPARE_11_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_OC11_PRIO         (4)
```

```c
#define AO_IR_OC11_SUBPRIO      (0)
```

```c
#define ao_ir_oc11_disable()
```

```c
#define ao_ir_oc11_enable()
```

```c
#define ao_ir_oc11_is_enabled()
```

```c
#define ao_ir_oc11_is_pending()
```

```c
#define ao_ir_oc11_reply()
```

```c
#define ao_ir_oc11_request()
```

```c
#define AO_IR_OC12_ATTRIBUTE    __ISR(_OUTPUT_COMPARE_12_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_OC12_PRIO         (4)
```

```c
#define AO_IR_OC12_SUBPRIO      (0)
```

```c
#define ao_ir_oc12_disable()
```

```c
#define ao_ir_oc12_enable()
```

```c
#define ao_ir_oc12_is_enabled()
```

```c
#define ao_ir_oc12_is_pending()
```

```c
#define ao_ir_oc12_reply()
```

```c
#define ao_ir_oc12_request()
```

```c
#define AO_IR_OC13_ATTRIBUTE    __ISR(_OUTPUT_COMPARE_13_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_OC13_PRIO         (4)
```

```c
#define AO_IR_OC13_SUBPRIO      (0)
```

```c
#define ao_ir_oc13_disable()
```

```c
#define ao_ir_oc13_enable()
```

```c
#define ao_ir_oc13_is_enabled()
```

```c
#define ao_ir_oc13_is_pending()
```

```c
#define ao_ir_oc13_reply()
```

```c
#define ao_ir_oc13_request()
```

```c
#define AO_IR_OC14_ATTRIBUTE    __ISR(_OUTPUT_COMPARE_14_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_OC14_PRIO         (4)
```

```c
#define AO_IR_OC14_SUBPRIO      (0)
```

```c
#define ao_ir_oc14_disable()
```

```c
#define ao_ir_oc14_enable()
```

```c
#define ao_ir_oc14_is_enabled()
```

```c
#define ao_ir_oc14_is_pending()
```

```c
#define ao_ir_oc14_reply()
```

```c
#define ao_ir_oc14_request()
```

```c
#define AO_IR_OC15_ATTRIBUTE    __ISR(_OUTPUT_COMPARE_15_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_OC15_PRIO         (4)
```

```c
#define AO_IR_OC15_SUBPRIO      (0)
```

```c
#define ao_ir_oc15_disable()
```

```c
#define ao_ir_oc15_enable()
```

```c
#define ao_ir_oc15_is_enabled()
```

```c
#define ao_ir_oc15_is_pending()
```

```c
#define ao_ir_oc15_reply()
```

```c
#define ao_ir_oc15_request()
```

```c
#define AO_IR_OC16_ATTRIBUTE    __ISR(_OUTPUT_COMPARE_16_VECTOR, IPL4SOFT)
```

```c
#define AO_IR_OC16_PRIO         (4)
```

```c
#define AO_IR_OC16_SUBPRIO      (0)
```

```c
#define ao_ir_oc16_disable()
```

```c
#define ao_ir_oc16_enable()
```

```c
#define ao_ir_oc16_is_enabled()
```

```c
#define ao_ir_oc16_is_pending()
```

```c
#define ao_ir_oc16_reply()
```

```c
#define ao_ir_oc16_request()
```

