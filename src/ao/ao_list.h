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

// List.

// ----------------------------------------------------------------------------

#include <stdbool.h>
#include <stddef.h>

// ----------------------------------------------------------------------------

typedef struct  ao_list_t       ao_list_t;

typedef struct  ao_list_node_t  ao_list_node_t;

// ----------------------------------------------------------------------------

#ifndef AO_LIST

#define AO_LIST

// ----------------------------------------------------------------------------

struct  ao_list_t
{
        ao_list_node_t *        back;

        ao_list_node_t *        front;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_LIST_NODE

#define AO_LIST_NODE

// ----------------------------------------------------------------------------

struct  ao_list_node_t
{
        ao_list_node_t *        next;

        ao_list_node_t *        prev;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

#ifndef ao_list_is_empty

#define ao_list_is_empty(x)     ((x)->front == NULL ? true : false)

#endif

// ----------------------------------------------------------------------------

void    ao_list_insert_after(   ao_list_t * x, ao_list_node_t * n1, ao_list_node_t * n2);

void    ao_list_insert_before(  ao_list_t * x, ao_list_node_t * n1, ao_list_node_t * n2);

// ----------------------------------------------------------------------------

ao_list_node_t *

        ao_list_pop_back(       ao_list_t * x);

ao_list_node_t *

        ao_list_pop_front(      ao_list_t * x);

// ----------------------------------------------------------------------------

void    ao_list_push_back(      ao_list_t * x, ao_list_node_t * n);

void    ao_list_push_front(     ao_list_t * x, ao_list_node_t * n);

// ----------------------------------------------------------------------------

void    ao_list_remove(         ao_list_t * x, ao_list_node_t * n);

void    ao_list_remove_all(     ao_list_t * x);

void    ao_list_remove_back(    ao_list_t * x);

void    ao_list_remove_front(   ao_list_t * x);

// ----------------------------------------------------------------------------

void    ao_list_reverse(        ao_list_t * x);

// ----------------------------------------------------------------------------
