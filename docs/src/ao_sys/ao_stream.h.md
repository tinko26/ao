---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_stream.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys/ao_stream.h/
subtitle: ""
title: "ao_stream.h"
toc: true
---

# Include

```c
#include <ao_async.h>
#include <ao_buffer.h>
#include <ao_time.h>
#include <stdbool.h>
#include <stddef.h>
```

# Typedefs

```c
typedef struct ao_stream_t ao_stream_t;
```

```c
typedef struct ao_spop_t ao_spop_t;
```

```c
typedef struct ao_spush_t ao_spush_t;
```

# Types

## `ao_stream_t`

```c
struct ao_stream_t
{
    ao_buffer_t buffer;
    ao_spop_t * pop;
    ao_spush_t * push;
};
```

Members:

| `buffer` | |
| `pop` | |
| `push` | |

## `ao_spop_t`

```c
struct ao_spop_t
{
    ao_async_t async;
    size_t volatile count;
    size_t count_max;
    size_t count_min;
    void * ptr;
    bool volatile result;
    ao_stream_t * stream;
};
```

Members:

| `async` | |
| `count` | |
| `count_max` | |
| `count_min` | |
| `ptr` | |
| `result` | |
| `stream` | |

## `ao_spush_t`

```c
struct ao_spush_t
{
    ao_async_t async;
    size_t volatile count;
    size_t count_max;
    size_t count_min;
    void * ptr;
    bool volatile result;
    ao_stream_t * stream;
};
```

Members:

| `async` | |
| `count` | |
| `count_max` | |
| `count_min` | |
| `ptr` | |
| `result` | |
| `stream` | |

# Functions

```c
void ao_spop( ao_spop_t * x, ao_time_t timeout);
```

```c
void ao_spop_from( ao_spop_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
void ao_spop_forever( ao_spop_t * x);
```

```c
void ao_spop_try( ao_spop_t * x);
```

```c
void ao_spop_begin( ao_spop_t * x);
```

```c
void ao_spop_end( ao_spop_t * x);
```

```c
void ao_spush( ao_spush_t * x, ao_time_t timeout);
```

```c
void ao_spush_from( ao_spush_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
void ao_spush_forever( ao_spush_t * x);
```

```c
void ao_spush_try( ao_spush_t * x);
```

```c
void ao_spush_begin( ao_spush_t * x);
```

```c
void ao_spush_end( ao_spush_t * x);
```

```c
void ao_spush_override( ao_spush_t * x);
```

