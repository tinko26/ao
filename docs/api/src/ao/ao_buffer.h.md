---
author: "Stefan Wagner"
date: 2022-09-24
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

| `stdbool.h` |
| `stddef.h` |

# Identifier

```c
#define AO_BUFFER
```

# Configuration

## `AO_BUFFER_COUNT_MAX`

```c
#define AO_BUFFER_COUNT_MAX (false)
```

Defines whether to keep track of the maximum number of bytes.

# Types

## `ao_buffer_t`

```c
typedef struct ao_buffer_t ao_buffer_t;
```

This type represents a buffer.

# Structs

## `ao_buffer_t`

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

| `capacity` | The maximum number of bytes that can be stored in the buffer. |
| `count` | The current number of bytes stored in the buffer. |
| `count_max` | The maximum number of bytes stored in the buffer. |
| `front` | The front byte index. |
| `store` | The store. |

# Functions

## `ao_buffer_is_empty`

```c
#define ao_buffer_is_empty(x) \
(                             \
    (x)->count == 0           \
    ? true                    \
    : false                   \
)
```

Checks whether a buffer is empty, in constant time.

## `ao_buffer_is_full`

```c
#define ao_buffer_is_full(x)    \
(                               \
    (x)->count == (x)->capacity \
    ? true                      \
    : false                     \
)
```

Checks whether a buffer is full, in constant time.

## `ao_buffer_peek_*`

```c
bool ao_buffer_peek_back (ao_buffer_t const * x, void * p);
bool ao_buffer_peek_front(ao_buffer_t const * x, void * p);
```

Peeks the back or front byte, respectively, in constant time. The return value indicates whether the operation was successful. Therefore, it is safe to call this function, if the buffer is empty.

## `ao_buffer_peek_range_*`

```c
size_t ao_buffer_peek_range_back (ao_buffer_t const * x, void * p, size_t n_min, size_t n_max);
size_t ao_buffer_peek_range_front(ao_buffer_t const * x, void * p, size_t n_min, size_t n_max);
```

Peeks a sequence of back or front bytes, respectively. The `n_min` and `n_max` parameters specify the minimum and maximum number of bytes, respectively. The return value indicates the actual number of bytes and, hence, whether the operation was successful. Therefore, it is safe to call this function, if the buffer is empty.

## `ao_buffer_pop_*`

```c
bool ao_buffer_pop_back (ao_buffer_t * x, void * p);
bool ao_buffer_pop_front(ao_buffer_t * x, void * p);
```

Pops the back or front byte, respectively, in constant time. The return value indicates whether the operation was successful. Therefore, it is safe to call this function, if the buffer is empty.

## `ao_buffer_pop_range_*`

```c
size_t ao_buffer_pop_range_back (ao_buffer_t * x, void * p, size_t n_min, size_t n_max);
size_t ao_buffer_pop_range_front(ao_buffer_t * x, void * p, size_t n_min, size_t n_max);
```

Pops a sequence of back or front bytes, respectively. The `n_min` and `n_max` parameters specify the minimum and maximum number of bytes, respectively. The return value indicates the actual number of bytes and, hence, whether the operation was successful. Therefore, it is safe to call this function, if the buffer is empty.

## `ao_buffer_push_*`

```c
bool ao_buffer_push_back (ao_buffer_t * x, void const * p);
bool ao_buffer_push_front(ao_buffer_t * x, void const * p);
```

Pushes a byte to the back or front, respectively, in constant time. The return value indicates, whether the operation was successful. Therefore, it is safe to call this function, if the buffer is full.

## `ao_buffer_push_*_override`

```c
bool ao_buffer_push_back_override (ao_buffer_t * x, void const * p);
bool ao_buffer_push_front_override(ao_buffer_t * x, void const * p);
```

Pushes a byte to the back or front, respectively, in constant time. If the buffer is full, then this function overrides the oldest byte in the buffer. The return value indicates, whether the operation was successful. Therefore, it is safe to call this function, if the buffer's capacity is zero.

## `ao_buffer_push_range_*`

```c
size_t ao_buffer_push_range_back (ao_buffer_t * x, void const * p, size_t n_min, size_t n_max);
size_t ao_buffer_push_range_front(ao_buffer_t * x, void const * p, size_t n_min, size_t n_max);
```

Pushes a sequence of bytes to the back or front, respectively. The `n_min` and `n_max` parameters specify the minimum and maximum number of bytes, respectively. The return value indicates the actual number of bytes and, hence, whether the operation was successful. Therefore, it is safe to call this function, if the buffer is too full.

## `ao_buffer_push_range_*_override`

```c
size_t ao_buffer_push_range_back_override (ao_buffer_t * x, void const * p, size_t n_min, size_t n_max);
size_t ao_buffer_push_range_front_override(ao_buffer_t * x, void const * p, size_t n_min, size_t n_max);
```

Pushes a sequence of bytes to the back or front, respectively. The `n_min` and `n_max` parameters specify the minimum and maximum number of bytes, respectively. If the buffer is too full, then this function overrides the oldest bytes in the buffer. The return value indicates the actual number of bytes and, hence, whether the operation was successful. Therefore, it is safe to call this function, if the buffer's capacity is less than the specified minimum number of bytes.
