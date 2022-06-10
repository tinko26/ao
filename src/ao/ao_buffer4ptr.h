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

// Buffer for pointers.

// ----------------------------------------------------------------------------

#include <stdbool.h>
#include <stddef.h>

// ----------------------------------------------------------------------------

typedef struct  ao_buffer4ptr_t                 ao_buffer4ptr_t;

// ----------------------------------------------------------------------------

#ifndef AO_BUFFER4PTR_COUNT_MAX

#define AO_BUFFER4PTR_COUNT_MAX                 (false)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_BUFFER4PTR

#define AO_BUFFER4PTR

// ----------------------------------------------------------------------------

struct  ao_buffer4ptr_t
{
        size_t                                  capacity;

        size_t                                  count;

#if     AO_BUFFER4PTR_COUNT_MAX

        size_t                                  count_max;

#endif

        size_t                                  front;

        void **                                 store;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

#ifndef ao_buffer4ptr_is_empty

#define ao_buffer4ptr_is_empty(x)               ((x)->count == 0 ? true : false)

#endif

#ifndef ao_buffer4ptr_is_full

#define ao_buffer4ptr_is_full(x)                ((x)->count == (x)->capacity ? true : false)

#endif

// ----------------------------------------------------------------------------

bool    ao_buffer4ptr_peek_back(                ao_buffer4ptr_t const * x, void ** p);

bool    ao_buffer4ptr_peek_front(               ao_buffer4ptr_t const * x, void ** p);

// ----------------------------------------------------------------------------

size_t  ao_buffer4ptr_peek_range_back(          ao_buffer4ptr_t const * x, void ** p, size_t n_min, size_t n_max);

size_t  ao_buffer4ptr_peek_range_front(         ao_buffer4ptr_t const * x, void ** p, size_t n_min, size_t n_max);

// ----------------------------------------------------------------------------

bool    ao_buffer4ptr_pop_back(                 ao_buffer4ptr_t * x, void ** p);

bool    ao_buffer4ptr_pop_front(                ao_buffer4ptr_t * x, void ** p);

// ----------------------------------------------------------------------------

size_t  ao_buffer4ptr_pop_range_back(           ao_buffer4ptr_t * x, void ** p, size_t n_min, size_t n_max);

size_t  ao_buffer4ptr_pop_range_front(          ao_buffer4ptr_t * x, void ** p, size_t n_min, size_t n_max);

// ----------------------------------------------------------------------------

bool    ao_buffer4ptr_push_back(                ao_buffer4ptr_t * x, void * p);

bool    ao_buffer4ptr_push_back_override(       ao_buffer4ptr_t * x, void * p);

bool    ao_buffer4ptr_push_front(               ao_buffer4ptr_t * x, void * p);

bool    ao_buffer4ptr_push_front_override(      ao_buffer4ptr_t * x, void * p);

// ----------------------------------------------------------------------------

size_t  ao_buffer4ptr_push_range_back(          ao_buffer4ptr_t * x, void * const * p, size_t n_min, size_t n_max);

size_t  ao_buffer4ptr_push_range_back_override( ao_buffer4ptr_t * x, void * const * p, size_t n_min, size_t n_max);

size_t  ao_buffer4ptr_push_range_front(         ao_buffer4ptr_t * x, void * const * p, size_t n_min, size_t n_max);

size_t  ao_buffer4ptr_push_range_front_override(ao_buffer4ptr_t * x, void * const * p, size_t n_min, size_t n_max);

// ----------------------------------------------------------------------------
