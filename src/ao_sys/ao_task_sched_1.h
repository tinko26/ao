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

// Task scheduler 1.

// This module implements round-robin scheduling without priorities.

// This module supports a single processor.

// ----------------------------------------------------------------------------

#include <ao_list.h>
#include <ao_time.h>
#include <stdbool.h>

// ----------------------------------------------------------------------------

typedef struct  ao_task_sched_t     ao_task_sched_t;

// ----------------------------------------------------------------------------

typedef struct  ao_task_ceiling_t   ao_task_ceiling_t;

typedef struct  ao_task_master_t    ao_task_master_t;

typedef struct  ao_task_slave_t     ao_task_slave_t;

// ----------------------------------------------------------------------------

#ifndef AO_TASK_SCHED_1

#define AO_TASK_SCHED_1

#endif

// ----------------------------------------------------------------------------

#ifndef AO_TASK_CEILING

#define AO_TASK_CEILING             (false)

#endif

#ifndef AO_TASK_INHERITANCE

#define AO_TASK_INHERITANCE         (false)

#endif

#ifndef AO_TASK_SUBMISSION

#define AO_TASK_SUBMISSION          (false)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_TASK_QUANTUM

#define AO_TASK_QUANTUM             (ao_milliseconds(10))

#endif

// ----------------------------------------------------------------------------

#ifndef AO_TASK_SCHED_T

#define AO_TASK_SCHED_T

// ----------------------------------------------------------------------------

struct  ao_task_sched_t
{
        ao_list_node_t              node;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

#ifndef AO_TASK_CEILING_T

#define AO_TASK_CEILING_T

// ----------------------------------------------------------------------------

struct  ao_task_ceiling_t           { };

// ----------------------------------------------------------------------------

#endif

#ifndef AO_TASK_MASTER_T

#define AO_TASK_MASTER_T

// ----------------------------------------------------------------------------

struct  ao_task_master_t            { };

// ----------------------------------------------------------------------------

#endif

#ifndef AO_TASK_SLAVE_T

#define AO_TASK_SLAVE_T

// ----------------------------------------------------------------------------

struct  ao_task_slave_t             { };

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------
