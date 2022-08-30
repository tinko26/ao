---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_signal.h file of the ao real-time operating system."
draft: true
permalink: /api/src/ao_sys/ao_signal.h/
subtitle: ""
title: "ao_signal.h"
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
typedef struct ao_signal_t ao_signal_t;
```

```c
typedef struct ao_signal_wait_t ao_signal_wait_t;
```

# Types

## `ao_signal_t`

```c
struct ao_signal_t
{
    ao_list_t list;
};
```

Members:

| `list` | |

## `ao_signal_wait_t`

```c
struct ao_signal_wait_t
{
    ao_async_t async;
    ao_list_node_t node;
    bool volatile result;
    ao_signal_t * signal;
};
```

Members:

| `async` | |
| `node` | |
| `result` | |
| `signal` | |

# Functions

```c
void ao_signal_notify( ao_signal_t * x);
```

```c
void ao_signal_notify_all( ao_signal_t * x);
```

```c
bool ao_signal_wait( ao_signal_t * x, ao_time_t timeout);
```

```c
bool ao_signal_wait_from( ao_signal_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
bool ao_signal_wait_forever( ao_signal_t * x);
```

```c
void ao_signal_wait_begin( ao_signal_wait_t * x);
```

```c
void ao_signal_wait_end( ao_signal_wait_t * x);
```

