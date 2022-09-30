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

// Rendezvous.

// ----------------------------------------------------------------------------

#include <ao_async.h>
#include <ao_time.h>
#include <stdbool.h>

// ----------------------------------------------------------------------------

typedef struct  ao_rendezvous_t         ao_rendezvous_t;

typedef struct  ao_rendezvous_wait_t    ao_rendezvous_wait_t;

// ----------------------------------------------------------------------------

typedef void (*                         ao_rendezvous_exchange_t)
(
        void *                          ptr_in_other,

        void *                          ptr_out_self,

        void *                          parameter
);

// ----------------------------------------------------------------------------

#ifndef AO_RENDEZVOUS

#define AO_RENDEZVOUS

#endif

// ----------------------------------------------------------------------------

#ifndef AO_RENDEZVOUS_T

#define AO_RENDEZVOUS_T

// ----------------------------------------------------------------------------

struct  ao_rendezvous_t
{
        ao_rendezvous_wait_t *          wait;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_RENDEZVOUS_WAIT_T

#define AO_RENDEZVOUS_WAIT_T

// ----------------------------------------------------------------------------

struct  ao_rendezvous_wait_t
{
        ao_async_t                      async;

        ao_rendezvous_exchange_t        exchange;

        void *                          exchange_parameter;

        void *                          ptr_in;

        void *                          ptr_out;

        ao_rendezvous_t *               rendezvous;

        bool                volatile    result;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

void    ao_rendezvous(                  ao_rendezvous_wait_t * w, ao_time_t timeout);

void    ao_rendezvous_from(             ao_rendezvous_wait_t * w, ao_time_t timeout, ao_time_t beginning);

void    ao_rendezvous_forever(          ao_rendezvous_wait_t * w);

// ----------------------------------------------------------------------------

void    ao_rendezvous_try(              ao_rendezvous_wait_t * w);

// ----------------------------------------------------------------------------

void    ao_rendezvous_begin(            ao_rendezvous_wait_t * w);

void    ao_rendezvous_end(              ao_rendezvous_wait_t * w);

// ----------------------------------------------------------------------------
