---
author: "Stefan Wagner"
date: 2022-09-27
draft: true
permalink: /api/src/ao_sys/ao_threshold16.h/
toc: true
---

# Include

| [`ao_async.h`](ao_async.h.md) |
| [`ao_list.h`](../ao/ao_list.h.md) |
| [`ao_time.h`](ao_time.h.md) |
| `stdbool.h` |
| `stdint.h` |

# Types

## `ao_threshold16_t`

```c
typedef struct ao_threshold16_t ao_threshold16_t;
```

Represents a threshold.

## `ao_threshold16_wait_t`

```c
typedef struct ao_threshold16_wait_t ao_threshold16_wait_t;
```

Represents the waiting for a threshold match.

## `ao_threshold16_adjust_t`

```c
typedef uint16_t (* ao_threshold16_adjust_t)
(
    uint16_t value_old,
    void *   parameter
);
```

Represents a function to adjust a threshold value. The function takes the old value and an additional parameter and returns the new value.

## `ao_threshold16_match_t`

```c
typedef bool (* ao_threshold16_match_t)
(
    uint16_t value_old,
    uint16_t value_new,
    void *   parameter
);
```

Represents a function to check whether a specific threshold value is a match. The function takes both the old and the new value of a threshold as well as an additional parameter.

# Structs

## `ao_threshold16_t`

```c
struct ao_threshold16_t
{
    ao_threshold16_adjust_t adjust;
    void *                  adjust_parameter;
    ao_threshold16_match_t  match;
    void *                  match_parameter;
    uint16_t                value;
    ao_list_t               wait;
};
```

| `adjust` | The adjust function. |
| `adjust_parameter` | The adjust function parameter. |
| `match` | The match function. |
| `match_parameter` | The match function parameter. |
| `value` | The value. |
| `wait` | The list of waitings. |

## `ao_threshold16_wait_t`

```c
struct ao_threshold16_wait_t
{
    ao_async_t         async;
    bool      volatile result;
    ao_threshold16_t * threshold;
    ao_list_node_t     threshold_wait_node;
    uint16_t  volatile value_new;
    uint16_t  volatile value_old;
};
```

| `async` | The asynchronous event. |
| `result` | The result. |
| `threshold` | The threshold. |
| `threshold_wait_node` | The node for the threshold's list of waitings. |
| `value_new` | The new value. |
| `value_old` | The old value. |

# Functions

## `ao_threshold16_adjust`

```c
void ao_threshold16_adjust(ao_threshold16_t * threshold, ao_threshold16_adjust_t adjust, void * adjust_parameter);
```

| `threshold` | The threshold. |
| `adjust` | The adjust function. |
| `adjust_parameter` | The adjust function parameter. |

Adjusts a threshold.

## `ao_threshold16_add`

```c
void ao_threshold16_add(ao_threshold16_t * threshold, uint16_t x);
```

Updates a threshold's value. This functions adds the threshold's value and the specified value.

## `ao_threshold16_and`

```c
void ao_threshold16_and(ao_threshold16_t * threshold, uint16_t x);
```

Updates a threshold's value. This functions performs a bitwise AND with the specified value.

## `ao_threshold16_decrement`

```c
void ao_threshold16_decrement(ao_threshold16_t * threshold);
```

Updates a threshold's value. This functions decrements the threshold's value.

## `ao_threshold16_divide`

```c
void ao_threshold16_divide(ao_threshold16_t * threshold, uint16_t x);
```

Updates a threshold's value. This functions divides the threshold's value by the specified value.

## `ao_threshold16_increment`

```c
void ao_threshold16_increment(ao_threshold16_t * threshold);
```

Updates a threshold's value. This functions increments the threshold's value.

## `ao_threshold16_max`

```c
void ao_threshold16_max(ao_threshold16_t * threshold);
```

Updates a threshold's value. This functions sets the threshold's value to the maximum possible value.

## `ao_threshold16_min`

```c
void ao_threshold16_min(ao_threshold16_t * threshold);
```

Updates a threshold's value. This functions sets the threshold's value to the minimum possible value, i.e. zero.

## `ao_threshold16_modulo`

```c
void ao_threshold16_modulo(ao_threshold16_t * threshold, uint16_t x);
```

Updates a threshold's value. This functions sets the threshold's value to the remainder of it divided by the specified value.

## `ao_threshold16_multiply`

```c
void ao_threshold16_multiply(ao_threshold16_t * threshold, uint16_t x);
```

Updates a threshold's value. This functions multiplies the threshold's value with the specified value.

## `ao_threshold16_nand`

```c
void ao_threshold16_nand(ao_threshold16_t * threshold, uint16_t x);
```

Updates a threshold's value. This functions performs a bitwise NAND with the specified value.

## `ao_threshold16_nor`

```c
void ao_threshold16_nor(ao_threshold16_t * threshold, uint16_t x);
```

Updates a threshold's value. This functions performs a bitwise NOR with the specified value.

## `ao_threshold16_not`

```c
void ao_threshold16_not(ao_threshold16_t * threshold);
```

Updates a threshold's value. This functions performs a bitwise inversion on the threshold's value.

## `ao_threshold16_or`

```c
void ao_threshold16_or(ao_threshold16_t * threshold, uint16_t x);
```

Updates a threshold's value. This functions performs a bitwise OR with the specified value.

## `ao_threshold16_set`

```c
void ao_threshold16_set(ao_threshold16_t * threshold, uint16_t x);
```

Updates a threshold's value. This functions sets the threshold's value to the specified value.

## `ao_threshold16_subtract`

```c
void ao_threshold16_subtract(ao_threshold16_t * threshold, uint16_t x);
```

Updates a threshold's value. This functions subtracts the specified value from the threshold's value.

## `ao_threshold16_subtract_from`

```c
void ao_threshold16_subtract_from(ao_threshold16_t * threshold, uint16_t x);
```

Updates a threshold's value. This functions subtracts the threshold's value from the specified value.

## `ao_threshold16_xnor`

```c
void ao_threshold16_xnor(ao_threshold16_t * threshold, uint16_t x);
```

Updates a threshold's value. This functions performs a bitwise XNOR with the specified value.

## `ao_threshold16_xor`

```c
void ao_threshold16_xor(ao_threshold16_t * threshold, uint16_t x);
```

Updates a threshold's value. This functions performs a bitwise XOR with the specified value.

## `ao_threshold16_wait`
## `ao_threshold16_wait_from`

```c
bool ao_threshold16_wait     (ao_threshold16_wait_t * wait, ao_time_t timeout);
bool ao_threshold16_wait_from(ao_threshold16_wait_t * wait, ao_time_t timeout, ao_time_t beginning);
```

Waits for a threshold match in a blocking fashion with a timeout and an optional beginning.

## `ao_threshold16_wait_forever`

```c
bool ao_threshold16_wait_forever(ao_threshold16_wait_t * wait);
```

Waits for a threshold match indefinitely in a blocking fashion.

## `ao_threshold16_wait_try`

```c
bool ao_threshold16_wait_try(ao_threshold16_wait_t * wait);
```

Waits for a threshold match in a non-blocking fashion.

## `ao_threshold16_wait_begin`
## `ao_threshold16_wait_end`

```c
void ao_threshold16_wait_begin(ao_threshold16_wait_t * wait);
void ao_threshold16_wait_end  (ao_threshold16_wait_t * wait);
```

Begins or ends, respectively, a waiting for a threshold match.
