---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys_xc32_pic32/ao_uint.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys_xc32_pic32/ao_uint.h/
subtitle: ""
title: "ao_uint.h"
toc: true
---

# Include

```c
#include <stdint.h>
#include <xc.h>
```

# Typedefs

```c
typedef uint32_t ao_uint_t;
```

# Constants

```c
#define AO_UINT_BITS (32)
```

```c
#define AO_UINT_BITS_LOG (5)
```

```c
#define AO_UINT_MAX (UINT32_MAX)
```

```c
#define AO_UINT_MIN (0)
```

```c
#define AO_UINT_SIZE (4)
```

# Functions

```c
#define ao_clou(x)
```

```c
#define ao_clzu(x)
```

```c
#define ao_ctou(x)
```

```c
#define ao_ctzu(x)
```

```c
#define ao_ffsu(x)
```

```c
#define ao_flsu(x)
```

```c
#define AO_LOG2U(x)
```

```c
#define AO_LOG2U2(x)
```

```c
#define AO_LOG2U4(x)
```

```c
#define AO_LOG2U8(x)
```

```c
#define AO_LOG2U16(x)
```

```c
#define AO_LOG2U32(x)
```

```c
#define AO_LOG2U64(x)
```

