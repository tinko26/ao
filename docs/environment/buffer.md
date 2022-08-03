---
author: "Stefan Wagner"
date: 2022-08-03
description: "Buffers in the ao Real-Time Operating System (RTOS)."
draft: true
permalink: /environment/buffer/
title: "Buffers"
---

# Buffers

The `ao_buffer.h` module defines [data buffers](https://en.wikipedia.org/wiki/Data_buffer), that is, places to temporarily store data.

## Configuration

Buffers can be configured to keep track of the maximum number of bytes ever contained within them. This can be useful when optimizing the memory usage of a buffer. By default, this option is disabled.

```c
#define AO_BUFFER_COUNT_MAX (true)
```

## Types

The `ao_buffer_t` type represents a data buffer. 

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
| `count_max` | The maximum-ever number of bytes contained in the buffer. This member is present, only, if the `AO_BUFFER_COUNT_MAX` configuration option is enabled.  |
| `front` | The index of the current first byte in the buffer. |
| `store` | The pointer to a memory block, whose size it not less than the specified `capacity`. |

## Initialization

A buffer can be initialized by clearing all its members. 

```c
ao_buffer_t * b;

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
