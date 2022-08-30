---
author: "Stefan Wagner"
date: 2022-08-17
description: "The ao_recv_obj_from_callback.h module of the ao real-time operating system."
draft: false
permalink: /modules/recv-obj-from-callback/
title: "<code>ao_recv_obj_from_callback.h</code>"
toc: true
---

# Overview

This module defines a single function that facilitates [receiving objects](recv-obj.md) from a callback.

```c
void ao_recv_obj_from_callback(ao_recv_obj_t * x, ao_recv_obj_proc_t y);
```