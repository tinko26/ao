---
author: "Stefan Wagner"
date: 2022-09-29
draft: true
permalink: /api/src/ao_sys/ao_cond.h/
toc: true
---

# Notes

...

- Condition (variable), but not that monitor-based kind implemented in the STL.
- actually the same behavior as a manual-reset event

...

# Include

| [`ao_async.h`](ao_async.h.md) |
| [`ao_list.h`](../ao/ao_list.h.md) |
| [`ao_time.h`](ao_time.h.md) |
| `stdbool.h` |

# Types

## `ao_cond_t`

```c
typedef struct ao_cond_t ao_cond_t;
```

Represents a condition.

## `ao_cond_wait_t`

```c
typedef struct ao_cond_wait_t ao_cond_wait_t;
```

Represents the waiting for a condition.

# Structs

## `ao_cond_t`

```c
struct ao_cond_t
{
    bool      state;
    ao_list_t wait;
};
```

| `state` | The state. |
| `wait` | The list of waitings. |

## `ao_cond_wait_t`

```c
struct ao_cond_wait_t
{
    ao_async_t     async;
    ao_cond_t *    cond;
    ao_list_node_t cond_wait_node;
    bool volatile  result;
};
```

| `async` | The asynchronous event. |
| `cond` | The condition. |
| `cond_wait_node` | The node for the condition's list of waitings. |
| `result` | The result. |

# Functions

## `ao_cond_false`

```c
void ao_cond_false(ao_cond_t * c);
```

Sets a condition to `false`.

## `ao_cond_true`

```c
void ao_cond_true(ao_cond_t * c);
```

Sets a condition to `true`.

## `ao_cond_wait`
## `ao_cond_wait_from`

```c
bool ao_cond_wait     (ao_cond_t * c, ao_time_t timeout);
bool ao_cond_wait_from(ao_cond_t * c, ao_time_t timeout, ao_time_t beginning);
```

Waits for a condition in a blocking fashion with a timeout and an optional beginning.

## `ao_cond_wait_forever`

```c
bool ao_cond_wait_forever(ao_cond_t * c);
```

Waits for a condition indefinitely in a blocking fashion.

## `ao_cond_wait_try`

```c
bool ao_cond_wait_try(ao_cond_t * c);
```

Waits for a condition in a non-blocking fashion.

## `ao_cond_wait_begin`
## `ao_cond_wait_end`

```c
void ao_cond_wait_begin(ao_cond_wait_t * w);
void ao_cond_wait_end  (ao_cond_wait_t * w);
```

Begins or ends, respectively, a waiting for a condition.
