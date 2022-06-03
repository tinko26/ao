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

// Barrier.

// ----------------------------------------------------------------------------

#include <ao_async.h>
#include <ao_int.h>
#include <ao_list.h>
#include <ao_time.h>
#include <stdbool.h>

// ----------------------------------------------------------------------------

typedef struct  ao_barrier_t        ao_barrier_t;

typedef struct  ao_barrier_wait_t   ao_barrier_wait_t;

// ----------------------------------------------------------------------------

#ifndef AO_BARRIER

#define AO_BARRIER

// ----------------------------------------------------------------------------

struct  ao_barrier_t
{
        ao_uint_t                   count;

        ao_uint_t                   count_threshold;

        ao_list_t                   list;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_BARRIER_WAIT

#define AO_BARRIER_WAIT

// ----------------------------------------------------------------------------

struct  ao_barrier_wait_t
{
        ao_async_t                  async;

        ao_barrier_t *              barrier;

        ao_list_node_t              node;

        bool            volatile    result;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

bool    ao_barrier_wait(            ao_barrier_t * x, ao_time_t timeout);

bool    ao_barrier_wait_from(       ao_barrier_t * x, ao_time_t timeout, ao_time_t beginning);

bool    ao_barrier_wait_forever(    ao_barrier_t * x);

// ----------------------------------------------------------------------------

bool    ao_barrier_wait_try(        ao_barrier_t * x);

// ----------------------------------------------------------------------------

void    ao_barrier_wait_begin(      ao_barrier_wait_t * x);

void    ao_barrier_wait_end(        ao_barrier_wait_t * x);

// ----------------------------------------------------------------------------
