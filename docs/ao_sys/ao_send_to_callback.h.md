---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_send_to_callback.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_send_to_callback.h/ 
subtitle: ""
title: "ao_send_to_callback.h"
toc: true
---

```c
#include <ao_send.h>

#ifndef AO_SEND_TO_CALLBACK

#define AO_SEND_TO_CALLBACK

#endif

void    ao_send_to_callback(ao_send_t * x, ao_send_proc_t y);

```
