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

// Manual-reset events.

// ----------------------------------------------------------------------------

#include <ao_async.h>
#include <ao_list.h>
#include <ao_time.h>
#include <stdbool.h>

// ----------------------------------------------------------------------------

typedef struct  ao_mre_t        ao_mre_t;

typedef struct  ao_mre_wait_t   ao_mre_wait_t;

// ----------------------------------------------------------------------------

#ifndef AO_MRE

#define AO_MRE

#endif

// ----------------------------------------------------------------------------

#ifndef AO_MRE_T

#define AO_MRE_T

// ----------------------------------------------------------------------------

struct  ao_mre_t
{
        bool                    state;

        ao_list_t               wait;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_MRE_WAIT_T

#define AO_MRE_WAIT_T

// ----------------------------------------------------------------------------

struct  ao_mre_wait_t
{
        ao_async_t              async;

        ao_mre_t *              mre;

        ao_list_node_t          mre_wait_node;

        bool        volatile    result;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

void    ao_mre_reset(           ao_mre_t * m);

void    ao_mre_set(             ao_mre_t * m);

// ----------------------------------------------------------------------------

bool    ao_mre_wait(            ao_mre_t * m, ao_time_t timeout);

bool    ao_mre_wait_from(       ao_mre_t * m, ao_time_t timeout, ao_time_t beginning);

bool    ao_mre_wait_forever(    ao_mre_t * m);

// ----------------------------------------------------------------------------

bool    ao_mre_wait_try(        ao_mre_t * m);

// ----------------------------------------------------------------------------

void    ao_mre_wait_begin(      ao_mre_wait_t * w);

void    ao_mre_wait_end(        ao_mre_wait_t * w);

// ----------------------------------------------------------------------------
