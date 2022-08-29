---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys_xc32_pic32mz_da/ao_ir_gpu.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mz_da/ao_ir_gpu.h/ 
subtitle: "<code>ao_sys_xc32_pic32mz_da</code>"
title: "<code>ao_ir_gpu.h</code>"
toc: true
---

```c
#ifndef AO_IR_GPU_ATTRIBUTE

#define AO_IR_GPU_ATTRIBUTE     __ISR(_GPU_VECTOR, IPL4SRS)

#endif

#ifndef AO_IR_GPU_PRIO

#define AO_IR_GPU_PRIO          (4)

#endif

#ifndef AO_IR_GPU_SUBPRIO

#define AO_IR_GPU_SUBPRIO       (0)

#endif

#ifndef ao_ir_gpu_disable

#define ao_ir_gpu_disable()     { IEC6CLR = _IEC6_GPUIE_MASK; }

#endif

#ifndef ao_ir_gpu_enable

#define ao_ir_gpu_enable()      { IEC6SET = _IEC6_GPUIE_MASK; }

#endif

#ifndef ao_ir_gpu_is_enabled

#define ao_ir_gpu_is_enabled()  ((IEC6 & _IEC6_GPUIE_MASK) ? true : false)

#endif

#ifndef ao_ir_gpu_is_pending

#define ao_ir_gpu_is_pending()  ((IFS6 & _IFS6_GPUIF_MASK) ? true : false)

#endif

#ifndef ao_ir_gpu_reply

#define ao_ir_gpu_reply()       { IFS6CLR = _IFS6_GPUIF_MASK; }

#endif

#ifndef ao_ir_gpu_request

#define ao_ir_gpu_request()     { IFS6SET = _IFS6_GPUIF_MASK; }

#endif

```
