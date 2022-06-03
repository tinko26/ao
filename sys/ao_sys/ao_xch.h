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

// Exchange.

// Request-reply messaging.

// ----------------------------------------------------------------------------

#include <ao_async.h>
#include <ao_list.h>
#include <ao_task.h>
#include <ao_time.h>
#include <stdbool.h>

// ----------------------------------------------------------------------------

typedef struct  ao_xch_t                ao_xch_t;

typedef struct  ao_xch_client_t         ao_xch_client_t;

typedef struct  ao_xch_server_t         ao_xch_server_t;

// ----------------------------------------------------------------------------

#ifndef AO_XCH

#define AO_XCH

// ----------------------------------------------------------------------------

struct  ao_xch_t
{
        ao_list_t                       clients;

        ao_list_t                       servers;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_XCH_CLIENT

#define AO_XCH_CLIENT

// ----------------------------------------------------------------------------

struct  ao_xch_client_t
{
        ao_async_t                      async;

#if     AO_TASK_INHERITANCE

        ao_task_master_t                master;

#endif

        ao_list_node_t                  node;

        bool                volatile    result;

        ao_xch_server_t *   volatile    server;

#if     AO_TASK_INHERITANCE

        ao_task_t *                     task;

#endif

        ao_xch_t *                      xch;
};

// ----------------------------------------------------------------------------

#endif

#ifndef AO_XCH_SERVER

#define AO_XCH_SERVER

// ----------------------------------------------------------------------------

struct  ao_xch_server_t
{
        ao_async_t                      async;

        ao_xch_client_t *   volatile    client;

        ao_list_node_t                  node;

        bool                volatile    result;

#if     AO_TASK_INHERITANCE

        ao_task_slave_t                 slave;

        ao_task_t *                     task;

#endif

        ao_xch_t *                      xch;
};

// ----------------------------------------------------------------------------

#endif

// ----------------------------------------------------------------------------

void    ao_xch_client(                  ao_xch_client_t * x, ao_time_t timeout);

void    ao_xch_client_from(             ao_xch_client_t * x, ao_time_t timeout, ao_time_t beginning);

void    ao_xch_client_forever(          ao_xch_client_t * x);

// ----------------------------------------------------------------------------

void    ao_xch_client_begin(            ao_xch_client_t * x);

void    ao_xch_client_end(              ao_xch_client_t * x);

// ----------------------------------------------------------------------------

void    ao_xch_server(                  ao_xch_server_t * x, ao_time_t timeout);

void    ao_xch_server_from(             ao_xch_server_t * x, ao_time_t timeout, ao_time_t beginning);

void    ao_xch_server_forever(          ao_xch_server_t * x);

// ----------------------------------------------------------------------------

void    ao_xch_server_try(              ao_xch_server_t * x);

// ----------------------------------------------------------------------------

void    ao_xch_server_begin(            ao_xch_server_t * x);

void    ao_xch_server_end(              ao_xch_server_t * x);

// ----------------------------------------------------------------------------

void    ao_xch_server_reply(            ao_xch_server_t * x);

// ----------------------------------------------------------------------------
