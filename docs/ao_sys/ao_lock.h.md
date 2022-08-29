---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys/ao_lock.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_lock.h/ 
subtitle: "<code>ao_sys</code>"
title: "<code>ao_lock.h</code>"
toc: true
---

typedef struct  ao_lock_t   ao_lock_t;

#ifndef AO_LOCK

#define AO_LOCK

struct  ao_lock_t           { };

#endif

void    ao_lock(            ao_lock_t * x);

void    ao_unlock(          ao_lock_t * x);

