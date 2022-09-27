---
author: "Stefan Wagner"
date: 2022-09-27
draft: true
permalink: /api/src/ao_sys/ao_num32.h/
toc: true
---

# Include

| [`ao_async.h`](ao_async.h.md) |
| [`ao_list.h`](../ao/ao_list.h.md) |
| [`ao_time.h`](ao_time.h.md) |
| `stdbool.h` |
| `stdint.h` |

# Types

## `ao_num32_t`

```c
typedef struct ao_num32_t ao_num32_t;
```

This type represents a number.

## `ao_num32_wait_t`

```c
typedef struct ao_num32_wait_t ao_num32_wait_t;
```

This type represents the waiting for a number match.

## `ao_num32_adjust_t`

```c
typedef uint32_t (* ao_num32_adjust_t)
(
    uint32_t value_old,
    void *   parameter
);
```

This type represents a function to adjust a number value. The function takes the old value and an additional parameter and returns the new value.

## `ao_num32_match_t`

```c
typedef bool (* ao_num32_match_t)
(
    uint32_t value_old,
    uint32_t value_new,
    void *   parameter
);
```

This type represents a function to check whether a specific number value is a match. The function takes both the old and the new value of a number as well as an additional parameter.

# Structs

## `ao_num32_t`

```c
struct ao_num32_t
{
    uint32_t  value;
    ao_list_t wait;
};
```

| `value` | The value. |
| `wait` | The list of waitings. |

## `ao_num32_wait_t`

```c
struct ao_num32_wait_t
{
    ao_async_t        async;
    ao_num32_match_t  match;
    void *            match_parameter;
    ao_num32_t *      num;
    ao_list_node_t    num_wait_node;
    bool     volatile result;
    uint32_t volatile value_new;
    uint32_t volatile value_old;
};
```

| `async` | The asynchronous event. |
| `match` | The match function. |
| `match_parameter` | The match function parameter. |
| `num` | The number. |
| `num_wait_node` | The node for the number's list of waitings. |
| `result` | The result. |
| `value_new` | The new value. |
| `value_old` | The old value. |

# Functions

## `ao_num32_adjust`

```c
void ao_num32_adjust(ao_num32_t * num, ao_num32_adjust_t adjust, void * adjust_parameter);
```

| `num` | The number. |
| `adjust` | The adjust function. |
| `adjust_parameter` | The adjust function parameter. |

Adjusts a number.

## `ao_num32_add`

```c
void ao_num32_add(ao_num32_t * num, uint32_t x);
```

Updates a number's value. This functions adds the number's value and the specified value.

## `ao_num32_and`

```c
void ao_num32_and(ao_num32_t * num, uint32_t x);
```

Updates a number's value. This functions performs a bitwise AND with the specified value.

## `ao_num32_decrement`

```c
void ao_num32_decrement(ao_num32_t * num);
```

Updates a number's value. This functions decrements the number's value.

## `ao_num32_divide`

```c
void ao_num32_divide(ao_num32_t * num, uint32_t x);
```

Updates a number's value. This functions divides the number's value by the specified value.

## `ao_num32_increment`

```c
void ao_num32_increment(ao_num32_t * num);
```

Updates a number's value. This functions increments the number's value.

## `ao_num32_max`

```c
void ao_num32_max(ao_num32_t * num);
```

Updates a number's value. This functions sets the number's value to the maximum possible value.

## `ao_num32_min`

```c
void ao_num32_min(ao_num32_t * num);
```

Updates a number's value. This functions sets the number's value to the minimum possible value, i.e. zero.

## `ao_num32_modulo`

```c
void ao_num32_modulo(ao_num32_t * num, uint32_t x);
```

Updates a number's value. This functions sets the number's value to the remainder of it divided by the specified value.

## `ao_num32_multiply`

```c
void ao_num32_multiply(ao_num32_t * num, uint32_t x);
```

Updates a number's value. This functions multiplies the number's value with the specified value.

## `ao_num32_nand`

```c
void ao_num32_nand(ao_num32_t * num, uint32_t x);
```

Updates a number's value. This functions performs a bitwise NAND with the specified value.

## `ao_num32_nor`

```c
void ao_num32_nor(ao_num32_t * num, uint32_t x);
```

Updates a number's value. This functions performs a bitwise NOR with the specified value.

## `ao_num32_not`

```c
void ao_num32_not(ao_num32_t * num);
```

Updates a number's value. This functions performs a bitwise inversion on the number's value.

## `ao_num32_or`

```c
void ao_num32_or(ao_num32_t * num, uint32_t x);
```

Updates a number's value. This functions performs a bitwise OR with the specified value.

## `ao_num32_set`

```c
void ao_num32_set(ao_num32_t * num, uint32_t x);
```

Updates a number's value. This functions sets the number's value to the specified value.

## `ao_num32_subtract`

```c
void ao_num32_subtract(ao_num32_t * num, uint32_t x);
```

Updates a number's value. This functions subtracts the specified value from the number's value.

## `ao_num32_subtract_from`

```c
void ao_num32_subtract_from(ao_num32_t * num, uint32_t x);
```

Updates a number's value. This functions subtracts the number's value from the specified value.

## `ao_num32_xnor`

```c
void ao_num32_xnor(ao_num32_t * num, uint32_t x);
```

Updates a number's value. This functions performs a bitwise XNOR with the specified value.

## `ao_num32_xor`

```c
void ao_num32_xor(ao_num32_t * num, uint32_t x);
```

Updates a number's value. This functions performs a bitwise XOR with the specified value.

## `ao_num32_wait`
## `ao_num32_wait_from`

```c
bool ao_num32_wait     (ao_num32_wait_t * wait, ao_time_t timeout);
bool ao_num32_wait_from(ao_num32_wait_t * wait, ao_time_t timeout, ao_time_t beginning);
```

Waits for a number match in a blocking fashion with a timeout and an optional beginning.

## `ao_num32_wait_forever`

```c
bool ao_num32_wait_forever(ao_num32_wait_t * wait);
```

Waits for a number match indefinitely in a blocking fashion.

## `ao_num32_wait_try`

```c
bool ao_num32_wait_try(ao_num32_wait_t * wait);
```

Waits for a number match in a non-blocking fashion.

## `ao_num32_wait_begin`
## `ao_num32_wait_end`

```c
void ao_num32_wait_begin(ao_num32_wait_t * wait);
void ao_num32_wait_end  (ao_num32_wait_t * wait);
```

Begins or ends, respectively, a waiting for a number match.
