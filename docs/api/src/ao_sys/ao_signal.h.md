---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_signal.h/
toc: true
---

# Include

```c
#include <ao_async.h>
#include <ao_list.h>
#include <ao_time.h>
#include <stdbool.h>
```

# Identifiers

## `AO_SIGNAL`

```c
#define AO_SIGNAL
```

# Typedefs

```c
typedef struct ao_signal_t      ao_signal_t;
typedef struct ao_signal_wait_t ao_signal_wait_t;
```

# Types

## `ao_signal_t`

This type represents a signal.

```c
struct ao_signal_t
{
    ao_list_t list;
};
```

It consists of the following members.

| `list` | The list of waiting tasks. |

## `ao_signal_wait_t`

This type represents the waiting for a signal.

```c
struct ao_signal_wait_t
{
    ao_async_t     async;
    ao_list_node_t node;
    bool volatile  result;
    ao_signal_t *  signal;
};
```

It consists of the following members.

| `async` | The asynchronous event. |
| `node` | The node for the signal's waiting list. |
| `result` | Indicates whether the waiting task has been notified. |
| `signal` | The signal. |

# Functions

## `ao_signal_notify`

```c
void ao_signal_notify(ao_signal_t * x);
```

## `ao_signal_notify_all`

```c
void ao_signal_notify_all(ao_signal_t * x);
```

## `ao_signal_wait`
## `ao_signal_wait_from`

```c
bool ao_signal_wait(     ao_signal_t * x, ao_time_t timeout);
bool ao_signal_wait_from(ao_signal_t * x, ao_time_t timeout, ao_time_t beginning);
```

## `ao_signal_wait_forever`

```c
bool ao_signal_wait_forever(ao_signal_t * x);
```

## `ao_signal_wait_begin`
## `ao_signal_wait_end`

```c
void ao_signal_wait_begin(ao_signal_wait_t * x);
void ao_signal_wait_end(  ao_signal_wait_t * x);
```
