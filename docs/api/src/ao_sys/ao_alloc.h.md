---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_alloc.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_alloc.h/
subtitle: ""
title: "ao_alloc.h"
toc: true
---

# Include

```c
#include <ao_alloc_0.h>
#include <ao_alloc_1.h>
#include <ao_alloc_2.h>
#include <stdbool.h>
#include <stddef.h>
```

# Typedefs

```c
typedef struct ao_acquired_t ao_acquired_t;
```

```c
typedef struct ao_released_t ao_released_t;
```

```c
typedef struct ao_retained_t ao_retained_t;
```

# Constants

```c
#define AO_ACQUIRED (false)
```

```c
#define AO_ALLOC (2)
```

```c
#define AO_RELEASED (false)
```

```c
#define AO_RETAINED (false)
```

# Types

## `ao_acquired_t`

```c
struct ao_acquired_t
{
    void * ptr;
    bool result;
    size_t size_body;
    size_t size_body_requested;
    size_t size_head;
};
```

It consists of the following members.

| `ptr` | |
| `result` | |
| `size_body` | |
| `size_body_requested` | |
| `size_head` | |

## `ao_released_t`

```c
struct ao_released_t
{
    void * ptr;
    size_t ref;
    bool result;
    size_t size_body;
    size_t size_head;
};
```

It consists of the following members.

| `ptr` | |
| `ref` | |
| `result` | |
| `size_body` | |
| `size_head` | |

## `ao_retained_t`

```c
struct ao_retained_t
{
    void * ptr;
    size_t ref;
    bool result;
    size_t size_body;
    size_t size_head;
};
```

It consists of the following members.

| `ptr` | |
| `ref` | |
| `result` | |
| `size_body` | |
| `size_head` | |

# Functions

```c
#define ao_new(type)
```

```c
#define ao_delete(ptr)
```

```c
void * ao_acquire( size_t size);
```

```c
bool ao_release( void * ptr);
```

```c
bool ao_retain( void * ptr);
```

```c
void ao_acquired( ao_acquired_t const * info);
```

```c
void ao_released( ao_released_t const * info);
```

```c
void ao_retained( ao_retained_t const * info);
```

