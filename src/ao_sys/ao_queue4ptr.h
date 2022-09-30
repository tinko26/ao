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

// Queues for pointers.

// ----------------------------------------------------------------------------

#include <ao_async.h>
#include <ao_heap4ptr.h>
#include <ao_list.h>
#include <ao_time.h>
#include <stdbool.h>

// ----------------------------------------------------------------------------

typedef struct  ao_queue4ptr_t      ao_queue4ptr_t;

// ----------------------------------------------------------------------------

typedef struct  ao_qinsert_ptr_t    ao_qinsert_ptr_t;

typedef struct  ao_qpop_ptr_t       ao_qpop_ptr_t;

// ----------------------------------------------------------------------------

#ifndef AO_QUEUE4PTR

#define AO_QUEUE4PTR

#endif

// ----------------------------------------------------------------------------

#ifndef AO_QUEUE4PTR_T

#define AO_QUEUE4PTR_T

// ----------------------------------------------------------------------------

struct  ao_queue4ptr_t
{
        ao_heap4ptr_t               heap;

        ao_list_t                   insert;

        ao_list_t                   pop;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

#ifndef AO_QINSERT_PTR_T

#define AO_QINSERT_PTR_T

// ----------------------------------------------------------------------------

struct  ao_qinsert_ptr_t
{
        ao_async_t                  async;

        void *                      ptr;

        ao_queue4ptr_t *            queue;

        ao_list_node_t              queue_insert_node;

        bool            volatile    result;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_QPOP_PTR_T

#define AO_QPOP_PTR_T

// ----------------------------------------------------------------------------

struct  ao_qpop_ptr_t
{
        ao_async_t                  async;

        void *          volatile    ptr;

        ao_queue4ptr_t *            queue;

        ao_list_node_t              queue_pop_node;

        bool            volatile    result;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

void    ao_qinsert_ptr(             ao_qinsert_ptr_t * i, ao_time_t timeout);

void    ao_qinsert_ptr_from(        ao_qinsert_ptr_t * i, ao_time_t timeout, ao_time_t beginning);

void    ao_qinsert_ptr_forever(     ao_qinsert_ptr_t * i);

// ----------------------------------------------------------------------------

void    ao_qinsert_ptr_try(         ao_qinsert_ptr_t * i);

// ----------------------------------------------------------------------------

void    ao_qinsert_ptr_begin(       ao_qinsert_ptr_t * i);

void    ao_qinsert_ptr_end(         ao_qinsert_ptr_t * i);

// ----------------------------------------------------------------------------

void    ao_qpop_ptr(                ao_qpop_ptr_t * p, ao_time_t timeout);

void    ao_qpop_ptr_from(           ao_qpop_ptr_t * p, ao_time_t timeout, ao_time_t beginning);

void    ao_qpop_ptr_forever(        ao_qpop_ptr_t * p);

// ----------------------------------------------------------------------------

void    ao_qpop_ptr_try(            ao_qpop_ptr_t * p);

// ----------------------------------------------------------------------------

void    ao_qpop_ptr_begin(          ao_qpop_ptr_t * p);

void    ao_qpop_ptr_end(            ao_qpop_ptr_t * p);

// ----------------------------------------------------------------------------
