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

# Include

```c
#include <ao_ir.h>
#include <ao_sys.h>
#include <stdint.h>
```

# Typedefs

```c
typedef uint32_t ao_lock_t;
```

# Constants

```c
#define AO_LOCK_PRIO (AO_IR_PRIO_MAX)
```

# Functions

```c
#define ao_lock(x)
```

```c
#define ao_unlock(x)
```

