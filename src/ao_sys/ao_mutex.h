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

// Mutexes.

// ----------------------------------------------------------------------------

#include <ao_async.h>
#include <ao_list.h>
#include <ao_task.h>
#include <ao_time.h>
#include <ao_uint.h>
#include <stdbool.h>

// ----------------------------------------------------------------------------

typedef struct  ao_mutex_t      ao_mutex_t;

typedef struct  ao_mutex_lock_t ao_mutex_lock_t;

// ----------------------------------------------------------------------------

#ifndef AO_MUTEX

#define AO_MUTEX

#endif

// ----------------------------------------------------------------------------

#ifndef AO_MUTEX_T

#define AO_MUTEX_T

// ----------------------------------------------------------------------------

struct  ao_mutex_t
{

#if     AO_TASK_CEILING

        ao_task_ceiling_t       ceiling_immediate;

        ao_task_ceiling_t       ceiling_original;

#endif

        ao_list_t               lock;

        ao_task_t *             owner;

        ao_uint_t               owner_count;

#if     AO_TASK_SUBMISSION

        ao_task_slave_t         slave;

#endif

};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_MUTEX_LOCK_T

#define AO_MUTEX_LOCK_T

// ----------------------------------------------------------------------------

struct  ao_mutex_lock_t
{
        ao_async_t              async;

#if     AO_TASK_INHERITANCE

        ao_task_master_t        master;

#endif

        ao_mutex_t *            mutex;

        ao_list_node_t          mutex_lock_node;

        bool        volatile    result;

        ao_task_t *             task;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

bool    ao_mutex_lock(          ao_mutex_t * m, ao_time_t timeout);

bool    ao_mutex_lock_from(     ao_mutex_t * m, ao_time_t timeout, ao_time_t beginning);

bool    ao_mutex_lock_forever(  ao_mutex_t * m);

// ----------------------------------------------------------------------------

bool    ao_mutex_lock_try(      ao_mutex_t * m);

// ----------------------------------------------------------------------------

void    ao_mutex_lock_begin(    ao_mutex_lock_t * l);

void    ao_mutex_lock_end(      ao_mutex_lock_t * l);

// ----------------------------------------------------------------------------

void    ao_mutex_unlock(        ao_mutex_t * m);

// ----------------------------------------------------------------------------
