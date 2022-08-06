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

// Threshold.

// ----------------------------------------------------------------------------

#include <ao_async.h>
#include <ao_list.h>
#include <ao_time.h>
#include <ao_uint.h>
#include <stdbool.h>

// ----------------------------------------------------------------------------

typedef struct  ao_threshold_t      ao_threshold_t;

typedef struct  ao_threshold_wait_t ao_threshold_wait_t;

// ----------------------------------------------------------------------------

typedef ao_uint_t (*                ao_threshold_adjust_t)
(
        ao_uint_t                   value,

        void *                      parameter
);

typedef bool (*                     ao_threshold_match_t)
(
        ao_uint_t                   value,

        void *                      parameter
);

// ----------------------------------------------------------------------------

#ifndef AO_THRESHOLD

#define AO_THRESHOLD

// ----------------------------------------------------------------------------

struct  ao_threshold_t
{
        ao_threshold_adjust_t       adjust;

        void *                      adjust_parameter;

        ao_list_t                   list;

        ao_threshold_match_t        match;

        void *                      match_parameter;

        ao_uint_t                   value;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_THRESHOLD_WAIT

#define AO_THRESHOLD_WAIT

// ----------------------------------------------------------------------------

struct  ao_threshold_wait_t
{
        ao_async_t                  async;

        ao_list_node_t              node;

        bool            volatile    result;

        ao_threshold_t *            threshold;

};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

void    ao_threshold_adjust(        ao_threshold_t * x, ao_threshold_adjust_t adjust, void * adjust_parameter);

// ----------------------------------------------------------------------------

void    ao_threshold_add(           ao_threshold_t * x, ao_uint_t value);

void    ao_threshold_decrement(     ao_threshold_t * x);

void    ao_threshold_divide(        ao_threshold_t * x, ao_uint_t value);

void    ao_threshold_increment(     ao_threshold_t * x);

void    ao_threshold_modulo(        ao_threshold_t * x, ao_uint_t value);

void    ao_threshold_multiply(      ao_threshold_t * x, ao_uint_t value);

void    ao_threshold_set(           ao_threshold_t * x, ao_uint_t value);

void    ao_threshold_subtract(      ao_threshold_t * x, ao_uint_t value);

void    ao_threshold_subtract_from( ao_threshold_t * x, ao_uint_t value);

// ----------------------------------------------------------------------------

bool    ao_threshold_wait(          ao_threshold_t * x, ao_time_t timeout);

bool    ao_threshold_wait_from(     ao_threshold_t * x, ao_time_t timeout, ao_time_t beginning);

bool    ao_threshold_wait_forever(  ao_threshold_t * x);

// ----------------------------------------------------------------------------

bool    ao_threshold_wait_try(      ao_threshold_t * x);

// ----------------------------------------------------------------------------

void    ao_threshold_wait_begin(    ao_threshold_wait_t * x);

void    ao_threshold_wait_end(      ao_threshold_wait_t * x);

// ----------------------------------------------------------------------------
