---
author: "Stefan Wagner"
date: 2022-08-17
description: "The ao_stream.h module of the ao real-time operating system."
draft: true
permalink: /modules/stream/
title: "ao_stream.h"
---

# ao_stream.h

...

## Types

### Stream

The `ao_stream_t` type represents a stream.

```c
struct ao_stream_t
{
    ao_buffer_t  buffer;
    ao_spop_t *  pop;
    ao_spush_t * push;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `buffer` | The buffer. |
| `pop` | The task attempting to pop data from the stream. |
| `push` | The task attempting to push data to the stream. |

### Stream Pushing

The `ao_spush_t` type represents the pushing of data to a stream.

```c
struct ao_spush_t
{
    ao_async_t      async;
    size_t volatile count;
    size_t          count_max;
    size_t          count_min;
    void *          ptr;
    bool   volatile result;
    ao_stream_t *   stream;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `async` | The asynchronous event. |
| `count` | The number of bytes that have been pushed to the stream. |
| `count_max` | The maximum number of bytes to push to the stream. |
| `count_min` | The minimum number of bytes to push to the stream. |
| `ptr` | Points to the data to push to the stream. |
| `result` | Indicates whether data has been pushed to the stream. |
| `stream` | The stream. |

### Stream Popping

The `ao_spop_t` type represents the popping of data from a stream.

```c
struct ao_spop_t
{
    ao_async_t      async;
    size_t volatile count;
    size_t          count_max;
    size_t          count_min;
    void *          ptr;
    bool   volatile result;
    ao_stream_t *   stream;
};
```

It consists of the following members.

| Member | |
|--------|-|
| `async` | The asynchronous event. |
| `count` | The number of bytes that have been popped from the stream. |
| `count_max` | The maximum number of bytes to pop from the stream. |
| `count_min` | The minimum number of bytes to pop from the stream. |
| `ptr` | Points to the location to store the popped data.  |
| `result` | Indicates whether data has been popped from the stream. |
| `stream` | The stream. |

## Initialization

...

## Functions

### Pushing

...

### Popping

...
