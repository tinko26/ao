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

// Task.

// ----------------------------------------------------------------------------

#include <ao_task_context.h>
#include <ao_task_sched.h>
#include <ao_task_stack.h>

// ----------------------------------------------------------------------------

#include <ao_block.h>
#include <ao_core.h>
#include <ao_func.h>
#include <ao_int.h>
#include <ao_time.h>
#include <ao_uint.h>

// ----------------------------------------------------------------------------

#include <stdbool.h>

// ----------------------------------------------------------------------------

typedef     struct  ao_task_t                   ao_task_t;

// ----------------------------------------------------------------------------

typedef     enum    ao_task_state_t             ao_task_state_t;

typedef     enum    ao_task_state_pending_t     ao_task_state_pending_t;

// ----------------------------------------------------------------------------

#ifndef     AO_TASK_COUNT

#define     AO_TASK_COUNT                       (false)

#endif

#ifndef     AO_TASK_ID

#define     AO_TASK_ID                          (false)

#endif

#ifndef     AO_TASK_NAME

#define     AO_TASK_NAME                        (false)

#endif

#ifndef     AO_TASK_TIME

#define     AO_TASK_TIME                        (false)

#endif

// ----------------------------------------------------------------------------

#ifndef     AO_TASK_STATE

#define     AO_TASK_STATE

// ----------------------------------------------------------------------------

enum        ao_task_state_t
{
            AO_TASK_STOPPED                     = (0),

            AO_TASK_READY                       = (1 << 0),

            AO_TASK_RUNNING                     = (1 << 1),

            AO_TASK_BLOCKED                     = (1 << 2),

            AO_TASK_SUSPENDED                   = (1 << 3),

            AO_TASK_ACTIVE                      = AO_TASK_READY       | AO_TASK_RUNNING,

            AO_TASK_SUSPENDABLE                 = AO_TASK_ACTIVE      | AO_TASK_BLOCKED,

            AO_TASK_STARTED                     = AO_TASK_SUSPENDABLE | AO_TASK_SUSPENDED
};

// ----------------------------------------------------------------------------

#endif

#ifndef     AO_TASK_STATE_PENDING

#define     AO_TASK_STATE_PENDING

// ----------------------------------------------------------------------------

enum        ao_task_state_pending_t
{
            AO_TASK_STOPPING                    = (1 << 0),

            AO_TASK_BLOCKING                    = (1 << 1),

            AO_TASK_SUSPENDING                  = (1 << 2),

            AO_TASK_YIELDING                    = (1 << 3)
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

#ifndef     AO_TASK

#define     AO_TASK

// ----------------------------------------------------------------------------

struct      ao_task_t
{
            ao_block_t *                        block;

            ao_task_context_t                   context;

#if         AO_TASK_COUNT

            struct
            {
                ao_uint_t                       activate;

                ao_uint_t                       block;

                ao_uint_t                       inactivate;

                ao_uint_t                       resume;

                ao_uint_t                       start;

                ao_uint_t                       stop;

                ao_uint_t                       suspend;

                ao_uint_t                       switch_in;

                ao_uint_t                       switch_out;

                ao_uint_t                       unblock;
            }
                                                count;

#endif

#if         AO_TASK_ID

            ao_uint_t                           id;

#endif

#if         AO_TASK_NAME

            char const *                        name;

#endif

            ao_proc_t                           proc;

            void *                              proc_parameter;

            ao_task_sched_t                     sched;

            ao_task_stack_t                     stack;

            ao_int_t                            started;

            ao_task_state_t                     state;

            ao_task_state_pending_t             state_pending;

            ao_int_t                            suspended;

#if         AO_TASK_TIME

            struct
            {
                struct
                {
                    ao_time_t                   activation;

                    ao_time_t                   inactivation;

                    ao_time_t                   start;

                    ao_time_t                   stop;

                    ao_time_t                   switch_in;

                    ao_time_t                   switch_out;
                }
                                                point;

                struct
                {
                    ao_time_t                   active;

                    ao_time_t                   down;

                    ao_time_t                   inactive;

                    ao_time_t                   up;
                }
                                                span;
            }
                                                time;

#endif

};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

void        ao_task_entry(                      ao_task_t const * t);

// ----------------------------------------------------------------------------

ao_uint_t   ao_task_get_count_activate(         ao_task_t const * t);

ao_uint_t   ao_task_get_count_block(            ao_task_t const * t);

ao_uint_t   ao_task_get_count_inactivate(       ao_task_t const * t);

ao_uint_t   ao_task_get_count_resume(           ao_task_t const * t);

ao_uint_t   ao_task_get_count_start(            ao_task_t const * t);

ao_uint_t   ao_task_get_count_stop(             ao_task_t const * t);

ao_uint_t   ao_task_get_count_suspend(          ao_task_t const * t);

ao_uint_t   ao_task_get_count_switch_in(        ao_task_t const * t);

ao_uint_t   ao_task_get_count_switch_out(       ao_task_t const * t);

ao_uint_t   ao_task_get_count_unblock(          ao_task_t const * t);

// ----------------------------------------------------------------------------

ao_uint_t   ao_task_get_id(                     ao_task_t const * t);

// ----------------------------------------------------------------------------

char const *

            ao_task_get_name(                   ao_task_t const * t);

// ----------------------------------------------------------------------------

ao_proc_t   ao_task_get_proc(                   ao_task_t const * t);

void *      ao_task_get_proc_parameter(         ao_task_t const * t);

// ----------------------------------------------------------------------------

ao_task_state_t

            ao_task_get_state(                  ao_task_t const * t);

ao_task_state_pending_t

            ao_task_get_state_pending(          ao_task_t const * t);

// ----------------------------------------------------------------------------

ao_time_t   ao_task_get_time_point_activation(  ao_task_t const * t);

ao_time_t   ao_task_get_time_point_inactivation(ao_task_t const * t);

ao_time_t   ao_task_get_time_point_start(       ao_task_t const * t);

ao_time_t   ao_task_get_time_point_stop(        ao_task_t const * t);

ao_time_t   ao_task_get_time_point_switch_in(   ao_task_t const * t);

ao_time_t   ao_task_get_time_point_switch_out(  ao_task_t const * t);

// ----------------------------------------------------------------------------

ao_time_t   ao_task_get_time_span_active(       ao_task_t const * t);

ao_time_t   ao_task_get_time_span_down(         ao_task_t const * t);

ao_time_t   ao_task_get_time_span_inactive(     ao_task_t const * t);

ao_time_t   ao_task_get_time_span_up(           ao_task_t const * t);

// ----------------------------------------------------------------------------

bool        ao_task_is_active(                  ao_task_t const * t);

bool        ao_task_is_blocked(                 ao_task_t const * t);

bool        ao_task_is_blocking(                ao_task_t const * t);

bool        ao_task_is_ready(                   ao_task_t const * t);

bool        ao_task_is_running(                 ao_task_t const * t);

bool        ao_task_is_started(                 ao_task_t const * t);

bool        ao_task_is_stopped(                 ao_task_t const * t);

bool        ao_task_is_stopping(                ao_task_t const * t);

bool        ao_task_is_suspendable(             ao_task_t const * t);

bool        ao_task_is_suspended(               ao_task_t const * t);

bool        ao_task_is_suspending(              ao_task_t const * t);

bool        ao_task_is_yielding(                ao_task_t const * t);

// ----------------------------------------------------------------------------

void        ao_task_resume(                     ao_task_t * t);

// ----------------------------------------------------------------------------

void        ao_task_set_count_activate(         ao_task_t * t, ao_uint_t x);

void        ao_task_set_count_block(            ao_task_t * t, ao_uint_t x);

void        ao_task_set_count_inactivate(       ao_task_t * t, ao_uint_t x);

void        ao_task_set_count_resume(           ao_task_t * t, ao_uint_t x);

void        ao_task_set_count_start(            ao_task_t * t, ao_uint_t x);

void        ao_task_set_count_stop(             ao_task_t * t, ao_uint_t x);

void        ao_task_set_count_suspend(          ao_task_t * t, ao_uint_t x);

void        ao_task_set_count_switch_in(        ao_task_t * t, ao_uint_t x);

void        ao_task_set_count_switch_out(       ao_task_t * t, ao_uint_t x);

void        ao_task_set_count_unblock(          ao_task_t * t, ao_uint_t x);

// ----------------------------------------------------------------------------

void        ao_task_set_id(                     ao_task_t * t, ao_uint_t x);

// ----------------------------------------------------------------------------

void        ao_task_set_name(                   ao_task_t * t, char const * x);

// ----------------------------------------------------------------------------

void        ao_task_set_proc(                   ao_task_t * t, ao_proc_t proc, void * parameter);

// ----------------------------------------------------------------------------

void        ao_task_set_time_span_active(       ao_task_t * t, ao_time_t x);

void        ao_task_set_time_span_down(         ao_task_t * t, ao_time_t x);

void        ao_task_set_time_span_inactive(     ao_task_t * t, ao_time_t x);

void        ao_task_set_time_span_up(           ao_task_t * t, ao_time_t x);

// ----------------------------------------------------------------------------

void        ao_task_start(                      ao_task_t * t);

// ----------------------------------------------------------------------------

void        ao_task_stop(                       ao_task_t * t);

// ----------------------------------------------------------------------------

void        ao_task_suspend(                    ao_task_t * t);

// ----------------------------------------------------------------------------

void        ao_task_wake(                       ao_task_t * t);

// ----------------------------------------------------------------------------

extern      ao_task_t                           ao_task_main;

extern      ao_task_t *             volatile    ao_task_running [AO_CORE_COUNT];

// ----------------------------------------------------------------------------
