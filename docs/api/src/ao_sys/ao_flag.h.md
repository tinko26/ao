---
author: "Stefan Wagner"
date: 2022-09-13
draft: true
permalink: /api/src/ao_sys/ao_flag.h/
toc: true
---

# Notes

This module defines (event) flags.

# Include

| [`ao_async.h`](ao_async.h.md) |
| [`ao_list.h`](../ao/ao_list.h.md) |
| [`ao_time.h`](ao_time.h.md) |
| [`ao_uint.h`](../ao/ao_uint.h.md) |
| `stdbool.h` |

# Identifier

```c
#define AO_FLAG
```

# Types

## `ao_flag_t`

```c
typedef struct ao_flag_t ao_flag_t;
```

```c
struct ao_flag_t
{
    ao_list_t list;
    ao_uint_t mask;
};
```

This type represents a flag. It consists of the following members.

| `list` | The list of waitings. |
| `mask` | The mask. |

## `ao_flag_wait_t`

```c
typedef struct ao_flag_wait_t ao_flag_wait_t;
```

```c
struct ao_flag_wait_t
{
    ao_async_t      async;
    ao_flag_t *     flag;
    ao_uint_t       mask;
    ao_flag_match_t match;
    void      *     match_parameter;
    ao_list_node_t  node;
    bool volatile   result;
};
```

This type represents the waiting for a flag match. It consists of the following members.

| `async` | The asynchronous event. |
| `flag` | The flag. |
| `mask` | The mask to be matched with the flag's current mask. |
| `match` | The match function. |
| `match_parameter` | The match function parameter. |
| `node` | The node for the flag's list of waitings. |
| `result` | The result. |

## `ao_flag_match_t`

```c
typedef bool (* ao_flag_match_t)
(
    ao_uint_t mask,
    ao_uint_t mask_wait,
    void *    parameter
);
```

This type represents a function to check whether a specific flag mask is a match. The function takes the current mask of a flag, the mask to be matched with that current mask, and an additional parameter.

# Functions

## `ao_flag_mask_clear`

```c
void ao_flag_mask_clear(ao_flag_t * x, ao_uint_t bits);
```

Clears the specified bits of a flag mask.

## `ao_flag_mask_set`

```c
void ao_flag_mask_set(ao_flag_t * x, ao_uint_t bits);
```

Sets the specified bits of a flag mask.

## `ao_flag_mask_toggle`

```c
void ao_flag_mask_toggle(ao_flag_t * x, ao_uint_t bits);
```

Toggles the specified bits of a flag mask.

## `ao_flag_wait`
## `ao_flag_wait_from`

```c
bool ao_flag_wait     (ao_flag_t * x, ao_uint_t mask, ao_flag_match_t match, void * match_parameter, ao_time_t timeout);
bool ao_flag_wait_from(ao_flag_t * x, ao_uint_t mask, ao_flag_match_t match, void * match_parameter, ao_time_t timeout, ao_time_t beginning);
```

Waits for a flag match in a blocking fashion with a timeout and an optional beginning.

## `ao_flag_wait_forever`

```c
bool ao_flag_wait_forever(ao_flag_t * x, ao_uint_t mask, ao_flag_match_t match, void * match_parameter);
```

Waits for a flag match indefinitely in a blocking fashion.

## `ao_flag_wait_try`

```c
bool ao_flag_wait_try(ao_flag_t * x, ao_uint_t mask, ao_flag_match_t match, void * match_parameter);
```

Waits for a flag match in a non-blocking fashion.

## `ao_flag_wait_begin`
## `ao_flag_wait_end`

```c
void ao_flag_wait_begin(ao_flag_wait_t * x);
void ao_flag_wait_end  (ao_flag_wait_t * x);
```

Begins or ends, respectively, a waiting for a flag match.
