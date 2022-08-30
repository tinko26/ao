---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao/ao_uint.h file of the ao real-time operating system."
draft: true
permalink: /src/ao/ao_uint.h/
subtitle: ""
title: "ao_uint.h"
toc: true
---

# Include

```c
#include <stdint.h>
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

```c
ao_uint_t ao_clou(ao_uint_t x);
```

```c
ao_uint_t ao_clzu(ao_uint_t x);
```

```c
ao_uint_t ao_ctou(ao_uint_t x);
```

```c
ao_uint_t ao_ctzu(ao_uint_t x);
```

```c
ao_uint_t ao_ffsu(ao_uint_t x);
```

```c
ao_uint_t ao_flsu(ao_uint_t x);
```

