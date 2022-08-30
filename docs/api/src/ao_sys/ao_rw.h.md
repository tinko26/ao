---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_rw.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_rw.h/
subtitle: ""
title: "ao_rw.h"
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
typedef struct ao_rw_t ao_rw_t;
```

```c
typedef struct ao_rw_lock_t ao_rw_lock_t;
```

# Types

## `ao_rw_t`

```c
struct ao_rw_t
{
    ao_uint_t r_active;
    ao_list_t r_waiting;
    bool w_active;
    ao_list_t w_waiting;
};
```

Members:

| `r_active` | |
| `r_waiting` | |
| `w_active` | |
| `w_waiting` | |

## `ao_rw_lock_t`

```c
struct ao_rw_lock_t
{
    ao_async_t async;
    ao_list_node_t node;
    bool volatile result;
    ao_rw_t * rw;
};
```

Members:

| `async` | |
| `node` | |
| `result` | |
| `rw` | |

# Functions

```c
bool ao_rw_lock_read( ao_rw_t * x, ao_time_t timeout);
```

```c
bool ao_rw_lock_read_forever( ao_rw_t * x);
```

```c
bool ao_rw_lock_read_from( ao_rw_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
bool ao_rw_lock_read_try( ao_rw_t * x);
```

```c
void ao_rw_lock_read_begin( ao_rw_lock_t * x);
```

```c
void ao_rw_lock_read_end( ao_rw_lock_t * x);
```

```c
bool ao_rw_lock_write( ao_rw_t * x, ao_time_t timeout);
```

```c
bool ao_rw_lock_write_forever( ao_rw_t * x);
```

```c
bool ao_rw_lock_write_from( ao_rw_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
bool ao_rw_lock_write_try( ao_rw_t * x);
```

```c
void ao_rw_lock_write_begin( ao_rw_lock_t * x);
```

```c
void ao_rw_lock_write_end( ao_rw_lock_t * x);
```

```c
void ao_rw_unlock_read( ao_rw_t * x);
```

```c
void ao_rw_unlock_write( ao_rw_t * x);
```

