---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_async.h/
toc: true
---

# Include

```c
#include <ao_func.h>
#include <stdbool.h>
#include <stddef.h>
```

# Identifier

```c
#define AO_ASYNC
```

# Types

## `ao_async_t`

```c
typedef struct ao_async_t ao_async_t;
```

```c
struct ao_async_t
{
    ao_proc_t     callback;
    void *        callback_parameter;
    bool volatile checked;
};
```

This type represents an asynchronous event. It consists of the following members.

| `callback` | The callback. |
| `callback_parameter` | The callback parameter. |
| `checked` | Indicates whether the asynchronous event has happened. |

## `ao_async_all_t`

```c
typedef struct ao_async_all_t ao_async_all_t;
```

```c
struct ao_async_all_t
{
    ao_async_t      async;
    size_t          count;
    size_t volatile count_checked;
    bool   volatile result;
    ao_async_t **   store;
};
```

This type represents the waiting for all out of a collection of asynchronous events. It consists of the following members.

| `async` | |
| `count` | |
| `count_checked` | |
| `result` | |
| `store` | |

## `ao_async_any_t`

```c
typedef struct ao_async_any_t ao_async_any_t;
```

```c
struct ao_async_any_t
{
    ao_async_t    async;
    size_t        count;
    bool volatile result;
    ao_async_t ** store;
};
```

This type represents the waiting for one out of a collection of asynchronous events. It consists of the following members.

| `async` | |
| `count` | |
| `result` | |
| `store` | |

# Functions

## `ao_async_all_begin`
## `ao_async_all_end`

```c
void ao_async_all_begin(ao_async_all_t * x);
void ao_async_all_end(  ao_async_all_t * x);
```

## `ao_async_all_try`

```c
void ao_async_all_try(ao_async_all_t * x);
```

## `ao_async_any_begin`
## `ao_async_any_end`

```c
void ao_async_any_begin(ao_async_any_t * x);
void ao_async_any_end(  ao_async_any_t * x);
```

## `ao_async_any_try`

```c
void ao_async_any_try(ao_async_any_t * x);
```
