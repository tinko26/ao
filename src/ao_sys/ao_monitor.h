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

// Monitors.

// ----------------------------------------------------------------------------

#include <ao_async.h>
#include <ao_list.h>
#include <ao_mutex.h>
#include <ao_time.h>
#include <stdbool.h>

// ----------------------------------------------------------------------------

typedef struct  ao_monitor_t        ao_monitor_t;

typedef struct  ao_monitor_enter_t  ao_monitor_enter_t;

typedef struct  ao_monitor_wait_t   ao_monitor_wait_t;

// ----------------------------------------------------------------------------

#ifndef AO_MONITOR

#define AO_MONITOR

#endif

// ----------------------------------------------------------------------------

#ifndef AO_MONITOR_T

#define AO_MONITOR_T

// ----------------------------------------------------------------------------

struct  ao_monitor_t
{
        ao_mutex_t *                mutex;

        ao_list_t                   wait;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_MONITOR_ENTER_T

#define AO_MONITOR_ENTER_T

// ----------------------------------------------------------------------------

struct  ao_monitor_enter_t
{
        ao_async_t                  async;

        ao_monitor_t *              monitor;

        ao_mutex_lock_t             monitor_mutex_lock;

        bool            volatile    result;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_MONITOR_WAIT_T

#define AO_MONITOR_WAIT_T

// ----------------------------------------------------------------------------

struct  ao_monitor_wait_t
{
        ao_async_t                  async;

        ao_monitor_t *              monitor;

        union
        {
            ao_mutex_lock_t         monitor_mutex_lock;

            ao_list_node_t          monitor_wait_node;
        };

        bool            volatile    result;

        bool            volatile    waiting;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

bool    ao_monitor_enter(           ao_monitor_t * m, ao_time_t timeout);

bool    ao_monitor_enter_from(      ao_monitor_t * m, ao_time_t timeout, ao_time_t beginning);

bool    ao_monitor_enter_forever(   ao_monitor_t * m);

// ----------------------------------------------------------------------------

bool    ao_monitor_enter_try(       ao_monitor_t * m);

// ----------------------------------------------------------------------------

void    ao_monitor_enter_begin(     ao_monitor_enter_t * e);

void    ao_monitor_enter_end(       ao_monitor_enter_t * e);

// ----------------------------------------------------------------------------

void    ao_monitor_exit(            ao_monitor_t * m);

// ----------------------------------------------------------------------------

void    ao_monitor_notify(          ao_monitor_t * m);

void    ao_monitor_notify_all(      ao_monitor_t * m);

// ----------------------------------------------------------------------------

bool    ao_monitor_wait(            ao_monitor_t * m, ao_time_t timeout);

bool    ao_monitor_wait_from(       ao_monitor_t * m, ao_time_t timeout, ao_time_t beginning);

bool    ao_monitor_wait_forever(    ao_monitor_t * m);

// ----------------------------------------------------------------------------

bool    ao_monitor_wait_try(        ao_monitor_t * m);

// ----------------------------------------------------------------------------

void    ao_monitor_wait_begin(      ao_monitor_wait_t * w);

void    ao_monitor_wait_end(        ao_monitor_wait_t * w);

// ----------------------------------------------------------------------------
