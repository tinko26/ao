---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_recv_obj_from_queue.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_recv_obj_from_queue.h/ 
subtitle: "ao_sys"
title: "ao_recv_obj_from_queue.h"
toc: true
---

```c
#include <ao_queue4obj.h>
#include <ao_recv_obj.h>

#ifndef AO_RECV_OBJ_FROM_QUEUE

#define AO_RECV_OBJ_FROM_QUEUE

#endif

void    ao_recv_obj_from_queue(ao_recv_obj_t * x, ao_qpop_obj_t * y);

```
