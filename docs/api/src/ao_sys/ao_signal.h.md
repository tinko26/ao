---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
permalink: /api/src/ao_sys/ao_signal.h/
toc: true
---

# Include

| [`ao_async.h`](ao_async.h.md) |
| [`ao_list.h`](../ao/ao_list.h.md) |
| [`ao_time.h`](ao_time.h.md) |
| `stdbool.h` |

# Identifier

```c
#define AO_SIGNAL
```

# Types

## `ao_signal_t`

```c
typedef struct ao_signal_t ao_signal_t;
```

```c
struct ao_signal_t
{
    ao_list_t list;
};
```

This type represents a signal. It consists of the following members.

| `list` | The list of waitings. |

## `ao_signal_wait_t`

```c
typedef struct ao_signal_wait_t ao_signal_wait_t;
```

```c
struct ao_signal_wait_t
{
    ao_async_t     async;
    ao_list_node_t node;
    bool volatile  result;
    ao_signal_t *  signal;
};
```

This type represents the waiting for a signal. It consists of the following members.

| `async` | The asynchronous event. |
| `node` | The node for the signal's list of waitings. |
| `result` | The result. |
| `signal` | The signal. |

# Functions

## `ao_signal_notify`

```c
void ao_signal_notify(ao_signal_t * x);
```

Notifies the first waiting for a signal.

## `ao_signal_notify_all`

```c
void ao_signal_notify_all(ao_signal_t * x);
```

Notifies all waitings for a signal.

## `ao_signal_wait`
## `ao_signal_wait_from`

```c
bool ao_signal_wait     (ao_signal_t * x, ao_time_t timeout);
bool ao_signal_wait_from(ao_signal_t * x, ao_time_t timeout, ao_time_t beginning);
```

Waits for a signal in a blocking fashion with a timeout and an optional beginning.

## `ao_signal_wait_forever`

```c
bool ao_signal_wait_forever(ao_signal_t * x);
```

Waits for a signal indefinitely in a blocking fashion.

## `ao_signal_wait_begin`
## `ao_signal_wait_end`

```c
void ao_signal_wait_begin(ao_signal_wait_t * x);
void ao_signal_wait_end  (ao_signal_wait_t * x);
```

Begins or ends, respectively, a waiting for a signal.
