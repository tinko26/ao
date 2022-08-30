---
author: "Stefan Wagner"
date: 2022-08-24
description: "The ao_alloc_0.h module of the ao real-time operating system."
draft: false
permalink: /modules/alloc-0/
subtitle: "Allocator stub"
title: "<code>ao_alloc_0.h</code>"
toc: false
---

This module provides a stub implementation for the [allocator](../allocator.md). That is, it does not facilitate the allocation or deallocation of memory blocks. Instead, all the functions simply ignore the input and return a standard value indicating failure.