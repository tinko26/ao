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

// Mail for asynchronous messaging.

// ----------------------------------------------------------------------------

#include <ao_async.h>
#include <ao_list.h>
#include <ao_time.h>
#include <stdbool.h>

// ----------------------------------------------------------------------------

typedef struct  ao_mail_t       ao_mail_t;

typedef struct  ao_mail_fetch_t ao_mail_fetch_t;

typedef struct  ao_mailbox_t    ao_mailbox_t;

// ----------------------------------------------------------------------------

#ifndef AO_MAIL

#define AO_MAIL

#endif

// ----------------------------------------------------------------------------

#ifndef AO_MAIL_T

#define AO_MAIL_T

// ----------------------------------------------------------------------------

struct  ao_mail_t
{
        ao_list_node_t          mailbox_mail_node;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_MAIL_FETCH_T

#define AO_MAIL_FETCH_T

// ----------------------------------------------------------------------------

struct  ao_mail_fetch_t
{
        ao_async_t              async;

        ao_mail_t * volatile    mail;

        ao_mailbox_t *          mailbox;

        ao_list_node_t          mailbox_fetch_node;

        bool        volatile    result;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_MAILBOX_T

#define AO_MAILBOX_T

// ----------------------------------------------------------------------------

struct  ao_mailbox_t
{
        ao_list_t               fetch;

        ao_list_t               mail;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

void    ao_mail_fetch(          ao_mail_fetch_t * f, ao_time_t timeout);

void    ao_mail_fetch_from(     ao_mail_fetch_t * f, ao_time_t timeout, ao_time_t beginning);

void    ao_mail_fetch_forever(  ao_mail_fetch_t * f);

// ----------------------------------------------------------------------------

void    ao_mail_fetch_try(      ao_mail_fetch_t * f);

// ----------------------------------------------------------------------------

void    ao_mail_fetch_begin(    ao_mail_fetch_t * f);

void    ao_mail_fetch_end(      ao_mail_fetch_t * f);

// ----------------------------------------------------------------------------

void    ao_mail_post(           ao_mailbox_t * x, ao_mail_t * m);

// ----------------------------------------------------------------------------
