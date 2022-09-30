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

typedef struct  ao_threshold32_t        ao_threshold32_t;

typedef struct  ao_threshold32_wait_t   ao_threshold32_wait_t;

// ----------------------------------------------------------------------------

typedef uint32_t (*                     ao_threshold32_adjust_t)
(
        uint32_t                        value_old,

        void *                          parameter
);

// ----------------------------------------------------------------------------

typedef bool (*                         ao_threshold32_match_t)
(
        uint32_t                        value_old,

        uint32_t                        value_new,

        void *                          parameter
);

// ----------------------------------------------------------------------------

#ifndef AO_THRESHOLD32

#define AO_THRESHOLD32

#endif

// ----------------------------------------------------------------------------

#ifndef AO_THRESHOLD32_T

#define AO_THRESHOLD32_T

// ----------------------------------------------------------------------------

struct  ao_threshold32_t
{
        ao_threshold32_adjust_t         adjust;

        void *                          adjust_parameter;

        ao_threshold32_match_t          match;

        void *                          match_parameter;

        uint32_t                        value;

        ao_list_t                       wait;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

#ifndef AO_THRESHOLD32_WAIT_T

#define AO_THRESHOLD32_WAIT_T

// ----------------------------------------------------------------------------

struct  ao_threshold32_wait_t
{
        ao_async_t                      async;

        bool                volatile    result;

        ao_threshold32_t *              threshold;

        ao_list_node_t                  threshold_wait_node;

        uint32_t            volatile    value_old;

        uint32_t            volatile    value_new;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

void    ao_threshold32_adjust
(
        ao_threshold32_t *              t,

        ao_threshold32_adjust_t         a,

        void *                          ap
);

// ----------------------------------------------------------------------------

void    ao_threshold32_add(             ao_threshold32_t * t, uint32_t x);

void    ao_threshold32_and(             ao_threshold32_t * t, uint32_t x);

void    ao_threshold32_decrement(       ao_threshold32_t * t);

void    ao_threshold32_divide(          ao_threshold32_t * t, uint32_t x);

void    ao_threshold32_increment(       ao_threshold32_t * t);

void    ao_threshold32_max(             ao_threshold32_t * t);

void    ao_threshold32_min(             ao_threshold32_t * t);

void    ao_threshold32_modulo(          ao_threshold32_t * t, uint32_t x);

void    ao_threshold32_multiply(        ao_threshold32_t * t, uint32_t x);

void    ao_threshold32_nand(            ao_threshold32_t * t, uint32_t x);

void    ao_threshold32_nor(             ao_threshold32_t * t, uint32_t x);

void    ao_threshold32_not(             ao_threshold32_t * t);

void    ao_threshold32_or(              ao_threshold32_t * t, uint32_t x);

void    ao_threshold32_set(             ao_threshold32_t * t, uint32_t x);

void    ao_threshold32_subtract(        ao_threshold32_t * t, uint32_t x);

void    ao_threshold32_subtract_from(   ao_threshold32_t * t, uint32_t x);

void    ao_threshold32_xnor(            ao_threshold32_t * t, uint32_t x);

void    ao_threshold32_xor(             ao_threshold32_t * t, uint32_t x);

// ----------------------------------------------------------------------------

void    ao_threshold32_wait(            ao_threshold32_wait_t * w, ao_time_t timeout);

void    ao_threshold32_wait_from(       ao_threshold32_wait_t * w, ao_time_t timeout, ao_time_t beginning);

void    ao_threshold32_wait_forever(    ao_threshold32_wait_t * w);

// ----------------------------------------------------------------------------

void    ao_threshold32_wait_try(        ao_threshold32_wait_t * w);

// ----------------------------------------------------------------------------

void    ao_threshold32_wait_begin(      ao_threshold32_wait_t * w);

void    ao_threshold32_wait_end(        ao_threshold32_wait_t * w);

// ----------------------------------------------------------------------------
