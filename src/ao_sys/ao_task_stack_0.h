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

// Task stack 0.

// Task stack stub.

// ----------------------------------------------------------------------------

#include <stddef.h>

// ----------------------------------------------------------------------------

typedef struct  ao_task_t                   ao_task_t;

typedef struct  ao_task_stack_t             ao_task_stack_t;

// ----------------------------------------------------------------------------

#ifndef AO_TASK_STACK_0

#define AO_TASK_STACK_0

#endif

// ----------------------------------------------------------------------------

#ifndef AO_TASK_STACK_T

#define AO_TASK_STACK_T

// ----------------------------------------------------------------------------

struct  ao_task_stack_t                     { };

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

void *  ao_task_get_stack_beginning(        ao_task_t const * t);

void *  ao_task_get_stack_beginning_locked( ao_task_t const * t);

// ----------------------------------------------------------------------------

size_t  ao_task_get_stack_size(             ao_task_t const * t);

size_t  ao_task_get_stack_size_locked(      ao_task_t const * t);

// ----------------------------------------------------------------------------
