---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32mz_dak/ao_ir_ic.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32mz_dak/ao_ir_ic.h/
subtitle: ""
title: "ao_ir_ic.h"
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
#define AO_IR_IC1_ATTRIBUTE __ISR(_INPUT_CAPTURE_1_VECTOR, IPL4SRS)
```

```c
#define AO_IR_IC1_PRIO (4)
```

```c
#define AO_IR_IC1_SUBPRIO (0)
```

```c
#define AO_IR_IC1E_ATTRIBUTE __ISR(_INPUT_CAPTURE_1_ERROR_VECTOR, IPL4SRS)
```

```c
#define AO_IR_IC1E_PRIO (4)
```

```c
#define AO_IR_IC1E_SUBPRIO (0)
```

```c
#define AO_IR_IC2_ATTRIBUTE __ISR(_INPUT_CAPTURE_2_VECTOR, IPL4SRS)
```

```c
#define AO_IR_IC2_PRIO (4)
```

```c
#define AO_IR_IC2_SUBPRIO (0)
```

```c
#define AO_IR_IC2E_ATTRIBUTE __ISR(_INPUT_CAPTURE_2_ERROR_VECTOR, IPL4SRS)
```

```c
#define AO_IR_IC2E_PRIO (4)
```

```c
#define AO_IR_IC2E_SUBPRIO (0)
```

```c
#define AO_IR_IC3_ATTRIBUTE __ISR(_INPUT_CAPTURE_3_VECTOR, IPL4SRS)
```

```c
#define AO_IR_IC3_PRIO (4)
```

```c
#define AO_IR_IC3_SUBPRIO (0)
```

```c
#define AO_IR_IC3E_ATTRIBUTE __ISR(_INPUT_CAPTURE_3_ERROR_VECTOR, IPL4SRS)
```

```c
#define AO_IR_IC3E_PRIO (4)
```

```c
#define AO_IR_IC3E_SUBPRIO (0)
```

```c
#define AO_IR_IC4_ATTRIBUTE __ISR(_INPUT_CAPTURE_4_VECTOR, IPL4SRS)
```

```c
#define AO_IR_IC4_PRIO (4)
```

```c
#define AO_IR_IC4_SUBPRIO (0)
```

```c
#define AO_IR_IC4E_ATTRIBUTE __ISR(_INPUT_CAPTURE_4_ERROR_VECTOR, IPL4SRS)
```

```c
#define AO_IR_IC4E_PRIO (4)
```

```c
#define AO_IR_IC4E_SUBPRIO (0)
```

```c
#define AO_IR_IC5_ATTRIBUTE __ISR(_INPUT_CAPTURE_5_VECTOR, IPL4SRS)
```

```c
#define AO_IR_IC5_PRIO (4)
```

```c
#define AO_IR_IC5_SUBPRIO (0)
```

```c
#define AO_IR_IC5E_ATTRIBUTE __ISR(_INPUT_CAPTURE_5_ERROR_VECTOR, IPL4SRS)
```

```c
#define AO_IR_IC5E_PRIO (4)
```

```c
#define AO_IR_IC5E_SUBPRIO (0)
```

```c
#define AO_IR_IC6_ATTRIBUTE __ISR(_INPUT_CAPTURE_6_VECTOR, IPL4SRS)
```

```c
#define AO_IR_IC6_PRIO (4)
```

```c
#define AO_IR_IC6_SUBPRIO (0)
```

```c
#define AO_IR_IC6E_ATTRIBUTE __ISR(_INPUT_CAPTURE_6_ERROR_VECTOR, IPL4SRS)
```

```c
#define AO_IR_IC6E_PRIO (4)
```

```c
#define AO_IR_IC6E_SUBPRIO (0)
```

```c
#define AO_IR_IC7_ATTRIBUTE __ISR(_INPUT_CAPTURE_7_VECTOR, IPL4SRS)
```

```c
#define AO_IR_IC7_PRIO (4)
```

```c
#define AO_IR_IC7_SUBPRIO (0)
```

```c
#define AO_IR_IC7E_ATTRIBUTE __ISR(_INPUT_CAPTURE_7_ERROR_VECTOR, IPL4SRS)
```

```c
#define AO_IR_IC7E_PRIO (4)
```

```c
#define AO_IR_IC7E_SUBPRIO (0)
```

```c
#define AO_IR_IC8_ATTRIBUTE __ISR(_INPUT_CAPTURE_8_VECTOR, IPL4SRS)
```

```c
#define AO_IR_IC8_PRIO (4)
```

```c
#define AO_IR_IC8_SUBPRIO (0)
```

```c
#define AO_IR_IC8E_ATTRIBUTE __ISR(_INPUT_CAPTURE_8_ERROR_VECTOR, IPL4SRS)
```

```c
#define AO_IR_IC8E_PRIO (4)
```

```c
#define AO_IR_IC8E_SUBPRIO (0)
```

```c
#define AO_IR_IC9_ATTRIBUTE __ISR(_INPUT_CAPTURE_9_VECTOR, IPL4SRS)
```

```c
#define AO_IR_IC9_PRIO (4)
```

```c
#define AO_IR_IC9_SUBPRIO (0)
```

```c
#define AO_IR_IC9E_ATTRIBUTE __ISR(_INPUT_CAPTURE_9_ERROR_VECTOR, IPL4SRS)
```

```c
#define AO_IR_IC9E_PRIO (4)
```

```c
#define AO_IR_IC9E_SUBPRIO (0)
```

# Functions

```c
#define ao_ir_ic1_disable()
```

```c
#define ao_ir_ic1_enable()
```

```c
#define ao_ir_ic1_is_enabled()
```

```c
#define ao_ir_ic1_is_pending()
```

```c
#define ao_ir_ic1_reply()
```

```c
#define ao_ir_ic1_request()
```

```c
#define ao_ir_ic1e_disable()
```

```c
#define ao_ir_ic1e_enable()
```

```c
#define ao_ir_ic1e_is_enabled()
```

```c
#define ao_ir_ic1e_is_pending()
```

```c
#define ao_ir_ic1e_reply()
```

```c
#define ao_ir_ic1e_request()
```

```c
#define ao_ir_ic2_disable()
```

```c
#define ao_ir_ic2_enable()
```

```c
#define ao_ir_ic2_is_enabled()
```

```c
#define ao_ir_ic2_is_pending()
```

```c
#define ao_ir_ic2_reply()
```

```c
#define ao_ir_ic2_request()
```

```c
#define ao_ir_ic2e_disable()
```

```c
#define ao_ir_ic2e_enable()
```

```c
#define ao_ir_ic2e_is_enabled()
```

```c
#define ao_ir_ic2e_is_pending()
```

```c
#define ao_ir_ic2e_reply()
```

```c
#define ao_ir_ic2e_request()
```

```c
#define ao_ir_ic3_disable()
```

```c
#define ao_ir_ic3_enable()
```

```c
#define ao_ir_ic3_is_enabled()
```

```c
#define ao_ir_ic3_is_pending()
```

```c
#define ao_ir_ic3_reply()
```

```c
#define ao_ir_ic3_request()
```

```c
#define ao_ir_ic3e_disable()
```

```c
#define ao_ir_ic3e_enable()
```

```c
#define ao_ir_ic3e_is_enabled()
```

```c
#define ao_ir_ic3e_is_pending()
```

```c
#define ao_ir_ic3e_reply()
```

```c
#define ao_ir_ic3e_request()
```

```c
#define ao_ir_ic4_disable()
```

```c
#define ao_ir_ic4_enable()
```

```c
#define ao_ir_ic4_is_enabled()
```

```c
#define ao_ir_ic4_is_pending()
```

```c
#define ao_ir_ic4_reply()
```

```c
#define ao_ir_ic4_request()
```

```c
#define ao_ir_ic4e_disable()
```

```c
#define ao_ir_ic4e_enable()
```

```c
#define ao_ir_ic4e_is_enabled()
```

```c
#define ao_ir_ic4e_is_pending()
```

```c
#define ao_ir_ic4e_reply()
```

```c
#define ao_ir_ic4e_request()
```

```c
#define ao_ir_ic5_disable()
```

```c
#define ao_ir_ic5_enable()
```

```c
#define ao_ir_ic5_is_enabled()
```

```c
#define ao_ir_ic5_is_pending()
```

```c
#define ao_ir_ic5_reply()
```

```c
#define ao_ir_ic5_request()
```

```c
#define ao_ir_ic5e_disable()
```

```c
#define ao_ir_ic5e_enable()
```

```c
#define ao_ir_ic5e_is_enabled()
```

```c
#define ao_ir_ic5e_is_pending()
```

```c
#define ao_ir_ic5e_reply()
```

```c
#define ao_ir_ic5e_request()
```

```c
#define ao_ir_ic6_disable()
```

```c
#define ao_ir_ic6_enable()
```

```c
#define ao_ir_ic6_is_enabled()
```

```c
#define ao_ir_ic6_is_pending()
```

```c
#define ao_ir_ic6_reply()
```

```c
#define ao_ir_ic6_request()
```

```c
#define ao_ir_ic6e_disable()
```

```c
#define ao_ir_ic6e_enable()
```

```c
#define ao_ir_ic6e_is_enabled()
```

```c
#define ao_ir_ic6e_is_pending()
```

```c
#define ao_ir_ic6e_reply()
```

```c
#define ao_ir_ic6e_request()
```

```c
#define ao_ir_ic7_disable()
```

```c
#define ao_ir_ic7_enable()
```

```c
#define ao_ir_ic7_is_enabled()
```

```c
#define ao_ir_ic7_is_pending()
```

```c
#define ao_ir_ic7_reply()
```

```c
#define ao_ir_ic7_request()
```

```c
#define ao_ir_ic7e_disable()
```

```c
#define ao_ir_ic7e_enable()
```

```c
#define ao_ir_ic7e_is_enabled()
```

```c
#define ao_ir_ic7e_is_pending()
```

```c
#define ao_ir_ic7e_reply()
```

```c
#define ao_ir_ic7e_request()
```

```c
#define ao_ir_ic8_disable()
```

```c
#define ao_ir_ic8_enable()
```

```c
#define ao_ir_ic8_is_enabled()
```

```c
#define ao_ir_ic8_is_pending()
```

```c
#define ao_ir_ic8_reply()
```

```c
#define ao_ir_ic8_request()
```

```c
#define ao_ir_ic8e_disable()
```

```c
#define ao_ir_ic8e_enable()
```

```c
#define ao_ir_ic8e_is_enabled()
```

```c
#define ao_ir_ic8e_is_pending()
```

```c
#define ao_ir_ic8e_reply()
```

```c
#define ao_ir_ic8e_request()
```

```c
#define ao_ir_ic9_disable()
```

```c
#define ao_ir_ic9_enable()
```

```c
#define ao_ir_ic9_is_enabled()
```

```c
#define ao_ir_ic9_is_pending()
```

```c
#define ao_ir_ic9_reply()
```

```c
#define ao_ir_ic9_request()
```

```c
#define ao_ir_ic9e_disable()
```

```c
#define ao_ir_ic9e_enable()
```

```c
#define ao_ir_ic9e_is_enabled()
```

```c
#define ao_ir_ic9e_is_pending()
```

```c
#define ao_ir_ic9e_reply()
```

```c
#define ao_ir_ic9e_request()
```

