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

// Flag.

// ----------------------------------------------------------------------------

#include <ao_async.h>
#include <ao_int.h>
#include <ao_list.h>
#include <ao_time.h>
#include <stdbool.h>

// ----------------------------------------------------------------------------

typedef struct  ao_flag_t       ao_flag_t;

typedef struct  ao_flag_wait_t  ao_flag_wait_t;

// ----------------------------------------------------------------------------

typedef bool (*                 ao_flag_match_t)
(
        ao_uint_t               mask,

        ao_uint_t               mask_wait,

        void *                  parameter
);

// ----------------------------------------------------------------------------

#ifndef AO_FLAG

#define AO_FLAG

// ----------------------------------------------------------------------------

struct  ao_flag_t
{
        ao_list_t               list;

        ao_uint_t               mask;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_FLAG_WAIT

#define AO_FLAG_WAIT

// ----------------------------------------------------------------------------

struct  ao_flag_wait_t
{
        ao_async_t              async;

        ao_flag_t *             flag;

        ao_uint_t               mask;

        ao_flag_match_t         match;

        void *                  match_parameter;

        ao_list_node_t          node;

        bool        volatile    result;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

void    ao_flag_mask_clear(     ao_flag_t * x, ao_uint_t bits);

void    ao_flag_mask_set(       ao_flag_t * x, ao_uint_t bits);

void    ao_flag_mask_toggle(    ao_flag_t * x, ao_uint_t bits);

// ----------------------------------------------------------------------------

bool    ao_flag_wait(           ao_flag_t * x, ao_uint_t mask, ao_flag_match_t match, void * match_parameter, ao_time_t timeout);

bool    ao_flag_wait_from(      ao_flag_t * x, ao_uint_t mask, ao_flag_match_t match, void * match_parameter, ao_time_t timeout, ao_time_t beginning);

bool    ao_flag_wait_forever(   ao_flag_t * x, ao_uint_t mask, ao_flag_match_t match, void * match_parameter);

// ----------------------------------------------------------------------------

bool    ao_flag_wait_try(       ao_flag_t * x, ao_uint_t mask, ao_flag_match_t match, void * match_parameter);

// ----------------------------------------------------------------------------

void    ao_flag_wait_begin(     ao_flag_wait_t * x);

void    ao_flag_wait_end(       ao_flag_wait_t * x);

// ----------------------------------------------------------------------------
