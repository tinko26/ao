---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_send_to_stream.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_send_to_stream.h/ 
subtitle: ""
title: "ao_send_to_stream.h"
toc: true
---

```c
#include <ao_send.h>
#include <ao_stream.h>

#ifndef AO_SEND_TO_STREAM

#define AO_SEND_TO_STREAM

#endif

void    ao_send_to_stream(ao_send_t * x, ao_spush_t * y);

```
