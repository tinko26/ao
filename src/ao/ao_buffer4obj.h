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

// Buffers for objects.

// ----------------------------------------------------------------------------

#include <stdbool.h>
#include <stddef.h>

// ----------------------------------------------------------------------------

typedef struct  ao_buffer4obj_t                 ao_buffer4obj_t;

// ----------------------------------------------------------------------------

#ifndef AO_BUFFER4OBJ

#define AO_BUFFER4OBJ

#endif

// ----------------------------------------------------------------------------

#ifndef AO_BUFFER4OBJ_COUNT_MAX

#define AO_BUFFER4OBJ_COUNT_MAX                 (false)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_BUFFER4OBJ_T

#define AO_BUFFER4OBJ_T

// ----------------------------------------------------------------------------

struct  ao_buffer4obj_t
{
        size_t                                  capacity;

        size_t                                  count;

#if     AO_BUFFER4OBJ_COUNT_MAX

        size_t                                  count_max;

#endif

        size_t                                  front;

        size_t                                  size;

        void *                                  store;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

bool    ao_buffer4obj_is_empty(                 ao_buffer4obj_t const * b);

bool    ao_buffer4obj_is_full(                  ao_buffer4obj_t const * b);

// ----------------------------------------------------------------------------

bool    ao_buffer4obj_peek_back(                ao_buffer4obj_t const * b, void * p);

bool    ao_buffer4obj_peek_front(               ao_buffer4obj_t const * b, void * p);

// ----------------------------------------------------------------------------

size_t  ao_buffer4obj_peek_range_back(          ao_buffer4obj_t const * b, void * p, size_t n_min, size_t n_max);

size_t  ao_buffer4obj_peek_range_front(         ao_buffer4obj_t const * b, void * p, size_t n_min, size_t n_max);

// ----------------------------------------------------------------------------

bool    ao_buffer4obj_pop_back(                 ao_buffer4obj_t * b, void * p);

bool    ao_buffer4obj_pop_front(                ao_buffer4obj_t * b, void * p);

// ----------------------------------------------------------------------------

size_t  ao_buffer4obj_pop_range_back(           ao_buffer4obj_t * b, void * p, size_t n_min, size_t n_max);

size_t  ao_buffer4obj_pop_range_front(          ao_buffer4obj_t * b, void * p, size_t n_min, size_t n_max);

// ----------------------------------------------------------------------------

bool    ao_buffer4obj_push_back(                ao_buffer4obj_t * b, void const * p);

bool    ao_buffer4obj_push_front(               ao_buffer4obj_t * b, void const * p);

// ----------------------------------------------------------------------------

bool    ao_buffer4obj_push_back_override(       ao_buffer4obj_t * b, void const * p);

bool    ao_buffer4obj_push_front_override(      ao_buffer4obj_t * b, void const * p);

// ----------------------------------------------------------------------------

size_t  ao_buffer4obj_push_range_back(          ao_buffer4obj_t * b, void const * p, size_t n_min, size_t n_max);

size_t  ao_buffer4obj_push_range_front(         ao_buffer4obj_t * b, void const * p, size_t n_min, size_t n_max);

// ----------------------------------------------------------------------------

size_t  ao_buffer4obj_push_range_back_override( ao_buffer4obj_t * b, void const * p, size_t n_min, size_t n_max);

size_t  ao_buffer4obj_push_range_front_override(ao_buffer4obj_t * b, void const * p, size_t n_min, size_t n_max);

// ----------------------------------------------------------------------------
