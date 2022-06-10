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

// Task switch interrupt.

// ----------------------------------------------------------------------------

#include <ao_core.h>
#include <ao_ir_cs.h>
#include <stdbool.h>

// ----------------------------------------------------------------------------

void    ao_task_switch();

// ----------------------------------------------------------------------------

#ifndef AO_IR_TASK

#define AO_IR_TASK

// ----------------------------------------------------------------------------

static void ao_task_switch_disable(ao_core_t c)
{
    (void) c;

    ao_ir_cs1_disable();
}

static void ao_task_switch_enable(ao_core_t c)
{
    (void) c;

    ao_ir_cs1_enable();
}

// ----------------------------------------------------------------------------

static bool ao_task_switch_is_pending(ao_core_t c)
{
    (void) c;

    return ao_ir_cs1_is_pending();
}

// ----------------------------------------------------------------------------

static void ao_task_switch_reply(ao_core_t c)
{
    (void) c;

    ao_ir_cs1_reply();
}

static void ao_task_switch_request(ao_core_t c)
{
    (void) c;

    ao_ir_cs1_request();
}

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------
