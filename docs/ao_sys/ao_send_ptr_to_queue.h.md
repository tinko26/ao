---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_send_ptr_to_queue.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_send_ptr_to_queue.h/ 
subtitle: ""
title: "ao_send_ptr_to_queue.h"
toc: true
---

```c
#include <ao_queue4ptr.h>
#include <ao_send_ptr.h>

#ifndef AO_SEND_PTR_TO_QUEUE

#define AO_SEND_PTR_TO_QUEUE

#endif

void    ao_send_acq_to_queue(   ao_send_ptr_t * x, ao_qinsert_ptr_t * y);

void    ao_send_ptr_to_queue(   ao_send_ptr_t * x, ao_qinsert_ptr_t * y);

```
