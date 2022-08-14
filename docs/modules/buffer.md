---
author: "Stefan Wagner"
date: 2022-08-04
description: "The ao_buffer.h module of the ao real-time operating system."
draft: false
permalink: /modules/buffer/
title: "ao_buffer.h"
---

# ao_buffer.h

This module defines buffers, that is, places to temporarily store data.

## Configuration

Buffers can be configured to keep track of the maximum number of bytes ever contained within them. This can be useful when optimizing the memory usage of a buffer. By default, this option is disabled.

```c
#define AO_BUFFER_COUNT_MAX
```

## Type

The `ao_buffer_t` type represents a buffer. 

```c
struct ao_buffer_t
{
    size_t capacity;
    size_t count;
    size_t count_max;
    size_t front;
    void * store;
};
```

It consists of the following members.

| Member | |
|-|-|
| `capacity` | The maximum number of bytes that the buffer can contain. If this value is greater than zero, then the `store` value must not be clear. |
| `count` | The current number of bytes contained in the buffer. |
| `count_max` | The maximum-ever number of bytes contained in the buffer. This member is absent, if the `AO_BUFFER_COUNT_MAX` configuration option is disabled.  |
| `front` | The index of the current front byte in the buffer. |
| `store` | The pointer to a memory block, whose size is not less than the specified `capacity`. |

## Initialization

A buffer can be initialized by clearing all of its members. 

```c
ao_buffer_t * b;
```

```c
b->capacity = 0;
b->count = 0;
b->count_max = 0;
b->front = 0;
b->store = NULL;
```

However, such a buffer is not very useful, since it cannot store a single byte. Therefore, it should be equipped with a store.

```c
uint8_t store[128];
```

```c
b->capacity = 128;
b->store = store;
```

## Functions

If a buffer's count is zero, then the buffer is empty. Accordingly, if the buffer's count matches its capacity, then the buffer is full. Both cases can be checked with a respective macro function.

```c
if (ao_buffer_is_empty(b))
{
    // Buffer is empty.
}
```

```c
if (ao_buffer_is_full(b))
{
    // Buffer is full.
}
```

Data can be inserted at either end of a buffer. Thereby, one can push a single byte ...

```c
uint8_t d1 = 0x5FU;
```

```c
ao_buffer_push_back(b, &d1);
ao_buffer_push_front(b, &d1);
```

... or a number of bytes from a specified range, for example $$[1, 4]$$.

```c
uint32_t d4 = 0xDEADBEEFU;
```

```c
ao_buffer_push_range_back(b, &d4, 1, 4);
ao_buffer_push_range_front(b, &d4, 1, 4);
```

The single-byte functions return a boolean value that indicates, whether the operation was successful. The range functions, however, return the number of bytes that have actually been inserted. Consequently, if there is not enough free space left in the buffer, these functions return `false` or `0`, respectively. 

However, in some scenarios, such as continuous media or sensor data streaming, it is desirable to simply override old data when adding new data.

```c
ao_buffer_push_back_override(b, &d1);
ao_buffer_push_front_override(b, &d1);
```

```c
ao_buffer_push_range_back_override(b, &d4, 1, 4);
ao_buffer_push_range_front_override(b, &d4, 1, 4);
```

Just like insertion, removal of data is feasible at either end.

```c
ao_buffer_pop_back(b, &d1);
ao_buffer_pop_front(b, &d1);
```

```c
ao_buffer_pop_range_back(b, &d4, 1, 4);
ao_buffer_pop_range_front(b, &d4, 1, 4);
```

Once again, the functions' return values indicate if or how many bytes, respectively, have been removed from the buffer.

Additionally, data can be retrieved from a buffer, without actually removing it.

```c
ao_buffer_peek_back(b, &d1);
ao_buffer_peek_front(b, &d1);
```

```c
ao_buffer_peek_range_back(b, &d4, 1, 4);
ao_buffer_peek_range_front(b, &d4, 1, 4);
```

## External Links

[https://en.wikipedia.org/wiki/Data_buffer](https://en.wikipedia.org/wiki/Data_buffer)
