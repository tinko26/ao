---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
permalink: /api/src/ao_sys/ao_stream.h/
toc: true
---

# Include

| [`ao_async.h`](ao_async.h.md) |
| [`ao_buffer.h`](../ao/ao_buffer.h.md) |
| [`ao_time.h`](ao_time.h.md) |
| `stdbool.h` |
| `stddef.h` |

# Types

## `ao_stream_t`

```c
typedef struct ao_stream_t ao_stream_t;
```

Represents a stream.

## `ao_spop_t`

```c
typedef struct ao_spop_t ao_spop_t;
```

Represents the popping from a stream.

## `ao_spush_t`

```c
typedef struct ao_spush_t ao_spush_t;
```

Represents the pushing to a stream.

# Struct

## `ao_stream_t`

```c
struct ao_stream_t
{
    ao_buffer_t  buffer;
    ao_spop_t  * pop;
    ao_spush_t * push;
};
```

| `buffer` | The buffer. |
| `pop` | The popping. |
| `push` | The pushing. |

## `ao_spop_t`

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

| `async` | The asynchronous event. |
| `count` | The number of bytes that have been popped from the stream. |
| `count_max` | The maximum number of bytes to pop from the stream. |
| `count_min` | The minimum number of bytes to pop from the stream. |
| `ptr` | Points to the location to store the popped data.  |
| `result` | The result. |
| `stream` | The stream. |

## `ao_spush_t`

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

| `async` | The asynchronous event. |
| `count` | The number of bytes that have been pushed to the stream. |
| `count_max` | The maximum number of bytes to push to the stream. |
| `count_min` | The minimum number of bytes to push to the stream. |
| `ptr` | Points to the data to push to the stream. |
| `result` | The result. |
| `stream` | The stream. |

# Functions

## `ao_spop`
## `ao_spop_from`

```c
void ao_spop     (ao_spop_t * pop, ao_time_t timeout);
void ao_spop_from(ao_spop_t * pop, ao_time_t timeout, ao_time_t beginning);
```

Pops from a stream in a blocking fashion with a timeout and an optional beginning.

## `ao_spop_forever`

```c
void ao_spop_forever(ao_spop_t * pop);
```

Pops from a stream indefinitely in a blocking fashion.

## `ao_spop_try`

```c
void ao_spop_try(ao_spop_t * pop);
```

Pops from a stream in a non-blocking fashion.

## `ao_spop_begin`
## `ao_spop_end`

```c
void ao_spop_begin(ao_spop_t * pop);
void ao_spop_end  (ao_spop_t * pop);
```

Begins or ends, respectively, a popping from a stream.

## `ao_spush`
## `ao_spush_from`

```c
void ao_spush     (ao_spush_t * push, ao_time_t timeout);
void ao_spush_from(ao_spush_t * push, ao_time_t timeout, ao_time_t beginning);
```

Pushes to a stream in a blocking fashion with a timeout and an optional beginning.

## `ao_spush_forever`

```c
void ao_spush_forever(ao_spush_t * push);
```

Pushes to a stream indefinitely in a blocking fashion.

## `ao_spush_try`

```c
void ao_spush_try(ao_spush_t * push);
```

Pushes to a stream in a non-blocking fashion.

## `ao_spush_begin`
## `ao_spush_end`

```c
void ao_spush_begin(ao_spush_t * push);
void ao_spush_end  (ao_spush_t * push);
```

Begins or ends, respectively, a pushing to a stream.

## `ao_spush_override`

```c
void ao_spush_override(ao_spush_t * push);
```

Pushes to a stream in a non-blocking fashion. If the stream is full, then this function overrides the oldest data in the stream.
