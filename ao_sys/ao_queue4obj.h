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

// Queue for objects.

// ----------------------------------------------------------------------------

#include <ao_async.h>
#include <ao_heap4obj.h>
#include <ao_list.h>
#include <ao_time.h>
#include <stdbool.h>

// ----------------------------------------------------------------------------

typedef struct  ao_queue4obj_t      ao_queue4obj_t;

// ----------------------------------------------------------------------------

typedef struct  ao_qinsert_obj_t    ao_qinsert_obj_t;

typedef struct  ao_qpop_obj_t       ao_qpop_obj_t;

// ----------------------------------------------------------------------------

#ifndef AO_QUEUE4OBJ

#define AO_QUEUE4OBJ

// ----------------------------------------------------------------------------

struct  ao_queue4obj_t
{
        ao_heap4obj_t               heap;

        ao_list_t                   insert;

        ao_list_t                   pop;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

#ifndef AO_QINSERT_OBJ

#define AO_QINSERT_OBJ

// ----------------------------------------------------------------------------

struct  ao_qinsert_obj_t
{
        ao_async_t                  async;

        ao_list_node_t              node;

        void *                      ptr;

        ao_queue4obj_t *            queue;

        bool            volatile    result;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_QPOP_OBJ

#define AO_QPOP_OBJ

// ----------------------------------------------------------------------------

struct  ao_qpop_obj_t
{
        ao_async_t                  async;

        ao_list_node_t              node;

        void *                      ptr;

        ao_queue4obj_t *            queue;

        bool            volatile    result;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

void    ao_qinsert_obj(             ao_qinsert_obj_t * x, ao_time_t timeout);

void    ao_qinsert_obj_from(        ao_qinsert_obj_t * x, ao_time_t timeout, ao_time_t beginning);

void    ao_qinsert_obj_forever(     ao_qinsert_obj_t * x);

// ----------------------------------------------------------------------------

void    ao_qinsert_obj_try(         ao_qinsert_obj_t * x);

// ----------------------------------------------------------------------------

void    ao_qinsert_obj_begin(       ao_qinsert_obj_t * x);

void    ao_qinsert_obj_end(         ao_qinsert_obj_t * x);

// ----------------------------------------------------------------------------

void    ao_qpop_obj(                ao_qpop_obj_t * x, ao_time_t timeout);

void    ao_qpop_obj_from(           ao_qpop_obj_t * x, ao_time_t timeout, ao_time_t beginning);

void    ao_qpop_obj_forever(        ao_qpop_obj_t * x);

// ----------------------------------------------------------------------------

void    ao_qpop_obj_try(            ao_qpop_obj_t * x);

// ----------------------------------------------------------------------------

void    ao_qpop_obj_begin(          ao_qpop_obj_t * x);

void    ao_qpop_obj_end(            ao_qpop_obj_t * x);

// ----------------------------------------------------------------------------
