---
author: "Stefan Wagner"
date: 2022-09-26
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

| [`ao_async.h`](ao_async.h.md) |
| [`ao_list.h`](../ao/ao_list.h.md) |
| [`ao_time.h`](ao_time.h.md) |
| `stdbool.h` |

# Identifier

```c
#define AO_ARE
```

# Types

## `ao_are_t`

```c
typedef struct ao_are_t ao_are_t;
```

This type represents an auto-reset event.

## `ao_are_wait_t`

```c
typedef struct ao_are_wait_t ao_are_wait_t;
```

This type represents the waiting for an auto-reset event.

# Structs

## `ao_are_t`

```c
struct ao_are_t
{
    bool      state;
    ao_list_t wait;
};
```

| `state` | The state. |
| `wait` | The list of waitings. |

## `ao_are_wait_t`

```c
struct ao_are_wait_t
{
    ao_are_t *     are;
    ao_list_node_t are_wait_node;
    ao_async_t     async;
    bool volatile  result;
};
```

| `are` | The auto-reset event. |
| `are_wait_node` | The node for the auto-reset event's list of waitings. |
| `async` | The asynchronous event. |
| `result` | The result. |

# Functions

## `ao_are_clear`

```c
void ao_are_clear(ao_are_t * are);
```

Clears an auto-reset event, i.e. set its state to `false`.

## `ao_are_set`

```c
void ao_are_set(ao_are_t * are);
```

Sets an auto-reset event, i.e. set its state to `true`. Eventually, this wakes up the first waiting task.

## `ao_are_wait`
## `ao_are_wait_from`

```c
bool ao_are_wait     (ao_are_t * are, ao_time_t timeout);
bool ao_are_wait_from(ao_are_t * are, ao_time_t timeout, ao_time_t beginning);
```

Waits for an auto-reset event in a blocking fashion with a timeout and optional beginning.

## `ao_are_wait_forever`

```c
bool ao_are_wait_forever(ao_are_t * are);
```

Waits for an auto-reset event indefinitely in a blocking fashion.

## `ao_are_wait_try`

```c
bool ao_are_wait_try(ao_are_t * are);
```

Waits for an auto-reset event in a non-blocking fashion.

## `ao_are_wait_begin`
## `ao_are_wait_end`

```c
void ao_are_wait_begin(ao_are_wait_t * wait);
void ao_are_wait_end  (ao_are_wait_t * wait);
```

Begins or ends, respectively, a waiting for an auto-reset event.
