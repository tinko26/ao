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

// Binary semaphores.

// ----------------------------------------------------------------------------

#include <ao_async.h>
#include <ao_list.h>
#include <ao_time.h>
#include <stdbool.h>

// ----------------------------------------------------------------------------

typedef struct  ao_bsem_t       ao_bsem_t;

typedef struct  ao_bsem_take_t  ao_bsem_take_t;

// ----------------------------------------------------------------------------

#ifndef AO_BSEM

#define AO_BSEM

#endif

// ----------------------------------------------------------------------------

#ifndef AO_BSEM_T

#define AO_BSEM_T

// ----------------------------------------------------------------------------

struct  ao_bsem_t
{
        ao_list_t               take;

        bool                    taken;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_BSEM_TAKE_T

#define AO_BSEM_TAKE_T

// ----------------------------------------------------------------------------

struct  ao_bsem_take_t
{
        ao_async_t              async;

        ao_bsem_t *             bsem;

        ao_list_node_t          bsem_take_node;

        bool        volatile    result;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

void    ao_bsem_give(           ao_bsem_t * b);

// ----------------------------------------------------------------------------

bool    ao_bsem_take(           ao_bsem_t * b, ao_time_t timeout);

bool    ao_bsem_take_from(      ao_bsem_t * b, ao_time_t timeout, ao_time_t beginning);

bool    ao_bsem_take_forever(   ao_bsem_t * b);

// ----------------------------------------------------------------------------

bool    ao_bsem_take_try(       ao_bsem_t * b);

// ----------------------------------------------------------------------------

void    ao_bsem_take_begin(     ao_bsem_take_t * t);

void    ao_bsem_take_end(       ao_bsem_take_t * t);

// ----------------------------------------------------------------------------
