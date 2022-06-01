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

// Sorted list.

// ----------------------------------------------------------------------------

#include <stdbool.h>
#include <stddef.h>

// ----------------------------------------------------------------------------

typedef struct  ao_slist_t      ao_slist_t;

typedef struct  ao_slist_node_t ao_slist_node_t;

// ----------------------------------------------------------------------------

typedef bool (*                 ao_slist_less_t)
(
        ao_slist_node_t *       n1,

        ao_slist_node_t *       n2,

        void *                  parameter
);

// ----------------------------------------------------------------------------

#ifndef AO_SLIST

#define AO_SLIST

// ----------------------------------------------------------------------------

struct  ao_slist_t
{
        ao_slist_node_t *       back;

        ao_slist_node_t *       front;

        ao_slist_less_t         less;

        void *                  less_parameter;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_SLIST_NODE

#define AO_SLIST_NODE

// ----------------------------------------------------------------------------

struct  ao_slist_node_t
{
        ao_slist_node_t *       next;

        ao_slist_node_t *       prev;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

#ifndef ao_slist_is_empty

#define ao_slist_is_empty(x)    ((x)->front == NULL ? true : false)

#endif

// ----------------------------------------------------------------------------

void    ao_slist_assert(        ao_slist_t * x);

// ----------------------------------------------------------------------------

void    ao_slist_insert(        ao_slist_t * x, ao_slist_node_t * n);

// ----------------------------------------------------------------------------

ao_slist_node_t *

        ao_slist_pop_back(      ao_slist_t * x);

ao_slist_node_t *

        ao_slist_pop_front(     ao_slist_t * x);

// ----------------------------------------------------------------------------

void    ao_slist_remove(        ao_slist_t * x, ao_slist_node_t * n);

void    ao_slist_remove_all(    ao_slist_t * x);

void    ao_slist_remove_back(   ao_slist_t * x);

void    ao_slist_remove_front(  ao_slist_t * x);

// ----------------------------------------------------------------------------

void    ao_slist_update(        ao_slist_t * x, ao_slist_node_t * n);

// ----------------------------------------------------------------------------
