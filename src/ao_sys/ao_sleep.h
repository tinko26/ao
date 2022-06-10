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

// Sleep.

// ----------------------------------------------------------------------------

#include <ao_alarm.h>
#include <ao_async.h>
#include <ao_time.h>
#include <stdbool.h>

// ----------------------------------------------------------------------------

typedef struct  ao_sleep_t  ao_sleep_t;

// ----------------------------------------------------------------------------

#ifndef AO_SLEEP

#define AO_SLEEP

// ----------------------------------------------------------------------------

struct  ao_sleep_t
{
        ao_alarm_t          alarm;

        ao_async_t          async;

        ao_time_t           beginning;

        bool    volatile    result;

        ao_time_t           timeout;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

// @brief

// Puts the running task to sleep.

// @details

// If the #timeout is not equal to #AO_INFINITY, then the task will
// wake up at #ao_now() + #timeout.

// If the #timeout is equal to #AO_INFINITY, then the task will sleep forever.
// It must be woken up explicitly by another task calling #ao_task_wake().

// @return

// #true    The task has woken up after the specified timeout.

// #false   Otherwise.

bool    ao_sleep(           ao_time_t timeout);

// ----------------------------------------------------------------------------

// @brief

// Puts the running task to sleep.

// @details

// If the #timeout is not equal to #AO_INFINITY, then the task will
// wake up at #beginning + #timeout.

// If the #timeout is equal to #AO_INFINITY, then the task will sleep forever
// and the specified #beginning will be ignored. Then, it must be woken up
// explicitly by another task calling #ao_task_wake().

// @return

// #true    The task has woken up after the specified timeout.

// #false   Otherwise.

bool    ao_sleep_from(      ao_time_t timeout, ao_time_t beginning);

// ----------------------------------------------------------------------------

// @brief

// Puts the running task to sleep.

// @details

// The task will never be woken up by the operating system. It must be woken up
// explicitly by another task calling #ao_task_wake().

// @return

// #true    The task has woken up after the specified timeout.

// #false   Otherwise.

bool    ao_sleep_forever();

// ----------------------------------------------------------------------------

void    ao_sleep_begin(     ao_sleep_t * x);

void    ao_sleep_end(       ao_sleep_t * x);

// ----------------------------------------------------------------------------
