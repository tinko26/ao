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

// Stream.

// ----------------------------------------------------------------------------

#include <ao_async.h>
#include <ao_buffer.h>
#include <ao_time.h>
#include <stdbool.h>
#include <stddef.h>

// ----------------------------------------------------------------------------

typedef struct  ao_stream_t ao_stream_t;

// ----------------------------------------------------------------------------

typedef struct  ao_spop_t   ao_spop_t;

typedef struct  ao_spush_t  ao_spush_t;

// ----------------------------------------------------------------------------

#ifndef AO_STREAM

#define AO_STREAM

// ----------------------------------------------------------------------------

struct  ao_stream_t
{
        ao_buffer_t         buffer;

        ao_spop_t *         pop;

        ao_spush_t *        push;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

#ifndef AO_SPOP

#define AO_SPOP

// ----------------------------------------------------------------------------

struct  ao_spop_t
{
        ao_async_t          async;

        size_t  volatile    count;

        size_t              count_max;

        size_t              count_min;

        void *              ptr;

        bool    volatile    result;

        ao_stream_t *       stream;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_SPUSH

#define AO_SPUSH

// ----------------------------------------------------------------------------

struct  ao_spush_t
{
        ao_async_t          async;

        size_t  volatile    count;

        size_t              count_max;

        size_t              count_min;

        void *              ptr;

        bool    volatile    result;

        ao_stream_t *       stream;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

void    ao_spop(            ao_spop_t * x, ao_time_t timeout);

void    ao_spop_from(       ao_spop_t * x, ao_time_t timeout, ao_time_t beginning);

void    ao_spop_forever(    ao_spop_t * x);

// ----------------------------------------------------------------------------

void    ao_spop_try(        ao_spop_t * x);

// ----------------------------------------------------------------------------

void    ao_spop_begin(      ao_spop_t * x);

void    ao_spop_end(        ao_spop_t * x);

// ----------------------------------------------------------------------------

void    ao_spush(           ao_spush_t * x, ao_time_t timeout);

void    ao_spush_from(      ao_spush_t * x, ao_time_t timeout, ao_time_t beginning);

void    ao_spush_forever(   ao_spush_t * x);

// ----------------------------------------------------------------------------

void    ao_spush_try(       ao_spush_t * x);

// ----------------------------------------------------------------------------

void    ao_spush_begin(     ao_spush_t * x);

void    ao_spush_end(       ao_spush_t * x);

// ----------------------------------------------------------------------------

void    ao_spush_override(  ao_spush_t * x);

// ----------------------------------------------------------------------------
