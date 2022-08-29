---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The ao/ao_assert.h module of the ao real-time operating system."
draft: true
permalink: /ao/ao_assert.h/ 
subtitle: ""
title: "ao_assert.h"
toc: true
---

# Overview

...

# Includes

```c
#include <ao_break.h>

#ifndef ao_assert

#define ao_assert(exp)                                                      \
{                                                                           \
        if (!(exp))                                                         \
        {                                                                   \
            ao_break();                                                     \
        }                                                                   \
}

#endif

```
