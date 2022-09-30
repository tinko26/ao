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

// Heaps for pointers.

// ----------------------------------------------------------------------------

#include <stdbool.h>
#include <stddef.h>

// ----------------------------------------------------------------------------

typedef struct  ao_heap4ptr_t   ao_heap4ptr_t;

// ----------------------------------------------------------------------------

typedef bool (*                 ao_heap4ptr_less_t)
(
        void *                  pointer1,

        void *                  pointer2,

        void *                  parameter
);

// ----------------------------------------------------------------------------

#ifndef AO_HEAP4PTR

#define AO_HEAP4PTR

#endif

// ----------------------------------------------------------------------------

#ifndef AO_HEAP4PTR_COUNT_MAX

#define AO_HEAP4PTR_COUNT_MAX   (false)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_HEAP4PTR_T

#define AO_HEAP4PTR_T

// ----------------------------------------------------------------------------

struct  ao_heap4ptr_t
{
        size_t                  capacity;

        size_t                  count;

#if     AO_HEAP4PTR_COUNT_MAX

        size_t                  count_max;

#endif

        size_t *                heap1;

        size_t *                heap2;

        ao_heap4ptr_less_t      less;

        void *                  less_parameter;

        void **                 store;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

void    ao_heap4ptr_assert(     ao_heap4ptr_t const * h);

// ----------------------------------------------------------------------------

bool    ao_heap4ptr_insert(     ao_heap4ptr_t * h, void * p);

// ----------------------------------------------------------------------------

bool    ao_heap4ptr_is_empty(   ao_heap4ptr_t const * h);

bool    ao_heap4ptr_is_full(    ao_heap4ptr_t const * h);

// ----------------------------------------------------------------------------

bool    ao_heap4ptr_peek(       ao_heap4ptr_t const * h, void ** p);

// ----------------------------------------------------------------------------

bool    ao_heap4ptr_pop(        ao_heap4ptr_t * h, void ** p);

// ----------------------------------------------------------------------------
