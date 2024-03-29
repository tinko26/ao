---
author: "Stefan Wagner"
date: 2022-09-26
draft: true
permalink: /api/src/ao_sys/ao_stream4obj.h/
toc: true
---

# Include

| [`ao_async.h`](ao_async.h.md) |
| [`ao_buffer4obj.h`](../ao/ao_buffer4obj.h.md) |
| [`ao_list.h`](../ao/ao_list.h.md) |
| [`ao_time.h`](ao_time.h.md) |
| `stdbool.h` |

# Types

## `ao_stream4obj_t`

```c
typedef struct ao_stream4obj_t ao_stream4obj_t;
```

Represents a stream for objects.

## `ao_spop_obj_t`

```c
typedef struct ao_spop_obj_t ao_spop_obj_t;
```

Represents the popping of an object from a stream.

## `ao_spush_obj_t`

```c
typedef struct ao_spush_obj_t ao_spush_obj_t;
```

Represents the pushing of an object to a stream.

# Structs

## `ao_stream4obj_t`

```c
struct ao_stream4obj_t
{
    ao_buffer4obj_t buffer;
    ao_list_t       pop;
    ao_list_t       push;
};
```

| `buffer` | The buffer. |
| `pop` | The list of poppings. |
| `push` | The list of pushings. |

## `ao_spop_obj_t`

```c
struct ao_spop_obj_t
{
    ao_async_t        async;
    void *            ptr;
    bool volatile     result;
    ao_stream4obj_t * stream;
    ao_list_node_t    stream_pop_node;
};
```

| `async` | The asynchronous event. |
| `ptr` | Points to a location to store the popped object. |
| `result` | The result. |
| `stream` | The stream. |
| `stream_pop_node` | The node for the stream's list of poppings. |

## `ao_spush_obj_t`

```c
struct ao_spush_obj_t
{
    ao_async_t        async;
    void *            ptr;
    void *            ptr_override;
    bool volatile     result;
    bool volatile     result_override;
    ao_stream4obj_t * stream;
    ao_list_node_t    stream_push_node;
};
```

| `async` | The asynchronous event. |
| `ptr` | Points to the object to push to the stream. |
| `ptr_override` | Points to a location to store the overridden object. |
| `result` | The result. |
| `result_override` | Indicates whether an object has been overridden. |
| `stream` | The stream. |
| `stream_push_node` | The node for the stream's list of pushings. |

# Functions

## `ao_spop_obj`
## `ao_spop_obj_from`

```c
void ao_spop_obj     (ao_spop_obj_t * p, ao_time_t timeout);
void ao_spop_obj_from(ao_spop_obj_t * p, ao_time_t timeout, ao_time_t beginning);
```

Pops an object from a stream in a blocking fashion with a timeout and an optional beginning.

## `ao_spop_obj_forever`

```c
void ao_spop_obj_forever(ao_spop_obj_t * p);
```

Pops an object from a stream indefinitely in a blocking fashion.

## `ao_spop_obj_try`

```c
void ao_spop_obj_try(ao_spop_obj_t * p);
```

Pops an object from a stream in a non-blocking fashion.

## `ao_spop_obj_begin`
## `ao_spop_obj_end`

```c
void ao_spop_obj_begin(ao_spop_obj_t * p);
void ao_spop_obj_end  (ao_spop_obj_t * p);
```

Begins or ends, respectively, a popping of an object from a stream.

## `ao_spush_obj`
## `ao_spush_obj_from`

```c
void ao_spush_obj     (ao_spush_obj_t * p, ao_time_t timeout);
void ao_spush_obj_from(ao_spush_obj_t * p, ao_time_t timeout, ao_time_t beginning);
```

Pushes an object to a stream in a blocking fashion with a timeout and an optional beginning.

## `ao_spush_obj_forever`

```c
void ao_spush_obj_forever(ao_spush_obj_t * p);
```

Pushes an object to a stream indefinitely in a blocking fashion.

## `ao_spush_obj_try`

```c
void ao_spush_obj_try(ao_spush_obj_t * p);
```

Pushes an object to a stream in a non-blocking fashion.

## `ao_spush_obj_begin`
## `ao_spush_obj_end`

```c
void ao_spush_obj_begin(ao_spush_obj_t * p);
void ao_spush_obj_end  (ao_spush_obj_t * p);
```

Begins or ends, respectively, a pushing of an object to a stream.

## `ao_spush_obj_override`

```c
void ao_spush_obj_override(ao_spush_obj_t * p);
```

Pushes an object to a stream in a non-blocking fashion. If the stream is full, then this function overrides the oldest object in the stream.
