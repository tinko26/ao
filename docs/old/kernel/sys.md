---
author: "Stefan Wagner"
date: 2022-08-13
description: ""
draft: false
permalink: /kernel/sys/
title: "System Identifiers"
---

# System Identifiers

The `ao_sys.h` module defines a single macro constant that identifies the kernel package. By adding further definitions, an override of this module can help to identify a specific target, which can support the implementation of a port package.

```c
#define AO_SYS
```
