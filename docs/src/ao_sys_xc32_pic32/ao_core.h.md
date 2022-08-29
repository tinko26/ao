---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32/ao_core.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32_pic32/ao_core.h/ 
subtitle: ""
title: "ao_core.h"
toc: true
---

# Overview

...

# Includes

```c
#include <stdint.h>

typedef uint32_t        ao_core_t;

#ifndef AO_CORE_COUNT

#define AO_CORE_COUNT   (1)

#endif

#ifndef ao_core

#define ao_core()       (0)

#endif

```
