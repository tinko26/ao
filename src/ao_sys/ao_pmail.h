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

// Priority mail for asynchronous messaging.

// ----------------------------------------------------------------------------

#include <ao_async.h>
#include <ao_list.h>
#include <ao_rb.h>
#include <ao_time.h>
#include <stdbool.h>

// ----------------------------------------------------------------------------

typedef struct  ao_pmail_t          ao_pmail_t;

typedef struct  ao_pmail_fetch_t    ao_pmail_fetch_t;

typedef struct  ao_pmailbox_t       ao_pmailbox_t;

// ----------------------------------------------------------------------------

#ifndef AO_PMAIL

#define AO_PMAIL

#endif

// ----------------------------------------------------------------------------

#ifndef AO_PMAIL_T

#define AO_PMAIL_T

// ----------------------------------------------------------------------------

struct  ao_pmail_t
{
        ao_rb_node_t                pmailbox_pmail_node;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_PMAIL_FETCH_T

#define AO_PMAIL_FETCH_T

// ----------------------------------------------------------------------------

struct  ao_pmail_fetch_t
{
        ao_async_t                  async;

        ao_pmail_t *    volatile    pmail;

        ao_pmailbox_t *             pmailbox;

        ao_list_node_t              pmailbox_fetch_node;

        bool            volatile    result;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_PMAILBOX_T

#define AO_PMAILBOX_T

// ----------------------------------------------------------------------------

struct  ao_pmailbox_t
{
        ao_list_t                   fetch;

        ao_rb_t                     pmail;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

void    ao_pmail_fetch(             ao_pmail_fetch_t * f, ao_time_t timeout);

void    ao_pmail_fetch_from(        ao_pmail_fetch_t * f, ao_time_t timeout, ao_time_t beginning);

void    ao_pmail_fetch_forever(     ao_pmail_fetch_t * f);

// ----------------------------------------------------------------------------

void    ao_pmail_fetch_try(         ao_pmail_fetch_t * f);

// ----------------------------------------------------------------------------

void    ao_pmail_fetch_begin(       ao_pmail_fetch_t * f);

void    ao_pmail_fetch_end(         ao_pmail_fetch_t * f);

// ----------------------------------------------------------------------------

void    ao_pmail_post(              ao_pmailbox_t * x, ao_pmail_t * p);

// ----------------------------------------------------------------------------
