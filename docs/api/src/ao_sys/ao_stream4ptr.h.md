---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
permalink: /api/src/ao_sys/ao_stream4ptr.h/
toc: true
---

# Include

| [`ao_async.h`](ao_async.h.md) |
| [`ao_buffer4ptr.h`](../ao/ao_buffer4ptr.h.md) |
| [`ao_list.h`](../ao/ao_list.h.md) |
| [`ao_time.h`](ao_time.h.md) |
| `stdbool.h` |

# Types

## `ao_stream4ptr_t`

```c
typedef struct ao_stream4ptr_t ao_stream4ptr_t;
```

Represents a stream for pointers.

## `ao_spop_ptr_t`

```c
typedef struct ao_spop_ptr_t ao_spop_ptr_t;
```

Represents the popping of a pointer from a stream.

## `ao_spush_ptr_t`

```c
typedef struct ao_spush_ptr_t ao_spush_ptr_t;
```

Represents the pushing of a pointer to a stream.

# Structs

## `ao_stream4ptr_t`

```c
struct ao_stream4ptr_t
{
    ao_buffer4ptr_t buffer;
    ao_list_t       pop;
    ao_list_t       push;
};
```

| `buffer` | The buffer. |
| `pop` | The list of poppings. |
| `push` | The list of pushings. |

## `ao_spop_ptr_t`

```c
struct ao_spop_ptr_t
{
    ao_async_t        async;
    void * volatile   ptr;
    bool   volatile   result;
    ao_stream4ptr_t * stream;
    ao_list_node_t    stream_pop_node;
};
```

| `async` | The asynchronous event. |
| `ptr` | The pointer that has been popped from the stream. |
| `result` | The result. |
| `stream` | The stream. |
| `stream_pop_node` | The node for the stream's list of poppings. |

## `ao_spush_ptr_t`

```c
struct ao_spush_ptr_t
{
    ao_async_t        async;
    void *            ptr;
    void * volatile   ptr_override;
    bool   volatile   result;
    bool   volatile   result_override;
    ao_stream4ptr_t * stream;
    ao_list_node_t    stream_push_node;
};
```

| `async` | The asynchronous event. |
| `ptr` | The pointer to push. |
| `ptr_override` | The pointer that has been overridden. |
| `result` | The result. |
| `result_override` | Indicates whether a pointer has been overridden. |
| `stream` | The stream. |
| `stream_push_node` | The node for the stream's list of pushings. |

# Functions

## `ao_spop_ptr`
## `ao_spop_ptr_from`

```c
void ao_spop_ptr     (ao_spop_ptr_t * p, ao_time_t timeout);
void ao_spop_ptr_from(ao_spop_ptr_t * p, ao_time_t timeout, ao_time_t beginning);
```

Pops a pointer from a stream in a blocking fashion with a timeout and an optional beginning.

## `ao_spop_ptr_forever`

```c
void ao_spop_ptr_forever(ao_spop_ptr_t * p);
```

Pops a pointer from a stream indefinitely in a blocking fashion.

## `ao_spop_ptr_try`

```c
void ao_spop_ptr_try(ao_spop_ptr_t * p);
```

Pops a pointer from a stream in a non-blocking fashion.

## `ao_spop_ptr_begin`
## `ao_spop_ptr_end`

```c
void ao_spop_ptr_begin(ao_spop_ptr_t * p);
void ao_spop_ptr_end  (ao_spop_ptr_t * p);
```

Begins or ends, respectively, a popping of a pointer from a stream.

## `ao_spush_ptr`
## `ao_spush_ptr_from`

```c
void ao_spush_ptr     (ao_spush_ptr_t * p, ao_time_t timeout);
void ao_spush_ptr_from(ao_spush_ptr_t * p, ao_time_t timeout, ao_time_t beginning);
```

Pushes a pointer to a stream in a blocking fashion with a timeout and an optional beginning.

## `ao_spush_ptr_forever`

```c
void ao_spush_ptr_forever(ao_spush_ptr_t * p);
```

Pushes a pointer to a stream indefinitely in a blocking fashion.

## `ao_spush_ptr_try`

```c
void ao_spush_ptr_try(ao_spush_ptr_t * p);
```

Pushes a pointer to a stream in a non-blocking fashion.

## `ao_spush_ptr_begin`
## `ao_spush_ptr_end`

```c
void ao_spush_ptr_begin(ao_spush_ptr_t * p);
void ao_spush_ptr_end  (ao_spush_ptr_t * p);
```

Begins or ends, respectively, a pushing of a pointer to a stream.

## `ao_spush_ptr_override`

```c
void ao_spush_ptr_override(ao_spush_ptr_t * p);
```

Pushes a pointer to a stream in a non-blocking fashion. If the stream is full, then this function overrides the oldest pointer in the stream.
