---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao/ao_scan.h file of the ao real-time operating system."
draft: true
permalink: /src/ao/ao_scan.h/
subtitle: ""
title: "ao_scan.h"
toc: true
---

# Include

```c
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
```

# Typedefs

```c
typedef struct ao_scan_t ao_scan_t;
```

# Types

## `ao_scan_t`

```c
struct ao_scan_t
{
    size_t radix;
    bool seek;
};
```

Members:

| `radix` | |
| `seek` | |

# Functions

```c
size_t ao_scanfd( char const * s, size_t n, ao_scan_t const * o, double * v);
```

```c
size_t ao_scanff( char const * s, size_t n, ao_scan_t const * o, float * v);
```

```c
size_t ao_scanfl( char const * s, size_t n, ao_scan_t const * o, long double * v);
```

```c
size_t ao_scani8( char const * s, size_t n, ao_scan_t const * o, int8_t * v);
```

```c
size_t ao_scani16( char const * s, size_t n, ao_scan_t const * o, int16_t * v);
```

```c
size_t ao_scani32( char const * s, size_t n, ao_scan_t const * o, int32_t * v);
```

```c
size_t ao_scani64( char const * s, size_t n, ao_scan_t const * o, int64_t * v);
```

```c
size_t ao_scanu8( char const * s, size_t n, ao_scan_t const * o, uint8_t * v);
```

```c
size_t ao_scanu16( char const * s, size_t n, ao_scan_t const * o, uint16_t * v);
```

```c
size_t ao_scanu32( char const * s, size_t n, ao_scan_t const * o, uint32_t * v);
```

```c
size_t ao_scanu64( char const * s, size_t n, ao_scan_t const * o, uint64_t * v);
```

