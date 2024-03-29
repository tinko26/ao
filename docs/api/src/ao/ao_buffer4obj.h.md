---
author: "Stefan Wagner"
date: 2022-09-28
draft: true
external:
- https://en.wikipedia.org/wiki/Circular_buffer : "Circular buffer"
permalink: /api/src/ao/ao_buffer4obj.h/
toc: true
---

# Include

| `stdbool.h` |
| `stddef.h` |

# Configuration

```c
#define AO_BUFFER4OBJ_COUNT_MAX (false)
```

Defines whether to keep track of the maximum number of objects.

# Types

## `ao_buffer4obj_t`

```c
typedef struct ao_buffer4obj_t ao_buffer4obj_t;
```

Represents a buffer for objects.

# Structs

## `ao_buffer4obj_t`

```c
struct ao_buffer4obj_t
{
    size_t capacity;
    size_t count;

#if AO_BUFFER4OBJ_COUNT_MAX

    size_t count_max;

#endif

    size_t front;
    size_t size;
    void * store;
};
```

| `capacity` | The maximum number of objects that can be stored in the buffer. |
| `count` | The current number of objects stored in the buffer. |
| `count_max` | The maximum number of objects stored in the buffer. |
| `front` | The front object index. |
| `size` | The size of an object, in bytes. |
| `store` | The store. |

# Functions

## `ao_buffer4obj_is_empty`
## `ao_buffer4obj_is_full`

```c
bool ao_buffer4obj_is_empty(ao_buffer4obj_t const * b);
bool ao_buffer4obj_is_full (ao_buffer4obj_t const * b);
```

Checks whether a buffer is empty or full, respectively, in constant time.

## `ao_buffer4obj_peek_*`

```c
bool ao_buffer4obj_peek_back (ao_buffer4obj_t const * b, void * p);
bool ao_buffer4obj_peek_front(ao_buffer4obj_t const * b, void * p);
```

Peeks the back or front object, respectively, in constant time. The return value indicates whether the operation was successful. Therefore, it is safe to call this function, if the buffer is empty.

## `ao_buffer4obj_peek_range_*`

```c
size_t ao_buffer4obj_peek_range_back (ao_buffer4obj_t const * b, void * p, size_t n_min, size_t n_max);
size_t ao_buffer4obj_peek_range_front(ao_buffer4obj_t const * b, void * p, size_t n_min, size_t n_max);
```

Peeks a sequence of back or front objects, respectively. The `n_min` and `n_max` parameters specify the minimum and maximum number of objects, respectively. The return value indicates the actual number of objects and, hence, whether the operation was successful. Therefore, it is safe to call this function, if the buffer is empty.

## `ao_buffer4obj_pop_*`

```c
bool ao_buffer4obj_pop_back (ao_buffer4obj_t * b, void * p);
bool ao_buffer4obj_pop_front(ao_buffer4obj_t * b, void * p);
```

Pops the back or front object, respectively, in constant time. The return value indicates whether the operation was successful. Therefore, it is safe to call this function, if the buffer is empty.

## `ao_buffer4obj_pop_range_*`

```c
size_t ao_buffer4obj_pop_range_back (ao_buffer4obj_t * b, void * p, size_t n_min, size_t n_max);
size_t ao_buffer4obj_pop_range_front(ao_buffer4obj_t * b, void * p, size_t n_min, size_t n_max);
```

Pops a sequence of back or front objects, respectively. The `n_min` and `n_max` parameters specify the minimum and maximum number of objects, respectively. The return value indicates the actual number of objects and, hence, whether the operation was successful. Therefore, it is safe to call this function, if the buffer is empty.

## `ao_buffer4obj_push_*`

```c
bool ao_buffer4obj_push_back (ao_buffer4obj_t * b, void const * p);
bool ao_buffer4obj_push_front(ao_buffer4obj_t * b, void const * p);
```

Pushes an object to the back or front, respectively, in constant time. The return value indicates, whether the operation was successful. Therefore, it is safe to call this function, if the buffer is full.

## `ao_buffer4obj_push_*_override`

```c
bool ao_buffer4obj_push_back_override (ao_buffer4obj_t * b, void const * p);
bool ao_buffer4obj_push_front_override(ao_buffer4obj_t * b, void const * p);
```

Pushes an object to the back or front, respectively, in constant time. If the buffer is full, then this function overrides the oldest object in the buffer. The return value indicates, whether the operation was successful. Therefore, it is safe to call this function, if the buffer's capacity is zero.

## `ao_buffer4obj_push_range_*`

```c
size_t ao_buffer4obj_push_range_back (ao_buffer4obj_t * b, void const * p, size_t n_min, size_t n_max);
size_t ao_buffer4obj_push_range_front(ao_buffer4obj_t * b, void const * p, size_t n_min, size_t n_max);
```

Pushes a sequence of objects to the back or front, respectively. The `n_min` and `n_max` parameters specify the minimum and maximum number of objects, respectively. The return value indicates the actual number of objects and, hence, whether the operation was successful. Therefore, it is safe to call this function, if the buffer is too full.

## `ao_buffer4obj_push_range_*_override`

```c
size_t ao_buffer4obj_push_range_back_override (ao_buffer4obj_t * b, void const * p, size_t n_min, size_t n_max);
size_t ao_buffer4obj_push_range_front_override(ao_buffer4obj_t * b, void const * p, size_t n_min, size_t n_max);
```

Pushes a sequence of objects to the back or front, respectively. The `n_min` and `n_max` parameters specify the minimum and maximum number of objects, respectively. If the buffer is too full, then this function overrides the oldest objects in the buffer. The return value indicates the actual number of objects and, hence, whether the operation was successful. Therefore, it is safe to call this function, if the buffer's capacity is less than the specified minimum number of objects.
