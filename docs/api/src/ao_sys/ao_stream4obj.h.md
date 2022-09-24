---
author: "Stefan Wagner"
date: 2022-09-13
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

# Identifier

```c
#define AO_STREAM4OBJ
```

# Types

## `ao_stream4obj_t`

```c
typedef struct ao_stream4obj_t ao_stream4obj_t;
```

```c
struct ao_stream4obj_t
{
    ao_buffer4obj_t buffer;
    ao_list_t       pop;
    ao_list_t       push;
};
```

This type represents a stream for objects. It consists of the following members.

| `buffer` | The buffer. |
| `pop` | The list of poppings. |
| `push` | The list of pushings. |

## `ao_spop_obj_t`

```c
typedef struct ao_spop_obj_t ao_spop_obj_t;
```

```c
struct ao_spop_obj_t
{
    ao_async_t        async;
    ao_list_node_t    node;
    void *            ptr;
    bool volatile     result;
    ao_stream4obj_t * stream;
};
```

This type represents the popping of an object from a stream. It consists of the following members.

| `async` | The asynchronous event. |
| `node` | The node for the stream's list of poppings. |
| `ptr` | Points to a location to store the popped object. |
| `result` | The result. |
| `stream` | The stream. |

## `ao_spush_obj_t`

```c
typedef struct ao_spush_obj_t ao_spush_obj_t;
```

```c
struct ao_spush_obj_t
{
    ao_async_t        async;
    ao_list_node_t    node;
    void *            ptr;
    void *            ptr_override;
    bool volatile     result;
    bool volatile     result_override;
    ao_stream4obj_t * stream;
};
```

This type represents the pushing of an object to a stream. It consists of the following members.

| `async` | The asynchronous event. |
| `node` | The node for the stream's list of pushings. |
| `ptr` | Points to the object to push to the stream. |
| `ptr_override` | Points to a location to store the overridden object. |
| `result` | The result. |
| `result_override` | Indicates whether an object has been overridden. |
| `stream` | The stream. |

# Functions

## `ao_spop_obj`
## `ao_spop_obj_from`

```c
void ao_spop_obj     (ao_spop_obj_t * x, ao_time_t timeout);
void ao_spop_obj_from(ao_spop_obj_t * x, ao_time_t timeout, ao_time_t beginning);
```

Pops an object from a stream in a blocking fashion with a timeout and an optional beginning.

## `ao_spop_obj_forever`

```c
void ao_spop_obj_forever(ao_spop_obj_t * x);
```

Pops an object from a stream indefinitely in a blocking fashion.

## `ao_spop_obj_try`

```c
void ao_spop_obj_try(ao_spop_obj_t * x);
```

Pops an object from a stream in a non-blocking fashion.

## `ao_spop_obj_begin`
## `ao_spop_obj_end`

```c
void ao_spop_obj_begin(ao_spop_obj_t * x);
void ao_spop_obj_end  (ao_spop_obj_t * x);
```

Begins or ends, respectively, a popping of an object from a stream.

## `ao_spush_obj`
## `ao_spush_obj_from`

```c
void ao_spush_obj     (ao_spush_obj_t * x, ao_time_t timeout);
void ao_spush_obj_from(ao_spush_obj_t * x, ao_time_t timeout, ao_time_t beginning);
```

Pushes an object to a stream in a blocking fashion with a timeout and an optional beginning.

## `ao_spush_obj_forever`

```c
void ao_spush_obj_forever(ao_spush_obj_t * x);
```

Pushes an object to a stream indefinitely in a blocking fashion.

## `ao_spush_obj_try`

```c
void ao_spush_obj_try(ao_spush_obj_t * x);
```

Pushes an object to a stream in a non-blocking fashion.

## `ao_spush_obj_begin`
## `ao_spush_obj_end`

```c
void ao_spush_obj_begin(ao_spush_obj_t * x);
void ao_spush_obj_end  (ao_spush_obj_t * x);
```

Begins or ends, respectively, a pushing of an object to a stream.

## `ao_spush_obj_override`

```c
void ao_spush_obj_override(ao_spush_obj_t * x);
```

Pushes an object to a stream in a non-blocking fashion. If the stream is full, then this function overrides the oldest object in the stream.
