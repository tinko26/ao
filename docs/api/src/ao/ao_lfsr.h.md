---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao/ao_lfsr.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao/ao_lfsr.h/
subtitle: ""
title: "ao_lfsr.h"
toc: true
---

# Include

```c
#include <stdint.h>
```

# Typedefs

```c
typedef struct ao_lfsr8_t ao_lfsr8_t;
```

```c
typedef struct ao_lfsr16_t ao_lfsr16_t;
```

```c
typedef struct ao_lfsr32_t ao_lfsr32_t;
```

```c
typedef struct ao_lfsr64_t ao_lfsr64_t;
```

# Types

## `ao_lfsr8_t`

```c
struct ao_lfsr8_t
{
    uint8_t polynomial;
    uint8_t seed;
};
```

Members:

| `polynomial` | |
| `seed` | |

## `ao_lfsr16_t`

```c
struct ao_lfsr16_t
{
    uint16_t polynomial;
    uint16_t seed;
};
```

Members:

| `polynomial` | |
| `seed` | |

## `ao_lfsr32_t`

```c
struct ao_lfsr32_t
{
    uint32_t polynomial;
    uint32_t seed;
};
```

Members:

| `polynomial` | |
| `seed` | |

## `ao_lfsr64_t`

```c
struct ao_lfsr64_t
{
    uint64_t polynomial;
    uint64_t seed;
};
```

Members:

| `polynomial` | |
| `seed` | |

# Functions

```c
void ao_lfsr8( ao_lfsr8_t * r);
```

```c
void ao_lfsr16( ao_lfsr16_t * r);
```

```c
void ao_lfsr32( ao_lfsr32_t * r);
```

```c
void ao_lfsr64( ao_lfsr64_t * r);
```

