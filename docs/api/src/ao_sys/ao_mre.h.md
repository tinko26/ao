---
author: "Stefan Wagner"
date: 2022-09-29
draft: true
external:
- https://learn.microsoft.com/en-us/dotnet/api/system.threading.manualresetevent : "ManualResetEvent"
permalink: /api/src/ao_sys/ao_mre.h/
toc: true
---

# Notes

This module defines manual-reset events.

# Include

| [`ao_async.h`](ao_async.h.md) |
| [`ao_list.h`](../ao/ao_list.h.md) |
| [`ao_time.h`](ao_time.h.md) |
| `stdbool.h` |

# Types

## `ao_mre_t`

```c
typedef struct ao_mre_t ao_mre_t;
```

Represents a manual-reset event.

## `ao_mre_wait_t`

```c
typedef struct ao_mre_wait_t ao_mre_wait_t;
```

Represents the waiting for a manual-reset event.

# Structs

## `ao_mre_t`

```c
struct ao_mre_t
{
    bool      state;
    ao_list_t wait;
};
```

| `state` | The state. |
| `wait` | The list of waitings. |

## `ao_mre_wait_t`

```c
struct ao_mre_wait_t
{
    ao_async_t     async;
    ao_mre_t *     mre;
    ao_list_node_t mre_wait_node;
    bool volatile  result;
};
```

| `async` | The asynchronous event. |
| `mre` | The manual-reset event. |
| `mre_wait_node` | The node for the manual-reset event's list of waitings. |
| `result` | The result. |

# Functions

## `ao_mre_reset`

```c
void ao_mre_reset(ao_mre_t * m);
```

Resets a manual-reset event.

## `ao_mre_set`

```c
void ao_mre_set(ao_mre_t * m);
```

Sets a manual-reset event.

## `ao_mre_wait`
## `ao_mre_wait_from`

```c
bool ao_mre_wait     (ao_mre_t * m, ao_time_t timeout);
bool ao_mre_wait_from(ao_mre_t * m, ao_time_t timeout, ao_time_t beginning);
```

Waits for a manual-reset event in a blocking fashion with a timeout and optional beginning.

## `ao_mre_wait_forever`

```c
bool ao_mre_wait_forever(ao_mre_t * m);
```

Waits for a manual-reset event indefinitely in a blocking fashion.

## `ao_mre_wait_try`

```c
bool ao_mre_wait_try(ao_mre_t * m);
```

Waits for a manual-reset event in a non-blocking fashion.

## `ao_mre_wait_begin`
## `ao_mre_wait_end`

```c
void ao_mre_wait_begin(ao_mre_wait_t * w);
void ao_mre_wait_end  (ao_mre_wait_t * w);
```

Begins or ends, respectively, a waiting for a manual-reset event.
