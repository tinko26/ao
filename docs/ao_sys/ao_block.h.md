---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_block.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_block.h/ 
subtitle: ""
title: "ao_block.h"
toc: true
---

# Overview

...

# Includes

```c
#include <ao_alarm.h>
#include <ao_time.h>

typedef struct  ao_block_t  ao_block_t;

#ifndef AO_BLOCK

#define AO_BLOCK

struct  ao_block_t
{
        ao_alarm_t          alarm;

        ao_time_t           beginning;

        ao_time_t           timeout;
};

#endif

```
