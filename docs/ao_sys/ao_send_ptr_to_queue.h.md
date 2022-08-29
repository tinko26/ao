---
author: "Stefan Wagner"
breadcrumbs: 2
date: 2022-08-29
description: "The ao_sys/ao_send_ptr_to_queue.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_send_ptr_to_queue.h/ 
subtitle: "<code>ao_sys</code>"
title: "<code>ao_send_ptr_to_queue.h</code>"
toc: true
---

#ifndef AO_SEND_PTR_TO_QUEUE

#define AO_SEND_PTR_TO_QUEUE

#endif

void    ao_send_acq_to_queue(   ao_send_ptr_t * x, ao_qinsert_ptr_t * y);

void    ao_send_ptr_to_queue(   ao_send_ptr_t * x, ao_qinsert_ptr_t * y);

