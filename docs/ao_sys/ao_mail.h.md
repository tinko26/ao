---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_mail.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_mail.h/ 
subtitle: ""
title: "ao_mail.h"
toc: true
---

```c
#include <ao_async.h>
#include <ao_list.h>
#include <ao_time.h>
#include <stdbool.h>

typedef struct  ao_mail_t       ao_mail_t;

typedef struct  ao_mail_fetch_t ao_mail_fetch_t;

typedef struct  ao_mailbox_t    ao_mailbox_t;

#ifndef AO_MAIL

#define AO_MAIL

struct  ao_mail_t
{
        ao_list_node_t          node;
};

#endif

#ifndef AO_MAIL_FETCH

#define AO_MAIL_FETCH

struct  ao_mail_fetch_t
{
        ao_async_t              async;

        ao_mail_t * volatile    mail;

        ao_mailbox_t *          mailbox;

        ao_list_node_t          node;

        bool        volatile    result;
};

#endif

#ifndef AO_MAILBOX

#define AO_MAILBOX

struct  ao_mailbox_t
{
        ao_list_t               fetchers;

        ao_list_t               mails;
};

#endif

void    ao_mail_post(           ao_mailbox_t * x, ao_mail_t * m);

bool    ao_mail_fetch(          ao_mailbox_t * x, ao_mail_t ** m, ao_time_t timeout);

bool    ao_mail_fetch_from(     ao_mailbox_t * x, ao_mail_t ** m, ao_time_t timeout, ao_time_t beginning);

bool    ao_mail_fetch_forever(  ao_mailbox_t * x, ao_mail_t ** m);

bool    ao_mail_fetch_try(      ao_mailbox_t * x, ao_mail_t ** m);

void    ao_mail_fetch_begin(    ao_mail_fetch_t * x);

void    ao_mail_fetch_end(      ao_mail_fetch_t * x);

```
