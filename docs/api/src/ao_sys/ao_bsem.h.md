---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_bsem.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_bsem.h/
subtitle: ""
title: "ao_bsem.h"
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
typedef struct ao_bsem_t ao_bsem_t;
```

```c
typedef struct ao_bsem_take_t ao_bsem_take_t;
```

# Types

## `ao_bsem_t`

```c
struct ao_bsem_t
{
    ao_list_t list;
    bool taken;
};
```

Members:

| `list` | |
| `taken` | |

## `ao_bsem_take_t`

```c
struct ao_bsem_take_t
{
    ao_async_t async;
    ao_list_node_t node;
    bool volatile result;
    ao_bsem_t * sem;
};
```

Members:

| `async` | |
| `node` | |
| `result` | |
| `sem` | |

# Functions

```c
void ao_bsem_give( ao_bsem_t * x);
```

```c
bool ao_bsem_take( ao_bsem_t * x, ao_time_t timeout);
```

```c
bool ao_bsem_take_from( ao_bsem_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
bool ao_bsem_take_forever( ao_bsem_t * x);
```

```c
bool ao_bsem_take_try( ao_bsem_t * x);
```

```c
void ao_bsem_take_begin( ao_bsem_take_t * x);
```

```c
void ao_bsem_take_end( ao_bsem_take_t * x);
```

