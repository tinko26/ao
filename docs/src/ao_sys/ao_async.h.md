---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_async.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys/ao_async.h/
subtitle: ""
title: "ao_async.h"
toc: true
---

# Include

```c
#include <ao_func.h>
#include <stdbool.h>
#include <stddef.h>
```

# Typedefs

```c
typedef struct ao_async_t ao_async_t;
```

```c
typedef struct ao_async_all_t ao_async_all_t;
```

```c
typedef struct ao_async_any_t ao_async_any_t;
```

# Types

## `ao_async_t`

```c
struct ao_async_t
{
    ao_proc_t callback;
    void * callback_parameter;
    bool volatile checked;
};
```

Members:

| `callback` | |
| `callback_parameter` | |
| `checked` | |

## `ao_async_all_t`

```c
struct ao_async_all_t
{
    ao_async_t async;
    size_t count;
    size_t volatile count_checked;
    bool volatile result;
    ao_async_t ** store;
};
```

Members:

| `async` | |
| `count` | |
| `count_checked` | |
| `result` | |
| `store` | |

## `ao_async_any_t`

```c
struct ao_async_any_t
{
    ao_async_t async;
    size_t count;
    bool volatile result;
    ao_async_t ** store;
};
```

Members:

| `async` | |
| `count` | |
| `result` | |
| `store` | |

# Functions

```c
void ao_async_all_begin( ao_async_all_t * x);
```

```c
void ao_async_all_end( ao_async_all_t * x);
```

```c
void ao_async_all_try( ao_async_all_t * x);
```

```c
void ao_async_any_begin( ao_async_any_t * x);
```

```c
void ao_async_any_end( ao_async_any_t * x);
```

```c
void ao_async_any_try( ao_async_any_t * x);
```

