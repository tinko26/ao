---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32/ao_count.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys_xc32_pic32/ao_count.h/
subtitle: ""
title: "ao_count.h"
toc: true
---

# Include

```c
#include <ao_sys.h>
#include <stdint.h>
#include <xc.h>
```

# Typedefs

```c
typedef uint32_t ao_count_t;
```

# Constants

```c
#define AO_COUNT_FREQUENCY ((AO_SYS_SYSCLK) / 2)
```

```c
#define AO_COUNT_MAX (UINT32_MAX)
```

```c
#define AO_COUNT_MIN (0)
```

# Functions

```c
#define ao_count()
```

```c
#define ao_count_debug_continue()
```

```c
#define ao_count_debug_stop()
```

