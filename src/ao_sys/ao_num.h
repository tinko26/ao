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
#include <ao_uint.h>
#include <stdbool.h>

// ----------------------------------------------------------------------------

typedef struct  ao_num_t        ao_num_t;

typedef struct  ao_num_wait_t   ao_num_wait_t;

// ----------------------------------------------------------------------------

typedef ao_uint_t (*            ao_num_adjust_t)
(
        ao_uint_t               value_old,

        void *                  parameter
);

// ----------------------------------------------------------------------------

typedef bool (*                 ao_num_match_t)
(
        ao_uint_t               value_old,

        ao_uint_t               value_new,

        void *                  parameter
);

// ----------------------------------------------------------------------------

#ifndef AO_NUM

#define AO_NUM

#endif

// ----------------------------------------------------------------------------

#ifndef AO_NUM_T

#define AO_NUM_T

// ----------------------------------------------------------------------------

struct  ao_num_t
{
        ao_uint_t               value;

        ao_list_t               wait;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

#ifndef AO_NUM_WAIT_T

#define AO_NUM_WAIT_T

// ----------------------------------------------------------------------------

struct  ao_num_wait_t
{
        ao_async_t              async;

        ao_num_match_t          match;

        void *                  match_parameter;

        ao_num_t *              num;

        ao_list_node_t          num_wait_node;

        bool        volatile    result;

        ao_uint_t   volatile    value_old;

        ao_uint_t   volatile    value_new;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

void    ao_num_adjust
(
        ao_num_t *              n,

        ao_num_adjust_t         a,

        void *                  ap
);

// ----------------------------------------------------------------------------

void    ao_num_add(             ao_num_t * n, ao_uint_t x);

void    ao_num_and(             ao_num_t * n, ao_uint_t x);

void    ao_num_decrement(       ao_num_t * n);

void    ao_num_divide(          ao_num_t * n, ao_uint_t x);

void    ao_num_increment(       ao_num_t * n);

void    ao_num_max(             ao_num_t * n);

void    ao_num_min(             ao_num_t * n);

void    ao_num_modulo(          ao_num_t * n, ao_uint_t x);

void    ao_num_multiply(        ao_num_t * n, ao_uint_t x);

void    ao_num_nand(            ao_num_t * n, ao_uint_t x);

void    ao_num_nor(             ao_num_t * n, ao_uint_t x);

void    ao_num_not(             ao_num_t * n);

void    ao_num_or(              ao_num_t * n, ao_uint_t x);

void    ao_num_set(             ao_num_t * n, ao_uint_t x);

void    ao_num_subtract(        ao_num_t * n, ao_uint_t x);

void    ao_num_subtract_from(   ao_num_t * n, ao_uint_t x);

void    ao_num_xnor(            ao_num_t * n, ao_uint_t x);

void    ao_num_xor(             ao_num_t * n, ao_uint_t x);

// ----------------------------------------------------------------------------

void    ao_num_wait(            ao_num_wait_t * w, ao_time_t timeout);

void    ao_num_wait_from(       ao_num_wait_t * w, ao_time_t timeout, ao_time_t beginning);

void    ao_num_wait_forever(    ao_num_wait_t * w);

// ----------------------------------------------------------------------------

void    ao_num_wait_try(        ao_num_wait_t * w);

// ----------------------------------------------------------------------------

void    ao_num_wait_begin(      ao_num_wait_t * w);

void    ao_num_wait_end(        ao_num_wait_t * w);

// ----------------------------------------------------------------------------
