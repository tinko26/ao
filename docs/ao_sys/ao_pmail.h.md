---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_pmail.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_pmail.h/ 
subtitle: "ao_sys"
title: "ao_pmail.h"
toc: true
---

```c
#include <ao_async.h>
#include <ao_list.h>
#include <ao_rb.h>
#include <ao_time.h>
#include <stdbool.h>

typedef struct  ao_pmail_t          ao_pmail_t;

typedef struct  ao_pmail_fetch_t    ao_pmail_fetch_t;

typedef struct  ao_pmailbox_t       ao_pmailbox_t;

#ifndef AO_PMAIL

#define AO_PMAIL

struct  ao_pmail_t
{
        ao_rb_node_t                node;
};

#endif

#ifndef AO_PMAIL_FETCH

#define AO_PMAIL_FETCH

struct  ao_pmail_fetch_t
{
        ao_async_t                  async;

        ao_pmail_t *    volatile    mail;

        ao_pmailbox_t *             mailbox;

        ao_list_node_t              node;

        bool            volatile    result;
};

#endif

#ifndef AO_PMAILBOX

#define AO_PMAILBOX

struct  ao_pmailbox_t
{
        ao_list_t                   fetchers;

        ao_rb_t                     mails;
};

#endif

void    ao_pmail_post(              ao_pmailbox_t * x, ao_pmail_t * m);

bool    ao_pmail_fetch(             ao_pmailbox_t * x, ao_pmail_t ** m, ao_time_t timeout);

bool    ao_pmail_fetch_from(        ao_pmailbox_t * x, ao_pmail_t ** m, ao_time_t timeout, ao_time_t beginning);

bool    ao_pmail_fetch_forever(     ao_pmailbox_t * x, ao_pmail_t ** m);

bool    ao_pmail_fetch_try(         ao_pmailbox_t * x, ao_pmail_t ** m);

void    ao_pmail_fetch_begin(       ao_pmail_fetch_t * x);

void    ao_pmail_fetch_end(         ao_pmail_fetch_t * x);

```
