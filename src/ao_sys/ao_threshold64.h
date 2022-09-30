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

// Thresholds.

// ----------------------------------------------------------------------------

#include <ao_async.h>
#include <ao_list.h>
#include <ao_time.h>
#include <stdbool.h>
#include <stdint.h>

// ----------------------------------------------------------------------------

typedef struct  ao_threshold64_t        ao_threshold64_t;

typedef struct  ao_threshold64_wait_t   ao_threshold64_wait_t;

// ----------------------------------------------------------------------------

typedef uint64_t (*                     ao_threshold64_adjust_t)
(
        uint64_t                        value_old,

        void *                          parameter
);

// ----------------------------------------------------------------------------

typedef bool (*                         ao_threshold64_match_t)
(
        uint64_t                        value_old,

        uint64_t                        value_new,

        void *                          parameter
);

// ----------------------------------------------------------------------------

#ifndef AO_THRESHOLD64

#define AO_THRESHOLD64

#endif

// ----------------------------------------------------------------------------

#ifndef AO_THRESHOLD64_T

#define AO_THRESHOLD64_T

// ----------------------------------------------------------------------------

struct  ao_threshold64_t
{
        ao_threshold64_adjust_t         adjust;

        void *                          adjust_parameter;

        ao_threshold64_match_t          match;

        void *                          match_parameter;

        uint64_t                        value;

        ao_list_t                       wait;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

#ifndef AO_THRESHOLD64_WAIT_T

#define AO_THRESHOLD64_WAIT_T

// ----------------------------------------------------------------------------

struct  ao_threshold64_wait_t
{
        ao_async_t                      async;

        bool                volatile    result;

        ao_threshold64_t *              threshold;

        ao_list_node_t                  threshold_wait_node;

        uint64_t            volatile    value_old;

        uint64_t            volatile    value_new;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

void    ao_threshold64_adjust
(
        ao_threshold64_t *              t,

        ao_threshold64_adjust_t         a,

        void *                          ap
);

// ----------------------------------------------------------------------------

void    ao_threshold64_add(             ao_threshold64_t * t, uint64_t x);

void    ao_threshold64_and(             ao_threshold64_t * t, uint64_t x);

void    ao_threshold64_decrement(       ao_threshold64_t * t);

void    ao_threshold64_divide(          ao_threshold64_t * t, uint64_t x);

void    ao_threshold64_increment(       ao_threshold64_t * t);

void    ao_threshold64_max(             ao_threshold64_t * t);

void    ao_threshold64_min(             ao_threshold64_t * t);

void    ao_threshold64_modulo(          ao_threshold64_t * t, uint64_t x);

void    ao_threshold64_multiply(        ao_threshold64_t * t, uint64_t x);

void    ao_threshold64_nand(            ao_threshold64_t * t, uint64_t x);

void    ao_threshold64_nor(             ao_threshold64_t * t, uint64_t x);

void    ao_threshold64_not(             ao_threshold64_t * t);

void    ao_threshold64_or(              ao_threshold64_t * t, uint64_t x);

void    ao_threshold64_set(             ao_threshold64_t * t, uint64_t x);

void    ao_threshold64_subtract(        ao_threshold64_t * t, uint64_t x);

void    ao_threshold64_subtract_from(   ao_threshold64_t * t, uint64_t x);

void    ao_threshold64_xnor(            ao_threshold64_t * t, uint64_t x);

void    ao_threshold64_xor(             ao_threshold64_t * t, uint64_t x);

// ----------------------------------------------------------------------------

void    ao_threshold64_wait(            ao_threshold64_wait_t * w, ao_time_t timeout);

void    ao_threshold64_wait_from(       ao_threshold64_wait_t * w, ao_time_t timeout, ao_time_t beginning);

void    ao_threshold64_wait_forever(    ao_threshold64_wait_t * w);

// ----------------------------------------------------------------------------

void    ao_threshold64_wait_try(        ao_threshold64_wait_t * w);

// ----------------------------------------------------------------------------

void    ao_threshold64_wait_begin(      ao_threshold64_wait_t * w);

void    ao_threshold64_wait_end(        ao_threshold64_wait_t * w);

// ----------------------------------------------------------------------------
