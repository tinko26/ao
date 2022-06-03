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

// Async.

// ----------------------------------------------------------------------------

#include <ao_func.h>
#include <stdbool.h>
#include <stddef.h>

// ----------------------------------------------------------------------------

typedef struct  ao_async_t      ao_async_t;

typedef struct  ao_async_all_t  ao_async_all_t;

typedef struct  ao_async_any_t  ao_async_any_t;

// ----------------------------------------------------------------------------

#ifndef AO_ASYNC

#define AO_ASYNC

// ----------------------------------------------------------------------------

struct  ao_async_t
{
        ao_proc_t               callback;

        void *                  callback_parameter;

        bool        volatile    checked;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_ASYNC_ALL

#define AO_ASYNC_ALL

// ----------------------------------------------------------------------------

struct  ao_async_all_t
{
        ao_async_t              async;

        size_t                  count;

        size_t      volatile    count_checked;

        bool        volatile    result;

        ao_async_t **           store;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_ASYNC_ANY

#define AO_ASYNC_ANY

// ----------------------------------------------------------------------------

struct  ao_async_any_t
{
        ao_async_t              async;

        size_t                  count;

        bool        volatile    result;

        ao_async_t **           store;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

void    ao_async_all_begin(     ao_async_all_t * x);

void    ao_async_all_end(       ao_async_all_t * x);

// ----------------------------------------------------------------------------

void    ao_async_all_try(       ao_async_all_t * x);

// ----------------------------------------------------------------------------

void    ao_async_any_begin(     ao_async_any_t * x);

void    ao_async_any_end(       ao_async_any_t * x);

// ----------------------------------------------------------------------------

void    ao_async_any_try(       ao_async_any_t * x);

// ----------------------------------------------------------------------------
