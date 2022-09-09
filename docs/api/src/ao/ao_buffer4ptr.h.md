---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
external:
- https://en.wikipedia.org/wiki/Circular_buffer : "Circular buffer"
- https://en.wikipedia.org/wiki/Data_buffer : "Data buffer"
permalink: /api/src/ao/ao_buffer4ptr.h/
toc: true
---

# Include

```c
#include <stdbool.h>
#include <stddef.h>
```

# Identifiers

## `AO_BUFFER4PTR`

```c
#define AO_BUFFER4PTR
```

# Configuration

Keep track of the maximum number of pointers.

```c
#define AO_BUFFER4PTR_COUNT_MAX (false)
```

# Typedefs

```c
typedef struct ao_buffer4ptr_t ao_buffer4ptr_t;
```

# Types

## `ao_buffer4ptr_t`

This type represents a buffer for pointers.

```c
struct ao_buffer4ptr_t
{
    size_t  capacity;
    size_t  count;

#if AO_BUFFER4PTR_COUNT_MAX

    size_t  count_max;

#endif

    size_t  front;
    void ** store;
};
```

It consists of the following members.

| `capacity` | The maximum number of pointers that can be stored in the buffer. |
| `count` | The current number of pointers stored in the buffer. |
| `count_max` | The maximum number of pointers stored in the buffer. |
| `front` | The front pointer index. |
| `store` | The store. |

# Functions

## `ao_buffer4ptr_is_empty`
## `ao_buffer4ptr_is_full`

Check whether a buffer is empty or full, respectively, in constant time.

```c
#define ao_buffer4ptr_is_empty(x)
#define ao_buffer4ptr_is_full(x)
```

## `ao_buffer4ptr_peek_back`
## `ao_buffer4ptr_peek_front`

Peek the back or front pointer, respectively, in constant time. The return value indicates whether the operation was successful. Therefore, it is safe to call this function, if the buffer is empty.

```c
bool ao_buffer4ptr_peek_back( ao_buffer4ptr_t const * x, void ** p);
bool ao_buffer4ptr_peek_front(ao_buffer4ptr_t const * x, void ** p);
```

## `ao_buffer4ptr_peek_range_back`
## `ao_buffer4ptr_peek_range_front`

Peek a sequence of back or front pointers, respectively. The `n_min` and `n_max` parameters specify the minimum and maximum number of pointers, respectively. The return value indicates the actual number of pointers and, hence, whether the operation was successful. Therefore, it is safe to call this function, if the buffer is empty.

```c
size_t ao_buffer4ptr_peek_range_back( ao_buffer4ptr_t const * x, void ** p, size_t n_min, size_t n_max);
size_t ao_buffer4ptr_peek_range_front(ao_buffer4ptr_t const * x, void ** p, size_t n_min, size_t n_max);
```

## `ao_buffer4ptr_pop_back`
## `ao_buffer4ptr_pop_front`

Pop the back or front pointer, respectively, in constant time. The return value indicates whether the operation was successful. Therefore, it is safe to call this function, if the buffer is empty.

```c
bool ao_buffer4ptr_pop_back( ao_buffer4ptr_t * x, void ** p);
bool ao_buffer4ptr_pop_front(ao_buffer4ptr_t * x, void ** p);
```

## `ao_buffer4ptr_pop_range_back`
## `ao_buffer4ptr_pop_range_front`

Pop a sequence of back or front pointers, respectively. The `n_min` and `n_max` parameters specify the minimum and maximum number of pointers, respectively. The return value indicates the actual number of pointers and, hence, whether the operation was successful. Therefore, it is safe to call this function, if the buffer is empty.

```c
size_t ao_buffer4ptr_pop_range_back( ao_buffer4ptr_t * x, void ** p, size_t n_min, size_t n_max);
size_t ao_buffer4ptr_pop_range_front(ao_buffer4ptr_t * x, void ** p, size_t n_min, size_t n_max);
```

## `ao_buffer4ptr_push_back`
## `ao_buffer4ptr_push_front`

Push a pointer to the back or front, respectively, in constant time. The return value indicates, whether the operation was successful. Therefore, it is safe to call this function, if the buffer is full.

```c
bool ao_buffer4ptr_push_back( ao_buffer4ptr_t * x, void * p);
bool ao_buffer4ptr_push_front(ao_buffer4ptr_t * x, void * p);
```

## `ao_buffer4ptr_push_back_override`
## `ao_buffer4ptr_push_front_override`

Push a pointer to the back or front, respectively, in constant time. If the buffer is full, then this function overrides the oldest pointer in the buffer. The return value indicates, whether the operation was successful. Therefore, it is safe to call this function, if the buffer's capacity is zero.

```c
bool ao_buffer4ptr_push_back_override( ao_buffer4ptr_t * x, void * p);
bool ao_buffer4ptr_push_front_override(ao_buffer4ptr_t * x, void * p);
```

## `ao_buffer4ptr_push_range_back`
## `ao_buffer4ptr_push_range_front`

Push a sequence of pointers to the back or front, respectively. The `n_min` and `n_max` parameters specify the minimum and maximum number of pointers, respectively. The return value indicates the actual number of pointers and, hence, whether the operation was successful. Therefore, it is safe to call this function, if the buffer is too full.

```c
size_t ao_buffer4ptr_push_range_back( ao_buffer4ptr_t * x, void * const * p, size_t n_min, size_t n_max);
size_t ao_buffer4ptr_push_range_front(ao_buffer4ptr_t * x, void * const * p, size_t n_min, size_t n_max);
```

## `ao_buffer4ptr_push_range_back_override`
## `ao_buffer4ptr_push_range_front_override`

Push a sequence of pointers to the back or front, respectively. The `n_min` and `n_max` parameters specify the minimum and maximum number of pointers, respectively. If the buffer is too full, then this function overrides the oldest pointers in the buffer. The return value indicates the actual number of pointers and, hence, whether the operation was successful. Therefore, it is safe to call this function, if the buffer's capacity is less than the specified minimum number of pointers.

```c
size_t ao_buffer4ptr_push_range_back_override( ao_buffer4ptr_t * x, void * const * p, size_t n_min, size_t n_max);
size_t ao_buffer4ptr_push_range_front_override(ao_buffer4ptr_t * x, void * const * p, size_t n_min, size_t n_max);
```
