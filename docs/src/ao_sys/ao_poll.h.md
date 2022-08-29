---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_poll.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys/ao_poll.h/ 
subtitle: ""
title: "ao_poll.h"
toc: true
---

# Overview

...

# Includes

```c
#include <ao_async.h>
#include <ao_time.h>

#ifndef AO_POLL

#define AO_POLL

#endif

void    ao_poll(            ao_async_t const * x, ao_time_t timeout);

void    ao_poll_from(       ao_async_t const * x, ao_time_t timeout, ao_time_t beginning);

void    ao_poll_forever(    ao_async_t const * x);

void    ao_poll_all(        ao_async_all_t   * x, ao_time_t timeout);

void    ao_poll_all_from(   ao_async_all_t   * x, ao_time_t timeout, ao_time_t beginning);

void    ao_poll_all_forever(ao_async_all_t   * x);

void    ao_poll_any(        ao_async_any_t   * x, ao_time_t timeout);

void    ao_poll_any_from(   ao_async_any_t   * x, ao_time_t timeout, ao_time_t beginning);

void    ao_poll_any_forever(ao_async_any_t   * x);

```
