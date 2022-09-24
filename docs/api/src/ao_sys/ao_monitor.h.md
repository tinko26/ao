---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
external:
- https://en.wikipedia.org/wiki/Monitor_(synchronization) : "Monitor"
permalink: /api/src/ao_sys/ao_monitor.h/
toc: true
---

# Include

[`ao_async.h`](ao_async.h.md) <br/>
[`ao_list.h`](../ao/ao_list.h.md) <br/>
[`ao_mutex.h`](ao_mutex.h.md) <br/>
[`ao_time.h`](ao_time.h.md) <br/>
`stdbool.h`

# Identifier

```c
#define AO_MONITOR
```

# Types

## `ao_monitor_t`

```c
typedef struct ao_monitor_t ao_monitor_t;
```

```c
struct ao_monitor_t
{
    ao_list_t    list;
    ao_mutex_t * mutex;
};
```

This type represents a monitor. It consists of the following members.

| `list` | The list of waitings. |
| `mutex` | The mutex. |

## `ao_monitor_enter_t`

```c
typedef struct ao_monitor_enter_t ao_monitor_enter_t;
```

```c
struct ao_monitor_enter_t
{
    ao_async_t      async;
    ao_monitor_t *  monitor;
    ao_mutex_lock_t mutex_lock;
    bool volatile   result;
};
```

This type represents the entering of a monitor. It consists of the following members.

| `async` | The asynchronous event. |
| `monitor` | The monitor. |
| `mutex_lock` | The mutex locking. |
| `result` | The result. |

## `ao_monitor_wait_t`

```c
typedef struct ao_monitor_wait_t ao_monitor_wait_t;
```

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

This type represents the waiting for a monitor. It consists of the following members.

| `async` | The asynchronous event. |
| `monitor` | The monitor. |
| `mutex_lock` | The mutex locking. |
| `node` | The node for the monitor's list of waitings. |
| `result` | The result. |
| `waiting` | Indicates whether waitings is in progress. |

# Functions

## `ao_monitor_enter`
## `ao_monitor_enter_from`

```c
bool ao_monitor_enter     (ao_monitor_t * x, ao_time_t timeout);
bool ao_monitor_enter_from(ao_monitor_t * x, ao_time_t timeout, ao_time_t beginning);
```

Enters a monitor in a blocking fashion with a timeout and an optional beginning.

## `ao_monitor_enter_forever`

```c
bool ao_monitor_enter_forever(ao_monitor_t * x);
```

Enters a monitor indefinitely in a blocking fashion.

## `ao_monitor_enter_try`

```c
bool ao_monitor_enter_try(ao_monitor_t * x);
```

Enters a monitor in a non-blocking fashion.

## `ao_monitor_enter_begin`
## `ao_monitor_enter_end`

```c
void ao_monitor_enter_begin(ao_monitor_enter_t * x);
void ao_monitor_enter_end  (ao_monitor_enter_t * x);
```

Begins or ends, respectively, an entering of a monitor.

## `ao_monitor_exit`

```c
void ao_monitor_exit(ao_monitor_t * x);
```

Exits a monitor.

## `ao_monitor_notify`

```c
void ao_monitor_notify(ao_monitor_t * x);
```

Notifies the first waiting for a monitor.

## `ao_monitor_notify_all`

```c
void ao_monitor_notify_all(ao_monitor_t * x);
```

Notifies all waitings for a monitor.

## `ao_monitor_wait`
## `ao_monitor_wait_from`

```c
bool ao_monitor_wait     (ao_monitor_t * x, ao_time_t timeout);
bool ao_monitor_wait_from(ao_monitor_t * x, ao_time_t timeout, ao_time_t beginning);
```

Waits for a monitor in a blocking fashion with a timeout and an optional beginning.

## `ao_monitor_wait_forever`

```c
bool ao_monitor_wait_forever(ao_monitor_t * x);
```

Waits for a monitor indefinitely in a blocking fashion.

## `ao_monitor_wait_try`

```c
bool ao_monitor_wait_try(ao_monitor_t * x);
```

Waits for a monitor in a non-blocking fashion.

## `ao_monitor_wait_begin`
## `ao_monitor_wait_end`

```c
void ao_monitor_wait_begin(ao_monitor_wait_t * x);
void ao_monitor_wait_end  (ao_monitor_wait_t * x);
```

Begins or ends, respectively, a waiting for a monitor.
