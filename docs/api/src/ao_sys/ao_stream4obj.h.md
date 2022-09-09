---
author: "Stefan Wagner"
date: 2022-08-31
draft: true
permalink: /api/src/ao_sys/ao_stream4obj.h/
toc: true
---

# Include

```c
#include <ao_async.h>
#include <ao_buffer4obj.h>
#include <ao_list.h>
#include <ao_time.h>
#include <stdbool.h>
```

# Identifiers

## `AO_STREAM4OBJ`

```c
#define AO_STREAM4OBJ
```

# Typedefs

```c
typedef struct ao_stream4obj_t ao_stream4obj_t;
typedef struct ao_spop_obj_t   ao_spop_obj_t;
typedef struct ao_spush_obj_t  ao_spush_obj_t;
```

# Types

## `ao_stream4obj_t`

This type represents a stream for objects.

```c
struct ao_stream4obj_t
{
    ao_buffer4obj_t buffer;
    ao_list_t       pop;
    ao_list_t       push;
};
```

It consists of the following members.

| `buffer` | The buffer. |
| `pop` | The list of tasks attempting to pop an object from the stream. |
| `push` | The list of tasks attempting to push an object to the stream. |

## `ao_spop_obj_t`

This type represents the popping of an object from a stream.

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

It consists of the following members.

| `async` | The asynchronous event. |
| `node` | The node for the stream's waiting list. |
| `ptr` | Points to a location to store the popped object. |
| `result` | Indicates whether an object has been popped from the stream. |
| `stream` | The stream. |

## `ao_spush_obj_t`

This type represents the pushing of an object to a stream.

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

It consists of the following members.

| `async` | The asynchronous event. |
| `node` | The node for the stream's waiting list. |
| `ptr` | Points to the object to push to the stream. |
| `ptr_override` | Points to a location to store the overridden object. |
| `result` | Indicates whether the object has been pushed to the stream. |
| `result_override` | Indicates whether an object has been overridden. |
| `stream` | The stream. |

# Functions

## `ao_spop_obj`
## `ao_spop_obj_from`

```c
void ao_spop_obj(     ao_spop_obj_t * x, ao_time_t timeout);
void ao_spop_obj_from(ao_spop_obj_t * x, ao_time_t timeout, ao_time_t beginning);
```

## `ao_spop_obj_forever`

```c
void ao_spop_obj_forever(ao_spop_obj_t * x);
```

## `ao_spop_obj_try`

```c
void ao_spop_obj_try(ao_spop_obj_t * x);
```

## `ao_spop_obj_begin`
## `ao_spop_obj_end`

```c
void ao_spop_obj_begin(ao_spop_obj_t * x);
void ao_spop_obj_end(  ao_spop_obj_t * x);
```

## `ao_spush_obj`
## `ao_spush_obj_from`

```c
void ao_spush_obj(     ao_spush_obj_t * x, ao_time_t timeout);
void ao_spush_obj_from(ao_spush_obj_t * x, ao_time_t timeout, ao_time_t beginning);
```

## `ao_spush_obj_forever`

```c
void ao_spush_obj_forever(ao_spush_obj_t * x);
```

## `ao_spush_obj_try`

```c
void ao_spush_obj_try(ao_spush_obj_t * x);
```

## `ao_spush_obj_begin`
## `ao_spush_obj_end`

```c
void ao_spush_obj_begin(ao_spush_obj_t * x);
void ao_spush_obj_end(  ao_spush_obj_t * x);
```

## `ao_spush_obj_override`

```c
void ao_spush_obj_override(ao_spush_obj_t * x);
```
