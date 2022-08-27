---
author: "Stefan Wagner"
date: 2022-08-17
description: "The ao_recv_obj_from_queue.h module of the ao real-time operating system."
draft: false
permalink: /modules/recv-obj-from-queue/
title: "<code>ao_recv_obj_from_queue.h</code>"
---

# Overview

This module defines a single function that facilitates [receiving objects](recv-obj.md) from a [queue](queue4obj.md).

```c
void ao_recv_obj_from_queue(ao_recv_obj_t * x, ao_qpop_obj_t * y);
```
