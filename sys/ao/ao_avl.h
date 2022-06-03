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

// AVL tree.

// ----------------------------------------------------------------------------

// @seeAlso

// https://en.wikipedia.org/wiki/AVL_tree

// ----------------------------------------------------------------------------

#include <ao_int.h>
#include <stdbool.h>
#include <stddef.h>

// ----------------------------------------------------------------------------

typedef struct  ao_avl_t        ao_avl_t;

typedef struct  ao_avl_node_t   ao_avl_node_t;

// ----------------------------------------------------------------------------

typedef bool (*                 ao_avl_less_t)
(
        ao_avl_node_t *         n1,

        ao_avl_node_t *         n2,

        void *                  parameter
);

// ----------------------------------------------------------------------------

#ifndef AO_AVL

#define AO_AVL

// ----------------------------------------------------------------------------

struct  ao_avl_t
{
        ao_avl_less_t           less;

        void *                  less_parameter;

        ao_avl_node_t *         root;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_AVL_NODE

#define AO_AVL_NODE

// ----------------------------------------------------------------------------

struct  ao_avl_node_t
{
        ao_int_t                height;

        ao_avl_node_t *         left;

        ao_avl_node_t *         parent;

        ao_avl_node_t *         right;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

#ifndef ao_avl_is_empty

#define ao_avl_is_empty(x)      ((x)->root == NULL ? true : false)

#endif

// ----------------------------------------------------------------------------

void    ao_avl_assert(          ao_avl_t * x);

// ----------------------------------------------------------------------------

void    ao_avl_insert(          ao_avl_t * x, ao_avl_node_t * n);

// ----------------------------------------------------------------------------

ao_avl_node_t *

        ao_avl_max(             ao_avl_t * x);

ao_avl_node_t *

        ao_avl_min(             ao_avl_t * x);

// ----------------------------------------------------------------------------

void    ao_avl_remove(          ao_avl_t * x, ao_avl_node_t * n);

// ----------------------------------------------------------------------------
