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

// Signal.

// ----------------------------------------------------------------------------

#include <ao_async.h>
#include <ao_list.h>
#include <ao_time.h>
#include <stdbool.h>

// ----------------------------------------------------------------------------

typedef struct  ao_signal_t         ao_signal_t;

typedef struct  ao_signal_wait_t    ao_signal_wait_t;

// ----------------------------------------------------------------------------

#ifndef AO_SIGNAL

#define AO_SIGNAL

// ----------------------------------------------------------------------------

struct  ao_signal_t
{
        ao_list_t                   list;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_SIGNAL_WAIT

#define AO_SIGNAL_WAIT

// ----------------------------------------------------------------------------

struct  ao_signal_wait_t
{
        ao_async_t                  async;

        ao_list_node_t              node;

        bool            volatile    result;

        ao_signal_t *               signal;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

void    ao_signal_notify(           ao_signal_t * x);

void    ao_signal_notify_all(       ao_signal_t * x);

// ----------------------------------------------------------------------------

bool    ao_signal_wait(             ao_signal_t * x, ao_time_t timeout);

bool    ao_signal_wait_from(        ao_signal_t * x, ao_time_t timeout, ao_time_t beginning);

bool    ao_signal_wait_forever(     ao_signal_t * x);

// ----------------------------------------------------------------------------

void    ao_signal_wait_begin(       ao_signal_wait_t * x);

void    ao_signal_wait_end(         ao_signal_wait_t * x);

// ----------------------------------------------------------------------------
