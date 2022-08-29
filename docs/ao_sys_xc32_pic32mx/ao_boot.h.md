---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao_sys_xc32_pic32mx/ao_boot.h module of the ao real-time operating system."
draft: true
permalink: /ao_sys_xc32_pic32mx/ao_boot.h/ 
subtitle: ""
title: "ao_boot.h"
toc: true
---

# Overview

...

# Includes

```c
#include <ao_sys.h>

#ifndef ao_boot_sys_bmx

#define ao_boot_sys_bmx()   ao_sys_bmx_wsdram_disable()

#endif

#include_next <ao_boot.h>

```
