---
author: "Stefan Wagner"
date: 2022-08-17
description: "The ao_recv_ptr_from_callback.h module of the ao real-time operating system."
draft: false
permalink: /modules/recv-ptr-from-callback/
title: "<code>ao_recv_ptr_from_callback.h</code>"
---

# Overview

This module defines a single function that facilitates [receiving pointers](recv-ptr.md) from a callback.

```c
void ao_recv_ptr_from_callback(ao_recv_ptr_t * x, ao_recv_ptr_proc_t y);
```
