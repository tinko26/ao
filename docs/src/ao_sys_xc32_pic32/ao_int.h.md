---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32/ao_int.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32_pic32/ao_int.h/ 
subtitle: ""
title: "ao_int.h"
toc: true
---

# Overview

...

# Includes

```c
#include <stdint.h>

typedef int32_t         ao_int_t;

#ifndef AO_INT_MAX

#define AO_INT_MAX      (INT32_MAX)

#endif

#ifndef AO_INT_MIN

#define AO_INT_MIN      (INT32_MIN)

#endif

#ifndef AO_INT_SIZE

#define AO_INT_SIZE     (4)

#endif

```
