---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_await.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_await.h/ 
subtitle: ""
title: "ao_await.h"
toc: true
---

# Overview

...

# Includes

```c
#include <ao_async.h>
#include <ao_time.h>

#ifndef AO_AWAIT

#define AO_AWAIT

#endif

void    ao_await(               ao_async_t * x,     ao_time_t timeout);

void    ao_await_from(          ao_async_t * x,     ao_time_t timeout, ao_time_t beginning);

void    ao_await_forever(       ao_async_t * x);

void    ao_await_all(           ao_async_all_t * x, ao_time_t timeout);

void    ao_await_all_from(      ao_async_all_t * x, ao_time_t timeout, ao_time_t beginning);

void    ao_await_all_forever(   ao_async_all_t * x);

void    ao_await_any(           ao_async_any_t * x, ao_time_t timeout);

void    ao_await_any_from(      ao_async_any_t * x, ao_time_t timeout, ao_time_t beginning);

void    ao_await_any_forever(   ao_async_any_t * x);

```
