---
author: "Stefan Wagner"
date: 2022-08-31
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

# Typedefs

```c
typedef struct ao_counter_t      ao_counter_t;
typedef struct ao_counter_wait_t ao_counter_wait_t;
```

```c
typedef ao_uint_t (* ao_counter_adjust_t)
(
    ao_uint_t value,
    void *    parameter
);
```

```c
typedef bool      (* ao_counter_match_t)
(
    ao_uint_t value,
    ao_uint_t value_wait,
    void *    parameter
);
```

# Types

## `ao_counter_t`

This type represents a counter.

```c
struct ao_counter_t
{
    ao_list_t list;
    ao_uint_t value;
};
```

It consists of the following members.

| `list` | The list of waiting tasks. |
| `value` | The value. |

## `ao_counter_wait_t`

This type represents the waiting for a counter match.

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

It consists of the following members.

| `async` | |
| `counter` | |
| `match` | |
| `match_parameter` | |
| `node` | |
| `result` | |
| `value` | |

## `ao_counter_adjust_t`

This type represents a function to adjust the value of a counter. The function takes the old value and an additional parameter and returns the new value.

## `ao_counter_match_t`

This type represents a function to check whether a specific value is a match. The function takes the current value, the waited-for value, and an additional parameter.

# Functions

## `ao_counter_adjust`

```c
void ao_counter_adjust(ao_counter_t * x, ao_counter_adjust_t adjust, void * adjust_parameter);
```

## `ao_counter_add`

```c
void ao_counter_add(ao_counter_t * x, ao_uint_t value);
```

## `ao_counter_decrement`

```c
void ao_counter_decrement(ao_counter_t * x);
```

## `ao_counter_divide`

```c
void ao_counter_divide(ao_counter_t * x, ao_uint_t value);
```

## `ao_counter_increment`

```c
void ao_counter_increment(ao_counter_t * x);
```

## `ao_counter_modulo`

```c
void ao_counter_modulo(ao_counter_t * x, ao_uint_t value);
```

## `ao_counter_multiply`

```c
void ao_counter_multiply(ao_counter_t * x, ao_uint_t value);
```

## `ao_counter_set`

```c
void ao_counter_set(ao_counter_t * x, ao_uint_t value);
```

## `ao_counter_subtract`

```c
void ao_counter_subtract(ao_counter_t * x, ao_uint_t value);
```

## `ao_counter_subtract_from`

```c
void ao_counter_subtract_from(ao_counter_t * x, ao_uint_t value);
```

## `ao_counter_wait`
## `ao_counter_wait_from`

```c
bool ao_counter_wait(     ao_counter_t * x, ao_uint_t value, ao_counter_match_t match, void * match_parameter, ao_time_t timeout);
bool ao_counter_wait_from(ao_counter_t * x, ao_uint_t value, ao_counter_match_t match, void * match_parameter, ao_time_t timeout, ao_time_t beginning);
```

## `ao_counter_wait_forever`

```c
bool ao_counter_wait_forever(ao_counter_t * x, ao_uint_t value, ao_counter_match_t match, void * match_parameter);
```

## `ao_counter_wait_try`

```c
bool ao_counter_wait_try(ao_counter_t * x, ao_uint_t value, ao_counter_match_t match, void * match_parameter);
```

## `ao_counter_wait_begin`
## `ao_counter_wait_end`

```c
void ao_counter_wait_begin(ao_counter_wait_t * x);
void ao_counter_wait_end(  ao_counter_wait_t * x);
```
