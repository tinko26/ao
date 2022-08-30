---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_cond.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys/ao_cond.h/
subtitle: ""
title: "ao_cond.h"
toc: true
---

# Include

```c
#include <ao_async.h>
#include <ao_list.h>
#include <ao_time.h>
#include <stdbool.h>
```

# Typedefs

```c
typedef struct ao_cond_t ao_cond_t;
```

```c
typedef struct ao_cond_wait_t ao_cond_wait_t;
```

# Types

## `ao_cond_t`

```c
struct ao_cond_t
{
    ao_list_t list;
    bool state;
};
```

Members:

| `list` | |
| `state` | |

## `ao_cond_wait_t`

```c
struct ao_cond_wait_t
{
    ao_async_t async;
    ao_cond_t * cond;
    ao_list_node_t node;
    bool volatile result;
};
```

Members:

| `async` | |
| `cond` | |
| `node` | |
| `result` | |

# Functions

```c
void ao_cond_clear( ao_cond_t * x);
```

```c
void ao_cond_set( ao_cond_t * x);
```

```c
bool ao_cond_wait( ao_cond_t * x, ao_time_t timeout);
```

```c
bool ao_cond_wait_from( ao_cond_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
bool ao_cond_wait_forever( ao_cond_t * x);
```

```c
bool ao_cond_wait_try( ao_cond_t * x);
```

```c
void ao_cond_wait_begin( ao_cond_wait_t * x);
```

```c
void ao_cond_wait_end( ao_cond_wait_t * x);
```

