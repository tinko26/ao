---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32/ao_ir_stack.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32/ao_ir_stack.h/ 
subtitle: ""
title: "ao_ir_stack.h"
toc: true
---

```c
#include <ao_align.h>
#include <ao_func.h>
#include <ao_stack.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct  ao_ir_stack_t       ao_ir_stack_t;

#ifndef AO_IR_STACK_DEPTH_MAX

#define AO_IR_STACK_DEPTH_MAX       (false)

#endif

#ifndef AO_IR_STACK_FILL

#define AO_IR_STACK_FILL            (false)

#endif

#ifndef AO_IR_STACK_SIZE

#define AO_IR_STACK_SIZE            (4096)

#endif

#ifndef AO_IR_STACK_SIZE_ALIGNED

#define AO_IR_STACK_SIZE_ALIGNED    AO_ALIGN_UP(AO_IR_STACK_SIZE, AO_STACK_ALIGN)

#endif

#ifndef AO_IR_STACK_SIZE_AS

#define AO_IR_STACK_SIZE_AS         (24)

#endif

#ifndef AO_IR_STACK

#define AO_IR_STACK

struct  ao_ir_stack_t
{
        uint32_t                    sp;

        uint32_t                    sp_backup;

        uint32_t                    fp_backup;

        uint32_t                    depth;

#if     AO_IR_STACK_DEPTH_MAX

        uint32_t                    depth_max;

#endif

#if     AO_IR_STACK_FILL

        size_t                      high_water_mark;

#endif

};

#endif

extern  ao_ir_stack_t               ao_ir_stack;

void *  ao_ir_stack_func0(                                           ao_func0_t f);

void *  ao_ir_stack_func1(          void * p1,                       ao_func1_t f);

void *  ao_ir_stack_func2(          void * p1, void * p2,            ao_func2_t f);

void *  ao_ir_stack_func3(          void * p1, void * p2, void * p3, ao_func3_t f);

void    ao_ir_stack_high_water_mark();

```
