---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
external:
- https://en.wikipedia.org/wiki/Monitor_(synchronization) : "Monitor"
permalink: /api/src/ao_sys/ao_monitor.h/
toc: true
---

# Include

```c
#include <ao_async.h>
#include <ao_list.h>
#include <ao_mutex.h>
#include <ao_time.h>
#include <stdbool.h>
```

# Typedefs

```c
typedef struct ao_monitor_t       ao_monitor_t;
```

```c
typedef struct ao_monitor_enter_t ao_monitor_enter_t;
```

```c
typedef struct ao_monitor_wait_t  ao_monitor_wait_t;
```

# Types

## `ao_monitor_t`

This type represents a monitor.

```c
struct ao_monitor_t
{
    ao_list_t    list;
    ao_mutex_t * mutex;
};
```

It consists of the following members.

| `list` | |
| `mutex` | |

## `ao_monitor_enter_t`

This type represents the entering of a monitor.

```c
struct ao_monitor_enter_t
{
    ao_async_t      async;
    ao_monitor_t *  monitor;
    ao_mutex_lock_t mutex_lock;
    bool volatile   result;
};
```

It consists of the following members.

| `async` | |
| `monitor` | |
| `mutex_lock` | |
| `result` | |

## `ao_monitor_wait_t`

This type represents the waiting for a monitor.

```c
struct ao_monitor_wait_t
{
    ao_async_t          async;
    ao_monitor_t *      monitor;
    union
    {
        ao_mutex_lock_t mutex_lock;
        ao_list_node_t  node;
    };
    bool volatile       result;
    bool volatile       waiting;
};
```

It consists of the following members.

| `async` | |
| `monitor` | |
| `mutex_lock` | |
| `node` | |
| `result` | |
| `waiting` | |

# Functions

```c
bool ao_monitor_enter(ao_monitor_t * x, ao_time_t timeout);
```

```c
bool ao_monitor_enter_from(ao_monitor_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
bool ao_monitor_enter_forever(ao_monitor_t * x);
```

```c
bool ao_monitor_enter_try(ao_monitor_t * x);
```

```c
void ao_monitor_enter_begin(ao_monitor_enter_t * x);
```

```c
void ao_monitor_enter_end(ao_monitor_enter_t * x);
```

```c
void ao_monitor_exit(ao_monitor_t * x);
```

```c
void ao_monitor_notify(ao_monitor_t * x);
```

```c
void ao_monitor_notify_all(ao_monitor_t * x);
```

```c
bool ao_monitor_wait(ao_monitor_t * x, ao_time_t timeout);
```

```c
bool ao_monitor_wait_from(ao_monitor_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
bool ao_monitor_wait_forever(ao_monitor_t * x);
```

```c
bool ao_monitor_wait_try(ao_monitor_t * x);
```

```c
void ao_monitor_wait_begin(ao_monitor_wait_t * x);
```

```c
void ao_monitor_wait_end(ao_monitor_wait_t * x);
```
