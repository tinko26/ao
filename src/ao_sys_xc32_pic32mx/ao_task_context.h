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

// Task context.

// ----------------------------------------------------------------------------

#include <stdint.h>
#include <xc.h>

// ----------------------------------------------------------------------------

typedef struct  ao_task_t               ao_task_t;

typedef struct  ao_task_context_t       ao_task_context_t;

typedef struct  ao_task_context_data_t  ao_task_context_data_t;

// ----------------------------------------------------------------------------

#ifndef AO_TASK_CONTEXT_T

#define AO_TASK_CONTEXT_T

// ----------------------------------------------------------------------------

struct  ao_task_context_t
{
        ao_task_context_data_t *        ptr;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_TASK_CONTEXT_DATA_T

#define AO_TASK_CONTEXT_DATA_T

// ----------------------------------------------------------------------------

struct  ao_task_context_data_t
{
        uint32_t                        hi;

        uint32_t                        lo;

        uint32_t                        a0;

        uint32_t                        a1;

        uint32_t                        a2;

        uint32_t                        a3;

        uint32_t                        at;

        uint32_t                        ra;

        uint32_t                        s2;

        uint32_t                        s3;

        uint32_t                        s4;

        uint32_t                        s5;

        uint32_t                        s6;

        uint32_t                        s7;

        uint32_t                        t0;

        uint32_t                        t1;

        uint32_t                        t2;

        uint32_t                        t3;

        uint32_t                        t4;

        uint32_t                        t5;

        uint32_t                        t6;

        uint32_t                        t7;

        uint32_t                        t8;

        uint32_t                        t9;

        uint32_t                        v0;

        uint32_t                        v1;

        uint32_t                        epc;

        uint32_t                        status;

        uint32_t                        s0;

        uint32_t                        s1;

        uint32_t                        s8;

        uint32_t                        padding;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

void    ao_task_start_context(          ao_task_t * t);

// ----------------------------------------------------------------------------

#ifndef ao_task_stop_context

#define ao_task_stop_context(           t)

#endif

// ----------------------------------------------------------------------------
