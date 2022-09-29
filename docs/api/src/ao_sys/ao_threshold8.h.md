---
author: "Stefan Wagner"
date: 2022-09-27
draft: true
permalink: /api/src/ao_sys/ao_threshold8.h/
toc: true
---

# Include

| [`ao_async.h`](ao_async.h.md) |
| [`ao_list.h`](../ao/ao_list.h.md) |
| [`ao_time.h`](ao_time.h.md) |
| `stdbool.h` |
| `stdint.h` |

# Types

## `ao_threshold8_t`

```c
typedef struct ao_threshold8_t ao_threshold8_t;
```

Represents a threshold.

## `ao_threshold8_wait_t`

```c
typedef struct ao_threshold8_wait_t ao_threshold8_wait_t;
```

Represents the waiting for a threshold match.

## `ao_threshold8_adjust_t`

```c
typedef uint8_t (* ao_threshold8_adjust_t)
(
    uint8_t value_old,
    void *   parameter
);
```

Represents a function to adjust a threshold value. The function takes the old value and an additional parameter and returns the new value.

## `ao_threshold8_match_t`

```c
typedef bool (* ao_threshold8_match_t)
(
    uint8_t value_old,
    uint8_t value_new,
    void *   parameter
);
```

Represents a function to check whether a specific threshold value is a match. The function takes both the old and the new value of a threshold as well as an additional parameter.

# Structs

## `ao_threshold8_t`

```c
struct ao_threshold8_t
{
    ao_threshold8_adjust_t adjust;
    void *                  adjust_parameter;
    ao_threshold8_match_t  match;
    void *                  match_parameter;
    uint8_t                value;
    ao_list_t               wait;
};
```

| `adjust` | The adjust function. |
| `adjust_parameter` | The adjust function parameter. |
| `match` | The match function. |
| `match_parameter` | The match function parameter. |
| `value` | The value. |
| `wait` | The list of waitings. |

## `ao_threshold8_wait_t`

```c
struct ao_threshold8_wait_t
{
    ao_async_t         async;
    bool      volatile result;
    ao_threshold8_t * threshold;
    ao_list_node_t     threshold_wait_node;
    uint8_t  volatile value_new;
    uint8_t  volatile value_old;
};
```

| `async` | The asynchronous event. |
| `result` | The result. |
| `threshold` | The threshold. |
| `threshold_wait_node` | The node for the threshold's list of waitings. |
| `value_new` | The new value. |
| `value_old` | The old value. |

# Functions

## `ao_threshold8_adjust`

```c
void ao_threshold8_adjust(ao_threshold8_t * t, ao_threshold8_adjust_t a, void * ap);
```

| `t` | The threshold. |
| `a` | The adjust function. |
| `ap` | The adjust function parameter. |

Adjusts a threshold.

## `ao_threshold8_add`

```c
void ao_threshold8_add(ao_threshold8_t * t, uint8_t x);
```

Updates a threshold's value. This functions adds the threshold's value and the specified value.

## `ao_threshold8_and`

```c
void ao_threshold8_and(ao_threshold8_t * t, uint8_t x);
```

Updates a threshold's value. This functions performs a bitwise AND with the specified value.

## `ao_threshold8_decrement`

```c
void ao_threshold8_decrement(ao_threshold8_t * t);
```

Updates a threshold's value. This functions decrements the threshold's value.

## `ao_threshold8_divide`

```c
void ao_threshold8_divide(ao_threshold8_t * t, uint8_t x);
```

Updates a threshold's value. This functions divides the threshold's value by the specified value.

## `ao_threshold8_increment`

```c
void ao_threshold8_increment(ao_threshold8_t * t);
```

Updates a threshold's value. This functions increments the threshold's value.

## `ao_threshold8_max`

```c
void ao_threshold8_max(ao_threshold8_t * t);
```

Updates a threshold's value. This functions sets the threshold's value to the maximum possible value.

## `ao_threshold8_min`

```c
void ao_threshold8_min(ao_threshold8_t * t);
```

Updates a threshold's value. This functions sets the threshold's value to the minimum possible value, i.e. zero.

## `ao_threshold8_modulo`

```c
void ao_threshold8_modulo(ao_threshold8_t * t, uint8_t x);
```

Updates a threshold's value. This functions sets the threshold's value to the remainder of it divided by the specified value.

## `ao_threshold8_multiply`

```c
void ao_threshold8_multiply(ao_threshold8_t * t, uint8_t x);
```

Updates a threshold's value. This functions multiplies the threshold's value with the specified value.

## `ao_threshold8_nand`

```c
void ao_threshold8_nand(ao_threshold8_t * t, uint8_t x);
```

Updates a threshold's value. This functions performs a bitwise NAND with the specified value.

## `ao_threshold8_nor`

```c
void ao_threshold8_nor(ao_threshold8_t * t, uint8_t x);
```

Updates a threshold's value. This functions performs a bitwise NOR with the specified value.

## `ao_threshold8_not`

```c
void ao_threshold8_not(ao_threshold8_t * t);
```

Updates a threshold's value. This functions performs a bitwise inversion on the threshold's value.

## `ao_threshold8_or`

```c
void ao_threshold8_or(ao_threshold8_t * t, uint8_t x);
```

Updates a threshold's value. This functions performs a bitwise OR with the specified value.

## `ao_threshold8_set`

```c
void ao_threshold8_set(ao_threshold8_t * t, uint8_t x);
```

Updates a threshold's value. This functions sets the threshold's value to the specified value.

## `ao_threshold8_subtract`

```c
void ao_threshold8_subtract(ao_threshold8_t * t, uint8_t x);
```

Updates a threshold's value. This functions subtracts the specified value from the threshold's value.

## `ao_threshold8_subtract_from`

```c
void ao_threshold8_subtract_from(ao_threshold8_t * t, uint8_t x);
```

Updates a threshold's value. This functions subtracts the threshold's value from the specified value.

## `ao_threshold8_xnor`

```c
void ao_threshold8_xnor(ao_threshold8_t * t, uint8_t x);
```

Updates a threshold's value. This functions performs a bitwise XNOR with the specified value.

## `ao_threshold8_xor`

```c
void ao_threshold8_xor(ao_threshold8_t * t, uint8_t x);
```

Updates a threshold's value. This functions performs a bitwise XOR with the specified value.

## `ao_threshold8_wait`
## `ao_threshold8_wait_from`

```c
bool ao_threshold8_wait     (ao_threshold8_wait_t * w, ao_time_t timeout);
bool ao_threshold8_wait_from(ao_threshold8_wait_t * w, ao_time_t timeout, ao_time_t beginning);
```

Waits for a threshold match in a blocking fashion with a timeout and an optional beginning.

## `ao_threshold8_wait_forever`

```c
bool ao_threshold8_wait_forever(ao_threshold8_wait_t * w);
```

Waits for a threshold match indefinitely in a blocking fashion.

## `ao_threshold8_wait_try`

```c
bool ao_threshold8_wait_try(ao_threshold8_wait_t * w);
```

Waits for a threshold match in a non-blocking fashion.

## `ao_threshold8_wait_begin`
## `ao_threshold8_wait_end`

```c
void ao_threshold8_wait_begin(ao_threshold8_wait_t * w);
void ao_threshold8_wait_end  (ao_threshold8_wait_t * w);
```

Begins or ends, respectively, a waiting for a threshold match.
