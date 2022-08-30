---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_count.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_count.h/
subtitle: ""
title: "ao_count.h"
toc: true
---

# Include

```c
#include <stdint.h>
```

# Typedefs

```c
typedef uint32_t ao_count_t;
```

# Constants

```c
#define AO_COUNT_FREQUENCY (0)
```

```c
#define AO_COUNT_MAX (UINT32_MAX)
```

```c
#define AO_COUNT_MIN (0)
```

# Functions

```c
ao_count_t ao_count();
```

