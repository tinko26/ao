---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_count.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys/ao_count.h/ 
subtitle: ""
title: "ao_count.h"
toc: true
---

# Overview

...

# Includes

```c
#include <stdint.h>

typedef     uint32_t            ao_count_t;

#ifndef     AO_COUNT_MAX

#define     AO_COUNT_MAX        (UINT32_MAX)

#endif

#ifndef     AO_COUNT_MIN

#define     AO_COUNT_MIN        (0)

#endif

#ifndef     AO_COUNT_FREQUENCY

#define     AO_COUNT_FREQUENCY  (0)

#endif

ao_count_t  ao_count();

```
