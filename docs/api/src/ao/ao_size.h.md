---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao/ao_size.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao/ao_size.h/
subtitle: ""
title: "ao_size.h"
toc: true
---

# Include

```c
#include <ao_uint.h>
#include <stddef.h>
#include <stdint.h>
```

# Constants

```c
#define AO_SIZE_BITS (32)
```

```c
#define AO_SIZE_BITS_LOG (5)
```

```c
#define AO_SIZE_MAX (SIZE_MAX)
```

```c
#define AO_SIZE_MIN (0)
```

```c
#define AO_SIZE_SIZE (4)
```

# Functions

```c
#define AO_LOG2Z(x)
```

```c
size_t ao_cloz(size_t x);
```

```c
size_t ao_clzz(size_t x);
```

```c
size_t ao_ctoz(size_t x);
```

```c
size_t ao_ctzz(size_t x);
```

```c
size_t ao_ffsz(size_t x);
```

```c
size_t ao_flsz(size_t x);
```

