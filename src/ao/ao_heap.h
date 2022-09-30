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

// Heaps.

// ----------------------------------------------------------------------------

#include <ao_uint.h>
#include <stdbool.h>
#include <stddef.h>

// ----------------------------------------------------------------------------

typedef struct  ao_heap_t       ao_heap_t;

typedef struct  ao_heap_node_t  ao_heap_node_t;

// ----------------------------------------------------------------------------

typedef bool (*                 ao_heap_less_t)
(
        ao_heap_node_t const *  node1,

        ao_heap_node_t const *  node2,

        void *                  parameter
);

// ----------------------------------------------------------------------------

#ifndef AO_HEAP

#define AO_HEAP

#endif

// ----------------------------------------------------------------------------

#ifndef AO_HEAP_COUNT_MAX

#define AO_HEAP_COUNT_MAX       (false)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_HEAP_T

#define AO_HEAP_T

// ----------------------------------------------------------------------------

struct  ao_heap_t
{
        ao_uint_t               count;

#if AO_HEAP_COUNT_MAX

        ao_uint_t               count_max;

#endif

        ao_heap_less_t          less;

        void *                  less_parameter;

        ao_heap_node_t *        root;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_HEAP_NODE_T

#define AO_HEAP_NODE_T

// ----------------------------------------------------------------------------

struct  ao_heap_node_t
{
        ao_heap_node_t *        left;

        ao_heap_node_t *        parent;

        ao_heap_node_t *        right;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

void    ao_heap_assert(         ao_heap_t const * h);

// ----------------------------------------------------------------------------

void    ao_heap_insert(         ao_heap_t * h, ao_heap_node_t * n);

// ----------------------------------------------------------------------------

bool    ao_heap_is_empty(       ao_heap_t const * h);

// ----------------------------------------------------------------------------

ao_heap_node_t *

        ao_heap_peek(           ao_heap_t const * h);

// ----------------------------------------------------------------------------

ao_heap_node_t *

        ao_heap_pop(            ao_heap_t * h);

// ----------------------------------------------------------------------------

void    ao_heap_remove(         ao_heap_t * h, ao_heap_node_t * n);

// ----------------------------------------------------------------------------
