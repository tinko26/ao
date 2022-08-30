---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_are.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_are.h/
subtitle: ""
title: "ao_are.h"
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
typedef struct ao_are_t ao_are_t;
```

```c
typedef struct ao_are_wait_t ao_are_wait_t;
```

# Types

## `ao_are_t`

```c
struct ao_are_t
{
    ao_list_t list;
    bool state;
};
```

Members:

| `list` | |
| `state` | |

## `ao_are_wait_t`

```c
struct ao_are_wait_t
{
    ao_are_t * are;
    ao_async_t async;
    ao_list_node_t node;
    bool volatile result;
};
```

Members:

| `are` | |
| `async` | |
| `node` | |
| `result` | |

# Functions

```c
void ao_are_clear( ao_are_t * x);
```

```c
void ao_are_set( ao_are_t * x);
```

```c
bool ao_are_wait( ao_are_t * x, ao_time_t timeout);
```

```c
bool ao_are_wait_from( ao_are_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
bool ao_are_wait_forever( ao_are_t * x);
```

```c
bool ao_are_wait_try( ao_are_t * x);
```

```c
void ao_are_wait_begin( ao_are_wait_t * x);
```

```c
void ao_are_wait_end( ao_are_wait_t * x);
```

