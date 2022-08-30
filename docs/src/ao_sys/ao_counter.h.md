---
api: true
author: "Stefan Wagner"
date: 2022-08-29
description: "The /src/ao_sys/ao_counter.h file of the ao real-time operating system."
draft: true
permalink: /src/ao_sys/ao_counter.h/
subtitle: ""
title: "ao_counter.h"
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
typedef struct ao_counter_t ao_counter_t;
```

```c
typedef struct ao_counter_wait_t ao_counter_wait_t;
```

```c
typedef ao_uint_t (* ao_counter_adjust_t)
(
ao_uint_t value,
void * parameter
);
```

```c
typedef bool (* ao_counter_match_t)
(
ao_uint_t value,
ao_uint_t value_wait,
void * parameter
);
```

# Types

## `ao_counter_t`

```c
struct ao_counter_t
{
    ao_list_t list;
    ao_uint_t value;
};
```

Members:

| `list` | |
| `value` | |

## `ao_counter_wait_t`

```c
struct ao_counter_wait_t
{
    ao_async_t async;
    ao_counter_t * counter;
    ao_counter_match_t match;
    void * match_parameter;
    ao_list_node_t node;
    bool volatile result;
    ao_uint_t value;
};
```

Members:

| `async` | |
| `counter` | |
| `match` | |
| `match_parameter` | |
| `node` | |
| `result` | |
| `value` | |

# Functions

```c
void ao_counter_adjust( ao_counter_t * x, ao_counter_adjust_t adjust, void * adjust_parameter);
```

```c
void ao_counter_add( ao_counter_t * x, ao_uint_t value);
```

```c
void ao_counter_decrement( ao_counter_t * x);
```

```c
void ao_counter_divide( ao_counter_t * x, ao_uint_t value);
```

```c
void ao_counter_increment( ao_counter_t * x);
```

```c
void ao_counter_modulo( ao_counter_t * x, ao_uint_t value);
```

```c
void ao_counter_multiply( ao_counter_t * x, ao_uint_t value);
```

```c
void ao_counter_set( ao_counter_t * x, ao_uint_t value);
```

```c
void ao_counter_subtract( ao_counter_t * x, ao_uint_t value);
```

```c
void ao_counter_subtract_from( ao_counter_t * x, ao_uint_t value);
```

```c
bool ao_counter_wait( ao_counter_t * x, ao_uint_t value, ao_counter_match_t match, void * match_parameter, ao_time_t timeout);
```

```c
bool ao_counter_wait_from( ao_counter_t * x, ao_uint_t value, ao_counter_match_t match, void * match_parameter, ao_time_t timeout, ao_time_t beginning);
```

```c
bool ao_counter_wait_forever( ao_counter_t * x, ao_uint_t value, ao_counter_match_t match, void * match_parameter);
```

```c
bool ao_counter_wait_try( ao_counter_t * x, ao_uint_t value, ao_counter_match_t match, void * match_parameter);
```

```c
void ao_counter_wait_begin( ao_counter_wait_t * x);
```

```c
void ao_counter_wait_end( ao_counter_wait_t * x);
```

