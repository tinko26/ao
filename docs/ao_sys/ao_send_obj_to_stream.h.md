---
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys/ao_send_obj_to_stream.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys/ao_send_obj_to_stream.h/ 
subtitle: "<code>ao_sys</code>"
title: "<code>ao_send_obj_to_stream.h</code>"
toc: true
---

#ifndef AO_SEND_OBJ_TO_STREAM

#define AO_SEND_OBJ_TO_STREAM

#endif

void    ao_send_obj_to_stream(          ao_send_obj_t * x, ao_spush_obj_t * y);

void    ao_send_obj_to_stream_override( ao_send_obj_t * x, ao_spush_obj_t * y);

