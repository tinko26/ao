---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32/ao_lock.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32_pic32/ao_lock.h/ 
subtitle: ""
title: "ao_lock.h"
toc: true
---

# Overview

...

# Includes

```c
#include <ao_ir.h>
#include <ao_sys.h>
#include <stdint.h>

typedef uint32_t        ao_lock_t;

#ifndef AO_LOCK_PRIO

#define AO_LOCK_PRIO    (AO_IR_PRIO_MAX)

#endif

#ifndef ao_lock

#define ao_lock(x)      { *(x) = ao_sys_lock_ir(AO_LOCK_PRIO); }

#endif

#ifndef ao_unlock

#define ao_unlock(x)    { ao_sys_unlock_ir(*(x)); }

#endif

```
