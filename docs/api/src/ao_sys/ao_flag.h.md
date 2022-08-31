---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_flag.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_flag.h/
subtitle: ""
title: "ao_flag.h"
toc: true
---

# Include

```c
#include <ao_async.h>
#include <ao_list.h>
#include <ao_time.h>
#include <ao_uint.h>
#include <stdbool.h>
```

# Typedefs

```c
typedef struct ao_flag_t ao_flag_t;
```

```c
typedef struct ao_flag_wait_t ao_flag_wait_t;
```

```c
typedef bool (* ao_flag_match_t)
(
ao_uint_t mask,
ao_uint_t mask_wait,
void * parameter
);
```

# Types

## `ao_flag_t`

```c
struct ao_flag_t
{
    ao_list_t list;
    ao_uint_t mask;
};
```

It consists of the following members.

| `list` | |
| `mask` | |

## `ao_flag_wait_t`

```c
struct ao_flag_wait_t
{
    ao_async_t async;
    ao_flag_t * flag;
    ao_uint_t mask;
    ao_flag_match_t match;
    void * match_parameter;
    ao_list_node_t node;
    bool volatile result;
};
```

It consists of the following members.

| `async` | |
| `flag` | |
| `mask` | |
| `match` | |
| `match_parameter` | |
| `node` | |
| `result` | |

# Functions

```c
void ao_flag_mask_clear( ao_flag_t * x, ao_uint_t bits);
```

```c
void ao_flag_mask_set( ao_flag_t * x, ao_uint_t bits);
```

```c
void ao_flag_mask_toggle( ao_flag_t * x, ao_uint_t bits);
```

```c
bool ao_flag_wait( ao_flag_t * x, ao_uint_t mask, ao_flag_match_t match, void * match_parameter, ao_time_t timeout);
```

```c
bool ao_flag_wait_from( ao_flag_t * x, ao_uint_t mask, ao_flag_match_t match, void * match_parameter, ao_time_t timeout, ao_time_t beginning);
```

```c
bool ao_flag_wait_forever( ao_flag_t * x, ao_uint_t mask, ao_flag_match_t match, void * match_parameter);
```

```c
bool ao_flag_wait_try( ao_flag_t * x, ao_uint_t mask, ao_flag_match_t match, void * match_parameter);
```

```c
void ao_flag_wait_begin( ao_flag_wait_t * x);
```

```c
void ao_flag_wait_end( ao_flag_wait_t * x);
```

