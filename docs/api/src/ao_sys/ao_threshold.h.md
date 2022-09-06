---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_threshold.h/
toc: true
---

# Overview

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

# Typedefs

```c
typedef struct ao_threshold_t      ao_threshold_t;
```

```c
typedef struct ao_threshold_wait_t ao_threshold_wait_t;
```

```c
typedef ao_uint_t (* ao_threshold_adjust_t)
(
ao_uint_t value,
void *    parameter
);
```

```c
typedef bool      (* ao_threshold_match_t)
(
ao_uint_t value,
void *    parameter
);
```

# Types

## `ao_threshold_t`

This type represents a threshold.

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

It consists of the following members.

| `adjust` | This function is to adjust the value after a match. |
| `adjust_parameter` | An additional parameter for the post-match adjusting. |
| `list` | The list of tasks waiting for a match. |
| `match` | The matching function. |
| `match_parameter` | An additional parameter for the matching function. |
| `value` | The value. |

## `ao_threshold_wait_t`

This type represents the waiting for a threshold match.

```c
struct ao_threshold_wait_t
{
ao_async_t       async;
ao_list_node_t   node;
bool volatile    result;
ao_threshold_t * threshold;
};
```

It consists of the following members.

| `async` | The asynchronous event. |
| `node` | The node for the threshold's waiting list. |
| `result` | Indicates whether a match has occured. |
| `threshold` | The threshold. |

## `ao_threshold_adjust_t`

This type represents a function to adjust the value of a threshold. The function takes the old value and an additional parameter and returns the new value.

## `ao_threshold_match_t`

This type represents a function to check whether a specific value is a match. The function takes the value and an additional parameter.

# Functions

```c
void ao_threshold_adjust(ao_threshold_t * x, ao_threshold_adjust_t adjust, void * adjust_parameter);
```

```c
void ao_threshold_add(ao_threshold_t * x, ao_uint_t value);
```

```c
void ao_threshold_decrement(ao_threshold_t * x);
```

```c
void ao_threshold_divide(ao_threshold_t * x, ao_uint_t value);
```

```c
void ao_threshold_increment(ao_threshold_t * x);
```

```c
void ao_threshold_modulo(ao_threshold_t * x, ao_uint_t value);
```

```c
void ao_threshold_multiply(ao_threshold_t * x, ao_uint_t value);
```

```c
void ao_threshold_set(ao_threshold_t * x, ao_uint_t value);
```

```c
void ao_threshold_subtract(ao_threshold_t * x, ao_uint_t value);
```

```c
void ao_threshold_subtract_from(ao_threshold_t * x, ao_uint_t value);
```

```c
bool ao_threshold_wait(ao_threshold_t * x, ao_time_t timeout);
```

```c
bool ao_threshold_wait_from(ao_threshold_t * x, ao_time_t timeout, ao_time_t beginning);
```

```c
bool ao_threshold_wait_forever(ao_threshold_t * x);
```

```c
bool ao_threshold_wait_try(ao_threshold_t * x);
```

```c
void ao_threshold_wait_begin(ao_threshold_wait_t * x);
```

```c
void ao_threshold_wait_end(ao_threshold_wait_t * x);
```
