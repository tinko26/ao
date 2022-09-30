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

// Numbers.

// ----------------------------------------------------------------------------

#include <ao_async.h>
#include <ao_list.h>
#include <ao_time.h>
#include <stdbool.h>
#include <stdint.h>

// ----------------------------------------------------------------------------

typedef struct  ao_num32_t      ao_num32_t;

typedef struct  ao_num32_wait_t ao_num32_wait_t;

// ----------------------------------------------------------------------------

typedef uint32_t (*             ao_num32_adjust_t)
(
        uint32_t                value_old,

        void *                  parameter
);

// ----------------------------------------------------------------------------

typedef bool (*                 ao_num32_match_t)
(
        uint32_t                value_old,

        uint32_t                value_new,

        void *                  parameter
);

// ----------------------------------------------------------------------------

#ifndef AO_NUM32

#define AO_NUM32

#endif

// ----------------------------------------------------------------------------

#ifndef AO_NUM32_T

#define AO_NUM32_T

// ----------------------------------------------------------------------------

struct  ao_num32_t
{
        uint32_t                value;

        ao_list_t               wait;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

#ifndef AO_NUM32_WAIT_T

#define AO_NUM32_WAIT_T

// ----------------------------------------------------------------------------

struct  ao_num32_wait_t
{
        ao_async_t              async;

        ao_num32_match_t        match;

        void *                  match_parameter;

        ao_num32_t *            num;

        ao_list_node_t          num_wait_node;

        bool        volatile    result;

        uint32_t    volatile    value_old;

        uint32_t    volatile    value_new;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

void    ao_num32_adjust
(
        ao_num32_t *            n,

        ao_num32_adjust_t       a,

        void *                  ap
);

// ----------------------------------------------------------------------------

void    ao_num32_add(           ao_num32_t * n, uint32_t x);

void    ao_num32_and(           ao_num32_t * n, uint32_t x);

void    ao_num32_decrement(     ao_num32_t * n);

void    ao_num32_divide(        ao_num32_t * n, uint32_t x);

void    ao_num32_increment(     ao_num32_t * n);

void    ao_num32_max(           ao_num32_t * n);

void    ao_num32_min(           ao_num32_t * n);

void    ao_num32_modulo(        ao_num32_t * n, uint32_t x);

void    ao_num32_multiply(      ao_num32_t * n, uint32_t x);

void    ao_num32_nand(          ao_num32_t * n, uint32_t x);

void    ao_num32_nor(           ao_num32_t * n, uint32_t x);

void    ao_num32_not(           ao_num32_t * n);

void    ao_num32_or(            ao_num32_t * n, uint32_t x);

void    ao_num32_set(           ao_num32_t * n, uint32_t x);

void    ao_num32_subtract(      ao_num32_t * n, uint32_t x);

void    ao_num32_subtract_from( ao_num32_t * n, uint32_t x);

void    ao_num32_xnor(          ao_num32_t * n, uint32_t x);

void    ao_num32_xor(           ao_num32_t * n, uint32_t x);

// ----------------------------------------------------------------------------

void    ao_num32_wait(          ao_num32_wait_t * w, ao_time_t timeout);

void    ao_num32_wait_from(     ao_num32_wait_t * w, ao_time_t timeout, ao_time_t beginning);

void    ao_num32_wait_forever(  ao_num32_wait_t * w);

// ----------------------------------------------------------------------------

void    ao_num32_wait_try(      ao_num32_wait_t * w);

// ----------------------------------------------------------------------------

void    ao_num32_wait_begin(    ao_num32_wait_t * w);

void    ao_num32_wait_end(      ao_num32_wait_t * w);

// ----------------------------------------------------------------------------
