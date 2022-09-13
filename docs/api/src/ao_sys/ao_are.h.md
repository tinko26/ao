---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
external:
- https://docs.microsoft.com/en-us/dotnet/api/system.threading.autoresetevent : "AutoResetEvent"
permalink: /api/src/ao_sys/ao_are.h/
toc: true
---

# Notes

...

microsoft: "Represents a thread synchronization event that, when signaled, resets automatically after releasing a single waiting thread."

...

# Include

```c
#include <ao_async.h>
#include <ao_list.h>
#include <ao_time.h>
#include <stdbool.h>
```

# Identifier

```c
#define AO_ARE
```

# Types

## `ao_are_t`

```c
typedef struct ao_are_t ao_are_t;
```

```c
struct ao_are_t
{
    ao_list_t list;
    bool      state;
};
```

This type represents an auto-reset event. It consists of the following members.

| `list` | The list of waitings. |
| `state` | The state. |

## `ao_are_wait_t`

```c
typedef struct ao_are_wait_t ao_are_wait_t;
```

```c
struct ao_are_wait_t
{
    ao_are_t *     are;
    ao_async_t     async;
    ao_list_node_t node;
    bool volatile  result;
};
```

This type represents the waiting for an auto-reset event. It consists of the following members.

| `are` | The auto-reset event. |
| `async` | The asynchronous event. |
| `node` | The node for the auto-reset event's list of waitings. |
| `result` | The result. |

# Functions

## `ao_are_clear`

```c
void ao_are_clear(ao_are_t * x);
```

Clears an auto-reset event, i.e. set its state to `false`. This function can be called from both task and interrupt context.

## `ao_are_set`

```c
void ao_are_set(ao_are_t * x);
```

Sets an auto-reset event, i.e. set its state to `true`. Eventually, this wakes up the first waiting task. This function can be called from both task and interrupt context.

## `ao_are_wait`
## `ao_are_wait_from`

```c
bool ao_are_wait     (ao_are_t * x, ao_time_t timeout);
bool ao_are_wait_from(ao_are_t * x, ao_time_t timeout, ao_time_t beginning);
```

Waits for an auto-reset event in a blocking fashion with a timeout and optional beginning.

## `ao_are_wait_forever`

```c
bool ao_are_wait_forever(ao_are_t * x);
```

Waits for an auto-reset event indefinitely in a blocking fashion.

## `ao_are_wait_try`

```c
bool ao_are_wait_try(ao_are_t * x);
```

Waits for an auto-reset event in a non-blocking fashion.

## `ao_are_wait_begin`
## `ao_are_wait_end`

```c
void ao_are_wait_begin(ao_are_wait_t * x);
void ao_are_wait_end(  ao_are_wait_t * x);
```

Begins or ends the waiting for an auto-reset event, respectively.
