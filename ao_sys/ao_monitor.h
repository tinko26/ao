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

// Monitor.

// ----------------------------------------------------------------------------

// @seeAlso

// https://en.wikipedia.org/wiki/Monitor_(synchronization)

// ----------------------------------------------------------------------------

// @example

// Producer-consumer problem.

// @code

/*

    ao_mutex_t * mutex;

    ao_monitor_t not_empty = { .mutex = mutex };
    ao_monitor_t not_full  = { .mutex = mutex };

    int volatile count;

    bool is_empty() { return count == 0; }
    bool is_full()  { return count == 10; }

    ao_task_t *  consumer;
    ao_task_t *  producer;

    void consumer_proc(void * x)
    {
        while (1)
        {
            ao_monitor_enter_forever(&not_empty);
            {
                while (is_empty())
                {
                    ao_monitor_wait_forever(&not_empty);
                }

                count--;

                ao_monitor_notify(&not_full);
            }
            ao_monitor_exit(&not_empty);
        }
    }

    void producer_proc(void * x)
    {
        while (1)
        {
            ao_monitor_enter_forever(&not_full);
            {
                while (is_full())
                {
                    ao_monitor_wait_forever(&not_full);
                }

                count++;

                ao_monitor_notify(&not_empty);
            }
            ao_monitor_exit(&not_full);
        }
    }

*/

// @endCode

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

// ----------------------------------------------------------------------------

struct  ao_monitor_t
{
        ao_list_t                   list;

        ao_mutex_t *                mutex;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_MONITOR_ENTER

#define AO_MONITOR_ENTER

// ----------------------------------------------------------------------------

struct  ao_monitor_enter_t
{
        ao_async_t                  async;

        ao_monitor_t *              monitor;

        ao_mutex_lock_t             mutex_lock;

        bool            volatile    result;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_MONITOR_WAIT

#define AO_MONITOR_WAIT

// ----------------------------------------------------------------------------

struct  ao_monitor_wait_t
{
        ao_async_t                  async;

        ao_monitor_t *              monitor;

        union
        {
            ao_mutex_lock_t         mutex_lock;

            ao_list_node_t          node;
        };

        bool            volatile    result;

        bool            volatile    waiting;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

bool    ao_monitor_enter(           ao_monitor_t * x, ao_time_t timeout);

bool    ao_monitor_enter_from(      ao_monitor_t * x, ao_time_t timeout, ao_time_t beginning);

bool    ao_monitor_enter_forever(   ao_monitor_t * x);

// ----------------------------------------------------------------------------

bool    ao_monitor_enter_try(       ao_monitor_t * x);

// ----------------------------------------------------------------------------

void    ao_monitor_enter_begin(     ao_monitor_enter_t * x);

void    ao_monitor_enter_end(       ao_monitor_enter_t * x);

// ----------------------------------------------------------------------------

void    ao_monitor_exit(            ao_monitor_t * x);

// ----------------------------------------------------------------------------

void    ao_monitor_notify(          ao_monitor_t * x);

void    ao_monitor_notify_all(      ao_monitor_t * x);

// ----------------------------------------------------------------------------

bool    ao_monitor_wait(            ao_monitor_t * x, ao_time_t timeout);

bool    ao_monitor_wait_from(       ao_monitor_t * x, ao_time_t timeout, ao_time_t beginning);

bool    ao_monitor_wait_forever(    ao_monitor_t * x);

// ----------------------------------------------------------------------------

bool    ao_monitor_wait_try(        ao_monitor_t * x);

// ----------------------------------------------------------------------------

void    ao_monitor_wait_begin(      ao_monitor_wait_t * x);

void    ao_monitor_wait_end(        ao_monitor_wait_t * x);

// ----------------------------------------------------------------------------
