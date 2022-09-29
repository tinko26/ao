---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
external:
- https://en.wikipedia.org/wiki/Monitor_(synchronization) : "Monitor"
permalink: /api/src/ao_sys/ao_monitor.h/
toc: true
---

# Include

| [`ao_async.h`](ao_async.h.md) |
| [`ao_list.h`](../ao/ao_list.h.md) |
| [`ao_mutex.h`](ao_mutex.h.md) |
| [`ao_time.h`](ao_time.h.md) |
| `stdbool.h` |

# Types

## `ao_monitor_t`

```c
typedef struct ao_monitor_t ao_monitor_t;
```

Represents a monitor.

## `ao_monitor_enter_t`

```c
typedef struct ao_monitor_enter_t ao_monitor_enter_t;
```

Represents the entering of a monitor.

## `ao_monitor_wait_t`

```c
typedef struct ao_monitor_wait_t ao_monitor_wait_t;
```

Represents the waiting for a monitor.

# Structs

## `ao_monitor_t`

```c
struct ao_monitor_t
{
    ao_mutex_t * mutex;
    ao_list_t    wait;
};
```

| `mutex` | The mutex. |
| `wait` | The list of waitings. |

## `ao_monitor_enter_t`

```c
struct ao_monitor_enter_t
{
    ao_async_t      async;
    ao_monitor_t *  monitor;
    ao_mutex_lock_t monitor_mutex_lock;
    bool volatile   result;
};
```

| `async` | The asynchronous event. |
| `monitor` | The monitor. |
| `monitor_mutex_lock` | The monitor mutex locking. |
| `result` | The result. |

## `ao_monitor_wait_t`

```c
struct ao_monitor_wait_t
{
    ao_async_t          async;
    ao_monitor_t *      monitor;
    union
    {
        ao_mutex_lock_t monitor_mutex_lock;
        ao_list_node_t  monitor_wait_node;
    };
    bool volatile       result;
    bool volatile       waiting;
};
```

| `async` | The asynchronous event. |
| `monitor` | The monitor. |
| `monitor_mutex_lock` | The monitor mutex locking. |
| `monitor_wait_node` | The node for the monitor's list of waitings. |
| `result` | The result. |
| `waiting` | Indicates whether waitings is in progress. |

# Functions

## `ao_monitor_enter`
## `ao_monitor_enter_from`

```c
bool ao_monitor_enter     (ao_monitor_t * m, ao_time_t timeout);
bool ao_monitor_enter_from(ao_monitor_t * m, ao_time_t timeout, ao_time_t beginning);
```

Enters a monitor in a blocking fashion with a timeout and an optional beginning.

## `ao_monitor_enter_forever`

```c
bool ao_monitor_enter_forever(ao_monitor_t * m);
```

Enters a monitor indefinitely in a blocking fashion.

## `ao_monitor_enter_try`

```c
bool ao_monitor_enter_try(ao_monitor_t * m);
```

Enters a monitor in a non-blocking fashion.

## `ao_monitor_enter_begin`
## `ao_monitor_enter_end`

```c
void ao_monitor_enter_begin(ao_monitor_enter_t * e);
void ao_monitor_enter_end  (ao_monitor_enter_t * e);
```

Begins or ends, respectively, an entering of a monitor.

## `ao_monitor_exit`

```c
void ao_monitor_exit(ao_monitor_t * m);
```

Exits a monitor.

## `ao_monitor_notify`

```c
void ao_monitor_notify(ao_monitor_t * m);
```

Notifies the first waiting for a monitor.

## `ao_monitor_notify_all`

```c
void ao_monitor_notify_all(ao_monitor_t * m);
```

Notifies all waitings for a monitor.

## `ao_monitor_wait`
## `ao_monitor_wait_from`

```c
bool ao_monitor_wait     (ao_monitor_t * m, ao_time_t timeout);
bool ao_monitor_wait_from(ao_monitor_t * m, ao_time_t timeout, ao_time_t beginning);
```

Waits for a monitor in a blocking fashion with a timeout and an optional beginning.

## `ao_monitor_wait_forever`

```c
bool ao_monitor_wait_forever(ao_monitor_t * m);
```

Waits for a monitor indefinitely in a blocking fashion.

## `ao_monitor_wait_try`

```c
bool ao_monitor_wait_try(ao_monitor_t * m);
```

Waits for a monitor in a non-blocking fashion.

## `ao_monitor_wait_begin`
## `ao_monitor_wait_end`

```c
void ao_monitor_wait_begin(ao_monitor_wait_t * w);
void ao_monitor_wait_end  (ao_monitor_wait_t * w);
```

Begins or ends, respectively, a waiting for a monitor.
