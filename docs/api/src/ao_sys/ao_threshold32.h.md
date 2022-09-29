---
author: "Stefan Wagner"
date: 2022-09-27
draft: true
permalink: /api/src/ao_sys/ao_threshold32.h/
toc: true
---

# Include

| [`ao_async.h`](ao_async.h.md) |
| [`ao_list.h`](../ao/ao_list.h.md) |
| [`ao_time.h`](ao_time.h.md) |
| `stdbool.h` |
| `stdint.h` |

# Types

## `ao_threshold32_t`

```c
typedef struct ao_threshold32_t ao_threshold32_t;
```

Represents a threshold.

## `ao_threshold32_wait_t`

```c
typedef struct ao_threshold32_wait_t ao_threshold32_wait_t;
```

Represents the waiting for a threshold match.

## `ao_threshold32_adjust_t`

```c
typedef uint32_t (* ao_threshold32_adjust_t)
(
    uint32_t value_old,
    void *   parameter
);
```

Represents a function to adjust a threshold value. The function takes the old value and an additional parameter and returns the new value.

## `ao_threshold32_match_t`

```c
typedef bool (* ao_threshold32_match_t)
(
    uint32_t value_old,
    uint32_t value_new,
    void *   parameter
);
```

Represents a function to check whether a specific threshold value is a match. The function takes both the old and the new value of a threshold as well as an additional parameter.

# Structs

## `ao_threshold32_t`

```c
struct ao_threshold32_t
{
    ao_threshold32_adjust_t adjust;
    void *                  adjust_parameter;
    ao_threshold32_match_t  match;
    void *                  match_parameter;
    uint32_t                value;
    ao_list_t               wait;
};
```

| `adjust` | The adjust function. |
| `adjust_parameter` | The adjust function parameter. |
| `match` | The match function. |
| `match_parameter` | The match function parameter. |
| `value` | The value. |
| `wait` | The list of waitings. |

## `ao_threshold32_wait_t`

```c
struct ao_threshold32_wait_t
{
    ao_async_t         async;
    bool      volatile result;
    ao_threshold32_t * threshold;
    ao_list_node_t     threshold_wait_node;
    uint32_t  volatile value_new;
    uint32_t  volatile value_old;
};
```

| `async` | The asynchronous event. |
| `result` | The result. |
| `threshold` | The threshold. |
| `threshold_wait_node` | The node for the threshold's list of waitings. |
| `value_new` | The new value. |
| `value_old` | The old value. |

# Functions

## `ao_threshold32_adjust`

```c
void ao_threshold32_adjust(ao_threshold32_t * t, ao_threshold32_adjust_t a, void * ap);
```

| `t` | The threshold. |
| `a` | The adjust function. |
| `ap` | The adjust function parameter. |

Adjusts a threshold.

## `ao_threshold32_add`

```c
void ao_threshold32_add(ao_threshold32_t * t, uint32_t x);
```

Updates a threshold's value. This functions adds the threshold's value and the specified value.

## `ao_threshold32_and`

```c
void ao_threshold32_and(ao_threshold32_t * t, uint32_t x);
```

Updates a threshold's value. This functions performs a bitwise AND with the specified value.

## `ao_threshold32_decrement`

```c
void ao_threshold32_decrement(ao_threshold32_t * t);
```

Updates a threshold's value. This functions decrements the threshold's value.

## `ao_threshold32_divide`

```c
void ao_threshold32_divide(ao_threshold32_t * t, uint32_t x);
```

Updates a threshold's value. This functions divides the threshold's value by the specified value.

## `ao_threshold32_increment`

```c
void ao_threshold32_increment(ao_threshold32_t * t);
```

Updates a threshold's value. This functions increments the threshold's value.

## `ao_threshold32_max`

```c
void ao_threshold32_max(ao_threshold32_t * t);
```

Updates a threshold's value. This functions sets the threshold's value to the maximum possible value.

## `ao_threshold32_min`

```c
void ao_threshold32_min(ao_threshold32_t * t);
```

Updates a threshold's value. This functions sets the threshold's value to the minimum possible value, i.e. zero.

## `ao_threshold32_modulo`

```c
void ao_threshold32_modulo(ao_threshold32_t * t, uint32_t x);
```

Updates a threshold's value. This functions sets the threshold's value to the remainder of it divided by the specified value.

## `ao_threshold32_multiply`

```c
void ao_threshold32_multiply(ao_threshold32_t * t, uint32_t x);
```

Updates a threshold's value. This functions multiplies the threshold's value with the specified value.

## `ao_threshold32_nand`

```c
void ao_threshold32_nand(ao_threshold32_t * t, uint32_t x);
```

Updates a threshold's value. This functions performs a bitwise NAND with the specified value.

## `ao_threshold32_nor`

```c
void ao_threshold32_nor(ao_threshold32_t * t, uint32_t x);
```

Updates a threshold's value. This functions performs a bitwise NOR with the specified value.

## `ao_threshold32_not`

```c
void ao_threshold32_not(ao_threshold32_t * t);
```

Updates a threshold's value. This functions performs a bitwise inversion on the threshold's value.

## `ao_threshold32_or`

```c
void ao_threshold32_or(ao_threshold32_t * t, uint32_t x);
```

Updates a threshold's value. This functions performs a bitwise OR with the specified value.

## `ao_threshold32_set`

```c
void ao_threshold32_set(ao_threshold32_t * t, uint32_t x);
```

Updates a threshold's value. This functions sets the threshold's value to the specified value.

## `ao_threshold32_subtract`

```c
void ao_threshold32_subtract(ao_threshold32_t * t, uint32_t x);
```

Updates a threshold's value. This functions subtracts the specified value from the threshold's value.

## `ao_threshold32_subtract_from`

```c
void ao_threshold32_subtract_from(ao_threshold32_t * t, uint32_t x);
```

Updates a threshold's value. This functions subtracts the threshold's value from the specified value.

## `ao_threshold32_xnor`

```c
void ao_threshold32_xnor(ao_threshold32_t * t, uint32_t x);
```

Updates a threshold's value. This functions performs a bitwise XNOR with the specified value.

## `ao_threshold32_xor`

```c
void ao_threshold32_xor(ao_threshold32_t * t, uint32_t x);
```

Updates a threshold's value. This functions performs a bitwise XOR with the specified value.

## `ao_threshold32_wait`
## `ao_threshold32_wait_from`

```c
bool ao_threshold32_wait     (ao_threshold32_wait_t * w, ao_time_t timeout);
bool ao_threshold32_wait_from(ao_threshold32_wait_t * w, ao_time_t timeout, ao_time_t beginning);
```

Waits for a threshold match in a blocking fashion with a timeout and an optional beginning.

## `ao_threshold32_wait_forever`

```c
bool ao_threshold32_wait_forever(ao_threshold32_wait_t * w);
```

Waits for a threshold match indefinitely in a blocking fashion.

## `ao_threshold32_wait_try`

```c
bool ao_threshold32_wait_try(ao_threshold32_wait_t * w);
```

Waits for a threshold match in a non-blocking fashion.

## `ao_threshold32_wait_begin`
## `ao_threshold32_wait_end`

```c
void ao_threshold32_wait_begin(ao_threshold32_wait_t * w);
void ao_threshold32_wait_end  (ao_threshold32_wait_t * w);
```

Begins or ends, respectively, a waiting for a threshold match.
