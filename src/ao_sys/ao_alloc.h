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

// Allocator.

// ----------------------------------------------------------------------------

#include <stdbool.h>
#include <stddef.h>

// ----------------------------------------------------------------------------

typedef struct  ao_acquired_t   ao_acquired_t;

typedef struct  ao_released_t   ao_released_t;

typedef struct  ao_retained_t   ao_retained_t;

// ----------------------------------------------------------------------------

#ifndef AO_ALLOC

#define AO_ALLOC                (2)

#endif

// ----------------------------------------------------------------------------

#if     AO_ALLOC ==             (0)

#include <ao_alloc_0.h>

#elif   AO_ALLOC ==             (1)

#include <ao_alloc_1.h>

#elif   AO_ALLOC ==             (2)

#include <ao_alloc_2.h>

#endif

// ----------------------------------------------------------------------------

#ifndef AO_ACQUIRED

#define AO_ACQUIRED             (false)

#endif

#ifndef AO_RELEASED

#define AO_RELEASED             (false)

#endif

#ifndef AO_RETAINED

#define AO_RETAINED             (false)

#endif

// ----------------------------------------------------------------------------

#ifndef AO_ACQUIRED_T

#define AO_ACQUIRED_T

// ----------------------------------------------------------------------------

struct  ao_acquired_t
{
        void *                  ptr;

        bool                    result;

        size_t                  size_body;

        size_t                  size_body_requested;

        size_t                  size_head;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_RELEASED_T

#define AO_RELEASED_T

// ----------------------------------------------------------------------------

struct  ao_released_t
{
        void *                  ptr;

        size_t                  ref;

        bool                    result;

        size_t                  size_body;

        size_t                  size_head;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_RETAINED_T

#define AO_RETAINED_T

// ----------------------------------------------------------------------------

struct  ao_retained_t
{
        void *                  ptr;

        size_t                  ref;

        bool                    result;

        size_t                  size_body;

        size_t                  size_head;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

void *  ao_acquire(             size_t size);

// ----------------------------------------------------------------------------

void    ao_acquired(            ao_acquired_t const * a);

// ----------------------------------------------------------------------------

bool    ao_release(             void * ptr);

// ----------------------------------------------------------------------------

void    ao_released(            ao_released_t const * r);

// ----------------------------------------------------------------------------

bool    ao_retain(              void * ptr);

// ----------------------------------------------------------------------------

void    ao_retained(            ao_retained_t const * r);

// ----------------------------------------------------------------------------

#ifndef ao_new

#define ao_new(type)                                                        \
(                                                                           \
        (type *)                                                            \
        ao_acquire                                                          \
        (                                                                   \
            sizeof(type)                                                    \
        )                                                                   \
)

#endif

#ifndef ao_delete

#define ao_delete(ptr)          ao_release(ptr)

#endif

// ----------------------------------------------------------------------------
