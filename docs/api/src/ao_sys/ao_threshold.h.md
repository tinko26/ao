---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
permalink: /api/src/ao_sys/ao_threshold.h/
toc: true
---

# Notes

...

- with a counter, each task can define its own matching function.
- in contrast, with a threshold, there is single matching function for all tasks.

...

# Include

```c
#include <ao_async.h>
#include <ao_list.h>
#include <ao_time.h>
#include <ao_uint.h>
#include <stdbool.h>
```

# Identifier

```c
#define AO_THRESHOLD
```

# Types

## `ao_threshold_t`

```c
typedef struct ao_threshold_t ao_threshold_t;
```

```c
struct ao_threshold_t
{
    ao_threshold_adjust_t adjust;
    void *                adjust_parameter;
    ao_list_t             list;
    ao_threshold_match_t  match;
    void *                match_parameter;
    ao_uint_t             value;
};
```

This type represents a threshold. It consists of the following members.

| `adjust` | The adjust function. |
| `adjust_parameter` | The adjust function parameter. |
| `list` | The list of waitings. |
| `match` | The match function. |
| `match_parameter` | The match function parameter. |
| `value` | The value. |

## `ao_threshold_wait_t`

```c
typedef struct ao_threshold_wait_t ao_threshold_wait_t;
```

```c
struct ao_threshold_wait_t
{
    ao_async_t       async;
    ao_list_node_t   node;
    bool volatile    result;
    ao_threshold_t * threshold;
};
```

This type represents the waiting for a threshold match. It consists of the following members.

| `async` | The asynchronous event. |
| `node` | The node for the threshold's list of waitings. |
| `result` | The result. |
| `threshold` | The threshold. |

## `ao_threshold_adjust_t`

```c
typedef ao_uint_t (* ao_threshold_adjust_t)
(
    ao_uint_t value,
    void *    parameter
);
```

This type represents a function to adjust a threshold value. The function takes the old value and an additional parameter and returns the new value.

## `ao_threshold_match_t`

```c
typedef bool (* ao_threshold_match_t)
(
    ao_uint_t value,
    void *    parameter
);
```

This type represents a function to check whether a specific threshold value is a match. The function takes the current value of a threshold and an additional parameter.

# Functions

## `ao_threshold_adjust`

```c
void ao_threshold_adjust(ao_threshold_t * x, ao_threshold_adjust_t adjust, void * adjust_parameter);
```

Adjusts a threshold.

## `ao_threshold_add`

```c
void ao_threshold_add(ao_threshold_t * x, ao_uint_t value);
```

Adds a specified value to a threshold's current value.

## `ao_threshold_decrement`

```c
void ao_threshold_decrement(ao_threshold_t * x);
```

Decrements a threshold's value.

## `ao_threshold_divide`

```c
void ao_threshold_divide(ao_threshold_t * x, ao_uint_t value);
```

Divides a threshold's current value by a specified value.

## `ao_threshold_increment`

```c
void ao_threshold_increment(ao_threshold_t * x);
```

Increments a threshold's value.

## `ao_threshold_modulo`

```c
void ao_threshold_modulo(ao_threshold_t * x, ao_uint_t value);
```

Sets a threshold's value to the remainder of it divided by a specified value.

## `ao_threshold_multiply`

```c
void ao_threshold_multiply(ao_threshold_t * x, ao_uint_t value);
```

Multiplies a threshold's value with a specified value.

## `ao_threshold_set`

```c
void ao_threshold_set(ao_threshold_t * x, ao_uint_t value);
```

Sets a threshold's value to a specified value.

## `ao_threshold_subtract`

```c
void ao_threshold_subtract(ao_threshold_t * x, ao_uint_t value);
```

Subtracts a specified value from a threshold's value.

## `ao_threshold_subtract_from`

```c
void ao_threshold_subtract_from(ao_threshold_t * x, ao_uint_t value);
```

Substracts a threshold's value from a specified value.

## `ao_threshold_wait`
## `ao_threshold_wait_from`

```c
bool ao_threshold_wait     (ao_threshold_t * x, ao_time_t timeout);
bool ao_threshold_wait_from(ao_threshold_t * x, ao_time_t timeout, ao_time_t beginning);
```

Waits for a threshold match in a blocking fashion with a timeout and an optional beginning.

## `ao_threshold_wait_forever`

```c
bool ao_threshold_wait_forever(ao_threshold_t * x);
```

Waits for a threshold match indefinitely in a blocking fashion.

## `ao_threshold_wait_try`

```c
bool ao_threshold_wait_try(ao_threshold_t * x);
```

Waits for a threshold match in a non-blocking fashion.

## `ao_threshold_wait_begin`
## `ao_threshold_wait_end`

```c
void ao_threshold_wait_begin(ao_threshold_wait_t * x);
void ao_threshold_wait_end  (ao_threshold_wait_t * x);
```

Begins or ends, respectively, a waiting for a threshold match.
