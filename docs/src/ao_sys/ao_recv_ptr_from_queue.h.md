---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_recv_ptr_from_queue.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys/ao_recv_ptr_from_queue.h/ 
subtitle: ""
title: "ao_recv_ptr_from_queue.h"
toc: true
---

# Overview

...

# Includes

```c
#include <ao_queue4ptr.h>
#include <ao_recv_ptr.h>

#ifndef AO_RECV_PTR_FROM_QUEUE

#define AO_RECV_PTR_FROM_QUEUE

#endif

void    ao_recv_ptr_from_queue(ao_recv_ptr_t * x, ao_qpop_ptr_t * y);

```
