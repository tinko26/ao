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

// Counter.

// ----------------------------------------------------------------------------

#include <ao_async.h>
#include <ao_list.h>
#include <ao_time.h>
#include <ao_uint.h>
#include <stdbool.h>

// ----------------------------------------------------------------------------

typedef struct  ao_counter_t        ao_counter_t;

typedef struct  ao_counter_wait_t   ao_counter_wait_t;

// ----------------------------------------------------------------------------

typedef ao_uint_t (*                ao_counter_adjust_t)
(
        ao_uint_t                   value,

        void *                      parameter
);

typedef bool (*                     ao_counter_match_t)
(
        ao_uint_t                   value,

        ao_uint_t                   value_wait,

        void *                      parameter
);

// ----------------------------------------------------------------------------

#ifndef AO_COUNTER

#define AO_COUNTER

// ----------------------------------------------------------------------------

struct  ao_counter_t
{
        ao_list_t                   list;

        ao_uint_t                   value;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_COUNTER_WAIT

#define AO_COUNTER_WAIT

// ----------------------------------------------------------------------------

struct  ao_counter_wait_t
{
        ao_async_t                  async;

        ao_counter_t *              counter;

        ao_counter_match_t          match;

        void *                      match_parameter;

        ao_list_node_t              node;

        bool            volatile    result;

        ao_uint_t                   value;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

void    ao_counter_adjust(          ao_counter_t * x, ao_counter_adjust_t adjust, void * adjust_parameter);

// ----------------------------------------------------------------------------

void    ao_counter_add(             ao_counter_t * x, ao_uint_t value);

void    ao_counter_decrement(       ao_counter_t * x);

void    ao_counter_divide(          ao_counter_t * x, ao_uint_t value);

void    ao_counter_increment(       ao_counter_t * x);

void    ao_counter_modulo(          ao_counter_t * x, ao_uint_t value);

void    ao_counter_multiply(        ao_counter_t * x, ao_uint_t value);

void    ao_counter_set(             ao_counter_t * x, ao_uint_t value);

void    ao_counter_subtract(        ao_counter_t * x, ao_uint_t value);

void    ao_counter_subtract_from(   ao_counter_t * x, ao_uint_t value);

// ----------------------------------------------------------------------------

bool    ao_counter_wait(            ao_counter_t * x, ao_uint_t value, ao_counter_match_t match, void * match_parameter, ao_time_t timeout);

bool    ao_counter_wait_from(       ao_counter_t * x, ao_uint_t value, ao_counter_match_t match, void * match_parameter, ao_time_t timeout, ao_time_t beginning);

bool    ao_counter_wait_forever(    ao_counter_t * x, ao_uint_t value, ao_counter_match_t match, void * match_parameter);

// ----------------------------------------------------------------------------

bool    ao_counter_wait_try(        ao_counter_t * x, ao_uint_t value, ao_counter_match_t match, void * match_parameter);

// ----------------------------------------------------------------------------

void    ao_counter_wait_begin(      ao_counter_wait_t * x);

void    ao_counter_wait_end(        ao_counter_wait_t * x);

// ----------------------------------------------------------------------------
