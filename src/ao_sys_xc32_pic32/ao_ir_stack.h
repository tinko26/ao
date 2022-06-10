// ----------------------------------------------------------------------------

// MIT License

// Copyright (c) 2022 Stefan Wagner

// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

// ----------------------------------------------------------------------------

// Interrupt stack.

// ----------------------------------------------------------------------------

#include <ao_align.h>
#include <ao_func.h>
#include <ao_stack.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// ----------------------------------------------------------------------------

typedef struct  ao_ir_stack_t       ao_ir_stack_t;

// ----------------------------------------------------------------------------

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

#define AO_IR_STACK_SIZE_ALIGNED    ao_align_up(AO_IR_STACK_SIZE, AO_STACK_ALIGN)

#endif

#ifndef AO_IR_STACK_SIZE_AS

#define AO_IR_STACK_SIZE_AS         (24)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_IR_STACK

#define AO_IR_STACK

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

extern  ao_ir_stack_t               ao_ir_stack;

// ----------------------------------------------------------------------------

// Executes function #f on the interrupt stack.

void *  ao_ir_stack_func0(                                           ao_func0_t f);

void *  ao_ir_stack_func1(          void * p1,                       ao_func1_t f);

void *  ao_ir_stack_func2(          void * p1, void * p2,            ao_func2_t f);

void *  ao_ir_stack_func3(          void * p1, void * p2, void * p3, ao_func3_t f);

// ----------------------------------------------------------------------------

// Measures the high water mark of the interrupt stack.

void    ao_ir_stack_high_water_mark();

// ----------------------------------------------------------------------------
