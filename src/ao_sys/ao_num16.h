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

typedef struct  ao_num16_t      ao_num16_t;

typedef struct  ao_num16_wait_t ao_num16_wait_t;

// ----------------------------------------------------------------------------

typedef uint16_t (*             ao_num16_adjust_t)
(
        uint16_t                value_old,

        void *                  parameter
);

// ----------------------------------------------------------------------------

typedef bool (*                 ao_num16_match_t)
(
        uint16_t                value_old,

        uint16_t                value_new,

        void *                  parameter
);

// ----------------------------------------------------------------------------

#ifndef AO_NUM16

#define AO_NUM16

#endif

// ----------------------------------------------------------------------------

#ifndef AO_NUM16_T

#define AO_NUM16_T

// ----------------------------------------------------------------------------

struct  ao_num16_t
{
        uint16_t                value;

        ao_list_t               wait;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

#ifndef AO_NUM16_WAIT_T

#define AO_NUM16_WAIT_T

// ----------------------------------------------------------------------------

struct  ao_num16_wait_t
{
        ao_async_t              async;

        ao_num16_match_t        match;

        void *                  match_parameter;

        ao_num16_t *            num;

        ao_list_node_t          num_wait_node;

        bool        volatile    result;

        uint16_t    volatile    value_old;

        uint16_t    volatile    value_new;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

void    ao_num16_adjust
(
        ao_num16_t *            n,

        ao_num16_adjust_t       a,

        void *                  ap
);

// ----------------------------------------------------------------------------

void    ao_num16_add(           ao_num16_t * n, uint16_t x);

void    ao_num16_and(           ao_num16_t * n, uint16_t x);

void    ao_num16_decrement(     ao_num16_t * n);

void    ao_num16_divide(        ao_num16_t * n, uint16_t x);

void    ao_num16_increment(     ao_num16_t * n);

void    ao_num16_max(           ao_num16_t * n);

void    ao_num16_min(           ao_num16_t * n);

void    ao_num16_modulo(        ao_num16_t * n, uint16_t x);

void    ao_num16_multiply(      ao_num16_t * n, uint16_t x);

void    ao_num16_nand(          ao_num16_t * n, uint16_t x);

void    ao_num16_nor(           ao_num16_t * n, uint16_t x);

void    ao_num16_not(           ao_num16_t * n);

void    ao_num16_or(            ao_num16_t * n, uint16_t x);

void    ao_num16_set(           ao_num16_t * n, uint16_t x);

void    ao_num16_subtract(      ao_num16_t * n, uint16_t x);

void    ao_num16_subtract_from( ao_num16_t * n, uint16_t x);

void    ao_num16_xnor(          ao_num16_t * n, uint16_t x);

void    ao_num16_xor(           ao_num16_t * n, uint16_t x);

// ----------------------------------------------------------------------------

void    ao_num16_wait(          ao_num16_wait_t * w, ao_time_t timeout);

void    ao_num16_wait_from(     ao_num16_wait_t * w, ao_time_t timeout, ao_time_t beginning);

void    ao_num16_wait_forever(  ao_num16_wait_t * w);

// ----------------------------------------------------------------------------

void    ao_num16_wait_try(      ao_num16_wait_t * w);

// ----------------------------------------------------------------------------

void    ao_num16_wait_begin(    ao_num16_wait_t * w);

void    ao_num16_wait_end(      ao_num16_wait_t * w);

// ----------------------------------------------------------------------------
