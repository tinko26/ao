---
author: "Stefan Wagner"
date: 2022-08-31
draft: false
permalink: /api/src/ao/ao_buffer4obj.h/
toc: true
wiki:
- circular-buffer
- data-buffer
---

# Include

```c
#include <stdbool.h>
#include <stddef.h>
```

# Typedefs

```c
typedef struct ao_buffer4obj_t ao_buffer4obj_t;
```

# Configuration

Keep track of the maximum number of objects.

```c
#define AO_BUFFER4OBJ_COUNT_MAX (false)
```

# Types

## `ao_buffer4obj_t`

This type represents a buffer for objects.

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

It consists of the following members.

| `capacity` | The maximum number of objects that can be stored in the buffer. |
| `count` | The current number of objects stored in the buffer. |
| `count_max` | The maximum number of objects stored in the buffer. |
| `front` | The front object index. |
| `size` | The size of an object in bytes. |
| `store` | The store. |

# Functions

Check whether a buffer is empty or full, respectively, in constant time.

```c
#define ao_buffer4obj_is_empty(x)
#define ao_buffer4obj_is_full(x)
```

Peek the back or front object, respectively, in constant time. The return value indicates whether the operation was successful. Therefore, it is safe to call this function, if the buffer is empty.

```c
bool ao_buffer4obj_peek_back( ao_buffer4obj_t const * x, void * p);
bool ao_buffer4obj_peek_front(ao_buffer4obj_t const * x, void * p);
```

Peek a sequence of back or front objects, respectively. The `n_min` and `n_max` parameters specify the minimum and maximum number of objects, respectively. The return value indicates the actual number of objects and, hence, whether the operation was successful. Therefore, it is safe to call this function, if the buffer is empty.

```c
size_t ao_buffer4obj_peek_range_back( ao_buffer4obj_t const * x, void * p, size_t n_min, size_t n_max);
size_t ao_buffer4obj_peek_range_front(ao_buffer4obj_t const * x, void * p, size_t n_min, size_t n_max);
```

Pop the back or front object, respectively, in constant time. The return value indicates whether the operation was successful. Therefore, it is safe to call this function, if the buffer is empty.

```c
bool ao_buffer4obj_pop_back( ao_buffer4obj_t * x, void * p);
bool ao_buffer4obj_pop_front(ao_buffer4obj_t * x, void * p);
```

Pop a sequence of back or front objects, respectively. The `n_min` and `n_max` parameters specify the minimum and maximum number of objects, respectively. The return value indicates the actual number of objects and, hence, whether the operation was successful. Therefore, it is safe to call this function, if the buffer is empty.

```c
size_t ao_buffer4obj_pop_range_back( ao_buffer4obj_t * x, void * p, size_t n_min, size_t n_max);
size_t ao_buffer4obj_pop_range_front(ao_buffer4obj_t * x, void * p, size_t n_min, size_t n_max);
```

Push an object to the back or front, respectively, in constant time. The return value indicates, whether the operation was successful. Therefore, it is safe to call this function, if the buffer is full.

```c
bool ao_buffer4obj_push_back( ao_buffer4obj_t * x, void const * p);
bool ao_buffer4obj_push_front(ao_buffer4obj_t * x, void const * p);
```

Push an object to the back or front, respectively, in constant time. If the buffer is full, then this function overrides the oldest object in the buffer. The return value indicates, whether the operation was successful. Therefore, it is safe to call this function, if the buffer's capacity is zero.

```c
bool ao_buffer4obj_push_back_override( ao_buffer4obj_t * x, void const * p);
bool ao_buffer4obj_push_front_override(ao_buffer4obj_t * x, void const * p);
```

Push a sequence of objects to the back or front, respectively. The `n_min` and `n_max` parameters specify the minimum and maximum number of objects, respectively. The return value indicates the actual number of objects and, hence, whether the operation was successful. Therefore, it is safe to call this function, if the buffer is too full.

```c
size_t ao_buffer4obj_push_range_back( ao_buffer4obj_t * x, void const * p, size_t n_min, size_t n_max);
size_t ao_buffer4obj_push_range_front(ao_buffer4obj_t * x, void const * p, size_t n_min, size_t n_max);
```

Push a sequence of objects to the back or front, respectively. The `n_min` and `n_max` parameters specify the minimum and maximum number of objects, respectively. If the buffer is too full, then this function overrides the oldest objects in the buffer. The return value indicates the actual number of objects and, hence, whether the operation was successful. Therefore, it is safe to call this function, if the buffer's capacity is less than the specified minimum number of objects.

```c
size_t ao_buffer4obj_push_range_back_override( ao_buffer4obj_t * x, void const * p, size_t n_min, size_t n_max);
size_t ao_buffer4obj_push_range_front_override(ao_buffer4obj_t * x, void const * p, size_t n_min, size_t n_max);
```

# Usage

An object buffer can be initialized by clearing all of its members.

```c
ao_buffer4obj_t * b;
```

```c
b->capacity = 0;
b->count = 0;
b->count_max = 0;
b->front = 0;
b->size = 0;
b->store = NULL;
```

However, such a buffer is not very useful, since it cannot store a single object. Therefore, it should be equipped with a store.

```c
double store[128];
```

```c
b->capacity = 128;
b->store = store;
```

Additionally, the object size must be set appropriately.

```c
b->size = sizeof(double);
```
