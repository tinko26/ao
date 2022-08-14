---
author: "Stefan Wagner"
date: 2022-08-04
description: ""
draft: false
permalink: /environment/buffer4obj/
title: "Object Buffers"
---

# Object Buffers

The `ao_buffer4obj.h` module defines object [buffers](https://en.wikipedia.org/wiki/Data_buffer). In contrast to ordinary [buffers](buffer.md), they do not temporarily store a stream of bytes of arbitrary length, but fixed-size blocks of memory, or objects.

## Configuration

Object buffers can be configured to keep track of the maximum number of objects ever contained within them. This can be useful when optimizing the memory usage of a buffer. By default, this option is disabled.

```c
#define AO_BUFFER4OBJ_COUNT_MAX
```

## Type

The `ao_buffer4obj_t` type represents an object buffer. 

```c
struct ao_buffer4obj_t
{
    size_t capacity;
    size_t count;
    size_t count_max;
    size_t front;
    size_t size;
    void * store;
};
```

It consists of the following members.

| Member | |
|-|-|
| `capacity` | The maximum number of objects that the buffer can contain. If this value is greater than zero, then the `store` value must not be clear. |
| `count` | The current number of objects contained in the buffer. |
| `count_max` | The maximum-ever number of objects contained in the buffer. This member is absent, if the `AO_BUFFER4OBJ_COUNT_MAX` configuration option is disabled. |
| `front` | The index of the current front object in the buffer. |
| `size` | The size of an object, in bytes. |
| `store` | The pointer to a memory block that can store at least the number of objects specified by the `capacity` member. |

## Initialization

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

## Functions

If a buffer's count is zero, then the buffer is empty. Accordingly, if the buffer's count matches its capacity, then the buffer is full. Both cases can be checked with a respective macro function.

```c
if (ao_buffer4obj_is_empty(b))
{
    // Buffer is empty.
}
```

```c
if (ao_buffer4obj_is_full(b))
{
    // Buffer is full.
}
```

Objects can be inserted at either end of a buffer. Thereby, one can push a single object ...

```c
double d = 3.141;
```

```c
ao_buffer4obj_push_back(b, &d);
ao_buffer4obj_push_front(b, &d);
```

... or a number of objects from a specified range, for example $$[1, 4]$$.

```c
double D[4] = 
{
    1.0,
    2.0,
    3.0,
    4.0
};
```

```c
ao_buffer4obj_push_range_back(b, D, 1, 4);
ao_buffer4obj_push_range_front(b, D, 1, 4);
```

The single-object functions return a boolean value that indicates, whether the operation was successful. The range functions, however, return the number of objects that have actually been inserted. Consequently, if there is not enough free space left in the buffer, these functions return `false` or `0`, respectively. 

However, in some scenarios, such as continuous media or sensor data streaming, it is desirable to simply override old data when adding new data.

```c
ao_buffer4obj_push_back_override(b, &d);
ao_buffer4obj_push_front_override(b, &d);
```

```c
ao_buffer4obj_push_range_back_override(b, D, 1, 4);
ao_buffer4obj_push_range_front_override(b, D, 1, 4);
```

Just like insertion, removal of objects is feasible at either end.

```c
ao_buffer4obj_pop_back(b, &d);
ao_buffer4obj_pop_front(b, &d);
```

```c
ao_buffer4obj_pop_range_back(b, D, 1, 4);
ao_buffer4obj_pop_range_front(b, D, 1, 4);
```

Once again, the functions' return values indicate if or how many objects, respectively, have been removed from the buffer.

Additionally, objects can be retrieved from a buffer, without actually removing them.

```c
ao_buffer4obj_peek_back(b, &d);
ao_buffer4obj_peek_front(b, &d);
```

```c
ao_buffer4obj_peek_range_back(b, D, 1, 4);
ao_buffer4obj_peek_range_front(b, D, 1, 4);
```
