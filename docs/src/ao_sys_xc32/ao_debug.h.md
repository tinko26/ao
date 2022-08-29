---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32/ao_debug.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32/ao_debug.h/ 
subtitle: ""
title: "ao_debug.h"
toc: true
---

# Overview

...

# Includes

```c
#include <stdbool.h>

#ifndef AO_DEBUG

#ifndef NDEBUG

#ifndef __DEBUG

#define AO_DEBUG    (false)

#else

#define AO_DEBUG    (true)

#endif

#else

#define AO_DEBUG    (false)

#endif

#endif

```
