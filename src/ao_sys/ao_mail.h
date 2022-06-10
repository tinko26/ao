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

// Mail.

// Asynchronous messaging.

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

// ----------------------------------------------------------------------------

struct  ao_mail_t
{
        ao_list_node_t          node;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_MAIL_FETCH

#define AO_MAIL_FETCH

// ----------------------------------------------------------------------------

struct  ao_mail_fetch_t
{
        ao_async_t              async;

        ao_mail_t * volatile    mail;

        ao_mailbox_t *          mailbox;

        ao_list_node_t          node;

        bool        volatile    result;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_MAILBOX

#define AO_MAILBOX

// ----------------------------------------------------------------------------

struct  ao_mailbox_t
{
        ao_list_t               fetchers;

        ao_list_t               mails;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

void    ao_mail_post(           ao_mailbox_t * x, ao_mail_t * m);

// ----------------------------------------------------------------------------

bool    ao_mail_fetch(          ao_mailbox_t * x, ao_mail_t ** m, ao_time_t timeout);

bool    ao_mail_fetch_from(     ao_mailbox_t * x, ao_mail_t ** m, ao_time_t timeout, ao_time_t beginning);

bool    ao_mail_fetch_forever(  ao_mailbox_t * x, ao_mail_t ** m);

// ----------------------------------------------------------------------------

bool    ao_mail_fetch_try(      ao_mailbox_t * x, ao_mail_t ** m);

// ----------------------------------------------------------------------------

void    ao_mail_fetch_begin(    ao_mail_fetch_t * x);

void    ao_mail_fetch_end(      ao_mail_fetch_t * x);

// ----------------------------------------------------------------------------
