---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
external:
- https://en.wikipedia.org/wiki/Circular_buffer : "Circular buffer"
- https://en.wikipedia.org/wiki/Data_buffer : "Data buffer"
permalink: /api/src/ao/ao_buffer.h/
toc: true
---

# Notes

This module defines buffers, that is, places to temporarily store data.

# Include

```c
#include <stdbool.h>
#include <stddef.h>
```

# Identifiers

## `AO_BUFFER`

```c
#define AO_BUFFER
```

# Configuration

## `AO_BUFFER_COUNT_MAX`

Keep track of the maximum number of bytes.

```c
#define AO_BUFFER_COUNT_MAX (false)
```

# Typedefs

```c
typedef struct ao_buffer_t ao_buffer_t;
```

# Types

## `ao_buffer_t`

This type represents a buffer.

```c
struct ao_buffer_t
{
    size_t capacity;
    size_t count;

#if AO_BUFFER_COUNT_MAX

    size_t count_max;

#endif

    size_t front;
    void * store;
};
```

It consists of the following members.

| `capacity` | The maximum number of bytes that can be stored in the buffer. |
| `count` | The current number of bytes stored in the buffer. |
| `count_max` | The maximum number of bytes stored in the buffer. |
| `front` | The front byte index. |
| `store` | The store. |

# Functions

## `ao_buffer_is_empty`
## `ao_buffer_is_full`

Check whether a buffer is empty or full, respectively, in constant time.

```c
#define ao_buffer_is_empty(x)
#define ao_buffer_is_full(x)
```

## `ao_buffer_peek_back`
## `ao_buffer_peek_front`

Peek the back or front byte, respectively, in constant time. The return value indicates whether the operation was successful. Therefore, it is safe to call this function, if the buffer is empty.

```c
bool ao_buffer_peek_back( ao_buffer_t const * x, void * p);
bool ao_buffer_peek_front(ao_buffer_t const * x, void * p);
```

## `ao_buffer_peek_range_back`
## `ao_buffer_peek_range_front`

Peek a sequence of back or front bytes, respectively. The `n_min` and `n_max` parameters specify the minimum and maximum number of bytes, respectively. The return value indicates the actual number of bytes and, hence, whether the operation was successful. Therefore, it is safe to call this function, if the buffer is empty.

```c
size_t ao_buffer_peek_range_back( ao_buffer_t const * x, void * p, size_t n_min, size_t n_max);
size_t ao_buffer_peek_range_front(ao_buffer_t const * x, void * p, size_t n_min, size_t n_max);
```

## `ao_buffer_pop_back`
## `ao_buffer_pop_front`

Pop the back or front byte, respectively, in constant time. The return value indicates whether the operation was successful. Therefore, it is safe to call this function, if the buffer is empty.

```c
bool ao_buffer_pop_back( ao_buffer_t * x, void * p);
bool ao_buffer_pop_front(ao_buffer_t * x, void * p);
```

## `ao_buffer_pop_range_back`
## `ao_buffer_pop_range_front`

Pop a sequence of back or front bytes, respectively. The `n_min` and `n_max` parameters specify the minimum and maximum number of bytes, respectively. The return value indicates the actual number of bytes and, hence, whether the operation was successful. Therefore, it is safe to call this function, if the buffer is empty.

```c
size_t ao_buffer_pop_range_back( ao_buffer_t * x, void * p, size_t n_min, size_t n_max);
size_t ao_buffer_pop_range_front(ao_buffer_t * x, void * p, size_t n_min, size_t n_max);
```

## `ao_buffer_push_back`
## `ao_buffer_push_front`

Push a byte to the back or front, respectively, in constant time. The return value indicates, whether the operation was successful. Therefore, it is safe to call this function, if the buffer is full.

```c
bool ao_buffer_push_back( ao_buffer_t * x, void const * p);
bool ao_buffer_push_front(ao_buffer_t * x, void const * p);
```

## `ao_buffer_push_back_override`
## `ao_buffer_push_front_override`

Push a byte to the back or front, respectively, in constant time. If the buffer is full, then this function overrides the oldest byte in the buffer. The return value indicates, whether the operation was successful. Therefore, it is safe to call this function, if the buffer's capacity is zero.

```c
bool ao_buffer_push_back_override( ao_buffer_t * x, void const * p);
bool ao_buffer_push_front_override(ao_buffer_t * x, void const * p);
```

## `ao_buffer_push_range_back`
## `ao_buffer_push_range_front`

Push a sequence of bytes to the back or front, respectively. The `n_min` and `n_max` parameters specify the minimum and maximum number of bytes, respectively. The return value indicates the actual number of bytes and, hence, whether the operation was successful. Therefore, it is safe to call this function, if the buffer is too full.

```c
size_t ao_buffer_push_range_back( ao_buffer_t * x, void const * p, size_t n_min, size_t n_max);
size_t ao_buffer_push_range_front(ao_buffer_t * x, void const * p, size_t n_min, size_t n_max);
```

## `ao_buffer_push_range_back_override`
## `ao_buffer_push_range_front_override`

Push a sequence of bytes to the back or front, respectively. The `n_min` and `n_max` parameters specify the minimum and maximum number of bytes, respectively. If the buffer is too full, then this function overrides the oldest bytes in the buffer. The return value indicates the actual number of bytes and, hence, whether the operation was successful. Therefore, it is safe to call this function, if the buffer's capacity is less than the specified minimum number of bytes.

```c
size_t ao_buffer_push_range_back_override( ao_buffer_t * x, void const * p, size_t n_min, size_t n_max);
size_t ao_buffer_push_range_front_override(ao_buffer_t * x, void const * p, size_t n_min, size_t n_max);
```
