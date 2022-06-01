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

// Stream for pointers.

// ----------------------------------------------------------------------------

#include <ao_async.h>
#include <ao_buffer4ptr.h>
#include <ao_list.h>
#include <ao_time.h>
#include <stdbool.h>

// ----------------------------------------------------------------------------

typedef struct  ao_stream4ptr_t ao_stream4ptr_t;

// ----------------------------------------------------------------------------

typedef struct  ao_spop_ptr_t   ao_spop_ptr_t;

typedef struct  ao_spush_ptr_t  ao_spush_ptr_t;

// ----------------------------------------------------------------------------

#ifndef AO_STREAM4PTR

#define AO_STREAM4PTR

// ----------------------------------------------------------------------------

struct  ao_stream4ptr_t
{
        ao_buffer4ptr_t         buffer;

        ao_list_t               pop;

        ao_list_t               push;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

#ifndef AO_SPOP_PTR

#define AO_SPOP_PTR

// ----------------------------------------------------------------------------

struct  ao_spop_ptr_t
{
        ao_async_t              async;

        ao_list_node_t          node;

        void *      volatile    ptr;

        bool        volatile    result;

        ao_stream4ptr_t *       stream;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_SPUSH_PTR

#define AO_SPUSH_PTR

// ----------------------------------------------------------------------------

struct  ao_spush_ptr_t
{
        ao_async_t              async;

        ao_list_node_t          node;

        void *                  ptr;

        void *      volatile    ptr_override;

        bool        volatile    result;

        bool        volatile    result_override;

        ao_stream4ptr_t *       stream;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

void    ao_spop_ptr(            ao_spop_ptr_t * x, ao_time_t timeout);

void    ao_spop_ptr_from(       ao_spop_ptr_t * x, ao_time_t timeout, ao_time_t beginning);

void    ao_spop_ptr_forever(    ao_spop_ptr_t * x);

// ----------------------------------------------------------------------------

void    ao_spop_ptr_try(        ao_spop_ptr_t * x);

// ----------------------------------------------------------------------------

void    ao_spop_ptr_begin(      ao_spop_ptr_t * x);

void    ao_spop_ptr_end(        ao_spop_ptr_t * x);

// ----------------------------------------------------------------------------

void    ao_spush_acq(           ao_spush_ptr_t * x, ao_time_t timeout);

void    ao_spush_acq_from(      ao_spush_ptr_t * x, ao_time_t timeout, ao_time_t beginning);

void    ao_spush_acq_forever(   ao_spush_ptr_t * x);

// ----------------------------------------------------------------------------

void    ao_spush_acq_try(       ao_spush_ptr_t * x);

// ----------------------------------------------------------------------------

void    ao_spush_acq_begin(     ao_spush_ptr_t * x);

void    ao_spush_acq_end(       ao_spush_ptr_t * x);

// ----------------------------------------------------------------------------

void    ao_spush_acq_override(  ao_spush_ptr_t * x);

// ----------------------------------------------------------------------------

void    ao_spush_ptr(           ao_spush_ptr_t * x, ao_time_t timeout);

void    ao_spush_ptr_from(      ao_spush_ptr_t * x, ao_time_t timeout, ao_time_t beginning);

void    ao_spush_ptr_forever(   ao_spush_ptr_t * x);

// ----------------------------------------------------------------------------

void    ao_spush_ptr_try(       ao_spush_ptr_t * x);

// ----------------------------------------------------------------------------

void    ao_spush_ptr_begin(     ao_spush_ptr_t * x);

void    ao_spush_ptr_end(       ao_spush_ptr_t * x);

// ----------------------------------------------------------------------------

void    ao_spush_ptr_override(  ao_spush_ptr_t * x);

// ----------------------------------------------------------------------------
