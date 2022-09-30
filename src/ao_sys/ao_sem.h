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

// Counting semaphores.

// ----------------------------------------------------------------------------

#include <ao_async.h>
#include <ao_list.h>
#include <ao_time.h>
#include <ao_uint.h>
#include <stdbool.h>

// ----------------------------------------------------------------------------

typedef struct  ao_sem_t        ao_sem_t;

typedef struct  ao_sem_take_t   ao_sem_take_t;

// ----------------------------------------------------------------------------

#ifndef AO_SEM

#define AO_SEM

#endif

// ----------------------------------------------------------------------------

#ifndef AO_SEM_T

#define AO_SEM_T

// ----------------------------------------------------------------------------

struct  ao_sem_t
{
        ao_uint_t               count;

        ao_list_t               take;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_SEM_TAKE_T

#define AO_SEM_TAKE_T

// ----------------------------------------------------------------------------

struct  ao_sem_take_t
{
        ao_async_t              async;

        ao_uint_t               count;

        bool        volatile    result;

        ao_sem_t *              sem;

        ao_list_node_t          sem_take_node;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

void    ao_sem_give(            ao_sem_t * s, ao_uint_t count);

// ----------------------------------------------------------------------------

bool    ao_sem_take(            ao_sem_t * s, ao_uint_t count, ao_time_t timeout);

bool    ao_sem_take_from(       ao_sem_t * s, ao_uint_t count, ao_time_t timeout, ao_time_t beginning);

bool    ao_sem_take_forever(    ao_sem_t * s, ao_uint_t count);

// ----------------------------------------------------------------------------

bool    ao_sem_take_try(        ao_sem_t * s, ao_uint_t count);

// ----------------------------------------------------------------------------

void    ao_sem_take_begin(      ao_sem_take_t * t);

void    ao_sem_take_end(        ao_sem_take_t * t);

// ----------------------------------------------------------------------------
