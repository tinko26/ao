---
author: "Stefan Wagner"
date: 2022-08-14
description: "The ao_buffer4ptr.h module of the ao real-time operating system."
draft: true
permalink: /modules/buffer4ptr/
title: "ao_buffer4ptr.h"
---

# ao_buffer4ptr.h

This module defines pointer [buffers](https://en.wikipedia.org/wiki/Data_buffer). In contrast to ordinary [buffers](buffer.md), they do not temporarily store a stream of bytes of arbitrary length, but pointers.

## Configuration

Pointer buffers can be configured to keep track of the maximum number of pointers ever contained within them. This can be useful when optimizing the memory usage of a buffer. By default, this option is disabled.

```c
#define AO_BUFFER4PTR_COUNT_MAX
```

## Type

The `ao_buffer4ptr_t` type represents a pointer buffer. 

```c
struct ao_buffer4ptr_t
{
    size_t  capacity;
    size_t  count;
    size_t  count_max;
    size_t  front;
    void ** store;
};
```

It consists of the following members.

| Member | |
|-|-|
| `capacity` | The maximum number of pointers that the buffer can contain. If this value is greater than zero, then the `store` value must not be clear. |
| `count` | The current number of pointers contained in the buffer. |
| `count_max` | The maximum-ever number of pointers contained in the buffer. This member is absent, if the `AO_BUFFER4PTR_COUNT_MAX` configuration option is disabled. |
| `front` | The index of the current front pointer in the buffer. |
| `store` | The pointer to a memory block that can store at least the number of pointers specified by the `capacity` member. |

## Initialization

A pointer buffer can be initialized by clearing all of its members. 

```c
ao_buffer4ptr_t * b;
```

```c
b->capacity = 0;
b->count = 0;
b->count_max = 0;
b->front = 0;
b->store = NULL;
```

However, such a buffer is not very useful, since it cannot store a single pointer. Therefore, it should be equipped with a store.

```c
void * store[128];
```

```c
b->capacity = 128;
b->store = store;
```

## Functions

If a buffer's count is zero, then the buffer is empty. Accordingly, if the buffer's count matches its capacity, then the buffer is full. Both cases can be checked with a respective macro function.

```c
if (ao_buffer4ptr_is_empty(b))
{
    // Buffer is empty.
}
```

```c
if (ao_buffer4ptr_is_full(b))
{
    // Buffer is full.
}
```

Pointers can be inserted at either end of a buffer. Thereby, one can push a single pointer ...

```c
void * p;
```

```c
ao_buffer4ptr_push_back(b, p);
ao_buffer4ptr_push_front(b, p);
```

... or a number of pointers from a specified range, for example $$[1, 4]$$.

```c
void * P[4];
```

```c
ao_buffer4ptr_push_range_back(b, P, 1, 4);
ao_buffer4ptr_push_range_front(b, P, 1, 4);
```

The single-pointer functions return a boolean value that indicates, whether the operation was successful. The range functions, however, return the number of pointers that have actually been inserted. Consequently, if there is not enough free space left in the buffer, these functions return `false` or `0`, respectively. 

However, in some scenarios, such as continuous media or sensor data streaming, it is desirable to simply override old data when adding new data.

```c
ao_buffer4ptr_push_back_override(b, p);
ao_buffer4ptr_push_front_override(b, p);
```

```c
ao_buffer4ptr_push_range_back_override(b, P, 1, 4);
ao_buffer4ptr_push_range_front_override(b, P, 1, 4);
```

Just like insertion, removal of pointers is feasible at either end.

```c
ao_buffer4ptr_pop_back(b, &p);
ao_buffer4ptr_pop_front(b, &p);
```

```c
ao_buffer4ptr_pop_range_back(b, P, 1, 4);
ao_buffer4ptr_pop_range_front(b, P, 1, 4);
```

Once again, the functions' return values indicate if or how many pointers, respectively, have been removed from the buffer.

Additionally, pointers can be retrieved from a buffer, without actually removing them.

```c
ao_buffer4ptr_peek_back(b, &p);
ao_buffer4ptr_peek_front(b, &p);
```

```c
ao_buffer4ptr_peek_range_back(b, P, 1, 4);
ao_buffer4ptr_peek_range_front(b, P, 1, 4);
```
