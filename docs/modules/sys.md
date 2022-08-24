---
author: "Stefan Wagner"
date: 2022-08-13
description: "The ao_sys.h module of the ao real-time operating system."
draft: false
permalink: /modules/sys/
title: "ao_sys.h"
---

# Overview

This module defines a single macro constant that identifies the kernel package. By adding further definitions, an override of this module can help to identify a specific target, which can support the implementation of a port package.

```c
#define AO_SYS
```
