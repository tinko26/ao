---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys/ao_block.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_block.h/ 
subtitle: "<code>ao_sys</code>"
title: "<code>ao_block.h</code>"
toc: true
---

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

