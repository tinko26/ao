---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_send_obj_to_queue.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys/ao_send_obj_to_queue.h/ 
subtitle: ""
title: "ao_send_obj_to_queue.h"
toc: true
---

# Overview

...

# Includes

```c
#include <ao_queue4obj.h>
#include <ao_send_obj.h>

#ifndef AO_SEND_OBJ_TO_QUEUE

#define AO_SEND_OBJ_TO_QUEUE

#endif

void    ao_send_obj_to_queue(ao_send_obj_t * x, ao_qinsert_obj_t * y);

```
