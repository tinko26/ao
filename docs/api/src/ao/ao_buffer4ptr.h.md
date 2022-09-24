---
author: "Stefan Wagner"
date: 2022-09-24
draft: true
external:
- https://en.wikipedia.org/wiki/Circular_buffer : "Circular buffer"
- https://en.wikipedia.org/wiki/Data_buffer : "Data buffer"
permalink: /api/src/ao/ao_buffer4ptr.h/
toc: true
---

# Include

`stdbool.h` <br/>
`stddef.h`

# Identifier

```c
#define AO_BUFFER4PTR
```

# Configuration

```c
#define AO_BUFFER4PTR_COUNT_MAX (false)
```

Defines whether to keep track of the maximum number of pointers.

# Types

## `ao_buffer4ptr_t`

```c
typedef struct ao_buffer4ptr_t ao_buffer4ptr_t;
```

This type represents a buffer for pointers.

# Structs

## `ao_buffer4ptr_t`

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

| `capacity` | The maximum number of pointers that can be stored in the buffer. |
| `count` | The current number of pointers stored in the buffer. |
| `count_max` | The maximum number of pointers stored in the buffer. |
| `front` | The front pointer index. |
| `store` | The store. |

# Functions

## `ao_buffer4ptr_is_empty`

```c
#define ao_buffer4ptr_is_empty(x) \
(                                 \
    (x)->count == 0               \
    ? true                        \
    : false                       \
)
```

Checks whether a buffer is empty, in constant time.

## `ao_buffer4ptr_is_full`

```c
#define ao_buffer4ptr_is_full(x) \
(                                \
    (x)->count == (x)->capacity  \
    ? true                       \
    : false                      \
)
```

## `ao_buffer4ptr_peek_*`

```c
bool ao_buffer4ptr_peek_back (ao_buffer4ptr_t const * x, void ** p);
bool ao_buffer4ptr_peek_front(ao_buffer4ptr_t const * x, void ** p);
```

Peeks the back or front pointer, respectively, in constant time. The return value indicates whether the operation was successful. Therefore, it is safe to call this function, if the buffer is empty.

## `ao_buffer4ptr_peek_range_*`

```c
size_t ao_buffer4ptr_peek_range_back (ao_buffer4ptr_t const * x, void ** p, size_t n_min, size_t n_max);
size_t ao_buffer4ptr_peek_range_front(ao_buffer4ptr_t const * x, void ** p, size_t n_min, size_t n_max);
```

Peeks a sequence of back or front pointers, respectively. The `n_min` and `n_max` parameters specify the minimum and maximum number of pointers, respectively. The return value indicates the actual number of pointers and, hence, whether the operation was successful. Therefore, it is safe to call this function, if the buffer is empty.

## `ao_buffer4ptr_pop_*`

```c
bool ao_buffer4ptr_pop_back (ao_buffer4ptr_t * x, void ** p);
bool ao_buffer4ptr_pop_front(ao_buffer4ptr_t * x, void ** p);
```

Pops the back or front pointer, respectively, in constant time. The return value indicates whether the operation was successful. Therefore, it is safe to call this function, if the buffer is empty.

## `ao_buffer4ptr_pop_range_*`

```c
size_t ao_buffer4ptr_pop_range_back (ao_buffer4ptr_t * x, void ** p, size_t n_min, size_t n_max);
size_t ao_buffer4ptr_pop_range_front(ao_buffer4ptr_t * x, void ** p, size_t n_min, size_t n_max);
```

Pops a sequence of back or front pointers, respectively. The `n_min` and `n_max` parameters specify the minimum and maximum number of pointers, respectively. The return value indicates the actual number of pointers and, hence, whether the operation was successful. Therefore, it is safe to call this function, if the buffer is empty.

## `ao_buffer4ptr_push_*`

```c
bool ao_buffer4ptr_push_back (ao_buffer4ptr_t * x, void * p);
bool ao_buffer4ptr_push_front(ao_buffer4ptr_t * x, void * p);
```

Pushes a pointer to the back or front, respectively, in constant time. The return value indicates, whether the operation was successful. Therefore, it is safe to call this function, if the buffer is full.

## `ao_buffer4ptr_push_*_override`

```c
bool ao_buffer4ptr_push_back_override (ao_buffer4ptr_t * x, void * p);
bool ao_buffer4ptr_push_front_override(ao_buffer4ptr_t * x, void * p);
```

Pushes a pointer to the back or front, respectively, in constant time. If the buffer is full, then this function overrides the oldest pointer in the buffer. The return value indicates, whether the operation was successful. Therefore, it is safe to call this function, if the buffer's capacity is zero.

## `ao_buffer4ptr_push_range_*`

```c
size_t ao_buffer4ptr_push_range_back (ao_buffer4ptr_t * x, void * const * p, size_t n_min, size_t n_max);
size_t ao_buffer4ptr_push_range_front(ao_buffer4ptr_t * x, void * const * p, size_t n_min, size_t n_max);
```

Pushes a sequence of pointers to the back or front, respectively. The `n_min` and `n_max` parameters specify the minimum and maximum number of pointers, respectively. The return value indicates the actual number of pointers and, hence, whether the operation was successful. Therefore, it is safe to call this function, if the buffer is too full.

## `ao_buffer4ptr_push_range_*_override`

```c
size_t ao_buffer4ptr_push_range_back_override (ao_buffer4ptr_t * x, void * const * p, size_t n_min, size_t n_max);
size_t ao_buffer4ptr_push_range_front_override(ao_buffer4ptr_t * x, void * const * p, size_t n_min, size_t n_max);
```

Pushes a sequence of pointers to the back or front, respectively. The `n_min` and `n_max` parameters specify the minimum and maximum number of pointers, respectively. If the buffer is too full, then this function overrides the oldest pointers in the buffer. The return value indicates the actual number of pointers and, hence, whether the operation was successful. Therefore, it is safe to call this function, if the buffer's capacity is less than the specified minimum number of pointers.
