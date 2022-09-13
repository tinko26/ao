---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
permalink: /api/src/ao_sys/ao_counter.h/
toc: true
---

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
#define AO_COUNTER
```

# Types

## `ao_counter_t`

```c
typedef struct ao_counter_t ao_counter_t;
```

```c
struct ao_counter_t
{
    ao_list_t list;
    ao_uint_t value;
};
```

This type represents a counter. It consists of the following members.

| `list` | The list of waitings. |
| `value` | The value. |

## `ao_counter_wait_t`

```c
typedef struct ao_counter_wait_t ao_counter_wait_t;
```

```c
struct ao_counter_wait_t
{
    ao_async_t         async;
    ao_counter_t *     counter;
    ao_counter_match_t match;
    void *             match_parameter;
    ao_list_node_t     node;
    bool volatile      result;
    ao_uint_t          value;
};
```

This type represents the waiting for a counter match. It consists of the following members.

| `async` | The asynchronous event. |
| `counter` | The counter. |
| `match` | The match function. |
| `match_parameter` | The match function parameter. |
| `node` | The node for the counter's list of waitings. |
| `result` | The result. |
| `value` | The value to match with the counter's value. |

## `ao_counter_adjust_t`

```c
typedef ao_uint_t (* ao_counter_adjust_t)
(
    ao_uint_t value,
    void *    parameter
);
```

This type represents a function to adjust a counter value. The function takes the old value and an additional parameter and returns the new value.

## `ao_counter_match_t`

```c
typedef bool (* ao_counter_match_t)
(
    ao_uint_t value,
    ao_uint_t value_wait,
    void *    parameter
);
```

This type represents a function to check whether a specific counter value is a match. The function takes the current value of a counter, the value to be matched with that current value, and an additional parameter.

# Functions

## `ao_counter_adjust`

```c
void ao_counter_adjust(ao_counter_t * x, ao_counter_adjust_t adjust, void * adjust_parameter);
```

Adjusts a counter.

## `ao_counter_add`

```c
void ao_counter_add(ao_counter_t * x, ao_uint_t value);
```

Adds a specified value to a counter's current value.

## `ao_counter_decrement`

```c
void ao_counter_decrement(ao_counter_t * x);
```

Decrements a counter's value.

## `ao_counter_divide`

```c
void ao_counter_divide(ao_counter_t * x, ao_uint_t value);
```

Divides a counter's current value by a specified value.

## `ao_counter_increment`

```c
void ao_counter_increment(ao_counter_t * x);
```

Increments a counter's value.

## `ao_counter_modulo`

```c
void ao_counter_modulo(ao_counter_t * x, ao_uint_t value);
```

Sets a counter's value to the remainder of it divided by a specified value.

## `ao_counter_multiply`

```c
void ao_counter_multiply(ao_counter_t * x, ao_uint_t value);
```

Multiplies a counter's value with a specified value.

## `ao_counter_set`

```c
void ao_counter_set(ao_counter_t * x, ao_uint_t value);
```

Sets a counter's value to a specified value.

## `ao_counter_subtract`

```c
void ao_counter_subtract(ao_counter_t * x, ao_uint_t value);
```

Subtracts a specified value from a counter's value.

## `ao_counter_subtract_from`

```c
void ao_counter_subtract_from(ao_counter_t * x, ao_uint_t value);
```

Substracts a counter's value from a specified value.

## `ao_counter_wait`
## `ao_counter_wait_from`

```c
bool ao_counter_wait     (ao_counter_t * x, ao_uint_t value, ao_counter_match_t match, void * match_parameter, ao_time_t timeout);
bool ao_counter_wait_from(ao_counter_t * x, ao_uint_t value, ao_counter_match_t match, void * match_parameter, ao_time_t timeout, ao_time_t beginning);
```

Waits for a counter match in a blocking fashion with a timeout and an optional beginning.

## `ao_counter_wait_forever`

```c
bool ao_counter_wait_forever(ao_counter_t * x, ao_uint_t value, ao_counter_match_t match, void * match_parameter);
```

Waits for a counter match indefinitely in a blocking fashion.

## `ao_counter_wait_try`

```c
bool ao_counter_wait_try(ao_counter_t * x, ao_uint_t value, ao_counter_match_t match, void * match_parameter);
```

Waits for a counter match in a non-blocking fashion.

## `ao_counter_wait_begin`
## `ao_counter_wait_end`

```c
void ao_counter_wait_begin(ao_counter_wait_t * x);
void ao_counter_wait_end  (ao_counter_wait_t * x);
```

Begins or ends, respectively, a waiting for a counter match.
